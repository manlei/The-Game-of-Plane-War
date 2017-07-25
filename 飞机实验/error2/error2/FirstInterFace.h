#include <windows.h>
#include <conio.h>
#include <iostream>
using namespace std;

#include "SetPos.h"
#include "SetColor.h"

#ifndef _FirstInterFace_H
#define _FirstInterFace_H

void posClean(COORD pos);
void printPos(COORD pos);

COORD getPos(char ch,COORD pos);
void gameintro();
COORD startShow();
int interFace();
void gameInterFace();

#endif