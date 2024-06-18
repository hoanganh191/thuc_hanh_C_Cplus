#include <stdio.h>
#include <ctype.h>
#include <string.h>
/*
Định hướng cách làm :
Hàm isalnum() kiểm tra có phải số/chữ hay không => nếu k phải chữ hoặc số thì trả về 0
=> biến ký tự thừa thành dấu space ' '
Dùng hàm strtok() Để tách các từ cách nhau bởi khoảng trắng
=> Thu được các từ riêng lẻ và sử lý theo yêu cầu đề
*/
char kyTuCuoi(char a){ 
	if(a == '!' || a == '.' || a == '?' || isalnum(a) != 0){
		return 0;
	} else{
		return 1;
	}
}

//Đếm số từ và tìm từ có ký tự dài nhất
void demTu_Max(char a[100]){ 
	char b[20][100]; //Khai báo mảng tối đa 20 từ, mỗi từ 100 ky tu 
	//Tách từ và lưu :
	char *token = strtok(a," ");
	int soTu = 0;
	while(token != NULL){
		strcpy(b[soTu],token);
		soTu++;
		token = strtok(NULL," ");
	}
	printf("\nSo tu cua chuoi la: %d",soTu);
	
	//Tìm từ có ký tự dài nhất
	int kichThuoc[soTu]; //Các giá trị trong mảng chính là số lượng ký tự ứng với từng từ
	for(int i = 0; i < soTu; i++){
		kichThuoc[i] = strlen(b[i]);
	}
		//Thuật toán tìm chỉ số lớn nhất của mảng
	int max_index = 0;
	for(int i = 0; i < soTu; i++){
		if(kichThuoc[max_index] < kichThuoc[i]){
			max_index = i;
		}
	}
	printf("\nTu co do dai lon nhat la: %s",b[max_index]);
}
int main(){
		//Nhap xau
	char xau[100] ="";//Xau ban đầu
	char dangChuan[100] = ""; //Xâu ở dạng chuẩn
	fflush(stdin);
	gets(xau);
	
		//Duyệt xâu, nếu không phải chữ cái/số thì biến thành dấu cách
	for(int i = 0; i < strlen(xau) - 1; i++){ // - 1 vi chua lai ky tu cuoi
		if(isalnum(xau[i]) == 0){
			xau[i] = ' ';
		}
	}
		//Ký tự kết thúc 1 câu tách riêng nó ra
	if(kyTuCuoi(xau[strlen(xau) - 1]) == 1){
		xau[strlen(xau) - 1] = ' ';
	}
		//Tách các từ cách nhau bởi dấu cách và nối vào dangChuan[100]
	char *token = strtok(xau," ");
	while(token != NULL){
		strcat(dangChuan,token);
		strcat(dangChuan," ");
		token = strtok(NULL," ");
	}
	printf("Xau sau khi loai bo ky tu vo nghia la: %s",dangChuan);
	
	//Chu cai dau viet hoa
	dangChuan[0] = toupper(dangChuan[0]);
	printf("\nChu cai dau cau viet hoa la: %s",dangChuan);
	
	//Dem so tu trong xau va in ra sau co do dai lon nhat
	demTu_Max(dangChuan);
	
}
