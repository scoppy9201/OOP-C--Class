#include <iostream>
#include <cstring>
using namespace std;
class Matrix {
	private:
		char name[20]; // ten ma tran
		int size; // bac ma tran
		int matran[10][10]; // matran, bac toi da cua ma tran la 20
	public:
		Matrix(const char* matrixName = "", int matrixSize = 0){
			strcpy(name, matrixName);
			name[19] = '\0';
			size = matrixSize;
			
			// gan tat ca cac phan tu bang 0
			for(int i =  0; i < 10; i++){
				for(int j  = 0; j < 10; j++){
					matran[i][j] = 0;
				}
			}
		}
		
		~Matrix();
		friend istream& operator>>(istream& is, Matrix& mt);
		friend ostream& operator<<(ostream& os, const Matrix& mt);
		Matrix operator+(const Matrix& mt)const;
		Matrix operator-(const Matrix& mt)const;
		Matrix operator*(const Matrix& mt)const;
		Matrix operator/(const Matrix& mt)const;		
};

Matrix::~Matrix(){
	size = 0;
	strcpy (name, "");
	for(int i = 0; i < 10; i++){
		for(int j = 0; j < 10; j++){
			matran[i][j] = 0;
			}
		}
	}
	
istream& operator>>(istream& is, Matrix& mt)
{
	cout << "Nhap ten ma tran: ";
	is >> mt.name;
	cout << "Nhap bac cua ma tran: ";
	is >> mt.size;
	if(mt.size > 10){
		cout << "Bac ma tran vuot qua gioi han. Se duoc dat ve 10.\n";
		mt.size = 10;
	}
	cout << "Nhap cac phan tu cua ma tran:\n";
	for(int i = 0; i < mt.size; i++){
		for(int j = 0; j < mt.size; j++){
			cout << "Phan tu [" << i+1 << "][" << j+1 << "]:";
			is >> mt.matran[i][j];
		}
	}
	return is;
}
		
ostream& operator<<(ostream& os, const Matrix& mt)
{
	os << "Ten ma tran: " << mt.name << endl;
	os << "Bac cua ma tran: " << mt.size << endl;
	os << "Cac phan tu cua ma tran:\n";
	for(int i = 0; i < mt.size; i++){
		for(int j = 0; j < mt.size; j++){
			os << mt.matran[i][j] << " ";
		}
		os << endl;
	}
	return os;
}
Matrix Matrix::operator+(const Matrix& mt)const
{
	Matrix cong("Tong", size);
	for(int i = 0; i < size; i++){
		for(int j = 0; j < size; j++){
			cong.matran[i][j] = matran[i][j] + mt.matran[i][j];
		}
	}
	return cong;
}
	
Matrix Matrix::operator-(const Matrix& mt)const
{
	Matrix tru("Tru", size);
	for(int i =  0; i < size; i++){
		for(int j = 0; j < size; j++){
			tru.matran[i][j] = matran[i][j] - mt.matran[i][j];
		}
	}
	return tru;
}

Matrix Matrix::operator*(const Matrix& mt)const
{
	Matrix nhan("Tich", size);
	for(int i = 0; i < size; i++){
		for(int j = 0; j < size; j++){
			nhan.matran[i][j] = 0;
			for(int k = 0; k < size; k++){
				nhan.matran[i][j] += matran[i][k] * mt.matran[k][j];
			}
		}
	}
	return nhan;
}
Matrix Matrix::operator/(const Matrix& mt)const
{
	Matrix chia("Chia", size);
	for(int i = 0; i < size; i++){
		for(int j = 0; j < size; j++){
			if(mt.matran[i][j] != 0){
				chia.matran[i][j] = matran[i][j] / mt.matran[i][j];
			}else{
				chia.matran[i][j] = 0;
			}
		}
	}
	return chia;
}

int main()
{
	Matrix A, B;
	cout << "Nhap ma tran A: " << endl;
	cin >> A;
	cout << "Nhap ma tran B: " << endl;
	cin >> B;
	
	cout << "\nMa tran A: \n" << A;
	cout << "\nMa tran B: \n" << B;
	
	cout << "\nTong hai ma tran:\n" << (A+B) << endl;
	cout << "Hieu hai ma tran:\n" << (A-B) << endl;
	cout << "Tich hai ma tran:\n" << (A*B) << endl;
	cout << "Thuong hai ma tran:\n" << (A/B) << endl;
	
	return 0;
}

