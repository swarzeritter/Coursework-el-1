#pragma once
#include <iostream>
#include <cmath>



struct formul {
	double T, delta_t, omega, beta, h0, A, H0, deltaS, my, R, f;
	const double g=9.8;	// звичайне значення гравітації
	const double pi=3.14;
public:
	formul();
	void readfromfile(int i);
	double calcOmega(int time);
	double hCalc(int time);
	double qCalc();
	void savecalctofile();
};