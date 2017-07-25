#include "Plane.h"
#include "Enemy.h"
#include "FirstInterFace.h"
#include <conio.h>


class game :public Plane,public  enemy
{
	int mode;
	int score;
	int strokes;//´óÕÐ

public:
	game(int mode){
		this->mode = mode;
		initial();
	}

	void initial();

	bool enemy1planeCheck();
	bool enemy1bulletCheck();

	bool enemy2planeCheck();
	bool enemy2bulletCheck();

	void gameOver();
	void buystrokes();
	void releaseStrokes();
	void printScore();
	void printRank();
	void printStrokes();

	bool judgeenemy1rate(int nrate);
	bool jusgebulletrate(int nrate);
	
	void gamepause();
	void play();

};

