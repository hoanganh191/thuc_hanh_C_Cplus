#include <stdio.h>
//Luu ý: Nen chay code tren DevC++
struct SinhVien{
        char hoTen[30];
        int namSinh;
        float dtb;
    };

typedef SinhVien sv; //thay vì viet SinhVien gio chi can viet tat la sv

SinhVien input(){
	struct SinhVien a; //Dai dien cho du lieu cua 1 sinh vien
	printf("Nhap ho ten: ");
	fflush(stdin);
	gets(a.hoTen);
	printf("Nhap nam sinh:");
	scanf("%d",&a.namSinh);
	printf("Nhap diem trung binh: ");
	scanf("%f",&a.dtb);
	return a;
	
}

void output(sv a){
	printf("\n %-30s %4d \t %.1f",a.hoTen,a.namSinh,a.dtb);
}

int loaiKha (sv a){
	if(7 <= a.dtb && a.dtb < 8 ){
		return 1;
	}else {
		return 0;
	}
	
}

sv sapXepGiamDtb(sv b[],int n){
	for (int i = 0; i < n; i++){
		int max_index = i;
		for(int j = i + 1; j < n; j++){
		 	if(b[max_index].dtb < b[j].dtb){
				max_index = j;
			}
		}
		if(max_index != i){
			sv temp; //Bien tam de doi du lieu 2 bien
			temp = b[max_index];
			b[max_index] = b[i];
			b[i] = temp;
		}
	}
	
	//In ra man hinh ket qua sap xep
	printf("\nDanh sach sinh vien theo thu tu giam dan diem trung binh la: ");
	for(int i = 0; i< n; i++){
		output(b[i]);
	}
}
int main(){
    //Nhap n sinh vien
	sv danhSach[100];
	int n;
	printf("Nhap vao so sinh vien: ");
	scanf("%d",&n);
	for(int i = 0; i<n ;i++){
		danhSach[i] = input();
	}
	//In ra danh sach sinh vien loai kha
    printf("\nDanh sach sinh vien xep loai kha la: ");
	for(int i = 0;i < n;i++) {
		if(loaiKha(danhSach[i]) == 1){
			output(danhSach[i]);
		}
	}
	
	//In ra sinh vien co nam sinh <1997
	printf("\nDanh sach sinh vien co nam sinh < 1997 la: ");
	for(int i = 0; i < n; i++){
		if(danhSach[i].namSinh < 1997 ){
			output(danhSach[i]);
		}
	}
	//Sap xep sinh vien
	sapXepGiamDtb(danhSach,n);
    
}

