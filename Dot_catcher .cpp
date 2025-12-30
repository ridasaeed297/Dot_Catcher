#include <iostream>
#include <conio.h>   // for getch()
#include <cstdlib>   // for rand() and srand()
#include <ctime>     // for time()
using namespace std;

const int width = 20;
const int height = 10;

int x, y;       // player position
int foodX, foodY;
int score;
bool gameOver;

void Setup() {
    gameOver = false;
    x = width / 2;
    y = height / 2;
    srand(time(0));
    foodX = rand() % (width - 2) + 1;
    foodY = rand() % (height - 2) + 1;
    score = 0;
}

void Draw() {
    system("cls");   // clear screen

    for (int i = 0; i < width + 2; i++)
        cout << "#";
    cout << endl;

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (j == 0)
                cout << "#";

            if (i == y && j == x)
                cout << "P";          // player
            else if (i == foodY && j == foodX)
                cout << "*";          // dot
            else
                cout << " ";

            if (j == width - 1)
                cout << "#";
        }
        cout << endl;
    }

    for (int i = 0; i < width + 2; i++)
        cout << "#";

    cout << "\nScore: " << score << endl;
    cout << "Controls: W A S D | Quit: Q" << endl;
}

void Input() {
    if (_kbhit()) {
        char ch = _getch();
        switch (ch) {
            case 'a': x--; break;
            case 'd': x++; break;
            case 'w': y--; break;
            case 's': y++; break;
            case 'q': gameOver = true; break;
        }
    }
}

void Logic() {
    // wall collision
    if (x < 0 || x >= width || y < 0 || y >= height)
        gameOver = true;

    // catching the dot
    if (x == foodX && y == foodY) {
        score++;
        foodX = rand() % (width - 2) + 1;
        foodY = rand() % (height - 2) + 1;
    }
}

int main() {
    Setup();
    while (!gameOver) {
        Draw();
        Input();
        Logic();
        _sleep(100);   // slow down game
    }

    system("cls");
    cout << "Game Over!" << endl;
    cout << "Final Score: " << score << endl;
    return 0;
}

