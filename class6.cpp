#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;
class ThiSinh {
	private:
		char MaThiSinh[20];
		char HoTen[50];
		float diemToan;
		float diemLy;
		float diemHoa;
	public:
		ThiSinh(): diemToan(0), diemLy(0), diemHoa(0) {
			strcpy(MaThiSinh, "");
			strcpy(HoTen, "");
		}
		ThiSinh(const char mathisinh[], const char hoten[], float diemtoan, float diemly, float diemhoa){
			strcpy(MaThiSinh, mathisinh);
			strcpy(HoTen, hoten);
			diemToan = diemtoan;
			diemLy = diemly;
			diemHoa = diemhoa;
		}
		~ThiSinh();
		friend istream& operator>>(istream& is, ThiSinh& ts);
		friend ostream& operator<<(ostream& os, const ThiSinh& ts);
		float tinhTongDiem()const;
		bool kiemTraDauVao()const;
};                          

ThiSinh::~ThiSinh(){
	strcpy(MaThiSinh, "");
	strcpy(HoTen, "");
	diemToan = 0;
	diemLy = 0;
	diemHoa = 0;
}

istream& operator>>(istream& is, ThiSinh& ts)
{
	cout << "Nhap ma thi sinh: ";
	is >> setw(20) >> ts.MaThiSinh;
	cout << "Nhap ho ten thi sinh: ";
	is.ignore();
	is.getline(ts.HoTen, 50);
	cout << "Nhap diem mon toan: ";
	is >> ts.diemToan;
	cout << "Nhap diem mon ly: ";
	is >> ts.diemLy;
	cout << "Nhap diem mon hoa: ";
	is >> ts.diemHoa;
	return is;
}

ostream& operator<<(ostream& os, const ThiSinh& ts)
{
	os << "Ma thi sinh: " << ts.MaThiSinh << endl;
	os << "Ho ten thi sinh: " << ts.HoTen << endl;
	os << "Diem mon toan: " << ts.diemToan << endl;
	os << "Diem mon ly: " << ts.diemLy << endl;
	os << "Diem mon hoa: " << ts.diemHoa << endl;
	return os;
}

float ThiSinh::tinhTongDiem()const
{
	return diemToan +  diemLy + diemHoa;
}

bool ThiSinh::kiemTraDauVao()const
{
	return tinhTongDiem() >= 21 && diemToan >= 2 && diemLy >= 2 && diemHoa >= 2;
}

int main()
{
	int n;
	cout << "Nhap so luong thi sinh: ";
	cin >> n;
	
	ThiSinh* thisinh = new ThiSinh[n];
	
	for(int i = 0; i < n; ++i){
		cout << "\nNhap thong tin thi sinh thu " << i+1 << ":" << endl;
		cin >> thisinh[i];
	}
	
	ThiSinh* thisinhmax = &thisinh[0];
	for(int i = 0; i < n; ++i){
		if(thisinh[i].tinhTongDiem()> thisinhmax->tinhTongDiem()){
			thisinhmax = &thisinh[i];
		}
	}
	
	cout << "\nThi sinh co tong diem cao nhat: " << endl;
	cout << *thisinhmax;
	
	cout << "\nDanh sach thi sinh thoa man dieu kien (tong diem >21 va khong mon nao duoi 2): " << endl;
	for(int i = 0; i < n; ++i){
		if(thisinh[i].kiemTraDauVao()){
			cout << thisinh[i];
		}
	}
	
	delete[] thisinh;
	return 0;
}
