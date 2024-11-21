#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

class TamGiac {
private:
    double a, b, c;

public:
    TamGiac() : a(0), b(0), c(0) {}

    TamGiac(double canha, double canhb, double canhc) : a(canha), b(canhb), c(canhc) {}

    ~TamGiac();

    friend istream& operator>>(istream& is, TamGiac& tg);
    friend ostream& operator<<(ostream& os, const TamGiac& tg);
    bool laTamGiac() const;
    double chuVi() const;
    double dienTich() const;
    bool operator<(const TamGiac& tamgiac) const;
};

TamGiac::~TamGiac()
{
	a = 0;
	b = 0;
	c = 0;
}

istream& operator>>(istream& is, TamGiac& tg)
{
    do {
        cout << "Nhap do dai canh a: ";
        is >> tg.a;
        cout << "Nhap do dai canh b: ";
        is >> tg.b;
        cout << "Nhap do dai canh c: ";
        is >> tg.c;
        if (!tg.laTamGiac()) {
            cout << "Ba canh khong tao thanh 1 tam giac. Vui long nhap lai\n";
        }
    } while (!tg.laTamGiac());
    return is;
}

ostream& operator<<(ostream& os, const TamGiac& tg)
{
    os << "Canh a: " << tg.a << endl;
	os << "Canh b: " << tg.b << endl; 
	os << "Canh c: " << tg.c << endl;
    os << "Chu vi: " << tg.chuVi() << endl;
	os << "Dien tích: " << tg.dienTich() << endl;
	return os;
}

bool TamGiac::laTamGiac() const {
    return (a + b > c) && (a + c > b) && (b + c > a);
}

double TamGiac::chuVi() const {
    return a + b + c;
}

double TamGiac::dienTich() const {
    double p = chuVi() / 2;
    return sqrt(p * (p - a) * (p - b) * (p - c)); 
}

bool TamGiac::operator<(const TamGiac& tamgiac) const {
    return dienTich() < tamgiac.dienTich();
}

int main() {
    int n;
    cout << "Nhap so luong tam giac: ";
    cin >> n;

    TamGiac dsTG[100]; 

    for (int i = 0; i < n; i++) {
        cout << "Tam giac thu " << i + 1 << ":\n";
        cin >> dsTG[i];
    }

    sort(dsTG, dsTG+n);

    cout << "\nDanh sách tam giác sau khi sap xep theo dien tich tang dan:\n";
    for (int i = 0; i < n; i++) {
        cout << "Tam giác thu " << i + 1 << ":\n";
       	cout << dsTG[i];
    }
    return 0;
}

