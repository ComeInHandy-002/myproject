#include <stdio.h>
#include <string.h>


/*读取一个字符串，字符串可能含有空格，将字符串逆转，原来的字符串与逆转后字符串相同，输出0，原字符串小于逆转后字符串输出-1，
大于逆转后字符串输出1。例如输入 hello，逆转后的字符串为 olleh，因为hello 小于 olleh，所以输出-1
注意最后的判断一定要这么写，因为strcmp（比较）标准C中并不是返回-1和1，而是负值和正值
int result = strcmp(c, d);
if (result < 0)
{
printf("%d\n",-1);
}
else if (result > 0)
{
printf("%d\n", 1);
}
else {
printf("%d\n", 0);
}
Input
输入一个字符串，例如 hello，当然输入的字符串也可能是 how are you，含有空格的字符串
Output
输出是一个整型数，如果输入的字符串是hello，那么输出的整型数为-1*/
int main(void) {
    char a[1000]={};
    char b[1000]={};
    gets(a);
    //puts(a);
    int len=strlen(a);
    int lenb=len;
    //printf("%d\n",len);
    for(int i=0;i<len;i++)
    {
        //b[lenb-1]=a[i];
        //lenb-=1;
        b[lenb-1-i]=a[i];
    }
    //不知道要加
    b[lenb]='\0';
    int result = strcmp(a, b);
    if (result < 0)
    {
        printf("%d\n",-1);
    }
    else if (result > 0)
    {
        printf("%d\n", 1);
    }
    else {
        printf("%d\n", 0);
    }

    return 0;
}


/*在写这段代码时，基础功能可以实现，但是有许多危险操作可能导致程序bug*/
