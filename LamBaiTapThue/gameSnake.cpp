#include <iostream>
#include <conio.h>
#include <windows.h>
#include <iomanip> 
#include <string>
#include <vector>
#include <stdlib.h>
#include <time.h>
#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77
using namespace std;

class gameInfo {
public:
    vector<int> score = { 60, 40, 20 };
    vector<int> snakeBodyX;
    vector<int> snakeBodyY;

    bool isAlive = true, playerWon = false;

    int playFieldWidth = 30;
    int playFieldHeight = 20;
    int x = playFieldWidth / 2, y = playFieldHeight / 2;
    int foodPosX = rand() % (playFieldWidth - 4) + 2;
    int foodPosY = rand() % (playFieldHeight - 4) + 2;
    int min = 0, row, col, currentScore = 0, currentBest = 0, gamesPlayed = 0;
    int tillHighScore = score[2];

    void updateCurrentBest() { 
        if (currentScore > currentBest) currentBest = currentScore; 
    }

    void updateTillHighScore() {  
        for (int i = 0; i < 3; i++) {
            if (currentScore < score[i]) tillHighScore = score[i] - currentScore;
            else if (currentScore >= score[0]) tillHighScore = 0;
        } 
    } 

    void updateScoreBoard() {  
        for (int tracker = 0; tracker < score.size(); tracker++) {
            if (currentScore > score[tracker]) { 
                score.insert(score.begin() + tracker, currentScore);
                score.erase(score.begin()+score.size());
                return;
            }
        }
    }
};

class snakeInteractions : public gameInfo {
public:
    void getSnakeBody() {
        snakeBodyX.insert(snakeBodyX.begin(), x);
        snakeBodyY.insert(snakeBodyY.begin(), y);
    }

    void resetSnakeBody() {
        for (int erase = 0; erase < snakeBodyX.size(); erase++) {
            snakeBodyX.erase(snakeBodyX.begin() + erase);
            snakeBodyY.erase(snakeBodyY.begin() + erase);
        }
    }

    void updateFoodPOS() { // randomly places food between 2 and (dimension - 2) - aka doesn't touch walls because I suck at this game and keep dying
        bool isUnique = false;
        while (!isUnique) {
            foodPosX = rand() % (playFieldWidth - 4) + 2;
            foodPosY = rand() % (playFieldHeight - 4) + 2;

            for (int i = 0; i < snakeBodyX.size(); i++) {
                if (foodPosY == snakeBodyY[i] && foodPosX == snakeBodyX[i]) break;
                else isUnique = true;
            }
        }
    }

    void getSnakeCondition() { // just checks for if the snake has eatten a piece of food or died by crashing into itself or a wall.
        if (foodPosX == x && foodPosY == y) {
            currentScore += 10;
            updateTillHighScore();
            updateFoodPOS();
        }

        if (x == 0 || x == playFieldWidth - 1 || y == 0 || y == playFieldHeight - 1) { 
            isAlive = false; 
        }

        for (int i = 1; i <= currentScore / 10; i++) {
            if (snakeBodyX[i] == x && snakeBodyY[i] == y) {
                isAlive = false;
            }
        }
    }
};



class playSnake : public snakeInteractions { 
public:

    enum directions { UP, DOWN, LEFT, RIGHT };
    directions dir;

    void getKeyStroke() {
        if (_kbhit()) {
            switch (_getch()) {
            case 'a': case 'A': case KEY_LEFT:
                if (dir != RIGHT) dir = LEFT;
                break;
            case 'd': case 'D': case KEY_RIGHT:
                if (dir != LEFT) dir = RIGHT;
                break;
            case 'w': case 'W': case KEY_UP:
                if (dir != DOWN) dir = UP;
                break;
            case 's': case 'S': case KEY_DOWN:
                if (dir != UP) dir = DOWN;
                break;
            }
        }
    }

    void setPlayField() {
        system("cls");
        for (row = 0; row < playFieldHeight; row++) {
            for (col = 0; col < playFieldWidth; col++) {
                if (row == 0 || row == playFieldHeight - 1) cout << "*";
                else if (col == 0 || col == playFieldWidth - 1) cout << "*";
                else if (row == y && col == x) cout << "X";
                else if (row == foodPosY && col == foodPosX) cout << "O";
                else {
                    bool showSpace = true; // is there a better way of doing this? This feels sloppy
                    for (int body = 1; body < (currentScore+10)/10; body++) {
                        if (snakeBodyX[body] == col && snakeBodyY[body] == row) {
                            cout << "X";
                            showSpace = false;
                        }
                    }
                    if (showSpace) {
                        cout << " ";
                    }
                }
            }
            setScoreBoard(row);
            cout << endl;
        }
    }

    void setScoreBoard(int row) { // is there a more efficient way of doing this? I couldn't think of one.
        if (row == 1) cout << setw(22) << "Current Score:" << setw(13) << currentScore;
        if (row == 2) cout << setw(26) << "Until High Score: " << setw(9) << tillHighScore; 
        if (row == 5) cout << setw(35) << "Top Scores                 ";
        if (row == 6) cout << setw(35) << "===========================";
        if (row == 7) cout << setw(17) << "1st Place" << setw(18) << score[0];
        if (row == 8) cout << setw(17) << "2nd Place" << setw(18) << score[1];
        if (row == 9) cout << setw(17) << "3rd Place" << setw(18) << score[2];
        if (row == 12) cout << setw(35) << "Current Session            ";
        if (row == 13) cout << setw(35) << "===========================";
        if (row == 14) cout << setw(21) << "Games Played:" << setw(14) << gamesPlayed;
        if (row == 15) cout << setw(21) << "Current Best:" << setw(14) << currentBest; 
    }

    void getSnakeMovement() { 
        if (dir == LEFT) x--;
        else if (dir == RIGHT) x++;
        else if (dir == UP) y--;
        else if (dir == DOWN) y++;
        else return;
    }

    void playAgain() { // is there a better way of doing this? 
        x = playFieldWidth / 2;
        y = playFieldHeight / 2;
        gamesPlayed++;
        resetSnakeBody();
        updateFoodPOS();
        updateCurrentBest();
        updateScoreBoard();
        currentScore = 0;
        isAlive = true;
        playGame();
    }


    void playGame() { 
        while (isAlive) {
            setPlayField();
            getKeyStroke();
            getSnakeMovement();
            getSnakeBody();
            getSnakeCondition();
            if (!isAlive) playAgain(); // currently not a boolean, just takes true for testing reasons
            Sleep(100);         
        }
    }
};

int main() { // was always taught it was a good practice from my professor to keep main as minimal and clean as possible.
    // system("cls");

    srand(time(NULL));

    playSnake play;
    play.playGame();

    system("PAUSE");

    std::cin.get();
    return 0;
}



