
// SimilarityCalculator.h

#ifndef SIMILARITYCALCULATOR_H
#define SIMILARITYCALCULATOR_H

#include <unordered_map>
#include <vector>
#include <string>
#include <utility>

class SimilarityCalculator {
public:
    static std::vector<std::vector<double>> generateSimilarityMatrix(
        const std::vector<std::unordered_map<std::string, double>>& wordFreqs);

    static std::vector<std::pair<int, int>> findTopSimilarPairs(
        const std::vector<std::vector<double>>& similarityMatrix, int topN);
};

#endif
