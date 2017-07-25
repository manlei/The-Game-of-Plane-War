#include <windows.h>
#include "SetPos.h"
#include "SetColor.h"
#include <time.h>


class enemy{
protected:
	COORD enemy1[10][8];//10个敌人,每个人8个位置，敌机
	int enemy1SpaceNum;//初始化为10
	int enemy1rate;

	COORD enemy2[3];//锯齿敌人 8x
	int enemy2Life[3];
	int enemy2SpaceNum;


public:

	void initial();

	void printEnemy1();
	void printEnemy1(int i);
	void enemy1Move();
	void enemy1Clean();
	void enemy1Clean(int i);
	void createEnemy1();


	void printEnemy2();
	void printEnemy2(int i);
	void enemy2Move();
	void enemy2Clean();
	void enemy2Clean(int i);
	void createEnemy2();

};