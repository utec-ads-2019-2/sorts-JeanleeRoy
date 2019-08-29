#ifndef BUBBLE_H
#define BUBBLE_H

#include "sort.h"
#include <algorithm>

class BubbleSort : public Sort {       
    public:
        BubbleSort(int *elements, size_t size) : Sort(elements, size) {}

        void execute() override {
            bool swapped;
            for (int i = 0; i < size-1; ++i){
                swapped = false;
                for (int j = 0; j < size-i-1; ++j)
                    if (elements[j] > elements[j+1]) {
                        std::swap(elements[j], elements[j+1]);
                        swapped = true;
                    }
                if (!swapped)
                    break;
            }
        }

        inline string name() { return "BubbleSort"; }
};

#endif