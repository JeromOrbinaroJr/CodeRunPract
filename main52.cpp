// Вам дан словарь, состоящий из пар слов. 
// Каждое слово является синонимом к парному ему слову. 
// Все слова в словаре различны. Для одного данного слова определите его синоним.

// Программа получает на вход количество пар синонимов N. 
// Далее следует N строк, каждая строка содержит ровно два слова-синонима. После этого следует одно слово.

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>

std::string findingSynonym(const std::vector<std::string>& synonyms, const std::string& mainWord) {
    for (size_t i = 0; i < synonyms.size(); i += 2) {
        std::string firstSynonym = synonyms[i];
        std::string secondSynonym = synonyms[i + 1];
        
        if (mainWord == firstSynonym) {
            return secondSynonym;
        }
        else if (mainWord == secondSynonym) {
            return firstSynonym;
        }
    }
    return "untitled";
}

int main() {
    std::ifstream inputFile;
    
    int N;
    std::string word1, word2;
    std::vector<std::string> synonyms;
    std::string mainWord;
    
    inputFile.open("input.txt");
    if (inputFile.is_open()) {
        inputFile >> N;
        for (int i = 0; i < N; ++i) {
            inputFile >> word1 >> word2;
            synonyms.push_back(word1);
            synonyms.push_back(word2);
        }
        inputFile >> mainWord;
    }
    inputFile.close();
    
    std::string exactSynonym = findingSynonym(synonyms, mainWord);
    
    std::ofstream outputFile;
    outputFile.open("output.txt");
    if (outputFile.is_open()) {
        outputFile << exactSynonym;
    }
    outputFile.close();
    
    return 0;
}
