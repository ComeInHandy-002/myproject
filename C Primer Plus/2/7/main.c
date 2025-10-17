#include <stdio.h>
/*许多研究表明，微笑益处多多。编写一个程序，生成以下格式的输
出：
Smile!Smile!Smile!
Smile!Smile!
Smile!
该程序要定义一个函数，该函数被调用一次打印一次“Smile!”，根据程
序的需要使用该函数。*/

void smile()
{
    printf("Smile!");
}

int main(void)
{
    smile();
    smile();
    smile();
    printf("\n");
    smile();
    smile();
    printf("\n");
    smile();
    return 0;
}