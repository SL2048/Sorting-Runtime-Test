#ifndef SELECTIONSORTER_H
#define SELECTIONSORTER_H

#include "Sorter.h"


class SelectionSorter : public Sorter
{
    public:
        SelectionSorter() {}
        virtual ~SelectionSorter() {}
        void sort(int * arr, int sz);
};

void SelectionSorter::sort(int * arr, int sz){
    for(int i = 0 ; i < sz - 1; i++){
        int m = arr[i];
        int index = i;
        for(int j = i + 1 ; j < sz; j++){
            if(m > arr[j]){
                m = arr[j];
                index = j;
            }
        }
        if(i!=index)
            swap(arr[i], arr[index]);
    }
}

#endif // SELECTIONSORTER_H
