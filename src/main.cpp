#include "../include/game.hpp"

int main()
{
    Game game = Game::GetInstance();
    game.Run();
    game.~Game();
}