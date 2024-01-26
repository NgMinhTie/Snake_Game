#include <iostream>
#include <cstdlib>
#include <ctime>

int main()
{
    std::srand(std::time(0)); // Khởi tạo seed dựa trên thời gian hiện tại

    // Tiếp tục sử dụng hàm rand() để tạo số ngẫu nhiên
    int random_number = std::rand();
    std::cout << "Số ngẫu nhiên: " << random_number << std::endl;

    return 0;
}