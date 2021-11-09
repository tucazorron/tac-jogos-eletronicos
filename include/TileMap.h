#ifndef _TILEMAP_H_
#define _TILEMAP_H_

#include <iostream>
#include <vector>
#include "Component.h"
#include "Sprite.h"
#include "TileSet.h"

using std::string;
using std::vector;

class TileMap : public Component
{
public:
  TileMap(GameObject &associated, string file, TileSet *tile_set);
  int &At(int x, int y, int z = 0);
  int GetDepth();
  int GetHeight();
  int GetWidth();
  void Load(string file);
  void Render();
  void RenderLayer(int layer, int x_camera = 0, int y_camera = 0);
  void SetTileSet(TileSet *tile_set);

private:
  int map_depth;
  int map_height;
  int map_width;
  vector<int> tile_matrix;
  TileSet *tile_set;
};

#endif