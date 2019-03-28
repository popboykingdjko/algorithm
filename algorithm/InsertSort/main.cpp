//
//  main.cpp
//  InsertSort
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
int main(int argc, const char * argv[]) {
    int array[16] = {88, 67, 98, 3, 987, 90, 9, 946, 87, 34, 998, 887 , 665 ,7788 ,453, 66};
    int length = sizeof(array) / sizeof(array[0]);
    int temp = 0;
    for(int i = 1; i < length; i++){
        for(int j = i-1; j >= 0; j--){
            if(array[j] > array[j+1]){
                temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }else{
                break;
            }
        }
    }
    print(array, length);
    cout << endl;
    return 0;
}
