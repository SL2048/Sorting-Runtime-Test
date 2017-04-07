#ifndef QUICKSORTER_H
#define QUICKSORTER_H

#include "Sorter.h"


class QuickSorter : public Sorter
{
    public:
        QuickSorter(){};
        virtual ~QuickSorter(){};
        void sort(int *, int);
    private:
        void quick(int *, int, int);
};
void QuickSorter::sort(int * arr, int sz){
    quick(arr, 0, sz - 1);
}

void QuickSorter::quick(int * arr, int left, int right){
     int i = left, j = right;
      int tmp;
      int pivot = arr[(left + right) / 2];
      while (i <= j) {
            while (arr[i] < pivot)
                  i++;
            while (arr[j] > pivot)
                  j--;
            if (i <= j) {
                  tmp = arr[i];
                  arr[i] = arr[j];
                  arr[j] = tmp;
                  i++;
                  j--;
            }
      }
      if (left < j)
            quick(arr, left, j);
      if (i < right)
            quick(arr, i, right);
}
#endif // QUICKSORTER_H
