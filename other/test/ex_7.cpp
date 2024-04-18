/**
 * Created by YJ on 2024/3/30 17:32
 */

//上台阶问题

#include <stdio.h>

int step(int n){
    if (1 == n || 2 == n){
        return n;
    }
    return step(n - 1) + step(n - 2);
}

int main(){
    int num; //要输入的台阶数
    int count = 0; //存放方法数量
    scanf("%d", &num);
    count = step(num);
    printf("%d\n", count); // printf可以存放各种表达式
    return 0;
}
