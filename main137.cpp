// На клетчатой плоскости закрашено K клеток. 
// Требуется найти минимальный по площади прямоугольник, со сторонами, параллельными линиям сетки, покрывающий все закрашенные клетки.
// Выведите в выходной файл координаты левого нижнего и правого верхнего углов прямоугольника.
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <limits>

std::vector<int>searchCoordinates(int k, std::vector<int>coordinateX, std::vector<int>coordinateY){ // Функция возращает вектор с двумя координатами, координаты левого нижнего и правого верхнего углов прямоугольника
    int min_x = std::numeric_limits<int>::max(), max_x = std::numeric_limits<int>::min(); // Минимальное и максимальное число для X
    int min_y = std::numeric_limits<int>::max(), max_y = std::numeric_limits<int>::min(); // Минимальное и максимальное число для Y

    // Далее ищем соответствующие координаты с помощью сравнения max и min
    for (int i = 0; i < k; ++i) {
        max_x = std::max(max_x, coordinateX.at(i));
        max_y = std::max(max_y, coordinateY.at(i));
        min_x = std::min(min_x, coordinateX.at(i));
        min_y = std::min(min_y, coordinateY.at(i));
    }
    std::vector<int>finalCoordinates{min_x, min_y, max_x, max_y}; // Собираем координаты в один вектор 

    return finalCoordinates; // Возвращаем данный вектор
}

int main() {
    std::ifstream inputFile;
    std::ofstream outputFile;

    int k; // Количество закрашенных клеток 
    std::vector<int>coordinateX; // Координаты по X закрашенных клеток
    std::vector<int>coordinateY; // Координаты по Y закрашенных клеток

    inputFile.open("input.txt");
    if (inputFile.is_open()) {
        inputFile >> k; // Первой строкой получаем количество закрашенных клеток

        for (int i = 0; i < k; ++i) {
            int x, y;
            inputFile >> x >> y; // Далее построчно считываем координаты закрашенных клеток и закидываем в вектора X и Y
            coordinateX.push_back(x);
            coordinateY.push_back(y);
        }
        inputFile.close();
    }

    std::vector<int>finalCoordinates = searchCoordinates(k, coordinateX, coordinateY); // Вызываем функцию поиска координат левого нижнего и правого верхнего углов прямоугольника

    outputFile.open("output.txt");
    if (outputFile.is_open()) {
        outputFile << finalCoordinates.at(0) << " " << finalCoordinates.at(1) << " " << finalCoordinates.at(2) << " " << finalCoordinates.at(3) << std::endl; // Вывод координаты одной строкой
    }
    outputFile.close();
    return 0;
}