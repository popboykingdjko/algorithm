//
//  main.cpp
//  SkipList
//
//  Created by pop boy on 2019/3/29.
//  Copyright © 2019年 pop boy. All rights reserved.
//

#include <stdio.h>
#include "SkipList.h"
#include <iostream>
int main()
{
    skip_list *sl=create_sl();
    int i=1;
    for(;i<11111; ++i)
    {
        insert(sl, i, i);
    }
    for(i=11; i<11111; ++i)
    {
        if(!erase(sl, i))
            printf("No!\n");
    }
    print_sl(sl);
    int *p=search(sl, 10);
    if(p)
        printf("value of key 10 is %d\n", *p);
    sl_free(sl);
    return 0;
}
