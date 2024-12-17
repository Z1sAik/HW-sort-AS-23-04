#include <iostream>
#include <vector>
#include <algorithm>
#include "algorithms.h"

// Вспомогательная функция для выполнения разбиения с двумя опорными элементами
template <typename T>
int partition(std::vector<T>& data, int low, int high, T& pivot1, T& pivot2) {
    int left = low + 1;
    int right = high - 1;
    int i = low + 1;

    while (i <= right) {
        if (data[i] < pivot1) {
            std::swap(data[i], data[left]);
            left++;
        }
        else if (data[i] > pivot2) {
            while (data[right] > pivot2 && i < right) {
                right--;
            }
            std::swap(data[i], data[right]);
            right--;
            if (data[i] < pivot1) {
                std::swap(data[i], data[left]);
                left++;
            }
        }
        i++;
    }

    left--;
    right++;
    std::swap(data[low], data[left]);
    std::swap(data[high], data[right]);

    return left;
}

// Рекурсивная функция сортировки с двумя опорными элементами
template <typename T>
void dualpivotsort_rec(std::vector<T>& data, int low, int high) {
    if (low < high) {
        T pivot1 = data[low];
        T pivot2 = data[high];

        if (pivot1 > pivot2) {
            std::swap(pivot1, pivot2);
        }

        int pivotIndex = partition(data, low, high, pivot1, pivot2);
        dualpivotsort_rec(data, low, pivotIndex - 1);
        dualpivotsort_rec(data, pivotIndex + 1, high);
    }
}

// Основная функция сортировки с двумя опорными элементами
template <typename T>
std::vector<T> dualpivotsort(std::vector<T> data) {
    // Функция сортировки теперь не выводит массив, а просто возвращает отсортированный
    dualpivotsort_rec(data, 0, data.size() - 1);
    return data;
}

// Явная инстанциация шаблонов для типов int и double
template std::vector<int> dualpivotsort<int>(std::vector<int> data);
template std::vector<double> dualpivotsort<double>(std::vector<double> data);