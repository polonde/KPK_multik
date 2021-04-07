#include "TXLib.h"

void BackgroundDraw();
void YolkaDraw      (int x, int y, double sizeX, double sizeY, int sdvigX, int sdvigY,
                    COLORREF krona);
void BeryozaDraw     (int x, int y);
void SunDraw        (int x, int y, double rEye, double crazy, double smile,
                    int ser, int sizeSun, COLORREF cEye);
void LakeDraw       (int x, int y);
void Fish_RedDraw     (int x, int y);
void Fish_YellowDraw  (int x, int y);
void CloudDraw     (int x, int y, double sizeX, double sizeY,
                    COLORREF rightCloud, COLORREF leftCloud);
void MountainsDraw (int x, int y);

int main()
  {
  txCreateWindow(800, 600);

  BackgroundDraw();

  SunDraw       (693,  98, 10,  0,   0, 0,  0, TX_WHITE);
  SunDraw       (493,  98, 10,  3, 180, 0, 10, TX_LIGHTGREEN);
  SunDraw       ( 93,  98, 10, -3,   0, 1,  0, TX_LIGHTBLUE);

  MountainsDraw (388, 119);
  MountainsDraw (688, 119);
  MountainsDraw ( 88, 119);

  YolkaDraw     (148, 158, 1, 1, 10, 0, TX_GREEN);
  YolkaDraw     ( 58, 408, 0.5, 0.5, 10, 0, TX_BLUE);
  YolkaDraw     (208, 200, 1.5, 1, 10, 0, TX_LIGHTGREEN);

  BeryozaDraw     (577, 238);
  BeryozaDraw     (700, 350);
  BeryozaDraw     (380, 248);

  LakeDraw      (212, 462);

  Fish_RedDraw   (328, 493);
  Fish_RedDraw   (378, 510);
  Fish_RedDraw   (220, 515);

  Fish_YellowDraw (495, 513);
  Fish_YellowDraw (465, 485);
  Fish_YellowDraw (405, 530);

  CloudDraw     (178,  62,  1,   0.5, TX_RED, TX_BLACK);
  CloudDraw     (378,  92,  0.5, 2,   TX_RED, TX_BLACK);
  CloudDraw     (578,  42, -1.5, 0.5, TX_RED, TX_BLACK);

  return 0;
  }

void BackgroundDraw()
  {
  txSetFillColor (RGB (255, 255, 255));
  txRectangle    (0,   0, 800, 600);

  txSetFillColor (RGB (0, 255, 0));
  txRectangle    (0, 410, 800, 600);
  }

void YolkaDraw(int x, int y, double sizeX, double sizeY, int sdvigX, int sdvigY,
                COLORREF krona)
  {
  txSetColor     (RGB (0,    0,  0));
  txSetFillColor (krona);
  POINT triangle_1 [3] = {{ROUND (x+sdvigX - 57*sizeX), ROUND (y + 227*sizeY)},
                          {ROUND (x+sdvigX),            ROUND (y + 131*sizeY)},
                          {ROUND (x+sdvigX + 57*sizeX), ROUND (y + 227*sizeY)}};
  txPolygon (triangle_1, 3);
  POINT triangle_2 [3] = {{ROUND (x+sdvigX - 57*sizeX), ROUND (y + 162*sizeY)},
                          {ROUND (x+sdvigX),            ROUND (y +  66*sizeY)},
                          {ROUND (x+sdvigX + 57*sizeX), ROUND (y + 162*sizeY)}};
  txPolygon (triangle_2, 3);
  POINT triangle_3 [3] = {{ROUND (x+sdvigX - 57*sizeX), ROUND (y +  97*sizeY)},
                          {ROUND (x+sdvigX),            ROUND (y)},
                          {ROUND (x+sdvigX + 57*sizeX), ROUND (y +  97*sizeY)}};
  txPolygon (triangle_3, 3);

  txSetColor     (RGB (85, 0, 0));
  txSetFillColor (RGB (85, 0, 0));
  txRectangle    (x + sdvigX - 17*sizeX, y + 227*sizeY, x + sdvigX + 18*sizeX, y + 282*sizeY);
  }

void BeryozaDraw (int x, int y)
  {
  txSetColor     (TX_BLACK, 4);
  txSetFillColor (TX_WHITE);
  txRectangle (x-11, y+69, x+11, y+198);

  txSetColor (TX_BLACK, 6);
  txLine (x+ 4, y+102, x+8, y+102);
  txLine (x-10, y+129, x-4, y+129);
  txLine (x+ 4, y+147, x+8, y+147);
  txLine (x-10, y+179, x-4, y+179);

  txSetColor     (RGB (0, 0, 0));
  txSetFillColor (RGB (0, 128, 0));
  txCircle (x, y, 85);
  }

void SunDraw (int x, int y, double rEye, double crazy, double smile,
             int ser, int sizeSun, COLORREF cEye)
  {
  txSetColor     (RGB (255, 255, 0), 4);
  txSetFillColor (RGB (255, 255, 0));
  txCircle (x, y, 45+sizeSun);

  txLine (x-45 + sizeSun, y,           x-90 - sizeSun, y);
  txLine (x,           y+45 + sizeSun, x,           y+90 + sizeSun);
  txLine (x+45 + sizeSun, y,           x+90 + sizeSun, y);
  txLine (x,           y-45 - sizeSun, x,           y-90 - sizeSun);

  txSetColor     (RGB (0, 0, 0));
  txSetFillColor (cEye);
  txCircle (x-20, y-15-crazy, rEye + crazy);
  txCircle (x+20, y-15+crazy, rEye - crazy);
  txSetFillColor (RGB (0, 0, 0));
  txCircle (x-20, y-15-crazy, 3);
  txCircle (x+20, y-15+crazy, 3);

  txSetColor     (RGB (0, 0, 0));
  if (ser==1)
    txLine (x-20, y+15, x+20, y+15);
  else
    txArc   (x-20, y+10, x+20, y+30, 0+smile, 180);
  }

void LakeDraw(int x, int y)
  {
  txSetColor     (RGB (0, 0, 255));
  txSetFillColor (RGB (0, 0, 255));
  txEllipse (x, y, x+344, y+90);

  txSetColor     (RGB (0, 128, 0));
  txSetFillColor (RGB (0, 128, 0));
  txEllipse (x+70, y+38, x+114, y+65);
  }

void Fish_RedDraw(int x, int y)
  {
  txSetColor     (RGB (255, 204, 0));
  txSetFillColor (RGB (255, 204, 0));
  POINT tail1 [3] = {{x,    y}, {x,    y-12}, {x+16, y}};
  txPolygon (tail1, 3);

  txSetColor     (RGB (255, 0, 0));
  txSetFillColor (RGB (255, 0, 0));
  POINT body1 [3] = {{x+16, y}, {x+33, y-16}, {x+49, y}};
  txPolygon (body1, 3);

  txSetColor     (RGB (0, 0, 0));
  txSetFillColor (RGB (0, 0, 0));
  txCircle (x+38, y-6, 3);
  }

void Fish_YellowDraw(int x, int y)
  {
  txSetColor     (RGB (255, 0, 0));
  txSetFillColor (RGB (255, 0, 0));
  POINT tail2 [3] = {{x, y}, {x+16, y-11}, {x+16, y}};
  txPolygon (tail2, 3);

  txSetColor     (RGB (255, 204, 0));
  txSetFillColor (RGB (255, 204, 0));
  POINT body2 [3] = {{x-32, y}, {x-16, y-16}, {x, y}};
  txPolygon (body2, 3);

  txSetColor     (RGB (0, 0, 0));
  txSetFillColor (RGB (0, 0, 0));
  txCircle (x-21, y-6, 3);
  }

void CloudDraw (int x, int y, double sizeX, double sizeY,
                COLORREF rightCloud, COLORREF leftCloud)
  {
  txSetColor     (RGB (0, 255, 255));
  txSetFillColor (leftCloud);
  txEllipse (x,           y,           x +  70*sizeX, y + 58*sizeY);
  txSetFillColor (RGB (0, 255, 255));
  txEllipse (x + 44*sizeX, y - 12*sizeY, x + 114*sizeX, y + 43*sizeY);
  txEllipse (x + 48*sizeX, y - 20*sizeY, x + 117*sizeX, y + 78*sizeY);
  txSetFillColor (rightCloud);
  txEllipse (x + 88*sizeX, y -  2*sizeY, x + 157*sizeX, y + 55*sizeY);
  }

void MountainsDraw(int x, int y)
  {
  txSetColor     (RGB (  0,   0,   0));
  txSetFillColor (RGB (172, 147, 147));
  POINT gora1 [3] = {{x-194, y+291}, {x-97, y+32}, {x,     y+291}};
  txPolygon (gora1, 3);
  POINT gora2 [3] = {{x- 97, y+291}, {x,    y},    {x+ 97, y+291}};
  txPolygon (gora2, 3);
  POINT gora3 [3] = {{x-  1, y+291}, {x+96, y+39}, {x+193, y+291}};
  txPolygon (gora3, 3);

  txSetColor     (RGB (  0,   0,   0));
  txSetFillColor (RGB (255, 255, 255));
  POINT pik1 [3] = {{x-126, y+108}, {x-97, y+32}, {x- 68, y+108}};
  txPolygon (pik1, 3);
  POINT pik2 [3] = {{x- 36, y+106}, {x,    y},    {x+ 36, y+106}};
  txPolygon (pik2, 3);
  POINT pik3 [3] = {{x+ 66, y+116}, {x+96, y+39}, {x+126, y+116}};
  txPolygon (pik3, 3);
  }
