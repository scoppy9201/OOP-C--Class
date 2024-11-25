/* Ðinh nghia lop Diem có:
Các thuoc tính x,y
Hai hàm tao
Phuong thuc nhap, xuat
+ Xây dung lop Hinhtron dan xuat tu lop Diem, dua thêm:
Thuoc tính r
Hai hàm tao
Phuong thuc nhap, xuat hình tròn
Phuong thuc tính chu vi, dien tích hình tròn. */
#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
class Diem {
	protected: 
		float x, y;
	public: 
		Diem() : x(0), y(0) {}
		Diem(float x1, float y1) : x(x1), y(y1) {}
		friend istream& operator>>(istream& is, Diem& diem)
		{
			cout << "Nhap x: ";
			is >> diem.x;
			cout << "Nhap y: ";
			is >> diem.y;
			return is;
		}
		friend ostream& operator<<(ostream& os, const Diem& diem)
		{
			os << "( " << diem.x << ", " << diem.y << " )";
			return os;
		}
};

class Hinhtron : public Diem {
	private: 
		float r;
	public:
		Hinhtron() : Diem(), r(0) {}
		Hinhtron(float x1, float y1, float r1) : Diem(x1, y1), r(r1){}
		friend istream& operator>>(istream& is, Hinhtron& ht)
		{
			cout << "Nhap toa do tam hinh tron: " << endl;
			is >> static_cast<Diem&>(ht); // goi toan tu nhap ua lop diem
			cout << "Nhap ban kinh hinh tron: ";
			is >> ht.r;
			return is;
		}
		friend ostream& operator<<(ostream& os, const Hinhtron& ht)
		{
			os << "Tam hinh tron: " << static_cast<const Diem&>(ht) << endl;
			os << "Ban kinh hinh tron: " << ht.r;
			return os;
		}
		
		float tinhchuvi() const
		{
			return 2*M_PI*r;
		}
		
		float tinhdientich() const
		{
			return M_PI*pow(r, 2); // pow la binh phuong 
		}
};

int main()
{
	Hinhtron ht;
	cout << "Nhap thong tin hinh tron: " << endl;
	cin >> ht;
	
	cout << "\nThong tin hinh tron vua nhap:\n";
	cout << ht << endl;
	cout << fixed << setprecision(2)  << "Chu vi hinh tron: " << ht.tinhchuvi() << endl;
	cout << "Dien tich hinh tron: " << ht.tinhdientich() << endl;
	
	return 0;
}
