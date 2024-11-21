#include <iostream>
#include <cmath>
using namespace std;

class diem {
	private:
		int x, y; // toa do cua diem
	public:
		void nhapdiem();
		void indiem() const;
		float KC2D(diem d2 ) const;
	};

// dinh nghia phuong thuc nhap diem 
void diem::nhapdiem(){
	cout << "Nhap x = ";
	cin >> x;
	cout << "Nhap y = ";
	cin >> y;
}

// dinh nghia phuong thuc in diem 
void diem::indiem() const{
	cout <<"( " << x << ", " << y << " )" << endl;
}

// dinh nghia phuong thuc tinh khoang cách hai diem 
float diem::KC2D(diem d2) const{
	return sqrt((x-d2.x) * (x-d2.x) + (y-d2.y) * (y-d2.y));
}

// ham kiem tra 3 cach có tao thanh 1 tam giac 
bool tamgiac (float a, float b, float c ){
	return (a+b>c) && (a+c>b) && (b+c>a);
}

// ham xác dinh loai tam giac 
string loaitamgiac(float a, float b, float c){
	if(a == b && b == c)
		return "Tam giac deu.";
	else if(a == b || b == c || c == a)
		return "Tam giac can.";
	else if(a*a == b*b + c*c || b*b == a*a + c*c || c*c == a*a + b*b)
		return "Tam giac vuong.";
	else
		return "Tam giac thuong.";
}

// ham tinh chu vi tam giac
float chuvi(float a, float b, float c){
	return (a + b + c);
}

// ham tinh dien tich tam giac 
float dientich (float a, float b, float c){
	float p = chuvi(a, b, c) / 2;
	return sqrt(p*(p-a)*(p-b)*(p-c));
}

int main()
{
	diem d1, d2, d3;
	
	cout << "Nhap toa do diem thu nhat\n";
	d1.nhapdiem();
	cout << "Nhap toa do diem thu hai\n";
	d2.nhapdiem();
	cout << "Nhap toa do diem thu ba\n";
	d3.nhapdiem();
	
	cout << "Toa do diem thu nhat la: " << endl;
	d1.indiem();
	cout << "Toa do iem tu hai la: " << endl;
	d2.indiem();
	cout << "Toa do diem thu ba la: " << endl;
	d3.indiem();
	
	float a = d1.KC2D(d2);
	float b = d2.KC2D(d3);
	float c = d1.KC2D(d3);
	
	cout << "Khoang cach giua diem d1 va d2 la: " << a <<  endl;
	cout << "Khoang cach giua diem d2 va d3 la: " << b << endl;
	cout << "Khoang cach giua diem d1 va d3 la: " << c << endl;
	
	if(tamgiac(a, b, c)){
		cout << "\mBa diem tao thanh mot tam giac:\n";
		cout << "Loai tma giac: " << loaitamgiac(a, b, c) << endl;
		
		cout << "Chu vi tam giac: " << chuvi(a, b, c) << endl;
		cout << "Dien tich tam giac " << dientich(a, b, c) << endl;
	}else{
		cout << "\nBa diem khong tao thanh mot tam giac\n";
	}
	return 0;
}
