#include "Testbed.h"

using namespace std;

struct comp {
  bool operator() (int i,int j) { return (i>j);}
}comparator;

Testbed::Testbed()
{
    //ctor
}

Testbed::~Testbed()
{
    //dtor
}

int * Testbed::generateRandomList(int min, int max, int size){
    int * arr;
    arr = new int[size];
    srand(time(0));
    for(int i = 0 ; i < size ; i++){
        arr[i] = rand()%(max - min + 1) + min;
    }
    return arr;
}

int * Testbed::generateReverseOrderedList(int min, int max, int size){
    int * arr;
    arr = this->generateRandomList(min, max, size);
    sort(arr, arr+size, comparator);
    return arr;
}

double Testbed::runOnce(Sorter * mySortet, int * data, int size){
    clock_t start = clock();
    mySortet->sort(data, size);
    clock_t finish = clock();
    double result = (double)(finish - start) / CLOCKS_PER_SEC;
    /*cout << fixed;
    cout << "Run Time is: " << setprecision(8) << result;*/
    return result;
}

double Testbed::runAndAverage(Sorter * mySorter, string type, int min, int max,int size,  int sets_num){
    bool random = true;
    if(type == "reverse")
        random = false;
    double sum = 0.0;
    for(int i = 0 ; i < sets_num ; i++){
        int * arr;
        double runtime;
        arr = random ? generateRandomList(min, max, size) : generateReverseOrderedList(min, max, size);
        runtime = runOnce(mySorter, arr, size);
        /*
        cout << fixed;
        cout << "Run Time is: " << setprecision(8) << runtime << endl;
        */
        sum += runtime;
    }
    return sum / sets_num;
}

void Testbed::runExperiment(Sorter * mySorter, string type, int min, int max, int min_val, int max_val, int sets_num, int step){
    int itr = min_val;
    while(itr <= max_val){
        double avr;
        cout << "when size = " << itr << endl;
        avr = runAndAverage(mySorter, type, min, max, itr, sets_num);
        cout << "Average runtime = " << avr << endl;
        cout << "*******************************************"  << endl;
        itr += step;

    }
}
