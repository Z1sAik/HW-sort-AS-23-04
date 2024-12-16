#include <iostream>
#include <vector>
#include <algorithm>
#include "algorithms.h"

template <typename T>
std::pair<T,T> findMinMax(const std::vector<T>& data) {
    int minVal = data[0];
    int maxVal = data[0];
    for (int num : data) {
        if (num < minVal) minVal = num;
        if (num > maxVal) maxVal = num;
    }
    return { minVal, maxVal };
}

template <typename T>
void flashSort(std::vector<T>& data) {
    int n = data.size();
    if (n <= 1) return;

    auto [minVal, maxVal] = findMinMax(data);

    if (minVal == maxVal) return;

    int m = static_cast<T>(0.2 * n);
    std::vector<T> L(m, 0);

    for (int i = 0; i < n; i++) {
        int index = (m - 1) * (data[i] - minVal) / (maxVal - minVal);
        L[index]++;
    }

    for (int i = 1; i < m; i++) {
        L[i] += L[i - 1];
    }

    std::vector<T> temp(n);
    for (int i = n - 1; i >= 0; i--) {
        int value = data[i];
        int index = (m - 1) * (value - minVal) / (maxVal - minVal);

        temp[L[index] - 1] = value;
        L[index]--;
    }

    data = std::move(temp);

    for (int i = 0; i < m; i++) {
        int start = (i == 0) ? 0 : L[i - 1];
        int end = L[i];

        if (start < end) {
            std::sort(data.begin() + start, data.begin() + end);
        }
    }
}

template <typename T>
std::vector<T> Osharov_flashsort(std::vector<T> data) {
    flashSort(data);
    return data;
}

template std::vector<int> Osharov_flashsort<int>(const std::vector<int> data);
template std::vector<double> Osharov_flashsort<double>(const std::vector<double> data);