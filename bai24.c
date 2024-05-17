#include <stdio.h>
int giaithua(int m){
    if (m == 1)
    {
        return 1;
    }
    return m*giaithua(m-1);
}

void tinhtong(int k){
    int ketqua = 0;
    for (int i = 1; i <= k; i++)
    {
        if (i % 2 != 0) //Neu i la so le
        {
            ketqua = ketqua + giaithua(i);
        }
        else { //Nếu k là lẻ sẽ rơi vào trường hợp còn lại là số chẵn
            ketqua = ketqua - giaithua(i);
        }
        
    }
    printf("Ket qua cua tong S = %d",ketqua);
    
}

int main(){
    int n;
    printf("Nhap so nguyen duong n: ");
    scanf("%d",&n);
    tinhtong(n);

}