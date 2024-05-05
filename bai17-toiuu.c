/*
Vì tờ 1k là tờ nhỏ chất có thể ghép thành hết tất cả giá trị 
=> Số cách cách phụ thuộc vào số tờ 2k và 5k, thiếu bao nhiêu thì lấy tờ 1k bù vào
=> lồng 2 vòng for cho số tờ 5k và 2k
*/
#include <stdio.h>
int main(){
    int so_5k,so_2k,so_1k; //số lượng mỗi loại tiền
    int so_cach = 1; //đếm số cách
    for (so_5k = 0; so_5k <= 20/5; so_5k++) //chạy cho đến số tờ 5k max
    {
       for (so_2k = 0; so_2k <= (20 - 5*so_5k)/2; so_2k++) //chạy cho đến max số tờ 2k có thể trong từng trường hợp 5k ở trên
       {
        so_1k = 20 - 5*so_5k - 2*so_2k;
        printf("Cach thu %d : %d to 5k - %d to 2k - %d to 1k\n",so_cach,so_5k,so_2k,so_1k);
        so_cach++;
       } 
    }
    
}

//Code by Hoàng Anh đớ thủ