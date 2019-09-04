#ifndef RADIX_H
#define RADIX_H

#include "sort.h"

class RadixSort : public Sort {       
    public:
        RadixSort(int *elements, size_t size) : Sort(elements, size) {}
        void CountingSort(int *elements, int n, int exp) {  
            int result[n], count[10] = {0};
            for (int i = 0; i < n; i++)
                count[(elements[i] / exp) % 10]++;
            for (int i = 1; i<10; i++)
                count[i] += count[i-1];
            for (int i = n-1; i>= 0; i--) {
                result[count[(elements[i] / exp) % 10] - 1] = elements[i];
                count[(elements[i] / exp) % 10]--;
            }
            for (int i =0; i <n; i++)
                elements[i] = result[i];
        }
        void execute() {
            int max = elements[0];
            for (int i = 1; i < size; ++i)
                max = (elements[i] > max) ? elements[i] : max;
            for (int exp = 1; max/exp > 0; exp *= 10)
                this->CountingSort(elements, size, exp);
        }

        inline string name() { return "RadixSort"; }
};

#endif