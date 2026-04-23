#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <queue>
#include <vector>

char toLowerChar(char c) {
    if (c >= 'A' && c <= 'Z') {
        return c + 32;
    }
    return c;
}
std::string LowerCase(const std::string& str) {
    std::string result = str;
    for (size_t i = 0; i < result.length(); i++) {
        result[i] = toLowerChar(result[i]);
    }
    return result;
}

std::vector<std::string> splitWords(const std::string& phrase) {
    std::vector<std::string> words;
    std::string separators = " ,?!.";

    size_t start = phrase.find_first_not_of(separators);

    while (start != std::string::npos) {
        size_t end = phrase.find_first_of(separators, start);
        if (end == std::string::npos) {
            words.push_back(phrase.substr(start));
            break;
        }
        words.push_back(phrase.substr(start, end - start));
        start = phrase.find_first_not_of(separators, end);
    }

    return words;
}

struct WordCount {
    std::string word;
    int count;
    bool operator<(const WordCount& other) const {
        if (count != other.count) {
            return count < other.count;
        }
        return word > other.word;
    }
};
int main() {
    std::ifstream inputFile("fisier.txt");
    std::string phrase;
    std::getline(inputFile, phrase);
    inputFile.close();


    std::vector<std::string> words = splitWords(phrase);
    std::map<std::string, int> wordCount;
    for (size_t i = 0; i < words.size(); i++) {
        std::string lowerWord = LowerCase(words[i]);
        wordCount[lowerWord]++;
    }
    for (std::map<std::string, int>::iterator that = wordCount.begin(); that != wordCount.end(); ++that) {
        std::cout << "    \"" << that->first << "\" : " << that->second << std::endl;
    }
    std::cout << std::endl;
    std::priority_queue<WordCount> pq;
    for (std::map<std::string, int>::iterator it = wordCount.begin(); it != wordCount.end(); ++it) {
        WordCount wc;
        wc.word = it->first;
        wc.count = it->second;
        pq.push(wc);
    }
    while (!pq.empty()) {
        WordCount wc = pq.top();
        pq.pop();
        std::cout << "    " << wc.word << " => " << wc.count << std::endl;
    }

    return 0;
}