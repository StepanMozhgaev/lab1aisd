#pragma once
#define _USE_MATH_DEFINES

class numerous {
private:
	int* _numerous = nullptr;
	int counter = 0;
	char name;
public:
	numerous();
	int counterr();
	void printer();
	int finder(int number);
	numerous* add(numerous* second);
	numerous* substract(numerous* second);
	void adder(int number);
	bool substracter(int number);
	numerous * intersexion(numerous* second);
	bool availability(int number);
	bool tuskfunction(numerous* second);
};