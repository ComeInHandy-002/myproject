#include <stdio.h>
#include <string.h>

//1.gets函数
//2.puts函数
//3.str系列---strlen（统计字符串长度），strcpy（复制），strcmp（比较），strcat（连接）

int mystrlen(char a[])
{
    int i=0;
    while(a[i])// 等价于 while(a[i] != '\0')
    {
        i++;
    }


    return i;
}


int main(void) {
    /*
     会一直读取，直到遇到 换行符 \n 或 EOF。
     读到的字符串里不包含换行符，但会自动加上 \0 作为结束.
    */
    char c[20];
    gets(c);//使用gets不安全(不限制字符长度，可能会发生越界)
    puts(c);//puts(c)就等价于printf("%s\n",c);puts内放的参数是字符数组名

    //strlen用来计算字符串长度（不包括'\0'）
    printf("%d\n",strlen(c));//不是很好
    //strlen 的返回值类型是 size_t（无符号整数，通常是 unsigned int 或 unsigned long）。
    //如果直接用 %d 打印，在某些平台可能会有 类型不匹配的警告。

    //✅ 正确做法是用 %zu：
    printf("%zu\n", strlen(c));

    //sizeof
    printf("%zu\n",sizeof(c));

    //sizeof和strlen的对比
    char a[]={'h','e','l','l','o'};
    printf("%zu\n",sizeof(a));//5
    printf("%zu\n",strlen(a));//找到'\0'为止

    char b[]="hello";//数组的长度实际为6
    printf("%zu\n",sizeof(b));//6
    printf("%zu\n",strlen(b));//5(strlen不包括'\0')
    //调用mystrlen函数
    printf("%d\n", mystrlen(b));

    //strcyp





    return 0;
}


/*
安全替代

读字符串 → 用 fgets：

fgets(str, sizeof(str), stdin);


它会限制最多读多少个字符，避免越界。

输出字符串 → puts 就挺好用的。


 */


/*
1. sizeof

作用：在 编译时 计算某个变量或类型占用的字节数。

返回值类型：size_t（无符号整数）。

特点：

编译阶段就确定结果，不依赖运行时数据。

对数组：返回整个数组所占字节数。

对指针：返回指针本身的字节数（通常是 4 或 8 字节）。





2. strlen

作用：在 运行时 计算字符串的实际长度（直到 '\0' 结束）。

返回值类型：size_t。

特点：

不包括 '\0'。

必须是字符串（以 \0 结尾），否则结果不可预期。

需要运行时扫描字符数组。




3. 🔑 总结对比
特性	            sizeof	            strlen
计算阶段	        编译时	            运行时
作用对象	        任意变量或类型	        必须是字符串（\0 结尾）
结果	            内存大小（字节数）	    字符串长度（不含\0）
效率	            高效（编译器直接替换）	需要逐个遍历直到\0




👉 所以：

如果你要知道数组（比如 int a[100]）占多少字节，用 sizeof。

如果你要知道字符串 "hello" 的长度，用 strlen。


*/
