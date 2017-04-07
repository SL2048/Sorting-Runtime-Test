#ifndef TESTBED_H
#define TESTBED_H

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <algorithm>
#include "Sorter.h"

using namespace std;

class Testbed
{
    public:
        Testbed();
        virtual ~Testbed();
        int * generateRandomList(int, int, int);
        int * generateReverseOrderedList(int, int, int);
        double runOnce(Sorter *, int *, int);
        double runAndAverage(Sorter *, string, int, int, int, int);
        void runExperiment(Sorter *, string, int, int,int, int, int, int);
};

#endif // TESTBED_H
