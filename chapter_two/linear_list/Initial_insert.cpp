/**
 * Created by YJ on 2024/3/7 10:47
 */
#include <stdio.h>

#define MaxSize 50

typedef int ElemType;
typedef struct{
    ElemType data[MaxSize]; // ���Ա��ŵ�Ԫ��
    int len; // ���Ա�ǰ�ĳ���
}SqList;

//���
void PrintList(SqList L){
    for (int i = 0; i < L.len; i++) {
        printf("%d ", L.data[i]);
    }
    printf("\n");
}

//����,��Ϊ��ı����������Ҫ�� &
bool ListInsert(SqList &L, int i , ElemType e){
    //�ж� i �Ƿ�Ϸ�
    if (i < 1 || i > L.len + 1){
        return false;
    }
    //����洢�ռ�����,�Ͳ��ܲ���
    if(L.len == MaxSize){
        return false;
    }
    //��ʼ����
    for (int j = L.len; j >= i ; j--) {
        L.data[j] = L.data[j-1];
    }
    L.data[i-1] = e;// ����Ҫ�����Ԫ��
    L.len++;//���ȼ�1
    return true;
}

//ɾ�� i Ҫɾ����λ�ã�e ��ȡɾ����Ԫ��
bool DeleteList(SqList &L, int i, ElemType &e){
    if (i < 1 || i > L.len){
        return false;
    }
    e = L.data[i - 1]; //����Ҫɾ����Ԫ��
    for (int j = i; j < L.len; j++) {
        L.data[j-1] = L.data[j];
    }
    L.len--;
    return true;
}

//��ѯ
int LocateElem(SqList L, ElemType e){
    for (int i = 0; i < L.len; ++i) {
        if(e == L.data[i]){
            return i+1;
        }
    }
    return 0;
}


//˳���ĳ�ʼ���Ͳ���
int main(){
    SqList L;// ˳��������
    bool ret;// �鿴����ֵ
    ElemType del;//Ҫɾ����Ԫ��;
    ElemType pos;//Ҫ���ҵ�Ԫ��λ��
    L.data[0] = 1;
    L.data[1] = 2;
    L.data[2] = 3;
    L.len = 3;//���ñ�
    ret = ListInsert(L, 2, 60);
    if (ret){
        printf("success!!!\n");
        PrintList(L);
    } else{
        printf("failure!!!\n");
    }
   /* ret = DeleteList(L, 2, del);
    if (ret){
        printf("delete success!!!\n");
        PrintList(L);
    } else{
        printf("delete failure!!!\n");
    }*/
    printf("������Ҫ���ҵ�Ԫ�أ�");
    int e;
    fflush(stdout);
    scanf("%d", &e);
    pos = LocateElem(L, e);
    if (pos){
        printf("find success!!!\n");
        printf("Ҫ����Ԫ�� %d ��λ��Ϊ��%d\n", e, pos);
    } else{
        printf("Lookup failed!!!\n");
    }

    return 0;
}
