#include <windows.h>
#include <iostream>
using namespace std;

#ifndef _SetPos_H
#define _SetPos_H
void setPos(COORD p);
void setPos(int x,int y);

// global hide the cursor
void hidConsor();

void drawCol(int x, int y1, int y2, char ch);
void drawCol(COORD a, COORD b, char ch);

void drawRow(int y, int x1, int x2, char ch);
void drawRow(COORD a, COORD b, char ch);

//左上角坐标、右下角坐标、用row填充行、用col填充列
void drawFrame(COORD a, COORD  b, char row, char col);
void drawFrame(int x1, int y1, int x2, int y2, char row, char col);
#endif