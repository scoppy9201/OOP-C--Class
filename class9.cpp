#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
class SoPhuc{
	private: 
		double PhanThuc;
		double PhanAo;
	public:
		SoPhuc () : PhanThuc(0), PhanAo(0) {}
		SoPhuc(double thuc , double ao ){
			PhanThuc = thuc;
			PhanAo = ao;
		}
		~SoPhuc();
		friend istream& operator>>(istream& is, SoPhuc& sp);
		friend ostream& operator<<(ostream& os, const SoPhuc& sp);
		SoPhuc operator+(const SoPhuc& sp)const;
		SoPhuc operator-(const SoPhuc& sp)const;
		SoPhuc operator*(const SoPhuc& sp)const;
		SoPhuc operator/(const SoPhuc& sp)const;
};

SoPhuc::~SoPhuc(){
	PhanThuc = 0;
	PhanAo = 0;
}

istream& operator>>(istream& is, SoPhuc& sp){
	cout << "Nhap phan thuc: ";
	is >> sp.PhanThuc;
	cout << "Nhap phan ao: ";
	is >> sp.PhanAo;
	return is;
}

ostream& operator<<(ostream& os, const SoPhuc& sp){
	os << sp.PhanThuc << (sp.PhanAo >= 0 ? " + " : " - ") << abs(sp.PhanAo) << "i";
	return os;
}

SoPhuc SoPhuc::operator+(const SoPhuc& sp)const{
	return SoPhuc(PhanThuc + sp.PhanThuc, PhanAo + sp.PhanAo);
}

SoPhuc SoPhuc::operator-(const SoPhuc& sp)const{
	return SoPhuc(PhanThuc - sp.PhanThuc, PhanAo - sp.PhanAo);
}

SoPhuc SoPhuc::operator *(const SoPhuc& sp)const{
	return SoPhuc(PhanThuc*sp.PhanThuc - PhanAo*sp.PhanAo, PhanThuc*sp.PhanAo + PhanAo*sp.PhanThuc);
}

SoPhuc SoPhuc::operator /(const SoPhuc& sp)const{
	float mauSp = sp.PhanThuc*sp.PhanThuc + sp.PhanAo*sp.PhanAo;
	return SoPhuc((PhanThuc*sp.PhanThuc + PhanAo*sp.PhanAo) / mauSp, 
	(PhanThuc*sp.PhanAo - PhanAo*sp.PhanThuc ) / mauSp);
}

int main()
{
	int n;
	cout << "Nhap so luomg so phuc: ";
	cin >> n;
	
	SoPhuc dsSP[100];
	for(int i = 0; i < n; i++){
		cout << "Nhap so phuc thu: " << i+1 << ":\n";
		cin >> dsSP[i];
	}
	
	// gam biem bang so phuc dau tien 
	SoPhuc tong = dsSP[0];
	SoPhuc hieu = dsSP[0];
	SoPhuc tich = dsSP[0];
	SoPhuc thuong = dsSP[0];
	
	for(int i = 1; i < n; i++){
		tong = tong + dsSP[i];
		hieu = hieu - dsSP[i];
		tich = tich * dsSP[i];
		thuong = thuong / dsSP[i];
	}
	
	cout << "\nTong cua cac so phuc la: " << tong << endl;
	cout << "Hieu cac so phuc la: " << hieu << endl;
	cout << "Tich cac so phuc la: " << tich << endl;
	cout << "Thuong cac so phuc la: " << fixed << setprecision(2) << thuong << endl;
	
	return 0;
}


