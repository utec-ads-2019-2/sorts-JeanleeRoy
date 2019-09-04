#ifndef MERGE_H
#define MERGE_H

#include "sort.h"

class MergeSort : public Sort {       
    public:
        MergeSort(int *elements, size_t size) : Sort(elements, size) {}
        void Merge(int *arr, int lo, int  mi, int hi){
            int *temp = new int[hi-lo+1];
            int i = lo, j = mi + 1;
            int k = 0;
            while(i <= mi && j <=hi){
                if(arr[i] <= arr[j])
                    temp[k++] = arr[i++];
                else
                    temp[k++] = arr[j++];
            }
            while(i <= mi)
                temp[k++] = arr[i++];
            while(j <= hi)
                temp[k++] = arr[j++];
            for(k = 0, i = lo; i <= hi; ++i, ++k)
                arr[i] = temp[k];
            delete []temp;
        }
        void MergeSortHelper(int *arr, int lo, int hi){
            int mid;
            if (lo < hi) {
                mid = (lo + hi) >> 1;
                this->MergeSortHelper(arr, lo, mid);
                this->MergeSortHelper(arr, mid+1, hi);
                this->Merge(arr, lo, mid, hi);
            }
        }
        void execute() {
            this->MergeSortHelper(elements, 0, size-1);
        }

        inline string name() { return "MergeSort"; }
};

#endif