/*
** wall_sky_ground.c for wolf3d in /home/nguye_1//afs_loc/projects/igraph/wolf3d-2017-nguye_1
**
** Made by alexandre1 nguyen
** Login   <nguye_1@epitech.net>
**
** Started on  Sat Jan 12 22:17:39 2013 alexandre1 nguyen
** Last update Mon Dec 15 17:36:23 2014 Alexandre NGUYEN
*/

#include <mlx.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "list.h"

void	sky(img_param *param, int x)
{
  int	i;

  i = 0;
  param->color = 0x9DD8D600;
  while (i != param->height / 2)
    {
      my_ppti_from_xpm(param, param->sky, x, i);
      i += 1;
    }
}

void	ground(img_param *param, int x)
{
  int	i;

  i = 0;
  /* param->color = 0x24464800; */
  param->color = 0x24464800;
  while (i != param->height / 2)
    {
      my_pixel_put_to_image(param, param->img, x, param->height / 2 + i);
      i += 1;
    }
}

void	wall(img_param *param, int x, int wall)
{
  int	i;

  i = 0;
  param->color = 0x09141800;
  if ((int)param->coord.g_y < 8 &&
      param->wall->lab[((int)param->coord.g_y) + 1][((int)param->coord.g_x)] == 0)
    param->color = 0x192E4300;
  else if ((int)param->coord.g_x < 8 &&
	   param->wall->lab[((int)param->coord.g_y)][((int)param->coord.g_x) + 1] == 0)
    param->color = 0x09141800;
  else if ((int)param->coord.g_y > 0 &&
	   param->wall->lab[((int)param->coord.g_y) - 1][((int)param->coord.g_x)] == 0)
    param->color = 0x25414500;
  else if ((int)param->coord.g_x > 0 &&
	   param->wall->lab[((int)param->coord.g_y)][((int)param->coord.g_x) + 1] == 0)
    param->color = 0x9AD8D500;
  while (i <= wall)
    {
      if (wall >= param->height)
	wall = param->height;
      my_pixel_put_to_image(param, param->img, x, ((param->height - wall) /
						   2) + i);
      i += 1;
    }
}