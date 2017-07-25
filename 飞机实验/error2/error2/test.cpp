//#include "SetColor.h"
//#include "SetPos.h"
#include "FirstInterFace.h"
#include "Game.h"
#include <iostream>
using namespace std;

int main(){
	int mode = interFace();
	system("cls");
	hidConsor();
	game a(mode);
	a.play();
}