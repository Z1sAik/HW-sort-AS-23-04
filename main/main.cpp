#include <iostream>
#include <chrono>
#include <fstream>
#include <iomanip>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include "algorithms.h"
#include "data.h"

template <typename T>
void write_results_to_file(const std::string& algorithm_name, const std::vector<T>& sortedData, double duration) {
    std::ofstream outFile("results.txt", std::ios::app);
    if (outFile.is_open()) {
        outFile << "Результаты для алгоритма: " << algorithm_name << "\n";
        outFile << "Отсортированные данные: ";
        for (T num : sortedData) {
            outFile << num << " ";
        }
        outFile << "\nВремя выполнения: " << std::fixed << std::setprecision(8) << duration << " секунд\n\n";
        outFile.close();
        std::cout << "Результаты записаны в results.txt" << std::endl;
    }
    else {
        std::cerr << "Не удалось открыть файл results.txt" << std::endl;
    }
}

template <typename T, typename Algorithm>
void Run(const std::string& method_name, Algorithm algorithm, const std::vector<T>& data) {
    auto start = std::chrono::system_clock::now();
    std::vector<T> res = algorithm(data);
    auto stop = std::chrono::system_clock::now();
    auto time = std::chrono::duration_cast<std::chrono::microseconds>(stop - start).count();

    write_results_to_file(method_name, res, static_cast<double>(time) / 1e6);
}

int main() {
    setlocale(LC_ALL, "RU");

    Run<int>("Algorithm 1 - data1", algorithm1<int>, data1);

    Run<double>("Algorithm 1 - data2", algorithm1<double>, data2);

    Run<int>("Algorithm 1 - data3", algorithm1<int>, random_ints);
    return 0;
}
