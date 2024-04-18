/**
 * Created by YJ on 2024/3/19 14:20
 */

#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;
typedef struct LinkNode{
    ElemType data;
    struct LinkNode* next;
}LinkNode;

typedef struct {
    LinkNode *front, *rear; //链表头（队头） 链表尾（队尾）
}LinkQueue;

//初始化
void InitQueue(LinkQueue &Q){
    Q.front = Q.rear = (LinkNode*)malloc(sizeof(LinkNode));
    Q.front -> next = NULL;
}

//输出
void PrintQueue(LinkQueue* q)
{
    LinkNode *p = q->front->next;
    if (q -> front == q -> rear){
        printf("空队列\n");
    }
    while (p) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

//入对
void EnQueue(LinkQueue &Q, ElemType e){
    LinkNode* p = (LinkNode*)malloc(sizeof(LinkNode));
    p -> data = e;
    p -> next = NULL;
    Q.rear -> next = p; //尾指针的next指向p，因为从尾部入
    Q.rear = p; //rear要指向新的尾部
}

//出队
bool DeQueue(LinkQueue &Q, ElemType &e){
    if(Q.rear == Q.front){
        //队列为空
        return false;
    }
    LinkNode *q = Q.front -> next; //拿到结点存入q

    e = q -> data; //获取要出队的元素值
    Q.front -> next = q -> next; //让第一个结点断链
    if (Q.rear == q){ //链表只剩一个结点时, 被删除后，要改变rear
        Q.rear = Q.front;
    }
    free(q);
    return true;
}

int main(){
    LinkQueue Q;
    bool res;

    InitQueue(Q);

    EnQueue(Q, 2);
    EnQueue(Q, 4);
    EnQueue(Q, 5);
    EnQueue(Q, 6);
    EnQueue(Q, 7);

    PrintQueue(&Q);

    fflush(stdout);
    ElemType e; //存储元素
    scanf("请输入要出队的元素；", &e);
    res = DeQueue(Q, e);
    if (res){
        printf("success %d\n", e);
        PrintQueue(&Q);
    }else{
        printf("failure\n");
    }

    return 0;
}
