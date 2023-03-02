#include "../incl/fdf.h"


void	add_color(int *color, int *dye, int bitshift)
{
		int	temp;
		int ff;

		ff = 255;
		temp = *color >> bitshift;
		temp += 10;
		if (temp > ff)
			temp = ff;
		*color -= *color & (ff << bitshift);
		*color += temp << bitshift;
		*dye = 0xFF000000;
}


int		add_factor(int color, int factor)
{
	int red;
	int green;
	int blue;

	red = color & 0x00FF0000 >> 16;
	green = color & 0x0000FF00 >> 8;
	blue = color & 0x000000FF;
	if (red)
		red += factor;
	if (red > 255)
		red = 255;
	if (green)
		green += factor;
	if (green > 255)
		green = 255;
	if (blue)
		blue += factor;
	if (blue > 255)
		blue = 255;
	return ((red << 16) + (green << 8) + blue);
}

int		put_colors(int color, int factor)
{
	int red_goal;
	int green_goal;
	int blue_goal;

	red_goal = color & 0x00FF0000 >> 16;
	if (red_goal > 255)
		red_goal = 255;
	if (red_goal < 1)
		red_goal = 1;
	green_goal = color & 0x0000FF00 >> 8;
	if (green_goal > 255)
		green_goal = 255;
	if (green_goal < 1)
		green_goal = 1;
	blue_goal = color & 0x000000FF;
	if (blue_goal > 255)
		blue_goal = 255;
	if (blue_goal < 1)
		blue_goal = 1;
	red_goal /= factor;
	green_goal /= factor;
	blue_goal /= factor;
	return ((red_goal << 16) + (green_goal << 8) + blue_goal);
}
