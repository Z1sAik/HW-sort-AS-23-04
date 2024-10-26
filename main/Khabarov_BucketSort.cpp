#include <vector>
#include <algorithm>
#include "algorithms.h"


template <typename T>
int findMaxDigits(const std::vector<T>& data) {
    if (data.empty()) return 0; 
    T maxVal = *std::max_element(data.begin(), data.end());
    int digits = 0;
    while (floor(maxVal) > 0) { 
        maxVal /= 10;
        digits++;
    }
    return digits;
}


template <typename T>
void bucketSort(std::vector<T>& data) {
    int n = data.size();
    if (n == 0) return; 
    int maxDigits = findMaxDigits(data);
    int divisor = 1;

    std::vector<std::vector<T>> buckets(10); 

    for (int digit = 0; digit < maxDigits; digit++) {
      
        for (const T& num : data) {
            int bucketIndex = static_cast<int>(floor(num / divisor)) % 10; 
            buckets[bucketIndex].push_back(num);
        }

       
        int index = 0;
        for (auto& bucket : buckets) {
            for (const T& num : bucket) {
                data[index++] = num;
            }
            bucket.clear(); 
        }

        divisor *= 10; 
    }
}


template <typename T>
std::vector<T> Khabarov_BucketSort(std::vector<T> data) {
    bucketSort(data);
    return data;
}

template std::vector<int> Khabarov_BucketSort<int>(const std::vector<int> data);
template std::vector<double> Khabarov_BucketSort<double>(const std::vector<double> data);