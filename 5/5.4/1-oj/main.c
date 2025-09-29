#include <stdio.h>
/*Description
输入N个数（N小于等于100），输出数字2的出现次数；
解题提示：
整型数组读取5个整型数的方法如下：
int a[100];
for(int i=0;i<5;i++)
{
scanf("%d",&a[i]);
}
Input
输入的格式是两行
第一行输入要输的元素个数，比如5
第二行输入  1 2 2 3 2，那么输出结果为3，因为2出现了3次
Output
统计数字2出现的次数*/

int main(void) {
    int a[100];
    int n;
    int num=0;
    scanf("%d",&n);
    int c;
    while((c=getchar())!='\n'&&c!=EOF);
    //将数字存入数组
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }

    for (int i = 0; i <n ; ++i)//将数组遍历一遍
    {
        if(a[i]==2)
        {
            num++;
        } else
        {
            while(a[i])
            {
                if(a[i]%10==2)
                {
                    num++;
                }
                a[i]/=10;
            }
        }
    }
    printf("%d\n",num);
    return 0;
}

/*逻辑不清晰导致这段代码写的很罗嗦*/


/*反思：在初级阶段先用自然语言梳理好逻辑，在用伪代码写出来*/




