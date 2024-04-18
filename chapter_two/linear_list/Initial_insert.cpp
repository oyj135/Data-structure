/**
 * Created by YJ on 2024/3/7 10:47
 */
#include <stdio.h>

#define MaxSize 50

typedef int ElemType;
typedef struct{
    ElemType data[MaxSize]; // 线性表存放的元素
    int len; // 线性表当前的长度
}SqList;

//输出
void PrintList(SqList L){
    for (int i = 0; i < L.len; i++) {
        printf("%d ", L.data[i]);
    }
    printf("\n");
}

//插入,因为会改变表长，所以需要用 &
bool ListInsert(SqList &L, int i , ElemType e){
    //判断 i 是否合法
    if (i < 1 || i > L.len + 1){
        return false;
    }
    //如果存储空间满了,就不能插入
    if(L.len == MaxSize){
        return false;
    }
    //开始插入
    for (int j = L.len; j >= i ; j--) {
        L.data[j] = L.data[j-1];
    }
    L.data[i-1] = e;// 放入要插入的元素
    L.len++;//长度加1
    return true;
}

//删除 i 要删除的位置，e 获取删除的元素
bool DeleteList(SqList &L, int i, ElemType &e){
    if (i < 1 || i > L.len){
        return false;
    }
    e = L.data[i - 1]; //保存要删除的元素
    for (int j = i; j < L.len; j++) {
        L.data[j-1] = L.data[j];
    }
    L.len--;
    return true;
}

//查询
int LocateElem(SqList L, ElemType e){
    for (int i = 0; i < L.len; ++i) {
        if(e == L.data[i]){
            return i+1;
        }
    }
    return 0;
}


//顺序表的初始化和插入
int main(){
    SqList L;// 顺序表的名称
    bool ret;// 查看返回值
    ElemType del;//要删除的元素;
    ElemType pos;//要查找的元素位置
    L.data[0] = 1;
    L.data[1] = 2;
    L.data[2] = 3;
    L.len = 3;//设置表长
    ret = ListInsert(L, 2, 60);
    if (ret){
        printf("success!!!\n");
        PrintList(L);
    } else{
        printf("failure!!!\n");
    }
   /* ret = DeleteList(L, 2, del);
    if (ret){
        printf("delete success!!!\n");
        PrintList(L);
    } else{
        printf("delete failure!!!\n");
    }*/
    printf("请输入要查找的元素：");
    int e;
    fflush(stdout);
    scanf("%d", &e);
    pos = LocateElem(L, e);
    if (pos){
        printf("find success!!!\n");
        printf("要查找元素 %d 的位置为：%d\n", e, pos);
    } else{
        printf("Lookup failed!!!\n");
    }

    return 0;
}
