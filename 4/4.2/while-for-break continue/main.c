#include <stdio.h>
//while循环 for循环 break continue的学习

int main(void) {
    //while循环
    /*
     特点：
     先判断表达式，后执行语句

     语法：
     while (条件)
     {
     循环体;
     }
     */

    //计算1~100之间所有整数之和
    int i=1,sum=0;
    int sum2=0;

    while(i<=100)
    {
        sum+=i;
        i++;
    }
    printf("%d\n",sum);
    /*
        方法2：sum2=(1+100)*100/2
    */
    printf("%d\n",sum2=(1+100)*100/2);

    //for循环
    /*
    语法：
        for (初始化; 条件; 更新)
        {
            循环体;
        }

    常用在循环次数确定的情况下。

     (初始化; 条件; 更新)内的两个分号不可以省略
     初始化：可以多个变量初始化，用逗号隔开
    */

    //for循环实现1~100整数求和
    int sum3=0;
    for(int a=1;a<=100;a++)
    {
        sum3+=a;
    }
    printf("%d\n",sum3);
    /*
       放在 for 循环里
       for (int a=1; a<=100; a++)
       for (int a=1; a<=100; ++a)
       这里的 a++ 或 ++a 都在 循环的“更新部分”，而更新部分的结果不会被使用，只是单纯让 a 加 1。
👉     所以它们的效果 完全一样：从 1 到 100 循环一次。
     */

    //b++和++b的区别
    int b = 5;
    printf("%d\n", b++);  // 输出 5，b 变成 6
    printf("%d\n", ++b);  // 输出 7，b 已经是 6，再加 1 变 7

    //continue语句
    //用于 跳过当前这一次循环，直接进入下一次。

    //打印 1 到 10，但跳过偶数
    int i1=1;
    while(i1<=10)
    {
        if(i1%2!=0)
        {
            printf("%d\n",i1);
            i1++;
        } else{
            i1++;
            continue;
        }
    }
/*你这段代码 👍 已经能实现「打印 1 到 10，但跳过偶数」了。
不过里面 else 里的 continue; 实际上是 多余的，因为 while 循环到达末尾后会自然回到条件判断。*/

    int i2=1;
    while(i2<=10)
    {
        if(i2%2!=0)
        {
            printf("%d\n",i2);
        }
        i2++;
    }

    //若想要使用continue
    int i3=1;
    while(i3<=10)
    {
        if(i3%2==0)
        {
            i3++;
            continue;
        }
        printf("%d ",i3);
        i3++;
    }

    //对1~100之间的奇数进行求和
    int sum4=0;
    //for(int i4=1,sum=0;i4<=100;i4++)
    for(int i4=1;i4<=100;i4++)//在 for 循环的声明里，如果你用了 int 来声明变量，那后面用逗号分隔的变量都必须是同一类型。
    {
        if(i4%2!=0)
        {
            sum4+=i4;
        }
    }
//局部变量的问题
/*
    int sum;
    for (int i4 = 1,sum=0; i4 <= 100; i4++)
    {
        if (i4 % 2 != 0)
        {
         sum += i4;
        }
    }
    printf("%d\n", sum);
❌ 问题在哪里

你在 for 的初始化部分 写了 int i4 = 1，sum=0;

int 出现了 → 这就是 一个声明语句。

声明语句里的 sum=0，其实是 重新声明了一个新的 sum（局部变量），它屏蔽了你外面定义的那个 sum。

所以外层的 sum 一直没被赋值，最后 printf 的是“未初始化的值”（结果可能是垃圾数）。

*/
    printf("%d\n",sum4);

    //优化(遍历奇数i4每次+2就可以)
        int sum5 = 0;
        for (int i4 = 1; i4 <= 100; i4 += 2)
        {
            sum5 += i4;
        }
        printf("%d\n", sum5);

    //使用continue来计算1~100的奇数和
    int sum6 = 0;
    for(int i = 1;i<=100;i++)
    {
        if(i%2==0)
        {
            continue;
        }
        sum6+=i;
    }
    printf("%d\n",sum6);


    //break 语句
    //👉 用于 提前结束整个循环。
    for (int i = 1; i <= 20; i++)
    {
        if (i % 7 == 0)
        {
            printf("找到啦: %d\n", i);
            break;  // 直接跳出循环
        }
    }

    //综合例子
    //👉 输入一组数，输出正数的和，遇到负数提前结束：
    int num=0;
    int sum7=0;
    while(1)
    {
        printf("输入一组数:\n");
        scanf("%d",&num);
        if(num<0)
        {
            break;
        }
        if (num == 0) {
            continue;  // 遇到 0，跳过，不加到和里
        }
        sum7+=num;
    }
    printf("正数之和 = %d\n", sum7);
    /*int num, sum7 = 0;

    while (1) {  // 死循环，等着 break 跳出
        printf("请输入一个数(输入负数结束): ");
        scanf("%d", &num);

        if (num < 0) {
            break;   // 遇到负数，退出循环
        }

        if (num == 0) {
            continue;  // 遇到 0，跳过，不加到和里
        }

        sum7 += num;
    }

    printf("正数之和 = %d\n", sum7);*/

    return 0;
}
/*
while注意事项：
while();这里加分号可能导致死循环
还有就是循环体内没有让while判断表达式趋近于假的操作
*/


/*
while 和 for 的选择

while：更适合次数不确定的循环（比如一直读输入，直到输入为负数）。

for：更适合次数确定的循环（比如循环 100 次）。
*/
