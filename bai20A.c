#include <stdio.h>
int main(){
    int n;
    int tong_A = 0;
    printf("Nhap gia tri cua n: ");
    scanf("%d",&n);
    while (n < 0) //vì đề bài xuất phát từ n từ 0 mới chạy được
    {
        printf("Nhap lai so n > 0 : ");
        scanf("%d",&n);
    }
    for (int i = 1; i <= n; i++)
    {
        tong_A = tong_A + i*(i+1);
    }
    printf("Gia tri cua tong A la : %d",tong_A);
    
}
