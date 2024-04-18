/**
 * Created by YJ on 2024/3/7 20:17
 */
#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;
typedef struct LNode{
    ElemType  data; //数据域
    struct LNode* next; //指针域
}LNode, *LinkList;

//输出
void print_List(LinkList L){
    L = L->next;
    while(L != NULL){
        printf("%d ", L->data);
        L = L->next;
    }
    printf("\n");
}

//头插法
void list_head_insert(LNode* &L){
    L = (LinkList)malloc(sizeof(LNode)); // 申请头节点空间,头指针指向头节点
    L->next = NULL;
    ElemType e;
    printf("请输入要插入的元素：");
    fflush(stdout);
    scanf("%d",&e);
    LinkList s;// 用来指向申请的新空间
    while(e != 9999){
        s = (LinkList)malloc(sizeof(LNode));
        s->data = e;
        s->next = L->next; // s的next指向原链表的第一个节点
        L->next = s; //头结点的next，指向新节点
        scanf("%d",&e);
    }
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

//按位置查找
LinkList GetElem(LinkList L, int lo){
    int i = 0;
    if(lo < 0){
        return NULL;
    }
    while(L && i < lo){
        L = L->next;
        i++;
    }
    return L;
}

//按值查找
LinkList LocateElem(LinkList L, ElemType e){
    while (L){
        //循环遍历打印
        if (L->data == e){
            return L;
        }
        L = L->next;
    }
    return NULL;
}

//插入  i 插入的位置， e 要插入的元素
bool listFrontInsert(LinkList &L, int i, ElemType e){
    LinkList p = GetElem(L, i - 1);
    if (NULL == p){
       return false;
    }
    LinkList q;
    q = (LinkList)malloc(sizeof (LinkList));
    q->data = e;
    q->next = p->next;
    p->next = q;
    return true;
}

//删除元素
bool DeleteLink(LinkList L, int i){
    LinkList p = GetElem(L, i - 1);
    LinkList q = p -> next; //拿到要删除的节点指针;
    if(NULL == p){
        return false;
    }
    p -> next = q -> next;
    free(q);
    return true;
}

int main(){
    LinkList L, search; //L是链表头指针，结构体指针类型
    //list_head_insert(L);
    list_tail_insert(L);
    print_List(L);//打印

   /* //按位置查找
    search = GetElem(L, 5);
    if (search != NULL){
        printf("successed in searching by number\n");
        printf("%d \n", search->data);
    }else{
        printf("failed in searching by number\n");
    }

    search = LocateElem(L, 8);
    if (search != NULL){
        printf("successed in searching by number\n");
        printf("%d \n", search->data);
    }else{
        printf("failed in searching by number\n");
    }*/

    //listFrontInsert(L, 2 , 65);
    DeleteLink(L, 3);
    print_List(L);
    return 0;
}
