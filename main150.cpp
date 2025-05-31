// По данному числу N определите количество последовательностей из нулей и единиц длины N,
// в которых никакие три единицы не стоят рядом.
// Во входном файле написано натуральное число N N, не превосходящее 35.
// Выведите количество искомых последовательностей.

#include <iostream>
#include <vector>

int correctSequences (int N) {
    if (N == 0) return 1;

    if (N == 1) return 2;

    if (N == 2) return 4;

    std::vector<long long>tempArr(N + 1);

    tempArr[0] = 1;
    tempArr[1] = 2;
    tempArr[2] = 4;

    for (int i = 3; i <= N; ++i) {
        tempArr[i] = tempArr[i - 1] + tempArr[i - 2] + tempArr[i - 3]; 
    }

    return tempArr[N];
}

int main() {
    int N{0};
    std::cin >> N;

    std::cout << correctSequences(N) << std::endl;

    return 0;
}