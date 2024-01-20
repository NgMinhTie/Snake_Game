#include <iostream>
#include <string>
#include <windows.h>

using namespace std;

struct Coordinate{
    int x, y;
};
class Snake{
    private:
        int length;
        Coordinate *snakeCoor[50];

    public:
        void setLength();
        int getLength();
        int getX(int i);
        int getY(int i);
};

class Bounder{
    private:
        int width;
        int length;
        Coordinate *boundLimit;

    public:
        void setWidth(int diff);
        int getWidth();
        void setLength(int diff);
        int getLength();
        int getXLimit();
        int getYLimit();
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
};
