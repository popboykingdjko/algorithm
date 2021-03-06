#include "DCLink.hpp"
#include <iostream>
//default constructor
DCLink::DCLink(){
    head = cur = NULL;//默认为空
    size = 0;
}
DCLink::DCLink(datatype data){//单参constructor
    head = new struct dclink[1];//申请空间
    cur = head;//指向当前节点
    head->data = data;
    head->next = head->pre = head;//指向自身
    size = 1;
}
void DCLink::add(datatype data){//添加data到链表中去
    //默认添加到表尾
    struct dclink *dcl = new struct dclink[1];
    dcl->data = data;
    if (NULL != head){//表非空
        //当前节点为第1号节点，它的后继节点为第2号节点
        struct dclink *temp = cur->next;//保持2号节点的位置
        cur->next = dcl;//1号节点的后继和新增节点相连
        dcl->pre = cur;//新增节点的前驱和1号节点相连
        dcl->next = temp;//新增节点的后继和2号节点相连
        temp->pre = dcl;//新增节点和2号节点的前驱相连
    }else {
        head = dcl;//新加节点成为头结点
        head->data = data;
        head->next = head->pre = head;//指向自身
    }//已经添加完毕,新增节点成为当前节点
    cur = dcl;
    size++;//长度+1
}
int DCLink::deleteData(int pos){//删除指定位置的数据
    if (size >= pos && pos > 0){//有数据并且没有越界才显示
        int count = 1;//计数
        struct dclink *temp = head;
        while (pos != count){
            temp = temp->next;//直到到达指定的位置
            count++;
        }//先到达指定位置
        //分情况是因为如果删除最后一个节点会改变cur的状态，挂空指针
        if (size == pos){
            if (1 == size){//只有一个节点的时候
                delete []temp;
                head = cur = NULL;//置空
                size--;//-1
                return 0;
            }else{//删除最后一个节点
                cur = temp->pre;//向前移动一个位置
            }
        }else{//如果删除第一个节点head会改变
            if (1 == pos){
                head = temp->next;//向后移动一个位置
            }
        }
        //当前节点为0号节点，后继节点为1号节点，前驱节点为-1号节点
        temp->pre->next = temp->next;//-1号节点的后继和1号节点相连
        temp->next->pre = temp->pre;//1号节点的前驱和-1号节点相连
        size--;//长度-1
        return 0;//成功返回0
    }
    return -1;//无数据或者越界返回-1
}
int DCLink::modify(int pos, datatype data){//更改指定位置的数据
    if (size >= pos && pos > 0){//有数据并且没有越界才显示
        int count = 1;//计数
        struct dclink *temp = head;
        while (pos != count){
            temp = temp->next;
            count++;
        }
        temp->data = data;//更新
        return 0;
    }
    return -1;//无数据或者越界返回-1
}
int DCLink::insert(int pos, datatype data){//在指定位置插入数据
    if (0 == size && 1 == pos){
        this->add(data);//直接调用add函数
        return 0;
    }
    if (size >= pos && pos > 0){//有数据并且没有越界才显示
        int count = 1;//计数
        struct dclink *dcl = new struct dclink[1];
        dcl->data = data;
        struct dclink *temp = head;
        while (pos != count){
            temp = temp->next;//直到到达指定的位置
            count++;
        }//先到达指定位置
        //分情况是因为如果插入到第一个节点会改变head的状态
        if (size == pos){
            if (1 == size){//只有一个节点的时候
                head = dcl;//当前结点成为头结点
                head->next = temp;//新结点的后继和旧头结点相连
                temp->pre = head;//旧头结点的前驱和新结点相连
                head->pre = temp;//新结点的前驱和旧头结点相连
                temp->next = head;//旧头结点的后继和新结点相连
            }else{//插入到尾结点的前面
                temp->pre->next = dcl;
                dcl->pre = temp->pre;
                dcl->next = temp;
                temp->pre = dcl;
            }
            size++;
            return 0;
        }else{
            if (1 == pos){//插入到第一个位置
                head = dcl;//当前结点成为头结点
                head->next = temp;//新结点的后继和旧头结点相连
                temp->pre = head;//旧头结点的前驱和新结点相连
                head->pre = temp->pre;//新结点的前驱和旧头结点相连
                //temp->pre->pre = head;//旧头结点的后继和新结点相连
            }else {//插入到中间的其它位置
                temp->pre->next = dcl;
                dcl->pre = temp->pre;
                dcl->next = temp;
                temp->pre = dcl;
            }
            size++;
            return 0;
        }
    }
    return -1;//越界返回-1
}
datatype DCLink::getData(int pos)const{//获得指定位置的数据
    if (size >= pos && pos > 0){//有数据并且没有越界才显示
        int count = 1;//计数
        struct dclink *temp = head;
        while (pos != count){
            temp = temp->next;//比插入和删除简单很多
            count++;//+1，第一次写的时候忘了+1，然后就固执地认为getData肯定没问题
            //可bug就在这里
        }
        return temp->data;
    }
    return -1;//无数据或者越界返回-1
}
void DCLink::sort()const{//排序
    if (1 < size){
        //快速排序
        int i = 1;
        int j = 0;
        struct dclink *ohead = head;
        while (size != i){//循环size - 1次
            j = 0;//重置
            struct dclink *temp = ohead;//辅助指针
            while (j != size - i){
                if (ohead->data > temp->next->data){//交换排序
                    ohead->data += temp->next->data;
                    temp->next->data = ohead->data - temp->next->data;
                    ohead->data -= temp->next->data;
                }
                temp = temp->next;//移动
                j++;
            }
            ohead = ohead->next;//前面j个数据已经排好
            i++;
        }
    }
}
int DCLink::rePrint()const{//打印链表
    if (NULL != head){//链表非空
        struct dclink *temp = head;
        int count = 0;//计数
        while (size != count){
            temp = temp->pre;
            std::cout<<temp->data<<std::endl;
            count++;
        }
        return 0;
    }
    return -1;//空表返回-1
}
int DCLink::print()const{//打印链表
    if (NULL != head){//链表非空
        struct dclink *temp = head;
        int count = 0;//计数
        while (size != count){
            std::cout<<temp->data<<"  ";
            temp = temp->next;
            count++;
        }
        return 0;
    }
    return -1;//空表返回-1
}
int DCLink::getLength()const{
    return size;
}//得到链表的长度
//destructor
DCLink::~DCLink()
{
    while (0 != size){//用size来控制析构的次数
        struct dclink *temp = head;//辅助指针
        head->pre->next = head->next;//让head的前一个节点指向它的后一个节点
        head = head->next;//head后移动一个节点
        head->pre = temp->pre;//head还是指向前一个节点
        delete []temp;
        size--;
    }
}

int main(void){
    DCLink dcl;
    for (int i = 10; i > 0; i--)
        dcl.add(i);
    //dcl.print();
   // std::cout << std::endl;
//    std::cout<<std::endl;
//    dcl.sort();
//    dcl.print();
//    dcl.modify(1,10);
//    dcl.modify(5,44);
//    dcl.modify(3,33);
//    dcl.deleteData(5);
//    dcl.deleteData(1);
//    dcl.deleteData(3);
    dcl.insert(6,0);
    dcl.print();
    std::cout << std::endl;
    dcl.rePrint();
    std::cout<<std::endl;
    
    return 0;
}
