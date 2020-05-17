#include <iostream>
#include <string>
#include <map>
#include "include/word_ladder.h"
#include "Clexicon.cpp"
#include <vector>


void printLadders(const string& word, std::map<std::string, std::vector<std::string>>& oneLetterAwayLists, std::vector<std::string>& ladder, const std::string& finish) {
    ladder.push_back(word);
    std::vector<string>& thisWordList = oneLetterAwayLists[word];
    std::sort(thisWordList.begin(), thisWordList.end());
    for (std::string nextWord : oneLetterAwayLists[word]) {
        if (oneLetterAwayLists[nextWord].empty()) {
            if (nextWord == finish) {
                for (std::string word2prnt : ladder) {
                    std::cout << word2prnt + " -> ";
                }
                std::cout << nextWord << std::endl;
            }
        }
        else {
           printLadders(nextWord, oneLetterAwayLists,ladder,finish);
        }
    }
    ladder.pop_back();
}

//Clexicon Clexicon::s_instance; // initialise singleton Clexicon class

int main() {
   // get start and end works from keyboard
    std::string startStr;
    std::string endStr;
    std::cout << "Enter start word(RETURN to quit) : ";
    std::getline(cin,startStr);
    std::cout << "Enter destination word : ";
    std::getline(cin,endStr);
    
    // set up the Lexicon
    Clexicon theLexicon; // = Clexicon::getInstance();  // reference to the Lexicon class instance  
    if (!theLexicon.getLexicon("words.txt", startStr, endStr)) {
        std::cin.get();
        //return 1;
    }

    // get the first vector (list) of words 1 difference to the start word
    // store it in the map nextWordVectors keyed on the start word
    std::map<std::string, std::vector<std::string> > nextWordVectors;
    nextWordVectors[startStr] = theLexicon.listOneLetterDifference(startStr);
    std::vector<string> wordsThisLevel;
    wordsThisLevel = theLexicon.getWords(); // get the list of words close to the start words
    theLexicon.removeWords();               // remove these words from the lexicon (no longer needed)

    // keep going unil the end word has been found
    while (!theLexicon.endWordFound() && !wordsThisLevel.empty()) {
        for (std::string nextWord : wordsThisLevel) {
            nextWordVectors[nextWord] = theLexicon.listOneLetterDifference(nextWord);
            //std::cout << nextWordVectors[nextWord].size() << std::endl;
        }
        wordsThisLevel = theLexicon.getWords();
        if (wordsThisLevel.empty()) {
            std::cout << "no more words" << std::endl;
            std::cin.get();
        }
        theLexicon.removeWords();
    }
    if (theLexicon.endWordFound()) {
        // find the ladders which find the end word
        std::vector<std::string> ladder;
        std::cout << "Found ladder: ";
        printLadders(startStr, nextWordVectors, ladder, endStr); // recursive function
    }
    else {
        std::cout << "No ladder found." << std::endl;
    }

    std::cin.get();

}
