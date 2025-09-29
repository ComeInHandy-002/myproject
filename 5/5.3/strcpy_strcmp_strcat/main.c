#include <stdio.h>
#include <string.h>

int main() {
    char src[] = "hello";
    char dest[20];   // 确保空间足够
    char str1[] = "apple";
    char str2[] = "banana";
    char base[30] = "I like ";  // 用于拼接

    // 1️⃣ strcpy 复制
    strcpy(dest, src);
    printf("strcpy: dest = %s\n", dest);

    // 2️⃣ strcmp 比较
    printf("strcmp: \"%s\" vs \"%s\" = %d\n", str1, str2, strcmp(str1, str2));
    printf("strcmp: \"%s\" vs \"%s\" = %d\n", str2, str1, strcmp(str2, str1));
    printf("strcmp: \"%s\" vs \"%s\" = %d\n", str1, "apple", strcmp(str1, "apple"));

    // 3️⃣ strcat 拼接
    strcat(base, str2);  // 把 "banana" 拼到 "I like " 后面

    //现在base中存放的是“I like banana”
    printf("strcat: base = %s\n", base);


    //可以很清楚的显示sizeof和strlen（易错容易混淆）
    char arr[]="hello";
    int i=sizeof(arr);
    int j=strlen(arr);
    printf("%d\n",i);//6
    printf("%d\n",j);//5

    /*
        1️⃣ sizeof(arr)
        arr[] = "hello"; 初始化时，C 会自动在最后加上 \0 结尾符。
        实际数组内容是：{'h','e','l','l','o','\0'}。
        所以数组长度是 6。
        sizeof(arr) 得到的是整个数组所占字节数，即 6。

        2️⃣ strlen(arr)
        strlen 只统计字符串中 字符的数量，不包括 \0。
        "hello" 的长度是 5。
    */



    return 0;
}




/*
1. strcpy —— 复制字符串
char *strcpy(char *dest, const char *src);


功能：把 src 字符串（包含末尾的 \0）复制到 dest。

要求：dest 足够大，否则会溢出。

返回值：返回 dest 的地址。

✅ 示例：

#include <stdio.h>
#include <string.h>

int main() {
    char src[] = "hello";
    char dest[10];

    strcpy(dest, src); // 把 "hello" 复制到 dest
    printf("dest = %s\n", dest); // hello
    return 0;
}

2. strcmp —— 比较字符串
int strcmp(const char *s1, const char *s2);


功能：逐个比较两个字符串的 ASCII 码。

返回值：

0 → 两个字符串相等。

<0 → s1 < s2。

>0 → s1 > s2。

✅ 示例：

#include <stdio.h>
#include <string.h>

int main() {
    char a[] = "apple";
    char b[] = "banana";

    printf("%d\n", strcmp(a, b)); // <0，因为 "apple" < "banana"
    printf("%d\n", strcmp(b, a)); // >0
    printf("%d\n", strcmp(a, "apple")); // 0
    return 0;
}

3. strcat —— 拼接字符串
char *strcat(char *dest, const char *src);


功能：把 src 追加到 dest 的末尾（覆盖 dest 里原来的 \0），并在最后补上新的 \0。

要求：dest 的空间必须够大，能容纳原来的字符串 + 新字符串 + \0。

返回值：返回 dest 的地址。

✅ 示例：

#include <stdio.h>
#include <string.h>

int main() {
    char a[20] = "hello";
    char b[] = " world";

    strcat(a, b); // a = "hello world"
    printf("%s\n", a);
    return 0;
}

📌 总结对比
函数	功能	注意点
strcpy	把一个字符串复制到另一个	dest 必须足够大
strcmp	比较字符串大小	返回 0 表示相等
strcat	拼接字符串	dest 必须足够大

⚠️ 提醒：这三个函数都不检查目标数组大小，容易产生缓冲区溢出。
👉 更安全的替代函数：

strncpy（限制长度的复制）

strncmp（限制长度的比较）

strncat（限制长度的拼接）









 */