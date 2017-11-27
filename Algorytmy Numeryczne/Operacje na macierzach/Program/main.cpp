//Mikolaj Bronk 234998

#include <iostream>
#include <vector>
#include <ctime>
#include <stdio.h>
#include <cstdlib>
#include <Eigen/Dense>
#include <iomanip>
#include <windows.h>


using namespace Eigen;
using namespace std;

double PCFreq = 0.0;
__int64 CounterStart = 0;
void StartCounter()
{
    LARGE_INTEGER li; 
     PCFreq = double(li.QuadPart)/1000000.0;
 
    QueryPerformanceCounter(&li);
    CounterStart = li.QuadPart;
}
double GetCounter()
{
    LARGE_INTEGER li;
    QueryPerformanceCounter(&li);
    return double(li.QuadPart-CounterStart)/PCFreq;
}


int fRand(int Max)
{
    int liczba = rand()%Max;
    if(liczba == 0) fRand(Max);
	else return liczba;
}


class Fraction {
    private:
    	
        long long gcd(long long a, long long b) {
            while (a != b) {
                if (a > b) {
                    a -= b;
                } else {
                    b -= a;
                }
            }
            return a;
        }
 
    public:
        long long numerator, denominator;
 
        Fraction() {
            numerator = 0;
            denominator = 1;
        }
 
        Fraction(long long n, long long d) {
            if (d==0) {              
                exit(0);
            } else if (n == 0) {
                numerator = 0;
                denominator = 1;
            } else {
                int sign = 1;
                if (n < 0) {
                    sign *= -1;
                    n *= -1;
                }
                if (d < 0) {
                    sign *= -1;
                    d *= -1;
                }
 
                long long tmp = gcd(n, d);
                numerator = n/tmp*sign;
                denominator = d/tmp;
            }
        }
 
        operator int() {return (numerator)/denominator;}
        operator float() {return ((float)numerator)/denominator;}
        operator double() {return ((double)numerator)/denominator;}
};
 
Fraction operator+(const Fraction& lhs, const Fraction& rhs) {
    Fraction tmp(lhs.numerator*rhs.denominator
                +rhs.numerator*lhs.denominator,
                lhs.denominator*rhs.denominator);
    return tmp;
}
 
Fraction operator+=(Fraction& lhs, const Fraction& rhs) {
    Fraction tmp(lhs.numerator*rhs.denominator
                +rhs.numerator*lhs.denominator,
                lhs.denominator*rhs.denominator);
    lhs = tmp;
    return lhs;
}
 
Fraction operator-(const Fraction& lhs, const Fraction& rhs) {
    Fraction tmp(lhs.numerator*rhs.denominator
                -rhs.numerator*lhs.denominator,
                lhs.denominator*rhs.denominator);
    return tmp;
}
 
Fraction operator-=(Fraction& lhs, const Fraction& rhs) {
    Fraction tmp(lhs.numerator*rhs.denominator
                -rhs.numerator*lhs.denominator,
                lhs.denominator*rhs.denominator);
    lhs = tmp;
    return lhs;
}
 
Fraction operator*(const Fraction& lhs, const Fraction& rhs) {
    Fraction tmp(lhs.numerator*rhs.numerator,
               lhs.denominator*rhs.denominator);
    return tmp;
}
 
Fraction operator*=(Fraction& lhs, const Fraction& rhs) {
    Fraction tmp(lhs.numerator*rhs.numerator,
               lhs.denominator*rhs.denominator);
    lhs = tmp;
    return lhs;
}
 
Fraction operator*(int lhs, const Fraction& rhs) {
    Fraction tmp(lhs*rhs.numerator,rhs.denominator);
    return tmp;
}
 
Fraction operator*(const Fraction& rhs, int lhs) {
    Fraction tmp(lhs*rhs.numerator,rhs.denominator);
    return tmp;
}

 
Fraction operator/(const Fraction& lhs, const Fraction& rhs) {
    Fraction tmp(lhs.numerator*rhs.denominator,
                 lhs.denominator*rhs.numerator);
    return tmp;
}
ostream& operator<<(std::ostream &strm, const Fraction &a) {
    if (a.denominator == 1) {
        strm << a.numerator;
    } else {
        strm << a.numerator << "/" << a.denominator;
    }
    return strm;
}
 
 Fraction s(0,1);

template <typename T> 

class MyMatrix {
 private:
  vector<vector<T> > matrix;
  unsigned rows;
  unsigned cols;

 T abs(T x) {
        return (x >= 0) ? x : -x;
    }



 public:
                                                                                                                                                 
MyMatrix(unsigned _rows, unsigned _cols, const T& _initial) {
  matrix.resize(_rows);
  for (unsigned i=0; i<matrix.size(); i++) {
    matrix[i].resize(_cols, _initial);
  }
  rows = _rows;
  cols = _cols;
}

MyMatrix(const MyMatrix<T>& rhs) {
  matrix = rhs.matrix;
  rows = rhs.get_rows();
  cols = rhs.get_cols();
}

                                                                                                                                               

virtual ~MyMatrix() {}
                                                                                                                                                    
MyMatrix<T>& operator=(const MyMatrix<T>& rhs) {
  if (&rhs == this)
    return *this;

  unsigned new_rows = rhs.get_rows();
  unsigned new_cols = rhs.get_cols();

  matrix.resize(new_rows);
  for (unsigned i=0; i<matrix.size(); i++) {
    matrix[i].resize(new_cols);
  }

  for (unsigned i=0; i<new_rows; i++) {
    for (unsigned j=0; j<new_cols; j++) {
      matrix[i][j] = rhs(i, j);
    }
  }
  rows = new_rows;
  cols = new_cols;

  return *this;
}

                                                                                                                                               

MyMatrix<T> operator+(const MyMatrix<T>& rhs) {
  MyMatrix result(rows, cols, s);

  for (unsigned i=0; i<rows; i++) {
    for (unsigned j=0; j<cols; j++) {
      result(i,j) = this->matrix[i][j] + rhs(i,j);
    }
  }

  return result;
}
                                                                                                                 

MyMatrix<T>& operator+=(const MyMatrix<T>& rhs) {
  unsigned rows = rhs.get_rows();
  unsigned cols = rhs.get_cols();

  for (unsigned i=0; i<rows; i++) {
    for (unsigned j=0; j<cols; j++) {
      this->matrix[i][j] += rhs(i,j);
    }
  }

  return *this;
}
                                                                                                                                  
MyMatrix<T> operator-(const MyMatrix<T>& rhs) {
  unsigned rows = rhs.get_rows();
  unsigned cols = rhs.get_cols();
  MyMatrix result(rows, cols, s);

  for (unsigned i=0; i<rows; i++) {
    for (unsigned j=0; j<cols; j++) {
      result(i,j) = this->matrix[i][j] - rhs(i,j);
    }
  }

  return result;
}
                                                                                                                     
MyMatrix<T>& operator-=(const MyMatrix<T>& rhs) {
  unsigned rows = rhs.get_rows();
  unsigned cols = rhs.get_cols();

  for (unsigned i=0; i<rows; i++) {
    for (unsigned j=0; j<cols; j++) {
      this->matrix[i][j] -= rhs(i,j);
    }
  }

  return *this;
}

                                                                                                                           
MyMatrix<T> operator*(const MyMatrix<T>& rhs) {
  unsigned rows = rhs.get_rows();
  unsigned cols = rhs.get_cols();  
  MyMatrix result(rows, cols, s);

  for (unsigned i=0; i<rows; i++) {
    for (unsigned j=0; j<cols; j++) {
      for (unsigned k=0; k<rows; k++) {
        result(i,j) += this->matrix[i][k] * rhs(k,j);
      }
    }
  }

  return result;
}

                                                                                                                
MyMatrix<T>& operator*=(const MyMatrix<T>& rhs) {
  MyMatrix result = (*this) * rhs;
  (*this) = result;
  return *this;
}

                                                                                                                                  
MyMatrix<T> transpose() {
  MyMatrix result(rows, cols, s);

  for (unsigned i=0; i<rows; i++) {
    for (unsigned j=0; j<cols; j++) {
      result(i,j) = this->matrix[j][i];
    }
  }

  return result;
}


// Macierz * wektor                                                                                                                                      


vector<T> operator*(const vector<T>& rhs) {
            vector<T> result(rhs.size(), s);
            for (unsigned i=0; i<rows; i++) {
                for (unsigned j=0; j<cols; j++) {
                    result[i] += this->matrix[i][j] * rhs[j];
                }
            }
            return result;
        }

                                                                                                                          

vector<T> diag_vec() {
  vector<T> result(rows, s);

  for (unsigned i=0; i<rows; i++) {
    result[i] = this->matrix[i][i];
  }

  return result;
}

                                                                                                                                            
T& operator()(const unsigned& row, const unsigned& col) {
  return this->matrix[row][col];
}
                                                                                                                                  

const T& operator()(const unsigned& row, const unsigned& col) const {
  return this->matrix[row][col];
}
 
unsigned get_rows() const {
  return this->rows;
}
 
unsigned get_cols() const {
  return this->cols;
}



 // metoda Gauss-Jordan pe³nego wyboru
        vector<T> Gauss_full() {
            int n = get_rows();
            for (int i = 0; i < n; i++) {
                // znajdŸ wiersz z maksymalnym elementem
                T maxEl = abs(matrix[i][i]);
                int maxRow = i;
                int maxCol = i;
                for (int k = i+1; k < n; k++) {
                    if (abs(matrix[k][i]) > maxEl) {
                        maxEl = abs(matrix[k][i]);
                        maxRow = k;
                        maxCol = i;
                    }
                }
                // zamieñ maksymalny wiersz z obecnym
                for (int k = i; k < n+1; k++) {
                    T pom = matrix[maxRow][k];
                    matrix[maxRow][k] = matrix[i][k];
                    matrix[i][k] = pom;
                }
                // zamien maksymalna kolumne z obecna
                for (int k = i; k < n; k++) {
                    T pom = matrix[k][maxCol];
                    matrix[k][maxCol] = matrix[k][i];
                    matrix[k][i] = pom;
                }
                
                // wyprowadŸ zera przed obecnym wierszem
                for (int k = i+1; k < n; k++) {
                    T c = -matrix[k][i] / matrix[i][i];
                    for (int j = i; j < n+1; j++) {
                        if (i == j) {
                            matrix[k][j] = 0;
                        } else {
                            matrix[k][j] += c * matrix[i][j];
                        }
                    }
                }
            }
            // rozwi¹¿ Ax = B za pomoc¹ powsta³ej macierzy trójk¹tnej
            vector<T> x(n);
            for (int i=n-1; i>=0; i--) {
                x[i] = matrix[i][n] / matrix[i][i];
                for (int k=i-1;k>=0; k--) {
                    matrix[k][n] -= matrix[k][i] * x[i];
                }
            }
            return x;
        }



   // metoda Gauss-Jordan po³owicznego wyboru (tylko wiersze)
        vector<T> Gauss_partial() {
            int n = get_rows();
            for (int i = 0; i < n; i++) {
                // znajdŸ wiersz z maksymalnym elementem
                T maxEl = abs(matrix[i][i]);
                int maxRow = i;
                for (int k = i+1; k < n; k++) {
                    if (abs(matrix[k][i]) > maxEl) {
                        maxEl = abs(matrix[k][i]);
                        maxRow = k;
                    }
                }
                // zamieñ maksymalny wiersz z obecnym
                for (int k = i; k < n+1; k++) {
                    T pom = matrix[maxRow][k];
                    matrix[maxRow][k] = matrix[i][k];
                    matrix[i][k] = pom;
                }
                // wyprowadŸ zera przed obecnym wierszem
                for (int k = i+1; k < n; k++) {
                    T c = -matrix[k][i] / matrix[i][i];
                    for (int j = i; j < n+1; j++) {
                        if (i == j) {
                            matrix[k][j] = 0;
                        } else {
                            matrix[k][j] += c * matrix[i][j];
                        }
                    }
                }
            }
            // rozwi¹¿ Ax = B za pomoc¹ powsta³ej macierzy trójk¹tnej
            vector<T> x(n);
            for (int i=n-1; i>=0; i--) {
                x[i] = matrix[i][n] / matrix[i][i];
                for (int k=i-1;k>=0; k--) {
                    matrix[k][n] -= matrix[k][i] * x[i];
                }
            }
            return x;
        }
        
        //bez wyboru
          vector<T> Gauss() {
            int n = get_rows();
            for (int i = 0; i < n; i++) {
                              
                
                // wyprowadŸ zera przed obecnym wierszem
                for (int k = i+1; k < n; k++) {
                    T c = -matrix[k][i] / matrix[i][i];
                    for (int j = i; j < n+1; j++) {
                        if (i == j) {
                            matrix[k][j] = 0;
                        } else {
                            matrix[k][j] += c * matrix[i][j];
                        }
                    }
                }
            }
            // rozwi¹¿ Ax = B za pomoc¹ powsta³ej macierzy trójk¹tnej
            vector<T> x(n);
            for (int i=n-1; i>=0; i--) {
                x[i] = matrix[i][n] / matrix[i][i];
                for (int k=i-1;k>=0; k--) {
                    matrix[k][n] -= matrix[k][i] * x[i];
                }
            }
            return x;
        }
        
        
        void print_matrix(MyMatrix<T>& mat, int prec){
        	cout << "\n";
        	for (int i=0; i<mat.get_rows(); i++) {
    			for (int j=0; j<mat.get_cols(); j++) {
    		cout << setprecision(prec) << mat(i,j) << "\t";
   			}
   		 	cout << endl;
  			}
		}
		
		 void print_matrix(MyMatrix<T>& mat){
        	cout << "\n";
        	for (int i=0; i<mat.get_rows(); i++) {
    			for (int j=0; j<mat.get_cols(); j++) {
    		cout << mat(i,j) << "\t";
   			}
   		 	cout << endl;
  			}
		}
		
		
        
        
};



void eigen_matrix_print(MatrixXd mat){
	
	 for (int i=0; i<mat.rows(); i++) {
      for (int j=0; j<mat.cols(); j++) {
      cout << mat(i,j) << "\t";
    }
    cout << endl;
  }	
}


double D_(Fraction l){
	double wynik;
	wynik = (double)l.numerator / l.denominator;
	return wynik;	
}

double blad(double f1, double f2){
	double wynik = f1 - f2;
	if(wynik < 0) wynik *= (-1);
	return wynik;
}


int main(int argc, char** argv) {

	srand(time(0));
	
	FILE *plik = fopen("ax.csv", "w");
   fprintf(plik, "eigen;double;float\n");
	
	int y;
	cout << "Podaj wielkosc";
	cin >> y;

	for(int i=2; i<=y; i++){
		cout << "\n";
		
		int ilosc = i*i;
		int ulamek[ilosc][2];
		float liczba1[ilosc];
		double liczba2[ilosc];
		float wektor_f[i];
		double wektor_d[i];
		
		MyMatrix<Fraction> A_fract(i,i,s);
		MyMatrix<float> A_float(i,i+1,1.0);
		MyMatrix<double> A_double(i,i+1,1.0);
		
		MyMatrix<Fraction> B_fract(i,i,s);
		MyMatrix<float> B_float(i,i+1,1.0);
		MyMatrix<double> B_double(i,i+1,1.0);
		
		MyMatrix<Fraction> C_fract(i,i,s);
		MyMatrix<float> C_float(i,i,1.0);
		MyMatrix<double> C_double(i,i,1.0);
		
		MatrixXd Eigen_A = MatrixXd(i,i);
		MatrixXd Eigen_B = MatrixXd(i,i);
		MatrixXd Eigen_C = MatrixXd(i,i);
		
		
		vector<Fraction> X_frac(i);
		vector<float> X_float(i);
		vector<double> X_double(i);
		VectorXd Eigen_X(i);
		
		//tworzê u³amki do macierzy	
		Fraction ulamki[ilosc]; 	
		
		for(int j=0; j<(ilosc); j++){
		//	cout << " i = " << ilosc << " j =" << j << endl;		
			ulamek[j][0] = fRand(10);
			ulamek[j][1] = fRand(10);
			liczba1[j] = (float) ulamek[j][0] / ulamek[j][1];
			liczba2[j] = (double) ulamek[j][0] / ulamek[j][1];
		}
		
			for(int j=0; j<(ilosc); j++){					
			Fraction u(ulamek[j][0],ulamek[j][1]);
			ulamki[j] = u;
		}
		//tworzê wektor
		int wektor_ulamki[ilosc][2];
		Fraction wektor_ulamkow[ilosc];
		
			for(int j=0; j<i; j++){
			wektor_ulamki[j][0] = fRand(10);
			wektor_ulamki[j][1] = fRand(10);
			wektor_f[j] = (float) wektor_ulamki[j][0] / wektor_ulamki[j][1];
			wektor_d[j] = (double) wektor_ulamki[j][0] / wektor_ulamki[j][1];			
		}
		
		for(int j=0; j<i; j++){					
			Fraction u2(wektor_ulamki[j][0],wektor_ulamki[j][1]);
			wektor_ulamkow[j] = u2;
		}
		
		//wrzucam do matrixa		  
   			 int p = 0;
   			  int d = 0;
			  for (int j=0; j<i; j++) {
		      for(int c=0; c<i;c++){
			   //cout << p << " " << c << " j =" << d << endl ;
			  A_fract(p,c) = ulamki[d];
			
			  
			  A_double(p,c) = liczba2[d];
			  A_float(p,c) = liczba1[d];
			  Eigen_A(p,c) = liczba2[d];

			  
			  d++;
			  }
			 p++;			 		     
		    }
		    
		  //wrzucam do wektora  
		  for (int j=0; j<i; j++){		  
 		   X_frac[j] = wektor_ulamkow[j];
 		   X_float[j] = wektor_f[j];
 		   X_double[j] = wektor_d[j];
 		   Eigen_X[j] = wektor_d[j];
 		  
 		  }
		 	  
		 	
		
		    for(int c=0; c<A_double.get_rows(); c++){
  			A_double(c,A_double.get_cols()-1)=wektor_d[c];
  			}
  			
  			for(int c=0; c<A_float.get_rows(); c++){
  			A_float(c,A_float.get_cols()-1)=wektor_f[c];
  			}
  			
  			
  			
  					 	
		 	VectorXd wynik = Eigen_A.partialPivLu().solve(Eigen_X);     
		    vector<double> wynik_duble = A_double.Gauss_partial() ;		     
		    vector<float> wynik_float = A_float.Gauss_partial();
		
			 		
		
							
					for(int j=0; j< i; j++){
						cout << "wynikowe " << j << endl;
					fprintf(plik, "%.15lf;", blad(wynik[j],wynik[j]));
					fprintf(plik, "%.15lf;",  blad(wynik[j],wynik_duble[j]));
					fprintf(plik, "%.15lf\n",  blad(wynik[j],wynik_float[j]));
				}
									
				
	}

fclose(plik);
	
 
    
    return 0;
}
  
