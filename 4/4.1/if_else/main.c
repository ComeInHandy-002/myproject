#include <stdio.h>
//if-else


int main(void) {
    //5>3&&8<4-!0的值为？
    printf("%d\n",5>3&&8<4-!0);//(5>3为1)---(!0为1)---(4-1为3)---(8<3为0)---(1&&0为0)

    int i;
    while( scanf("%d",&i))
    {
        if(i>0)
        {
            printf("i is bigger than 0\n");
        }
        else{
            printf("i is not bigger than 0\n");
        }
    }
    //清空缓冲区

    int ch;
    while ((ch=getchar())!='\n' && ch!=EOF);
    //这种写法优点：
    //除了遇到换行符 \n 会停，还能在输入结束（EOF）时停，不会死循环。
    //更稳健，特别是处理文件输入时。

    /*
    while (getchar() != '\n');
    特点：
    一直读取字符，直到遇到换行符 \n 停止。

    简单好用，常用于清理掉前一次输入多余的回车。

    局限：

    如果输入数据里没有换行符（例如遇到文件结束 EOF 的情况），这个循环就可能陷入 死循环。

    所以它更适合用于键盘输入场景（因为用户总会按回车）。
    */

    //成绩>=90为优秀，80~90为良好，70~80为中，60~70为及格，<60为不及格
    int score;
    while(scanf("%d",&score))
    {
        if(score>=90)
        {
            printf("优秀\n");
        }
        else if(score>=80)
        {
            printf("良好\n");
        }
        else if(score>=70)
        {
            printf("中\n");
        }
        else if(score>=60)
        {
            printf("及格\n");
        }
        else{
            printf("不及格\n");
        }
    }


    return 0;
}
/*
if-else的注意事项
  else 对应最近的 if（就近原则）
  if (x > 0); 错误，这里多了分号，导致 if 判断没有效果（分号误用）
  if-else if-else 多分支


*/