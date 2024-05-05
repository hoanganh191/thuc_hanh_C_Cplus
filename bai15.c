#include <stdio.h>
int main(){
    int a,b;
    char ch;
    printf("Nhap vao 2 so nguyen a va b va ky tu ch: ");
    scanf("%d %d %c",&a,&b,&ch);
    if (ch == '+')
    {
        printf("Tong 2 so la: %d",a+b);
    }
    else if (ch == '-')
    {
        printf("Hieu cua a - b la: %d",a-b);
    }
    else if (ch == '*')
    {
        printf("Tich cua 2 so la: %d",a*b);
    }
    else if (ch == '/')
    {
        printf("Thuong cua a chia b la: %f",(float)a/b);
    }else {
        printf("Khong phai la phep toan");
    } 
    
}