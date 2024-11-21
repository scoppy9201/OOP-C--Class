#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;
class SinhVien{
	private:
		char HoTen[50];
		int NamSinh;
		double diemMon1;
		double diemMon2;
		double diemMon3;
		double diemMon4;
		double diemMon5;
	public:
		SinhVien(){
			strcpy(HoTen, "");
			NamSinh = 0;
			diemMon1 = diemMon2 = diemMon3 = diemMon4 = diemMon5 = diemMon5 = 0.0;
		}
		SinhVien(const char* hoten, int namsinh, double diem1, double diem2, double diem3, double diem4, double diem5){
			strcpy(HoTen, hoten);
			NamSinh = namsinh;
			diemMon1 = diem1;
			diemMon2 = diem2;
			diemMon3 = diem3;
			diemMon4 = diem4;
			diemMon5 = diem5;
		}
		~SinhVien();
		// void Nhap();
		friend istream& operator>>(istream& is, SinhVien& sv);
		// void Xuat()const;
		friend ostream& operator<<(ostream& os, const SinhVien& sv);
		double tinhDiemTrungBinh()const;
		bool kiemTraMonThiLai()const;
		void inDanhSachThiLai()const;
		bool duocThiTotNgiep()const;
		bool duocLamDoAnTotNghiep()const;
		void quyDoiDiem()const;
};

SinhVien::~SinhVien()
{
	strcpy(HoTen, "");
	NamSinh = 0;
	diemMon1 = diemMon2 = diemMon3 = diemMon4 = diemMon5= 0;
}


/* void SinhVien::Nhap(){
	cout << "Nhap ten sinh vien: ";
	cin.ignore();
	cin.getline(HoTen, 50);
	cout << "Nhap nam sinh: ";
	cin >> NamSinh;
	cout << "Nhap diem mon 1: ";
	cin >> diemMon1;
	cout << "Nhap diem mon 2: ";
	cin >> diemMon2;
	cout << "Nhap diem mon 3: ";
	cin >> diemMon3;
	cout << "Nhap diem mon 4: ";
	cin >> diemMon4;
	cout << "Nhap diem mon 5: ";
	cin >> diemMon5;
} */
istream& operator>>(istream& is, SinhVien& sv)
{
	cout << "Nhap ten sinh vien: ";
	is.ignore();
	is.getline(sv.HoTen, 50);
	cout << "Nhap nam sinh: ";
	is >> sv.NamSinh;
	cout << "Nhap diem mon 1: ";
	is >> sv.diemMon1;
	cout << "Nhap diem mon 2: ";
	is >> sv.diemMon2;
	cout << "Nhap diem mon 3: ";
	is >> sv.diemMon3;
	cout << "Nhap diem mon 4: ";
	is >> sv.diemMon4;
	cout << "Nhap diem mon 5: ";
	is >> sv.diemMon5;
	return is;
}


/*void SinhVien::Xuat()const{
	cout << "Ho ten sinh vien: " << HoTen << endl;
	cout << "Nam sinh: " << NamSinh << endl;
	cout << fixed << setprecision(2) << "Diem mon 1: " << diemMon1 << endl;
	cout << fixed << setprecision(2) << "Diem mon 2: " << diemMon2 << endl;
	cout << fixed << setprecision(2) << "Diem mon 3: " << diemMon3 << endl;
	cout << fixed << setprecision(2) << "Diem mon 4: " << diemMon4 << endl;
	cout << fixed << setprecision(2) << "Diem mon 5: " << diemMon5 << endl;
	cout << "Diem trung binh: " << fixed << setprecision(2) << tinhDiemTrungBinh() << endl;
}*/
ostream& operator<<(ostream& os, const SinhVien& sv)
{
	os << "Ho ten sinh vien: " << sv.HoTen << endl;
	os << "Nam sinh: " << sv.NamSinh << endl;
	os << fixed << setprecision(2) << "Diem mon 1: " << sv.diemMon1 << endl;
	os << fixed << setprecision(2) << "Diem mon 2: " << sv.diemMon2 << endl;
	os << fixed << setprecision(2) << "Diem mon 3: " << sv.diemMon3 << endl;
	os << fixed << setprecision(2) << "Diem mon 4: " << sv.diemMon4 << endl;
	os << fixed << setprecision(2) << "Diem mon 5: " << sv.diemMon5 << endl;
	os << "Diem trung binh: " << fixed << setprecision(2) << sv.tinhDiemTrungBinh() << endl;
	return os;
}

double SinhVien::tinhDiemTrungBinh()const{
	return (diemMon1 + diemMon2 + diemMon3 + diemMon4 + diemMon5) / 5.0;
}

bool SinhVien::kiemTraMonThiLai()const{
	return (diemMon1 < 5 || diemMon2 < 5 || diemMon3 < 5 || diemMon4 < 5 || diemMon5 < 5);
}

void SinhVien::inDanhSachThiLai()const{
	bool hasThiLai = false;
    if (diemMon1 < 5) { cout << "Mon 1: " << diemMon1 << endl; hasThiLai = true; }
    if (diemMon2 < 5) { cout << "Mon 2: " << diemMon2 << endl; hasThiLai = true; }
    if (diemMon3 < 5) { cout << "Mon 3: " << diemMon3 << endl; hasThiLai = true; }
    if (diemMon4 < 5) { cout << "Mon 4: " << diemMon4 << endl; hasThiLai = true; }
    if (diemMon5 < 5) { cout << "Mon 5: " << diemMon5 << endl; hasThiLai = true; }
    if (!hasThiLai) {
        cout << "Sinh vien khong co mon thi lai." << endl;
    }
}

bool SinhVien::duocThiTotNgiep()const{
	if(tinhDiemTrungBinh() > 7){
		return (diemMon1 >= 5 && diemMon2 >= 5 && diemMon3 >= 5 && diemMon4 >= 5 && diemMon5 >= 5);
	}
	return false;
}

bool SinhVien::duocLamDoAnTotNghiep()const{
	if(tinhDiemTrungBinh() >= 7){
		return (diemMon1 >= 5 && diemMon2 >= 5 && diemMon3 >= 5 && diemMon4 >= 5 && diemMon5 >= 5);
	}
	return false;
}

void SinhVien::quyDoiDiem()const{
    double diemMon[] = {diemMon1, diemMon2, diemMon3, diemMon4, diemMon5};
    const char grades[] = {'A', 'B', 'C', 'D', 'F'};
    for (int i = 0; i < 5; i++) {
        cout << "Mon " << i+1 << ": ";
        if (diemMon[i] >= 8.5) cout << 'A' << endl;
        else if (diemMon[i] >= 7) cout << 'B' << endl;
        else if (diemMon[i] >= 5.5) cout << 'C' << endl;
        else if (diemMon[i] >= 4) cout << 'D' << endl;
        else cout << 'F' << endl;
    }
}

int main()
{
	int n;
	cout << "Nhap so luong sinh vien: ";
	cin >> n;
	
	SinhVien dsSV[100];
	
	for(int i = 0; i < n; i++){
		cout << "Nhap thong tin cho sinh vien thu: " << i+1 << endl;
		cin >> dsSV[i];
	}
	
	cout << "\nDanh sach sinh vien phai thi lai:\n";
    bool hasThiLai = false;
    for (int i = 0; i < n; i++) {
        if (dsSV[i].kiemTraMonThiLai()) {
            cout << dsSV[i];
            dsSV[i].inDanhSachThiLai();
            hasThiLai = true;
        }
    }
    if (!hasThiLai) cout << "Khong co sinh vien phai thi lai!" << endl;
	
	cout << "\nDanh sach sinh vien duoc thi tot nghiep:\n";
	for(int i = 0; i < n; i++){
		if(dsSV[i].duocThiTotNgiep()){
			cout << dsSV[i];
		}
	}
	
	cout << "\nDanh sach sinh vien du dieu kien lam do an tot nghiep:\n";
	for(int i = 0; i < n; i++){
		if(dsSV[i].duocLamDoAnTotNghiep()){
			cout << dsSV[i];
		}
	}
	
	cout << "\nQuy doi diem cac mon sang chu:\n";
    for (int i = 0; i < n; i++) {
        cout << "Sinh vien thu " << i + 1 << ":\n";
        dsSV[i].quyDoiDiem();
        cout << endl;
    }
    return 0;
}

