/**
 * Created by YJ on 2024/4/10 9:35
 */

#include <stdio.h>
#include <stdlib.h>
#include "tree.h"


//初始化
void InitQueue(LinkQueue &Q){
    Q.front = Q.rear = (LinkNode*)malloc(sizeof(LinkNode));
    Q.front -> next = NULL;
}

//判空
bool IsEmpty(LinkQueue Q){
    return Q.rear == Q.front;
}

//入对
void EnQueue(LinkQueue &Q, ElemType e){
    LinkNode* p = (LinkNode*)malloc(sizeof(LinkNode));
    p -> data = e;
    p -> next = NULL;
    Q.rear -> next = p; //尾指针的next指向p，因为从尾部入
    Q.rear = p; //rear要指向新的尾部
}

//出队
bool DeQueue(LinkQueue &Q, ElemType &e){
    if(Q.rear == Q.front){
        //队列为空
        return false;
    }
    LinkNode *q = Q.front -> next; //拿到结点存入q

    e = q -> data; //获取要出队的元素值
    Q.front -> next = q -> next; //让第一个结点断链
    if (Q.rear == q){ //链表只剩一个结点时, 被删除后，要改变rear
        Q.rear = Q.front;
    }
    free(q);
    return true;
}
