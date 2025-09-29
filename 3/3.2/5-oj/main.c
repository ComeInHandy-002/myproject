#include <stdio.h>
//判断是否是闰年

//这个程序的非法输入有误，只考虑了i小于0和i大于10000的情况
int main(){

    int i=0;
    scanf("%d",&i);
    if(i>=0&&i<=10000)
    {
        if((i%4==0&&i%100!=0)||(i%400==0))
        {
            printf("yes\n");
        }
        else
        {
            printf("no\n");
        }
    }
    else
    {
        printf("非法输入\n");
    }



    return 0;
}


