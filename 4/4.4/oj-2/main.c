#include <stdio.h>
//算n阶层
//这段代码有些问题
//0！的阶层为1，而且int类型存不了太大的数
int main(void) {
    int n;
    int sum=1;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        sum=sum*i;
    }
    printf("%d",sum);
    return 0;
}
