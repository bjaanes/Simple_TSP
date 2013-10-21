#ifndef HELPER_FUNCTIONS_H
#define HELPER_FUNCTIONS_H

#include <vector>

/* Generates a random number */
int getRandomNumber(int min, int max);

/* Creates a random graph represented as an adjency matrix */
std::vector<std::vector<int> > generateRandomGraph(int size, int minWeight, int maxWeight);

/* Utilites to print graphs and paths to the terminal: Mostly for debugging use */
void printGraphToTerminal(const std::vector<std::vector<int> > &graph);
void printPathToTerminal(const std::vector<int> &path, const std::vector<std::vector<int> > &graph);

/* Gets the total path cost for given path (with indexes to a given full graph) */
int getTotalPathCost(const std::vector<int> &path, const std::vector<std::vector<int> > &graph);

#endif // HELPER_FUNCTIONS_H
