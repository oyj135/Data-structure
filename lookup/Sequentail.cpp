/**
 * Created by YJ on 2024/4/25 16:33
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef int ElemType;
typedef struct {
    ElemType *elem; //整形指针，申请的堆空间的起始地址存入elem
    int TableLen; //存储动态数组里边元素的个数
}SSTable;

//初始化
void ST_Init(SSTable &ST, int len){
    ST.TableLen = len + 1;
    ST.elem = (ElemType *)malloc(sizeof(ElemType) * ST.TableLen);
    srand(time(NULL)); //随机数生成
    for (int i = 1; i < ST.TableLen; i++) {
        ST.elem[i] = rand() % 100;
    }
}

//打印
void ST_Print(SSTable ST){
    for (int i = 1; i < ST.TableLen; i++) {
        printf("%3d ", ST.elem[i]);
    }
    printf("\n");
}

int Search(SSTable ST, ElemType key){
    for (int i = ST.TableLen - 1; i > 0; i--) {
        if(ST.elem[i] == key){
            return i;
        }
    }
    return 0;
}

//顺序查找
int main(){
    SSTable ST;
    ST_Init(ST, 10);
    ST_Print(ST);
    printf("请输入要搜索的key值：\n");
    fflush(stdout);
    ElemType key;
    scanf("%d", &key);
    int pos;
    pos = Search(ST, key);
    if(pos){
        printf("找到key值，位置为：%d\n", pos);
    }else{
        printf("未找到key值\n");
    }
    return 0;
}