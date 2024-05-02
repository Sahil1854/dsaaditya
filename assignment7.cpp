#include<iostream>
using namespace std;

#define ROW 10
#define COL 10
#define infi 9999

class prims {
    int graph[ROW][COL], nodes;
public:
    void createGraph();
    void primsAlgo();
};

void prims::createGraph() {
    int i, j;
    cout << "Enter Total Offices: ";
    cin >> nodes;
    cout << "\nEnter Adjacency Matrix: \n";
    for (i = 0; i < nodes; i++) {
        for (j = i; j < nodes; j++) {
            cout << "Enter distance between " << i << " and " << j << endl;
            cin >> graph[i][j];
            graph[j][i] = graph[i][j];
        }
    }

    for (i = 0; i < nodes; i++) {
        for (j = 0; j < nodes; j++) {
            if (graph[i][j] == 0)
                graph[i][j] = infi;    //fill infinity where path is not present
        }
    }
}

void prims::primsAlgo() {
    int selected[ROW], i, j, ne=0;
    int zero = 0, one = 1, min = 0, x, y;
    int cost = 0;
    for (i = 0; i < nodes; i++)
        selected[i] = zero;

    selected[0] = one;        //starting vertex is always node-0

    while (ne < nodes - 1) {
        min = infi;

        for (i = 0; i < nodes; i++) {
            if (selected[i] == one) {
                for (j = 0; j < nodes; j++) {
                    if (selected[j] == zero) {
                        if (min > graph[i][j]) {
                            min = graph[i][j];
                            x = i;
                            y = j;
                        }
                    }
                }
            }
        }
        selected[y] = one;
        cout << "\n" << x << " --> " << y;
        cost += graph[x][y];
        ne++;
    }
    cout << "\nTotal cost is: " << cost << endl;
}

int main() {
    prims MST;
    cout << "\nPrims Algorithm to connect several offices\n";
    MST.createGraph();
    MST.primsAlgo();
}
/*A spanning tree is a subset of Graph G, such that all the vertices are connected using minimum possible number of edges. 
Hence, a spanning tree does not have cycles and a graph may have more than one spanning tree.
Minimum Spanning Tree: A spanning tree whose weight of edges is minimum is called as 
Minimum Spanning Tree A minimum spanning tree (MST) is defined as a spanning tree that has the minimum weight among all the possible spanning trees
give example 
Two Methods to find Minimum Spanning Tree:
1)prims algo 2) kruskal algo
1)prims
Step 1: Determine an arbitrary vertex as the starting vertex of the MST.
Step 2: Follow steps 3 to 5 till there are vertices that are not included in the MST (known as fringe vertex).
Step 3: Find edges connecting any tree vertex with the fringe vertices.
Step 4: Find the minimum among these edges.
Step 5: Add the chosen edge to the MST if it does not form any cycle.
Step 6: Return the MST and exit tc O(v) cannot be used for directed graph. use for dense graph.graph must be connected.

2)kruskal algorithm
Sort all the edges in increasing  order of their weight. 
2Pick the smallest edge. Check if it forms a cycle with the spanning tree formed so far. 3)If the cycle is not formed, include this edge. Else, discard it. 
Repeat step#2 until there are (V-1) edges in the spanning tree.
it should be used for sparse graph


: Prims Algorithms is successfully implemented to find out minimum distance*/