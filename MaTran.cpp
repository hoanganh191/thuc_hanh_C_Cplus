#include <iostream>
#include <string>

using namespace std;

class Matrix {
    private:
        string tenMatrix;
        int x[5][5];
        int n,m;
    public:
        Matrix(){
            n = 0;
            m = 0;
        }

        Matrix(int n1, int m1){
            n = n1;
            m = m1;
        }

        friend istream &operator >> (istream &is , Matrix &a);
        friend ostream &operator << (ostream &os, Matrix &a);
        Matrix operator + (Matrix b);
        Matrix operator - (Matrix b);
        Matrix operator * (Matrix b);
        int tongDcc();
};

istream &operator >> (istream &is, Matrix &a){
    cout << "\nNhap so dong = ";
    is >> a.n;
    cout << "Nhap so cot = ";
    is >> a.m;
    for (int i = 0; i < a.n; i++)
    {
        for (int j = 0; j < a.m; j++)
        {
            cout << "a[" << i << " , " << j << "]= ";
            cin >> a.x[i][j];
        }
        
    }

    return is;  
}

ostream &operator << (ostream &os, Matrix &a){
    for (int i = 0; i < a.n; i++)
    {
        for (int j = 0; j < a.m; j++)
        {
            os << a.x[i][j] << " ";
        }

        os << "\n";
        
    }

    return os;
    
}

Matrix Matrix::operator+(Matrix b){
    Matrix c;
    if (n != b.n || m != b.m)
    {
       
       cout << "Kich thuoc ma tran khong khop" << endl;
       return c; //Tra ve doi tuong tam thoi tao boi contructor  mac dinh co kich thuoc 0x0
    }
    
    c.n = n;
    c.m = m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            c.x[i][j] = x[i][j] + b.x[i][j];
        }
        
    }
    
    return c;
    
}

Matrix Matrix::operator-(Matrix b){
    Matrix c;
    if (n != b.n || m != b.m)
    {
       
       cout << "Kich thuoc ma tran khong khop" << endl;
       return c; //Tra ve doi tuong tam thoi tao boi contructor  mac dinh co kich thuoc 0x0
    }
    
    
    c.n = n;
    c.m = m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            c.x[i][j] = x[i][j] - b.x[i][j];
        }
        
    }
    
    return c;
    
}

Matrix Matrix::operator*(Matrix b){
    Matrix c;
    if (m != b.n)
    {
        cout << "Kich thuoc khong dung: ";
        return c;
    }
    
    c.n = n;
    c.m = b.m;
    for (int i = 0; i < c.n; i++)
    {
        for (int j = 0; j < c.m; j++)
        {
            c.x[i][j] = 0;
            for (int k = 0; k < m; k++)
            {
                c.x[i][j] += x[i][j]*b.x[i][j];
            }
            
        }
        
    }

    return c;
    
}

int Matrix::tongDcc(){
    int tong = 0;
    if (m == n)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (i == j)
                {
                    tong += x[i][j];
                }
                
            }
            
        }
        
    }
    
    return tong;
    
}


int main(){
    Matrix maTran1, maTran2, ketqua;
    cout << "------Nhap ma tran thu nhat ------------" << endl;
    cin >> maTran1;
    cout << "------Nhap ma tran thu 2----------------" << endl;
    cin >> maTran2;

    cout << "-------Tong 2 ma tran la------------------ " << endl;
    ketqua = maTran1 + maTran2;
    cout << ketqua;

    cout << "--------Hieu 2 ma tran la-------------------" << endl;
    ketqua = maTran1 - maTran2;
    cout << ketqua;

    cout << "--------Tich 2 ma tran la-------------------" << endl;
    ketqua = maTran1 * maTran2;
    cout << ketqua;

    cout << "\nTong duong cheo chinh tai ma tran dau la: " << maTran1.tongDcc();

}

