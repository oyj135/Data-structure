/**
 * Created by YJ on 2024/3/12 20:44
 */

#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;
typedef struct LNode{
    ElemType  data; //数据域
    struct LNode* next; //指针域
}LNode, *LinkList;

//输出
void PrintList(LinkList L) {
    L = L->next;
    while (L != NULL) {
        printf("%d", L->data);//打印当前结点数据
        L = L->next;//指向下一个结点
        if (L != NULL) {
            printf(" ");
        }
    }
    printf("\n");
}

//头插法
void list_head_insert(LNode* &L){
    L = (LNode*)malloc(sizeof(LNode));// 申请头节点空间,头指针指向头节点
    L -> next = NULL;
    ElemType e;
    printf("请输入你要插入的元素：");
    fflush(stdout);
    scanf("%d", &e);
    struct LNode* s; //创建一个指针用来指向新申请的空间
    while(e != 9999){
        s = (LNode*)malloc(sizeof (LNode));
        s -> data = e;
        s -> next = L -> next;// s 的next 指针 指向 头结点指向的首节点
        L -> next = s; // 头指针 指向新节点
        scanf("%d", &e);
    }
}

//尾插法
void list_tail_insert(LNode* &L){
    L = (LNode*)malloc(sizeof (LNode));
    L -> next = NULL;
    ElemType e;
    printf("请输入要插入的元素：");
    fflush(stdout);
    scanf("%d",&e);
    struct LNode* s, *r = L;// s是用来指向申请的新节点，r始终指向链表尾部
    while(e != 9999){
        s = (LNode*)malloc(sizeof(LNode));
        s->data = e;
        r->next = s;// 新结点给尾结点的next指针
        r = s; //r要指向新的尾部
        scanf("%d",&e);
    }
    r -> next = NULL;//尾结点置空

}

int main(){
    struct LNode* L; //L是链表头指针，结构体指针类型
    list_head_insert(L);
    PrintList(L);
    list_tail_insert(L);
    PrintList(L);

    return 0;
}
