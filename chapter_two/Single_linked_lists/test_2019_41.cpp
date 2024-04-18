/**
 * Created by YJ on 2024/3/8 20:56
 */
#include <stdio.h>
#include <stdlib.h>


typedef int ElemType;
typedef struct LNode{
    ElemType  data; //数据域
    struct LNode* next; //指针域
}LNode, *LinkList;

void print_List(LinkList L){
    L = L->next;
    while(L != NULL){
        printf("%d ", L->data);
        L = L->next;
    }
    printf("\n");
}

//尾插法
void list_tail_insert(LinkList &L){
    L = (LinkList)malloc(sizeof(LNode)); // 申请头节点空间,头指针指向头节点
    L->next = NULL;
    ElemType e;
    printf("请输入要插入的元素：");
    fflush(stdout);
    scanf("%d",&e);
    LinkList s, r = L;// s是用来指向申请的新节点，r始终指向链表尾部
    while(e != 9999){
        s = (LinkList)malloc(sizeof(LNode));
        s->data = e;
        r->next = s;// 新结点给尾结点的next指针
        r = s; //r要指向新的尾部
        scanf("%d",&e);
    }
    r -> next = NULL;//尾结点置空
}

//找到中间节点，并设置好L2链表
void find_middle(LinkList L, LinkList &L2){

}

int main(){
    LinkList L, search; //L是链表头指针，结构体指针类型
    //list_head_insert(L);
    list_tail_insert(L);
    print_List(L);//打印
    return 0;
}