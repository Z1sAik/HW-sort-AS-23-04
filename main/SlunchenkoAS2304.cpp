#include <iostream>
#include <vector>
#include <algorithm> 
#include <fstream> 

void dualPivotPartition(std::vector<int>& arr, int low, int high, int& pivot1, int& pivot2) {
    if (arr[low] > arr[high]) {
        std::swap(arr[low], arr[high]);
    }

    pivot1 = arr[low];
    pivot2 = arr[high];

    int i = low + 1;
    int lt = low + 1;
    int gt = high - 1;

    while (i <= gt) {
        if (arr[i] < pivot1) {
            std::swap(arr[i], arr[lt]);
            ++lt;
        }
        else if (arr[i] > pivot2) {
            std::swap(arr[i], arr[gt]);
            --gt;
            --i; 
        }
        ++i;
    }

    --lt;
    ++gt;

    std::swap(arr[low], arr[lt]);
    std::swap(arr[high], arr[gt]);

    pivot1 = lt;
    pivot2 = gt;
}

// Рекурсивная функция Dual-Pivot QuickSort
void dualPivotQuickSort(std::vector<int>& arr, int low, int high) {
    if (low < high) {
        int pivot1, pivot2;
        dualPivotPartition(arr, low, high, pivot1, pivot2);

        // Рекурсивно сортируем три части
        dualPivotQuickSort(arr, low, pivot1 - 1);
        dualPivotQuickSort(arr, pivot1 + 1, pivot2 - 1);
        dualPivotQuickSort(arr, pivot2 + 1, high);
    }
}

// Удобная обертка для сортировки
void dualPivotQuickSort(std::vector<int>& arr) {
    dualPivotQuickSort(arr, 0, arr.size() - 1);
}

int main() {
    std::vector<int> arr = { 24, 8, 42, 75, 29, 77, 38, 57 };

    std::ofstream outFile("results.txt"); 
    if (!outFile) {
        std::cerr << "Error opening file for writing" << std::endl;
        return 1;
    }

    std::cout << "Before sorting: ";
    outFile << "Before sorting: ";
    for (int num : arr) {
        std::cout << num << " ";
        outFile << num << " ";
    }
    std::cout << std::endl;
    outFile << std::endl;

    dualPivotQuickSort(arr);

    std::cout << "After sorting: ";
    outFile << "After sorting: ";
    for (int num : arr) {
        std::cout << num << " ";
        outFile << num << " ";
    }
    std::cout << std::endl;
    outFile << std::endl;

    outFile.close(); 

    return 0;
}
