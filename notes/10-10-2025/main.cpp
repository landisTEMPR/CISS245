#include <iostream>
#include <chrono>
#include <thread>
#include <iomanip>

int main()
{
    for (int i = 0; i < 10; ++i)
    {
        
        std::this_thread::sleep_for(std::chrono::seconds(1));
        std::cout << "LOADING: [";
        for (int j = 0; j < i + 1; ++j)
        {
            std::cout << '*';
            system("clear");
        }
        std::cout << std::setw(10 - i) << ']' << ' ' << i << " MB\n";
    }
    return 0;
}
