#include <stdio.h>

//求字节运算符sizeof

int main() {
    printf("char类型占用字节数: %zu\n", sizeof(char));//1
    printf("int类型占用字节数: %zu\n", sizeof(int));//4
    printf("float类型占用字节数: %zu\n", sizeof(float));//4
    printf("double类型占用字节数: %zu\n", sizeof(double));//8
    return 0;
}