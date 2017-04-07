#ifndef SORTER_H
#define SORTER_H


class Sorter
{
    public:
        Sorter(){};
        virtual ~Sorter(){};
        virtual void sort(int * arr, int sz){};
        static void swap(int &a, int &b){
            a ^= b;
            b ^= a;
            a ^= b;
        }
};


#endif // SORTER_H
