#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

int calculatingMinimumWeight(int N, int M, std::vector<std::vector<int>>steps) {
    std::vector<std::vector<int>>tempSteps(N, std::vector<int>(M));

    tempSteps[0][0] = steps[0][0];
    for (int i = 1; i < N; ++i) {
        tempSteps[i][0] = steps[i][0] + tempSteps[i - 1][0];
    }
    for (int j = 1; j < M; ++j) {
        tempSteps[0][j] = steps[0][j] + tempSteps[0][j - 1];
    }

    for (int i = 1; i < N; ++i) {
        for (int j = 1; j < M; ++j) {
            tempSteps[i][j] = std::min(tempSteps[i][j - 1], tempSteps[i - 1][j]) + steps[i][j];
        }
    }

    return tempSteps[N - 1][M - 1];
}

int main() {
    std::ifstream inputFile;

    int N{0};
    int M{0};
    std::vector<std::vector<int>> steps;

    inputFile.open("input.txt");
    if (inputFile.is_open()) {
        inputFile >> N >> M;
        steps.resize(N, std::vector<int>(M));
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < M; ++j) {
                inputFile >> steps[i][j];
            }
        }
   }

   std::cout << calculatingMinimumWeight(N, M, steps) << std::endl;

   return 0;
}