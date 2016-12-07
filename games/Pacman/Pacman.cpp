#include <stdlib.h>
#include "Pacman.hh"

Pacman::Pacman(enum Status *s, int *k, char **m)
{
  state = s;
  keyPressed = k;
  map = m;
  size = 0;
  eat = false;
  pac[0] = 13;
  pac[1] = 9;
  gMove = 0;
  enemy1[0] = 10;
  enemy1[1] = 9;
  enemy2[0] = 11;
  enemy2[1] = 9;
  enemy3[0] = 11;
  enemy3[1] = 8;
  enemy4[0] = 11;
  enemy4[1] = 10;
  dir1 = ArcadeKey::UP;
  dir2 = ArcadeKey::UP;
  dir3 = ArcadeKey::RIGHT;
  dir4 = ArcadeKey::UP;
  old1 = ArcadeTile::DEFAULT;
  old2 = ArcadeTile::DEFAULT;
  old3 = ArcadeTile::DEFAULT;
  old4 = ArcadeTile::DEFAULT;
  map[0][0] = ArcadeTile::WALL;
  map[1][0] = ArcadeTile::WALL;
  map[2][0] = ArcadeTile::WALL;
  map[3][0] = ArcadeTile::WALL;
  map[4][0] = ArcadeTile::WALL;
  map[5][0] = ArcadeTile::WALL;
  map[6][0] = ArcadeTile::WALL;
  map[7][0] = ArcadeTile::WALL;
  map[8][0] = ArcadeTile::DEFAULT;
  map[9][0] = ArcadeTile::WALL;
  map[10][0] = ArcadeTile::FOOD1;
  map[11][0] = ArcadeTile::WALL;
  map[12][0] = ArcadeTile::DEFAULT;
  map[13][0] = ArcadeTile::DEFAULT;
  map[14][0] = ArcadeTile::WALL;
  map[15][0] = ArcadeTile::WALL;
  map[16][0] = ArcadeTile::WALL;
  map[17][0] = ArcadeTile::WALL;
  map[18][0] = ArcadeTile::WALL;
  map[19][0] = ArcadeTile::WALL;
  map[20][0] = ArcadeTile::WALL;
  map[21][0] = ArcadeTile::WALL;
  map[22][0] = ArcadeTile::WALL;
  map[23][0] = ArcadeTile::DEFAULT;
  map[0][1] = ArcadeTile::WALL;
  map[1][1] = ArcadeTile::FOOD1;
  map[2][1] = ArcadeTile::FOOD1;
  map[3][1] = ArcadeTile::FOOD2;
  map[4][1] = ArcadeTile::FOOD1;
  map[5][1] = ArcadeTile::FOOD1;
  map[6][1] = ArcadeTile::FOOD1;
  map[7][1] = ArcadeTile::WALL;
  map[8][1] = ArcadeTile::DEFAULT;
  map[9][1] = ArcadeTile::WALL;
  map[10][1] = ArcadeTile::FOOD1;
  map[11][1] = ArcadeTile::WALL;
  map[12][1] = ArcadeTile::DEFAULT;
  map[13][1] = ArcadeTile::DEFAULT;
  map[14][1] = ArcadeTile::WALL;
  map[15][1] = ArcadeTile::FOOD1;
  map[16][1] = ArcadeTile::FOOD1;
  map[17][1] = ArcadeTile::FOOD2;
  map[18][1] = ArcadeTile::WALL;
  map[19][1] = ArcadeTile::FOOD1;
  map[20][1] = ArcadeTile::FOOD1;
  map[21][1] = ArcadeTile::FOOD1;
  map[22][1] = ArcadeTile::WALL;
  map[23][1] = ArcadeTile::DEFAULT;
  map[0][2] = ArcadeTile::WALL;
  map[1][2] = ArcadeTile::FOOD1;
  map[2][2] = ArcadeTile::WALL;
  map[3][2] = ArcadeTile::WALL;
  map[4][2] = ArcadeTile::FOOD1;
  map[5][2] = ArcadeTile::WALL;
  map[6][2] = ArcadeTile::FOOD1;
  map[7][2] = ArcadeTile::WALL;
  map[8][2] = ArcadeTile::DEFAULT;
  map[9][2] = ArcadeTile::WALL;
  map[10][2] = ArcadeTile::FOOD1;
  map[11][2] = ArcadeTile::WALL;
  map[12][2] = ArcadeTile::DEFAULT;
  map[13][2] = ArcadeTile::DEFAULT;
  map[14][2] = ArcadeTile::WALL;
  map[15][2] = ArcadeTile::FOOD1;
  map[16][2] = ArcadeTile::WALL;
  map[17][2] = ArcadeTile::FOOD1;
  map[18][2] = ArcadeTile::FOOD1;
  map[19][2] = ArcadeTile::FOOD1;
  map[20][2] = ArcadeTile::WALL;
  map[21][2] = ArcadeTile::FOOD1;
  map[22][2] = ArcadeTile::WALL;
  map[23][2] = ArcadeTile::DEFAULT;
  map[0][3] = ArcadeTile::WALL;
  map[1][3] = ArcadeTile::FOOD1;
  map[2][3] = ArcadeTile::WALL;
  map[3][3] = ArcadeTile::WALL;
  map[4][3] = ArcadeTile::FOOD1;
  map[5][3] = ArcadeTile::WALL;
  map[6][3] = ArcadeTile::FOOD1;
  map[7][3] = ArcadeTile::WALL;
  map[8][3] = ArcadeTile::WALL;
  map[9][3] = ArcadeTile::WALL;
  map[10][3] = ArcadeTile::FOOD1;
  map[11][3] = ArcadeTile::WALL;
  map[12][3] = ArcadeTile::WALL;
  map[13][3] = ArcadeTile::WALL;
  map[14][3] = ArcadeTile::WALL;
  map[15][3] = ArcadeTile::FOOD1;
  map[16][3] = ArcadeTile::WALL;
  map[17][3] = ArcadeTile::WALL;
  map[18][3] = ArcadeTile::WALL;
  map[19][3] = ArcadeTile::FOOD1;
  map[20][3] = ArcadeTile::WALL;
  map[21][3] = ArcadeTile::FOOD1;
  map[22][3] = ArcadeTile::WALL;
  map[23][3] = ArcadeTile::DEFAULT;
  map[0][4] = ArcadeTile::WALL;
  map[1][4] = ArcadeTile::FOOD1;
  map[2][4] = ArcadeTile::FOOD1;
  map[3][4] = ArcadeTile::FOOD1;
  map[4][4] = ArcadeTile::FOOD1;
  map[5][4] = ArcadeTile::FOOD1;
  map[6][4] = ArcadeTile::FOOD1;
  map[7][4] = ArcadeTile::FOOD1;
  map[8][4] = ArcadeTile::FOOD1;
  map[9][4] = ArcadeTile::FOOD1;
  map[10][4] = ArcadeTile::FOOD1;
  map[11][4] = ArcadeTile::FOOD1;
  map[12][4] = ArcadeTile::FOOD1;
  map[13][4] = ArcadeTile::FOOD1;
  map[14][4] = ArcadeTile::FOOD1;
  map[15][4] = ArcadeTile::FOOD1;
  map[16][4] = ArcadeTile::FOOD1;
  map[17][4] = ArcadeTile::FOOD1;
  map[18][4] = ArcadeTile::FOOD1;
  map[19][4] = ArcadeTile::FOOD1;
  map[20][4] = ArcadeTile::WALL;
  map[21][4] = ArcadeTile::FOOD1;
  map[22][4] = ArcadeTile::WALL;
  map[23][4] = ArcadeTile::DEFAULT;
  map[0][5] = ArcadeTile::WALL;
  map[1][5] = ArcadeTile::FOOD1;
  map[2][5] = ArcadeTile::WALL;
  map[3][5] = ArcadeTile::WALL;
  map[4][5] = ArcadeTile::FOOD1;
  map[5][5] = ArcadeTile::WALL;
  map[6][5] = ArcadeTile::WALL;
  map[7][5] = ArcadeTile::WALL;
  map[8][5] = ArcadeTile::WALL;
  map[9][5] = ArcadeTile::WALL;
  map[10][5] = ArcadeTile::FOOD1;
  map[11][5] = ArcadeTile::WALL;
  map[12][5] = ArcadeTile::WALL;
  map[13][5] = ArcadeTile::WALL;
  map[14][5] = ArcadeTile::WALL;
  map[15][5] = ArcadeTile::FOOD1;
  map[16][5] = ArcadeTile::WALL;
  map[17][5] = ArcadeTile::FOOD1;
  map[18][5] = ArcadeTile::WALL;
  map[19][5] = ArcadeTile::WALL;
  map[20][5] = ArcadeTile::WALL;
  map[21][5] = ArcadeTile::FOOD1;
  map[22][5] = ArcadeTile::WALL;
  map[23][5] = ArcadeTile::DEFAULT;
  map[0][6] = ArcadeTile::WALL;
  map[1][6] = ArcadeTile::FOOD1;
  map[2][6] = ArcadeTile::WALL;
  map[3][6] = ArcadeTile::WALL;
  map[4][6] = ArcadeTile::FOOD1;
  map[5][6] = ArcadeTile::FOOD1;
  map[6][6] = ArcadeTile::FOOD1;
  map[7][6] = ArcadeTile::WALL;
  map[8][6] = ArcadeTile::FOOD1;
  map[9][6] = ArcadeTile::FOOD1;
  map[10][6] = ArcadeTile::FOOD1;
  map[11][6] = ArcadeTile::FOOD1;
  map[12][6] = ArcadeTile::FOOD1;
  map[13][6] = ArcadeTile::FOOD1;
  map[14][6] = ArcadeTile::FOOD1;
  map[15][6] = ArcadeTile::FOOD1;
  map[16][6] = ArcadeTile::WALL;
  map[17][6] = ArcadeTile::FOOD1;
  map[18][6] = ArcadeTile::FOOD1;
  map[19][6] = ArcadeTile::FOOD1;
  map[20][6] = ArcadeTile::WALL;
  map[21][6] = ArcadeTile::FOOD1;
  map[22][6] = ArcadeTile::WALL;
  map[23][6] = ArcadeTile::DEFAULT;
  map[0][7] = ArcadeTile::WALL;
  map[1][7] = ArcadeTile::FOOD1;
  map[2][7] = ArcadeTile::WALL;
  map[3][7] = ArcadeTile::WALL;
  map[4][7] = ArcadeTile::FOOD1;
  map[5][7] = ArcadeTile::WALL;
  map[6][7] = ArcadeTile::FOOD1;
  map[7][7] = ArcadeTile::WALL;
  map[8][7] = ArcadeTile::FOOD1;
  map[9][7] = ArcadeTile::WALL;
  map[10][7] = ArcadeTile::WALL;
  map[11][7] = ArcadeTile::WALL;
  map[12][7] = ArcadeTile::WALL;
  map[13][7] = ArcadeTile::FOOD1;
  map[14][7] = ArcadeTile::WALL;
  map[15][7] = ArcadeTile::FOOD1;
  map[16][7] = ArcadeTile::WALL;
  map[17][7] = ArcadeTile::FOOD1;
  map[18][7] = ArcadeTile::WALL;
  map[19][7] = ArcadeTile::FOOD1;
  map[20][7] = ArcadeTile::WALL;
  map[21][7] = ArcadeTile::FOOD1;
  map[22][7] = ArcadeTile::WALL;
  map[23][7] = ArcadeTile::DEFAULT;
  map[0][8] = ArcadeTile::WALL;
  map[1][8] = ArcadeTile::FOOD1;
  map[2][8] = ArcadeTile::FOOD1;
  map[3][8] = ArcadeTile::FOOD1;
  map[4][8] = ArcadeTile::FOOD1;
  map[5][8] = ArcadeTile::WALL;
  map[6][8] = ArcadeTile::FOOD1;
  map[7][8] = ArcadeTile::FOOD1;
  map[8][8] = ArcadeTile::FOOD1;
  map[9][8] = ArcadeTile::WALL;
  map[10][8] = ArcadeTile::DEFAULT;
  map[11][8] = ArcadeTile::DEFAULT;
  map[12][8] = ArcadeTile::WALL;
  map[13][8] = ArcadeTile::FOOD1;
  map[14][8] = ArcadeTile::WALL;
  map[15][8] = ArcadeTile::FOOD1;
  map[16][8] = ArcadeTile::FOOD1;
  map[17][8] = ArcadeTile::FOOD1;
  map[18][8] = ArcadeTile::WALL;
  map[19][8] = ArcadeTile::FOOD1;
  map[20][8] = ArcadeTile::FOOD1;
  map[21][8] = ArcadeTile::FOOD1;
  map[22][8] = ArcadeTile::WALL;
  map[23][8] = ArcadeTile::DEFAULT;
  map[0][9] = ArcadeTile::WALL;
  map[1][9] = ArcadeTile::WALL;
  map[2][9] = ArcadeTile::WALL;
  map[3][9] = ArcadeTile::WALL;
  map[4][9] = ArcadeTile::FOOD1;
  map[5][9] = ArcadeTile::WALL;
  map[6][9] = ArcadeTile::WALL;
  map[7][9] = ArcadeTile::WALL;
  map[8][9] = ArcadeTile::FOOD1;
  map[9][9] = ArcadeTile::DEFAULT;
  map[10][9] = ArcadeTile::DEFAULT;
  map[11][9] = ArcadeTile::DEFAULT;
  map[12][9] = ArcadeTile::WALL;
  map[13][9] = ArcadeTile::FOOD1;
  map[14][9] = ArcadeTile::WALL;
  map[15][9] = ArcadeTile::WALL;
  map[16][9] = ArcadeTile::WALL;
  map[17][9] = ArcadeTile::FOOD1;
  map[18][9] = ArcadeTile::WALL;
  map[19][9] = ArcadeTile::WALL;
  map[20][9] = ArcadeTile::WALL;
  map[21][9] = ArcadeTile::FOOD1;
  map[22][9] = ArcadeTile::WALL;
  map[23][9] = ArcadeTile::DEFAULT;
  map[0][10] = ArcadeTile::WALL;
  map[1][10] = ArcadeTile::FOOD1;
  map[2][10] = ArcadeTile::FOOD1;
  map[3][10] = ArcadeTile::FOOD1;
  map[4][10] = ArcadeTile::FOOD1;
  map[5][10] = ArcadeTile::WALL;
  map[6][10] = ArcadeTile::FOOD1;
  map[7][10] = ArcadeTile::FOOD1;
  map[8][10] = ArcadeTile::FOOD1;
  map[9][10] = ArcadeTile::WALL;
  map[10][10] = ArcadeTile::DEFAULT;
  map[11][10] = ArcadeTile::DEFAULT;
  map[12][10] = ArcadeTile::WALL;
  map[13][10] = ArcadeTile::FOOD1;
  map[14][10] = ArcadeTile::WALL;
  map[15][10] = ArcadeTile::FOOD1;
  map[16][10] = ArcadeTile::FOOD1;
  map[17][10] = ArcadeTile::FOOD1;
  map[18][10] = ArcadeTile::WALL;
  map[19][10] = ArcadeTile::FOOD1;
  map[20][10] = ArcadeTile::FOOD1;
  map[21][10] = ArcadeTile::FOOD1;
  map[22][10] = ArcadeTile::WALL;
  map[23][10] = ArcadeTile::DEFAULT;
  map[0][11] = ArcadeTile::WALL;
  map[1][11] = ArcadeTile::FOOD1;
  map[2][11] = ArcadeTile::WALL;
  map[3][11] = ArcadeTile::WALL;
  map[4][11] = ArcadeTile::FOOD1;
  map[5][11] = ArcadeTile::WALL;
  map[6][11] = ArcadeTile::FOOD1;
  map[7][11] = ArcadeTile::WALL;
  map[8][11] = ArcadeTile::FOOD1;
  map[9][11] = ArcadeTile::WALL;
  map[10][11] = ArcadeTile::WALL;
  map[11][11] = ArcadeTile::WALL;
  map[12][11] = ArcadeTile::WALL;
  map[13][11] = ArcadeTile::FOOD1;
  map[14][11] = ArcadeTile::WALL;
  map[15][11] = ArcadeTile::FOOD1;
  map[16][11] = ArcadeTile::WALL;
  map[17][11] = ArcadeTile::FOOD1;
  map[18][11] = ArcadeTile::WALL;
  map[19][11] = ArcadeTile::FOOD1;
  map[20][11] = ArcadeTile::WALL;
  map[21][11] = ArcadeTile::FOOD1;
  map[22][11] = ArcadeTile::WALL;
  map[23][11] = ArcadeTile::DEFAULT;
  map[0][12] = ArcadeTile::WALL;
  map[1][12] = ArcadeTile::FOOD1;
  map[2][12] = ArcadeTile::WALL;
  map[3][12] = ArcadeTile::WALL;
  map[4][12] = ArcadeTile::FOOD1;
  map[5][12] = ArcadeTile::FOOD1;
  map[6][12] = ArcadeTile::FOOD1;
  map[7][12] = ArcadeTile::WALL;
  map[8][12] = ArcadeTile::FOOD1;
  map[9][12] = ArcadeTile::FOOD1;
  map[10][12] = ArcadeTile::FOOD1;
  map[11][12] = ArcadeTile::FOOD1;
  map[12][12] = ArcadeTile::FOOD1;
  map[13][12] = ArcadeTile::FOOD1;
  map[14][12] = ArcadeTile::FOOD1;
  map[15][12] = ArcadeTile::FOOD1;
  map[16][12] = ArcadeTile::WALL;
  map[17][12] = ArcadeTile::FOOD1;
  map[18][12] = ArcadeTile::FOOD1;
  map[19][12] = ArcadeTile::FOOD1;
  map[20][12] = ArcadeTile::WALL;
  map[21][12] = ArcadeTile::FOOD1;
  map[22][12] = ArcadeTile::WALL;
  map[23][12] = ArcadeTile::DEFAULT;
  map[0][13] = ArcadeTile::WALL;
  map[1][13] = ArcadeTile::FOOD1;
  map[2][13] = ArcadeTile::WALL;
  map[3][13] = ArcadeTile::WALL;
  map[4][13] = ArcadeTile::FOOD1;
  map[5][13] = ArcadeTile::WALL;
  map[6][13] = ArcadeTile::WALL;
  map[7][13] = ArcadeTile::WALL;
  map[8][13] = ArcadeTile::WALL;
  map[9][13] = ArcadeTile::WALL;
  map[10][13] = ArcadeTile::FOOD1;
  map[11][13] = ArcadeTile::WALL;
  map[12][13] = ArcadeTile::WALL;
  map[13][13] = ArcadeTile::WALL;
  map[14][13] = ArcadeTile::WALL;
  map[15][13] = ArcadeTile::FOOD1;
  map[16][13] = ArcadeTile::WALL;
  map[17][13] = ArcadeTile::FOOD1;
  map[18][13] = ArcadeTile::WALL;
  map[19][13] = ArcadeTile::WALL;
  map[20][13] = ArcadeTile::WALL;
  map[21][13] = ArcadeTile::FOOD1;
  map[22][13] = ArcadeTile::WALL;
  map[23][13] = ArcadeTile::DEFAULT;
  map[0][14] = ArcadeTile::WALL;
  map[1][14] = ArcadeTile::FOOD1;
  map[2][14] = ArcadeTile::FOOD1;
  map[3][14] = ArcadeTile::FOOD1;
  map[4][14] = ArcadeTile::FOOD1;
  map[5][14] = ArcadeTile::FOOD1;
  map[6][14] = ArcadeTile::FOOD1;
  map[7][14] = ArcadeTile::FOOD1;
  map[8][14] = ArcadeTile::FOOD1;
  map[9][14] = ArcadeTile::FOOD1;
  map[10][14] = ArcadeTile::FOOD1;
  map[11][14] = ArcadeTile::FOOD1;
  map[12][14] = ArcadeTile::FOOD1;
  map[13][14] = ArcadeTile::FOOD1;
  map[14][14] = ArcadeTile::FOOD1;
  map[15][14] = ArcadeTile::FOOD1;
  map[16][14] = ArcadeTile::FOOD1;
  map[17][14] = ArcadeTile::FOOD1;
  map[18][14] = ArcadeTile::FOOD1;
  map[19][14] = ArcadeTile::FOOD1;
  map[20][14] = ArcadeTile::WALL;
  map[21][14] = ArcadeTile::FOOD1;
  map[22][14] = ArcadeTile::WALL;
  map[23][14] = ArcadeTile::DEFAULT;
  map[0][15] = ArcadeTile::WALL;
  map[1][15] = ArcadeTile::FOOD1;
  map[2][15] = ArcadeTile::WALL;
  map[3][15] = ArcadeTile::WALL;
  map[4][15] = ArcadeTile::FOOD1;
  map[5][15] = ArcadeTile::WALL;
  map[6][15] = ArcadeTile::FOOD1;
  map[7][15] = ArcadeTile::WALL;
  map[8][15] = ArcadeTile::WALL;
  map[9][15] = ArcadeTile::WALL;
  map[10][15] = ArcadeTile::FOOD1;
  map[11][15] = ArcadeTile::WALL;
  map[12][15] = ArcadeTile::WALL;
  map[13][15] = ArcadeTile::WALL;
  map[14][15] = ArcadeTile::WALL;
  map[15][15] = ArcadeTile::FOOD1;
  map[16][15] = ArcadeTile::WALL;
  map[17][15] = ArcadeTile::WALL;
  map[18][15] = ArcadeTile::WALL;
  map[19][15] = ArcadeTile::FOOD1;
  map[20][15] = ArcadeTile::WALL;
  map[21][15] = ArcadeTile::FOOD1;
  map[22][15] = ArcadeTile::WALL;
  map[23][15] = ArcadeTile::DEFAULT;
  map[0][16] = ArcadeTile::WALL;
  map[1][16] = ArcadeTile::FOOD1;
  map[2][16] = ArcadeTile::WALL;
  map[3][16] = ArcadeTile::WALL;
  map[4][16] = ArcadeTile::FOOD1;
  map[5][16] = ArcadeTile::WALL;
  map[6][16] = ArcadeTile::FOOD1;
  map[7][16] = ArcadeTile::WALL;
  map[8][16] = ArcadeTile::DEFAULT;
  map[9][16] = ArcadeTile::WALL;
  map[10][16] = ArcadeTile::FOOD1;
  map[11][16] = ArcadeTile::WALL;
  map[12][16] = ArcadeTile::DEFAULT;
  map[13][16] = ArcadeTile::DEFAULT;
  map[14][16] = ArcadeTile::WALL;
  map[15][16] = ArcadeTile::FOOD1;
  map[16][16] = ArcadeTile::WALL;
  map[17][16] = ArcadeTile::FOOD1;
  map[18][16] = ArcadeTile::FOOD1;
  map[19][16] = ArcadeTile::FOOD1;
  map[20][16] = ArcadeTile::WALL;
  map[21][16] = ArcadeTile::FOOD1;
  map[22][16] = ArcadeTile::WALL;
  map[23][16] = ArcadeTile::DEFAULT;
  map[0][17] = ArcadeTile::WALL;
  map[1][17] = ArcadeTile::FOOD1;
  map[2][17] = ArcadeTile::FOOD1;
  map[3][17] = ArcadeTile::FOOD2;
  map[4][17] = ArcadeTile::FOOD1;
  map[5][17] = ArcadeTile::FOOD1;
  map[6][17] = ArcadeTile::FOOD1;
  map[7][17] = ArcadeTile::WALL;
  map[8][17] = ArcadeTile::DEFAULT;
  map[9][17] = ArcadeTile::WALL;
  map[10][17] = ArcadeTile::FOOD1;
  map[11][17] = ArcadeTile::WALL;
  map[12][17] = ArcadeTile::DEFAULT;
  map[13][17] = ArcadeTile::DEFAULT;
  map[14][17] = ArcadeTile::WALL;
  map[15][17] = ArcadeTile::FOOD1;
  map[16][17] = ArcadeTile::FOOD1;
  map[17][17] = ArcadeTile::FOOD2;
  map[18][17] = ArcadeTile::WALL;
  map[19][17] = ArcadeTile::FOOD1;
  map[20][17] = ArcadeTile::FOOD1;
  map[21][17] = ArcadeTile::FOOD1;
  map[22][17] = ArcadeTile::WALL;
  map[23][17] = ArcadeTile::DEFAULT;
  map[0][18] = ArcadeTile::WALL;
  map[1][18] = ArcadeTile::WALL;
  map[2][18] = ArcadeTile::WALL;
  map[3][18] = ArcadeTile::WALL;
  map[4][18] = ArcadeTile::WALL;
  map[5][18] = ArcadeTile::WALL;
  map[6][18] = ArcadeTile::WALL;
  map[7][18] = ArcadeTile::WALL;
  map[8][18] = ArcadeTile::DEFAULT;
  map[9][18] = ArcadeTile::WALL;
  map[10][18] = ArcadeTile::FOOD1;
  map[11][18] = ArcadeTile::WALL;
  map[12][18] = ArcadeTile::DEFAULT;
  map[13][18] = ArcadeTile::DEFAULT;
  map[14][18] = ArcadeTile::WALL;
  map[15][18] = ArcadeTile::WALL;
  map[16][18] = ArcadeTile::WALL;
  map[17][18] = ArcadeTile::WALL;
  map[18][18] = ArcadeTile::WALL;
  map[19][18] = ArcadeTile::WALL;
  map[20][18] = ArcadeTile::WALL;
  map[21][18] = ArcadeTile::WALL;
  map[22][18] = ArcadeTile::WALL;
  map[23][18] = ArcadeTile::DEFAULT;
  map[0][19] = ArcadeTile::DEFAULT;
  map[1][19] = ArcadeTile::DEFAULT;
  map[2][19] = ArcadeTile::DEFAULT;
  map[3][19] = ArcadeTile::DEFAULT;
  map[4][19] = ArcadeTile::DEFAULT;
  map[5][19] = ArcadeTile::DEFAULT;
  map[6][19] = ArcadeTile::DEFAULT;
  map[7][19] = ArcadeTile::DEFAULT;
  map[8][19] = ArcadeTile::DEFAULT;
  // map[9][19] = ArcadeTile::DEFAULT;
  map[10][19] = ArcadeTile::DEFAULT;
  map[11][19] = ArcadeTile::DEFAULT;
  map[12][19] = ArcadeTile::DEFAULT;
  map[13][19] = ArcadeTile::DEFAULT;
  map[14][19] = ArcadeTile::DEFAULT;
  map[15][19] = ArcadeTile::DEFAULT;
  map[16][19] = ArcadeTile::DEFAULT;
  map[17][19] = ArcadeTile::DEFAULT;
  map[18][19] = ArcadeTile::DEFAULT;
  map[19][19] = ArcadeTile::DEFAULT;
  map[20][19] = ArcadeTile::DEFAULT;
  map[21][19] = ArcadeTile::DEFAULT;
  map[22][19] = ArcadeTile::DEFAULT;
  map[23][19] = ArcadeTile::DEFAULT;
  map[0][20] = ArcadeTile::DEFAULT;
  map[1][20] = ArcadeTile::DEFAULT;
  map[2][20] = ArcadeTile::DEFAULT;
  map[3][20] = ArcadeTile::DEFAULT;
  map[4][20] = ArcadeTile::DEFAULT;
  map[5][20] = ArcadeTile::DEFAULT;
  map[6][20] = ArcadeTile::DEFAULT;
  map[7][20] = ArcadeTile::DEFAULT;
  map[8][20] = ArcadeTile::DEFAULT;
  // map[9][20] = ArcadeTile::DEFAULT;
  map[10][20] = ArcadeTile::DEFAULT;
  map[11][20] = ArcadeTile::DEFAULT;
  map[12][20] = ArcadeTile::DEFAULT;
  map[13][20] = ArcadeTile::DEFAULT;
  map[14][20] = ArcadeTile::DEFAULT;
  map[15][20] = ArcadeTile::DEFAULT;
  map[16][20] = ArcadeTile::DEFAULT;
  map[17][20] = ArcadeTile::DEFAULT;
  map[18][20] = ArcadeTile::DEFAULT;
  map[19][20] = ArcadeTile::DEFAULT;
  map[20][20] = ArcadeTile::DEFAULT;
  map[21][20] = ArcadeTile::DEFAULT;
  map[22][20] = ArcadeTile::DEFAULT;
  map[23][20] = ArcadeTile::DEFAULT;
  map[0][21] = ArcadeTile::DEFAULT;
  map[1][21] = ArcadeTile::DEFAULT;
  map[2][21] = ArcadeTile::DEFAULT;
  map[3][21] = ArcadeTile::DEFAULT;
  map[4][21] = ArcadeTile::DEFAULT;
  map[5][21] = ArcadeTile::DEFAULT;
  map[6][21] = ArcadeTile::DEFAULT;
  map[7][21] = ArcadeTile::DEFAULT;
  map[8][21] = ArcadeTile::DEFAULT;
  // map[9][21] = ArcadeTile::DEFAULT;
  map[10][21] = ArcadeTile::DEFAULT;
  map[11][21] = ArcadeTile::DEFAULT;
  map[12][21] = ArcadeTile::DEFAULT;
  map[13][21] = ArcadeTile::DEFAULT;
  map[14][21] = ArcadeTile::DEFAULT;
  map[15][21] = ArcadeTile::DEFAULT;
  map[16][21] = ArcadeTile::DEFAULT;
  map[17][21] = ArcadeTile::DEFAULT;
  map[18][21] = ArcadeTile::DEFAULT;
  map[19][21] = ArcadeTile::DEFAULT;
  map[20][21] = ArcadeTile::DEFAULT;
  map[21][21] = ArcadeTile::DEFAULT;
  map[22][21] = ArcadeTile::DEFAULT;
  map[23][21] = ArcadeTile::DEFAULT;
  map[0][22] = ArcadeTile::DEFAULT;
  map[1][22] = ArcadeTile::DEFAULT;
  map[2][22] = ArcadeTile::DEFAULT;
  map[3][22] = ArcadeTile::DEFAULT;
  map[4][22] = ArcadeTile::DEFAULT;
  map[5][22] = ArcadeTile::DEFAULT;
  map[6][22] = ArcadeTile::DEFAULT;
  map[7][22] = ArcadeTile::DEFAULT;
  map[8][22] = ArcadeTile::DEFAULT;
  map[9][22] = ArcadeTile::DEFAULT;
  map[10][22] = ArcadeTile::DEFAULT;
  map[11][22] = ArcadeTile::DEFAULT;
  map[12][22] = ArcadeTile::DEFAULT;
  map[13][22] = ArcadeTile::DEFAULT;
  map[14][22] = ArcadeTile::DEFAULT;
  map[15][22] = ArcadeTile::DEFAULT;
  map[16][22] = ArcadeTile::DEFAULT;
  map[17][22] = ArcadeTile::DEFAULT;
  map[18][22] = ArcadeTile::DEFAULT;
  map[19][22] = ArcadeTile::DEFAULT;
  map[20][22] = ArcadeTile::DEFAULT;
  map[21][22] = ArcadeTile::DEFAULT;
  map[22][22] = ArcadeTile::DEFAULT;
  map[23][22] = ArcadeTile::DEFAULT;
  map[0][23] = ArcadeTile::DEFAULT;
  map[1][23] = ArcadeTile::DEFAULT;
  map[2][23] = ArcadeTile::DEFAULT;
  map[3][23] = ArcadeTile::DEFAULT;
  map[4][23] = ArcadeTile::DEFAULT;
  map[5][23] = ArcadeTile::DEFAULT;
  map[6][23] = ArcadeTile::DEFAULT;
  map[7][23] = ArcadeTile::DEFAULT;
  map[8][23] = ArcadeTile::DEFAULT;
  map[9][23] = ArcadeTile::DEFAULT;
  map[10][23] = ArcadeTile::DEFAULT;
  map[11][23] = ArcadeTile::DEFAULT;
  map[12][23] = ArcadeTile::DEFAULT;
  map[13][23] = ArcadeTile::DEFAULT;
  map[14][23] = ArcadeTile::DEFAULT;
  map[15][23] = ArcadeTile::DEFAULT;
  map[16][23] = ArcadeTile::DEFAULT;
  map[17][23] = ArcadeTile::DEFAULT;
  map[18][23] = ArcadeTile::DEFAULT;
  map[19][23] = ArcadeTile::DEFAULT;
  map[20][23] = ArcadeTile::DEFAULT;
  map[21][23] = ArcadeTile::DEFAULT;
  map[22][23] = ArcadeTile::DEFAULT;
  map[23][23] = ArcadeTile::DEFAULT;
  map[pac[0]][pac[1]] = ArcadeTile::PLAYER;
  map[10][9] = ArcadeTile::ENEMY1;
  map[11][9] = ArcadeTile::ENEMY2;
  map[11][8] = ArcadeTile::ENEMY3;
  map[11][10] = ArcadeTile::ENEMY4;
}

Pacman::~Pacman()
{
  int	x = 0, y = 0;

  *state = MENU;
  while (x < WIDTH)
    {
      y = 0;
      while (y < HEIGHT)
	{
	  map[y][x] = ArcadeTile::DEFAULT;
	  y = y + 1;
	}
      x = x + 1;
    }
}

void	*Pacman::iplay()
{
  while (size < 192 && *keyPressed != ArcadeKey::ESCAPE && *keyPressed != ArcadeKey::NUM9 && *keyPressed != ArcadeKey::NUM8 && *keyPressed != ArcadeKey::NUM5 && *keyPressed != ArcadeKey::NUM4)
    {
      if (move() == 1)
	return (NULL);
      usleep(550000);
      if (gMove < 10)
	gMove += 1;
      else
	if (moveGhost() == 1)
	  return (NULL);
    }
  return (NULL);
}

int	Pacman::moveGhost()
{
  if (dir1 == ArcadeKey::UP && map[enemy1[0] - 1][enemy1[1]] != ArcadeTile::WALL && map[enemy1[0] - 1][enemy1[1]] != ArcadeTile::ENEMY2 && map[enemy1[0] - 1][enemy1[1]] != ArcadeTile::ENEMY3 && map[enemy1[0] - 1][enemy1[1]] != ArcadeTile::ENEMY4)
    {
      if (map[enemy1[0] - 1][enemy1[1]] == ArcadeTile::PLAYER)
	return (1);
      map[enemy1[0]][enemy1[1]] = old1;
      enemy1[0] -= 1;
      old1 = map[enemy1[0]][enemy1[1]];
      map[enemy1[0]][enemy1[1]] = ArcadeTile::ENEMY1;
    }
  else if (dir1 == ArcadeKey::DOWN && map[enemy1[0] + 1][enemy1[1]] != ArcadeTile::WALL && map[enemy1[0] + 1][enemy1[1]] != ArcadeTile::ENEMY2 && map[enemy1[0] + 1][enemy1[1]] != ArcadeTile::ENEMY3 && map[enemy1[0] + 1][enemy1[1]] != ArcadeTile::ENEMY4)
    {
      if (map[enemy1[0] + 1][enemy1[1]] == ArcadeTile::PLAYER)
	return (1);
      map[enemy1[0]][enemy1[1]] = old1;
      enemy1[0] += 1;
      old1 = map[enemy1[0]][enemy1[1]];
      map[enemy1[0]][enemy1[1]] = ArcadeTile::ENEMY1;
    }
  else if (dir1 == ArcadeKey::LEFT && map[enemy1[0]][enemy1[1] - 1] != ArcadeTile::WALL && map[enemy1[0]][enemy1[1] - 1] != ArcadeTile::ENEMY2 && map[enemy1[0]][enemy1[1] - 1] != ArcadeTile::ENEMY3 && map[enemy1[0]][enemy1[1] - 1] != ArcadeTile::ENEMY4)
    {
      if (map[enemy1[0]][enemy1[1] - 1] == ArcadeTile::PLAYER)
	return (1);
      map[enemy1[0]][enemy1[1]] = old1;
      enemy1[1] -= 1;
      old1 = map[enemy1[0]][enemy1[1]];
      map[enemy1[0]][enemy1[1]] = ArcadeTile::ENEMY1;
    }
  else if (dir1 == ArcadeKey::RIGHT && map[enemy1[0]][enemy1[1] + 1] != ArcadeTile::WALL && map[enemy1[0]][enemy1[1] + 1] != ArcadeTile::ENEMY2 && map[enemy1[0]][enemy1[1] + 1] != ArcadeTile::ENEMY3 && map[enemy1[0]][enemy1[1] + 1] != ArcadeTile::ENEMY4)
    {
      if (map[enemy1[0]][enemy1[1] + 1] == ArcadeTile::PLAYER)
	return (1);
      map[enemy1[0]][enemy1[1]] = old1;
      enemy1[1] += 1;
      old1 = map[enemy1[0]][enemy1[1]];
      map[enemy1[0]][enemy1[1]] = ArcadeTile::ENEMY1;
    }
  else if (dir1 == ArcadeKey::UP && map[enemy1[0] - 1][enemy1[1]] == ArcadeTile::WALL &&
	   map[enemy1[0]][enemy1[1] - 1] != ArcadeTile::WALL && map[enemy1[0] - 1][enemy1[1]] != ArcadeTile::ENEMY2 && map[enemy1[0] - 1][enemy1[1]] != ArcadeTile::ENEMY3 && map[enemy1[0] - 1][enemy1[1]] != ArcadeTile::ENEMY4)
    {
      if (map[enemy1[0] - 1][enemy1[1]] == ArcadeTile::PLAYER)
	return (1);
      dir1 = ArcadeKey::LEFT;
      map[enemy1[0]][enemy1[1]] = old1;
      enemy1[1] -= 1;
      old1 = map[enemy1[0]][enemy1[1]];
      map[enemy1[0]][enemy1[1]] = ArcadeTile::ENEMY1;
    }
  else if (dir1 == ArcadeKey::UP && map[enemy1[0] - 1][enemy1[1]] == ArcadeTile::WALL &&
	   map[enemy1[0]][enemy1[1] + 1] != ArcadeTile::WALL && map[enemy1[0]][enemy1[1] + 1] != ArcadeTile::ENEMY2 && map[enemy1[0]][enemy1[1] + 1] != ArcadeTile::ENEMY3 && map[enemy1[0]][enemy1[1] + 1] != ArcadeTile::ENEMY4)
    {
      if (map[enemy1[0]][enemy1[1] + 1] == ArcadeTile::PLAYER)
	return (1);
      dir1 = ArcadeKey::RIGHT;
      map[enemy1[0]][enemy1[1]] = old1;
      enemy1[1] += 1;
      old1 = map[enemy1[0]][enemy1[1]];
      map[enemy1[0]][enemy1[1]] = ArcadeTile::ENEMY1;
    }
  else if (dir1 == ArcadeKey::DOWN && map[enemy1[0] + 1][enemy1[1]] == ArcadeTile::WALL &&
	   map[enemy1[0]][enemy1[1] - 1] != ArcadeTile::WALL && map[enemy1[0]][enemy1[1] - 1] != ArcadeTile::ENEMY2 && map[enemy1[0]][enemy1[1] - 1] != ArcadeTile::ENEMY3 && map[enemy1[0]][enemy1[1] - 1] != ArcadeTile::ENEMY4)
    {
      if (map[enemy1[0]][enemy1[1] - 1] == ArcadeTile::PLAYER)
	return (1);
      dir1 = ArcadeKey::LEFT;
      map[enemy1[0]][enemy1[1]] = old1;
      enemy1[1] -= 1;
      old1 = map[enemy1[0]][enemy1[1]];
      map[enemy1[0]][enemy1[1]] = ArcadeTile::ENEMY1;
    }
  else if (dir1 == ArcadeKey::DOWN && map[enemy1[0] + 1][enemy1[1]] == ArcadeTile::WALL &&
	   map[enemy1[0]][enemy1[1] + 1] != ArcadeTile::WALL && map[enemy1[0]][enemy1[1] + 1] != ArcadeTile::ENEMY2 && map[enemy1[0]][enemy1[1] + 1] != ArcadeTile::ENEMY3 && map[enemy1[0]][enemy1[1] + 1] != ArcadeTile::ENEMY4)
    {
      if (map[enemy1[0]][enemy1[1] + 1] == ArcadeTile::PLAYER)
	return (1);
      dir1 = ArcadeKey::RIGHT;
      map[enemy1[0]][enemy1[1]] = old1;
      enemy1[1] += 1;
      old1 = map[enemy1[0]][enemy1[1]];
      map[enemy1[0]][enemy1[1]] = ArcadeTile::ENEMY1;
    }
  else if (dir1 == ArcadeKey::LEFT && map[enemy1[0]][enemy1[1] - 1] == ArcadeTile::WALL &&
	   map[enemy1[0] - 1][enemy1[1]] != ArcadeTile::WALL && map[enemy1[0] - 1][enemy1[1]] != ArcadeTile::ENEMY2 && map[enemy1[0] - 1][enemy1[1]] != ArcadeTile::ENEMY3 && map[enemy1[0] - 1][enemy1[1]] != ArcadeTile::ENEMY4)
    {
      if (map[enemy1[0] - 1][enemy1[1]] == ArcadeTile::PLAYER)
	return (1);
      dir1 = ArcadeKey::UP;
      map[enemy1[0]][enemy1[1]] = old1;
      enemy1[0] -= 1;
      old1 = map[enemy1[0]][enemy1[1]];
      map[enemy1[0]][enemy1[1]] = ArcadeTile::ENEMY1;
    }
  else if (dir1 == ArcadeKey::LEFT && map[enemy1[0]][enemy1[1] - 1] == ArcadeTile::WALL &&
	   map[enemy1[0] + 1][enemy1[1]] != ArcadeTile::WALL && map[enemy1[0] + 1][enemy1[1]] != ArcadeTile::ENEMY2 && map[enemy1[0] + 1][enemy1[1]] != ArcadeTile::ENEMY3 && map[enemy1[0] + 1][enemy1[1]] != ArcadeTile::ENEMY4)
    {
      if (map[enemy1[0] + 1][enemy1[1]] == ArcadeTile::PLAYER)
	return (1);
      dir1 = ArcadeKey::DOWN;
      map[enemy1[0]][enemy1[1]] = old1;
      enemy1[0] += 1;
      old1 = map[enemy1[0]][enemy1[1]];
      map[enemy1[0]][enemy1[1]] = ArcadeTile::ENEMY1;
    }
  else if (dir1 == ArcadeKey::RIGHT && map[enemy1[0]][enemy1[1] + 1] == ArcadeTile::WALL &&
	   map[enemy1[0] + 1][enemy1[1]] != ArcadeTile::WALL && map[enemy1[0] + 1][enemy1[1]] != ArcadeTile::ENEMY2 && map[enemy1[0] + 1][enemy1[1]] != ArcadeTile::ENEMY3 && map[enemy1[0] + 1][enemy1[1]] != ArcadeTile::ENEMY4)
    {
      if (map[enemy1[0] + 1][enemy1[1]] == ArcadeTile::PLAYER)
	return (1);
      dir1 = ArcadeKey::DOWN;
      map[enemy1[0]][enemy1[1]] = old1;
      enemy1[0] += 1;
      old1 = map[enemy1[0]][enemy1[1]];
      map[enemy1[0]][enemy1[1]] = ArcadeTile::ENEMY1;
    }
  else if (dir1 == ArcadeKey::RIGHT && map[enemy1[0]][enemy1[1] + 1] == ArcadeTile::WALL &&
	   map[enemy1[0] - 1][enemy1[1]] != ArcadeTile::WALL && map[enemy1[0] - 1][enemy1[1]] != ArcadeTile::ENEMY2 && map[enemy1[0] - 1][enemy1[1]] != ArcadeTile::ENEMY3 && map[enemy1[0] - 1][enemy1[1]] != ArcadeTile::ENEMY4)
    {
      if (map[enemy1[0] - 1][enemy1[1]] == ArcadeTile::PLAYER)
	return (1);
      dir1 = ArcadeKey::UP;
      map[enemy1[0]][enemy1[1]] = old1;
      enemy1[0] -= 1;
      old1 = map[enemy1[0]][enemy1[1]];
      map[enemy1[0]][enemy1[1]] = ArcadeTile::ENEMY1;
    }
      if (dir2 == ArcadeKey::UP && map[enemy2[0] - 1][enemy2[1]] != ArcadeTile::WALL && map[enemy2[0] - 1][enemy2[1]] != ArcadeTile::ENEMY2 && map[enemy2[0] - 1][enemy2[1]] != ArcadeTile::ENEMY3 && map[enemy2[0] - 1][enemy2[1]] != ArcadeTile::ENEMY4)
	{
	  if (map[enemy2[0] - 1][enemy2[1]] == ArcadeTile::PLAYER)
	    return (1);
	  map[enemy2[0]][enemy2[1]] = old2;
	  enemy2[0] -= 1;
	  old2 = map[enemy2[0]][enemy2[1]];
	  map[enemy2[0]][enemy2[1]] = ArcadeTile::ENEMY2;
	}
      else if (dir2 == ArcadeKey::DOWN && map[enemy2[0] + 1][enemy2[1]] != ArcadeTile::WALL && map[enemy2[0] + 1][enemy2[1]] != ArcadeTile::ENEMY2 && map[enemy2[0] + 1][enemy2[1]] != ArcadeTile::ENEMY3 && map[enemy2[0] + 1][enemy2[1]] != ArcadeTile::ENEMY4)
	{
	  if (map[enemy2[0] + 1][enemy2[1]] == ArcadeTile::PLAYER)
	    return (1);
	  map[enemy2[0]][enemy2[1]] = old2;
	  enemy2[0] += 1;
	  old2 = map[enemy2[0]][enemy2[1]];
	  map[enemy2[0]][enemy2[1]] = ArcadeTile::ENEMY2;
	}
      else if (dir2 == ArcadeKey::LEFT && map[enemy2[0]][enemy2[1] - 1] != ArcadeTile::WALL && map[enemy2[0]][enemy2[1] - 1] != ArcadeTile::ENEMY2 && map[enemy2[0]][enemy2[1] - 1] != ArcadeTile::ENEMY3 && map[enemy2[0]][enemy2[1] - 1] != ArcadeTile::ENEMY4)
	{
	  if (map[enemy2[0]][enemy2[1] - 1] == ArcadeTile::PLAYER)
	    return (1);
	  map[enemy2[0]][enemy2[1]] = old2;
	  enemy2[1] -= 1;
	  old2 = map[enemy2[0]][enemy2[1]];
	  map[enemy2[0]][enemy2[1]] = ArcadeTile::ENEMY2;
	}
      else if (dir2 == ArcadeKey::RIGHT && map[enemy2[0]][enemy2[1] + 1] != ArcadeTile::WALL && map[enemy2[0]][enemy2[1] + 1] != ArcadeTile::ENEMY2 && map[enemy2[0]][enemy2[1] + 1] != ArcadeTile::ENEMY3 && map[enemy2[0]][enemy2[1] + 1] != ArcadeTile::ENEMY4)
	{
	  if (map[enemy2[0]][enemy2[1] + 1] == ArcadeTile::PLAYER)
	    return (1);
	  map[enemy2[0]][enemy2[1]] = old2;
	  enemy2[1] += 1;
	  old2 = map[enemy2[0]][enemy2[1]];
	  map[enemy2[0]][enemy2[1]] = ArcadeTile::ENEMY2;
	}
      else if (dir2 == ArcadeKey::UP && map[enemy2[0] - 1][enemy2[1]] == ArcadeTile::WALL &&
	       map[enemy2[0]][enemy2[1] + 1] != ArcadeTile::WALL && map[enemy2[0]][enemy2[1] + 1] != ArcadeTile::ENEMY2 && map[enemy2[0]][enemy2[1] + 1] != ArcadeTile::ENEMY3 && map[enemy2[0]][enemy2[1] + 1] != ArcadeTile::ENEMY4)
	{
	  if (map[enemy2[0]][enemy2[1] + 1] == ArcadeTile::PLAYER)
	    return (1);
	  dir2 = ArcadeKey::RIGHT;
	  map[enemy2[0]][enemy2[1]] = old2;
	  enemy2[1] += 1;
	  old2 = map[enemy2[0]][enemy2[1]];
	  map[enemy2[0]][enemy2[1]] = ArcadeTile::ENEMY2;
	}
      else if (dir2 == ArcadeKey::UP && map[enemy2[0] - 1][enemy2[1]] == ArcadeTile::WALL &&
	       map[enemy2[0]][enemy2[1] - 1] != ArcadeTile::WALL && map[enemy2[0]][enemy2[1] - 1] != ArcadeTile::ENEMY2 && map[enemy2[0]][enemy2[1] - 1] != ArcadeTile::ENEMY3 && map[enemy2[0]][enemy2[1] - 1] != ArcadeTile::ENEMY4)
	{
	  if (map[enemy2[0]][enemy2[1] - 1] == ArcadeTile::PLAYER)
	    return (1);
	  dir2 = ArcadeKey::LEFT;
	  map[enemy2[0]][enemy2[1]] = old2;
	  enemy2[1] -= 1;
	  old2 = map[enemy2[0]][enemy2[1]];
	  map[enemy2[0]][enemy2[1]] = ArcadeTile::ENEMY2;
	}
      else if (dir2 == ArcadeKey::DOWN && map[enemy2[0] + 1][enemy2[1]] == ArcadeTile::WALL &&
	       map[enemy2[0]][enemy2[1] - 1] != ArcadeTile::WALL && map[enemy2[0]][enemy2[1] - 1] != ArcadeTile::ENEMY2 && map[enemy2[0]][enemy2[1] - 1] != ArcadeTile::ENEMY3 && map[enemy2[0]][enemy2[1] - 1] != ArcadeTile::ENEMY4)
	{
	  if (map[enemy2[0]][enemy2[1] - 1] == ArcadeTile::PLAYER)
	    return (1);
	  dir2 = ArcadeKey::LEFT;
	  map[enemy2[0]][enemy2[1]] = old2;
	  enemy2[1] -= 1;
	  old2 = map[enemy2[0]][enemy2[1]];
	  map[enemy2[0]][enemy2[1]] = ArcadeTile::ENEMY2;
	}
      else if (dir2 == ArcadeKey::DOWN && map[enemy2[0] + 1][enemy2[1]] == ArcadeTile::WALL &&
	       map[enemy2[0]][enemy2[1] + 1] != ArcadeTile::WALL && map[enemy2[0]][enemy2[1] + 1] != ArcadeTile::ENEMY2 && map[enemy2[0]][enemy2[1] + 1] != ArcadeTile::ENEMY3 && map[enemy2[0]][enemy2[1] + 1] != ArcadeTile::ENEMY4)
	{
	  if (map[enemy2[0]][enemy2[1] + 1] == ArcadeTile::PLAYER)
	    return (1);
	  dir2 = ArcadeKey::RIGHT;
	  map[enemy2[0]][enemy2[1]] = old2;
	  enemy2[1] += 1;
	  old2 = map[enemy2[0]][enemy2[1]];
	  map[enemy2[0]][enemy2[1]] = ArcadeTile::ENEMY2;
	}
      else if (dir2 == ArcadeKey::LEFT && map[enemy2[0]][enemy2[1] - 1] == ArcadeTile::WALL &&
	       map[enemy2[0] - 1][enemy2[1]] != ArcadeTile::WALL && map[enemy2[0] - 1][enemy2[1]] != ArcadeTile::ENEMY2 && map[enemy2[0] - 1][enemy2[1]] != ArcadeTile::ENEMY3 && map[enemy2[0] - 1][enemy2[1]] != ArcadeTile::ENEMY4)
	{
	  if (map[enemy2[0] - 1][enemy2[1]] == ArcadeTile::PLAYER)
	    return (1);
	  dir2 = ArcadeKey::UP;
	  map[enemy2[0]][enemy2[1]] = old2;
	  enemy2[0] -= 1;
	  old2 = map[enemy2[0]][enemy2[1]];
	  map[enemy2[0]][enemy2[1]] = ArcadeTile::ENEMY2;
	}
      else if (dir2 == ArcadeKey::LEFT && map[enemy2[0]][enemy2[1] - 1] == ArcadeTile::WALL &&
	       map[enemy2[0] + 1][enemy2[1]] != ArcadeTile::WALL && map[enemy2[0] + 1][enemy2[1]] != ArcadeTile::ENEMY2 && map[enemy2[0] + 1][enemy2[1]] != ArcadeTile::ENEMY3 && map[enemy2[0] + 1][enemy2[1]] != ArcadeTile::ENEMY4)
	{
	  if (map[enemy2[0] + 1][enemy2[1]] == ArcadeTile::PLAYER)
	    return (1);
	  dir2 = ArcadeKey::DOWN;
	  map[enemy2[0]][enemy2[1]] = old2;
	  enemy2[0] += 1;
	  old2 = map[enemy2[0]][enemy2[1]];
	  map[enemy2[0]][enemy2[1]] = ArcadeTile::ENEMY2;
	}
      else if (dir2 == ArcadeKey::RIGHT && map[enemy2[0]][enemy2[1] + 1] == ArcadeTile::WALL &&
	       map[enemy2[0] - 1][enemy2[1]] != ArcadeTile::WALL && map[enemy2[0] - 1][enemy2[1]] != ArcadeTile::ENEMY2 && map[enemy2[0] - 1][enemy2[1]] != ArcadeTile::ENEMY3 && map[enemy2[0] - 1][enemy2[1]] != ArcadeTile::ENEMY4)
	{
	  if (map[enemy2[0] - 1][enemy2[1]] == ArcadeTile::PLAYER)
	    return (1);
	  dir2 = ArcadeKey::UP;
	  map[enemy2[0]][enemy2[1]] = old2;
	  enemy2[0] -= 1;
	  old2 = map[enemy2[0]][enemy2[1]];
	  map[enemy2[0]][enemy2[1]] = ArcadeTile::ENEMY2;
	}
      else if (dir2 == ArcadeKey::RIGHT && map[enemy2[0]][enemy2[1] + 1] == ArcadeTile::WALL &&
	       map[enemy2[0] + 1][enemy2[1]] != ArcadeTile::WALL && map[enemy2[0] + 1][enemy2[1]] != ArcadeTile::ENEMY2 && map[enemy2[0] + 1][enemy2[1]] != ArcadeTile::ENEMY3 && map[enemy2[0] + 1][enemy2[1]] != ArcadeTile::ENEMY4)
	{
	  if (map[enemy2[0] + 1][enemy2[1]] == ArcadeTile::PLAYER)
	    return (1);
	  dir2 = ArcadeKey::DOWN;
	  map[enemy2[0]][enemy2[1]] = old2;
	  enemy2[0] += 1;
	  old2 = map[enemy2[0]][enemy2[1]];
	  map[enemy2[0]][enemy2[1]] = ArcadeTile::ENEMY2;
	}
      if (dir3 == ArcadeKey::UP && map[enemy3[0] - 1][enemy3[1]] != ArcadeTile::WALL && map[enemy3[0] - 1][enemy3[1]] != ArcadeTile::ENEMY3 && map[enemy3[0] - 1][enemy3[1]] != ArcadeTile::ENEMY2 && map[enemy3[0] - 1][enemy3[1]] != ArcadeTile::ENEMY4)
	{
	  if (map[enemy3[0] - 1][enemy3[1]] == ArcadeTile::PLAYER)
	    return (1);
	  map[enemy3[0]][enemy3[1]] = old3;
	  enemy3[0] -= 1;
	  old3 = map[enemy3[0]][enemy3[1]];
	  map[enemy3[0]][enemy3[1]] = ArcadeTile::ENEMY3;
	}
      else if (dir3 == ArcadeKey::DOWN && map[enemy3[0] + 1][enemy3[1]] != ArcadeTile::WALL && map[enemy3[0] + 1][enemy3[1]] != ArcadeTile::ENEMY3 && map[enemy3[0] + 1][enemy3[1]] != ArcadeTile::ENEMY2 && map[enemy3[0] + 1][enemy3[1]] != ArcadeTile::ENEMY4)
	{
	  if (map[enemy3[0] + 1][enemy3[1]] == ArcadeTile::PLAYER)
	    return (1);
	  map[enemy3[0]][enemy3[1]] = old3;
	  enemy3[0] += 1;
	  old3 = map[enemy3[0]][enemy3[1]];
	  map[enemy3[0]][enemy3[1]] = ArcadeTile::ENEMY3;
	}
      else if (dir3 == ArcadeKey::LEFT && map[enemy3[0]][enemy3[1] - 1] != ArcadeTile::WALL && map[enemy3[0]][enemy3[1] - 1] != ArcadeTile::ENEMY3 && map[enemy3[0]][enemy3[1] - 1] != ArcadeTile::ENEMY2 && map[enemy3[0]][enemy3[1] - 1] != ArcadeTile::ENEMY4)
	{
	  if (map[enemy3[0] - 1][enemy3[1]] != ArcadeTile::WALL && enemy3[1] == 9)
	    {
	      if (map[enemy3[0]][enemy3[1] - 1] == ArcadeTile::PLAYER)
		return (1);
	      dir3 = ArcadeKey::UP;
	      map[enemy3[0]][enemy3[1]] = old3;
	      enemy3[0] -= 1;
	      old3 = map[enemy3[0]][enemy3[1]];
	      map[enemy3[0]][enemy3[1]] = ArcadeTile::ENEMY3;
	    }
	  else
	    {
	      if (map[enemy3[0]][enemy3[1] - 1] == ArcadeTile::PLAYER)
		return (1);
	      map[enemy3[0]][enemy3[1]] = old3;
	      enemy3[1] -= 1;
	      old3 = map[enemy3[0]][enemy3[1]];
	      map[enemy3[0]][enemy3[1]] = ArcadeTile::ENEMY3;
	    }
	}
      else if (dir3 == ArcadeKey::RIGHT && map[enemy3[0]][enemy3[1] + 1] != ArcadeTile::WALL && map[enemy3[0]][enemy3[1] + 1] != ArcadeTile::ENEMY3 && map[enemy3[0]][enemy3[1] + 1] != ArcadeTile::ENEMY2 && map[enemy3[0]][enemy3[1] + 1] != ArcadeTile::ENEMY4)
	{
	  if (map[enemy3[0] - 1][enemy3[1]] != ArcadeTile::WALL && enemy3[1] == 9)
	    {
	      if (map[enemy3[0]][enemy3[1] + 1] == ArcadeTile::PLAYER)
		return (1);
	      dir3 = ArcadeKey::UP;
	      map[enemy3[0]][enemy3[1]] = old3;
	      enemy3[0] -= 1;
	      old3 = map[enemy3[0]][enemy3[1]];
	      map[enemy3[0]][enemy3[1]] = ArcadeTile::ENEMY3;
	    }
	  else
	    {
	      if (map[enemy3[0]][enemy3[1] + 1] == ArcadeTile::PLAYER)
		return (1);
	      map[enemy3[0]][enemy3[1]] = old3;
	      enemy3[1] += 1;
	      old3 = map[enemy3[0]][enemy3[1]];
	      map[enemy3[0]][enemy3[1]] = ArcadeTile::ENEMY3;
	    }
	}
      else if (dir3 == ArcadeKey::UP && map[enemy3[0] - 1][enemy3[1]] == ArcadeTile::WALL &&
	       map[enemy3[0]][enemy3[1] - 1] != ArcadeTile::WALL && map[enemy3[0]][enemy3[1] - 1] != ArcadeTile::ENEMY3 && map[enemy3[0]][enemy3[1] - 1] != ArcadeTile::ENEMY2 && map[enemy3[0]][enemy3[1] - 1] != ArcadeTile::ENEMY4)
	{
	  if (map[enemy3[0]][enemy3[1] - 1] == ArcadeTile::PLAYER)
	    return (1);
	  dir3 = ArcadeKey::LEFT;
	  map[enemy3[0]][enemy3[1]] = old3;
	  enemy3[1] -= 1;
	  old3 = map[enemy3[0]][enemy3[1]];
	  map[enemy3[0]][enemy3[1]] = ArcadeTile::ENEMY3;
	}
      else if (dir3 == ArcadeKey::UP && map[enemy3[0] - 1][enemy3[1]] == ArcadeTile::WALL &&
	       map[enemy3[0]][enemy3[1] + 1] != ArcadeTile::WALL && map[enemy3[0]][enemy3[1] + 1] != ArcadeTile::ENEMY3 && map[enemy3[0]][enemy3[1] + 1] != ArcadeTile::ENEMY2 && map[enemy3[0]][enemy3[1] + 1] != ArcadeTile::ENEMY4)
	{
	  if (map[enemy3[0]][enemy3[1] + 1] == ArcadeTile::PLAYER)
	    return (1);
	  dir3 = ArcadeKey::RIGHT;
	  map[enemy3[0]][enemy3[1]] = old3;
	  enemy3[1] += 1;
	  old3 = map[enemy3[0]][enemy3[1]];
	  map[enemy3[0]][enemy3[1]] = ArcadeTile::ENEMY3;
	}
      else if (dir3 == ArcadeKey::DOWN && map[enemy3[0] + 1][enemy3[1]] == ArcadeTile::WALL &&
	       map[enemy3[0]][enemy3[1] - 1] != ArcadeTile::WALL && map[enemy3[0]][enemy3[1] - 1] != ArcadeTile::ENEMY3 && map[enemy3[0]][enemy3[1] - 1] != ArcadeTile::ENEMY2 && map[enemy3[0]][enemy3[1] - 1] != ArcadeTile::ENEMY4)
	{
	  if (map[enemy3[0]][enemy3[1] - 1] == ArcadeTile::PLAYER)
	    return (1);
	  dir3 = ArcadeKey::LEFT;
	  map[enemy3[0]][enemy3[1]] = old3;
	  enemy3[1] -= 1;
	  old3 = map[enemy3[0]][enemy3[1]];
	  map[enemy3[0]][enemy3[1]] = ArcadeTile::ENEMY3;
	}
      else if (dir3 == ArcadeKey::DOWN && map[enemy3[0] + 1][enemy3[1]] == ArcadeTile::WALL &&
	       map[enemy3[0]][enemy3[1] + 1] != ArcadeTile::WALL && map[enemy3[0]][enemy3[1] + 1] != ArcadeTile::ENEMY3 && map[enemy3[0]][enemy3[1] + 1] != ArcadeTile::ENEMY2 && map[enemy3[0]][enemy3[1] + 1] != ArcadeTile::ENEMY4)
	{
	  if (map[enemy3[0]][enemy3[1] + 1] == ArcadeTile::PLAYER)
	    return (1);
	  dir3 = ArcadeKey::RIGHT;
	  map[enemy3[0]][enemy3[1]] = old3;
	  enemy3[1] += 1;
	  old3 = map[enemy3[0]][enemy3[1]];
	  map[enemy3[0]][enemy3[1]] = ArcadeTile::ENEMY3;
	}
      else if (dir3 == ArcadeKey::LEFT && map[enemy3[0]][enemy3[1] - 1] == ArcadeTile::WALL &&
	       map[enemy3[0] - 1][enemy3[1]] != ArcadeTile::WALL && map[enemy3[0] - 1][enemy3[1]] != ArcadeTile::ENEMY3 && map[enemy3[0] - 1][enemy3[1]] != ArcadeTile::ENEMY2 && map[enemy3[0] - 1][enemy3[1]] != ArcadeTile::ENEMY4)
	{
	  if (map[enemy3[0] - 1][enemy3[1]] == ArcadeTile::PLAYER)
	    return (1);
	  dir3 = ArcadeKey::UP;
	  map[enemy3[0]][enemy3[1]] = old3;
	  enemy3[0] -= 1;
	  old3 = map[enemy3[0]][enemy3[1]];
	  map[enemy3[0]][enemy3[1]] = ArcadeTile::ENEMY3;
	}
      else if (dir3 == ArcadeKey::LEFT && map[enemy3[0]][enemy3[1] - 1] == ArcadeTile::WALL &&
	       map[enemy3[0] + 1][enemy3[1]] != ArcadeTile::WALL && map[enemy3[0] + 1][enemy3[1]] != ArcadeTile::ENEMY3 && map[enemy3[0] + 1][enemy3[1]] != ArcadeTile::ENEMY2 && map[enemy3[0] + 1][enemy3[1]] != ArcadeTile::ENEMY4)
	{
	  if (map[enemy3[0] + 1][enemy3[1]] == ArcadeTile::PLAYER)
	    return (1);
	  dir3 = ArcadeKey::DOWN;
	  map[enemy3[0]][enemy3[1]] = old3;
	  enemy3[0] += 1;
	  old3 = map[enemy3[0]][enemy3[1]];
	  map[enemy3[0]][enemy3[1]] = ArcadeTile::ENEMY3;
	}
      else if (dir3 == ArcadeKey::RIGHT && map[enemy3[0]][enemy3[1] + 1] == ArcadeTile::WALL &&
	       map[enemy3[0] - 1][enemy3[1]] != ArcadeTile::WALL && map[enemy3[0] - 1][enemy3[1]] != ArcadeTile::ENEMY3 && map[enemy3[0] - 1][enemy3[1]] != ArcadeTile::ENEMY2 && map[enemy3[0] - 1][enemy3[1]] != ArcadeTile::ENEMY4)
	{
	  if (map[enemy3[0] - 1][enemy3[1]] == ArcadeTile::PLAYER)
	    return (1);
	  dir3 = ArcadeKey::UP;
	  map[enemy3[0]][enemy3[1]] = old3;
	  enemy3[0] -= 1;
	  old3 = map[enemy3[0]][enemy3[1]];
	  map[enemy3[0]][enemy3[1]] = ArcadeTile::ENEMY3;
	}
      else if (dir3 == ArcadeKey::RIGHT && map[enemy3[0]][enemy3[1] + 1] == ArcadeTile::WALL &&
	       map[enemy3[0] + 1][enemy3[1]] != ArcadeTile::WALL && map[enemy3[0] + 1][enemy3[1]] != ArcadeTile::ENEMY3 && map[enemy3[0] + 1][enemy3[1]] != ArcadeTile::ENEMY2 && map[enemy3[0] + 1][enemy3[1]] != ArcadeTile::ENEMY4)
	{
	  if (map[enemy3[0] + 1][enemy3[1]] == ArcadeTile::PLAYER)
	    return (1);
	  dir3 = ArcadeKey::DOWN;
	  map[enemy3[0]][enemy3[1]] = old3;
	  enemy3[0] += 1;
	  old3 = map[enemy3[0]][enemy3[1]];
	  map[enemy3[0]][enemy3[1]] = ArcadeTile::ENEMY3;
	}
      if (dir4 == ArcadeKey::UP && map[enemy4[0] - 1][enemy4[1]] != ArcadeTile::WALL && map[enemy4[0] - 1][enemy4[1]] != ArcadeTile::ENEMY4 && map[enemy4[0] - 1][enemy4[1]] != ArcadeTile::ENEMY2 && map[enemy4[0] - 1][enemy4[1]] != ArcadeTile::ENEMY3)
	{
	  if (map[enemy4[0] - 1][enemy4[1]] == ArcadeTile::PLAYER)
	    return (1);
	  map[enemy4[0]][enemy4[1]] = old4;
	  enemy4[0] -= 1;
	  old4 = map[enemy4[0]][enemy4[1]];
	  map[enemy4[0]][enemy4[1]] = ArcadeTile::ENEMY4;
	}
      else if (dir4 == ArcadeKey::DOWN && map[enemy4[0] + 1][enemy4[1]] != ArcadeTile::WALL && map[enemy4[0] + 1][enemy4[1]] != ArcadeTile::ENEMY4 && map[enemy4[0] + 1][enemy4[1]] != ArcadeTile::ENEMY2 && map[enemy4[0] + 1][enemy4[1]] != ArcadeTile::ENEMY3)
	{
	  if (map[enemy4[0] + 1][enemy4[1]] == ArcadeTile::PLAYER)
	    return (1);
	  map[enemy4[0]][enemy4[1]] = old4;
	  enemy4[0] += 1;
	  old4 = map[enemy4[0]][enemy4[1]];
	  map[enemy4[0]][enemy4[1]] = ArcadeTile::ENEMY4;
	}
      else if (dir4 == ArcadeKey::LEFT && map[enemy4[0]][enemy4[1] - 1] != ArcadeTile::WALL && map[enemy4[0]][enemy4[1] - 1] != ArcadeTile::ENEMY4 && map[enemy4[0]][enemy4[1] - 1] != ArcadeTile::ENEMY2 && map[enemy4[0]][enemy4[1] - 1] != ArcadeTile::ENEMY3)
	{
	  if (map[enemy4[0] - 1][enemy4[1]] != ArcadeTile::WALL && enemy4[1] == 9)
	    {
	      if (map[enemy4[0]][enemy4[1] - 1] == ArcadeTile::PLAYER)
		return (1);
	      dir4 = ArcadeKey::UP;
	      map[enemy4[0]][enemy4[1]] = old4;
	      enemy4[0] -= 1;
	      old4 = map[enemy4[0]][enemy4[1]];
	      map[enemy4[0]][enemy4[1]] = ArcadeTile::ENEMY4;
	    }
	  else
	    {
	      if (map[enemy4[0] + 1][enemy4[1] - 1] == ArcadeTile::PLAYER)
		return (1);
	      map[enemy4[0]][enemy4[1]] = old4;
	      enemy4[1] -= 1;
	      old4 = map[enemy4[0]][enemy4[1]];
	      map[enemy4[0]][enemy4[1]] = ArcadeTile::ENEMY4;
	    }
	}
      else if (dir4 == ArcadeKey::RIGHT && map[enemy4[0]][enemy4[1] + 1] != ArcadeTile::WALL && map[enemy4[0]][enemy4[1] + 1] != ArcadeTile::ENEMY4 && map[enemy4[0]][enemy4[1] + 1] != ArcadeTile::ENEMY2 && map[enemy4[0]][enemy4[1] + 1] != ArcadeTile::ENEMY3)
	{
	  if (map[enemy4[0]][enemy4[1] + 1] == ArcadeTile::PLAYER)
	    return (1);
	  map[enemy4[0]][enemy4[1]] = old4;
	  enemy4[1] += 1;
	  old4 = map[enemy4[0]][enemy4[1]];
	  map[enemy4[0]][enemy4[1]] = ArcadeTile::ENEMY4;
	}
      else if (dir4 == ArcadeKey::UP && map[enemy4[0] - 1][enemy4[1]] == ArcadeTile::WALL &&
	       map[enemy4[0]][enemy4[1] - 1] != ArcadeTile::WALL && map[enemy4[0]][enemy4[1] - 1] != ArcadeTile::ENEMY4 && map[enemy4[0]][enemy4[1] - 1] != ArcadeTile::ENEMY2 && map[enemy4[0]][enemy4[1] - 1] != ArcadeTile::ENEMY3)
	{
	  if (map[enemy4[0]][enemy4[1] - 1] == ArcadeTile::PLAYER)
	    return (1);
	  dir4 = ArcadeKey::LEFT;
	  map[enemy4[0]][enemy4[1]] = old4;
	  enemy4[1] -= 1;
	  old4 = map[enemy4[0]][enemy4[1]];
	  map[enemy4[0]][enemy4[1]] = ArcadeTile::ENEMY4;
	}
      else if (dir4 == ArcadeKey::UP && map[enemy4[0] - 1][enemy4[1]] == ArcadeTile::WALL &&
	       map[enemy4[0]][enemy4[1] + 1] != ArcadeTile::WALL && map[enemy4[0]][enemy4[1] + 1] != ArcadeTile::ENEMY4 && map[enemy4[0]][enemy4[1] + 1] != ArcadeTile::ENEMY2 && map[enemy4[0] + 1][enemy4[1]] != ArcadeTile::ENEMY3)
	{
	  if (map[enemy4[0]][enemy4[1] + 1] == ArcadeTile::PLAYER)
	    return (1);
	  dir4 = ArcadeKey::RIGHT;
	  map[enemy4[0]][enemy4[1]] = old4;
	  enemy4[1] += 1;
	  old4 = map[enemy4[0]][enemy4[1]];
	  map[enemy4[0]][enemy4[1]] = ArcadeTile::ENEMY4;
	}
      else if (dir4 == ArcadeKey::DOWN && map[enemy4[0] + 1][enemy4[1]] == ArcadeTile::WALL &&
	       map[enemy4[0]][enemy4[1] + 1] != ArcadeTile::WALL && map[enemy4[0]][enemy4[1] + 1] != ArcadeTile::ENEMY4 && map[enemy4[0]][enemy4[1] + 1] != ArcadeTile::ENEMY2 && map[enemy4[0]][enemy4[1] + 1] != ArcadeTile::ENEMY3)
	{
	  if (map[enemy4[0]][enemy4[1] + 1] == ArcadeTile::PLAYER)
	    return (1);
	  dir4 = ArcadeKey::RIGHT;
	  map[enemy4[0]][enemy4[1]] = old4;
	  enemy4[1] += 1;
	  old4 = map[enemy4[0]][enemy4[1]];
	  map[enemy4[0]][enemy4[1]] = ArcadeTile::ENEMY4;
	}
      else if (dir4 == ArcadeKey::DOWN && map[enemy4[0] + 1][enemy4[1]] == ArcadeTile::WALL &&
	       map[enemy4[0]][enemy4[1] - 1] != ArcadeTile::WALL && map[enemy4[0]][enemy4[1] - 1] != ArcadeTile::ENEMY4 && map[enemy4[0]][enemy4[1] - 1] != ArcadeTile::ENEMY2 && map[enemy4[0]][enemy4[1] - 1] != ArcadeTile::ENEMY3)
	{
	  if (map[enemy4[0]][enemy4[1] - 1] == ArcadeTile::PLAYER)
	    return (1);
	  dir4 = ArcadeKey::LEFT;
	  map[enemy4[0]][enemy4[1]] = old4;
	  enemy4[1] -= 1;
	  old4 = map[enemy4[0]][enemy4[1]];
	  map[enemy4[0]][enemy4[1]] = ArcadeTile::ENEMY4;
	}
      else if (dir4 == ArcadeKey::LEFT && map[enemy4[0]][enemy4[1] - 1] == ArcadeTile::WALL &&
	       map[enemy4[0] - 1][enemy4[1]] != ArcadeTile::WALL && map[enemy4[0] - 1][enemy4[1]] != ArcadeTile::ENEMY4 && map[enemy4[0] - 1][enemy4[1]] != ArcadeTile::ENEMY2 && map[enemy4[0] - 1][enemy4[1]] != ArcadeTile::ENEMY3)
	{
	  if (map[enemy4[0] - 1][enemy4[1]] == ArcadeTile::PLAYER)
	    return (1);
	  dir4 = ArcadeKey::UP;
	  map[enemy4[0]][enemy4[1]] = old4;
	  enemy4[0] -= 1;
	  old4 = map[enemy4[0]][enemy4[1]];
	  map[enemy4[0]][enemy4[1]] = ArcadeTile::ENEMY4;
	}
      else if (dir4 == ArcadeKey::LEFT && map[enemy4[0]][enemy4[1] - 1] == ArcadeTile::WALL &&
	       map[enemy4[0] + 1][enemy4[1]] != ArcadeTile::WALL && map[enemy4[0] + 1][enemy4[1]] != ArcadeTile::ENEMY4 && map[enemy4[0] + 1][enemy4[1]] != ArcadeTile::ENEMY2 && map[enemy4[0] + 1][enemy4[1]] != ArcadeTile::ENEMY3)
	{
	  if (map[enemy4[0] + 1][enemy4[1]] == ArcadeTile::PLAYER)
	    return (1);
	  dir4 = ArcadeKey::DOWN;
	  map[enemy4[0]][enemy4[1]] = old4;
	  enemy4[0] += 1;
	  old4 = map[enemy4[0]][enemy4[1]];
	  map[enemy4[0]][enemy4[1]] = ArcadeTile::ENEMY4;
	}
      else if (dir4 == ArcadeKey::RIGHT && map[enemy4[0]][enemy4[1] + 1] == ArcadeTile::WALL &&
	       map[enemy4[0] - 1][enemy4[1]] != ArcadeTile::WALL && map[enemy4[0] - 1][enemy4[1]] != ArcadeTile::ENEMY4 && map[enemy4[0] - 1][enemy4[1]] != ArcadeTile::ENEMY2 && map[enemy4[0] - 1][enemy4[1]] != ArcadeTile::ENEMY3)
	{
	  if (map[enemy4[0] - 1][enemy4[1]] == ArcadeTile::PLAYER)
	    return (1);
	  dir4 = ArcadeKey::UP;
	  map[enemy4[0]][enemy4[1]] = old4;
	  enemy4[0] -= 1;
	  old4 = map[enemy4[0]][enemy4[1]];
	  map[enemy4[0]][enemy4[1]] = ArcadeTile::ENEMY4;
	}
      else if (dir4 == ArcadeKey::RIGHT && map[enemy4[0]][enemy4[1] + 1] == ArcadeTile::WALL &&
	       map[enemy4[0] + 1][enemy4[1]] != ArcadeTile::WALL && map[enemy4[0] + 1][enemy4[1]] != ArcadeTile::ENEMY4 && map[enemy4[0] + 1][enemy4[1]] != ArcadeTile::ENEMY2 && map[enemy4[0] + 1][enemy4[1]] != ArcadeTile::ENEMY3)
	{
	  if (map[enemy4[0] + 1][enemy4[1]] == ArcadeTile::PLAYER)
	    return (1);
	  dir4 = ArcadeKey::DOWN;
	  map[enemy4[0]][enemy4[1]] = old4;
	  enemy4[0] += 1;
	  old4 = map[enemy4[0]][enemy4[1]];
	  map[enemy4[0]][enemy4[1]] = ArcadeTile::ENEMY4;
	}
  return (0);
}

int	Pacman::up()
{
  if (map[pac[0] - 1][pac[1]] == ArcadeTile::FOOD1 || map[pac[0] - 1][pac[1]] == ArcadeTile::FOOD2)
    size += 1;
  if (map[pac[0] - 1][pac[1]] == ArcadeTile::ENEMY1 ||
	   map[pac[0] - 1][pac[1]] == ArcadeTile::ENEMY2 ||
	   map[pac[0] - 1][pac[1]] == ArcadeTile::ENEMY3 ||
	   map[pac[0] - 1][pac[1]] == ArcadeTile::ENEMY4)
    return (1);
  else if (map[pac[0] - 1][pac[1]] != ArcadeTile::WALL)
    {
      map[pac[0]][pac[1]] = ArcadeTile::DEFAULT;
      pac[0] -= 1;
      map[pac[0]][pac[1]] = ArcadeTile::PLAYER;
    }
  return (0);
}

int	Pacman::down()
{
  if (map[pac[0] + 1][pac[1]] == ArcadeTile::FOOD1 || map[pac[0] + 1][pac[1]] == ArcadeTile::FOOD2)
    size += 1;
  if (map[pac[0] + 1][pac[1]] == ArcadeTile::ENEMY1 ||
	   map[pac[0] + 1][pac[1]] == ArcadeTile::ENEMY2 ||
	   map[pac[0] + 1][pac[1]] == ArcadeTile::ENEMY3 ||
	   map[pac[0] + 1][pac[1]] == ArcadeTile::ENEMY4)
    return (1);
  else if (map[pac[0] + 1][pac[1]] != ArcadeTile::WALL && (pac[0] + 1 != 9 || pac[1] != 9))
    {
      map[pac[0]][pac[1]] = ArcadeTile::DEFAULT;
      pac[0] += 1;
      map[pac[0]][pac[1]] = ArcadeTile::PLAYER;
    }
  return (0);
}

int	Pacman::left()
{
  if (map[pac[0]][pac[1] - 1] == ArcadeTile::FOOD1 || map[pac[0]][pac[1] - 1] == ArcadeTile::FOOD2)
    size += 1;
  if (map[pac[0]][pac[1] - 1] == ArcadeTile::ENEMY1 ||
	   map[pac[0]][pac[1] - 1] == ArcadeTile::ENEMY2 ||
	   map[pac[0]][pac[1] - 1] == ArcadeTile::ENEMY3 ||
	   map[pac[0]][pac[1] - 1] == ArcadeTile::ENEMY4)
    return (1);
  else if (pac[1] == 0 && pac[0] == 10)
    {
      map[pac[0]][pac[1]] = ArcadeTile::DEFAULT;
      pac[1] = 18;
      map[pac[0]][pac[1]] = ArcadeTile::PLAYER;
    }
  else if (map[pac[0]][pac[1] - 1] != ArcadeTile::WALL)
    {
      map[pac[0]][pac[1]] = ArcadeTile::DEFAULT;
      pac[1] -= 1;
      map[pac[0]][pac[1]] = ArcadeTile::PLAYER;
    }
  return (0);
}

int	Pacman::right()
{
  if (map[pac[0]][pac[1] + 1] == ArcadeTile::FOOD1 || map[pac[0]][pac[1] + 1] == ArcadeTile::FOOD2)
    size += 1;
  if (map[pac[0]][pac[1] + 1] == ArcadeTile::ENEMY1 ||
	   map[pac[0]][pac[1] + 1] == ArcadeTile::ENEMY2 ||
	   map[pac[0]][pac[1] + 1] == ArcadeTile::ENEMY3 ||
	   map[pac[0]][pac[1] + 1] == ArcadeTile::ENEMY4)
    return (1);
  else if (pac[1] == 18 && pac[0] == 10)
    {
      map[pac[0]][pac[1]] = ArcadeTile::DEFAULT;
      pac[1] = 0;
      map[pac[0]][pac[1]] = ArcadeTile::PLAYER;
    }
  else if (map[pac[0]][pac[1] + 1] != ArcadeTile::WALL)
    {
      map[pac[0]][pac[1]] = ArcadeTile::DEFAULT;
      pac[1] += 1;
      map[pac[0]][pac[1]] = ArcadeTile::PLAYER;
    }
  return (0);
}

int	Pacman::move()
{
  int	i = 0;

  if (*keyPressed == ArcadeKey::UP)
    i = up();
  else if (*keyPressed == ArcadeKey::DOWN)
    i = down();
  else if (*keyPressed == ArcadeKey::LEFT)
    i = left();
  else if (*keyPressed == ArcadeKey::RIGHT)
    i = right();
  return (i);
}

extern "C" IGame	*newIGame(enum Status *s, int *k, char **new_map)
{
  return (new Pacman(s, k, new_map));
}

extern "C" void		deleteIGame(IGame *i)
{
  delete (reinterpret_cast<Pacman*>(i));
}
