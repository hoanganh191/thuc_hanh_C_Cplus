#include <stdio.h>
int main(){
    int thang,nam;
    printf("Nhap thang va nam: ");
    scanf("%d %d",&thang,&nam);
    while (thang > 12 || thang < 1 || nam < 0)
    {
        printf("Nhap lai: ");
        scanf("%d %d",&thang,&nam);
    }
    switch(thang){
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            printf("Thang %d co 31 ngay",thang);
            break;
        case 4: case 6: case 9: case 11:
            printf("Thang %d co 30 ngay",thang);
            break;
        case 2:
            if (nam % 4 == 0 && nam % 100 != 0)
            {
                printf("Thang 2 co 29 ngay");
            }else{
                printf("Thang 2 co 28 ngay");
            }
            break;
    }
}