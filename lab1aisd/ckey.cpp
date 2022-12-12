#include <iostream>
#include <conio.h>
#include "ckey.h"

int Menu() {
    int key = _getch();
    if (key == 48 || key == 49 || key == 50 || key == 51 || key == 52 || key == 53 || key == 54 || key == 55 || key == 8 || key == 56 || key == 57)
        return key;
    return 0;
}