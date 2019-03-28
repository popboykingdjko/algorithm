//
//  main.cpp
//  SelectionSort
//
//  Created by pop boy on 2019/3/28.
//  Copyright © 2019年 pop boy. All rights reserved.
//

#include <iostream>
#include <limits.h>
using namespace std;
void print(int array[], int length){
    for(int i = 0; i < length; i++){
        cout <<array[i] << " ";
    }
}
int main(int argc, const char * argv[]) {
    int array[16] = {88, 67, 98, 3, 987, 90, 9, 946, 87, 34, 998, 887 , 665 ,7788 ,453, 66};
    int length = sizeof(array) / sizeof(array[0]);
    int min = INT_MAX;
    int index = 0;
    int temp;
    for(int i = 0; i < length; i++){
        index = i;
        for(int j = i; j < length; j++){
            if(array[j] < min){
                index = j;
                min = array[j];
            }
        }
        temp = min;
        array[index] = array[i];
        array[i] = min;
        min = INT_MAX;
    }
    print(array, length);
    cout << endl;
}
