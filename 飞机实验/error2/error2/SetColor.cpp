#include "SetColor.h"

void setWordColor(int a){//字体和背景
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),a);
}

void setBackColor(int a){//取出背景的颜色
	int color = (int)(a>>4);
	switch(color){
	case 1:system("color 10");break;
	case 2:system("color 20");break;
	case 3:system("color 30");break;
	case 4:system("color 40");break;
	case 5:system("color 50");break;
	case 6:system("color 60");break;
	case 7:system("color 70");break;
	case 8:system("color 80");break;
	case 9:system("color 90");break;
	case 10:system("color a0");break;
	case 11:system("color b0");break;
	case 12:system("color c0");break;
	case 13:system("color d0");break;
	case 14:system("color e0");break;
	case 15:system("color f0");break;
	default:;
	}
	//system("pause");
}
