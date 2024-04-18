/**
 * Created by YJ on 2024/4/3 21:37
 */
#include <stdio.h>
#include "tree.h"
#include <stdlib.h>

//深度优先遍历
void PreOrder(BiTree p){
    if (p != NULL){
        printf("%c", p -> data);
        PreOrder(p -> lc);
        PreOrder(p -> rc);
    }
}

//中序遍历
void InOrder(BiTree p){
    if (p != NULL){
        InOrder(p -> lc);
        printf("%c", p -> data);
        InOrder(p -> rc);
    }
}

//后序遍历
void PostOrder(BiTree p){
    if (p != NULL){
        PostOrder(p -> lc);
        PostOrder(p -> rc);
        printf("%c", p -> data);
    }
}

//建树
BiTree CreateThree(){
    BiTree p_new;//用来指向新申请的树节点
    BiTree tree = NULL; //tree是指向树根的，代表树
    //p_head 队列头， p_tail 队列尾
    ptag_t p_head = NULL, p_tail = NULL, list_p_new = NULL, p_cur;
    char c;
    //abcdefghij
    while(scanf("%c", &c)){
        if (c == '\n'){
            break; //读取到换行就结束
        }
        //calloc申请的空间大小是两个参数直接相乘，并对空间进行初始化，赋值为0
        p_new = (BiTree)calloc(1,sizeof(BiTNode));
        p_new -> data = c;
        list_p_new = (ptag_t)calloc(1, sizeof(tag_t));
        list_p_new -> p = p_new;
        //如果是树的第一个结点
        if (NULL == tree){
            tree = p_new; //tree指向树的根结点
            p_head = list_p_new;
            p_tail = list_p_new;
            p_cur = list_p_new; //p_cur 指向要进入树的父亲元素
        }else{
            //让元素入队列
            p_tail -> pnext = list_p_new;
            p_tail = list_p_new;
            //把结点放入树中
            if (NULL == p_cur -> p -> lc){
                p_cur -> p -> lc = p_new; //左孩子为空就放入
            }else if (NULL == p_cur -> p -> rc){
                p_cur -> p -> rc = p_new; //右孩子为空就放入
                p_cur = p_cur -> pnext; //当左右孩子都有了，就指向下一个结点
            }
        }
    }
    return tree;
}

//层序遍历
void LevelOrder(BiTree T){
    LinkQueue Q;
    InitQueue(Q);
    BiTree p; //储存出队的节点
    EnQueue(Q, T); //树根入队
    while(!IsEmpty(Q)){
        DeQueue(Q,p);
        putchar(p -> data);//等价printf
        if (p -> lc){
            EnQueue(Q,p -> lc);
        }
        if(p -> rc){
            EnQueue(Q,p -> rc);
        }
    }
}


int main(){
    BiTree res = CreateThree();

    printf("--------前序遍历--------\n");
    PreOrder(res);
    printf("\n--------中序遍历--------\n");
    InOrder(res);
    printf("\n--------后序遍历--------\n");
    PostOrder(res);
    printf("\n--------广度优先遍历--------\n");
    LevelOrder(res);
    return 0;
}