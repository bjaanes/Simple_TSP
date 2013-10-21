#include "tsp_algorithms.h"
#include "helper_functions.h"
#include <vector>
#include <algorithm>

using namespace std;

/* Creates an initial random path for a give Graph.
 * This function implements the following algorithm:
 * Choose a random starting city;
 * Mark this city as visited;
 * While ( all cities not visisted )
 * start:
 *   Choose a random city;
 *   Mark it visited;
 *   Connect it to the previous chosen city;
 * end;
 */
vector<int> randomConstructionMethod(const vector<vector<int> > &graph) {
    vector<int> visited; // cities visited
    vector<int> notVisited; // cities not visited yet

    // set up notVisited with all nodes
    for (unsigned int i = 0; i < graph.size(); ++i) {
        notVisited.push_back(i);
    }

    // Visit all in a random matter
    while (!notVisited.empty()) {
        int randomCity = getRandomNumber(0, (int)(notVisited.size()-1));
        visited.push_back(notVisited[randomCity]);
        notVisited.erase(notVisited.begin() + randomCity);
    }

    // A random path has been created and returned
    return visited;
}

/* Creats an initial path for a graph in a greedy matter
 * This function implements the following algorithm:
 * Choose a city in a random manner;
 * Mark it visited;
 * while ( all the cities not visited )
 * start:
 *   Identify the unvisited nearest city to the previous visited city;
 *   Mark it visited;
 *   Connect it to the previous visited city;
 * end;
 */
vector<int> greedyConstructionMethod(const vector<vector<int> > &graph) {
    vector<int> visited; // cities visited
    vector<int> notVisited; // cities not yet visited

    // set up notVisited with all nodes
    for (unsigned int i = 0; i < graph.size(); ++i) {
        notVisited.push_back(i);
    }

    // Chooses a city at random and uses it as starting point
    int randomCity = getRandomNumber(0, (int)(notVisited.size()-1));
    visited.push_back(notVisited[randomCity]);
    notVisited.erase(notVisited.begin() + randomCity);

    // Visit all in a random matter
    while (!notVisited.empty()) {
        int currentIndex = visited[visited.size()-1]; // Actual graph index
        int nearestIndex = 0; // Index of notVisited vector

        // Find nearest unvisited city
        for (unsigned int i = 0; i < notVisited.size(); ++i) {
            if (graph[currentIndex][notVisited[i]]
                    < graph[currentIndex][notVisited[nearestIndex]]) {
                nearestIndex = i; // Better found
            }
        }

        // Mark nearest city as visited and remove it from notVisited
        visited.push_back(notVisited[nearestIndex]);
        notVisited.erase(notVisited.begin() + nearestIndex);
    }

    // The greedy path is now done and neatly ordered in the visited vector
    return visited;
}

/* Tries to improve an initial path by a greedy heuristic algorithm
 * This function implements the following algorithm:
 * Generate an initial tour using a chosen construction algorithm ;
 * while ( !stop )
 * start:
 *   choose a random city C_1;
 *   choose a random city C_2;
 *   Exchange their locations;
 *   if ( length of the tour is improved )
 *       accept the current tour ;
 *   else
 *       keep the previous the tour ;
 * stop;
 */
vector<int> greedyHeuristicMethod(const vector<int> &initialTour, const vector<vector<int> > &graph) {
    const int maxIterations = 10000;
    int numberOfIterations = 0;

    vector<int> currentBestPath = initialTour; // Copy over;

    // Try to find a better path
    while (numberOfIterations < maxIterations) {
        vector<int> newPath = currentBestPath;
        int randomCityIndex1 = getRandomNumber(0, (int)(newPath.size()-1));
        int randomCityIndex2 = getRandomNumber(0, (int)(newPath.size()-1));

        // Swap location
        int tmpCity = newPath[randomCityIndex1];
        newPath[randomCityIndex1] = newPath[randomCityIndex2];
        newPath[randomCityIndex2] = tmpCity;

        if (getTotalPathCost(newPath, graph) < getTotalPathCost(currentBestPath, graph)) {
            currentBestPath = newPath; // New and better path found, use that instead
            numberOfIterations = 0; // reset
        }

        numberOfIterations++;
    }

    return currentBestPath;
}
