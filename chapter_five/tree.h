/**
 * Created by YJ on 2024/4/7 16:36
 */
#ifndef DATA_STRUCTURE_TREE_H
#define DATA_STRUCTURE_TREE_H

typedef char BiElemType;
typedef struct BiTNode{
    BiElemType data;
    struct BiTNode* lc; //左孩子
    struct BiTNode* rc; //右孩子
}BiTNode, *BiTree;

//辅助队列使用
typedef struct tag{
    BiTree p; //树的某一个节点的地址值
    struct tag* pnext;
}tag_t, *ptag_t;

//队列结构体
typedef BiTree ElemType;
typedef struct LinkNode{
    ElemType data;
    struct LinkNode* next;
}LinkNode;

typedef struct {
    LinkNode *front, *rear; //链表头（队头） 链表尾（队尾）
}LinkQueue;
void InitQueue(LinkQueue &Q);
bool IsEmpty(LinkQueue Q);
void EnQueue(LinkQueue &Q, ElemType e);
bool DeQueue(LinkQueue &Q, ElemType &e);

#endif //DATA_STRUCTURE_TREE_H
