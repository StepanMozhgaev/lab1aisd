#include "numerous.h"
#include "coll.h"
#include <iostream>
#include "ckey.h"
#include <windows.h>
using namespace std;

int main() {
	coll* colle = new coll();
	while (true) {
		cout << "Hello! Choose your action:" << endl;
		cout << "Add numerous --> [1]" << endl;
		cout << "Delete numerous --> [2]" << endl;
		cout << "Work with some numerous --> [3]" << endl;
		cout << "Delete all --> [4]" << endl;
		cout << "Leave the programm --> [Backspase]" << endl;
		int ckey = Menu();
		if (ckey == 8) {
			system("cls");
			cout << "End..." << endl;
			break;
		}
		switch (ckey) {
		case '1':
			system("cls");
			colle->add_numerous();
			cout << "Added!" << endl;
			break;
		case '2':
			system("cls");
			int number;
			cout << "Enter the number of numerous" << endl;
			cout << "Available " << colle->getcounter() << " numerouses" << endl;
			cin >> number;
			while (number > colle->getcounter() || number < 1) {
				cout << "Print correct number" << endl;
				cin >> number;
			}
			colle->delete_numerous(number);
			cout << "Deleted!" << endl;
			break;
		case '3':
			while (true) {
				system("cls");
				cout << "Choose the numerous" << endl;
				cout << "Available " << colle->getcounter() << " numerouses" << endl;
				cout << "Back to the actions --> [Backspase]" << endl;
				int ckey1 = Menu();
				if (ckey1 == 8) {
					system("cls");
					cout << "Back..." << endl;
					break;
				}
				while ((ckey1 - 48) > colle->getcounter() || (ckey1 - 48) < 1) {
					cout << "Input correct number";
					ckey1 = Menu();
					if (ckey1 == 8) {
						system("cls");
						cout << "Back..." << endl;
						break;
					}
				}
				if (ckey1 == 8) {
					system("cls");
					cout << "Back..." << endl;
					break;
				}
				while (true) {
					system("cls");
					cout << "Choose the action" << endl;
					cout << "Print numerous --> [1]" << endl;
					cout << "Print [n] number --> [2]" << endl;
					cout << "Add number --> [3]" << endl;
					cout << "Delete number --> [4]" << endl;
					cout << "Check availability in numerous --> [5]" << endl;
					cout << "Tuskfunction --> [6]" << endl;
					cout << "Add numerouses --> [7]" << endl;
					cout << "Substract numerouses --> 8[]" << endl;
					cout << "Intersection of numerouses --> [9]" << endl;
					cout << "Back to the actions --> [Backspase]" << endl;
					int ckey2 = Menu();
					if (ckey2 == 8) {
						system("cls");
						cout << "Back..." << endl;
						break;
					}
					numerous* example = colle->example(ckey1 - 49);
					int a;
					switch (ckey2) {
					case '1':
						example->printer();
						Sleep(5000);
						break;
					case '2':
						if (example->counterr() == 0) {
							cout << "Sorry, numerous is empty :(";
							Sleep(3000);
							break;
						}
						cout << "Availible " << example->counterr() << " numbers in numerous" << endl;
						cout << "Input [n]: ";
						cin >> a;
						while (a > example->counterr() || a < 1) {
							cout << "Input correct number!!!" << endl;
							cin >> a;
						}
						cout << "The number is: " << example->finder(a - 1) << endl;
						Sleep(3000);
						break;
					case'3':
						cout << "Input number ";
						cin >> a;
						example->adder(a);
						cout << "The number is added!" << endl;
						Sleep(1500);
						break;
					case'4':
						cout << "Input number ";
						cin >> a;
						if (example->substracter(a)) cout << "Deleted!" << endl;
						else cout << "This number doesn't belong to the set" << endl;
						Sleep(3000);
						break;
					case'5':
						cout << "Availible " << example->counterr() << " numbers in numerous " << endl;
						cout << "Input number";
						cin >> a;
						if (example->availability(a)) cout << "This number belongs to the set " << endl;
						else cout << "This number doesn't belong to the set" << endl;
						Sleep(3000);
						break;
					case'6':
						cout << "Choose second numerous" << endl;
						cout << "Available " << colle->getcounter() << " numerouses " << endl;
						cout << "Now you are working with " << ckey1 << " numerous" << endl;
						cin >> a;
						while (a > colle->getcounter() || a < 1) {
							cout << "Input correct number";
							cin >> a;
								break;
							}
						if (example->tuskfunction(colle->example(a - 1))) cout << "All elements of the first set are found in the second" << endl;
						else cout << "Not all elements of the first set are found in the second" << endl;
						Sleep(3000);
						break;
					case '7':
						cout << "Choose second numerous" << endl;
						cout << "Available " << colle->getcounter() << " numerouses " << endl;
						cout << "Now you are working with " << ckey1 - 48 << " numerous" << endl;
						cin >> a;
						while (a > colle->getcounter() || a < 1) {
							cout << "Input correct number";
							cin >> a;
							break;
						}
						(example->add(colle->example(a - 1)))->printer();
						Sleep(10000);
						break;
					case '8':
						cout << "Choose second numerous" << endl;
						cout << "Available " << colle->getcounter() << " numerouses " << endl;
						cout << "Now you are working with " << ckey1 - 48 << " numerous" << endl;
						cin >> a;
						while (a > colle->getcounter() || a < 1) {
							cout << "Input correct number";
							cin >> a;
							break;
						}
						(example->substract(colle->example(a - 1)))->printer();
						Sleep(10000);
						break;
					case '9':
						cout << "Choose second numerous" << endl;
						cout << "Available " << colle->getcounter() << " numerouses " << endl;
						cout << "Now you are working with " << ckey1 - 48 << " numerous" << endl;
						cin >> a;
						while (a > colle->getcounter() || a < 1) {
							cout << "Input correct number";
							cin >> a;
							break;
						}
						(example->intersexion(colle->example(a - 1)))->printer();
						Sleep(10000);
						break;
					default:
						break;
					}
				}
			}
		case '4':
			system("cls");
			colle->delall();
			cout << "Done!";
			break;
		}
	}
	colle->delall();
	delete colle;
	return 0;
}