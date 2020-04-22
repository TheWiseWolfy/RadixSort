#include <iostream>
#include "Queue.h"
#include "RadixSort.h"

#include <stdlib.h>     /
#include <time.h> 

using namespace std;

int main() {

	srand(time(NULL));

	//Marimea vectorului de gestionat 
	int n = 0 , max = 0, i = 0, sizeCurrent;
	cin >> n;

	//Vectorul de sortat
	int* vec = new int[n];

	
	for (int f1 = 0; f1 < n; ++f1) {
		vec[f1] = n- f1;
		//vec[f1]  = rand() % n + 1;

	}

	//Sortare
	vec = radixSort(vec, n);

	//END
	for (int f2 = 0; f2 < n; ++f2) {
		cout << vec[f2] << "\n";
	}
	delete[] vec;

	return 0;
}
