
// SimilarityCalculator.cpp

#include "SimilarityCalculator.h"
#include <algorithm>
#include <cmath>

std::vector<std::vector<double>> SimilarityCalculator::generateSimilarityMatrix(
    const std::vector<std::unordered_map<std::string, double>>& wordFreqs) {
    
    int numFiles = wordFreqs.size();
    std::vector<std::vector<double>> similarityMatrix(numFiles, std::vector<double>(numFiles, 0.0));

    for (int i = 0; i < numFiles; ++i) {
        for (int j = i + 1; j < numFiles; ++j) {
            double similarity = 0.0;
            for (const auto& [word, freq] : wordFreqs[i]) {
                if (wordFreqs[j].count(word)) {
                    similarity += freq * wordFreqs[j].at(word);
                }
            }
            similarityMatrix[i][j] = similarity;
            similarityMatrix[j][i] = similarity;
        }
    }

    return similarityMatrix;
}

std::vector<std::pair<int, int>> SimilarityCalculator::findTopSimilarPairs(
    const std::vector<std::vector<double>>& similarityMatrix, int topN) {

    int numFiles = similarityMatrix.size();
    std::vector<std::tuple<double, int, int>> similarities;

    for (int i = 0; i < numFiles; ++i) {
        for (int j = i + 1; j < numFiles; ++j) {
            similarities.emplace_back(similarityMatrix[i][j], i, j);
        }
    }

    std::sort(similarities.rbegin(), similarities.rend());

    std::vector<std::pair<int, int>> topPairs;
    for (int k = 0; k < topN && k < similarities.size(); ++k) {
        topPairs.emplace_back(std::get<1>(similarities[k]), std::get<2>(similarities[k]));
    }

    return topPairs;
}
