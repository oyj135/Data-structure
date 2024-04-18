/**
 * Created by YJ on 2024/3/11 19:24
 */

#include <stdio.h>
#include <string.h>

int main(){
    char arr1[] = "abcdef";
    char arr2[] = {'a', 'b', 'c', 'd', 'e', 'f'};
    printf("%s\n", arr1);
    printf("%s\n", arr2);

    int len = strlen(arr2);//strlen 找字符串长度时，没有\0 会一直找，直到找到\0为止
    int size = sizeof(arr2);
    printf("%d\n", len);
    printf("%d\n", size);
    return 0;
}
