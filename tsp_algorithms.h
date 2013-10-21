#ifndef TSP_ALGORITHMS_H
#define TSP_ALGORITHMS_H

#include <vector>

// Construction methods
std::vector<int> randomConstructionMethod(const std::vector<std::vector<int> > &graph);
std::vector<int> greedyConstructionMethod(const std::vector<std::vector<int> > &graph);

std::vector<int> greedyHeuristicMethod(const std::vector<int> &initialTour,
                                       const std::vector<std::vector<int> > &graph);

#endif // TSP_ALGORITHMS_H
