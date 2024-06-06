#include <stdio.h>

void input(int n,int m,int a[][100]){
    printf("Moi ban nhap ma tran: \n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            scanf("%d",&a[i][j]);
        }
        
    }
    
}

void output(int n,int m,int a[][100]){
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            printf("%d ",a[i][j]);
            
        }
        printf("\n");    
    }
    
}

void sapXepTang(int m,int a[]){ //Sắp xếp mảng 1 chiều
    for (int i = 0; i < m; i++)
    {
        int min_index = i;
        for (int j = i + 1; j < m; j++)
        {
            if (a[min_index] > a[j])
            {
                min_index = j;
            }
            
        }
        if (min_index != i)
        {
            int temp = a[i];
            a[i] = a[min_index];
            a[min_index] = temp;
        }
        
    }
    
}

void sapXepGiam(int m,int a[]){
     for (int i = 0; i < m; i++)
    {
        int max_index = i;
        for (int j = i + 1; j < m; j++)
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
}

void yeuCau1(int n,int m,int a[][100]){
    //Chuyển ma trận về mảng một chiều
    int luu[m*n];
    int dem = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            luu[dem] = a[i][j];
            dem++;
        }
        
    }

    //Sắp xếp mảng 1 chiều
    sapXepTang(m*n,luu);
    
    //Đưa gia trị mảng 1 chiều vào ma trận tăng dần
    dem = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            a[i][j] = luu[dem++];
        } 
    }
    printf("Ma tran sap xep tang dan tu trai qua phai, tu tren xuong duoi la: \n");
    output(n,m,a);

    //Đưa giá trị mảng 1 chiều vào ma trận giảm dần
    dem = (m*n)-1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            a[i][j] = luu[dem--];
        }
        
    }
    printf("Ma tran sap xep giam dan tu trai qua phai, tu tren xuong duoi la: \n");
    output(n,m,a);
    
    
}

void xepDongTang(int n,int m,int a[][100]){
    for (int i = 0; i < n; i++)
    {
        /*Mảng a là mảng 2 chiều , ta viết a[i] thì máy tự hiểu là lấy hết các giá trị của hàng
        như a[i][0],a[i][1],.... Đây là cách tà đạo*/ 
        sapXepTang(m,a[i]); 
    }
    output(n,m,a);
    
}
void xepDongGiam(int n,int m,int a[][100]){
    for (int i = 0; i < n; i++)
    {
        sapXepGiam(m,a[i]);
    }
    output(n,m,a);
}

void xepCotTang(int n,int m,int a[][100]){
    for (int j = 0; j < m; j++)
    {
        for (int i = 0; i < n; i++)
        {
            int min_index = i;
            for (int k = i + 1; k < n; k++)
            {
                if (a[min_index][j] > a[k][j])
                {
                    min_index = k;
                }
                
            }
            if (min_index != i)
            {
                int temp = a[i][j];
                a[i][j] = a[min_index][j];
                a[min_index][j] = temp;
            }
            
            
        }
        
    }
    printf("Ma tran xep theo cot tang la: \n");
    output(n,m,a); 
}

void xepCotGiam(int n,int m, int a[][100]){
    for (int j = 0; j < m; j++)
    {
        for (int i = 0; i < n; i++)
        {
            int max_index = i;
            for (int k = i + 1; k < n; k++)
            {
                if (a[k][j] > a[max_index][j])
                {
                    max_index = k;
                }  
            }
            if (max_index != i)
            {
                int temp = a[max_index][j];
                a[max_index][j] = a[i][j];
                a[i][j] = temp; 
            }
             
        }
        
    }
    printf("Ma tran xep theo cot giam la: ");
    output(n,m,a);
    
}

void maxAndMin(int n,int m,int a[][100]){
    int min = a[0][0];//Giả sử phần tử đầu tiên nhỏ nhất
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (min > a[i][j])
            {
                min = a[i][j];
            }
            
        }
        
    }
    printf("Gia tri nho nhat cua ma tran la : %d",min);
    
    int max = a[0][0]; //Giả sử phần tử đầu tiên là lớn nhất
    // so sánh max với từng phần tử nếu max < số nào đó thì cho max = số đó đến khi k còn số nào < max
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (max < a[i][j])
            {
                max = a[i][j];
            }
            
        }
        
    }
    printf("\nGia tri lon nhat cua ma tran la: %d",max);

}

void inVien(int n,int m,int a[][100]){
    printf("Vien cua ma tran la: \n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (i == 0 || i == n-1 || j == 0 || j == m - 1) //Do mảng tính từ 0
            {
                printf("%d\t",a[i][j]);
            }else{
                printf(" \t");
            }
            
        }
        printf("\n");
    }
    
}
int main(){
    int matran[100][100]; //Mảng lưu trữ ma trận (kích thước tối đa tớ thiết lập là 100x100)
    int n,m;
    do
    {
        printf("Nhap kich thuoc cua mang: ");
        scanf("%d %d",&n,&m);

    } while (m <= 0 || n <= 0);
    input(n,m,matran);
    int chon; //biến lựa chọn
    printf("Nhap yeu cau theo de bai: ");
    scanf("%d",&chon);
    switch(chon){
        case 1:
            yeuCau1(n,m,matran);
            break;
        case 2:
            xepDongTang(n,m,matran);
            break;
        case 3:
            xepCotTang(n,m,matran);
            break;
        case 4:
            xepDongGiam(n,m,matran);
            break;
        case 5:
            xepCotGiam(n,m,matran);
            break;
        case 6:
            maxAndMin(n,m,matran);
            break;
        case 7:
            inVien(n,m,matran);
            break;
        default:
            printf("Khong ton tai trong de");
            break;

    }
    
}