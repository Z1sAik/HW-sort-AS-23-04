#include "algorithms.h"
#include <algorithm>
// ���������� ��������� 1 (����������� ����������)
template <typename T>
std::vector<T> algorithm1(std::vector<T> data)
{
    std::sort(data.begin(), data.end()); // ��������� ������
    return data; // ���������� ��������������� ������
}
template std::vector<int> algorithm1(std::vector<int> data);
template std::vector<double> algorithm1(std::vector<double> data);
