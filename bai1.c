/*
Lệnh clrscr() Bản chất là lệnh xoá màn hình những gì hiện ở trên nó nhưng câu lệnh này đã cũ
*/
#include<stdio.h>
#include<conio.h>
#include <stdlib.h> //thêm thư viện này
int main() {
    int a = 20 ; /* Khai bao va khoi dau cac bien */
    int b = 15;
    float x = 25.678;
    system("cls"); //Lệnh mới này thay cho clrscr() 
    printf("\n1:%d %f\n",a,x);
    printf("2:%4d %10f\n",b,x);
    printf("3:%2d %3f\n",a,x);
    printf("4:%10.3f %10d\n",x,b);
    printf("5:%-5d %f\n",a,x); //%-5d nghĩa là in ra kết quả ở những vị trí đầu và đằng sau là khoảng trống
    printf("6:%*d\n",b,b); // ký tự * này dùng để lấy giá trị đầu tiên sau dấu ',' tương đương là số ô vị trí là b
    printf("7:%*.*f\n",12,5,x);
    printf("8:%x :%8x :\n",a,a); //%x nghĩa là chuyển sang hệ thập lục phân
    printf("9:%o :%8o :\n",a,a); //%o nghĩa là xuất ra số nguyên dưới dạng bát phân
    getch();
}
