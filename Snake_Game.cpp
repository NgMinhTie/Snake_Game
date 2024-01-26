#include <C:\Users\Admin\Personal_Projects\Immediate\Snake_Game\Snake_Game\Snake_Game.h>
static bool isLose = 0;
static int score = 0;
static char direction = '\0';
static char **coor;
static int setupSuccess = 0;
const int MAXSIZE = 150;
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
void Snake::setUpCoor(int row, int column){
    
    coor[row][column] = '0';
}
void Snake::setLength(){
    return;
}
int Snake::getLength(){
    return this->length;
}
void Snake::setX(int i){

}
void Snake::setY(int i){

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
void setUpCoor(int length, int width){
    coor = new char*[length];
    for (int i = 0; i < length;i++){
        coor[i] = new char[width * 2];
    }
}
void Bounder::setupBounder(){
    //setUpCoor(this->length, this->width * 2);
    if (setupSuccess == 1)
        return;
    for (int i = 0; i < this->length; i++)
    {
        if(i==0||i==this->length-1){
            for (int j = 0; j < this->width * 2;j++){
                coor[i][j] = '#';
            }
        }
        else{
            for (int j = 0; j < this->width * 2;j++){
                if(j==0||j==this->width*2-1)
                    coor[i][j] = '#';
                else
                    coor[i][j] = ' ';
            }
        }
    }
    setupSuccess = 1;

   
}
void Bounder :: printBounder(){
    //*PRINT

    for (int i = 0; i < this->length; i++)
    {
        for (int j = 0; j < this->width * 2; j++)
        {
            cout << coor[i][j];
        }
        cout << endl;
    }
    return;
}
/**
 * !IMPLEMENT IMPLEMENTATION
 * ------------------------------------------
 */
void Implementation::setFood(){
    int row = this->bounder->getLength();
    int column = this->bounder->getWidth();
    std::random_device rd;
    std::mt19937 generator(rd());
    std::uniform_int_distribution<int> distributionRow(1, row);
    std::uniform_int_distribution<int> distributionColumn(1, column * 2 - 1);
    int randomRow = distributionRow(generator);
    int randomColum = distributionColumn(generator);

    while(coor[randomRow][randomColum]=='0'){
        randomRow = distributionRow(generator);
        randomColum = distributionColumn(generator);
    }
    coor[randomRow][randomColum] = '#';
}

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
Snake* Implementation::getSnake(){
    return this->snake;
}
Bounder* Implementation::getBounder(){
    return this->bounder;
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
void Implementation::printInfo(){
    cout << "\nYour Username is: " << this->Username 
         << "\nThe Score you achieve is: " << score
         <<"/" << MAXSIZE << endl;
}
void Implementation::run(){
    //this->bounder->printBounder();
    //this->bounder->setupBounder();
    this->snake->setUpCoor(3, 2);
    this->snake->setUpCoor(3, 3);
    this->setFood();
    this->bounder->printBounder();
    this->printInfo();
}
Implementation::Implementation(){
    this->snake = new Snake;
    this->bounder = new Bounder;
}
int main(){
    Implementation *implementation = new Implementation();
    implementation->askUserName();
    implementation->setDifficulty();
    setUpCoor(implementation->getBounder()->getLength(), implementation->getBounder()->getWidth() * 2);
    implementation->getBounder()->setupBounder();
    implementation->setScore(0); //*FIRST SET SCORE = 0;
    while(!isLose){
        implementation->run();
        system("cls");
    }
    return 0;
}