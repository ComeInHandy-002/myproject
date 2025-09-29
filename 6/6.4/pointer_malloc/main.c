#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//在指针中malloc的使用（栈空间和堆空间的差异）
//栈空间---在程序运行时空间的大小是确定的
//堆空间---是可以配一个可变的空间

//malloc的返回值类型是void *---无类型指针（无类型指针无法使用指针的偏移）
//所以在使用malloc都是把他的类型强转成int *，char *等
//include <stdlib.h>

//还有在使用完malloc后定要free（）一下


int main(void) {
    int size;//size代表我要申请多大字节的空间
    char *p;

    scanf("%d",&size);//请输入我们要申请空间的大小
    getchar();//清除缓冲区

    p=malloc(size);//malloc一般要强转一下
/*
✅ 总结
在 C：不强转也能偏移，因为 malloc 返回的 void* 自动转换为你定义的类型指针。
在 C++：必须强转。
最佳写法（C）：
char *p = malloc(size);
*/

    //gets(p);不好
    //fgets(p,size,stdin);更安全
    strcpy(p,"malloc success");
    puts(p);
    free(p);//free时必须使用malloc申请时返回的指针值，不能进行任何的偏移

    return 0;
}

/*
为什么 size=1 也能输出？

1. malloc(size) 分配的是真实内存块
当你申请 malloc(1)，理论上只得到 1 个字节的可用空间。
但是 堆分配器（glibc 的 malloc 等）为了效率，通常会分配比你要的更大的块（比如 8、16、32字节对齐）。
所以虽然你只申请了 1，实际得到的物理内存可能远远大于 1。
👉 这就导致 你写“越界数据”时，刚好落在了那块对齐分配的额外空间里，程序不会立刻崩溃。

2. strcpy 不管三七二十一全拷贝
strcpy(p,"malloc success");
"malloc success" 长度是 14（含 \0 一共 15 个字节）。
strcpy 会把这 15 个字节都拷过去。
实际上你只“合法”拥有 1 个字节，但因为底层分配了更多，写进去暂时没事。

3. 为什么还能 puts(p) 输出？
puts 只是从地址 p 开始，打印字符直到 \0 为止。
因为 strcpy 已经把字符串完整写到那片大于 1 的实际内存里，所以 puts 也能正常读出来。
*/
