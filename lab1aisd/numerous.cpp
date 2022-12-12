#include "numerous.h"
#include <iostream>
using namespace std;

numerous::numerous(){
}

bool numerous::availability(int number) {
	for (int i = 0; i < counter; i++) {
		if (_numerous[i] == number)
			return 1;
	}
	return 0;
}

void numerous::printer() {
	if (counter == 0) cout << "numerous is empty :(" << endl;
	else {
		for (int i = 0; i < counter; i++) {
			cout << _numerous[i] << " | ";
		}
	}
}

void numerous::adder(int number) {
	if (!availability(number)) {
		counter++;
		_numerous = (int*)realloc(_numerous, counter * sizeof(int));
		_numerous[counter - 1] = number;
	}
}

bool numerous::substracter(int number) {
	for (int i = 0; i < counter; i++) {
		if (number == _numerous[i]) {
			for (int j = i; j < counter - 1; j++) {
				_numerous[j] = _numerous[j + 1];
			}
			counter--;
			_numerous = (int*)realloc(_numerous, counter * sizeof(int));
			return 1;
		}
	}
	return 0;
}

numerous* numerous::add(numerous* second) {
	numerous result;
	for (int i = 0; i < counter ; i++) {
		result.adder(_numerous[i]);
	}
	for (int i = 0; i < second->counter ; i++) {
		if (!availability(second->_numerous[i])) {
			result.adder(second->_numerous[i]);
		}
	}
	return &result;
}

numerous* numerous::substract(numerous* second) {
	numerous result;
	for (int i = 0; i < second->counter ; i++) {
		if (!availability(second->_numerous[i])) {
			result.adder(second->_numerous[i]);
		}
	}
	for (int i = 0; i < counter ; i++) {
		if (!second->availability(_numerous[i])) {
			result.adder(_numerous[i]);
		}
	}
	return &result;
}

int numerous::finder(int number) {
	return _numerous[number];
}

numerous* numerous::intersexion(numerous* second) {
	numerous result;
	for (int i = 0; i < counter; i++) {
		if (second->availability(_numerous[i])) {
			result.adder(_numerous[i]);
		}
	}
	for (int i = 0; i < second->counter; i++) {
		if (availability(second->_numerous[i])) {
			result.adder(second->_numerous[i]);
		}
	}
	return &result;
}

bool numerous::tuskfunction(numerous* second) {
	for (int i = 0; i < counter; i++) {
		if (!second->availability(_numerous[i]))
			return 0;
	}
	return 1;
}

int numerous::counterr() {
	return counter;
}