/*Bài này tớ sử dụng quy tắc lấy phần nguyên chia 2 và viết ngược lại phần dư, 
quy tắc này youtube có nhé*/
#include <stdio.h>
#include <math.h>
void doi_nhi_phan(int n){
    int so_nhi_phan = 0;
    int luu1[100]; //mảng này tớ lưu giá trị các phần dư khi %2
    int dem1 = 0; //Biến này để đếm xem có bao nhiêu phần dư để dùng vòng lặp
    /*Vòng lặp này chạy đến khi phần nguyên / 2 bằng 0 
    (Do tớ giảm biến n sau lần nên hiểu n ở đây là phần nguyên sau khi chia)*/
    while (n > 0) //Tớ thay điều kiện lặp này so với code cũ vì nó tối ưu hơn
    {
        luu1[dem1] = n%2; //Mảng này lưu giá trị từ vị trí 0
        dem1++;
        n = n/2;
    }
    for (int i = 0; i < dem1; i++) //Vòng lặp này để tính ra số nhị phân 
    {
        so_nhi_phan = so_nhi_phan + luu1[i]*pow(10,i);
    }
    printf("Ket qua cua phep doi la: %d",so_nhi_phan);
}

void doi_thap_phan(int m){
    int luu2[100]; //Lưu giá trị của các chữ số của số nhị phân
    int dem2 = 0; //Biến đếm
    int so_thap_phan = 0 ;//Tính kết quả
    while (m  > 0 ) //Vòng lặp này chạy đến khi phần nguyên > 0 false thì dừng
    {
        luu2[dem2] = m%10; //lưu giá trị các chữ số ( nhớ cái mảng này lưu giá trị số từ phải qua trái)
        dem2++;
        m = m / 10;
    }
   
    for (int j = 0; j < dem2; j++)
    {
        so_thap_phan = so_thap_phan + pow(2,j)*luu2[j]; 
    }
    printf("Ket qua cua phep doi la: %d",so_thap_phan);
    
}
int main(){
    printf("Nhan 1 de doi sang so thap phan");
    printf("\nNhan 2 de doi sang so nhi phan\n");
    printf("Lua chon cua ban la: ");
    int chon; //Lựa chọn menu
    scanf("%d",&chon);
    int a; //Lưu giá trị đầu vào
    printf("Nhap so muon chuyen: ");
    scanf("%d",&a);
    //Lưu ý khi nhập: số kiểu 101101,.. có thể là số nhị phân hoặc thập phân 
    //Số kiểu 2345,... (có chứa sô khác 0 và 1) chỉ là số thập phân nhé
    switch (chon)
    {
    case 1:
        doi_thap_phan(a);
        break;
    case 2:
        doi_nhi_phan(a);
        break;
    default:
        printf("Khong co lua chon nao ca");
        break;
    }
    
}