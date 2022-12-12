#include "coll.h"
#include "numerous.h"
#include <iostream>

void coll::add_numerous(){
	counter++;
	collection = (numerous**)realloc(collection, counter * sizeof(numerous*));
	collection[counter - 1] = new numerous;
}

void coll::delete_numerous(int number) {
	delete collection[number - 1];
	for (int i = number - 1; i < counter; i++) {
		collection[i] = collection[i + 1];
	}
	counter--;
	collection = (numerous**)realloc(collection, counter * sizeof(numerous*));
}

void coll::delall() {
	for (int i = 0; i < counter; i++)
		delete collection[i];
	counter = 0;
	collection = (numerous**)realloc(collection, counter * sizeof(numerous*));
}

int coll::getcounter() {
	return counter;
}

numerous* coll::example(int number) {
	return collection[number];
}