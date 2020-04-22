#include <iostream>
#include "RadixSort.h"
#include "Queue.h"


int* radixSort(int* vec, int n) {
	int temp, max = 0, i = 0, sizeCurrent;

	//Radix sort in baza 10
	for (int f1 = 0; f1 < n; ++f1) {
		temp = getNrOfDigits(vec[f1]);
		max = temp > max ? temp : max;
	}
	//Variabila locala in for ,destructor chemat automatic dupa terminarea for-ului
	Queue<int> q[10] = {
		Queue<int>(8),Queue<int>(8),Queue<int>(8),Queue<int>(8),Queue<int>(8),
		Queue<int>(8),Queue<int>(8),Queue<int>(8),Queue<int>(8),Queue<int>(8)
	};

	//Pentru fiecare cifra in parte
	for (int f1 = 0; f1 < max; ++f1) {

		//Pentru fiecare numar in parte il punem in cozi
		for (int f2 = 0; f2 < n; ++f2) {
			q[findDigitOf(vec[f2], f1)].put(vec[f2]);
		}
		//Rescriem vectorul
		i = 0;
		for (int f2 = 0; f2 < 10; ++f2) {
			sizeCurrent = q[f2].size();
			temp = 0;
			while (temp < sizeCurrent) {
				vec[i] = q[f2].peek();
				q[f2].skip();
				++i;
				++temp;
			}
		}
	}
	return vec;
}

int getNrOfDigits(int nr) {
	int i = 0;
	while (nr > 0) {
		nr /= 10;
		++i;
	}

	return i;
}

int findDigitOf(int nr, int poz) {

	int tempVect[100];
	int i = 0;

	if (nr == 0)
		return 0;

	while (nr > 0) {
		tempVect[i] = nr % 10;
		nr /= 10;
		i++;
	}

	if (poz >= i) {
		return 0;
	}
	return tempVect[poz];
}
