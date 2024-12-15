#include <iostream>
#include <vector>
#include <algorithm>
#include "algorithms.h"



template <typename T>
int Partition(std::vector<T>& arr, int low, int high) { //раздел€ет массив на 2 части + выбираем серединный элемент как опорный. можно другой.

    int pivot = arr[high/2];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] <= pivot) {
            i++;
            std::swap(arr[i], arr[j]);
        }
    }
    std::swap(arr[i + 1], arr[high]);
    return (i + 1);
}

template <typename T>
void Heapify(std::vector<T>& arr, int n, int i) { // корень поддерера
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        std::swap(arr[i], arr[largest]);
        Heapify(arr, n, largest);
    }
}
template <typename T>
void BuildHeap(std::vector<T>& arr, int n) { // делает кучу массива чисел дл€ создани€ дерева, пирамиды
    for (int i = n / 2 - 1; i >= 0; i--)
        Heapify(arr, n, i);
}
template <typename T>
void HeapSort(std::vector<T>& arr, int n) { // замена чисел, сам процесс пирамидальной сортировки
    BuildHeap(arr, n);

    for (int i = n - 1; i >= 0; i--) {
        std::swap(arr[0], arr[i]);
        Heapify(arr, i, 0);
    }
}


template <typename T>
void InsertionSort(std::vector<T>& arr, int low, int high) { //сортировка ¬—“ј¬ јћ»
    for (int i = low + 1; i <= high; ++i) {
        int key = arr[i];
        int j = i - 1;

        while (j >= low && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// Introsort
template <typename T>
void IntroSort(std::vector<T>& arr, int low, int high, int depthLimit) {
    if (depthLimit == 0) {
        HeapSort(arr, high - low + 1); // почти отсортированный массив -> идЄм в ѕ»–јћ»ƒјЋ№Ќ”ё сортировку
        return;
    }

    if (high - low < 16) {  // если размер массива меньше 16 - вызываетс€ сортировка ¬—“ј¬ јћ»
        InsertionSort(arr, low, high);
        return;
    }

    int pi = Partition(arr, low, high); // противный случай - Ѕџ—“–јя сортировку
    IntroSort(arr, low, pi - 1, depthLimit - 1); //и по новой
    IntroSort(arr, pi + 1, high, depthLimit - 1);
}


template <typename T> // ќсновна€ функци€ Introspective
void IntrospectiveSort(std::vector<T>& arr) {  
    int n = arr.size();
    int maxDepth = 2 * log2(n); // √лубина, необходима дл€ переключени€ режима
    IntroSort(arr, 0, n - 1, maxDepth);
}



template <typename T>
std::vector<T> Khabarov_introspectiveSort(std::vector<T> data) { // вызов сортировки
    IntrospectiveSort(data);
    return data;
}


template std::vector<int> Khabarov_introspectiveSort(std::vector<int> data); // дл€ int
template std::vector<double> Khabarov_introspectiveSort(std::vector<double> data); // дл€ double