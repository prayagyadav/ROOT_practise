//Its important to include all the header files to compile the script 
// tocompile and run : run this with root tut18.C+ in the terminal

#include"TStopwatch.h"
#include"TRandom2.h"
#include<iostream>
using namespace std;

void tut18() {
	TStopwatch t ;
	TRandom2 *rand = new TRandom2();
	double x = 0;
	for (int i = 0 ; i < 1e9 ; i++ ){
		x += rand->Rndm();
	};
	cout<< x << endl;
	t.Print();
}
