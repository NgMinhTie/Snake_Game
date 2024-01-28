#include <C:\Users\Admin\Personal_Projects\Immediate\Snake_Game\Snake_Game\Snake_Game.h>
static bool isLose = 0;
static int score = 0;
static char direction = '\0';
static char **coor;
static int setupSuccess = 0;
static bool ate = false;
static bool entered = false;
const int MAXSIZE = 150;
enum Direction
{
    LEFT = 0,
    RIGHT,
    UP,
    DOWN,
    STAY
};
static Direction direct;
/**
 * !IMPLEMENT SNAKE
 * ------------------------------------------
 */
Snake::Snake() : length(0){}
void Snake::setUpCoor(int row, int column){
    pair<int, int> temp;
    if(this->myvector.empty())
    {
        coor[row][column] = '0';
        temp.first = row;
        temp.second = column;
        myvector.push_back(temp);
        //cout << temp.first << " " << temp.second << endl;
    }
    return;
}
void Snake::setLength(){
    return;
}
int Snake::getLength(){
    return this->length;
}
void Snake::move(){
    if(myvector.empty())
        return;
    ////bool eat = false;
    pair<int, int> front = myvector.front();
    if (direct == UP)
    {
        front.first-=1;
    }
    else if (direct == DOWN)
    {
        front.first+=1;
    }
    else if (direct == LEFT)
    {
        front.second-=1;
    }
    else if (direct == RIGHT)
    {
        front.second+=1;
    }
    else
        return;

    //**************************************************
    //*check the snake eat itselt or meet the wall or not
    //***************************************************
    if ((coor[front.first][front.second] == '0' || coor[front.first][front.second] =='*')&&entered)
    {
        cout << "Game Over!";
        isLose = 1;
        return;
    }
    if (coor[front.first][front.second]== '*'){
        ate = true;
    }

    if(ate == true){
        myvector.insert(myvector.begin(), front);
        coor[front.first][front.second] = '0';
    }
    else {
        myvector.insert(myvector.begin(), front);
        coor[front.first][front.second] = '0';
        pair<int, int> last = myvector.back();
        myvector.pop_back();
        coor[last.first][last.second] = '\0';
    }
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
    if(ate == false)
        return;
    int row = this->bounder->getLength();
    int column = this->bounder->getWidth();
    std::srand(std::time(0));

    int random_Row = std::rand() % (row - 1) + 1;
    int random_Column = std::rand() % ((column - 1) * 2) + 1;

    while (coor[random_Row][random_Column] == '0' || coor[random_Row][random_Column] == '#')
    {
        random_Row = std::rand() % (row) + 1;
        random_Column = std::rand() % ((column - 1) * 2) + 1;
    }
    coor[random_Row][random_Column] = '*';
    ate = false;
    return;
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
void Implementation::enterKey(){
    char direction = ' ';

        if (_kbhit())
        { // Kiểm tra xem có ký tự trong buffer đầu vào không
            direction = _getch();
            if (direction == 'w')
            {
                direct = UP;
            }
            else if (direction == 's')
            {
                direct = DOWN;
            }
            else if (direction == 'a')
            {
                direct = LEFT;
            }
            else if (direction == 'd')
            {
                direct = RIGHT;
            }
        }
}
void Implementation::run(){
    //this->bounder->printBounder();
    //this->bounder->setupBounder();
    this->snake->setUpCoor(this->bounder->getLength()/2 , (this->bounder->getWidth()*2)/2);
    this->setFood();
    this->enterKey();
    this->snake->move();
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
    direct = STAY;
    while(!isLose){
        implementation->run();
        Sleep(250);
        system("cls");
        
    }
    system("cls");
    if(isLose)
        cout << "-------------YOU LOSE------------" << endl;
    return 0;
}