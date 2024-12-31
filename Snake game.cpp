#include <iostream>
#include <conio.h>   // For _kbhit() and _getch()
#include <windows.h> // For Sleep()
using namespace std;

// Constants for the game
const int width = 20;
const int height = 20;
int x, y, fruitX, fruitY, score;
int tailX[100], tailY[100];
int nTail;
enum eDirection
{
    STOP = 0,
    LEFT,
    RIGHT,
    UP,
    DOWN
};
eDirection dir;

void Setup()
{
    dir = STOP;    // Initialize direction to STOP
    x = width / 2; // Start position of snake
    y = height / 2;
    fruitX = rand() % width; // Random position for fruit
    fruitY = rand() % height;
    score = 0; // Initialize score to 0
}
