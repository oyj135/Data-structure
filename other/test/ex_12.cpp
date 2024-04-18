/**
 * Created by YJ on 2024/3/16 15:37
 */

/**
 * 输入3 4 5 6 7 9999一串整数，9999代表结束，
 * 通过尾插法新建链表，查找第二个位置的值并输出，
 * 在2个位置插入99，输出为  3 99  4  5  6  7，
 * 删除第4个位置的值，打印输出为  3 99  4  6  7。
 */

#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;
typedef struct LNode{
    ElemType data; //数据域
    struct LNode* next; //指针域
}LNode, *LinkList;

//输出
void PrintList(LNode* L){
    L = L->next;
    while (L != NULL) {
        printf("%3d", L->data);//打印当前结点数据
        L = L->next;//指向下一个结点
    }
    printf("\n");
}

//尾插法
void link_tail_insert(LNode* &L){
    L = (LNode*) malloc(sizeof(LNode)); //申请头节点空间,头指针指向头节点
    L -> next = NULL;
    ElemType e;
    printf("请输入要插入的数据: ");
    fflush(stdout);
    scanf("%d", &e);
    struct LNode *s, *r = L;// s 指向要插入的数据, r始终指向链表的尾部
    while(e != 9999){
        s = (LNode*)malloc(sizeof(LNode));
        s -> data = e;
        r -> next = s;
        r = s;
        scanf("%d", &e);
    }
    r -> next = NULL;
}

//按位置查找
LNode* LocateList(LNode* L, int po){
    int i = 0;
    if (po < 0 ){
        return NULL;
    }
    while(L && i < po){
        L = L -> next;
        i++;
    }
    return L;
}

//按位置删除
bool ListDelete(LNode* L, int i){
    LNode* q = LocateList(L, i - 1);
    LNode* p = q -> next; // 拿到要删除的指针
    if (p == NULL){
        return false;
    }
    q -> next = p -> next;
    free(p);
    return true;
}

//插入
// L 可以加& 也可以不加，一般写增加、删除、插入节点的函数时，
// 为了保证涉及到头指针的修改不出错（尤其是不带头结点的链表），都需要加上&。
bool ListInsert(LNode* L, int i, ElemType e){
    LNode* p = LocateList(L, i - 1);
    if (p == NULL){
        return false;
    }
    LNode* q;
    q = (LNode* )malloc(sizeof(LNode));
    q -> data = e;
    q -> next = p -> next;
    p -> next = q;
    return true;
}

int main(){
    struct LNode* L; //建立头指针
    link_tail_insert(L);
    PrintList(L);

    //查找
    LNode* res = LocateList(L, 2);
    printf("%d\n", res -> data);

    //插入
    ListInsert(L, 2, 99);
    PrintList(L);

    //删除
    ListDelete(L, 4);
    PrintList(L);
    return 0;
}
