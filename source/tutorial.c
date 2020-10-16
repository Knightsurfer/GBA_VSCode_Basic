#include "intellisense.h"
#include "tutorial/registers.h"



#pragma region Draw
void vsync()
{
    while(REG_VCOUNT >= SCREEN_H);
    while(REG_VCOUNT < SCREEN_H);
}

u16 setColour(u8 a_red,u8 a_green,u8 a_blue){ return(a_red & 0x1F) |(a_green & 0x1F) << 5 |(a_blue & 0x1F) << 10;}
void PlotPixel(s32 a_x, s32 a_y, u16 a_colour) {SCREENBUFFER[a_y * SCREEN_W + a_x] = a_colour;}
void DrawLine( s32 a_x, s32 a_y, s32 a_x2, s32 a_y2, u16 a_colour)
{   
        s32 w = a_x2 - a_x;
        s32 h = a_y2 - a_y;

        s32 dx1 = 0, dx2 = 0, dy1 = 0, dy2 = 0;
        if(w < 0) dx1 = dx2 = -1; else if(w > 0) dx1 = dx2 = 1;
        if(h < 0) dy1 = -1; else if(h > 0) dy1 = 1;

        s32 longest = abs(w);
        s32 shortest = abs(h);

        if(shortest > longest)
        {
            longest ^= shortest; shortest ^= longest; longest ^= shortest;
            if(h < 0) dy2 = -1; else if(h > 0) dy2 = 1;
            dx2 = 0;
        }

        s32 numerator = longest >> 1;
        for(s32 i = 0; i <= longest; ++i)
        {
            PlotPixel(a_x,a_y, a_colour);

            numerator += shortest;
            if(numerator > longest){
                numerator -= longest;
                a_x += dx1;
                a_y += dy1;
            }
            else{
                a_x += dx2;
                a_y += dy2;

            }
        }
}
void DrawRect( s32 a_left, s32 a_top, s32 a_width, s32 a_height, u16 a_colour)
{
        for(s32 y = 0; y < a_height; ++y)
        {
            for(s32 x = 0; x < a_width; ++x)
            {
                PlotPixel(a_left + x, a_top + y, a_colour);
            }
        }
}
void DrawCool()
{
    s32 t = 0;
    while(1){
        s32 x,y;
        for(x = 0; x < SCREEN_W; ++x)
        {
            for(y = 0; y < SCREEN_H; ++y){
                PlotPixel(x,y,setColour((x&y)+t*5, (x&y)+t*3, (x&y)+t));
            }
        }
        ++t;
    }
}
#pragma endregion
#pragma region Number Generator
s32 abs(s32 a_val)
{
    s32 mask = a_val >> 31;
    return(a_val ^ mask) - mask;
}
s32 __gba_rand_seed = 42;
s32 seed_gba_rand(s32 a_seed)
{
    s32 old_seed = __gba_rand_seed;
    __gba_rand_seed = a_seed;
    return old_seed;
}
s32 gba_rand()
{
    __gba_rand_seed = 1664525 * __gba_rand_seed + 1013904223;
    return(__gba_rand_seed >> 16) & 0x7FFF;
}
s32 gba_rand_range(s32 a_min, s32 a_max)
{
    return (gba_rand() * (a_max - a_min) >> 15) + a_min;
}
#pragma endregion
#pragma region Game Rules
typedef struct Ball{
    s32 x,y,xDir,yDir, size;
    u16 colour;
}Ball;

void StartBall(Ball* a_ball)
{
    while(a_ball->xDir == 0)
    {
        a_ball->xDir = gba_rand_range(-1, 2);
    }
    a_ball->yDir = gba_rand_range(-1, 2);
}
void InitBall(Ball* a_ball, s32 a_x, s32 a_y, s32 a_size, u16 a_colour){
    a_ball->x = a_x;
    a_ball->y = a_y;
    a_ball->size = a_size;
    a_ball->colour = a_colour;
    a_ball->xDir = a_ball->yDir = 0;
    StartBall(a_ball);
}
void MoveBall(Ball* a_ball){
    a_ball ->y += a_ball->yDir;
    if(a_ball->y < 0)
    {
        a_ball->y = 0;
        a_ball->yDir *= -1;
    }
    if(a_ball->y > SCREEN_H - a_ball->size)
    {
        a_ball->y = SCREEN_H - a_ball->size;
        a_ball->yDir *= -1;
    }

    a_ball ->x += a_ball->xDir;
    if(a_ball->x < 0 || a_ball->x > SCREEN_W - a_ball->size)
    {
        a_ball->x = (SCREEN_W >> 1) - (a_ball->size >>1);
        a_ball->y = (SCREEN_H >> 1) - (a_ball->size >>1);
        a_ball->xDir = 0; a_ball->yDir = 0;
        StartBall(a_ball);
    }
}
void DrawBall(Ball* a_ball){
    DrawRect(a_ball->x,a_ball->y,a_ball->size,a_ball->size,a_ball->colour);
}
void ClearBall(Ball* a_ball)
{
    DrawRect(a_ball->x, a_ball->y, a_ball->size,a_ball->size, setColour(0,0,0));
}

typedef struct Paddle{
    s32 x, y, width, height;
    u16 colour;
}Paddle;

void InitPaddle(Paddle* a_paddle, s32 a_x,s32 a_y, s32 a_width, s32 a_height, u16 a_colour)
{
    a_paddle->x = a_x;
    a_paddle->y = a_y;
    a_paddle->width = a_width;
    a_paddle->height = a_height;
    a_paddle->colour = a_colour;
}

void DrawPaddle(Paddle* a_paddle){
    DrawRect(a_paddle->x, a_paddle->y, a_paddle->width,a_paddle->height,a_paddle->colour);
}

void ClearPaddle(Paddle* a_paddle){
    DrawRect(a_paddle->x, a_paddle->y, a_paddle->width,a_paddle->height,setColour(0,0,0));
}
#pragma endregion

int test = 0;
int Tutorial(int mode)
{  

    switch(mode)
        {
            default:
            REGDISCNT = VIDEOMODE_3 | BGMODE_2;
            DrawCool();
            break;

            case 1:
            REGDISCNT = VIDEOMODE_3 |  BGMODE_2;
            while(1)
                {
                    DrawRect(20,20,SCREEN_W - 40, SCREEN_H - 40, setColour(31,5,12));
                }
            break;

            case 2:
            REGDISCNT = VIDEOMODE_3 |  BGMODE_2;
            while(1)
                {
                    DrawLine(10,5,230,5,setColour(1,24,16));
                }
            break;

            case 3:
            REGDISCNT = VIDEOMODE_3 |  BGMODE_2;
            while(1)
                {
                    DrawLine(10,4,230,4,setColour(31,31,31));
                    DrawLine(230,156,10,156,setColour(31,31,31));

                    DrawLine(10,4,230,156,setColour(2,31,15));
                    DrawLine(10,156,230,4,setColour(2,15,31));

                    DrawRect(100,60,40,40, setColour(31,5,12));
                }
            break;

            case 4:
            REGDISCNT = VIDEOMODE_3 |  BGMODE_2;
            seed_gba_rand(23343);
            s32 randVal = gba_rand();
            while(1){
                randVal = gba_rand_range(-20,20);
            }
            break;

            case 5:
            REGDISCNT = VIDEOMODE_3 | BGMODE_2;
            seed_gba_rand(23343);
            Ball ball;
            InitBall(&ball,SCREEN_W >> 1, SCREEN_H >> 1, 10, setColour(31,31,31));

            Paddle p1;
            InitPaddle(&p1, 10,60,8,40,setColour(0,0,31));

            Paddle p2;
            InitPaddle(&p2, SCREEN_W - 18,60,8,40,setColour(31,0,0));
            while(1)
            {
                vsync();
                ClearBall(&ball);
                //ClearPaddle(&p1);
                //ClearPaddle(&p2);

                MoveBall(&ball);
                DrawBall(&ball);
                DrawPaddle(&p1);
                DrawPaddle(&p2);

                DrawLine(10,4,230,4,setColour(31,31,31));
                DrawLine(230,156,10,156,setColour(31,31,31));
            }
            break;

            case 6:
            REGDISCNT = VIDEOMODE_3 | BGMODE_2;
            while(1)
            {
                DrawLine(0,1,SCREEN_W -1,1,setColour(31,0,0));
                DrawLine(0,2,SCREEN_W -1,2,setColour(28,0,0));
                DrawLine(0,3,SCREEN_W -1,3,setColour(24,0,0));
                DrawLine(0,4,SCREEN_W -1,4,setColour(28,0,0));
                DrawLine(0,5,SCREEN_W -1,5,setColour(31,0,0));
                
                //DrawRect(0,6,SCREEN_W ,149,setColour(10,0,0));

                DrawLine(0,159,SCREEN_W -1,159,setColour(31,0,0));
                DrawLine(0,158,SCREEN_W -1,158,setColour(28,0,0));
                DrawLine(0,157,SCREEN_W -1,157,setColour(24,0,0));
                DrawLine(0,156,SCREEN_W -1,156,setColour(28,0,0));
                DrawLine(0,155,SCREEN_W -1,155,setColour(31,0,0));

                    switch(test)
                    {
                        default:
                        DrawRect(20,20,SCREEN_W - 40 ,SCREEN_H - 40,setColour(0,0,0));
                        break;

                        case 1:
                         DrawRect(20,20,SCREEN_W - 40 ,SCREEN_H - 40,setColour(10,20,15));
                        break;

                        case 2:
                        DrawRect(20,20,SCREEN_W - 40 ,SCREEN_H - 40,setColour(20,10,15));
                        break;

                        case 3:
                        DrawRect(20,20,SCREEN_W - 40 ,SCREEN_H - 40,setColour(15,10,20));
                        break;


                    }
                      scanKeys();
                    if (keysDown() & KEY_LEFT) { test--; } 
                    if (keysUp() & KEY_LEFT) {  } 
                    if (keysDown() & KEY_RIGHT) { test++; } 
               

               if(test > 3)
                {
                    test = 0;
                }
                else if(test < 0)
                {
                    test = 3;
                }
               
                
                
                //
            }
            break;

            case 7:
                
            break;



        }
  return 0;
}