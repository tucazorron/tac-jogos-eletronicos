#include <fstream>
#include <sstream> // std::istringstream
#include "../include/TileMap.h"

using namespace std;

TileMap::TileMap(GameObject &associated, string file, TileSet *tile_set) : Component(associated)
{
  Load(file);
  SetTileSet(tile_set);
}

void removeSpaceBeginEnd(string &line)
{
  string regex = " \n\t\f\v\r";
  //apaga qualquer coisa antes de uma caractere
  size_t lineposition;
  lineposition = line.find_first_not_of(regex);
  if (lineposition <= line.length())
  {
    line.erase(0, lineposition);
  }
  //acha a ultima coisa que nao é um espaço e apaga a partir daí
  lineposition = (line.find_last_not_of(regex)) + 1;
  if (lineposition <= line.length())
  {
    line.erase(lineposition, string::npos);
  }
}
void splitToVector1(string line, vector<int> &tokens)
{
  string regex = " \n\t\f\v\r"; //acha o primeiro que não for espaço
  size_t lineposition = line.find_first_not_of(regex);

  if (lineposition <= line.length())
  { //se a linha tiver algum caractere

    istringstream auxstring(line);
    string token;
    int auxint;
    cout << "Lendo o mapa: \n";
    while (getline(auxstring, token, ','))
    {
      cout << token << " foi o token\n";
      if (token == "\n")
      {
        cout << "ola\n";
        // getchar();
      }
      auxint = atoi(token.c_str());
      cout << auxint << "\n";
      tokens.push_back(auxint);
    }
  }
}
void splitToVector(string line, vector<int> &tokens)
{
  // cout<<"entrou\n";
  // getchar();

  istringstream auxstring(line);
  string token;
  int auxint;
  cout << "Lendo o mapa: \n";
  while (getline(auxstring, token, ','))
  {
    auxint = atoi(token.c_str());
    auxint--;
    // cout<<auxint<<"\n";
    tokens.push_back(auxint);
  }
}

void TileMap::Load(string file)
{
  ifstream mapfile; //arquivo original, leitura
  mapfile.open(file);
  int numberline = 1;
  string linha;
  if (!mapfile.is_open())
  {
    cout << "Não foi possível abrir o arquivo de mapa \n";
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
        // getchar();
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
          // getchar();
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
  int width = map_width;
  int height = map_height;
  //pra cada linha em cada coluna
  for (int i = 0; i < width; i++)
  {
    for (int j = 0; j < height; j++)
    {
      int tile_matrixindex = At(i, j, layer); //onde i é horizontal, j é vertical, e layer é prfundidae
      //renderizar a tile
      int tilex = i * (tile_set->GetTileWidth());
      int tiley = j * (tile_set->GetTileHeight());
      tile_set->RenderTile(tile_matrixindex, tilex, tiley);
    }
  }
}

void TileMap::Render()
{
  // cout<<"\n renderizando o mapa\n";
  for (int layer = 0; layer < map_depth; layer++)
  {
    RenderLayer(layer);
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
