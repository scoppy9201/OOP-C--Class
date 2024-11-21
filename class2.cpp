#include <iostream>
#include <cmath>
using namespace std;

class phanso {
	private:
		int tu, mau;
	public:
		phanso(int t = 0, int m = 1);
		~phanso();
		void nhapps();
		void inps() const;
		int UCLN(int a, int b) const;
		phanso rutgon() const;
		phanso cong(const phanso& p) const;
		phanso tru(const phanso& p) const;
		phanso nhan(const phanso& p) const;
		phanso chia(const phanso& p) const;
};

// ham tao phan so
phanso::phanso(int t , int m ) : tu(t), mau(m){
	if(mau == 0){
		cout << "Mau so khong duoc bang 0. Da gan mau so = 1 "<< endl;
		mau = 1;
	}
}
	
// ham huy
phanso::~phanso(){}
	
// phuong thuc nhap phan so
void phanso::nhapps(){
	cout << "Nhap tu so: ";
	cin >> tu;
	cout << "Nhap mau so: ";
	cin >> mau;
}
	
// phuong thuc xuat phan so 
void phanso::inps() const {
	if(mau == 1)
		cout << tu << endl;
	else
		cout << tu << " / " << mau << endl;
}
	
// dinh nghia ham tim USCLN
int phanso::UCLN(int a, int b) const{
	while(b != 0){
		int temp = b; 
		b = a % b;
		a = temp;
	}
	return a;
}

// dinh nghia phuong thuc rut gon phan so 
phanso phanso::rutgon() const{
	int gcd = UCLN(abs(tu), abs(mau));
	return phanso(tu / gcd, mau / gcd);
}
	
// phep cong phan so 
phanso phanso::cong(const phanso& p) const{
	int new_tu = tu * p.mau + mau * p.tu;
	int new_mau = mau * p.mau;
	return phanso(new_tu, new_mau).rutgon();
}
	
// phép tru phan so 
phanso phanso::tru(const phanso& p) const{
	int new_tu = tu * p.mau - mau * p.tu;
	int new_mau = mau * p.mau;
	return phanso(new_tu, new_mau).rutgon();
}
	
// phep nhan phan so
phanso phanso::nhan(const phanso& p) const{
	int new_tu = tu * p.tu;
	int new_mau = mau * p.mau;
	return phanso(new_tu, new_mau).rutgon();
}
	
// phep chia phan so 
phanso phanso::chia(const phanso& p) const{
	int new_tu = tu * p.mau;
	int new_mau = mau * p.tu;
	return phanso(new_tu, new_mau).rutgon();
}

int main()
{
	phanso p1, p2;
	
	cout << "Nhap phan so thu nhat:\n";
	p1.nhapps();
	cout << "Nhap phan so thu hai:\n";
	p2.nhapps();
	
	cout << "Tong = ";
	p1.cong(p2).inps();
	cout << "Hieu = ";
	p1.tru(p2).inps();
	cout << "Tich = ";
	p1.nhan(p2).inps();
	cout << "Thuong = ";
	p1.chia(p2).inps();
	
	return 0;
}
