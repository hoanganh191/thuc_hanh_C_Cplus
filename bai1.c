/*
L?nh clrscr() b?n ch?t là d? xoá màn hình (Xoá các ph?n tru?c câu l?nh này)
*/
#include<stdio.h>
#include<conio.h>
#include <stdlib.h> //thêm thu vi?n này
int main() {
    int a = 20 ; /* Khai bao va khoi dau cac bien */
    int b = 15;
    float x = 25.678;
    system("cls"); //l?nh này là l?nh b?n m?i thay cho clrscr() 
    printf("\n1:%d %f\n",a,x);
    printf("2:%4d %10f\n",b,x);
    printf("3:%2d %3f\n",a,x);
    printf("4:%10.3f %10d\n",x,b);
    printf("5:%-5d %f\n",a,x);
    printf("6:%*d\n",b,b);
    printf("7:%*.*f\n",12,5,x);
    printf("8:%x :%8x :\n",a,a);
    printf("9:%o :%8o :\n",a,a);
    getch();
}
