#include "../common_header.hpp"
#include "pattern.hpp"

#include <fstream>

int main() 
{
    std::ifstream file{"/proc/self/status"};
    if(file.is_open())
    {
        std::string line;
        while(getline(file, line))
        {
            cout << line << endl;
        }

        file.close();
    }
    return 0;
}