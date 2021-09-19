#include "../include/Game.h"

int main()
{
    Game game = Game::GetInstance();
    game.Run();
    game.~Game();
}