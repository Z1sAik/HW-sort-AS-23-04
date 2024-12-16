#pragma once
#include <vector>
#include <algorithm>

template <typename T>
std::vector<T> Kochetov_TreeSort(std::vector<T> data);

template <typename T>
std::vector<T> Khabarov_introspectiveSort( std::vector<T> data);

template <typename T>
std::vector<T> Osharov_flashsort(const std::vector<T> data);

