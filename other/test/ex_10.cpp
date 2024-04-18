/**
 * Created by YJ on 2024/3/9 23:10
 */

#include <stdio.h>

#define MaxSize 50

typedef int ElemType;
typedef struct{
    ElemType data[MaxSize]; // ���Ա��ŵ�Ԫ��
    int len; // ���Ա�ǰ�ĳ���
}SqList;

//������Ա�Ԫ��
void print_List(SqList L){
    for (int i = 0; i < L.len; ++i) {
        printf("%3d", L.data[i]);
    }
    printf("\n");
}

//����   L ��i Ҫ�����λ��, e Ҫ�����Ԫ��
bool InsertList(SqList &L, int i, ElemType e){
    //�жϲ����λ���Ƿ�Ϸ�
    if (i < 0 || i > L.len + 1){
        return false;
    }
    //�ж����Ա��Ƿ�����
    if (L.len == MaxSize){
        return false;
    }
    //��ʼ����
    for (int j = L.len; j >= i; j--) {
        L.data[j] = L.data[j - 1];
    }
    L.data[i - 1] = e; // ����Ҫ�����Ԫ��
    L.len++;
    return true;
}

//ɾ��Ԫ��
bool DeleteList(SqList &L, int i, ElemType &e){
    //�ж�Ҫɾ����λ���Ƿ�Ϸ�
    if (i < 1 || i > L.len){
        return false;
    }
    e = L.data[i - 1]; // ����Ҫɾ����Ԫ��
    for (int j = i - 1; j < L.len; j++) {
        L.data[j] = L.data[j + 1];
    }
    L.len--;
    return true;
}

int main(){
    SqList L;// ˳��������
    L.data[0] = 1;
    L.data[1] = 2;
    L.data[2] = 3;
    L.len = 3;//���ñ�

    bool res, ret; //���صĽ��

    ElemType num; // Ҫ�����Ԫ��
    print_List(L);
    printf("��������Ҫ�����Ԫ�أ�");
    fflush(stdout); // ��ջ�����
    scanf("%d", &num);
    res = InsertList(L, 2, num);
    if (res){
        print_List(L);

    } else{
        printf("false");
    }

    ElemType ele; //Ҫɾ����Ԫ��;
    ElemType digit; //Ҫɾ����λ��
    fflush(stdout);
    printf("��������Ҫɾ����λ�ã�");
    fflush(stdout);
    scanf("%d", &digit);
    ret = DeleteList(L, digit, ele);
    if (ret){
        print_List(L);

    }else{
        printf("false");
    }
    return 0;
}