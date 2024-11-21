// su dung nap chong toán tu 
#include <iostream>
#include <cmath>
using namespace std;
class SoPhuc{
	private:
		float phanThuc;
		float phanAo;
	
	public:
		SoPhuc(){
			phanThuc = 0;
			phanAo = 0;
		}
		
		SoPhuc(float t, float a){
			phanThuc = t;
			phanAo = a;
		}
		
		~SoPhuc();
		
		friend istream& operator>>(istream& is, SoPhuc& sp);
		friend ostream& operator<<(ostream& os, const SoPhuc& sp);
		
		SoPhuc operator + (const SoPhuc& sp);
		SoPhuc operator - (const SoPhuc& sp);
		SoPhuc operator * (const SoPhuc& sp);
		SoPhuc operator / (const SoPhuc& sp);
		double modun() const;
};

SoPhuc::~SoPhuc()
{
	phanThuc = 0;
	phanAo = 0;
}

istream& operator>>(istream& is, SoPhuc& sp)
{
	cout << "Nhap phan thuc: ";
	is >> sp.phanThuc;
	cout << "Nhap phan ao: ";
	is >> sp.phanAo;
	return is;
}

ostream& operator<<(ostream& os, const SoPhuc& sp)
{
	if(sp.phanThuc >= 0)
		os << sp.phanThuc << " + " << sp.phanAo << "i" << endl;
	else
		os << sp.phanThuc << " - " << abs(sp.phanAo) << "i" << endl;
	return os;
}

SoPhuc SoPhuc::operator +(const SoPhuc& sp)
{
	return SoPhuc(phanThuc + sp.phanThuc, phanAo + sp.phanAo);
}

SoPhuc SoPhuc::operator -(const SoPhuc& sp)
{
	return SoPhuc(phanThuc - sp.phanThuc, phanAo - sp.phanAo);
}

SoPhuc SoPhuc::operator *(const SoPhuc& sp)
{
	return SoPhuc(phanThuc*sp.phanThuc - phanAo*sp.phanAo, phanThuc*sp.phanAo + phanAo*sp.phanThuc);
}

SoPhuc SoPhuc::operator /(const SoPhuc& sp)
{
	float mauSp = sp.phanThuc*sp.phanThuc + sp.phanAo*sp.phanAo;
	return SoPhuc((phanThuc*sp.phanThuc + phanAo*sp.phanAo) / mauSp, 
	(phanThuc*sp.phanAo - phanAo*sp.phanThuc) / mauSp);
}
double SoPhuc::modun()const
{
	return sqrt(phanThuc * phanThuc + phanAo * phanAo);
}

int main()
{
	int n;
	cout << "Nhap so luong so phuc: ";
	cin >> n;
	
	//SoPhuc *sp = new SoPhuc[n]; // cap phat dong 

	SoPhuc sp[100];
	for(int i = 0; i < n; i++){
		cout << "\nNhap so phuc thu " << i+1 << ":" << endl;
		cin >> sp[i];
	}
	
	int modunmax = 0;
	for(int i = 0; i < n; i++){
		if(sp[i].modun() > sp[modunmax].modun()){
			modunmax = i;
		}
	}
	
	if(n >= 2){
		SoPhuc tong = sp[0] + sp[1];
		cout << "\nTong cua so phuc thu 1 va so phuc thu 2 la: ";
		cout << tong << endl;
	}else{
		cout << "Khong co du hai so phuc de tinh tong!";
	}
	
	if(n >= 2){
		SoPhuc hieu = sp[0] - sp[1];
		cout << "Hieu cua so phuc thu 1 va so phuc thu 2 la: ";
		cout << hieu << endl;
	}else{
		cout << "Khong co du hai so phuc de tinh tong!";
	}
	
	if(n >= 2){
		SoPhuc tich = sp[0] * sp[1];
		cout << "Tich cua so phuc thu 1 va so phuc thu 2 la: ";
		cout << tich << endl;
	}else{
		cout << "Khong co du hai so phuc de tinh tong!";
	}
	
	if(n >= 2){
		SoPhuc thuong = sp[0] / sp[1];
		cout << "Thuong cua so phuc thu 1 va so phuc thu 2 la: ";
		cout << thuong << endl;
	}else{
		cout << "Khong co du hai so phuc de tinh tong!";
	}
	
	cout << "So phuc co modun lon nhat: ";
	cout << sp[modunmax];
	// delete[]sp; // dung cho cap phat dong
	
	return 0;
}
	
	

