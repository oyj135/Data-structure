/**
 * Created by YJ on 2024/3/16 20:34
 */

#include <stdio.h>

#define MaxSize 50

typedef int ElemType;
typedef struct{
    ElemType data[MaxSize]; //用数组存放元素
    int top; // 始终指向栈顶的一个变量
}SqStack;

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

//读取栈顶元素
bool GetTop(SqStack S, ElemType &e){
    if (EmptyStack(S)){
        return false;
    }
    e = S.data[S.top]; //拿栈顶元素
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


int main(){
    SqStack s;
    ElemType e;
    InitStack(s);
    bool flag = EmptyStack(s);
    if (flag){
        printf("stack is empty\n");
    }
    printf("请输入要入栈的元素：");
    fflush(stdout);
    scanf("%d", &e);
    Push(s,e);

    ElemType m;
    flag = GetTop(s, m); //获取栈顶元素
    if(flag){
        printf("get top %d\n", m);
    }
    flag = Pop(s, m); //出栈
    if(flag){
        printf("pop element %d\n", m);
    }
    return 0;
}
