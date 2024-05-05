#include <stdio.h>
int main(){
    int a,don_vi,tram,chuc;//a là số có 3 chữ số 
    printf("Nhap so co 3 chu so: ");
    scanf("%d",&a);
    don_vi = a%10;
    a = a/10;
    chuc = a%10;
    a = a/10;
    tram = a%10;
    printf("Chu so hang tram la: %d\n",tram);
    printf("Chu so hang chuc la: %d\n",chuc);
    printf("Chu so hang tram la: %d",don_vi);
}