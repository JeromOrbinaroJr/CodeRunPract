#include <iostream>
#include <fstream>
#include <string>

std::string brickPass(int A,int B ,int C , int D, int E) {
    bool answer = 
        (A <= D && B <= E) || (A <= E && B <= D) ||
        (A <= D && C <= E) || (A <= E && C <= D) ||
        (B <= D && C <= E) || (B <= E && C <= D);
    return answer ? "YES" : "NO";
}

int main() {
    std::ifstream inputFile;
    int A, B, C, D, E;

    inputFile.open("input.txt");
    if (inputFile.is_open()) {
        inputFile >> A;
        inputFile >> B;
        inputFile >> C;
        inputFile >> D;
        inputFile >> E;
    }
    inputFile.close();

    std::cout << brickPass(A, B, C, D, E) << std::endl;

    return 0;
}