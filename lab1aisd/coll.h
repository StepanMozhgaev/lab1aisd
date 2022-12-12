#pragma once
#include "numerous.h"
class coll {
private:
	numerous** collection = nullptr;
	int counter = 0;
public:
	void add_numerous();
	void delete_numerous(int number);
	void delall();
	int getcounter();
	numerous* example(int number);
};