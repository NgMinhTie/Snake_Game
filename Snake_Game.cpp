#include <C:\Users\Admin\Personal_Projects\Immediate\Snake_Game\Snake_Game\Snake_Game.h>

enum Direction
{
    LEFT = 0,
    RIGHT,
    UP,
    DOWN
};
/**
 * !IMPLEMENT SNAKE
 * ------------------------------------------
 */
void Snake::setLength(){
    return;
}
int Snake::getLength(){
    return this->length;
}
int Snake::getX(){
    return this->snakeCoor->x;
}
int Snake::getY(){
    return this->snakeCoor->y;
}

/**
 * !IMPLEMENT BOUNDER
 * ------------------------------------------
 */
void Bounder::setWidth(){
    return;
}
int Bounder::getWidth(){
    return this->width;
}
void Bounder::setLength()
{
    return;
}
int Bounder::getLength()
{
    return this->length;
}
int Bounder::getXLimit(){
    return this->boundLimit->x;
}
int Bounder::getYLimit()
{
    return this->boundLimit->y;
}

/**
 * !IMPLEMENT IMPLEMENTATION
 * ------------------------------------------
 */
void Implementation::setScore(){
    return;
}
int Implementation::getScore(){
    return 0;
}
void Implementation::askUserName(){
    cout << "Please Enter Your Name: " << endl;
    string name;
    cin >> name;
    this->Username = name;
    return;
}
void Implementation::setDifficulty()
{
    return;
}
void Implementation::run(){

}

int main(){
    Implementation *implementation = new Implementation();
    implementation->askUserName();
    implementation->setDifficulty();

    return 0;
}