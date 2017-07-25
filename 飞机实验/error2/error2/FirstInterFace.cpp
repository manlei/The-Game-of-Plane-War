#include "FirstInterFace.h"
void setBackColor(int a);
void setWordColor(int a);



void posClean(COORD pos){
	setPos(pos);
	cout<<"  ";
}
void printPos(COORD pos){
	setPos(pos);
	cout<<">>";
}

COORD getPos(char ch,COORD pos){
	if(ch == 'w'){
		if(pos.Y != 10){
			pos.Y -= 3;
			return pos;
		}
		else
			return pos;
	}
	else{
		if(pos.Y != 19){
		pos.Y += 3;
		return pos;
		}
		else
			return pos;
	}
}

void gameintro(){
	system("cls");
	setPos(48,10);
	cout<<"w,s,a,d control directions";
	setPos(48,12);
	cout<<"p pause during gaming";
	setPos(48,14);
	cout<<"b buy strokes with your score";
	setPos(48,16);
	cout<<"release strokes";
	setPos(48,18);
	cout<<"press 'r' return last level";
	char ch ='a';
	while(ch != 'r')
		ch = getch();
	system("cls");
}

COORD startShow(){
	COORD index = {49,10};
	setPos(index);
	cout<<">>";
	setBackColor(57);
	setWordColor(57);
	//system("color 57");
	COORD  a = {52,10};
	setPos(a);
	cout<<"游戏说明";

	//setPos(100,30);
	//cout<<"";
	
	COORD  b = {52,13};
	setPos(b);
	cout<<"初级难度";

	setPos(98,32);
	cout<<"w,s choose,k to enter";

	COORD  c = {52,16};
	system("color 5f");
	setPos(c);
	cout<<"高级难度";

	COORD  d = {52,19};
	setPos(d);
	cout<<"退出游戏";


	return index;
}

int interFace(){
	hidConsor();
	//drawchart();
	COORD index = startShow();
	while(1){
		char ch = getch();
		if(ch == 'w' || ch == 's'){
			posClean(index);
			index = getPos(ch,index);
			printPos(index);
		}
		else if(ch == 'k'){
			if(index.Y == 10){
				gameintro();
				posClean(index);
				index = startShow();
			}
			else if(index.Y == 13){
				return 1;
			}
			else if(index.Y == 16){
				return 2;
			}
			else if(index.Y = 19){
				system("cls");
				setPos(48,13);
				cout<<"THANK YOU FOR YOUR USING!"<<endl;
				setPos(48,15);
					exit(0);
			}
		}
	}
}

void gameInterFace(){
	setWordColor(0x5c);
	COORD a = {0,0};
	COORD b = {100,0};
	COORD c = {0,30};
	COORD d = {100,30};
	//drawCol(a,c,'|');
	drawCol(b,d,'|');
	//drawRow(a,b,'-');
	//drawRow(c,d,'-');//行
	setPos(103,7);
	cout<<"Score:";
	setPos(103,12);
	cout<<"Rank:";
	setPos(103,17);
	cout<<"strokes:";

	setPos(103,22);
	cout<<"OP:";
	setPos(103,23);
	cout<<"w,s,a,d direction";
	setPos(103,24);
	cout<<"b buy strokes";
	setPos(103,25);
	cout<<"u relase strokes";
	setPos(103,27);
	cout<<"e exit";
	setPos(103,26);
	cout<<"p pause";
	setWordColor(0x55);
	 
}
