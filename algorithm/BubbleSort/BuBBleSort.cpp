//
//  main.cpp
//  BubbleSort
//
//  Created by pop boy on 2019/3/27.
//  Copyright © 2019年 pop boy. All rights reserved.
//

#include <iostream>
using namespace std;

void swag(int& a, int& b){
    int temp =a;
    a=b;
    b=temp;
}

void print(int array[]){
    //cout<<sizeof(array) <<endl;
    for(int i = 0; i < 16; i++){
        cout <<array[i] << " ";
    }
}
int main(int argc, const char * argv[]) {
    int array[16] = {88, 67, 98, 3, 987, 90, 9, 946, 87, 34, 998, 887 , 665 ,7788 ,453, 66};
    int length = sizeof(array) / sizeof(array[0]);
    int temp = length;
    //cout << sizeof(array)<< endl;
    cout << length << endl;
    for(int i=0; i < temp-1; i++){
        for(int j =0; j < length-1-i; j++){
            if(array[j] > array[j+1]){
                swag(array[j], array[j+1]);
            }
        }
       temp--;
    }
    print(array);
    cout << endl;
    return 0;
}
