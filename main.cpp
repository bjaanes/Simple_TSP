#include <iostream>
#include <vector>
#include "helper_functions.h"
#include "tsp_algorithms.h"


int const numberOfCities = 100;
int const minWeight = 1;
int const maxWeight = 5;
int const numberOfTests = 5;
bool const randomConstruction = true;

using namespace std;

int main()
{
    cout << "Test Data:" << endl;
    cout << "Number of cities: " << numberOfCities << endl;
    cout << "Using ";
    if (randomConstruction) cout << "random";
    else cout << "greedy";
    cout << " construction method" << endl;

    /* Running the tests */
    for (int i = 0; i < numberOfTests; ++i) {
        cout << "Test #" << i << ":" << endl;
        vector<vector<int> > graph = generateRandomGraph(numberOfCities, minWeight, maxWeight);
        vector<int> constuctionPath;
        vector<int> heuristicPath;

        // Phase 1:
        if (randomConstruction) constuctionPath = randomConstructionMethod(graph);
        else constuctionPath = greedyConstructionMethod(graph);
        cout << "Phase 1 cost:" << getTotalPathCost(constuctionPath, graph) << endl;

        // Phase 2:
        heuristicPath = greedyHeuristicMethod(constuctionPath, graph);
        cout << "Phase 2 cost:" << getTotalPathCost(heuristicPath, graph) << endl;

        cout << endl;
    }
}

