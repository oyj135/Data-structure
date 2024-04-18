/**
 * Created by YJ on 2024/3/15 23:37
 */

#include <stdio.h>

//存放指针（地址）的变量就是指针变量
struct Stu{
    char name[20];
    int age;
    char sex[10];
    char tele[12];
};
int main(){
    struct Stu s = {"张三", 20, "nam", "sdfewrfe"};
    printf("%s %d %s %s\n", s.name, s.age, s.sex, s.tele);
    return 0;
}
