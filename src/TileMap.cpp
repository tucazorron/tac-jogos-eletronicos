#include <fstream>
#include <sstream>
#include "../include/TileMap.h"
#include "../include/Camera.h"

using std::cout;
using std::endl;

TileMap::TileMap(GameObject &associated, string file, TileSet *tile_set) : Component(associated)
{
  Load(file);
  SetTileSet(tile_set);
}

void removeSpaceBeginEnd(string &line)
{
  string regex = " \n\t\f\v\r";
  size_t lineposition;
  lineposition = line.find_first_not_of(regex);
  if (lineposition <= line.length())
  {
    line.erase(0, lineposition);
  }
  lineposition = (line.find_last_not_of(regex)) + 1;
  if (lineposition <= line.length())
  {
    line.erase(lineposition, string::npos);
  }
}
void splitToVector1(string line, vector<int> &tokens)
{
  string regex = " \n\t\f\v\r";
  size_t lineposition = line.find_first_not_of(regex);

  if (lineposition <= line.length())
  {

    istringstream auxstring(line);
    string token;
    int auxint;
    while (getline(auxstring, token, ','))
    {
      auxint = atoi(token.c_str());
      tokens.push_back(auxint);
    }
  }
}
void splitToVector(string line, vector<int> &tokens)
{

  istringstream auxstring(line);
  string token;
  int auxint;
  while (getline(auxstring, token, ','))
  {
    auxint = atoi(token.c_str());
    auxint--;
    tokens.push_back(auxint);
  }
}

void TileMap::Load(string file)
{
  ifstream mapfile;
  mapfile.open(file);
  int numberline = 1;
  string linha;
  if (!mapfile.is_open())
  {
    cout << "Unable to open map file." << endl;
  }
  else
  {
    while (getline(mapfile, linha))
    {
      vector<int> tokens;
      removeSpaceBeginEnd(linha);

      if (numberline == 1)
      {
        splitToVector1(linha, tokens);

        map_width = tokens[0];
        map_height = tokens[1];
        map_depth = tokens[2];
        cout << "vetor\n";
        for (auto t : tokens)
        {
          cout << t << "\n";
        }
      }
      else
      {
        if (linha.empty())
        {
          cout << "linha vazia\n";
        }
        else
        {
          cout << "marcador\n";
          splitToVector(linha, tokens);
          for (auto t : tokens)
          {
            tile_matrix.push_back(t);
          }
          cout << "matriz: ";
          for (auto m : tile_matrix)
          {
            cout << m << " ";
          }
        }
      }
      numberline++;
    }
    mapfile.close();
  }
}

void TileMap::SetTileSet(TileSet *tile_set)
{
  this->tile_set = tile_set;
}

int &TileMap::At(int x, int y, int z)
{
  int area = map_width * map_height;
  int profundidade = z * area;
  int index = x + (y * map_width) + profundidade;
  return tile_matrix[index];
}

void TileMap::RenderLayer(int layer, int cameraX, int cameraY)
{
  int width = GetWidth();
  int height = GetHeight();
  for (int i = 0; i < width; i++)
  {
    for (int j = 0; j < height; j++)
    {
      int tile_matrix_index = At(i, j, layer);
      int tilex = i * (tile_set->GetTileWidth());
      int tiley = j * (tile_set->GetTileHeight());
      tile_set->RenderTile(tile_matrix_index, ((tilex) - (cameraX * (layer + 1))), (tiley - (cameraY * (layer + 1))));
    }
  }
}

void TileMap::Render()
{
  int dep = GetDepth();
  int x = Camera::pos.x;
  int y = Camera::pos.y;
  for (int layer = 0; layer < dep; layer++)
  {
    RenderLayer(layer, x, y);
  }
}

int TileMap::GetWidth()
{
  return this->map_width;
}

int TileMap::GetHeight()
{
  return this->map_height;
}

int TileMap::GetDepth()
{

  return this->map_depth;
}
