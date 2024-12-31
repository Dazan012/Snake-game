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

void Draw()
{
    system("cls"); // Clear the console

    // Draw top border
    for (int i = 0; i < width + 2; i++)
        cout << "#";
    cout << endl;

    // Draw the game area
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if (j == 0)
                cout << "#"; // Left border
            if (i == y && j == x)
                cout << "O"; // Snake head
            else if (i == fruitY && j == fruitX)
                cout << "F"; // Fruit
            else
            {
                bool isTail = false;
                for (int k = 0; k < nTail; k++)
                {
                    if (tailX[k] == j && tailY[k] == i)
                    {
                        cout << "o"; // Snake tail
                        isTail = true;
                    }
                }
                if (!isTail)
                    cout << " "; // Empty space
            }
            if (j == width - 1)
                cout << "#"; // Right border
        }
        cout << endl;
    }

    // Draw bottom border
    for (int i = 0; i < width + 2; i++)
        cout << "#";
    cout << endl;

    cout << "Score: " << score << endl;
}

void Input()
{
    if (_kbhit())
    {
        switch (_getch())
        {
        case 'a':
            dir = LEFT;
            break;
        case 'd':
            dir = RIGHT;
            break;
        case 'w':
            dir = UP;
            break;
        case 's':
            dir = DOWN;
            break;
        case 'x':
            dir = STOP; // Stop the game
            break;
        }
    }
}

void Logic()
{
    int prevX = tailX[0];
    int prevY = tailY[0];
    int prev2X, prev2Y;
    tailX[0] = x; // Update tail position with current head position

    for (int i = 1; i < nTail; i++)
    {
        prev2X = tailX[i];
        prev2Y = tailY[i];
        tailX[i] = prevX; // Move the tail forward
        prevX = prev2X;
        prevY = prev2Y;
    }

    switch (dir)
    {
    case LEFT:
        x--;
        break;
    case RIGHT:
        x++;
        break;
    case UP:
        y--;
        break;
    case DOWN:
        y++;
        break;
    default:
        break;
    }

    // Check for collision with fruit
    if (x == fruitX && y == fruitY)
    {
        score += 10;             // Increase score
        fruitX = rand() % width; // Respawn fruit
        fruitY = rand() % height;
        nTail++; // Increase the length of the snake's tail
    }
