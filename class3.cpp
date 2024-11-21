#include <iostream>
using namespace std;
class DaThuc {
	private: 
		int bac;
		int heSo[10]; // gia su bac toi da la 10 
	public: 
		// khai bao mac dinh - ham tao khong tham so 
		DaThuc(){
			bac = 0;
			for(int i = 0; i < 10; i++){
				heSo[i] = 0;
		}
	}
		// khai bao chua tham so - ham tao co tham so 
		DaThuc (int b, int heso[]){
			bac = b;
			for(int i = 0; i <= bac; i++){
				heSo[i] = heso[i];
			}
			for(int i = bac + 1; i < 10; i++){ // gan gia tri nhung he so con lai bang 0
				heSo[i] = 0;
		}
	}
		
		// ham huy - dua gia tri bac va he so ve 0
		~DaThuc(){
			bac = 0;
			for(int i = 0; i < 10; i++){
				heSo[i] = 0;
		}
	}
		void nhap();
		void xuat();
		DaThuc cong(DaThuc b);
		DaThuc tru(DaThuc b);
};

// phuong thuc nhap 
void DaThuc::nhap(){
	cout << "Nhap bac cua da thuc: ";
	cin >> bac;
	for(int i = bac; i >= 0; i--){
		cout << "Nhap he so bac " << i << ": "<< endl;
		cin >> heSo[i];
	}
}

// phuong thuc xuat 
void DaThuc::xuat(){
	for(int i = bac; i >= 0; i--){
		if(heSo[i] != 0){
			if(i < bac && heSo[i] > 0) cout << "+";
			cout << heSo[i];
			if(i > 0) cout << "x^" << i;
		}
	}
	cout << endl;
}

// phuong thuc cong 
DaThuc DaThuc::cong(DaThuc b){
	DaThuc ketqua;
	ketqua.bac = max(bac, b.bac);
	for(int i = 0; i <= ketqua.bac; i++){
		ketqua.heSo[i] = heSo[i] + b.heSo[i];
	}
	return ketqua;
}

// phuong thuc tru 
DaThuc DaThuc::tru(DaThuc b){
	DaThuc ketqua;
	ketqua.bac = max(bac, b.bac);
	for(int i = 0; i <= ketqua.bac; i++){
		ketqua.heSo[i] = heSo[i] - b.heSo[i];
	}
	return ketqua;
}

int main()
{
	int bac1, bac2;
	cout << "Nhap bac cua da thuc thu nhat: ";
	cin >> bac1;
	int heSo1[bac1+1];
	for(int i = bac1; i >= 0; i--){
		cout << "Nhap he so bac" << i << ":";
		cin >> heSo1[i];
	}
	
	cout << "Nhap bac cua da thuc thu hai: ";
	cin >> bac2;
	int heSo2[bac2+1];
	for(int i = bac2; i >= 0; i--){
		cout << "Nhap he so bac" << i << ":";
		cin >>heSo2[i];
	}
	
	DaThuc dt1(bac1, heSo1);
	DaThuc dt2(bac2, heSo2);
	
	cout << "\nDa thuc thu nhat: ";
	dt1.xuat();
	cout << "Da thuc thu hai: ";
	dt2.xuat();
	
	DaThuc tong = dt1.cong(dt2);
	cout << "\nTong hai da thuc = ";
	tong.xuat();
	DaThuc hieu = dt1.tru(dt2);
	cout << "Hieu hai da thuc = ";
	hieu.xuat();
	
	return 0;
}
		
		
		
		
			
			
