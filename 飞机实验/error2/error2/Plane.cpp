#include "Plane.h"


//output my plane
void Plane::printPlane(){
	setWordColor(0x5f);
	setPos(plane[0]);
	cout<<"||";
	setPos(plane[2]);
	cout<<"======";
	setPos(plane[8]);
	cout<<"====";
	setWordColor(0x55);
}


//change the position of the plane
void Plane::planeMove(char s){
	planeClean();
	switch(s){
	case 'w': if(plane[0].Y > 2)for(int i = 0;i < 12;i++) plane[i].Y--;break;
	case 's': if(plane[0].Y < 26)for(int i = 0;i < 12;i++) plane[i].Y++;break;
	case 'a': if(plane[0].X > 2)for(int i = 0;i < 12;i++) plane[i].X-=2;break;
	case 'd': if(plane[0].X < 96)for(int i = 0;i < 12;i++) plane[i].X+=2;break;
	}
}
//clean the plane to NULL in the screen
void Plane::planeClean(){
	setWordColor(0x55);
	setPos(plane[0]);
	cout<<"  ";
	setPos(plane[2]);
	cout<<"      ";
	setPos(plane[8]);
	cout<<"    ";
}




//bullet op

void Plane::shoot(){
	for(int i = 0;i < 20;i++){
		if(bullet[i].Y == 100){
			bullet[i].X = plane[0].X;
			bullet[i].Y = plane[0].Y-1;
			break;
		}
	}
}
void Plane::printBullet(){
	setWordColor(0x5f);
	for(int i = 0;i < 20;i++){
		if(bullet[i].Y != 100){
			setPos(bullet[i]);
			cout<<"*";
		}
	}
	setWordColor(0x55);
}
void Plane::bulletMove(){
	//Sleep(20);
	bulletClean();
	for(int i = 0;i < 20;i++){
		if(bullet[i].Y != 100){
			bullet[i].Y--;
			if(bullet[i].Y <= 1)
				bullet[i].Y = 100;
		}
	}
}
void Plane::bulletClean(){
	setWordColor(0x55);
	for(int i = 0;i < 20;i++){
		if(bullet[i].Y != 100){
			setPos(bullet[i]);
			cout<<" ";
		}
	}
}

void Plane::bulletClean(int i){
	setWordColor(0x55);
		if(bullet[i].Y != 100){
			setPos(bullet[i]);
			cout<<" ";
		}
}






