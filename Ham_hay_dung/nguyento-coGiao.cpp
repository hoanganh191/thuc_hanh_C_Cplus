#include <stdio.h>
#include <math.h>

int main(){
int n;
     printf("Nhap gia tri cua n : ");
     scanf("%d",&n);
     printf("Cac so nguyen to la: ");
     for (int i = 2; i < n; i++) //Vòng lặp chạy các số từ 2 đến n ( vì các số nguyên tố bắt đầu từ 2)
     {
          if (i == 2 || i == 3) //2 và 3 là trường hợp đặc biệt nên là số nguyên tố luôn
          {
               printf("%d ",i);
               continue; //Vòng lặp gặp dòng này là chạy đến giá trị i tiếp theo luôn
          }
       
       //Khi i khác 2 và 3 thì sẽ là trường hợp bình thường
          int laNguyenTo = 1; //Giả sử là số nguyên tố đúng = 1, không là số nguyên tố = 0
          for (int j = 2; j < i - 1; j++) //Vòng lặp để ước của số i (Vì số nào cũng chia hết cho 1 nên bắt đầu từ 2)
          {
               if (i % j == 0) //Nếu if này đúng => số này có ước khác 1 và chính nó
               {
                    laNguyenTo = 0; //=> không là số nguyên tố
                    break; //Thoát khỏi vòng lặp j
               }
          }
       
          if (laNguyenTo == 1) /*Nếu chạy hết cái vòng lặp j mà k có ước => nó là số nguyên tố*/
          {
               printf("%d ",i);
          }
       
     }

}