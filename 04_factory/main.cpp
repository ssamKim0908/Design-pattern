#include "../pch.hpp"
#include "pattern.hpp"

int main() 
{
    unique_ptr<ACharacter> ch = make_unique<gunner>();
    cout << "my weapon damage: " << ch->shoot() << endl;
    return 0;
}