//
//  DCLink.hpp
//  algorithm
//
//  Created by pop boy on 2019/3/26.
//  Copyright © 2019年 pop boy. All rights reserved.
//

#ifndef DCLink_h
#define DCLink_h
//双向链表

typedef int datatype;

struct dclink{
    datatype data;
    struct dclink *pre;
    struct dclink *next;
};

class DCLink{
public:
    DCLink();
    DCLink(datatype data);
    void add(datatype data);
    datatype getData(int pos)const;
    int deleteData(int pos);
    int modify(int pos, datatype data);
    int insert(int pos, datatype data);
    void sort()const;
    int rePrint()const; //转置输出
    int print() const;
    ~DCLink();
    int getLength()const;
private:
    //DCLink operator=(const DCLink &dcl){}
  //  DCLink (const DCLink &dcl){}
    struct dclink *head;
    struct dclink *cur; //当前指针
    int size;
};

#endif /* DCLink_h */
