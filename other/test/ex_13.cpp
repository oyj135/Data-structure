/**
 * Created by YJ on 2024/3/16 20:34
 */

#include <stdio.h>

#define MaxSize 5

typedef int ElemType;
typedef struct{
    ElemType data[MaxSize]; //用数组存放元素
    int top; // 始终指向栈顶的一个变量
}SqStack;

typedef struct {
    ElemType data[MaxSize];
    int rear, front; // 分别指向队尾和队头
}SqQueue;

//初始化栈
void InitStack(SqStack &s){
    s.top = -1; //栈为空
}

//判空
bool EmptyStack(SqStack S){
    if (-1 == S.top){
        return true;
    }else{
        return false;
    }
}

//入栈
bool Push(SqStack &S, ElemType e){
    //判断栈是否已满
    if (S.top == MaxSize - 1){
        return false;
    }
    S.data[++S.top] = e;
    return true;
}

//出栈
bool Pop(SqStack &S, ElemType &e){
    if (EmptyStack(S)){
        return false;
    }
    e = S.data[S.top--];
    return true;
}

//初始化队列
void InitQueue(SqQueue &Q){
    Q.rear = Q.front = 0;
}

//判断队列是否为空
bool EmptyQueue(SqQueue &Q){
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


int main(){
    SqStack s;
    ElemType e;
    InitStack(s);

    for (int i = 0; i < 3; ++i) {
        scanf("%d", &e);
        Push(s,e);
    }
    //将栈内元素弹出
    for (int i = 0; i < 3; ++i) {
        Pop(s, e);
        printf("%2d", e);
    }
    printf("\n");

    //队列
    SqQueue Q;
    InitQueue(Q);
    bool flag;
    fflush(stdout);
    for (int i = 0; i < 5; ++i) {
        scanf("%d", &e);
        flag = EnQueue(Q, e);
        if (false == flag){
            printf("false\n");
        }
    }
    //出队
    for (int i = 0; i < 4; ++i) {
        DeQueue(Q, e);
        printf("%2d", e);
    }
    printf("\n");
    return 0;
}
