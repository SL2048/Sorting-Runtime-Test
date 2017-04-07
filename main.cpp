#include <iostream>
#include <ctime>
#include <cstdlib>
#include "Sorter.h"
#include "Testbed.h"
#include "QuickSorter.h"
#include "SelectionSorter.h"

using namespace std;

int main()
{
    Testbed t;
    Sorter * s;

    //***************************************
    cout << "running quick sort on random data: " << endl;
    s = new QuickSorter;
    t.runExperiment(s, "random", 5, 500, 1000, 10000, 15, 1000);
    delete s;
    cout << endl << endl;
    //***************************************
    cout << "running quick sort on reverse ordered data: " << endl;
    s = new QuickSorter;
    t.runExperiment(s, "reverse", 5, 500, 1000, 10000, 15, 1000);
    delete s;
    cout << endl << endl;
    //***************************************
    cout << "running selection sort on random data: " << endl;
    s = new SelectionSorter;
    t.runExperiment(s, "random", 5, 500, 1000, 10000, 15, 1000);
    delete s;
    cout << endl << endl;
    //***************************************
    cout << "running selection sort on reverse ordered data: " << endl;
    s = new SelectionSorter;
    t.runExperiment(s, "reverse", 5, 500, 1000, 10000, 15, 1000);
    delete s;
    cout << endl << endl;

    return 0;
}
/*
int arr[10];
    srand(time(0));
    for(int i = 0 ; i < 10 ; i++){
        arr[i] = rand()%10;
        cout << arr[i] << " ";
    }
*/
/*
    Sorter * s;
    s = new SelectionSorter();
    int arr[] = {35, 33, 42, 10, 14, 19, 27, 44, 26, 31};
    s->sort(arr, 10);
    for(int i = 0 ; i < 10 ; i++)
        cout << arr[i] << " ";
*/
