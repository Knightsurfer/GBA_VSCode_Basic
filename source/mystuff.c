#include "mystuff/draw.h"


float counter,offset,offset;

void DrawStuff(int mode, int index)
{
    
    


    
    REGDISCNT = VIDEOMODE_3 | BGMODE_2;
       DrawBackground(0);
    while(1)
    {
        
        counter+= 0.2;
        
        
        
    if(counter > 0.5)
    {
       
        counter = 0;
       
       
       
       

        


        offset+=3;
    }
    if(offset > SCREEN_W)
    {
        offset = 0;
    } 
       
       DrawSprite(0, offset,407);
       
        
        vsync();
        DrawSprite(1, offset,407);
    }
}