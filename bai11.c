#include <stdio.h>
#include <math.h>
int main(){
    float a,b,c;
    printf("Nhap vao he so a b c: ");
    scanf("%f %f %f",&a,&b,&c);
    while(a == 0){
        printf("Nhap lai gia tri a khac 0! \n");
        printf("Nhap lai he so a b c: ");
        scanf("%f %f %f",&a,&b,&c);
    }
    float denta = pow(b,2) - 4*a*c; //denta
    float x1,x2; //nghiệm
    if (denta < 0)
    {
        printf("Phuong trinh vo nghiem");
    }else if (denta == 0)
    {
        x1 = -(b/(2*a));
        printf("Phuong trinh co nghiem kep la: %f",x1);
    }else{
        x1 = (-b + sqrt(denta))/(2*a);
        x2 = (-b - sqrt(denta))/(2*a);
        printf("Phuong trinh co 2 nghiem la %f va %f",x1,x2);
    }
    
    
}