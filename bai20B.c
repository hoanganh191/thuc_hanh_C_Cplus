#include <stdio.h>
int main(){
    int n;
    float x;
    float tong_B = 10; //Nhớ đề float vì cộng phân số 
    printf("Nhap gia tri cua n va x: ");
    scanf("%d %f",&n,&x);
    while (x == 0 || n < 2) //Điều kiện x do đề bài còn n < 2 do phân số chạy từ 2/x +....
    {
        printf("Nhap lai so thoa man n > 2 va x khac 0 : ");
        scanf("%d %f",&n,&x);
    }
    for (int i = 2; i <= n; i++)
    {
        tong_B = tong_B + (float)i/x;
    }
    printf("Gia tri cua tong B la : %f",tong_B);
    
}