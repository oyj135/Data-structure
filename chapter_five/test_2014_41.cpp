/**
 * Created by YJ on 2024/4/21 22:19
 */

#include <stdio.h>
#include <stdlib.h>

typedef int BiElemType;
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

//先序遍历
int PreOrder(BiTree p, int deep){
    static int wpl = 0;
    if (p != NULL){
        if (p -> lc == NULL && p -> rc == NULL){
            wpl = wpl + p -> data * deep;
        }
        PreOrder(p -> lc, deep + 1);
        PreOrder(p -> rc, deep + 1);
    }
    return wpl;
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


int main(){
    BiTree res = CreateThree();
    printf("--------前序遍历--------\n");
    int result = PreOrder(res, 0);
    printf("wpl = %d\n", result);
    return 0;
}
