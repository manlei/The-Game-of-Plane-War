#include <windows.h>
#include "SetPos.h"
#include "SetColor.h"

class Plane{
protected:
	COORD plane[12];
	int planeLife;

	COORD bullet[20];
	int bulletrate;


public:
	void initial();
	void printPlane();
	void planeMove(char s);
	void planeClean();

	void shoot();
	void printBullet();
	void bulletMove();
	void bulletClean();
	void bulletClean(int i);


};