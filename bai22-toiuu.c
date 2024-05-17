#include <stdio.h>
#include <math.h>
int sang_nhi_phan(int n){ //Hàm đổi số thập phân sang nhị phân
    int so_nhi_phan = 0; //Kết quả
    int dem1 = 0; //Biến đếm 
    while (n > 0) //n ở đây hiểu là phần nguyên, vòng lặp này dừng khi phần nguyên = 0 thì dừng
    {
        /*Vì kết quả sẽ là viết phần dư từ dưới lên => Ta tính ra được kết quả bằng cách 
        tính tổng các thành phần cộng lại 
        VD: output =  (số dư lần 1)*10^0 + (Số dư lần 2)*10^1+...  */
        so_nhi_phan = so_nhi_phan + (n%2)*pow(10,dem1);
        dem1++;
        n = n / 2;
    }
    return so_nhi_phan;
    
}

int sang_thap_phan(int m){
    int so_thap_phan = 0; //kết quả
    int dem2 = 0; //biến đếm
    while (m > 0)
    {
        /*Vì mỗi vòng lặp (m%10) tương đương lấy giá trị của chữ số cuối cùng rồi áp dụng công thức*/
        so_thap_phan = so_thap_phan + (m%10)*pow(2,dem2);
        dem2++;
        m = m / 10;
    }
    return so_thap_phan;
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
        printf("So nhi phan %d doi sang so thap phan la : %d",a,sang_thap_phan(a));
        break;
    case 2:
        printf("So thap phan %d doi sang so nhi phan la: %d",a,sang_nhi_phan(a));
        break;
    default:
        printf("Khong co lua chon nao ca");
        break;
    }
}