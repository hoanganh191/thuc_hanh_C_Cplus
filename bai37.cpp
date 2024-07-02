#include <stdio.h>
#include <string.h>
struct sach{
	char masach[20];
	char tensach[40];
	char tacgia[40];
	int namxb;
};

sach input(){
	sach a;
	printf("Nhap ma sach: ");
	fflush(stdin);
	gets(a.masach);
	printf("Nhap ten sach: ");
	fflush(stdin);
	gets(a.tensach);
	printf("Nhap tac gia: ");
	fflush(stdin);
	gets(a.tacgia);
	printf("Nhap nam xuat bam: ");
	scanf("%d",&a.namxb);
	return a;
}

void output(sach a){
	printf("\n%-20s %-40s %-40s %-4d",a.masach,a.tensach,a.tacgia,a.namxb);
}
int main(){
	//viet chuong trinh nhap n quyen sach
	int n;
	do {
		printf("Nhap vao gia tri n: ");
		scanf("%d",&n);
	} while(n < 1);
	sach b[n];
	for(int i = 0; i < n; i++){
		b[i] = input();
	}
	
	//In ra quyen sach co ten < tin hoc dai cuong
	char check[] = "tin hoc dai cuong";
	printf("\n%-20s %-40s %-40s %-4s","Ma sach","Ten sach","Tac gia","Nam xuat ban");
	for(int i = 0; i < n; i++){
		if(strcmp(b[i].tensach,check) < 0) output(b[i]);
	} 
	
	//sap xep theo a,b,c,...
	for(int i = 0; i < n;i++){
		int min_index = i;
		for(int j = i + 1; j < n; j++){
			if(strcmp(b[i].tensach,b[j].tensach) < 0) {
				min_index = j;
			}
		}
		if(min_index != i){
			sach temp;
			temp = b[i];
			b[i] = b[min_index];
			b[min_index] = temp;
		}
	}
	printf("\nKet qua cua sap xep theo thu tu a,b,c.. la: ");
	printf("\n%-20s %-40s %-40s %-4s","Ma sach","Ten sach","Tac gia","Nam xuat ban");
	for(int i = 0; i < n; i++){
		output(b[i]);
	}
	
}
