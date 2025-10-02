#include <stdio.h>

//函数的递归调用
//递归（Recursion）就是 函数自己调用自己，并且要有一个终止条件，否则会无限循环导致栈溢出。（死循环）


//使用递归来实现数字n的阶乘（是为理解递归）
int recursion_n(int i)
{
    //一定要有终止条件
    if (1==i)
    {
        return 1;
    }
    return i*recursion_n(i-1);//写公式
}

int main(void)
{
    int n=0;
    scanf("%d",&n);
    printf("recursion_n(%d)=%d\n",n,recursion_n(n));
    return 0;
}

/*
递归 vs 循环
循环：效率高，占用内存小。
递归：代码简洁，结构清晰，但效率可能低，递归太深可能栈溢出。
*/

/*
✅ 总结
递归的关键点：
1.必须有 终止条件。
2.每次调用要 逼近终止条件。
3.利用 调用栈 保存中间状态。
 */