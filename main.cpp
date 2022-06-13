#include <iostream>
#include "Header.h"	

using namespace std;

int main() {
	setlocale(LC_ALL,"Ukr");
	formul formul[3];
	for (int i = 0; i < 3; i++) {
		formul[i].readfromfile(i);
		formul[i].qCalc();
	}
	formul[2].savecalctofile();

}