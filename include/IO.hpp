#ifndef _IO_
#define _IO_

// —— Includes —–
#ifdef _WIN32
#include "SDL/SDL.h"
 #include "SDL/SDL_gfxPrimitives.h"
#else
#include <SDL2/SDL.h>
#include <SDL2/SDL2_gfxPrimitives.h>
#endif

// —— Enums —–
enum color {BLACK, RED, GREEN, BLUE, CYAN, MAGENTA, YELLOW, WHITE, COLOR_MAX}; // Colors

// ——————————————————————————–
// IO
// ——————————————————————————–

class IO
{
public:

IO ();

void DrawRectangle (int pX1, int pY1, int pX2, int pY2, enum color pC);
void ClearScreen ();
int GetScreenHeight ();
int InitGraph ();
int Pollkey ();
int Getkey ();
int IsKeyDown (int pKey);
void UpdateScreen ();
bool IsWindowClosed();


};

#endif // _IO_