void	bresenham(t_mlxs *ms, t_vect p1, t_vect p2)
{
	int	dx;
	int	dy;
	int	y;
	int delta;

	dx = p2.x - p1.x;
	dy = p2.y - p1.y;
	delta = 2 * dy - dx;
	y = p1.y;

	while (p1.x <= p2.x)
	{
		put_pixel(p1.x, y, 1);
		if (delta > 0)
		{
			y = y + 1;
			delta = (delta - 2 * dx);
		}
		delta = delta + (2 * dy);
		p1.x++;
	}
}
//test map drawing, works with version 1.1.3
void	draw_map(t_mlxs *ms)
{
	t_line	line;

	line.x0 = 100;
	line.x1 = 110;
	line.y0 = -100;
	line.y1 = 100;
	ms->img1->color = 0xFFFFFFFF;
	put_line(ms, &line);
	ft_printf("got to draw_map\n");
}

/*
0a1
> 
8,9c9,10
<       decisive = (2 * line->dy) - line->dx;
<       while (ppl < line->dx)
---
>       decisive = (2 * line->dx) - line->dy;
>       while (ppl < line->dy)
12c13
<               line->x0 += line->sx;
---
>               line->y0 += line->sy;
14c15
<                       decisive += (2 * line->dy);
---
>                       decisive += (2 * line->dx);
17,18c18,19
<                       line->y0 += line->sy;
<                       decisive += ((2 * line->dy) - (2 * line->dx));
---
>                       line->x0 += line->sx;
>                       decisive += ((2 * line->dx) - (2 * line->dy));
*/