//assignment 8
#include <bits/stdc++.h>
using namespace std;
int sum(int frequency[], int i, int j)
{
    int sum = 0;
    for (int x = i; x <= j; x++)
        sum += frequency[x];
    return sum;
}
int optimalCost(int frequency[], int i, int j)
{
    if (j < i)
        return 0;
    if (j == i)
        return frequency[i];

    int frequencySum = sum(frequency, i, j);

    int min = INT_MAX;

    for (int r = i; r <= j; ++r)
    {
        int cost = optimalCost(frequency, i, r - 1) + optimalCost(frequency, r + 1, j);
        if (cost < min)
            min = cost;
    }

    return min + frequencySum;
}
int optimalSearchTree(int keys[], int frequency[], int n)
{
    return optimalCost(frequency, 0, n - 1);
}
int main()
{
    int keys[] = {5, 20, 30};
    int frequency[] = {3, 8, 40};
    int n = sizeof(keys) / sizeof(keys[0]);
    cout << "Cost of Optimal BST is " << optimalSearchTree(keys, frequency, n);
    return 0;
}












/*An Optimal Binary Search Tree (OBST), also known as a Weighted Binary Search Tree, is a binary search tree that minimizes the expected search cost. 
In a binary search tree, the search cost is the number of comparisons required to search for a given key.
In an OBST, each node is assigned a weight that represents the probability of the key being searched for. 
The sum of all the weights in the tree is 1.0. The expected search cost of a node is the sum of the product of its depth and weight,
and the expected search cost of its children.
This program uses recursive techniques to calculate the optimal cost of constructing an optimal BST.
To construct an OBST, we start with a sorted list of keys and their probabilities. We then build a table that contains the expected search cost for all possible sub-trees of the original list. We can use dynamic programming to fill in this table efficiently.
 Finally, we use this table to construct the OBST.
The time complexity of constructing an OBST is O(n^3), where n is the number of keys. 
However, with some optimizations, we can reduce the time complexity to O(n^2). 
Once the OBST is constructed, the time complexity of searching for a key is O(log n), 
the same as for a regular binary search tree.
The optimal cost for freq[i..j] can be recursively calculated using following formula.
optcost(i,j)=sum i=k to j freq[k]+ min r=i to j[optcost(i, r - 1)+optcost(j,r+1)]
We need to calculate optCost(0, n-1) to find the result.
The idea of above formula is simple, we one by one try all nodes as root (r varies from i to j in second term). When we make rth node as root, we recursively calculate optimal cost from i to r-1 and r+1 to j. We add sum of frequencies from i to j (see first term in the above formula), this is added because every search will go through root and one comparison will be done for every search.
The algorithm requires O (n2) time and O (n2) storage. Therefore, as ‘n’ increases it will run out 
of storage even before it runs out of time. The storage needed can be reduced by almost half by 
implementing the two-dimensional arrays as one-dimensional arrays

Conclusion: This program gives us the knowledge OBST, Extended binary search tree.

   */

