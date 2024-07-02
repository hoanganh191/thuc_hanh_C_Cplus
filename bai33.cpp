#include<stdio.h>
#include<string.h>

int main(){
	char text[100];
	printf("Moi ban nhap xau: ");
	fflush(stdin);
	gets(text);
	
	//Do dai cua xau
	printf("Do dai cua xau vua nhap la: %d",strlen(text));
	
	//Doi xau tu chu thuong => Hoa
	char chuHoa[100]; //Tao xau moi va copy thong tin tu xau goc, tranh bi bien doi xau goc
	strcpy(chuHoa,text);//Copy xau
	printf("\nXau doi sang chu hoa la : %s",strupr(chuHoa));
	
	//Nhap vao ky tu xem co bao nhieu ky tu trung voi ky tu vua nhap
	char check;
	printf("\nNhap vao ky tu muon dem: ");
	scanf("%c",&check);
	int dem = 0;
	for(int i = 0; i < strlen(text) - 1 ; i++){
		if(text[i] == check){
			dem++;
		}
	}
	printf("So ky tu trung voi ky tu vua nhap la: %d",dem);
	
	//In ra man hinh xau co thu tu nguoc lai
	char xauDao[100];
	strcpy(xauDao,text); //Copy xau
	printf("\nXau do theo thu tu nguoc lai la: %s",strrev(xauDao));
}
