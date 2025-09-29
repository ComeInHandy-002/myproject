#include <stdio.h>

//1.字符数组初始化及传递
//2.scanf读取字符串

//模拟printf("%s",arr2);操作
void print(char a[])//这里的 a[] 在函数参数里等价于 char *a，实际上传进来的是 字符串首地址。
{
    int i=0;
    while(a[i]!='\0')
    {
        printf("%c",a[i]);
        i++;
    }
}

int main(void) {

    //字符数组的初始化
    //方法1
    char arr1[]={'h','e','l','l','o'};//太麻烦不推荐

    //方法2
    char arr2[]="hello";//推荐


    char str1[] = "hello";         // 自动加上 '\0'，数组长度 = 6
    char str2[10] = "hi";          // 多余位置自动补 '\0'
    char str3[] = {'h','e','l','l','o','\0'}; // 手动加 '\0'


    char str4[5] = "hello";        // ❌ 错误，少了 '\0' 的空间
    //%s来输出一个字符串(遇到'\0'停止)
    printf("%s\n",str4);    //会产生乱码

    //模拟printf("%s",arr2);操作
    print(arr2);
    printf("");


    //scanf读取字符串
    //scanf读取字符串操作中，会自动往字符数组内存放'\0'
    char arr3[10];
    scanf("%9s",arr3);//要注意数组越界，最好限制一下长度（限制长度为9，留一位给'\0'）
    printf("%s\n",arr3);
    int c;
    while((c=getchar())!='\n'&&c!=EOF);
    //想要输出：i am good使用gets
    char arr4[10];
    gets(arr4);
    printf("%s\n",arr4);



    return 0;
}

/*
%s 读字符串
scanf("%s", str);
会 自动跳过前面的空格，从第一个非空白字符开始读取。
但是！遇到空格（或 Tab、换行）就停止。
*/