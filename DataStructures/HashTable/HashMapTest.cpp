#include <iostream>
#include <fstream>
#include <sstream>
#include <cctype>
#include <vector>
#include <algorithm> // for std::sort
#include "include/HashMap.h" // Adjust this include according to your file structure

void toLower(std::string& str) {
    for (char& c : str) {
        c = std::tolower(c);
    }
}




int main() {
    size_t totalWords = 0;
    HashMap<std::string, int> wordCountMap;
    std::ifstream file("shakespeare.txt"); 

    if (!file.is_open()) {
        std::cerr << "Failed to open file.\n";
        return 1;
    }

    std::string line, word;
    while (std::getline(file, line)) {
        std::istringstream lineStream(line);
        while (lineStream >> word) {
          totalWords++;
            toLower(word); // Optional: converts word to lowercase
            if (wordCountMap.containsKey(word)) {
                wordCountMap.get(word)++;
            } else {
                wordCountMap.insert(word, 1);
            }
        }
    }

    file.close();

    // Extracting key-value pairs into a vector
    std::vector<std::pair<std::string, int>> elements;
    for (const auto& kv : wordCountMap) {
        elements.push_back({kv.key, kv.value});
    }

    // Sorting the vector based on frequency
    std::sort(elements.begin(), elements.end(),
              [](const std::pair<std::string, int>& a, const std::pair<std::string, int>& b) {
                  return a.second > b.second; // sort in descending order
              });

    // Printing the first 10 elements
    int count = 0;
    std::cout << "Out of the " << totalWords << " in the text provided\n";
    std::cout << "The first 10 words with the most occurances in the text are: \n";
    for (const auto& kv : elements) {
        if (count >= 10) break;
        std::cout << kv.first << ": " << kv.second << std::endl;
        count++;
    }

    return 0;
}
