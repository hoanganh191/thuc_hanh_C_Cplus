#include <stdio.h>
int main(){
    int a,don_vi,tram,chuc;//a là số có 3 chữ số 
    printf("Nhap so co 3 chu so: ");
    scanf("%d",&a);
    don_vi = a%10;
    chuc = (a/10)%10; //Chia /10 nghĩa là lấy phần nguyên thành số có 2 chữ số rồi lấy phần dư để lấy giá trị hàng chục 
    tram = (a/100)%10; 
    printf("Chu so hang tram la: %d\n",tram);
    printf("Chu so hang chuc la: %d\n",chuc);
    printf("Chu so hang tram la: %d",don_vi);
}