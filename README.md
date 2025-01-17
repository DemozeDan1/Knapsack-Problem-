# Knapsack-Problem-

## Code Explanation for Resource Allocation:

1.Data Structures for Item Management:

Struct:
The Item struct is used to represent each resource with attributes:
### name: The resource's identifier.
### weight: The cost or requirement of the resource.
### value: The benefit or utility of the resource.
Vector:
     A vector<Item> is used to store multiple items, dynamically adjusting to the number of resources provided by the user.

2.Knapsack Algorithm:

The 0/1 Knapsack Dynamic Programming (DP) approach is used to maximize resource utilization under constraints.
A 2D DP table (dp) stores the maximum value achievable with a given capacity and subset of items.

3.Algorithm Effectiveness:

### The DP algorithm ensures optimality by evaluating all combinations of items for a given capacity constraint.
### The time complexity is 𝑂(𝑛 × 𝑊), where n is the number of items and 𝑊 is the capacity. This makes it efficient for moderate problem sizes.
