#ifndef COUNTING_H
#define COUNTING_H

#include "sort.h"
#include <algorithm>
#include <vector>

class CountingSort : public Sort {       
    public:
        CountingSort(int *elements, size_t size) : Sort(elements, size) {}

        void execute() override {
            int max = elements[0], sorted[size+1];
            for (int i = 1; i < size; ++i){
                max = (elements[i] > max) ? elements[i] : max;
            }
            int count[max+1] = {0};
            for(int i=0; i<size;i++){
                ++count[elements[i]];
            }   
            for(int i=1; i<=max; i++){
                count[i] += count[i-1];
            }
            for(int i=0;i<size;i++){
                sorted[count[elements[i]]-1] = elements[i];
                --count[elements[i]];
            }
            for(int i=0; i<size; i++){
                elements[i] = sorted[i];
            }
        }

        inline string name() { return "CountingSort"; }
};

#endif