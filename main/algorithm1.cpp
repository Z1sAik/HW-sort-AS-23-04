#include "algorithms.h"
#include <algorithm>
// Реализация алгоритма 1 (стандартная сортировка)
template <typename T>
std::vector<T> algorithm1(std::vector<T> data)
{
    std::sort(data.begin(), data.end()); // Сортируем данные
    return data; // Возвращаем отсортированный вектор
}
template std::vector<int> algorithm1(std::vector<int> data);
template std::vector<double> algorithm1(std::vector<double> data);
