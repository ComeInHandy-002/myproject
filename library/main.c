#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>   // for sleep/usleep

// 定义清屏函数
void clrscr() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

// 定义 gotoxy
void gotoxy(int x, int y) {
    printf("\033[%d;%dH", y, x);
}

// 定义 delay (毫秒)
void delay(int ms) {
    usleep(ms * 1000);
}

// 定义日期结构
struct date {
    int da_day;
    int da_mon;
    int da_year;
};

// 获取当前日期
void getdate(struct date *d) {
    time_t t = time(NULL);
    struct tm *tm_info = localtime(&t);

    d->da_day = tm_info->tm_mday;
    d->da_mon = tm_info->tm_mon + 1;  // 月份从 0 开始
    d->da_year = tm_info->tm_year + 1900;
}

// ================== 示例菜单 =====================

char *mainmenu[] = {
        "Member",
        "Book",
        "Reports",
        "Help",
        "Exit"
};

void showmenu(char **menu, int count, int sr, int sc) {
    clrscr();
    printf("\n==== Library Management System ====\n\n");
    for (int i = 0; i < count; i++) {
        gotoxy(sc, sr + i);
        printf("%d. %s\n", i + 1, menu[i]);
    }
}

int getchoice(int count) {
    int ch;
    printf("\nEnter choice: ");
    scanf("%d", &ch);
    return ch;
}

// ================== 主程序 =====================
int main() {
    int ch;
    struct date d;

    clrscr();
    getdate(&d);
    printf("Today: %d/%d/%d\n", d.da_day, d.da_mon, d.da_year);
    sleep(1);

    while (1) {
        showmenu(mainmenu, 5, 3, 5);
        ch = getchoice(5);

        switch (ch) {
            case 1: printf("Member Menu...\n"); sleep(1); break;
            case 2: printf("Book Menu...\n"); sleep(1); break;
            case 3: printf("Reports...\n"); sleep(1); break;
            case 4: printf("Help...\n"); sleep(1); break;
            case 5: printf("Exiting...\n"); exit(0);
            default: printf("Invalid choice\n"); sleep(1);
        }
    }
    return 0;
}
