#include <stdio.h>
int main(){
    int a,b; //2 số nhập từ bàn phím
    int tong; //tong 2 so
    printf("Nhap vao 2 so tu nhien: ");
    scanf("%d %d",&a,&b);
    //Kiểm tra xem có phải nhập số tự nhiên hay không 
    while (a < 0 || b < 0) 
    {
        printf("Nhap lai 2 so tu nhien: ");
        scanf("%d %d",&a,&b);
    }
    tong = a + b; //Tính tổng
    printf("Tong cua 2 so la: %d",tong);//In ra tổng

}