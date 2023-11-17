#include <iostream>


int main()
{
	int n;
	std::cin >> n;
	int rep = n/4;
	
	for (int i=0; i<rep; i++)
		std::cout << "long ";

	std::cout << "int";
}