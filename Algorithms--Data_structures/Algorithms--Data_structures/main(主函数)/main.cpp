#include "Sorting_algorithm(≈≈–ÚÀ„∑®)/Bubble.h"

#include <iostream>

using namespace std;

int main(void)
{

	std::cout << "Welcome to algorithms and data structures." << std::endl;

	//√∞≈›≈≈–Ú≤‚ ‘
	int Arr_i[] = { 3, 1, 4, 2 , 6, 9, 5, 7, 8, 0 };
	double Arr_d[] = { 13.1, 21.3, 31.4, 0.31, 1.43, 6.52, 12.6, 19.75, 50.01, 30.33};
	bubble(Arr_i, 10);
	bubble(Arr_d, 10);
	for (int i = 0; i < 10; i++)
		cout << Arr_d[i] << ", ";
	cout << endl;

	//










	std::cin.get();
}