/* Bài 2. Xây dung lop mang mot chieu gom n so nguyên. Du lieu thanh phan gom:ten mang, so phan tu trong mang.  Các hàm thành phan gom:
 - Hàm tao, ham huy
 - Nap chong toan tu nhap, xuat mang;
 - Hàm tính tong cac phan tu chan trong mang
 - Ham tinh tong cac phan tu le trong mang 
 - Hàm in phan tu co gia tri lon nhat lên màn hình
 - Hàm sap xep mang theo chieu tang dan 
Viet CT nhap vao mot mang gom n so nguyên. In tong cac phan tu chan, phan tu le, phan tu có GTLN, mang sau khi sap xep lên màn hình */
#include <iostream>
#include <algorithm> // su dung sort de sap xep 
using namespace std;
class MangSoNguyen {
	private:
		string TenMang;
		int* mang; // con tro mang cho mang dong 
		int phantu;
	public: 
		MangSoNguyen() : TenMang(""), mang(NULL), phantu(0){}
		MangSoNguyen(string ten, int n) : TenMang(ten), phantu(n){
			if(phantu > 0){
				mang  = new int[phantu]; // cap phat bo nho cho mang
			}else{
				mang = NULL;
			}
		}
		
		~MangSoNguyen();
		friend istream& operator>>(istream& is, MangSoNguyen& msn);
		friend ostream& operator<<(ostream& os, const MangSoNguyen& msn);
		int tongphantuChan()const;
		int tongphantuLe()const;
		void inphantumax()const;
		void sapxepmang();
		bool operator<(const MangSoNguyen& msn) const;
};

MangSoNguyen::~MangSoNguyen()
{
	delete[] mang;
}

istream& operator>>(istream& is, MangSoNguyen& msn)
{
	cout << "Nhap ten mang: ";
	getline(is, msn.TenMang);
	cout << "Nhap so luong phan tu: ";
	is >> msn.phantu;
	
	msn.mang = new int[msn.phantu]; // cap phat lai bo nho
	cout << "Nhap " << msn.phantu << " phan tu cho mang: " << endl;
	for(int i = 0; i < msn.phantu; ++i){
		cout << "Nhap phan tu thu " << i+1;
		is >> msn.mang[i];
	}
	return is;
}
ostream& operator<<(ostream& os, const MangSoNguyen& msn)
{
	os << "Ten mang: " << msn.TenMang << endl;
	os << "Mang: ";
	for(int i = 0; i < msn.phantu; ++i){
		os << msn.mang[i] << " ";
	}
	os << endl;
	return os;
}

int MangSoNguyen::tongphantuChan() const
{
	int tongChan = 0;
	for(int i = 0 ;i < phantu; ++i){
		if(mang[i] % 2 == 0){
			tongChan += mang[i];
		}
	}
	return tongChan;
}

int MangSoNguyen::tongphantuLe() const 
{
	int tongLe = 0;
	for(int i = 0; i < phantu; ++i){
		if(mang[i] % 2 != 0){
			tongLe += mang[i];
		}
	}
	return tongLe;
}
 
void MangSoNguyen::inphantumax()const
{
	if(phantu == 0){
		cout << "Mang rong, khong co phan tu." << endl;
		return;
	}
	int max = mang[0];
	for(int i = 1; i < phantu; ++i){
		if(mang[i] > max){
			max = mang[i];
		}
	}
	cout << "Phan tu lon nhat: " << max << endl;
}

void MangSoNguyen::sapxepmang()const
{
	if(phantu > 1){
		sort(mang, mang + phantu);
	}
}

bool MangSoNguyen::operator<(const MangSoNguyen& msn) const
{
	return mang[0] < msn.mang[0];
}

int main()
{
	MangSoNguyen msn;
	
	cin >> msn;
	cout << msn;
	
	cout << "Tong cac phan tu chan: " << msn.tongphantuChan() << endl;
	cout << "Tong cac phan tu le: " << msn.tongphantuLe() << endl;
	
	msn.inphantumax();
	
	msn.sapxepmang();
	cout << "Mang sau khi sap xep: " << endl;
	cout << msn;
	
	return 0;
}

