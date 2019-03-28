//
//  main.cpp
//  QuickSort
//
//  Created by pop boy on 2019/3/28.
//  Copyright © 2019年 pop boy. All rights reserved.
//

#include <iostream>
using namespace std;
void print(int array[], int length){
    for(int i = 0; i < length; i++){
        cout <<array[i] << " ";
    }
}

int partition(int array[], int begain, int end){
    int pivot = array[end], temp = 0, j = begain;
    for(int i = end-1; i >= j ; i--){
        if(array[i] < pivot){
            while(array[j] < pivot && j < i){
                j++;
            }
            temp = array[j];
            array[j] = array[i];
            array[i] = temp;
            j++;
        }
    }
    temp = array[j];
    array[j] = array[end];
    array[end] = temp;
    return j;
}

void quickSort(int array [], int begain, int end){
    if(end <= begain)
        return;
    int mid = partition(array, begain, end);
    quickSort(array, begain, mid-1);
    quickSort(array, mid+1, end);
}

int main(int argc, const char * argv[]) {
    int array[16] = {88, 67, 98, 3, 987, 90, 9, 946, 87, 34, 998, 887 , 665 ,7788 ,453, 66};
    int length = sizeof(array) / sizeof(array[0]);
    quickSort(array, 0, length-1);
    print(array, length);
    cout << endl;
    return 0;
}
