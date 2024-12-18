#include <iostream>


using namespace std;

class Matrix {
    private:
        int **x;
        int n,m;
    public:
        Matrix(){
            n = 0;
            m = 0;
        }

        Matrix(int n1, int m1) : n(n1),m(m1){
            x = new int*[n]; //Cap phat bo nho
            for (int i = 0; i < n; i++)
            {
                x[i] = new int[m]{0};
            }
            
        }
        void nhap(){
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < m; j++)
                {
                    cout << "x[" << i << "]" << "[" << j << "] = ";
                    cin >> x[i][j];
                }
                
            }
            
            
        }

        void xuat(){
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    cout << x[i][j] << " ";
                }
                
                cout << "\n";
            }
            
        }

        friend Matrix cong(Matrix &a, Matrix &b);
        friend int tongHang2(Matrix &a);
        friend int tong_4dv(Matrix &a);


};

Matrix cong(Matrix &a, Matrix &b){
    if ((a.n != b.n) || (a.m != b.m))
    {
        cout << "2 Ma tran khong cung cap";
        return Matrix(); //Tra ve ma tran contructor nghia la ma tran 0x0
    }

    Matrix reslult(a.n,a.m);
    for (int i = 0; i < a.n; i++)
    {
        for (int j = 0; j < a.m; j++)
        {
            reslult.x[i][j] = a.x[i][j] + b.x[i][j];
        }
        
    }
    
    return reslult;
}

int tongHang2(Matrix &a){ //Tong cac gia tri tinh o hang 2 cua ma tran
    int s1 = 0;
    for (int j = 0; j < a.m; j++)
    {
        s1 = s1 + a.x[1][j];
    }

    return s1;
}

int tong_4dv(Matrix &a){
    // Day la 1 cach de tham khao , n la so hang con m la so cot
    // int tong = 0;
    // for (int i = 0; i < a.n; i++)
    // {
    //     for (int j = 0; j < a.m; j++)
    //     {
    //         if (i == 0 || i == a.n - 1 || j == 0 || j == a.m - 1)
    //         {
    //             tong = tong + a.x[i][j];
    //         }
            
    //     }
        
    // }
    
    // return tong;

   //Day la cach 2 , nang cao hon
   int tong = 0;
   //Ta tinh cot mep trai va cot mep phai
   for (int i = 0; i < a.n; i++)
   {
        tong = tong + a.x[i][0]; //Tinh cot dau tien
        //Cai if nay de tan dung bien chay i de tinh cot ben phai vao
        if (a.m > 1) //neu ma co 2 cot tro len thi moi tinh tiep
        {
            tong = tong + a.x[i][a.m - 1]; //Cai if nay chu yeu tan dung bien i chay cho gon code thoi, viet rieng ra cung duoc nhe
        }
        
   }

    //Tinh hang tren va hang duoi
   for (int i = 1; i < a.m - 1; i++) // i bat dau tu 1 de tru phan tu goc trau da tinh o cot , a.m -1 de tru di phan tu goc phai da tinh o cot
   {
        tong = tong + a.x[0][i];
        if(a.n > 1) //Neu co nhieu hon 1 hang thi moi tinh
        {
            tong = tong + a.x[a.n - 1][i];  //Cung chi tan dung bien i thui, tuong tu nhu tren
        }
   }
   
   return tong;
}

int main(){
    int n,m;
        cout << "\n Nhap so dong n = ";
        cin >> n;
        cout << "\n Nhap so cot m = ";
        cin >> m;
    Matrix a(m,n) , b(m,n);
    cout << "-----------------Nhap Ma tran A-----------------" << endl;
    a.nhap();
    cout << "\n-----------------Nhap Ma tran B-----------------" << endl;
    b.nhap();
    cout << "\n----------------Ma tran A vua nhap la-----------------" << endl;
    a.xuat();
    cout << "\n-----------------Ma tran B vua nhap la-----------------" << endl;
    b.xuat();
    Matrix c = cong(a,b);
    cout << "\n-----------------Tong 2 Ma tran la-----------------";
    c.xuat();
    cout << "\nTong cac phan tu nam tren dong 2 ma tran A la: " << tongHang2(a);
    cout << "\nTong cac phan tu o 4 duong vien ma tran A la: " << tong_4dv(a);




}

