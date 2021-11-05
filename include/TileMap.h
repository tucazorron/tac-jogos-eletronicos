#ifndef _TILEMAP_H_
#define _TILEMAP_H_

#include "Sprite.h"
#include "TileSet.h"
#include <vector>
#include <iostream>
#include "Component.h"

using std::string;
using std::vector;

class TileMap : public Component
{
public:
  TileMap(GameObject &associated, string file, TileSet *tileSet);
  void Load(string file);
  void SetTileSet(TileSet *tileSet);
  int &At(int x, int y, int z = 0);
  void Render();
  void RenderLayer(int layer, int cameraX = 0, int cameraY = 0);
  int GetWidth();
  int GetHeight();
  int GetDepth();

private:
  vector<int> tileMatrix;
  TileSet *tileSet;
  int mapWidth;
  int mapHeight;
  int mapDepth;
};

#endif