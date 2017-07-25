#include "SetPos.h"


void setPos(COORD p){//set the posi of the cursor
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),p);
}

void setPos(int x,int y){
	COORD a = {x,y};
	setPos(a);
}

// global hide the cursor
void hidConsor(){
	CONSOLE_CURSOR_INFO cursor_info = {1,0}; 
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE),&cursor_info);
}

void drawCol(int x, int y1, int y2, char ch)//draw a column
{
	int y=y1;
	while(y!=y2+1)
	{
		setPos(x, y);
		cout<<ch;
		y++;
	}
}
void drawRow(int y, int x1, int x2, char ch)// draw a row
{
	setPos(x1,y);
	for(int i = 0; i <= (x2-x1); i++)
		cout<<ch;
}

void drawCol(COORD a, COORD b, char ch)
{
	if(a.X == b.X)
		drawCol(a.X, a.Y, b.Y, ch);
	else
	{
		setPos(0, 25);
		cout<<"error code 02���޷�����У���Ϊ��������ĺ�����(y)�����";
		system("pause");
	}
}

void drawRow(COORD a, COORD b, char ch)
{
	if(a.Y == b.Y)
		drawRow(a.Y, a.X, b.X, ch);
	else
	{
		setPos(0, 25);
		cout<<"error code 01���޷�����У���Ϊ���������������(x)�����";
		system("pause");
	}
}

//draw a rectangle
//���Ͻ����ꡢ���½����ꡢ��row����С���col�����
void drawFrame(COORD a, COORD  b, char row, char col)
{
	drawRow(a.Y, a.X+1, b.X-1, row);
	drawRow(b.Y, a.X+1, b.X-1, row);
	drawCol(a.X, a.Y+1, b.Y-1, col);
	drawCol(b.X, a.Y+1, b.Y-1, col);
}

void drawFrame(int x1, int y1, int x2, int y2, char row, char col)
{
	COORD a={x1, y1};
	COORD b={x2, y2};
	drawFrame(a, b, row, col);
}
