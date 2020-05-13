#include <iostream>
#include <unordered_set>
#include <fstream>
#include <iterator>
#include <algorithm>

using namespace std;

void Error(const std::string& message);

class Clexicon
{
public:
    static Clexicon getInstance() {
        return s_instance;
    }
private:
    Clexicon() {}  // Constructor? (the {} brackets) are needed here.

    // C++ 03
    // ========
    // Don't forget to declare these two. You want to make sure they
    // are unacceptable otherwise you may accidentally get copies of
    // your singleton appearing.
    //Clexicon(Clexicon const&);              // Don't Implement
    //void operator=(Clexicon const&); // Don't implement

    // C++ 11
    // =======
    // We can use the better technique of deleting the methods
    // we don't want.\\

    static Clexicon s_instance;
    unordered_set<string> m_lexicon;
    vector<string> m_words4removal;
    int m_stringLength = 0;
    string m_startWrd;
    string m_endWrd;
    bool m_found = false;

public:
   //Clexicon(Clexicon const&) = delete;
   //void operator=(Clexicon const&) = delete;

    // Note: Scott Meyers mentions in his Effective Modern
    //       C++ book, that deleted functions should generally
    //       be public as it results in better error messages
    //       due to the compilers behavior to check accessibility
    //       before deleted status

    bool getLexicon(const string& filename, const string& startWrd, const string& endWrd) {
        ifstream f{ filename };
        if (!f) {
            Error("Failed to open file");
            return false;
        }
        m_startWrd = startWrd;
        m_endWrd = endWrd;
        m_lexicon.clear();
        m_words4removal.clear();
        m_stringLength = m_startWrd.length();

        if (m_stringLength != m_endWrd.length()) {
            Error("start and end words different lengths");
            return false;
        }

        copy_if(istream_iterator<std::string>(f), {}, inserter(m_lexicon, m_lexicon.end()), [&](string str) { return (str.length() == m_stringLength); });

        if (f.bad()) {
            Error("I/O error while reading");
            return false;
        }
        if (!f.eof()) {
            Error("Didn't reach end of file");
            return false;
        }

        m_lexicon.erase(m_startWrd);

        return true;
    }

    void listAll() {
        for (auto i = m_lexicon.begin(); i != m_lexicon.end(); ++i) {
            std::cout << (*i) << std::endl;
        }

    }

    vector<string> listOneLetterDifference(string& target) {
        vector<string> outList = {};
        for (const auto& word : m_lexicon) {
            //std::cout << word << std::endl;
        }
        std::unordered_set<string> ::iterator itr;
        string checkWord;
        int count;
        for (itr = m_lexicon.begin(); itr != m_lexicon.end(); itr++) {
            count = 0;
            checkWord = *itr;
            for (int i = 0; i < m_stringLength; i++) {
                if (checkWord[i] != target[i]) count++;
                if (count > 1) break;
            }
            if (count == 1) {
                outList.push_back(checkWord);
                m_words4removal.push_back(checkWord);
            }

            count = 0;
        }
        return outList;
    }

    vector<string> getWords() {
        return m_words4removal;
    }

    void removeWords() { 
        for (string wrd2remove : m_words4removal) {
            if (std::find(m_words4removal.begin(), m_words4removal.end(), m_endWrd) != m_words4removal.end()) { m_found = true; }
            m_lexicon.erase(wrd2remove);
        }
        m_words4removal.clear(); // dont removed this!!
    }

    bool endWordFound() {
        return m_found;
    }

};





