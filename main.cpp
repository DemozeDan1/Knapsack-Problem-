#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Item {
    string name;
    int weight;
    int value;
};

// Function to get user input for number of items
int getNumItems() {
    int numItems;
    cout << "Enter the number of items: ";
    cin >> numItems;
    return numItems;
}

// Function to get user input for an item
Item getItem(int itemNumber) {
    Item item;
    cout << "Enter name for item " << itemNumber << ": ";
    cin >> item.name;
    cout << "Enter weight for item " << itemNumber << ": ";
    cin >> item.weight;
    cout << "Enter value for item " << itemNumber << ": ";
    cin >> item.value;
    return item;
}

// Function to get user input for items
vector<Item> getItems(int numItems) {
    vector<Item> items;
    for (int i = 0; i < numItems; ++i) {
        items.push_back(getItem(i + 1)); 
    }
    return items;
}

// Function to get knapsack capacity
int getCapacity() {
    int capacity;
    cout << "Enter the knapsack capacity: ";
    cin >> capacity;
    return capacity;
}

// Knapsack algorithm (0/1 Knapsack)
pair<int, vector<int>> knapsack(vector<Item>& items, int capacity) {
    int n = items.size();
    vector<vector<int>> dp(n + 1, vector<int>(capacity + 1, 0));
    vector<vector<bool>> keep(n + 1, vector<bool>(capacity + 1, false));

    for (int i = 1; i <= n; ++i) {
        for (int w = 1; w <= capacity; ++w) {
            if (items[i - 1].weight <= w) {
                if (items[i - 1].value + dp[i - 1][w - items[i - 1].weight] > dp[i - 1][w]) {
                    dp[i][w] = items[i - 1].value + dp[i - 1][w - items[i - 1].weight];
                    keep[i][w] = true;
                } else {
                    dp[i][w] = dp[i - 1][w];
                }
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    vector<int> selectedItems;
    int w = capacity;
    for (int i = n; i > 0; --i) {
        if (keep[i][w]) {
            selectedItems.push_back(i - 1); // Store index of the item
            w -= items[i - 1].weight;
        }
    }

    return {dp[n][capacity], selectedItems};
}

// Function to display the result
void displayResult(int maxValue, const vector<Item>& items, const vector<int>& selectedItems) {
    cout << "Maximum value that can be obtained: " << maxValue << endl;
    cout << "Selected items:" << endl;
    for (int idx : selectedItems) {
        cout << " - " << items[idx].name 
             << " (Weight: " << items[idx].weight 
             << ", Value: " << items[idx].value << ")" << endl;
    }
}

int main() {
    int numItems = getNumItems();
    vector<Item> items = getItems(numItems);
    int capacity = getCapacity();

    auto [maxValue, selectedItems] = knapsack(items, capacity);

    displayResult(maxValue, items, selectedItems);

    return 0;
}
