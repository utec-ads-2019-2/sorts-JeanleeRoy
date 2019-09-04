#ifndef INSERT_H
#define INSERT_H

#include "sort.h"

class InsertSort : public Sort {       
    public:
        InsertSort(int *elements, size_t size) : Sort(elements, size) {}

        void execute() {
            int key;  
            for (int i = 1; i < size; i++) {  
                key = elements[i];  
                int j = i - 1;  
                while (j >= 0 && elements[j] > key) {  
                    elements[j + 1] = elements[j];  
                    j--;  
                }  
                elements[j + 1] = key;  
            }  
        }

        inline string name() { return "InsertSort"; }
};

#endif