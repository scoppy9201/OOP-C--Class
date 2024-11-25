/* Bài 1: Xây dung lop Diem có du lieu thành phan gom: toa do x, y. Các hàm thành phan bao gom:
- Hàm tao, hàm nhap du lieu, xuat du lieu, tính khoang cách 2 diem
Xây dung lop hình tam giác ke thua tu lop diem. Voi các hàm thành phân: nhap du lieu, xuât du lieu cua tam giác.
Kiêm tra xem 3 diêm nhap vào tao thành tam giác gì? Tính chu vi, dien tích tam giác theo công thuc Herong.
cv = a + b + c (a,b,c: do dài 3 canh)
s= Vp* (p -a) * (p - b) * (p - c) (p:nua chu vi)
Viet chuong trình nhap vào 1 danh sách tam giác, in lên màn hình tam giác gi? in ra tam giác nào có dien tich lon nhat */

#include <iostream>
#include <cmath>
using namespace std;
class Diem {
	protected:
		float x, y;
	public:
		Diem() : x(0), y(0) {}
		Diem(float x1, float y1) : x(x1), y(y1) {}
	// toan tu nhap lop Diem
	friend istream& operator>>(istream& is, Diem& diem){
		cout << "Nhap x: ";
		is >> diem.x;
		cout << "Nhap y: ";
		is >> diem.y;
		return is;
	}
	//Toan tu xuat
	friend ostream& operator<<(ostream& os, const Diem& diem){
		os << "( " << diem.x << ", " << diem.y << " )";
		return os;
	}
	// ham tinh khaong cach 2 diem
	float KC2D(const Diem& diem) const{
		return sqrt(pow(x-diem.x, 2) + pow(y-diem.y, 2));
	}
};

class Hinhtamgiac : public Diem {
	private: 
		Diem d1, d2, d3;
	public: 
		Hinhtamgiac(){}
		// toan tu nhap lop tam giac
		friend istream& operator>>(istream& is, Hinhtamgiac& tamgiac){
			cout << "Nhap diem thu nhat: " << endl;
			is >> tamgiac.d1;
			cout << "Nhap diem thu hai: " << endl;
			is >> tamgiac.d2;
			cout << "Nhap diem thu ba: " << endl;
			is >> tamgiac.d3;
			return is;
		}
		// toan tu xuat lop tam giac
		friend ostream& operator<<(ostream& os, Hinhtamgiac& tamgiac){
			os << "Tam giac voi cac dinh: " << tamgiac.d1 << "; " << tamgiac.d2 << ";  " << tamgiac.d3 << ", ";
			return os;
		}
		// tinh do dai cac canh
		float CanhA() const{return d1.KC2D(d2);}
		float CanhB() const{return d2.KC2D(d3);}
		float CanhC() const{return d1.KC2D(d3);}
		// in ra loai tam giac
		string loaitamgiac()const{
			float a = CanhA(), b = CanhB(), c = CanhC();
			if(a+b<=c || a+c<=b || b+c<=a)
				return "Khong la tam giac.";
			if(a==b && b==c)
				return "Tam giac deu.";
			if(a==b || b==c || c==a)
				return "Tam giac can.";
			if(pow(a,2) + pow(b,2) == pow(c,2) ||
			  pow(a,2) + pow(c,2) == pow(b,2) ||
			  pow(b,2) + pow(c,2) == pow(a,2))
			  return "Tam giac vuong.";
			return "Tam giac thuong.";
		}
		// chu vi tam giac 
		float Chuvi()const{
			return CanhA() + CanhB() + CanhC();
		}
		// dien tich tam giac
		float Dientich()const{
			float a = CanhA(), b = CanhB(), c = CanhC();
			float p = Chuvi() / 2;
			return sqrt(p*(p-a)*(p-b)*(p-c));
		}	
};

int main()
{
	int n;
	cout << "Nhap so luong tam giac: ";
	cin >> n;
	
	Hinhtamgiac* dsTG = new Hinhtamgiac[n];
	
	for(int i = 0 ;i < n; ++i){
		cout << "\nNhap tam giac thu: " << i+1 << endl;
		cin >> dsTG[i];
	}
	
	//xuat thong tin tam giac va tam giac lon nhat 
	float dientichmax = 0;
	int indexmax = -1; //  chi so tam giac lon nhat gan = -1 vi chua co tam giac nao 
	
	cout << "\nThong tin tam giac: \n";
	for(int i = 0; i < n; ++i){
		cout << "Tam giac thu: " << i+1 << ": ";
		cout << dsTG[i] << endl;
		string loai = dsTG[i].loaitamgiac();
		cout << "Loai: " << loai << endl;
		
		if(loai != "Khong la tam giac."){
			float dientich = dsTG[i].Dientich();
			cout << "Chu vi tam giac: " << dsTG[i].Chuvi() << endl;
			cout << "Dien tich tam giac: " << dientich;
			
			if(dientich > dientichmax){
				dientichmax = dientich;
				indexmax = i;
			}
		}else{
			cout << "Khong phai tam giac hop le.\n";
		}
		cout << endl;
	}
	
	// xuat tam giac co dien tich lon nhat
	if(indexmax != -1){
		cout << "Tam giac co dien tich lon nhat:\n";
		cout << dsTG[indexmax] << endl;
		cout << "Dien tich lon nhat: " << dientichmax << endl;
	}else{
		cout << "Khong co tam giac hop le.\n";
	}
	
	delete[] dsTG;
	return 0;
}
