#ifndef _TILESET_H_
#define _TILESET_H_

#include <iostream>
#include "Sprite.h"

using std::string;

class TileSet
{
public:
  TileSet(int tile_width, int tile_height, string file);
  int GetTileHeight();
  int GetTileWidth();
  void RenderTile(unsigned index, float x, float y);

private:
  int rows;
  int columns;
  int tile_height;
  int tile_width;
  Sprite *tile_set;
};

#endif