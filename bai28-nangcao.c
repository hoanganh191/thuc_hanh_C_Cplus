#include <stdio.h>
#include <string.h>
#include <stdlib.h> //Khai báo thư viện để dùng stoi (Đổi chuỗi sang số nguyên)
#include <math.h>

void sapXepTangDan (int a[], int n){ //Hàm nhận giá trị 1 mảng và số lượng phần tử mảng
    for (int i = 0; i < n; i++)
    {
        int min_index = i;
        for (int j = i + 1; j < n; j++)
        {
            if (a[min_index] > a[j])
            {
               min_index = j;
            }
        }
        if (min_index != i)   
        {
            int temp = a[i]; //Biến tạm
            a[i] = a[min_index];
            a[min_index] = temp;
        }
        

    }
    //In ra kết quả
    printf("Day so sap xep theo chieu tang dan la :");
    for (int i = 0; i < n; i++)
    {
        printf("%d ",a[i]);
    }
    
}

void sapXepGiamDan (int a[],int n){
    for (int i = 0; i < n; i++)
    {
        int max_index = i;
        for (int j = i + 1; j < n; j++)
        {
            if (a[max_index] < a[j])
            {
                max_index = j;
            }
        }
        if (max_index != i)
        {
            int temp = a[i];
            a[i] = a[max_index];
            a[max_index] = temp;

        }
        
    }
    printf("Day so sap xep theo chieu giam dan la: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ",a[i]);
    }
    
}

void tbcCacSoLe(int a[], int n){
    float tongSoLe = 0;
    int dem = 0; //Đếm số lẻ
    for (int i = 0; i < n; i++)
    {
        if (a[i] % 2 == 1)
        {
            dem++;
            tongSoLe = tongSoLe + a[i];
        }
        
    }
    printf("Trung binh cong so le la: %.1f",tongSoLe/dem);
}

void timPhanTu(int a[],int n){
    int max = a[0];
    int min = a[0];
    for (int i = 1; i < n; i++) //Tìm Số lớn nhất
    {
        if (max < a[i])
        {
            max = a[i];
        }
    }
    for (int i = 1; i < n; i++) //Tìm số nhỏ nhất
    {
        if (min > a[i])
        {
            min = a[i];
        }
    }
    printf("So lon nhat la : %d va so nho nhat la : %d ",max,min);
    
}

void soHoanHao(int a[],int n){
    printf("Cac so hoan hao trong day la: ");
    for (int i = 0; i < n; i++)
    {
        int tongUoc = 0;
        for (int j = 1; j < a[i]; j++)
        {
            if (a[i] % j == 0)
            {
                tongUoc = tongUoc + j;
            }
            
        }
        if (tongUoc == a[i])
        {
            printf("%d ",a[i]);
        }
        
    }
    
}

void soChinhPhuong (int a[],int n){
    printf("Cac so chinh phuong trong day la: ");
    for (int i = 0; i < n; i++)
    {
        int can = sqrt(a[i]);
        if (can * can == a[i])
        {
            printf("%d ",a[i]);
        }
        
    }
    
}

int checkSoNto (int n){
    if (n == 1 || n == 2 || n == 3)
    {
        return 1;
    } 
    for (int i = 2; i < sqrt(n); i++)
    {
        if (n % i == 0)
        {
            return 0;
        }
        
    }
    return 1; //Vì nếu cái if và vòng for trên k chạy = > nó đúng là số nguyên tố
    
}

void inVaTinhTbcSoNto (int a[],int n){
    float tongSoNguyenTo = 0;
    int dem = 0;
    printf("Cac so nguyen to la: ");
    for (int i = 0; i < n; i++)
    {
        if (checkSoNto(a[i]) == 1) //Hàm if sẽ nhận 0 là sai , giá trị > 0 là đúng
        {
            dem++;
            printf("%d ",a[i]);
            tongSoNguyenTo = tongSoNguyenTo + a[i];
        }
        
    }
    printf("\nTrung binh cong cac so nguyen to la: %f",tongSoNguyenTo/dem);
}

void yeuCau8(int a[],int n){
    printf("Cac so chia het cho 6 tan cung bang 2 la: ");
    float tong = 0;
    int dem = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] % 6 == 0 && a[i] % 10 == 2)
        {
            dem++;
            printf("%d ",a[i]);
            tong = tong + a[i];
        }
        
    }
    printf("\nTBC cua cac so tren la: %f",tong/dem);
}

int main(){
    char nhap[100]; //Lưu giá trị nhập dưới dạng chuỗi
    int luu[100]; //Lưu giá trị nhập dưới dạng số sau khi đổi
    fgets(nhap,100,stdin);
    /*Vì k biết nhập bao nhiêu số thì dừng nên hàm này lưu giá trị nhập ở dạng chuỗi và tách thành 
    các chuỗi nhỏ ngắt nhau bởi dấu cách và dùng hàm chuyển sang số nguyên*/ 
    char *tach = strtok(nhap," ");
    int doi;
    int dem = 0; //Biến đếm
    while (tach != NULL)
    {
        doi = atoi(tach);
        luu[dem] = doi;
        dem++;
        tach = strtok(NULL," ");
    }
    printf("Nhap so chuong trinh thuc hien theo de: ");
    int chon;
    scanf("%d",&chon);
    switch (chon)
    {
    case 1:
        sapXepTangDan(luu,dem);
        break;
    case 2:
        sapXepGiamDan(luu,dem);
        break;
    case 3:
        tbcCacSoLe(luu,dem);
        break;
    case 4:
        timPhanTu(luu,dem);
        break;
    case 5:
        inVaTinhTbcSoNto(luu,dem);
        break;
    case 6:
        soChinhPhuong(luu,dem);
        break;
    case 7:
        soHoanHao(luu,dem);
        break;
    case 8:
        yeuCau8(luu,dem);
        break;
    default:
        printf("Khong co yeu cau do");
        break;
    }
}