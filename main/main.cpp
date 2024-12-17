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
        outFile << "���������� ��� ���������: " << algorithm_name << "\n";
        outFile << "��������������� ������: ";
        for (T num : sortedData) {
            outFile << num << " ";
        }
        outFile << "\n����� ����������: " << std::fixed << std::setprecision(8) << duration << " ������\n\n";
        outFile.close();
        std::cout << "���������� �������� � results.txt" << std::endl;
    }
    else {
        std::cerr << "�� ������� ������� ���� results.txt" << std::endl;
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

    Run<int>("Kochetov_smoothsort - data1", Kochetov_TreeSort<int>, data1);

    Run<double>("Kochetov_smoothsort - data2", Kochetov_TreeSort<double>, data2);

    Run<int>("Kochetov_smoothort - data3", Kochetov_TreeSort<int>, random_ints);


    Run<int>("Khabarov_introspectiveSort - data1", Khabarov_introspectiveSort<int>, data1);

    Run<double>("Khabarov_introspectiveSort - data2", Khabarov_introspectiveSort<double>, data2);

    Run<int>("Khabarov_introspectiveSort - data3", Khabarov_introspectiveSort<int>, random_ints);


    Run<int>("Osharov_flashsort - data1", Osharov_flashsort<int>, data1);

    Run<double>("Osharov_flashsort - data2", Osharov_flashsort<double>, data2);

    Run<int>("Osharov_flashsort - data3", Osharov_flashsort<int>, random_ints);

    Run<int>("Sliunchenko_dualpivotsort - data1", dualpivotsort<int>, data1);

    Run<double>("Sliunchenko_dualpivotsort - data2", dualpivotsort<double>, data2);

    Run<int>("Sliunchenko_dualpivotsort - data3", dualpivotsort<int>, random_ints);

    return 0;
}

