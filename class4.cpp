#include <iostream>
#include <string>
#include <algorithm>
#include <iomanip> // su dung setprecision - fixed
using namespace std;
class SinhVien{
	private:
		string Hoten;
		string Masv;
		float diemToan;
		float diemLy;
		float diemHoa;
		float diemTB;
	public:
		SinhVien(){
			Hoten = "";
			Masv = "";
			diemToan = diemLy = diemHoa = diemTB = 0.0;
		}
		SinhVien(string hoten, string masv, float diemtoan, float diemly, float diemhoa){
			Hoten = hoten;
			Masv = masv;
			diemToan = diemtoan;
			diemLy = diemly;
			diemHoa = diemhoa;
			diemTB = (diemToan + diemLy + diemHoa) / 3.0;
		}
		
		friend istream& operator>>(istream& is, SinhVien& sv);
		friend ostream& operator<<(ostream& os, const SinhVien& sv);
		
		float tinhdiemTB();
		float quydiemtbHe4()const;
		string gethoten() const;
		bool operator<(const SinhVien& sv ) const;
};

istream& operator>>(istream& is, SinhVien& sv)
{
	cout << "Nhap ho ten sinh vien: ";
	is.ignore();
	getline(is, sv.Hoten);
	cout << "Nhap ma sinh vien: ";
	getline(is, sv.Masv);
	cout << "Nhap diem toan: ";
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
	return os;
}

// phuong thuc tinh diem trung binh 
float SinhVien::tinhdiemTB(){
	diemTB = (diemToan + diemHoa + diemLy) / 3.0;
	return diemTB;
}

// phuong thuc quy doi diem trne thang diem 4
float SinhVien::quydiemtbHe4()const{
	if(diemTB >= 8.5) return 4.0;
	else if(diemTB >= 8.0) return 3.5;
	else if(diemTB >= 7.0) return 3.0;
	else if(diemTB >= 6.0) return 2.5;
	else if(diemTB >= 5.5) return 2.0;
	else if(diemTB >= 5.0) return 1.5;
	else if(diemTB >= 4.0) return 1.0;
	else return 0.0;
}

// lay ho ten sinh vien de sap xep
string SinhVien::gethoten() const{
	return Hoten;
}

// ham so sanh dung de sap xep sinh vien theo ho ten 
bool SinhVien::operator<(const SinhVien& sv) const{
	return Hoten < sv.Hoten;
}

int main(){
	int n;
	cout << "Nhap so luong sinh vien: ";
	cin >> n;
	
	SinhVien sv[100]; // khai bao mang 1 chieu gom 100 phan tu 
	
	// nhap thong tin cho cac sinh vien 
	for(int i = 0; i < n; i++){
		cout << "\nNhap thong tin cho sinh vien " << i + 1 << ":" << endl;
		cin >> sv[i];
	}
	
	// sap xep danh sach sinh vien theo ho ten
	sort (sv, sv+n);
	
	// in ra thong tin
	cout << "\nDanh sach nhan vien sau khi sap xep: " << endl;
	for(int i = 0; i < n; i++){
		cout << sv[i];
		cout << endl;
	}
	return 0;
}
