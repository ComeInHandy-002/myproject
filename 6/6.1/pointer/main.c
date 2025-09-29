#include <stdio.h>


//指针的本质（间接访问原理）

//指针就是地址，指针就是指针变量也就是保存地址的变量

int main(void) {
    int i=5;
    char c='a';

    //定义整型指针变量i_pointer,并初始化
    //int* i_pointer=&i;都可以
    int *i_pointer=&i;// 指针存储i的地址


    //先定义字符型指针变量c_pointer,然后再初始化
    char *c_pointer;
    c_pointer=&c;

    //注意事项
    /*
        1.定义多个（整型）指针变量
          int *a,b,c;//这种是错误的（这样只有a的指针变量，而a，b的整型）
          int *a,*b,*c;//这样是正确的

        2.float a;
          int *p;
          p=&a;//这样毫无意义而且会出错

        3."&"和"*"两个运算符的优先级相同，但要按自右向左的方向结合
          *&a与a（我们不会将取地址和取值放在一起去用）
          int *p = &a;
          *&p == p   // 对p取地址，然后解引用 → 还是p

    */

    //*是取值符号，而在初始化的时候int*，char*为指针类型
    //指针在使用前必须初始化否则会出现野指针

    int b=*i_pointer;
    printf("%d\n",b);//5

    //深刻的理解一下指针
    int sizei=sizeof(*i_pointer);//这里拿到的是指针所指向变量的大小
    printf("%d\n",sizei);//4（整型int的大小为4）

    int sizec=sizeof(*c_pointer);
    printf("%d\n",sizec);//1（字符型char的大小为1）

    int sizei2=sizeof(i_pointer);//这里拿到的是指针的大小（通常是固定的，与操作系统有关）
    int sizec2=sizeof(c_pointer);
    printf("sizei2=%d  sizec2=%d\n",sizei2,sizec2);//8

    //使用间接访问，修改i的值
    *i_pointer=10;
    printf("%d\n",i);//10,修改了i中的值


    return 0;
}
/*
    内存：
    地址 1000: a = 10
    地址 2000: p = 1000  (p存的是a的地址)

    操作：
    *p = 20  → 访问 p 指向的地址 1000，把值改成 20
*/

/*
    int a = 10;  // 普通变量
    int *p = &a; // 指针存储a的地址

    printf("%d\n", *p); // 间接访问 → 输出 10
    *p = 20;            // 间接修改 → a 的值变成 20
    printf("%d\n", a);  // 输出 20
*/

/*
为什么叫“间接访问”
普通变量访问：a → CPU直接从地址读取数据
指针访问：*p → CPU先读取 p 的值（一个地址），再去这个地址读取数据

所以是两步访问：
1.先访问指针本身的值（地址）
2.再访问该地址对应的内存

这就是“间接”的本质。
*/
