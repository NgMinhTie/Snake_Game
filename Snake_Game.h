#include <iostream>
#include <string>
#include <windows.h>
#include <random>
#include<ctime>
#include<conio.h>
#include<thread>
#include<vector>
#include<utility>
#include<queue>

using namespace std;

struct Coordinate{
    int x, y;
};

class Snake{
    private:
        int length;
        Coordinate **snakeCoor;
        ////pair<int, int> *myCoor;
        vector<pair<int, int>> myvector;

    public:
        Snake();
        void setLength();
        int getLength();
        //void setX(int i);
        //void setY(int i);
        void setUpCoor(int row, int column);
        void move();
        bool win();
};

class Bounder{
    private:
        int width;
        int length;

    public:
        void setWidth(int diff);
        int getWidth();
        void setLength(int diff);
        int getLength();
        void setupBounder();
        void printBounder();
};

class Implementation{
    private:
        Snake *snake;
        Bounder *bounder;
        int Score;
        string Username;
        int levelDiff;

    public:
        Implementation();
        void setScore(int i);
        int getScore();
        void askUserName();
        void setDifficulty();
        void run();
        void printInfo();
        void setFood();
        void enterKey();
        Snake *getSnake();
        Bounder *getBounder();
};
