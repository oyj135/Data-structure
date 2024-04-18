/**
 * Created by YJ on 2024/3/8 23:07
 */
#include <stdio.h>
//输入N个数（N小于等于100），输出数字2的出现次数；
int main(){
    int num; //要输入的个数
    int count = 0;
    int arr[100];
    scanf("%d", &num);
    for(int i = 0; i< num; i++){
       scanf("%d", &arr[i]);
    }
    int len = sizeof(arr) / sizeof(arr[0]);
    for(int i = 0; i< num; i++){
        if(arr[i] == 2){
            count++;
        }
    }
    printf("%d\n", count);

    return 0;
}