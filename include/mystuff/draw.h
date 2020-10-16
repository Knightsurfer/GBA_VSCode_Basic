#include "tutorial/registers.h"

int haircolour=        000511;
int dungaree =   060000;
int bro =     000037;
int skins=        057734;



int hair =        000511;
int dungarees =   060000;
int brother =     000037;
int skin =        057734;
int background = 000012;

#pragma region Basic Shapes
void DrawBigPixel(s32 x, s32 y, u16 colour)
{
    PlotPixel(x + 0,y + 0, colour);
    PlotPixel(x + 1,y + 0, colour);
    PlotPixel(x + 0,y + 1, colour);
    PlotPixel(x + 1,y + 1, colour);
}

void DrawBigLine(int x,int y, int x2, int y2, u16 colour)
{
    for(int i = 0; i < x2; i+=2)
    {
        
        DrawBigPixel(x + i, y, colour);
        if(y < y2)
        {y+=2;}
    }
}
#pragma endregion

#pragma region Sprites
void DrawSprite(int sprite,int posx,int posy)
{
    switch(sprite)
    {
        default: // Mario
        PlotPixel(posx + 6,posy + 0,brother);
        PlotPixel(posx + 7,posy + 0,brother);
        PlotPixel(posx + 8,posy + 0,brother);
        PlotPixel(posx + 9,posy + 0,brother);
        PlotPixel(posx + 10,posy+ 0,brother);

        PlotPixel(posx + 5,posy + 1,brother);
        PlotPixel(posx + 6,posy + 1,brother);
        PlotPixel(posx + 7,posy + 1,brother);
        PlotPixel(posx + 8,posy + 1,brother);
        PlotPixel(posx + 9,posy + 1,brother);
        PlotPixel(posx + 10,posy + 1,brother);
        PlotPixel(posx + 11,posy + 1,brother);
        PlotPixel(posx + 12,posy + 1,brother);
        PlotPixel(posx + 13,posy + 1,brother);

        PlotPixel(posx + 5 ,posy +  2,  hair );   
	    PlotPixel(posx +  6 ,posy +  2 , hair );    
	    PlotPixel(posx +  7 ,posy +  2 , hair );   
	    PlotPixel(posx +  8 ,posy +  2 , skin ); 
	    PlotPixel(posx +  9 ,posy +  2 , skin ); 
	    PlotPixel(posx +  10,posy +  2 , hair);    
	    PlotPixel(posx +  11, posy + 2 , skin ); 
	
	
	PlotPixel(posx +  4 ,posy +  3 , hair );   
	PlotPixel(posx +  5 ,posy +  3 , skin ); 
	PlotPixel(posx +  6 ,posy +  3 , hair );   
	PlotPixel(posx +  7 ,posy +  3 , skin ); 
	PlotPixel(posx +  8 ,posy +  3 , skin ); 
	PlotPixel(posx +  9 ,posy +  3 , skin ); 
	PlotPixel(posx +  10 ,posy +  3 , hair );   
	PlotPixel(posx +  11 ,posy +  3 , skin ); 
	PlotPixel(posx +  12 ,posy +  3 , skin ); 
	PlotPixel(posx +  13 ,posy +  3 , skin ); 
	
	
	PlotPixel(posx +  4 ,posy +  4 , hair );   
	PlotPixel(posx +  5 ,posy +  4 , skin ); 
	PlotPixel(posx +  6 ,posy +  4 , hair );   
	PlotPixel(posx +  7 ,posy +  4 , hair );   
	PlotPixel(posx +  8 ,posy +  4 , skin ); 
	PlotPixel(posx +  9 ,posy +  4 , skin ); 
	PlotPixel(posx +  10 ,posy +  4 , skin ); 
	PlotPixel(posx +  11, posy + 4,  hair );   
	PlotPixel(posx +  12 , posy + 4, skin ); 
	PlotPixel(posx +  13 , posy +4,  skin ); 
	PlotPixel(posx +  14 ,  posy +4,  skin ); 
	
	
	PlotPixel(posx +  4 ,posy +   5 , hair );   
	PlotPixel(posx +  5 ,posy +   5 , hair );   
	PlotPixel(posx +  6 ,posy +   5 , skin ); 
	PlotPixel(posx +  7 ,posy +   5 , skin ); 
	PlotPixel(posx +  8 ,posy +   5 , skin ); 
	PlotPixel(posx + 9 ,posy +   5 , skin ); 
	PlotPixel(posx +  10 ,posy +   5 , hair );   
	PlotPixel(posx +  11 ,posy +   5 , hair );   
	PlotPixel(posx +  12 ,posy +   5 , hair );   
	PlotPixel(posx +  13 ,posy +   5 , hair );   
	
	
	PlotPixel(posx +  5 ,posy +   6 , skin ); 
	PlotPixel(posx +  6 ,posy +   6 , skin ); 
	PlotPixel(posx +  7 ,posy +   6 , skin ); 
	PlotPixel(posx +  8 , posy +  6 , skin ); 
	PlotPixel(posx +  9 ,posy +   6 , skin ); 
	PlotPixel(posx +  10 ,posy +   6 , skin ); 
	PlotPixel(posx +  11 ,posy +   6 , skin ); 
	PlotPixel(posx +  12 ,posy +   6 , skin ); 

    PlotPixel(posx +   5  ,posy +    7 , brother	);
	PlotPixel(posx +   6  ,posy +    7 , brother 	);
	PlotPixel(posx +   7  ,posy +    7 , dungarees	);
	PlotPixel(posx +   8  ,posy +    7 , brother	);
	PlotPixel(posx +   9  ,posy +    7 , brother	);
	PlotPixel(posx +   10 ,posy +    7 , brother	);
	
	PlotPixel(posx +   4 ,posy +    8 , brother );
	PlotPixel(posx +   5 ,posy +    8 , brother );
	PlotPixel(posx +   6 ,posy +    8 , brother );
	PlotPixel(posx +   7 ,posy +    8 , dungarees );
	PlotPixel(posx +   8 ,posy +    8 , brother );
	PlotPixel(posx +   9 ,posy +    8 , brother );
	PlotPixel(posx +   10 ,posy +    8 , dungarees );
	PlotPixel(posx +   11 ,posy +    8 , brother );
	PlotPixel(posx +   12 ,posy +    8 , brother );
	PlotPixel(posx +   13 ,posy +    8 , brother );
	
	PlotPixel(posx +   3 ,posy +    9 , brother );
	PlotPixel(posx +   4 ,posy +    9 , brother );
	PlotPixel(posx +   5 ,posy +    9 , brother );
	PlotPixel(posx +   6 ,posy +    9 , brother );
	PlotPixel(posx +   7 ,posy +    9 , dungarees );
	PlotPixel(posx +   8 ,posy +    9 , dungarees );
	PlotPixel(posx +   9 ,posy +    9 , dungarees );
	PlotPixel(posx +   10 ,posy +    9 , dungarees );
	PlotPixel(posx +   11 ,posy +    9 , brother );
	PlotPixel(posx +  12 ,posy +    9 , brother );
	PlotPixel(posx +   13 ,posy +    9 , brother );
	PlotPixel(posx +   14 ,posy +    9 , brother );
	
	PlotPixel(posx +   3 ,posy +    10 , skin ); 
	PlotPixel(posx +   4 ,posy +    10 , skin ); 
	PlotPixel(posx +   5 ,posy +    10 , brother );
	PlotPixel(posx +   6 ,posy +    10 , dungarees );
	PlotPixel(posx +   7 ,posy +    10 , skin ); 
	PlotPixel(posx +   8 ,posy +    10 , dungarees );
	PlotPixel(posx +   9 ,posy +    10 , dungarees );
	PlotPixel(posx +   10 ,posy +    10 , skin ); 
	PlotPixel(posx +   11 ,posy +    10 , dungarees );
	PlotPixel(posx +   12 ,posy +    10 , brother );
	PlotPixel(posx +   13 ,posy +    10 , skin ); 
	PlotPixel(posx +   14 ,posy +    10 , skin ); 
	
	PlotPixel(posx +   3 ,posy +    11 , skin ); 
	PlotPixel(posx +   4 ,posy +    11 , skin ); 
	PlotPixel(posx +   5 ,posy +    11 , skin ); 
	PlotPixel(posx +   6 ,posy +    11 , dungarees );
	PlotPixel(posx +   7 ,posy +    11 , dungarees );
	PlotPixel(posx +   8 ,posy +    11 , dungarees );
	PlotPixel(posx +   9 ,posy +    11 , dungarees );
	PlotPixel(posx +   10 ,posy +    11 , dungarees );
	PlotPixel(posx +   11 ,posy +    11 , dungarees );
	PlotPixel(posx +   12 ,posy +    11 , skin ); 
	PlotPixel(posx +   13 ,posy +    11 , skin ); 
	PlotPixel(posx +   14 ,posy +    11 , skin ); 
	
	PlotPixel(posx +   3 ,posy +    12 , skin ); 
	PlotPixel(posx +   4 ,posy +    12 , skin ); 
	PlotPixel(posx +   5 ,posy +    12 , dungarees );
	PlotPixel(posx +   6 ,posy +    12 , dungarees );
	PlotPixel(posx +   7 ,posy +    12 , dungarees );
	PlotPixel(posx +   8 ,posy +    12 , dungarees );
	PlotPixel(posx +   9 ,posy +    12 , dungarees );
	PlotPixel(posx +   10 ,posy +    12 , dungarees );
	PlotPixel(posx +   11 ,posy +    12 , dungarees );
	PlotPixel(posx +   12 ,posy +    12 , dungarees );
	PlotPixel(posx +   13 ,posy +    12 , skin ); 
	PlotPixel(posx +   14 ,posy +    12 , skin ); 
	
	PlotPixel(posx +   5 ,posy +    13 , dungarees );
	PlotPixel(posx +   6 ,posy +    13 , dungarees );
	PlotPixel(posx +   7 ,posy +    13 , dungarees );
	PlotPixel(posx +   10 ,posy +    13 , dungarees );
	PlotPixel(posx +   11 ,posy +    13 , dungarees );
	PlotPixel(posx +   12 ,posy +    13 , dungarees );
	
	PlotPixel(posx +   4 ,posy +    14 , hair );   
	PlotPixel(posx +   5 ,posy +    14 , hair );   
	PlotPixel(posx +  6 ,posy +    14 , hair );   
	PlotPixel(posx +   11 ,posy +    14 , hair );   
	PlotPixel(posx +   12 ,posy +    14 , hair );   
	PlotPixel(posx +   13 ,posy +    14 , hair );   


	PlotPixel(posx +   3 ,posy +    15 , hair );   
	PlotPixel(posx +   4 ,posy +    15 , hair );   
	PlotPixel(posx +   5 ,posy +    15 , hair );   
	PlotPixel(posx +  6 ,posy +    15 , hair );   
	PlotPixel(posx +   11 ,posy +    15 , hair );   
	PlotPixel(posx +   12 ,posy +    15 , hair );   
	PlotPixel(posx +   13 ,posy +    15 , hair );   
	PlotPixel(posx +   14 ,posy +    15 , hair );   
// =================================================================	
        break;

        case 1:
        PlotPixel(posx + 6,posy + 0,background);
        PlotPixel(posx + 7,posy + 0,background);
        PlotPixel(posx + 8,posy + 0,background);
        PlotPixel(posx + 9,posy + 0,background);
        PlotPixel(posx + 10,posy+ 0,background);

        PlotPixel(posx + 5,posy + 1,background);
        PlotPixel(posx + 6,posy + 1,background);
        PlotPixel(posx + 7,posy + 1,background);
        PlotPixel(posx + 8,posy + 1,background);
        PlotPixel(posx + 9,posy + 1,background);
        PlotPixel(posx + 10,posy + 1,background);
        PlotPixel(posx + 11,posy + 1,background);
        PlotPixel(posx + 12,posy + 1,background);
        PlotPixel(posx + 13,posy + 1,background);

        PlotPixel(posx + 5 ,posy +  2,  background );   
	    PlotPixel(posx +  6 ,posy +  2 , background );    
	    PlotPixel(posx +  7 ,posy +  2 , background );   
	    PlotPixel(posx +  8 ,posy +  2 , background ); 
	    PlotPixel(posx +  9 ,posy +  2 , background ); 
	    PlotPixel(posx +  10,posy +  2 , background);    
	    PlotPixel(posx +  11, posy + 2 , background ); 
	
	
	PlotPixel(posx +  4 ,posy +  3 , background );   
	PlotPixel(posx +  5 ,posy +  3 , background ); 
	PlotPixel(posx +  6 ,posy +  3 , background );   
	PlotPixel(posx +  7 ,posy +  3 , background ); 
	PlotPixel(posx +  8 ,posy +  3 , background ); 
	PlotPixel(posx +  9 ,posy +  3 , background ); 
	PlotPixel(posx +  10 ,posy +  3 , background );   
	PlotPixel(posx +  11 ,posy +  3 , background ); 
	PlotPixel(posx +  12 ,posy +  3 , background ); 
	PlotPixel(posx +  13 ,posy +  3 , background ); 
	
	
	PlotPixel(posx +  4 ,posy +  4 , background );   
	PlotPixel(posx +  5 ,posy +  4 , background ); 
	PlotPixel(posx +  6 ,posy +  4 , background );   
	PlotPixel(posx +  7 ,posy +  4 , background );   
	PlotPixel(posx +  8 ,posy +  4 , background ); 
	PlotPixel(posx +  9 ,posy +  4 , background ); 
	PlotPixel(posx +  10 ,posy +  4 , background ); 
	PlotPixel(posx +  11, posy + 4,  background );   
	PlotPixel(posx +  12 , posy + 4, background ); 
	PlotPixel(posx +  13 , posy +4,  background ); 
	PlotPixel(posx +  14 ,  posy +4,  background ); 
	
	
	PlotPixel(posx +  4 ,posy +   5 , background );   
	PlotPixel(posx +  5 ,posy +   5 , background );   
	PlotPixel(posx +  6 ,posy +   5 , background ); 
	PlotPixel(posx +  7 ,posy +   5 , background ); 
	PlotPixel(posx +  8 ,posy +   5 , background ); 
	PlotPixel(posx + 9 ,posy +   5 , background ); 
	PlotPixel(posx +  10 ,posy +   5 , background );   
	PlotPixel(posx +  11 ,posy +   5 , background );   
	PlotPixel(posx +  12 ,posy +   5 , background );   
	PlotPixel(posx +  13 ,posy +   5 , background );   
	
	
	PlotPixel(posx +  5 ,posy +   6 , background ); 
	PlotPixel(posx +  6 ,posy +   6 , background ); 
	PlotPixel(posx +  7 ,posy +   6 , background ); 
	PlotPixel(posx +  8 , posy +  6 , background ); 
	PlotPixel(posx +  9 ,posy +   6 , background ); 
	PlotPixel(posx +  10 ,posy +   6 , background ); 
	PlotPixel(posx +  11 ,posy +   6 , background ); 
	PlotPixel(posx +  12 ,posy +   6 , background ); 

    PlotPixel(posx +   5  ,posy +    7 , background	);
	PlotPixel(posx +   6  ,posy +    7 , background 	);
	PlotPixel(posx +   7  ,posy +    7 , background	);
	PlotPixel(posx +   8  ,posy +    7 , background	);
	PlotPixel(posx +   9  ,posy +    7 , background	);
	PlotPixel(posx +   10 ,posy +    7 , background	);
	
	PlotPixel(posx +   4 ,posy +    8 , background );
	PlotPixel(posx +   5 ,posy +    8 , background );
	PlotPixel(posx +   6 ,posy +    8 , background );
	PlotPixel(posx +   7 ,posy +    8 , background );
	PlotPixel(posx +   8 ,posy +    8 , background );
	PlotPixel(posx +   9 ,posy +    8 , background );
	PlotPixel(posx +   10 ,posy +    8 , background );
	PlotPixel(posx +   11 ,posy +    8 , background );
	PlotPixel(posx +   12 ,posy +    8 , background );
	PlotPixel(posx +   13 ,posy +    8 , background );
	
	PlotPixel(posx +   3 ,posy +    9 , background );
	PlotPixel(posx +   4 ,posy +    9 , background );
	PlotPixel(posx +   5 ,posy +    9 , background );
	PlotPixel(posx +   6 ,posy +    9 , background );
	PlotPixel(posx +   7 ,posy +    9 , background );
	PlotPixel(posx +   8 ,posy +    9 , background );
	PlotPixel(posx +   9 ,posy +    9 , background );
	PlotPixel(posx +   10 ,posy +    9 , background );
	PlotPixel(posx +   11 ,posy +    9 , background );
	PlotPixel(posx +  12 ,posy +    9 , background );
	PlotPixel(posx +   13 ,posy +    9 , background );
	PlotPixel(posx +   14 ,posy +    9 , background );
	
	PlotPixel(posx +   3 ,posy +    10 , background ); 
	PlotPixel(posx +   4 ,posy +    10 , background ); 
	PlotPixel(posx +   5 ,posy +    10 , background );
	PlotPixel(posx +   6 ,posy +    10 , background );
	PlotPixel(posx +   7 ,posy +    10 , background ); 
	PlotPixel(posx +   8 ,posy +    10 , background );
	PlotPixel(posx +   9 ,posy +    10 , background );
	PlotPixel(posx +   10 ,posy +    10 , background ); 
	PlotPixel(posx +   11 ,posy +    10 , background );
	PlotPixel(posx +   12 ,posy +    10 , background );
	PlotPixel(posx +   13 ,posy +    10 , background ); 
	PlotPixel(posx +   14 ,posy +    10 , background ); 
	
	PlotPixel(posx +   3 ,posy +    11 , background ); 
	PlotPixel(posx +   4 ,posy +    11 , background ); 
	PlotPixel(posx +   5 ,posy +    11 , background ); 
	PlotPixel(posx +   6 ,posy +    11 , background );
	PlotPixel(posx +   7 ,posy +    11 , background );
	PlotPixel(posx +   8 ,posy +    11 , background );
	PlotPixel(posx +   9 ,posy +    11 , background );
	PlotPixel(posx +   10 ,posy +    11 , background );
	PlotPixel(posx +   11 ,posy +    11 , background );
	PlotPixel(posx +   12 ,posy +    11 , background ); 
	PlotPixel(posx +   13 ,posy +    11 , background ); 
	PlotPixel(posx +   14 ,posy +    11 , background ); 
	
	PlotPixel(posx +   3 ,posy +    12 , background ); 
	PlotPixel(posx +   4 ,posy +    12 , background ); 
	PlotPixel(posx +   5 ,posy +    12 , background );
	PlotPixel(posx +   6 ,posy +    12 , background );
	PlotPixel(posx +   7 ,posy +    12 , background );
	PlotPixel(posx +   8 ,posy +    12 , background );
	PlotPixel(posx +   9 ,posy +    12 , background );
	PlotPixel(posx +   10 ,posy +    12 , background );
	PlotPixel(posx +   11 ,posy +    12 , background );
	PlotPixel(posx +   12 ,posy +    12 , background );
	PlotPixel(posx +   13 ,posy +    12 , background ); 
	PlotPixel(posx +   14 ,posy +    12 , background ); 
	
	PlotPixel(posx +   5 ,posy +    13 , background );
	PlotPixel(posx +   6 ,posy +    13 , background );
	PlotPixel(posx +   7 ,posy +    13 , background );
	PlotPixel(posx +   10 ,posy +    13 , background );
	PlotPixel(posx +   11 ,posy +    13 , background );
	PlotPixel(posx +   12 ,posy +    13 , background );
	
	PlotPixel(posx +   4 ,posy +    14 , background );   
	PlotPixel(posx +   5 ,posy +    14 , background );   
	PlotPixel(posx +  6 ,posy +    14 , background );   
	PlotPixel(posx +   11 ,posy +    14 , background );   
	PlotPixel(posx +   12 ,posy +    14 , background );   
	PlotPixel(posx +   13 ,posy +    14 , background );   


	PlotPixel(posx +   3 ,posy +    15 , background );   
	PlotPixel(posx +   4 ,posy +    15 , background );   
	PlotPixel(posx +   5 ,posy +    15 , background );   
	PlotPixel(posx +  6 ,posy +    15 , background );   
	PlotPixel(posx +   11 ,posy +    15 , background );   
	PlotPixel(posx +   12 ,posy +    15 , background );   
	PlotPixel(posx +   13 ,posy +    15 , background );   
	PlotPixel(posx +   14 ,posy +    15 , background );   
        break;
    }
}
#pragma endregion

void DrawBackground(int backdrop)
{
    switch(backdrop)
    {
        default:
        DrawBigLine(0,0,SCREEN_W,0,setColour(31,0,0));
        DrawBigLine(0,2,SCREEN_W,2,setColour(28,0,0));
        DrawBigLine(0,4,SCREEN_W,4,setColour(24,0,0));
        DrawBigLine(0,6,SCREEN_W,6,setColour(28,0,0));
        DrawBigLine(0,8,SCREEN_W,8,setColour(31,0,0));
        for(int i = 10; i < 150; i += 2)
        {
            DrawBigLine(0, i, SCREEN_W, i, setColour(10,0,0));
        }
        DrawBigLine(0,150,SCREEN_W,148,setColour(31,0,0));
        DrawBigLine(0,152,SCREEN_W,150,setColour(28,0,0));
        DrawBigLine(0,154,SCREEN_W,152,setColour(24,0,0));
        DrawBigLine(0,156,SCREEN_W,154,setColour(28,0,0));
        DrawBigLine(0,158,SCREEN_W,156,setColour(31,0,0));
        break;

        case 1:
        break;
    }
}
