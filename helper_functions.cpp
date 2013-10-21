#include <ctime>
#include <cstdlib>
#include <iostream>
#include <vector>
#include "helper_functions.h"

using namespace std;

/* Generates a random number with seed from the time it was first called */
int getRandomNumber(int min, int max) {
    if ((max+min) == 0) return 0; // We should not devide by zero

    static bool seedUsed = false;
    if (!seedUsed) { // if we havend used the seed already
        srand(time(0)); // use current time as seed for random generator
        seedUsed = true;
    }

    return rand() % max + min;
}

/* Creates a random graph represented as an adjency matrix */
vector<vector<int> > generateRandomGraph(int size, int minWeight, int maxWeight) {
    vector<vector<int> > graph(size, vector<int>(size, 0)); // The new graph, filled with zero's

    // Fill ut up with random edge-weights
    // All nodes will be connected to all other nodes
    for (unsigned int i = 0; i < graph.size(); ++i) {
        for (unsigned int j = 0; j < graph.size(); ++j) {
            if (i != j && graph[i][j] == 0) {
                int randomWeight = getRandomNumber(minWeight, maxWeight);
                graph[i][j] = randomWeight;
                graph[j][i] = randomWeight;
            }
        }
    }

    return graph;
}

/* Prints the graph to terminal in a semi-sensable matter */
void printGraphToTerminal(const vector<vector<int> > &graph) {
    for (unsigned int i = 0; i < graph.size(); ++i) {
        cout << "Node #" << i << ":" << endl;
        for (unsigned int j = 0; j < graph.size(); ++j) {
            if (i != j && graph[i][j] != 0) {
                cout << "\t" << j << " : " <<  graph[i][j] << endl;
            }
        }
    }
}

/* Prints the path to terminal in a semi-sensable matter */
void printPathToTerminal(const vector<int> &path, const vector<vector<int> > &graph) {
    cout << "(" << path[0] << ")";
    for (unsigned int i = 0; i < path.size()-1; ++i) {
        cout << "<-" << graph[path[i]][path[i+1]] << "->"
             << "(" << path[i+1] << ")";
    }
}

/* Calculates the total cost of a given path */
int getTotalPathCost(const std::vector<int> &path, const std::vector<std::vector<int> > &graph) {
    int cost = 0;

    // Iterate through and add together all path weights
    for (unsigned int i = 0; i < path.size()-1; ++i) {
        cost += graph[path[i]][path[i+1]];
    }

    return cost;
}
