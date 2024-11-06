#include <iostream>
#include <vector>
#include <algorithm>
#include "algorithms.h"

using namespace std;

// ������� ��� ������ ���������
template <typename T>
void swapp(T& a, T& b) {
    T temp = a;
    a = b;
    b = temp;
}

// ������� siftDown ��� ����������� �������� ����
template <typename T>
void siftDown(vector<T>& heap, int root, int end) {
    int child = root * 2 + 1;
    while (child <= end) {
        if (child + 1 <= end && heap[child] < heap[child + 1]) {
            child++;
        }
        if (heap[root] < heap[child]) {
            swapp(heap[root], heap[child]);
            root = child;
            child = root * 2 + 1;
        }
        else {
            return;
        }
    }
}

// ���������� ��������� Kochetov_Smoothsort
template <typename T>
std::vector<T> Kochetov_TreeSort(std::vector<T> data) {
    int n = data.size();

    // ��� 1: ���������� ���� � ������� siftDown
    for (int i = (n / 2) - 1; i >= 0; i--) {
        siftDown(data, i, n - 1);
    }

    // ��� 2: ���������� ��������� � ��������������� �������
    for (int i = n - 1; i > 0; i--) {
        swapp(data[0], data[i]);
        siftDown(data, 0, i - 1);
    }

    return data;
}

// ����� ������������� ��� int 
template std::vector<int> Kochetov_TreeSort(std::vector<int> data);
template std::vector<double> Kochetov_TreeSort(std::vector<double> data);