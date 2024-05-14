/*Bài này tớ sử dụng quy tắc lấy phần nguyên chia 2 và viết ngược lại phần dư, 
quy tắc này youtube có nhé*/
#include <stdio.h>
#include <math.h>
void doi_nhi_phan(int n){
    int luu1[100]; //mảng này tớ lưu giá trị các phần dư khi %2
    int dem1 = 0; //Biến này để đếm xem có bao nhiêu phần dư để dùng vòng lặp
    /*Vòng lặp này chạy đến khi phần nguyên / 2 bằng 0 
    (Do tớ giảm biến n sau lần nên hiểu n ở đây là phần nguyên sau khi chia)*/
    while (n / 2 > 0) 
    {
        dem1++;
        luu1[dem1] = n%2; //Mảng này lưu giá trị từ vị trí 1 nhé do cái biến đếm tớ thiết lập
        n = n/2;
    }
    //Vì vòng lặp trên chạy đến khi phần nguyên lớn > 0 thì dừng nên tớ xét thêm trường hợp phần nguyên cuối cùng = 0
    dem1++;
    luu1[dem1] = n%2;
    printf("Ket qua cua phep doi la: ");
    for (int i = dem1; i > 0; i--) //Vòng lặp này để in ra kết quả 
    {
        printf("%d",luu1[i]);
    }
}

void doi_thap_phan(int m){
    int luu2[100]; //Lưu giá trị của các chữ số của số nhị phân
    int dem2 = 0; //Biến đếm
    int ketqua = 0 ;//Tính kết quả
    while (m / 10 > 0 ) //Vòng lặp này chạy đến khi phần nguyên / 10 > 0 false thì dừng
    {
        dem2++;
        luu2[dem2] = m%10; //lưu giá trị các chữ số ( nhớ cái mảng này lưu giá trị số từ phải qua trái)
        m = m / 10;
    }
    //Xét nốt trường hợp phần nguyên = 0 
    dem2++;
    luu2[dem2] = m%10;
    for (int j = 0; j < dem2; j++)
    {
        ketqua = ketqua + pow(2,j)*luu2[j+1]; //Công thức nha cậu, cái chỉ số [j + 1] do tớ thiết lập từ giá trị = 1 ở mảng luu2
    }
    printf("Ket qua cua phep doi la: %d",ketqua);
    
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