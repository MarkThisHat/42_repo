{
	int	decisive;
	int	ppl;

	decisive = 0;
	ppl = 0;
	put_a_pixel(img, *line);
	decisive = (2 * line->dy) - line->dx;
	while (ppl < line->dx)
	{
		ppl++;
		line->x0 += line->sx;
		if (decisive < 0)
			decisive += (2 * line->dy);
		else
		{
			line->y0 += line->sy;
			decisive += ((2 * line->dy) - (2 * line->dx));
		}
		put_a_pixel(img, *line);
	}
}
