#include "Header.h"
#include <fstream>
#include <cmath>
#include <vector>
using namespace std;

ifstream read;
ofstream write;

vector<double> outputData;

formul::formul()
{
	T = delta_t = omega = beta = h0 = A = H0 = deltaS = my = R = f = 0;
}

void formul::readfromfile(int i)
{
	int counter = i+1;
	cout << "<=====================[Input Data #"<< counter <<"]====================>" << endl;
	read.open("input.txt");
	if (!read.is_open()) {
		cout << "Read error\n";
	}
	for (i = 0; i < counter; i++) {
		read >> T >> delta_t >> omega >> beta >> h0 >> A >> H0 >> deltaS >> my >> R >> f;
		deltaS *= pow(10, -4);
		f *= pow(10, -6);
	}
		read.close();
		//
		cout << "T:\t" << T << endl;
		cout << "Delt T:\t" << delta_t << endl;
		cout << "Omega:\t" << omega << endl;
		cout << "Beta:\t" << beta << endl;
		cout << "h0:\t" << h0 << endl;
		cout << "A:\t" << A << endl;
		cout << "H0:\t" << H0 << endl;
		cout << "Delt S:\t" << deltaS << endl;
		cout << "My:\t" << my << endl;
		cout << "R:\t" << R << endl;
		cout << "F:\t" << f << endl;
		cout << "----------------------------------------------------------" << endl;
}

double formul::hCalc(int time)
{
	double result=0;
	if (time >= 0 && time <= T / 3) {
		result = h0 + (3 * A) / T;
	}
	else if (time > T / 3 && time <= (2 * T) / 3) {
		result = h0 + A;
	}
	else {
		result = h0 + A - (time - 2 / 3 * T) * ((3*A) / T);
	}
	return result;
}

double formul::qCalc()
{	
	double q;
	for (int time = 0; time <= T; time += delta_t) {
		q = ((2*pi*my*R*f)/(3*g*deltaS))*sqrt(pow(2*g*H0+pow(calcOmega(time),2)*pow(R,2)+2*g*hCalc(time),3))+sqrt(pow((2*g*H0+pow((calcOmega(time)), 2)*pow(R,2)), 3));
		cout << "Second: " << time << "\tQ:" << q << endl;
		outputData.push_back(q);
	}
	return 0;
}

void formul::savecalctofile()
{
	write.open("output.txt");
	for (int i = 0; i < 3; i++) {
		write << "<=========== Result #" << i+1 << " ===========>" << endl;
		int xsec = 0;
		for (int k = 0+(31*i); k <= (31*i)+(T / delta_t); k++) {
			write << "Sec: " << xsec << "\tQ:" << outputData[k] << endl;
			xsec += delta_t;
		}
	}
	write.close();
}

double formul::calcOmega(int time)
{
	double result = 0;
	if (time >= 0 && time <= T / 3) {
		result = omega;
	}
	else if (time > T / 3 && time <= (2 * T) / 3) {
		result = omega + (time - (T / 3)*((3*beta)/T));
	}
	else {
		result = omega + beta - (time - (2 / 3) * T)*(3*beta)/T;
	}
	return result;
}




