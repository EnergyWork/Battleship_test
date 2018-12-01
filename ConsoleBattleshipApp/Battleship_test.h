#include "libs.h"

class Battleship {
private:
	size_t width;
	size_t height;

public: 
	Battleship();
	~Battleship();

	void run();
	size_t getwidth();
	size_t getheight();
};