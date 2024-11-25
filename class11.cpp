/* Bài 1: Xây dung lop thoi gian gian Time. Du lieu thanh phan gom: gio, phút, giây. Các hàm thành phan bao gom:
 - Hàm tao, hàm nhap du lieu, xuat du lieu
 - Hàm normalize() de chuan hoa du lieu nam trong khoang quy dinh cua gio (0 <= gio <= 24) , phút (0 <= phút < 60), giây (0 <= giây < 60)
 - hàm advance(int h, int m, int s) de tang thoi gian hien hành cua doi tuong dang ton tai 
 - Nhap vao mot thoi gian bat ky. In thoi gian dó lên màn hình */
 
#include <iostream>
#include <iomanip>
using namespace std;
class Time {
	private:
		int gio, phut, giay;
	public:
		Time() : gio(0), phut(0), giay(0){}
		Time(int h, int m, int s) : gio(h), phut(m), giay(s){
			normalize();
		}
		friend istream& operator>>(istream& is, Time& t);
		friend ostream& operator<<(ostream& os, const Time& t);
		
		void normalize();
		void advance(int h, int n, int s);
};


istream& operator>>(istream& is, Time& t)
{
	cout << "Nhap gio: ";
	is >> t.gio;
	cout << "Nhap phut: ";
	is >> t.phut;
	cout << "Nhap giay: ";
	is >> t.giay;
	t.normalize();
	return is;
}
ostream& operator<<(ostream& os, const Time& t)
{
	os << setw(2) << setfill('0') << t.gio << ":"
	   << setw(2) << setfill('0') << t.phut << ":"
	   << setw(2) << setfill('0') << t.giay;
	return os;
}

void Time::normalize()
{
	if(giay >= 60){
		phut += giay / 60;
		giay %= 60;
	}
	if(phut >= 60){
		gio += phut / 60;
		phut %= 60;
	}
	gio %= 24;
}

void Time::advance(int h, int m , int s)
{
	gio += h;
	phut += m;
	giay += s;
	normalize();
}

int main()
{
	Time t;
	cout << "Nhap vao thoi gian bat ky: " << endl;
	cin >> t;
	
	cout << "Thoi gian vua nhap la: " << t << endl;
	
	int h, m, s;
	cout << "\nNhap thoi gian can tang (gio, phut, giay):\n";
	cout << "Nhap gio: ";
	cin >> h;
	cout << "Nhap phut: ";
	cin >> m;
	cout << "Nhap giay: ";
	cin >> s;
	t.advance(h, m, s);
	
	cout << "\nThoi gian sau khi tang: " << t << endl;
	return 0;
}


