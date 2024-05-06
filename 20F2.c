#include <stdio.h>
#include <math.h>
int main(){
    float x;
    int n;
    float tong_F2 = 0;
    printf("Nhap gia tri cua n nguyen va so thuc x: ");
    scanf("%d %f",&n,&x);
    while (n < 1) //Bởi vì bắt đầu từ e^x
    {
        printf("Nhap gia tri cua n nguyen > 1 va so thuc x : ");
        scanf("%d %f",&n,&x);
    }
    
    for (int i = 1; i <= n; i++)
    {
        tong_F2 = tong_F2 + exp(i*x);
    }
    printf("Tong cua F2 la : %f",tong_F2);
}