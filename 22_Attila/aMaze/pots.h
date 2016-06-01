#ifndef POTS_H_INCLUDED
#define POTS_H_INCLUDED

#include "aMaze.h"

#define pots_value_max 1000

extern const int pot_ones[maze_height][maze_width];
extern const int pot_2dsin[maze_height][maze_width];
extern const int pot_cosxsin[maze_height][maze_width];
extern const int pot_xyramp[maze_height][maze_width];
extern const int pot_yramp[maze_height][maze_width];
extern const int pot_exyramp[maze_height][maze_width];
extern const int pot_saddle[maze_height][maze_width];
extern const int pot_logflower[maze_height][maze_width];
extern const int pot_logpeak[maze_height][maze_width];

#endif // POTS_H_INCLUDED
