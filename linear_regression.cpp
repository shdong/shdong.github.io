#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
//https://github.com/Aluxian/CPP-ML-LinearRegression/blob/master/LinearRegression.cpp

bool loadData(const char *file,vector< vector<double> > &X,int n){
	ifstream iFile(file);
	if (!iFile) return false;
	vector<double> x(n);
	while (iFile >> x[0]) {
		for (int i = 1; i < n; i++)
			iFile >> x[i];
		X.push_back(x);
	}
	return true;
}
bool loadData(const char *file,  vector<double>  &y) {
	ifstream iFile(file);
	if (!iFile) return false;
	double yi;
	while (iFile >> yi) {
		y.push_back(yi);
	}
	return true;
}

inline double hx(vector<double> theta, vector<double> x) {
	int n = theta.size();
	double h = 0;
	for (int j = 0; j < n; j++)
		h += theta[j] * x[j];
	return h;
}

void gradient_descent(vector< vector<double> > &X, vector<double>  &y,double alpha,int iterations, 
	vector<double> &theta, vector<double> &J)
{	
	int m = X.size();
	int n = X[0].size();
	theta.resize(n);
	for (int j = 0; j < theta.size(); j++)
		theta[j] = 0;

	vector<double> errs(m);
	
	J.resize(iterations);

	for (int iter = 0; iter < iterations; iter++) {
		J[iter] = 0; 
		for (int i = 0; i < m; i++) {
			errs[i] = y[i] - hx(theta, X[i]);
			J[iter] +=  errs[i] * errs[i];
		}
		J[iter] /= (2*m);

		for (int j = 0; j < n; j++) {
			double sum = 0;
			for (int i = 0; i < m; i++) {				
				sum = sum + errs[i] * X[i][j];
			}
			theta[j] = theta[j] + alpha*sum / m;
		}
	}
}
int main() {
	
	vector< vector<double> > X;
	vector<double>  y;
	
	loadData("../../ex2x.dat", X, 1);
	loadData("../../ex2y.dat", y);

	int m = X.size();
	int n = X[0].size();

	// X1[i]:  1  X[i][0]  X[i][1] ...X[i][n-1] ;
	vector< vector<double> > X1(m);
	for (int i = 0; i < m; i++) {
		X1[i].resize(n + 1);
		X1[i][0] = 1;
		for (int j = 0; j < n; j++)
			X1[i][j + 1] = X[i][j];
	}

	vector<double> theta;
	vector<double> J;
	double alpha = 0.07;
	int iterations = 1500;
	gradient_descent(X1, y, alpha, iterations, theta, J);

#if 0
	std::cout << "the iterative J(theta) is:\n";
	for (int i = 0; i < iterations; i++)
		std::cout << J[i] << "\n";
	std::cout << "\n";
#endif

	std::cout << "the theta is:\n";
	for (int j = 0; j < theta.size(); j++)
		std::cout << theta[j] << " ";
	std::cout << "\n";

	vector<double> x(2); 
	x[0] = 1; x[1] = 3.5;
	std::cout << "For age = 3.5, we predict a profit of " << hx(theta,x)  << "\n";
	x[1] = 7;
	std::cout << "For age = 7 , we predict a profit of " << hx(theta, x) << "\n";

	return 0;
}