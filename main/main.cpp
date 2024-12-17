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
        outFile << "Первые 10 отсортированных данных: ";
        for (size_t i = 0; i < std::min(sortedData.size(), size_t(10)); ++i) {
            outFile << sortedData[i] << " ";
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

    Run<int>("Kochetov_smoothort - data(random_ints100)", Kochetov_TreeSort<int>, random_ints100);
    Run<int>("Kochetov_smoothort - data(random_ints1000)", Kochetov_TreeSort<int>, random_ints1000);
    Run<int>("Kochetov_smoothort - data(random_ints10000)", Kochetov_TreeSort<int>, random_ints10000);
    Run<int>("Kochetov_smoothort - data(sorted)", Kochetov_TreeSort<int>, sorted);
    Run<int>("Kochetov_smoothort - data(reverse_sorted)", Kochetov_TreeSort<int>, reverse_sorted);
    Run<int>("Kochetov_smoothort - data(duplicates)", Kochetov_TreeSort<int>, duplicates);
    Run<double>("Kochetov_smoothort - data(random_doubles)", Kochetov_TreeSort<double>, random_doubles);
    Run<int>("Kochetov_smoothort - data(otric_numbers)", Kochetov_TreeSort<int>, otric_numbers);

    Run<int>("Khabarov_introspectiveSort - data(random_ints100)", Khabarov_introspectiveSort<int>, random_ints100);
    Run<int>("Khabarov_introspectiveSort - data(random_ints1000)", Khabarov_introspectiveSort<int>, random_ints1000);
    Run<int>("Khabarov_introspectiveSort - data(random_ints10000)", Khabarov_introspectiveSort<int>, random_ints10000);
    Run<int>("Khabarov_introspectiveSort - data(sorted)", Khabarov_introspectiveSort<int>, sorted);
    Run<int>("Khabarov_introspectiveSort - data(reverse_sorted)", Khabarov_introspectiveSort<int>, reverse_sorted);
    Run<int>("Khabarov_introspectiveSort - data(duplicates)", Khabarov_introspectiveSort<int>, duplicates);
    Run<double>("Khabarov_introspectiveSort - data(random_doubles)", Khabarov_introspectiveSort<double>, random_doubles);
    Run<int>("Khabarov_introspectiveSort - data(otric_numbers)", Khabarov_introspectiveSort<int>, otric_numbers);

    Run<int>("Osharov_flashsort - data(random_ints100)", Osharov_flashsort<int>, random_ints100);
    Run<int>("Osharov_flashsort - data(random_ints1000)", Osharov_flashsort<int>, random_ints1000);
    Run<int>("Osharov_flashsort - data(random_ints10000)", Osharov_flashsort<int>, random_ints10000);
    Run<int>("Osharov_flashsort - data(sorted)", Osharov_flashsort<int>, sorted);
    Run<int>("Osharov_flashsort - data(reverse_sorted)", Osharov_flashsort<int>, reverse_sorted);
    Run<int>("Osharov_flashsort - data(duplicates)", Osharov_flashsort<int>, duplicates);
    Run<double>("Osharov_flashsort - data(random_doubles)", Osharov_flashsort<double>, random_doubles);
    Run<int>("Osharov_flashsort - data(otric_numbers)", Osharov_flashsort<int>, otric_numbers);

    Run<int>("Sliunchenko_dualpivotsort - data(random_ints100)", dualpivotsort<int>, random_ints100);
    Run<int>("Sliunchenko_dualpivotsort - data(random_ints1000)", dualpivotsort<int>, random_ints1000);
    Run<int>("Sliunchenko_dualpivotsort - data(random_ints10000)", dualpivotsort<int>, random_ints10000);
    Run<int>("Sliunchenko_dualpivotsort - data(sorted)", dualpivotsort<int>, sorted);
    Run<int>("Sliunchenko_dualpivotsort - data(reverse_sorted)", dualpivotsort<int>, reverse_sorted);
    Run<int>("Sliunchenko_dualpivotsort - data(duplicates)", dualpivotsort<int>, duplicates);
    Run<double>("Sliunchenko_dualpivotsort - data(random_doubles)", dualpivotsort<double>, random_doubles);
    Run<int>("Sliunchenko_dualpivotsort - data(otric_numbers)", dualpivotsort<int>, otric_numbers);
    
    return 0;
}

