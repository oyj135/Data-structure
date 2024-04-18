/**
 * Created by YJ on 2024/3/22 20:31
 */
#include <stdio.h>

struct Peo{
    char name[20]; //20
    char telephone[12]; // 12
    char sex[5]; // 5
    int high; // 4
}p2; //全局的结构体变量

void print2(struct Peo* sp){
    printf("%s %s %s %d\n", sp -> name, sp -> telephone, sp -> sex, sp -> high);
}

int main(){
    struct Peo p1;
    p1 = {"张三", "1223442324", "男", 195};
    p1.sex;
    p2.name;
    printf("%d\n" ,sizeof (p1));
    print2(&p1);
    return 0;
}