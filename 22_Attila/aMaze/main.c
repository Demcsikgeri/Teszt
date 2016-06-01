#include <stdio.h>
#include <conio.h>

#include "MyConsole.h"
#include "aMaze.h"
#include "pots.h"

int main()
{
    Set_Console_FullScreen();
    Set_Console_Buffer_Sizes(maze_width,maze_height+1);

    while(1)
    {
        generate_maze();

        //solve_maze()

        getch();
    }

    return 0;
}

