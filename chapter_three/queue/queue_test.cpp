/**
 * Created by YJ on 2024/3/19 10:57
 */

#include <stdio.h>


#define MaxSize 10

typedef int ElemType;
typedef struct{
    ElemType data[MaxSize]; //数组存放队列元素 存储 MaxSize - 1 个元素
    int front, rear; // 队头和对尾
}SqQueue;

//初始化
void InitQueue(SqQueue &Q){
    Q.front = Q.rear = 0;
}

//判空
bool QueueEmpty(SqQueue Q){
    if (Q.rear == Q.front){
        return true;
    }
    return false;
}

//入队
bool EnQueue(SqQueue &Q, ElemType e){
    if ((Q.rear + 1) % MaxSize == Q.front){//判断队满
        return false;
    }
    Q.data[Q.rear] = e;
    Q.rear = (Q.rear + 1) % MaxSize; // 改变队尾标记 如果大于数组最大下标，回到开头
    return true;
}

//出队
bool DeQueue(SqQueue &Q, ElemType &e){
    if(Q.rear == Q.front){
        return false;
    }
    e = Q.data[Q.front];
    Q.front = (Q.front + 1) % MaxSize;
    return true;
}

//读取队头元素
void GetQueue(SqQueue Q){
    ElemType len = (Q.rear + MaxSize - Q.front) % MaxSize;
    ElemType i = 0;
    while(i < len){
        printf("%d ", Q.data[i]);
        i++;
    }
}

//队列长度
ElemType length(SqQueue &Q){
    return (Q.rear + MaxSize - Q.front) % MaxSize;
}

int main(){
    SqQueue Q;
    InitQueue(Q);
    bool res;
    res = QueueEmpty(Q);
    if (res){
        printf("is empty\n");
    } else{
        printf("not empty\n");
    }

    EnQueue(Q, 3);
    EnQueue(Q, 4);
    EnQueue(Q, 5);
    res = EnQueue(Q, 6);
    if (res){
        printf("success\n");
    } else{
        printf("failure\n");
    }

    //printf("Queue Length: %d\n", length(Q));

    GetQueue(Q);
    return 0;
}
