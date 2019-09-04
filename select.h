#ifndef SELECT_H
#define SELECT_H

#include "sort.h"

class SelectSort : public Sort {       
    public:
        SelectSort(int *elements, size_t size) : Sort(elements, size) {}

        void execute() {
            int min_idx;
            for (int i = 0; i < size-1; i++) {  
                min_idx = i;  
                for (int j = i+1; j < size; j++)  
                    if (elements[j] < elements[min_idx])  
                        min_idx = j;
                std::swap(elements[min_idx], elements[i]);  
            }  
        }

        inline string name() { return "SelectSort"; }
};

#endif