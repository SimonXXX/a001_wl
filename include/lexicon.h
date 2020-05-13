#ifndef ASSIGNMENTS_WL_LEXICON_H_
#define ASSIGNMENTS_WL_LEXICON_H_

#include <string>
#include <unordered_set>
#include <vector>

// Later on in semester we will learn about exceptions. But for now, we just exit on failure.
void Error(const std::string& message);

std::unordered_set<std::string> GetLexicon(const std::string& filename, const int word_length);

std::vector<std::string>  listOneLetterDifference(std::unordered_set<std::string>& lexicon, std::string& target, int& length);

void removeWords(std::unordered_set<std::string>& lexicon, std::vector<std::string>& words4removal);

#endif  // ASSIGNMENTS_WL_LEXICON_H_
