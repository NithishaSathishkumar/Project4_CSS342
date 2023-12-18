/* Nithisha Sathishkumar
* Novemeber 13, 2023
* Project 1
* Professor.Dimpsey
*/

#include "sorts.h"
#include<vector>
#include<iostream>
using namespace std;

void PrintSort(vector<int> &vecs){
    for(int i = 0; i < vecs.size(); i++){
        cout << vecs[i] << " ";
    }
    cout << endl;
}

int main(){
    vector<int> vec = {1, 7, 9, 11, 3, 15, 5, 17, 19, 13};
    PrintSort(vec);
    //IterativeMergeSort(vec, 0, vec.size() - 1);
    //IterativeMergeSort(vec, 2, vec.size() - 1);
    IterativeMergeSort(vec, 2, 5);
    PrintSort(vec);
    
    return 0;
}

