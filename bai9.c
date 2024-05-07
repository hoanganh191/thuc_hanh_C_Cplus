#include <stdio.h>
#include <conio.h>
#include <math.h>

int main(){
	float a,b,c;
	float cv,s;
	float p; //nua chu 
	printf("Nhap do dai 3 canh: ");
	scanf("%f %f %f",&a,&b,&c);
	if(a < b + c && b < a + c && c < a + b ){
		cv = a + b + c;
		p = cv/2;
		s = sqrt(p*(p-a)*(p-b)*(p-c));
		printf("Chu vi cua tam giac laf: %f \n",cv);
		printf("Dien tich cua tam giac la: %f",s);
	}else{
		printf("Day khong phai tam giac");
	}
	return 0;
}
