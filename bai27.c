#include <stdio.h>
//tìm ucln bằng thuật toán euclid
int ucln(int a,int b){
    if (a == 0 || b == 0)
    {
        return a + b; //Vì trường hợp có 1 số a hoặc b == 0 nên ucln chính là số còn lại = tổng 2 số
    }
    
    int temp; //biến tạm để đổi giá trị giữa các biến
    if (b > a) //Vì mong muốn số chia là a (số lớn hơn) => nếu b > a thì đổi giá trị của 2 biến này
    {
        temp = b;
        b = a;
        a = temp;
    }
    //Áp dụng thuật toán
    while (a % b != 0 )
    {
        //Lấy a chia b phần nguyên bao nhiêu rồi lại chia cho số dư lặp lại đến khi số dư = 0
        //Ta hiểu ở đay a là số chia , b là phần dư của phép chia suốt
        temp = a % b; //Lấy phần dư 
        a = b;
        b = temp;
        
    }
    //Vòng lặp trên dừng khi số chia a chia cho số dư phép chia trước là b dư 0 => b là ucln
    return b;

}

int bcnn(int m,int n){
    return (m*n)/ucln(m,n);
}
int main(){
    int x,y; //Tử số và mẫu số
    do {
        printf("Nhap lan luot gia tri nguyen duong cua tu so va mau so :");
        scanf("%d %d",&x,&y);
    } while( y == 0 ); //Vì mẫu số khác 0
    int CanChia = ucln(x,y);
    x = x / CanChia;
    y = y / CanChia;
    printf("Phan so rut gon la: %d/%d",x,y);

}
