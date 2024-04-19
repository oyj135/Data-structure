/**
 * Created by YJ on 2024/4/3 21:34
 */
#include <stdio.h>

#define MAXSize 100

//静态数组实现字符串
typedef struct {
    char ch[MAXSize]; //每个分量存储一个字符
    int length; //串的实际长度
}SString;

//动态数组实现字符串
typedef struct {
    char *ch; // 按串长分配存储区，ch指向串的起始地址
    int length; //串的实际长度
}HString;

//串的链式存储
typedef struct StringNode{
    char ch[4]; //每个节点存储多个字符
    struct StringNode* next;
}StringNode, *String;

//求串长
int StrLength(SString S){
    return S.length;
}

//求子串
//SubString(S,T,pos,len) 用S返回串T的第pos个字符之后长度为len的字符串
bool SubString(SString &S, SString T, int pos, int len){
    //边界判断
    if (pos < 1 || pos > T.length || pos + len - 1 > T.length)
        return false;
    //赋值
    for (int i = pos; i < pos + len; ++i) {
        S.ch[i - pos + 1] = T.ch[i];
    }
    S.length = len;
    return true;
}

//比较串
//StrCompare(S,T) 若 s > t 则返回值 > 0，若 s = t 则返回值 = 0，若 s < t 则返回值 < 0
int StrCompare(SString S, SString T){
    for (int i = 1; i <= S.length && i <= T.length; ++i) {
        if (S.ch[i] != T.ch[i]){
            return S.ch[i] - T.ch[i];
        }
    }
}

//求子串的位置
//Index(S,T) 返回串T在串S中第一次出现的位置，若不存在则返回值 = 0
int Index(SString S, SString T){
    int i = 1;
    int n = StrLength(S), m = StrLength(T);
    SString sub; //用于暂存子串
    while(i <= n - m + 1){
        SubString(sub, S, i, m);
        if (StrCompare(sub, T) != 0){
            ++i;
        } else{
            return i; //返回子串在串中的位置
        }
    }
    return 0;
}

//朴素模式匹配算法
int Index_Naive(SString S, SString T){
    int i = 1, j = 1;
    int n = StrLength(S), m = StrLength(T);
    while(i <= n && j <= m){
        if (S.ch[i] == T.ch[j]){
            ++i; //匹配成功，继续匹配下一个字符
            ++j;
        } else{ //匹配失败，回退到上一个字符
            i = i - j + 2;
            j = 1;
        }
    }
    if (j > m){
        return i - m;
    } else{
        return 0;
    }
}

int main(){
    // 示例字符串
    SString strS = {"Hello, World! This is a test string.", 27};
    SString strT1 = {"World", 5};
    SString strT2 = {"test", 4};

    printf("Original string: %s\n", strS.ch);

    // 使用 Index 函数查找子串位置
    int index1 = Index(strS, strT1);
    int index2 = Index(strS, strT2);

    if (index1 != 0) {
        printf("Substring \"%s\" found at position %d.\n", strT1.ch, index1);
    } else {
        printf("Substring \"%s\" not found in the string.\n", strT1.ch);
    }

    if (index2 != 0) {
        printf("Substring \"%s\" found at position %d.\n", strT2.ch, index2);
    } else {
        printf("Substring \"%s\" not found in the string.\n", strT2.ch);
    }

    // 使用 Index_Naive 函数（朴素模式匹配算法）查找子串位置
    int naiveIndex1 = Index_Naive(strS, strT1);
    int naiveIndex2 = Index_Naive(strS, strT2);

    if (naiveIndex1 != 0) {
        printf("Substring \"%s\" found at position %d (using Naive algorithm).\n", strT1.ch, naiveIndex1);
    } else {
        printf("Substring \"%s\" not found in the string (using Naive algorithm).\n", strT1.ch);
    }

    if (naiveIndex2 != 0) {
        printf("Substring \"%s\" found at position %d (using Naive algorithm).\n", strT2.ch, naiveIndex2);
    } else {
        printf("Substring \"%s\" not found in the string (using Naive algorithm).\n", strT2.ch);
    }

    return 0;
}
