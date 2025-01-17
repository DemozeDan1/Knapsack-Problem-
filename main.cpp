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
int knapsack(vector<Item>& items, int capacity) {
    int n = items.size();
    vector<vector<int>> dp(n + 1, vector<int>(capacity + 1, 0));

    for (int i = 1; i <= n; ++i) {
        for (int w = 1; w <= capacity; ++w) {
            if (items[i - 1].weight <= w) {
                dp[i][w] = max(dp[i - 1][w], items[i - 1].value + dp[i - 1][w - items[i - 1].weight]);
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    return dp[n][capacity];
}

// Function to display the result
void displayResult(int maxValue) {
    cout << "Maximum value that can be obtained: " << maxValue << endl;
}

int main() {
    int numItems = getNumItems();
    vector<Item> items = getItems(numItems);
    int capacity = getCapacity();
    int maxValue = knapsack(items, capacity);
    displayResult(maxValue);

    return 0;
}