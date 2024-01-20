#include <C:\Users\Admin\Personal_Projects\Immediate\Snake_Game\Snake_Game\Snake_Game.h>
static bool isLose = 0;
static int score = 0;
static char direction = '\0';
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
int Snake::getX(int i){
    return this->snakeCoor[i]->x;
}
int Snake::getY(int i){
    return this->snakeCoor[i]->y;
}

/**
 * !IMPLEMENT BOUNDER
 * ------------------------------------------
 */
void Bounder::setWidth(int diff){
    switch(diff){
        case 1:
            this->width = 10;
            break;
        case 2:
            this->width = 20;
            break;
        case 3:
            this->width = 30;
            break;
        default:
            cout << "Invalid numbers" << endl;
    }
    return;
}
int Bounder::getWidth(){
    return this->width;
}
void Bounder::setLength(int diff)
{
    switch (diff)
    {
    case 1:
        this->length = 10;
        break;
    case 2:
        this->length = 20;
        break;
    case 3:
        this->length = 30;
        break;
    default:
        cout << "Invalid numbers" << endl;
    }
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
void Implementation::setScore(int i){
    this->Score = score;
    return;
}
int Implementation::getScore(){
    return this->Score;
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
    int diff = 0;
    cout << "Choose your own level. \n"
         << "- Level 1: Easy \n"
         << "- Level 2: Immediate\n"
         << "- Level 3: Hard\n"
         << endl;
    cin >> diff;
    this->levelDiff = diff;
    this->bounder->setLength(diff);
    this->bounder->setWidth(diff);

    return;
}
void Implementation::run(){

}
Implementation::Implementation(){
    this->snake = new Snake;
    this->bounder = new Bounder;
}
int main(){
    Implementation *implementation = new Implementation();
    implementation->askUserName();
    implementation->setDifficulty();
    implementation->setScore(0); //*FIRST SET SCORE = 0;

    while(!isLose){
        implementation->run();
    }
    return 0;
}