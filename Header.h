#pragma once
#include "cpp-text-table-master\TextTable.h"
#include <math.h>
#include <iostream>
#include <string>
double Function(double x) {
	return (cos(x) + log10(x));
}
double ModifiedFunction(double x) {
	return (sin(5 * x) * Function(x));
}
double CalcPoints(double P, double q) {
	double numerator = log(1 - P);
	double denominator = log(1 - q);
	return (numerator / denominator);
}
double FindMinX(double function(double), double N, int a, int b) {
	double delta = (b - a) / N;
	double min_x = a + delta;
	for (size_t i = 2; i <= N; ++i) {
		double temp_x = a + delta * i;
		if (function(min_x) < function(temp_x)) {
			continue;
		}
		else {
			min_x = temp_x;
		}
	}
	return min_x;
}
template<typename T>
void Print(std::vector<std::vector<T>>& val) {
	TextTable table('-', '|', '+');
	table.add("P/q");
	for (double p = 0.9; p < 1; p += 0.01) {
		table.add(std::to_string(p));
	}
	table.endOfRow();
	table.setAlignment(2, TextTable::Alignment::LEFT);
	for (double i = 0, q = 0.005; i < 20; ++i, q+=0.005) {
		table.add(std::to_string(q));
		for (size_t j = 0; j < 10; ++j) {
			T temp = val[j][i];
			table.add(std::to_string(temp));
		}
		table.endOfRow();
		table.setAlignment(2, TextTable::Alignment::LEFT);
	}
	std::cout << table;
}
void RandomSearch(double function(double), int a, int b ) {
	std::vector<std::vector<double>> values(10);
	std::vector<std::vector<int>> arguments(10);
	double P = 0.9;
	for (size_t i = 0; i < 10; ++i) {
		double q = 0.005;
		for (size_t j = 0; j < 20;  ++j) {
			double N = CalcPoints(P, q);
			arguments[i].push_back(floor(N));
			values[i].push_back(FindMinX(function, N, a, b));
			q += 0.005;
		}
		P += 0.01;
	}
	std::cout << "Table of Arguments" << std::endl;
	Print(arguments);
	std::cout << std::endl;
	std::cout << "Table of Values" << std::endl;
	Print(values);
}