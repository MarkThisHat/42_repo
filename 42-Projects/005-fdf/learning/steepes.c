
{
	int	decisive;
	int	ppl;

	decisive = 0;
	ppl = 0;
	put_a_pixel(img, *line);
	decisive = (2 * line->dx) - line->dy;
	while (ppl < line->dy)
	{
		ppl++;
		line->y0 += line->sy;
		if (decisive < 0)
			decisive += (2 * line->dx);
		else
		{
			line->x0 += line->sx;
			decisive += ((2 * line->dx) - (2 * line->dy));
		}
		put_a_pixel(img, *line);
	}
}
