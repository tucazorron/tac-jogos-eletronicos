#ifndef _RESOURCES_H_
#define _RESOURCES_H_

#include <iostream>
#include <unordered_map>
#include "SDL2/SDL_image.h"
#include "SDL2/SDL_mixer.h"
#include "Sprite.h"

using std::string;
using std::unordered_map;

class Resources
{
public:
  static void ClearImages();
  static void ClearMusics();
  static void ClearSounds();
  static SDL_Texture *GetImage(string file);
  static Mix_Music *GetMusic(string file);
  static Mix_Chunk *GetSound(string file);
  static SDL_Texture *createTexture(string file);

private:
  static unordered_map<string, SDL_Texture *> imageTable;
  static unordered_map<string, Mix_Music *> musicTable;
  static unordered_map<string, Mix_Chunk *> soundTable;
};

#endif