
// main.cpp

#include <iostream>
#include <fstream>
#include <filesystem>
#include <vector>
#include "TextProcessor.h"
#include "SimilarityCalculator.h"

int main() {
    std::string dirPath = "./Book-Txt";  // Adjust path if necessary
    std::vector<std::string> fileNames;

    // Gather all text files from the directory
    for (const auto& entry : std::filesystem::directory_iterator(dirPath)) {
        if (entry.path().extension() == ".txt") {
            fileNames.push_back(entry.path().string());
        }
    }

    // Process each file to get normalized frequency vectors
    std::vector<std::unordered_map<std::string, double>> wordFreqs;
    for (const auto& fileName : fileNames) {
        wordFreqs.push_back(TextProcessor::computeNormalizedWordFrequency(fileName));
    }

    // Generate similarity matrix
    std::vector<std::vector<double>> similarityMatrix = SimilarityCalculator::generateSimilarityMatrix(wordFreqs);

    // Identify top 10 similar pairs
    std::vector<std::pair<int, int>> topPairs = SimilarityCalculator::findTopSimilarPairs(similarityMatrix, 10);

    // Output the top 10 pairs
    std::cout << "Top 10 Similar Pairs of Textbooks:" << std::endl;
    for (const auto& pair : topPairs) {
        std::cout << fileNames[pair.first] << " and " << fileNames[pair.second] << " with similarity index: "
                  << similarityMatrix[pair.first][pair.second] << std::endl;
    }

    return 0;
}
