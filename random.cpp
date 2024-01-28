#include <iostream>
#include <cstdlib>
#include <ctime>

int main()
{
    std::srand(std::time(0)); // Khởi tạo seed dựa trên thời gian hiện tại

    int random_number = std::rand() % 20 + 1; // Số ngẫu nhiên từ 1 đến 20
    std::cout << "Số ngẫu nhiên từ 1 đến 20: " << random_number << std::endl;

    return 0;
}