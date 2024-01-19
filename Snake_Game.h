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
        Coordinate *snakeCoor;

    public:
        void setLength();
        int getLength();
        int getX();
        int getY();
};

class Bounder{
    private:
        int width;
        int length;
        Coordinate *boundLimit;

    public:
        void setWidth();
        int getWidth();
        void setLength();
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
        void setScore();
        int getScore();
        void askUserName();
        void setDifficulty();
        void run();
};
