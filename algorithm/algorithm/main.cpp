//
//  main.cpp
//  algorithm
//
//  Created by pop boy on 2019/3/25.
//  Copyright © 2019年 pop boy. All rights reserved.
//

#include <iostream>
#include "Array.hpp"
#include <stdio.h>
using namespace std;
int main(int argc, const char * argv[]) {
    Array<int> *array = new Array<int>();
    for(int i = 0; i < 11; i++){
        array->addFirst(i);
    }
    array->print();
    return 0;
}
