#include <stdio.h>
#include <math.h>

int checkNguyenTo(int a){ //Hàm kiểm tra số nguyên tố
    //Trường hợp đặc biệt
    if (a == 2 || a == 3)
    {
        return 1; //Trả về đúng 
    }
    
    for (int i = 2; i <= sqrt(a); i++) //Tìm nghiệm của a, chạy từ 2 đến căn a cho nó nhanh
    {
        if (a%i == 0) //Nếu số a có chia hết cho i => không là số nguyên tố
        {
            return 0; //Trả về sai
        }  
    }
    
    //Nếu mà vòng lặp trên không tìm thấy ước nào của a 
    return 1; //Trả về đúng
}
int main(){
    int n;
    printf("Nhap gia tri cua n : ");
    scanf("%d",&n);
    printf("Cac so nguyen to la: ");
    for (int i = 2; i < n; i++)
    {
        if (checkNguyenTo(i))
        {
            printf("%d ",i);
        }
        
    }
    
}
