#include "Game.h"

//initial the position of the plane
void game::initial(){
	//plane position
	plane[0].X= 50,
	plane[0].Y = 20,
	plane[1].X = 51,
	plane[1].Y = 20;
	for(int i = 2;i < 7;i++){
		plane[i].X = 46+i;
		plane[i].Y = 21;
	}
	for(int i = 8;i < 12;i++){
		plane[i].X = 41+i;
		plane[i].Y = 22;
	}

	//bullet position,100
	for(int i = 0;i < 20;i++)
		bullet[i].Y = 100;

	//enemy1 initial
	enemy1SpaceNum = 10;
	for(int i = 0;i < 10;i++){
		enemy1[i][0].X = 100;
		enemy1[i][0].Y = 100;
	}

	//enemy2 initial
	enemy2SpaceNum = 3;
	enemy2[1].X = 100;
	enemy2[1].Y = 100;
	enemy2[0].X = 100;
	enemy2[0].Y = 100;
	enemy2[2].X = 100;
	enemy2[3].Y = 100;
	enemy2Life[0] = 5;
	enemy2Life[1] = 5;
	enemy2Life[2] = 5;
	planeLife = 2;

	score = 0;
	strokes = 0;

	enemy1rate = 5000;
	bulletrate = 3000;
}

//four check

//check whether enemy2 have coolision
bool game::enemy2planeCheck(){
	for(int i = 0;i < 3;i++){
		for(int j = 0;j < 12;j++){
			if(abs(plane[0].X-enemy2[i].X) <= 11 && abs(plane[0].Y-enemy2[i].Y) <=3){
				if(plane[j].X+1 >= enemy2[i].X && plane[j].X+1 <= enemy2[i].X+8 && (plane[j].Y == enemy2[i].Y || plane[j].Y == enemy2[i].Y+1)){//collision
					/*enemy2Clean(j);//暂时是enemy2消失
					printPlane();
					enemy2[j].X = 100;
					enemy2[j].Y = 100;
					enemy2SpaceNum++;
					*/gameOver();
					return 1;
				}
			}
		}
	}
	return true;
}

bool game::enemy2bulletCheck(){
	for(int i = 0;i < 20;i++){
		if(bullet[i].Y != 100){
			for(int j = 0;j < 3;j++){
				if(bullet[i].X <= enemy2[j].X+8 && bullet[i].X >= enemy2[j].X && (bullet[i].Y == enemy2[j].Y || bullet[i].Y == enemy2[j].Y+1)){															
							if((--enemy2Life[j]) == 0){
								enemy2Clean(j);
								enemy2[j].X = 100;
								enemy2[j].Y = 100;
								enemy2SpaceNum++;
								score+=200;
								printScore();
								printRank();
							}
							bulletClean(i);
							printEnemy2();//重画
							bullet[i].Y = 100;
							break;
					}
				}
			}
		}
	return true;
}



//check whether enemy1 have collision
bool game::enemy1planeCheck(){//相撞返回false
	//planeClean();
	//enemy1Clean();
	for(int i = 0;i < 10;i++){
		for(int j = 0;j < 12;j++){
			if(abs(plane[0].X-enemy1[i][0].X) <= 10 && abs(plane[0].Y-enemy1[i][0].Y) <=3)
				for(int k = 0;k < 8;k++)
					if((plane[j].X+1 == enemy1[i][k].X || plane[j].X == enemy1[i][k].X) && plane[j].Y == enemy1[i][k].Y){//清除掉敌机，本机暂不处理
					/*	enemy1Clean(i);
						printPlane();
						enemy1[i][0].X = 100;
						enemy1[i][0].Y = 100;
						enemy1SpaceNum++;
					*/	gameOver();
						return 1;
					}
		}
	}
	return true;
}

bool game::enemy1bulletCheck(){//相撞返回false
	//bulletClean();
	//enemy1Clean();
	for(int i = 0;i < 20;i++){
		if(bullet[i].Y != 100){
			for(int j = 0;j < 10;j++){
				if(bullet[i].X <= enemy1[j][5].X && bullet[i].X >= enemy1[j][0].X && (bullet[i].Y == enemy1[j][0].Y || bullet[i].Y == enemy1[j][7].Y)){
					for(int k = 0;k < 8;k++)
						if(bullet[i].X == enemy1[j][k].X && bullet[i].Y == enemy1[j][k].Y){
							enemy1Clean(j);
							bulletClean(i);
							enemy1[j][0].X = 100;
							enemy1[j][0].Y = 100;
							enemy1SpaceNum++;
							bullet[i].Y = 100;
							score+=100;
							printScore();
							printRank();
							i++;
							j = 0;
							break;
					}
				}
			}
		}
	}
	return true;
}


void game::gameOver(){
	setWordColor(0x5c);
	Sleep(2000);
	system("cls");
	setPos(48,9);
	cout<<"G A M E  O V E R !";
	setPos(48,12);
	cout<<"final score:"<<score;
	setPos(48,15);
	cout<<"rank:";
	if(score < 1000){
		setPos(54,15);
		cout<<"菜鸟飞行员  ";
	}
	else if(score < 2000){
		setPos(54,15);
		cout<<"新手上道    ";
	}
	else if(score < 3000){
		setPos(54,15);
		cout<<"合格司机    ";
	}
	else if(score < 4000){
		setPos(54,15);
		cout<<"初级教练    ";
	}
	else if(score < 1000){
		setPos(54,15);
		cout<<"高级教练    ";
	}
	else {
		setPos(54,15);
		cout<<"终极老司机  ";
	}

	setPos(48,18);
	cout<<"DO'NT you be convinced ?";
	setPos(48,21);
	cout<<"PRESS Y to play again, N to give up";
	char c = 'a';
	while(!(c == 'y' || c == 'Y' || c == 'n' || c == 'N')){
		c = getch();
	}
	if(c == 'n' || c == 'N')
		exit(0);
	else
	{
		system("cls");
		int mode = interFace();
		system("cls");
		hidConsor();
		game a(mode);
		a.play();
	}


	setWordColor(0x55);

	exit(0);
}

void game::printScore(){
	setWordColor(0x5c);
	setPos(110,7);
	cout<<"            ";
	setPos(110,7);
	cout<<score;
	setWordColor(0x55);
}
void game::printRank(){
	setWordColor(0x5c);
	//setPos(112,17);
	//cout<<"           ";
	//setPos(112,17);
	//cout<<strokes;
	if(score < 1000){
		setPos(109,12);
		cout<<"菜鸟飞行员  ";
	}
	else if(score < 2000){
		setPos(109,12);
		cout<<"新手上道    ";
	}
	else if(score < 3000){
		setPos(109,12);
		cout<<"合格司机    ";
	}
	else if(score < 4000){
		setPos(109,12);
		cout<<"初级教练    ";
	}
	else if(score < 1000){
		setPos(109,12);
		cout<<"高级教练    ";
	}
	else {
		setPos(109,12);
		cout<<"终极老司机  ";
	}
	setWordColor(0x55);
}
void game::printStrokes(){
	setWordColor(0x5c);
	setPos(112,17);
	cout<<"            ";
	setPos(112,17);
	cout<<strokes;

}

void game::buystrokes(){
	if(score > 100){
		score = score - 100;
		strokes++;
		printScore();
		printRank();
		printStrokes();
	}
}
void game::releaseStrokes(){
	if(strokes > 0){
		enemy1Clean();
		for(int i = 0;i < 10;i++){
			enemy1[i][0].X = 100;
			enemy1[i][0].Y = 100;
			enemy1SpaceNum = 10;
		}
		enemy2Clean();
		for(int i = 0;i < 3;i++){
			enemy2[i].X = 100;
			enemy2[i].Y = 100;
			enemy2SpaceNum = 3;
		}
		strokes--;
		printStrokes();
		Sleep(1000);
	}
}



bool game::judgeenemy1rate(int nrate){
	if(nrate == enemy1rate){
		if(mode == 1){
			if(enemy1rate > 1000)
				enemy1rate -= 1;
		}
		else{
			if(enemy1rate > 700)
				enemy1rate -= 2;
		}
		return true;
	}
	return false;
}
bool game::jusgebulletrate(int nrate){
	if(nrate == bulletrate){
		if(bulletrate > 1000)
			bulletrate -= 1;
		return true;
	}
	return false;
}

void game::gamepause(){
	setWordColor(0x5c);
	setPos(103,3);
	cout<<"Pause!";
	char ch;
	ch = getch();
	while(ch != 'p')
		ch = getch();
	setPos(103,3);
	cout<<"      ";
	setWordColor(0x55);
}
void game::play(){

	int count = 0;
	int count1 = 0;
	printPlane();
	gameInterFace();
	printScore();
	printRank();
	printStrokes();
	
	while(1){
		
		char ch;
		if(kbhit()){
			ch = getch();
			if(ch == 'w' ||ch == 'a' ||ch == 's' ||ch == 'd'){
				planeMove(ch);
				enemy1planeCheck();
				printPlane();
			}
			else if(ch == 'e')
				return ;
			else if(ch == 'b')
				buystrokes();
			else if(ch == 'u')
				releaseStrokes();
			else if(ch == 'p')
				gamepause();
		}
		count++;
		count1++;
		if(judgeenemy1rate(count)){	//5000
			createEnemy1();//check enemy1 with bullet and plane			
			enemy1Move();
			//a.enemy1bulletCheck();
			printEnemy1();
			enemy1planeCheck();

			createEnemy2();
			enemy2Move();
			printEnemy2();
			enemy2planeCheck();
			count = 0;
		}

		if(jusgebulletrate(count1)){//3000
			shoot();//check enemy1 with bullet
			bulletMove();
			printBullet();
			enemy1bulletCheck();
			enemy2bulletCheck();
			count1 = 0;
		}
	}
}