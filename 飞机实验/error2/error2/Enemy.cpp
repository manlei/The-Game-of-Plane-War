#include "Enemy.h"


//output the enemy1
void enemy::printEnemy1(){
	setWordColor(0x5a);
	for(int i = 0;i < 10;i++){
		if(enemy1[i][0].X != 100 && enemy1[i][0].Y != 100){
			setPos(enemy1[i][0]);
			cout<<"\\\\  //";
			setPos(enemy1[i][0].X +2,enemy1[i][0].Y+1);
			cout<<"||";
		}
	}
	setWordColor(0x55);
}

void enemy::printEnemy1(int i){
	setWordColor(0x5a);
		if(enemy1[i][0].X != 100 && enemy1[i][0].Y != 100){
			setPos(enemy1[i][0]);
			cout<<"\\\\  //";
			setPos(enemy1[i][0].X +2,enemy1[i][0].Y+1);
			cout<<"||";
		}
		setWordColor(0x55);
}


void enemy::enemy1Move(){
//	Sleep(1000);
	enemy1Clean();
	for(int i = 0;i < 10;i++){
		if(enemy1[i][0].X != 100 && enemy1[i][0].Y != 100){
			for(int j = 0;j < 8;j++)
				enemy1[i][j].Y += 1;
			if(enemy1[i][0].Y == 28){//到第30行就结束生命
				enemy1[i][0].X = 100;
				enemy1[i][0].Y = 100;
				enemy1SpaceNum++;
			}
		}
	}
}

void enemy::enemy1Clean(int i){
	setWordColor(0x55);
		if(enemy1[i][0].X!= 100 && enemy1[i][0].Y != 100){
			setPos(enemy1[i][0]);
			cout<<"      ";
			setPos(enemy1[i][0].X +2,enemy1[i][0].Y+1);
			cout<<"  ";
		}
}


void enemy::enemy1Clean(){
	setWordColor(0x55);
	for(int i = 0;i < 10;i++){
		if(enemy1[i][0].X!= 100 && enemy1[i][0].Y != 100){
			setPos(enemy1[i][0]);
			cout<<"      ";
			setPos(enemy1[i][0].X+2,enemy1[i][0].Y+1);
			cout<<"  ";
		}
	}
}

void enemy::createEnemy1(){
	int createNum = 0;//确定生成敌人个数
	srand((unsigned) time(NULL));
	if(enemy1SpaceNum > 0){
		createNum = rand() % enemy1SpaceNum;
		enemy1SpaceNum -= createNum;
	}
	for(int i = 0;i < createNum;i++){//生成createNum架敌机
		for(int j = 0;j < 10;j++){
			if(enemy1[j][0].X == 100 && enemy1[j][0].Y == 100){//生成一架敌机
				enemy1[j][0].X = rand() % (93 / createNum) + i * (93 / createNum)+2;
				for(int k = 0;k < 6;k++){
					enemy1[j][k].X = enemy1[j][0].X+k;
					enemy1[j][k].Y = 1;
				}
				enemy1[j][6].X = enemy1[j][0].X+2;
				enemy1[j][6].Y = 2;
				enemy1[j][7].X = enemy1[j][0].X+3;
				enemy1[j][7].Y = 2;
				break;
			}
		}
	}
}



//op of enemy2
void enemy::printEnemy2(){
	setWordColor(0x5e);
	for(int i = 0;i < 3;i++){
		if(enemy2[i].X != 100 && enemy2[i].Y != 100){
			setPos(enemy2[i]);
			cout<<"________";
			setPos(enemy2[i].X,enemy2[i].Y+1);
			cout<<"\\/ \\/ \\/";
		}
	}
	setWordColor(0x55);
}

void enemy::printEnemy2(int i){
	setWordColor(0x5e);
		if(enemy2[i].X != 100 && enemy2[i].Y != 100){
			setPos(enemy2[i]);
			cout<<"________";
			setPos(enemy2[i].X,enemy2[i].Y+1);
			cout<<"\\/ \\/ \\/";
		}
		setWordColor(0x55);
}

void enemy::enemy2Clean(){
	setWordColor(0x55);
	for(int i = 0;i < 3;i++){
		if(enemy2[i].X != 100 && enemy2[i].Y != 100){
			setPos(enemy2[i]);
			cout<<"        ";
			setPos(enemy2[i].X,enemy2[i].Y+1);
			cout<<"        ";
		}
	}
}

void enemy::enemy2Clean(int i){
	setWordColor(0x55);
		if(enemy2[i].X != 100 && enemy2[i].Y != 100){
			setPos(enemy2[i]);
			cout<<"        ";
			setPos(enemy2[i].X,enemy2[i].Y+1);
			cout<<"        ";
		}
}

void enemy::createEnemy2(){
	int createNum = 0;//确定生成敌人个数
	if(enemy1SpaceNum <= 1 && enemy2SpaceNum > 0){
		srand((unsigned) time(NULL));
		createNum = rand() % enemy2SpaceNum;
		enemy2SpaceNum -= createNum;
	}

	for(int i = 0;i < createNum;i++){//生成createNum架敌机
		for(int j = 0;j < 3;j++){
			if(enemy2[j].X == 100 && enemy2[j].Y == 100){//生成一架敌机
				enemy2[j].X = rand() % (91 / createNum) + i * (91 / createNum)+2;
				enemy2[j].Y = 0;
				enemy2Life[j] = 5;
				break;
			}
		}
	}
}

void enemy::enemy2Move(){
	enemy2Clean();
	for(int i = 0;i < 3;i++){
		if(enemy2[i].X != 100 && enemy2[i].Y != 100){
			enemy2[i].Y += 1;
			if(enemy2[i].Y == 28){//到第30行就结束生命
				enemy2[i].X = 100;
				enemy2[i].Y = 100;
				enemy2SpaceNum++;
			}
		}
	}
}

