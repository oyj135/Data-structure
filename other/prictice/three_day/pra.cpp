/**
 * Created by YJ on 2024/4/3 13:01
 */

#include <stdio.h>

//写一个函数返回参数二进制中1的个数
int count_num_of_1(int n){
    int count = 0;
    while(n){
        if ((n % 2) == 1){
            count++;
        }
        n /= 2;
    }
    return count;
}

//second methods
int count_num_of_1_2(int n){
    int i = 0;
    int count = 0;
    for (int i = 0; i < 32; ++i) {
        if(((n >> i) & 1) == 1){
            count++;
        }
    }
    return count;
}

//thirst methods (效率最高)
int count_num_of_1_3(int n){
    int count = 0;
    while(n){
        n = n & (n - 1);
        count++;
    }
    return 0;
}
//还可以用来 判断一个数是不是2的n次方

// 两个int(32位) 整数m和n的二进制表达中，有多少个位(bit)不同?
int count_diff_bit(int m, int n){
    int count = 0;
    for (int i = 0; i < 32; ++i) {
        if (((m >> i) & 1) != ((n >> i) & 1)){
            count++;
        }
    }
    return count;
}

//获取一个整数二进制序列中所有的偶数位和奇数位，分别打印出二进制序列
void count_ou_ji(){
    int num = 0;
    scanf("%d", &num);
    //获取奇数位的数字
    for (int i = 30; i >= 0; i -= 2) {
        printf("%d ", (num >> i) & 1);
    }
    printf("\n");
    //获取偶数位的数字
    for (int i = 31; i >= 1; i -= 2) {
        printf("%d ", (num >> i) & 1);
    }
}

int main(){
    int num = 0;
    int num2 = 0;
    //scanf("%d%d", &num, &num2);
    //int res = count_num_of_1(num);
    //int res = count_diff_bit(num,num2);
    //printf("res = %d\n", res);
    count_ou_ji();
    return 0;
}
