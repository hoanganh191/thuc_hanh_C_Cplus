#include <stdio.h>
#include <math.h>
int main(){
    int n;
    float x;
    float tong_T = 100;
     printf("Nhap gia tri cua n nguyen va so thuc x: ");
        scanf("%d %f",&n,&x);
    while (n == 0) //Vì n nằm ở mẫu
    {
        printf("Nhap lai gia tri cua n va x: ");
        scanf("%d %f",&n,&x);
    }
    for (int i = 0; i < n; i++)
    {
        tong_T = tong_T + (pow(-1,i)*x)/(10*(i+1)); //Dạng tổng quát
    }
    printf("Tong cua T la: %f",tong_T);
    

}