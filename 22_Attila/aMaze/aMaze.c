#include <conio.h>
#include <stdio.h>
#include <time.h>

#include "aMaze.h"
#include "MyConsole.h"
#include "pots.h"

#define DR (1 << 0)
#define DD (1 << 1)
#define DL (1 << 2)
#define DU (1 << 3)

float maze_potentials[maze_height][maze_width];
char maze[maze_height][maze_width];

clock_t generator_start_t;

int forward_sleeptime;

int last_dir;
int act_distance;
int act_depth;
int act_x;
int act_y;

int max_depth;
int max_depth_x;
int max_depth_y;

int stat_R;
int stat_D;
int stat_L;
int stat_U;

void init_maze()
{
    int x,y;

    for (y = 0; y < maze_height; y++)
        for (x = 0; x < maze_width; x++)
            maze[y][x] = 0;
}

inline void set_maze_cell(int FX, int FY, char FValue)
{
    maze[FY][FX]=FValue;

    Set_Console_Cursor_Position(FX, FY);

    printf("%c", FValue);
}

inline void set_maze_cell_forward(int Direction)
{
    switch (Direction)
    {
    case DR:
    {
        act_x++;

        maze[act_y][act_x] = ' ';
        Set_Console_Cursor_Position(act_x, act_y);
        printf("%c", ' ');

        act_x++;

        maze[act_y][act_x] = '<';
        Set_Console_Cursor_Position(act_x, act_y);
        printf("%c", '<');

        stat_R++;

        break;
    }
    case DD:
    {
        act_y++;

        maze[act_y][act_x] = ' ';
        Set_Console_Cursor_Position(act_x, act_y);
        printf("%c", ' ');

        act_y++;

        maze[act_y][act_x] = '^';
        Set_Console_Cursor_Position(act_x, act_y);
        printf("%c", '^');

        stat_D++;

        break;
    }
    case DL:
    {
        act_x--;

        maze[act_y][act_x] = ' ';
        Set_Console_Cursor_Position(act_x, act_y);
        printf("%c", ' ');

        act_x--;

        maze[act_y][act_x] = '>';
        Set_Console_Cursor_Position(act_x, act_y);
        printf("%c", '>');

        stat_L++;

        break;
    }
    case DU:
    {
        act_y--;

        maze[act_y][act_x] = ' ';
        Set_Console_Cursor_Position(act_x, act_y);
        printf("%c", ' ');

        act_y--;

        maze[act_y][act_x] = 'v';
        Set_Console_Cursor_Position(act_x, act_y);
        printf("%c", 'v');

        stat_U++;

        break;
    }
    }

    act_depth += 2;

    if (act_depth > max_depth)
    {
        max_depth = act_depth;
        max_depth_x = act_x;
        max_depth_y = act_y;
    }

    act_distance += 2;

    MySleep(forward_sleeptime);
}

inline void set_maze_cell_backward(int FX, int FY, char FValue)
{
    maze[FY][FX] = ' ';

    Set_Console_Cursor_Position(FX, FY);

    printf("%c", FValue);

    MySleep(maze_generation_backward_sleeptime);
}

inline int is_valid_coord(int fx, int fy)
{
    return
        (fx >= 0)
        &&
        (fx < maze_width)
        &&
        (fy >= 0)
        &&
        (fy < maze_height);
}

inline int can_step_to(int fx, int fy)
{
    if (is_valid_coord(fx, fy))
        if (maze[fy][fx] == 0)
            return 1;

    return 0;
}

inline int get_valid_dirs(int fx, int fy)
{
    return
        (can_step_to(fx+2, fy) << 0)
        |
        (can_step_to(fx, fy+2) << 1)
        |
        (can_step_to(fx-2, fy) << 2)
        |
        (can_step_to(fx, fy-2) << 3);
}

inline int get_double_valid_dirs(int fx, int fy)
{
    return
        (can_step_to(fx+4, fy) << 0)
        |
        (can_step_to(fx, fy+4) << 1)
        |
        (can_step_to(fx-4, fy) << 2)
        |
        (can_step_to(fx, fy-4) << 3);
}


int step_forward()
{
    int valid_dirs = get_valid_dirs(act_x,act_y);

    if (valid_dirs == 0)
        return 0;

    int double_valid_dirs = get_double_valid_dirs(act_x,act_y);

    /*if (double_valid_dirs!=(DR|DD|DL|DU)) // fairplay near borders
        double_valid_dirs=0;*/

    int new_dir,rnd;
    UI R,D,L,U;
    UI cR,cD,cL,cU;

    Set_Console_Text_Color(FCN | BCIM);

    do
    {
        if ((act_distance > maze_min_run) || (! (valid_dirs & last_dir)))
        {
            if (valid_dirs & DR)
                R=(maze_potential_array[act_y][act_x+2] + (double_valid_dirs & DR) ? (maze_potential_array[act_y][act_x+4]):(0))* PDF_R;
            else
                R=0;

            if (valid_dirs & DD)
                D=(maze_potential_array[act_y+2][act_x] + (double_valid_dirs & DD) ? (maze_potential_array[act_y+4][act_x]):(0))* PDF_D;
            else
                D=0;

            if (valid_dirs & DL)
                L=(maze_potential_array[act_y][act_x-2] + (double_valid_dirs & DL) ? (maze_potential_array[act_y][act_x-4]):(0))* PDF_L;
            else
                L=0;

            if (valid_dirs & DU)
                U=(maze_potential_array[act_y-2][act_x] + (double_valid_dirs & DU) ? (maze_potential_array[act_y-4][act_x]):(0))* PDF_U;
            else
                U=0;

            cR=R;
            cD=D;
            cL=L;
            cU=U;

            cD+=cR;
            cL+=cD;
            cU+=cL;

            if (cU<=0)
                return 0;

            // 0.0 ... R ... D ... L ... U(1.0)
            //           ^ random pick

            rnd=rand() % cU; // random pick, cU must be less than RAND_MAX

            if (rnd<=cR)
                new_dir=DR;
            else if (rnd<=cD)
                new_dir=DD;
            else if (rnd<=cL)
                new_dir=DL;
            else
                new_dir=DU;

            act_distance = 0;
        }
        else
            new_dir=last_dir;
    }
    while (!(valid_dirs & new_dir));

    set_maze_cell_forward(new_dir);
    last_dir = new_dir;
    return 1;
}

int step_backward()
{
    Set_Console_Text_Color(FCM | BCN);

    act_depth-=2;

    if (act_distance > maze_run_decrase)
        act_distance -= maze_run_decrase;
    else
        act_distance = 0;

    char tmp = maze[act_y][act_x];

    switch (tmp)
    {
    case '>':
    {
        set_maze_cell_backward(act_x, act_y, tmp);
        act_x++;
        set_maze_cell_backward(act_x, act_y, ' ');
        act_x++;
        return 1;
    }
    case 'v':
    {
        set_maze_cell_backward(act_x, act_y, tmp);
        act_y++;
        set_maze_cell_backward(act_x, act_y, ' ');
        act_y++;
        return 1;
    }
    case '<':
    {
        set_maze_cell_backward(act_x, act_y, tmp);
        act_x--;
        set_maze_cell_backward(act_x, act_y, ' ');
        act_x--;
        return 1;
    }
    case '^':
    {
        set_maze_cell_backward(act_x, act_y, tmp);
        act_y--;
        set_maze_cell_backward(act_x, act_y, ' ');
        act_y--;
        return 1;
    }
    default:
    {
        set_maze_cell_backward(act_x, act_y, ' ');
        return 0;
    }
    }
}

void init_maze_generator()
{
    srand(time(NULL));
    generator_start_t = clock();

    forward_sleeptime=maze_generation_forward_sleeptime;

    last_dir=0;
    act_distance=10000;

    act_depth = 0;
    act_x = 1;
    act_y = 1;

    max_depth = 0;
    max_depth_x = 1;
    max_depth_y = 1;

    stat_R=0;
    stat_D=0;
    stat_L=0;
    stat_U=0;

    init_maze();

    int x,y;

    for (y=0; y<maze_height; y++)
        for (x=0; x<maze_width; x++)
        {
            Set_Console_Text_Color(Bcolormap[(int)((maze_potential_array[y][x]*7.0)/(pots_value_max+1))]);
            Set_Console_Cursor_Position(x,y);
            printf(" ");
        }
}

void generate_maze()
{
    char str[100];

    char c=0;
    int x,y,tmp;

    init_maze_generator();

    // generate path

    while (1)
    {
        if (!step_forward())
            if (!step_backward())
                break;

        if (kbhit())
            switch(getch())
            {
            case 'r':
                init_maze_generator();
                break;
            case '0':
            {
                forward_sleeptime=0;
                break;
            }
            case '1':
            {
                forward_sleeptime=5;
                break;
            }
            case '2':
            {
                forward_sleeptime=10;
                break;
            }
            case '3':
            {
                forward_sleeptime=20;
                break;
            }
            case '4':
            {
                forward_sleeptime=40;
                break;
            }
            case '5':
            {
                forward_sleeptime=50;
                break;
            }
            case '6':
            {
                forward_sleeptime=75;
                break;
            }
            case '7':
            {
                forward_sleeptime=100;
                break;
            }
            case '8':
            {
                forward_sleeptime=150;
                break;
            }
            case '9':
            {
                forward_sleeptime=200;
                break;
            }
            }


        sprintf(str,"%.2f - R:%i,D:%i,L:%i,U:%i",(clock() - generator_start_t) / (double)CLOCKS_PER_SEC,stat_R,stat_D,stat_L,stat_U);
        SetConsoleTitle(str);
    }

    // generate walls
    // http://www.asciitable.com/

    Set_Console_Text_Color(FCIW | BCN);

    for (y=0; y<maze_height; y++)
        for (x=0; x<maze_width; x++)
        {
            if (maze[y][x]==0)
            {
                tmp=0;

                if (is_valid_coord(x+1,y))
                    if (maze[y][x+1] != '.' && maze[y][x+1] != ' ')
                        tmp|=DR;

                if (is_valid_coord(x,y+1))
                    if (maze[y+1][x] != '.' && maze[y+1][x] != ' ')
                        tmp|=DD;

                if (is_valid_coord(x-1,y))
                    if (maze[y][x-1] != '.' && maze[y][x-1] != ' ')
                        tmp|=DL;

                if (is_valid_coord(x,y-1))
                    if (maze[y-1][x] != '.' && maze[y-1][x] != ' ')
                        tmp|=DU;

                switch (tmp)
                {
                //   DR,DD,DL,DU
                case 00|00|00|DU:
                    c=179;
                    break; // ┼
                case 00|00|DL|00:
                    c=196;
                    break; // ─
                case 00|00|DL|DU:
                    c=217;
                    break; // ┘
                case 00|DD|00|00:
                    c=179;
                    break; // │
                case 00|DD|00|DU:
                    c=179;
                    break; // │
                case 00|DD|DL|00:
                    c=191;
                    break; // ┐
                case 00|DD|DL|DU:
                    c=180;
                    break; // ┤
                case DR|00|00|00:
                    c=196;
                    break; // ─
                case DR|00|00|DU:
                    c=192;
                    break; // └
                case DR|00|DL|00:
                    c=196;
                    break; // ─
                case DR|00|DL|DU:
                    c=193;
                    break; // ┴
                case DR|DD|00|00:
                    c=218;
                    break; // ┌
                case DR|DD|00|DU:
                    c=195;
                    break; // ├
                case DR|DD|DL|00:
                    c=194;
                    break; // ┬
                case DR|DD|DL|DU:
                    c=197;
                    break; // ┼
                    //   DR,DD,DL,DU
                }

                Set_Console_Text_Color(Fcolormap[(int)((maze_potential_array[y][x]*7.0)/(pots_value_max+1))]);

                set_maze_cell(x,y,c);
            }
            else
                set_maze_cell(x,y,' ');
        }

    // Start
    Set_Console_Text_Color(FCIG | BCN);
    set_maze_cell(1,1,'O');

    // Finish
    Set_Console_Text_Color(FCIR | BCN);
    set_maze_cell(max_depth_x,max_depth_y,'X');
}
