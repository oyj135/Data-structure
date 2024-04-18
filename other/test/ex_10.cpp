/**
 * Created by YJ on 2024/3/9 23:10
 */

#include <stdio.h>

#define MaxSize 50

typedef int ElemType;
typedef struct{
    ElemType data[MaxSize]; // 线性表存放的元素
    int len; // 线性表当前的长度
}SqList;

//输出线性表元素
void print_List(SqList L){
    for (int i = 0; i < L.len; ++i) {
        printf("%3d", L.data[i]);
    }
    printf("\n");
}

//插入   L 表，i 要插入的位置, e 要插入的元素
bool InsertList(SqList &L, int i, ElemType e){
    //判断插入的位置是否合法
    if (i < 0 || i > L.len + 1){
        return false;
    }
    //判断线性表是否已满
    if (L.len == MaxSize){
        return false;
    }
    //开始插入
    for (int j = L.len; j >= i; j--) {
        L.data[j] = L.data[j - 1];
    }
    L.data[i - 1] = e; // 放入要插入的元素
    L.len++;
    return true;
}

//删除元素
bool DeleteList(SqList &L, int i, ElemType &e){
    //判断要删除的位置是否合法
    if (i < 1 || i > L.len){
        return false;
    }
    e = L.data[i - 1]; // 保存要删除的元素
    for (int j = i - 1; j < L.len; j++) {
        L.data[j] = L.data[j + 1];
    }
    L.len--;
    return true;
}

int main(){
    SqList L;// 顺序表的名称
    L.data[0] = 1;
    L.data[1] = 2;
    L.data[2] = 3;
    L.len = 3;//设置表长

    bool res, ret; //返回的结果

    ElemType num; // 要插入的元素
    print_List(L);
    printf("请输入你要插入的元素：");
    fflush(stdout); // 清空缓存区
    scanf("%d", &num);
    res = InsertList(L, 2, num);
    if (res){
        print_List(L);

    } else{
        printf("false");
    }

    ElemType ele; //要删除的元素;
    ElemType digit; //要删除的位置
    fflush(stdout);
    printf("请输入你要删除的位置：");
    fflush(stdout);
    scanf("%d", &digit);
    ret = DeleteList(L, digit, ele);
    if (ret){
        print_List(L);

    }else{
        printf("false");
    }
    return 0;
}