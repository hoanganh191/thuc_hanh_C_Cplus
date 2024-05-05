//Bài này không sai gì cả, chú ý thứ tự thực hiện và toán tử 3 ngôi
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
int main(){
    int m = 3,p = 5;
    int a1,a2,a3,a4,a5;
    float x1,x2,x3,x4;
    system("cls");
    printf("\n Tim gia tri gan cho cac bien ");
    a1 = m<p; //m < p là đúng => trả về giá trị là 1
    a2 = m == p; // m = p là sai và trả về giá trị 0
    a3 = p%m + p>m; //p chia m dư 2 rồi 2 + 5 = 7 > 3 là true => trả về 1
    a4 = m*(p>m ? m:p); 
    //toán tử 3 ngôi, vì p = 5 > m = 3 true nên cái () trả về m , rồi a4 = m*m = 3*3 = 9
    a5 = m*(p<m ? p:p);
    //toán tử 3 ngôi, vì p = 5 < m = 3 false nên cái () trả về giá trị sau dấu : là p và a5 = m*p = 15
    x1 = p/m;
    x2 = (float)p/m;
    x3 = (p +0.5)/m;
    x4 = (int)(p+0.5)/m; 
    //vì giá trị của (p+0.5)/m = 5.5/3 nhưng trước nó bị ép kiểu int nên giá trị của x4 = 1 là 
    printf("\n a1 = %d ",a1);
    printf("\n a2 = %d ",a2);
    printf("\n a3 = %d ",a3);
    printf("\n a4 = %d ",a4);
    printf("\n a5 = %d ",a5);
    printf("\n x1 = %10.3f ",x1); 
    //10.3f nghĩa là dạng số thực trước nó có 10 ô ký tự tính cả dấu cách, phần thập phân có 3 ký tự
    printf("\n x2 = %10.3f ",x2);
    printf("\n x3 = %10.3f ",x3);
    printf("\n x4 = %10.3f ",x4);
    getch();
}
