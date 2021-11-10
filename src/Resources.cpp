#include "../include/Resources.h"
#include "../include/Game.h"

using std::cout;
using std::endl;
using std::string;
using std::unordered_map;

unordered_map<std::string, SDL_Texture *> Resources::imageTable;
unordered_map<std::string, Mix_Music *> Resources::musicTable;
unordered_map<std::string, Mix_Chunk *> Resources::soundTable;

SDL_Texture *Resources::createTexture(string file)
{
  SDL_Renderer *renderer = Game::GetInstance().GetRenderer();
  SDL_Texture *texture = nullptr;
  texture = IMG_LoadTexture(renderer, file.c_str());
  if (texture == nullptr)
  {
    cout << "Error while creating texture: " << SDL_GetError() << endl;
  }

  return texture;
}

SDL_Texture *Resources::GetImage(string file)
{
  if (imageTable.find(file) == imageTable.end())
  {
    SDL_Texture *texture = createTexture(file);

    if (texture == nullptr)
    {
      cout << "Error while creating image: " << SDL_GetError() << endl;
      exit(EXIT_FAILURE);
    }
    else
    {
      imageTable[file] = texture;
    }
    return texture;
  }
  else
  {
    return imageTable[file];
  }
}

Mix_Chunk *Resources::GetSound(string file)
{
  if (soundTable.find(file) == soundTable.end())
  {
    Mix_Chunk *chunk = Mix_LoadWAV(file.c_str());

    if (chunk == nullptr)
    {
      cout << "Erro ao criar som: " << SDL_GetError() << endl;
      exit(EXIT_FAILURE);
    }
    else
    {
      soundTable[file] = chunk;
    }
  }
  return soundTable[file];
}

Mix_Music *Resources::GetMusic(string file)
{
  if (musicTable.find(file) == musicTable.end())
  {
    Mix_Music *music = Mix_LoadMUS(file.c_str());

    if (music == nullptr)
    {
      cout << "Erro while creating music: " << SDL_GetError() << endl;
      exit(EXIT_FAILURE);
    }
    else
    {
      musicTable[file] = music;
    }
    return musicTable[file];
  }
  else
  {
    return musicTable[file];
  }
}

void Resources::ClearImages()
{
  for (auto im : imageTable)
  {
    SDL_DestroyTexture(im.second);
  }

  imageTable.clear();
}

void Resources::ClearMusics()
{
  for (auto mus : musicTable)
  {
    Mix_FreeMusic(mus.second);
  }

  musicTable.clear();
}

void Resources::ClearSounds()
{
  for (auto sound : soundTable)
  {
    Mix_FreeChunk(sound.second);
  }

  soundTable.clear();
}