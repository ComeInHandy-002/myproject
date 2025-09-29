#include <stdio.h>

//指针与一维数组


//数组名作为实参传递给子函数时，是弱化为指针的
//练习传递与偏移
void change(char *m)//形参没有数组变量一说
//写成void change(char m[])和void change(char *m)是完全等价的
{
    *m='H';
    m[1]='E';//等价于*(m+1)
    *(m+2)='L';
}

int main(void) {

    char c[10]="hello";
    change(c);//数组名作为实参传递给子函数时，是弱化为指针的
    puts(c);

    return 0;
}
/*
指针可以当数组用，但必须先指向一片有效的连续内存（数组或 malloc 的结果）。
否则就是未定义行为。
*/

/*
✅ 情况 1：指针指向数组
#include <stdio.h>
int main() {
    int a[5] = {1,2,3,4,5};
    int *p = a;   // 指向数组首元素

    printf("%d\n", p[0]); // 相当于 a[0]
    printf("%d\n", p[2]); // 相当于 a[2]
    return 0;
}

👉 在这种情况下，p[i] 和 a[i] 完全一样。
*/



/*
✅ 情况 2：指针指向动态内存
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n = 5;
    int *p = malloc(n * sizeof(int)); // 分配 5 个 int 的空间
    for (int i = 0; i < n; i++) {
        p[i] = i * 10;   // 像数组一样使用
    }
    for (int i = 0; i < n; i++) {
        printf("%d ", p[i]);
    }
    free(p); // 别忘了释放
    return 0;
}

👉 指针 p 指向堆上的一块连续空间，所以能像数组一样操作。
*/

/*
❌ 情况 3：指针未初始化
int *p;     // 野指针，未指向有效内存
p[0] = 10;  // ❌ 未定义行为（可能崩溃）

👉 如果指针没有指向有效内存，就不能当数组用。
*/