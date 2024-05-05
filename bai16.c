#include <stdio.h>
#include <ctype.h> //Sử dụng hàm isalpha() và isdigit()
int main(){
    char ky_tu; //Ký tự nhập vào từ bàn phím
    printf("Nhap ky tu :");
    scanf("%c",&ky_tu);
    /*hàm isalpha() kiểm tra xem có phải chữ cái không ,
    Nếu đúng hàm trả giá trị về 1 , sai tra ve gia tri la 0 */
    if (isalpha(ky_tu)) 
    {
        printf("Ky tu do la chu cai");
    }
    /*hàm isdigit() kiểm tra xem có phải số hay không ,
    Nếu đúng hàm trả giá trị về 1 , sai tra ve gia tri la 0 */
    else if (isdigit(ky_tu)){
        printf("Ky tu do la chu so");
    }
    else{
        printf("Day la ky tu khac khong phai chu cai va chu so");
    }
    
}