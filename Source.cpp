#include "Header.h"
int main() {
	std::cout << "Tables for f(x) = cos(x) + log(x)" << std::endl;
	RandomSearch(Function, 7, 10);
	std::cout << std::endl;
	std::cout << "Tables for f(x) = sin(5x)(cos(x) + log(x))" << std::endl;
	RandomSearch(ModifiedFunction, 7, 10);
}