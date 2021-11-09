#include <iostream>
#include "../include/TileSet.h"

using std::cout;
using std::string;

TileSet::TileSet(int tile_width, int tile_height, string file) : tile_width(tile_width), tile_height(tile_height)
{

  GameObject *go = new GameObject();

  tile_set = new Sprite(*go, file);
  if (tile_set != nullptr)
  {
    cout << "abrimos o sprite do tileset\n";
    columns = ((tile_set->GetWidth()) / tile_width);
    rows = ((tile_set->GetHeight()) / tile_height);
    cout << "columns: " << columns << "\n rows:" << rows << "\n";
  }
}

void TileSet::RenderTile(unsigned int index, float x, float y)
{
  int numberTiles = columns * rows;
  if ((index >= 0) && (index < numberTiles))
  {
    int leftx = (index % columns) * tile_width;
    int lefty = (index / columns) * tile_height;
    tile_set->SetClip(leftx, lefty, tile_width, tile_height);
    tile_set->Render(x, y);
  }
}

int TileSet::GetTileHeight()
{
  return tile_height;
}
int TileSet::GetTileWidth()
{
  return tile_width;
}