#include <iostream>
#include <cstring> // su dung strcpy,strcmp, strlen
#include <algorithm>
#include <iomanip>
using namespace std;
class SinhVien{
	private:
		char Hoten[50];
		char Masv[20];
		float diemToan;
		float diemLy;
		float diemHoa;
		float diemTB;
	
	public:
		SinhVien(){
			strcpy(Hoten, "");
			strcpy(Masv, "");
			diemTB = diemToan = diemLy = diemHoa = 0.0;
		}
		
		SinhVien(const char hoten[], const char masv[], float diemtoan, float diemly, float diemhoa){
			strcpy(Hoten, hoten);
			strcpy(Masv, masv);
			diemToan = diemtoan;
			diemLy = diemly;
			diemHoa = diemhoa;
			diemTB = (diemToan + diemLy + diemHoa) / 3.0;
		}
		friend istream& operator>>(istream& is, SinhVien& sv);
		friend ostream& operator<<(ostream& os, const SinhVien& sv);
		float tinhdiemTB();
		float quydiemtbHe4()const;
		const char* gethoten() const;
		bool operator<(const SinhVien& other) const;
};

istream& operator>>(istream& is, SinhVien& sv)
{
	cout << "Nhap ho ten sinh vien: ";
	is.ignore();
	is.getline(sv.Hoten, 50);
	cout << "Nhap ma sinh vien: ";
	is.getline(sv.Masv, 20);
	cout << "Mhap diem toan: ";
	is >> sv.diemToan;
	cout << "Nhap diem ly: ";
	is >> sv.diemLy;
	cout << "Nhap diem hoa: ";
	is >> sv.diemHoa;
	sv.diemTB = sv.tinhdiemTB();
	return is;
}

ostream& operator<<(ostream& os, const SinhVien& sv)
{
	os << "Ho ten sinh vien: " << sv.Hoten << endl;
	os << "Ma sinh vien: " << sv.Masv << endl;
	os << "Diem toan: " << sv.diemToan << endl;
	os << "Diem ly: " << sv.diemLy << endl;
	os << "Diem hoa: " << sv.diemHoa << endl;
	os << "Diem trung binh: " << sv.diemTB << endl;
	os << "Diem trung binh (He 4): " << sv.quydiemtbHe4() << endl;
}

float SinhVien::tinhdiemTB()
{
	diemTB = (diemToan + diemLy + diemHoa) / 3.0;
	return diemTB;
}

float SinhVien::quydiemtbHe4()const 
{
	if(diemTB >= 8.5) return 4.0;
	else if(diemTB >= 8.0) return 3.5;
	else if(diemTB >= 7.0) return 3.0;
	else if(diemTB >= 6.0) return 2.5;
	else if(diemTB >= 5.5) return 2.0;
	else if(diemTB >= 5.0) return 1.5;
	else if(diemTB >= 4.0) return 1.0;
	else return 0.0;
}

const char* SinhVien::gethoten() const 
{
	return Hoten;
}

bool SinhVien::operator<(const SinhVien& sv) const 
{
	return strcmp(Hoten, sv.Hoten) < 0;
}

int main()
{
	int n;
	
	cout << "Nhap so luong sinh vien: ";
	cin >> n;
	
	SinhVien sv[100];
	
	for(int i = 0; i < n; i++){
		cout << "\nNhap thong tin cho sinh vien: " << i+1 << ":"<< endl;
		cin >> sv[i];
	}
	
	sort(sv, sv+n);
	
	cout << "\nDanh sach thong tin sinh vien sau khi sap xep: " << endl;
	for(int i = 0; i < n; i++){
		cout << sv[i];
		cout << endl;
	}
	
	return 0;
}
