#include <stdio.h>


//这个写法不正确如果输入数末尾是0就不进入循环
/*
int main(void) {
    int a,j=0;
    scanf("%d",&a);
    for(;a%10!=0;a/=10)
    {
        j++;
    }
    printf("%d\n",j);
    return 0;
}
*/
int main(void) {
    int m=0;
    //scanf("%d",&m);

    while(scanf("%d",&m))//程序连续执行
    {
        int sum=0;
        int i=m;
        while(m)
        {
            int x=m%10;
            sum=sum*10+x;
            m/=10;
        }
        if(sum==i)
        {
            printf("yes\n");
        }else{
            printf("no\n");
        }

    }
    return 0;
}
