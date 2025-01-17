#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Item {
    string name;
    int weight;
    int value;
};

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

int main() {
    int numItems;
    cout << "Enter the number of items: ";
    cin >> numItems;

    vector<Item> items;

    for (int i = 0; i < numItems; ++i) {
        Item item;
        cout << "Enter name for item " << i + 1 << ": ";
        cin >> item.name;
        cout << "Enter weight for item " << i + 1 << ": ";
        cin >> item.weight;
        cout << "Enter value for item " << i + 1 << ": ";
        cin >> item.value;
        items.push_back(item);
    }

    int capacity;
    cout << "Enter the knapsack capacity: ";
    cin >> capacity;

    int maxValue = knapsack(items, capacity);

    cout << "Maximum value that can be obtained: " << maxValue << endl;

    return 0;  }