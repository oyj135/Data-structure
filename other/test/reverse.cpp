/**
 * Created by YJ on 2024/3/9 20:55
 */

#include <stdio.h>

int main(){
    int x;
    scanf("%d", &x);
    int digit;
    int res = 0;
    while(x > 0){
        digit = x % 10;
        res = res * 10 + digit;
        x /= 10;
    }
    printf("res = %d", res);
    return 0;
}
