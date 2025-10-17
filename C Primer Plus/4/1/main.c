#include <stdio.h>
//编写一个程序，提示用户输入名和姓，然后以“名,姓”的格式打印出来

int main(void)
{
    char arr1[10];
    char arr2[20];
    printf("请输入名和性：");
    scanf("%s%s",arr1,arr2);
    printf("%s,%s",arr1,arr2);
    return 0;
}