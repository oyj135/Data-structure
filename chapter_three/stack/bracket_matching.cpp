/**
 * Created by YJ on 2024/3/21 20:30
 */

#include <stdio.h>

#define MaxSize 10
typedef struct {
    char data[MaxSize]; // 静态数组存放栈中元素
    int top; // 栈顶指针
}SqStack;

//初始化
void InitStack(SqStack &S){
    S.top = -1;
}

//判空
bool StackEmpty(SqStack S){
    if (S.top == -1){
        return true;
    }
    return false;
}

//入栈
bool Push(SqStack &S, char e){
    //判断栈是否已满
    if(S.top == MaxSize -1){
        return false;
    }
    S.data[++S.top] = e;
    return true;
}

//出栈
bool Pop(SqStack &S, char &e){
    //判断栈是否为空
    if (S.top == -1){
        return false;
    }
    e = S.data[S.top--];
    return true;
}

//括号匹配
bool bracketCheck(char str[], int len){
    SqStack S;
    InitStack(S); //初始化
    for (int i = 0; i < len; ++i) {
        if(str[i] == '(' || str[i] == '[' || str[i] == '{'){
            Push(S, str[i]); //扫描到左括号，入栈
        } else{
            if (StackEmpty(S)){
                //扫描到右括号，且栈为空
                return false; //匹配失败
            }
            char topElem;
            Pop(S, topElem); //出栈
            if(str[i] == ')' && topElem != '(')
                return false;
            if(str[i] == ']' && topElem != '[')
                return false;
            if(str[i] == '}' && topElem != '{')
                return false;
        }
    }
    return StackEmpty(S); //检索完全部括号后，栈空则匹配成功
}
int main(){
    SqStack s;
    InitStack(s);
    char str[] = {"[][{[()]}"};
    int len = sizeof (str) / sizeof (str[0]) - 1;
    bool res = bracketCheck(str,len);
    if (res){
        printf("匹配成功\n");
    } else{
        printf("匹配失败\n");
    }
    return 0;
}
