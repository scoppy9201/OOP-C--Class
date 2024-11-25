#include <iostream>
#include <cmath/.b;b vn vmb j v bj f >
using namespace std;
class PhanSo {
	private: 
		int tuSo;
		int mauSo;
	public:
		PhanSo() : tuSo(0), mauSo(1) {}
		PhanSo(int tu, int mau) : tuSo(tu), mauSo(mau) {}
		~PhanSo();
		friend istream& operator>>(istream& is, PhanSo& ps);
		friend ostream& operator<<(ostream& os, const PhanSo& ps);
		
		PhanSo operator+(const PhanSo& ps)const;
		PhanSo operator-(const PhanSo& ps)const;
		PhanSo operator*(const PhanSo& ps)const;
		PhanSo operator/(const PhanSo& ps)const;
		
		int UCLN(int a, int b)const;
		PhanSo rutgon()const;
};

PhanSo::~PhanSo()
{
	tuSo = 0;
	mauSo = 0;
}
istream& operator>>(istream& is, PhanSo& ps)
{
	cout << "Nhap tu so: ";
	is >> ps.tuSo;
	cout << "Nhap mau so: ";
	is >> ps.mauSo;
	return is;
}
ostream& operator<<(ostream& os, const PhanSo& ps)
{
	os << ps.tuSo << " / " << ps.mauSo;
	return os;
}

int PhanSo::UCLN(int a, int b) const{
	while(b != 0){
		int temp = b; 
		b = a % b;
		a = temp;
	}
	return a;
}

PhanSo PhanSo::rutgon() const{
	int gcd = UCLN(abs(tuSo), abs(mauSo));
	return PhanSo(tuSo / gcd, mauSo / gcd);
}

PhanSo PhanSo::operator+(const PhanSo& ps)const
{
	int new_tu = tuSo * ps.mauSo + mauSo * ps.tuSo;
	int new_mau = mauSo * ps.mauSo;
	return PhanSo(new_tu, new_mau).rutgon();
}
PhanSo PhanSo::operator-(const PhanSo& ps)const
{
	int new_tu = tuSo * ps.mauSo - mauSo * ps.tuSo;
	int new_mau = mauSo * ps.mauSo;
	return PhanSo(new_tu, new_mau).rutgon();
}
PhanSo PhanSo::operator*(const PhanSo& ps)const
{
	int new_tu = tuSo * ps.tuSo;
	int new_mau = mauSo * ps.mauSo;
	return PhanSo(new_tu, new_mau).rutgon();
}
PhanSo PhanSo::operator/(const PhanSo& ps)const
{
	int new_tu = tuSo * ps.mauSo;
	int new_mau = mauSo * ps.tuSo;
	return PhanSo(new_tu, new_mau).rutgon();
}

int main()
{
	int n;
	cout << "Nhap so luong phan so: ";
	cin >> n;
	
	PhanSo dsPS[100];
	
	for(int i = 0; i < n; i++){
		cout << "Nhap phan so thu " << i+1 << endl;
		cin >> dsPS[i];
	}
	
	PhanSo tong = dsPS[0];
	PhanSo hieu = dsPS[0];
	PhanSo tich = dsPS[0];
	PhanSo thuong = dsPS[0];
	
	for(int i = 1; i < n; i++){
		tong = tong + dsPS[i];
		hieu = hieu - dsPS[i];
		tich = tich * dsPS[i];
		thuong = thuong / dsPS[i];
	}
	
	cout << "\nTong cua cac phan so la: " << tong << endl;
	cout << "Hieu cac phan so la: " << hieu << endl;
	cout << "Tich cac phan so la: " << tich << endl;
	cout << "Thuong cac phan so la: " << thuong << endl;
	
	return 0;
}


