#ifndef AMAZE_H_INCLUDED
#define AMAZE_H_INCLUDED

#include "base.h"

#define maze_width  145
#define maze_height 145

#define maze_min_run  0
#define maze_run_decrase 0

#define maze_generation_forward_sleeptime 100
#define maze_generation_backward_sleeptime 0

extern float maze_potentials[maze_height][maze_width];
extern char maze[maze_height][maze_width];

#define PDF_R 10.0
#define PDF_D 2.0
#define PDF_L 2.0
#define PDF_U 2.0

#define maze_potential_array pot_logpeak

void generate_maze();

#endif // AMAZE_H_INCLUDED
