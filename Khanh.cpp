#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Nguoi{
	protected:
		string hoten, gioitinh;
		int namsinh;
	public:
		void nhap()
		{
			cin.ignore();
			cout << "Nhap ho ten: ";
			getline(cin, hoten);
			cout << "\nNhap gioi tinh: ";
			getline(cin, gioitinh);
			cout << "\nNhap nam sinh: ";
			cin >> namsinh;
		}
		void xuat()
		{
			cout << "Hoten : " << hoten << "\tGioitinh : " << gioitinh << "\tNamsinh : " << namsinh; 
		}
		int tinhTuoi()
		{
			return 2024 - namsinh;
		}
};

class NhanSu : public Nguoi
{
	private:
		string mapb, chucvu;
		int namcongtac;
	public:
		void nhap()
		{
			Nguoi::nhap();
			cin.ignore();
			cout << "\nNhap ma phong ban: ";
	        getline(cin, mapb);
	        cout << "\nNhap chuc vu: ";
	        getline(cin, chucvu);
	        cout << "\nNhap nam cong tac: ";
	        cin >> namcongtac;
		}
		void xuat()
		{
			Nguoi::xuat();
			cout << "\tMapb : " << mapb << "\tChucvu : " << chucvu << "\tNamct : " << namcongtac << endl; 
		}
		string getMaphongban()
		{
			return mapb;
		}
};

int main()
{
	NhanSu ns[10];
	int i, n;
	cout << "Nhap so luong nhan vien: "; cin >> n;
	for (i = 0; i < n; ++i) 
	{
        cout << "Nhap thong tin nhan vien thu " << i + 1 << ":" << endl;
        ns[i].nhap();
	}
	
    cout << "----------------------------------";
	cout << "\nDanh sach nhan vien phong hanh chinh: \n";
	for(i =0; i<n ; i++)
	{
		if(ns[i].getMaphongban().compare("HANH CHINH") == 0){ //Nen su dung compare va viet hoa y het noi dung ben trong
			ns[i].xuat();
		}
	}
	
    
    cout << "--------------------------------";
    //Thuat toan sai can sua lai
	cout << "\nNhan vien co tuoi cao nhat: " << endl;
    int viTriTuoiMax = 0; // Bien nay se di tim vi tri nguoi co tuoi cao nhat trong mang, ta gia su nguoi dau tien cao tuoi nhat
    for(int i = 1; i < n; i++){ //Vong lap de so sanh nhung nguoi con lai voi gia thuyet
        if(ns[viTriTuoiMax].tinhTuoi() < ns[i].tinhTuoi()){ //Neu co nguoi nao do co nhieu tuoi hon, cap nhat vi tri
            viTriTuoiMax = i; //Cap nhat vi tri nguoi co nhieu tuoi nhat la nguoi do
        }
    }

    //Vong lap ket thuc, bay gio bien viTriTuoiMax luu vi tri cua nguoi nhieu tuoi nhat
    ns[viTriTuoiMax].xuat();


	
}