#ifndef QUICK_H
#define QUICK_H

#include "sort.h"

class QuickSort : public Sort {       
    public:
        QuickSort(int *elements, size_t size) : Sort(elements, size) {}
        int partition (int* arr, int low, int high) {  
            int pivot = arr[high];
            int i = (low - 1);
            for (int j = low; j <= high - 1; j++) {  
                if (arr[j] < pivot) {  
                    i++;
                    std::swap(arr[i], arr[j]);  
                }  
            }  
            std::swap(arr[i + 1], arr[high]);  
            return (i + 1);  
        }
        void quickSortHelper (int *arr, int low, int high) {  
            if (low < high) {
                int pi = this->partition(arr, low, high);
                this->quickSortHelper(arr, low, pi - 1);  
                this->quickSortHelper(arr, pi + 1, high);  
            }  
        }
        void execute() {
            this->quickSortHelper(elements, 0, size-1);
        }

        inline string name() { return "QuickSort"; }
};

#endif