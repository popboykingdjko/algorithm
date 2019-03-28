//
//  main.cpp
//  MergeSort
//
//  Created by pop boy on 2019/3/28.
//  Copyright © 2019年 pop boy. All rights reserved.
//

#include <iostream>
using namespace std;
void sort(int array[], int begain, int mid, int end);
void print(int* array, int length);
void merge(int array[], int begain, int end);
void test(int array[] , int index1, int index2){
    int temp = array[index1];
    array[index1] = array[index2];
    array[index2] = temp;
}

int main(int argc, const char * argv[]) {
    int array1[16] = {88, 67, 98, 3, 987, 90, 9, 946, 87, 34, 998, 887 , 665 ,7788 ,453, 66};
    int array2[15] = {88, 67, 98, 3, 987, 90, 9, 946, 87, 34, 998, 887 , 665 ,778 ,453};
    int length1 = sizeof(array1)/sizeof(array1[0]);
    int length2 = sizeof(array2)/sizeof(array2[0]);
    test(array1, 0, 1);
    cout << "测试数组是否都是引用传递" << "  ";
    print(array1, length1);
    cout << endl;
    merge(array1, 0, length1-1);
    merge(array2, 0, length2-1);
    print(array1, length1);
    cout << endl;
    print(array2, length2);
    cout << endl;
    return 0;
}
void print(int* array, int length){
    for(int i = 0; i < length; i++){
        cout <<array[i] << " ";
    }
}
void merge(int array[], int begain, int end){
    if(end == begain)
        return;
    int mid = (begain + end)/2;
    merge(array, begain, mid);
    merge(array, mid + 1, end);
    sort(array, begain, mid, end);
}

void sort(int array[], int begain, int mid, int end){
    int index1 = begain, index2 = mid+1;
    int temp[end- begain + 1];
    int i = 0;
    while(index1 <= mid && index2 <= end){
        if(array[index1] <= array[index2]){
            temp[i] = array[index1];
            index1++;
        }else{
            temp[i] = array[index2];
            index2++;
        }
        i++;
    }
    if(index1 <= mid){
        while(i < end-begain+1){
            temp[i] = array[index1];
            i++;
            index1++;
        }
    }
    if(index2 <= end){
        while(i < end-begain+1){
            temp[i] = array[index2];
            i++;
            index2++;
        }
    }
    index1 = begain;
    i = 0;
    while(index1 <= end){
        array[index1++] = temp[i++];
    }
}


