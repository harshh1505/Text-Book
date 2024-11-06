
// TextProcessor.h

#ifndef TEXTPROCESSOR_H
#define TEXTPROCESSOR_H

#include <string>
#include <unordered_map>

class TextProcessor {
public:
    static std::unordered_map<std::string, double> computeNormalizedWordFrequency(const std::string& fileName);

private:
    static std::string normalizeText(const std::string& text);
    static bool isCommonWord(const std::string& word);
};

#endif
