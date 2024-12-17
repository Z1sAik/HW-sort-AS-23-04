#pragma once
#include <vector>
#include <random>
#include <algorithm> 

const std::vector<int> data1 = {34, 7, 23, 32, 5, 62, 32, 43, 7, 3};

const std::vector<double> data2 = { 3.1, 7.1, 235, 323, 5, 612, 32, 433, 7, 3 };

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

std::vector<int> generate_sorted_vector(size_t size, int min, int max) {
    std::vector<int> vec(size);
    for (size_t i = 0; i < size; ++i) {
        vec[i] = min + i;
    }
    return vec;
}

std::vector<int> generate_reverse_sorted_vector(size_t size, int min, int max) {
    std::vector<int> vec(size);
    for (size_t i = 0; i < size; ++i) {
        vec[i] = min + i;
    }
    std::reverse(vec.begin(), vec.end());
    return vec;
}

std::vector<int> generate_array_with_duplicates(size_t size, int duplicate_value, int min, int max) {
    std::vector<int> vec(size, duplicate_value);
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(min, max);

    for (size_t i = 0; i < size / 10; ++i) {
        vec[i] = dis(gen);
    }

    return vec;
}

std::vector<double> generate_double_array(size_t size, double min, double max) {
    std::vector<double> vec(size);
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(min, max);

    for (size_t i = 0; i < size; ++i) {
        vec[i] = dis(gen);
    }
    return vec;
}

std::vector<int> generate_negative_array(size_t size, int min, int max) {
    std::vector<int> vec(size);
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(min, max);

    for (size_t i = 0; i < size; ++i) {
        vec[i] = -dis(gen);
    }
    return vec;
}


//все рандомные
std::vector<int> random_ints100 = generate_random_int_vector(100, 1, 10000);
std::vector<int> random_ints1000 = generate_random_int_vector(1000, 1, 10000);
std::vector<int> random_ints10000 = generate_random_int_vector(10000, 1, 10000);

//отсортированные
std::vector<int> sorted = generate_sorted_vector(1000, 0, 999);

//обратно отсортированные
std::vector<int> reverse_sorted = generate_reverse_sorted_vector(1000, 0, 999);

//большое кол-во одинаковых элементов 10% только случайные
std::vector<int> duplicates = generate_array_with_duplicates(1000, 10, 0, 500);

//Вещественные числа
std::vector<double> random_doubles = generate_double_array(10000, -100.0, 100.0);

//отриц числа
std::vector<int> otric_numbers = generate_negative_array(10000, 1, 1000);