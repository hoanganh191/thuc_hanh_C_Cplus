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
			cout << "Hoten" << hoten << "\tGioitinh" << gioitinh << "\tNamsinh" << namsinh; 
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
			cout << "Mapb" << mapb << "\tChucvu" << chucvu << "\tNamct" << namcongtac; 
		}
		string getMaphongban()
		{
			return mapb;
		}
};

main()
{
	NhanSu ns[10];
	int i, n;
	cout << "Nhap so luong nhan vien: "; cin >> n;
	for (i = 0; i < n; ++i) 
	{
        cout << "Nhap thong tin nhan vien thu " << i << ":" << endl;
        ns[i].nhap();
	}
	
	cout << "\nDanh sach nhan vien phong hanh chinh: \n";
	for(i =0; i<n ; i++)
	{
		if(ns[i].getMaphongban() == "HANH CHINH"){
			ns[i].xuat();
		}
	}
	
	cout << "\nNhan vien co tuoi cao nhat: ";
	int max = ns[0].tinhTuoi();
	for(i =0; i<n ; i++)
	{
		if(ns[i].tinhTuoi() > max){
			ns[i].tinhTuoi() == max;
				ns[i].xuat();
		}
	}
}
