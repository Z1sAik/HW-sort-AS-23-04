#pragma once
#include <vector>
#include <random>
#include <algorithm> 

const std::vector<int> data1 = {34, 7, 23, 32, 5, 62, 32, 43, 7, 3}; // Вектор данных

const std::vector<double> data2 = { 3.1, 7.1, 235, 323, 5, 612, 32, 433, 7, 3 }; // Вектор данных

std::vector<int> generate_random_int_vector(size_t size, int min, int max) {
    std::vector<int> vec(size);
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(min, max);

    for (size_t i = 0; i < size; ++i) {
        vec[i] = dis(gen);
    }

    return vec;
}

std::vector<int> random_ints = generate_random_int_vector(10, 1, 100);