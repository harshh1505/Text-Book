
// TextProcessor.cpp

#include "TextProcessor.h"
#include <fstream>
#include <sstream>
#include <algorithm>
#include <cctype>
#include <unordered_map>
#include <set>

std::unordered_map<std::string, double> TextProcessor::computeNormalizedWordFrequency(const std::string& fileName) {
    std::ifstream file(fileName);
    std::unordered_map<std::string, int> wordCount;
    int totalWords = 0;
    std::string word;

    while (file >> word) {
        word = normalizeText(word);
        if (!word.empty() && !isCommonWord(word)) {
            ++wordCount[word];
            ++totalWords;
        }
    }

    std::unordered_map<std::string, double> normalizedFreq;
    for (const auto& pair : wordCount) {
        normalizedFreq[pair.first] = static_cast<double>(pair.second) / totalWords;
    }

    return normalizedFreq;
}

std::string TextProcessor::normalizeText(const std::string& text) {
    std::string result;
    for (char ch : text) {
        if (std::isalnum(ch)) {
            result += std::toupper(ch);
        }
    }
    return result;
}

bool TextProcessor::isCommonWord(const std::string& word) {
    static const std::set<std::string> commonWords = {"A", "AND", "AN", "OF", "IN", "THE"};
    return commonWords.find(word) != commonWords.end();
}
