void	swap(double *a, double *b)
{
	double temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

double	get_fract(double n)
{
	return (ceil(n) - n);
}

void	draw_line(t_mlxs *ms, t_vect p1, t_vect p2)
{
	double	dx;
	double	dy;

	if (fabs(p1.y - p2.y) > fabs(p1.x - p2.x))
		ms->steep = 1;
	else
		ms->steep = 0;
	if (ms->steep)
	{
		swap(&p1.x, &p1.y);
		swap(&p2.x, &p2.y);
	}
	if (p2.x < p1.x)
	{
		swap(&p1.x, &p2.x);
		swap(&p1.y, &p2.y);
	}
	dx = p2.x - p1.x;
	dy = p2.y - p1.y;
	if (dx == 0)
		ms->gradient = 1;
	else
		ms->gradient = dy / dx;
	plot_coords(ms, p1, p2);
	}

void	plot_coords(t_mlxs *ms, t_vect p1, t_vect p2)
{
	while (p1.x <= p2.x)
	{
		if (ms->steep)
			draw_slope(ms, p1.y, p1.x);
		else
			draw_slope(ms, p1.x, p1.y);
		p1.y += ms->gradient;
		p1.x++;
	}
}

void	draw_slope(t_vct *ms, double x, double y)
{
	t_img	*img;

	if (!ms->toggle)
		img = ms->img1;
	else
		img = ms->img2;
	if (ms->gradient >= 0)
	{
		put_pixel(img, floor(x), y, 1 - get_fract(y));
		put_pixel(img, floor(x) + 1, y, get_fract(y));
	}
	else if (ms->gradient < 0)
	{
		put_pixel(img, floor(x), y, 1 - get_fract(y));
		put_pixel(img, floor(x) - 1, y, get_fract(y));
	}
}


void	put_pixel(t_img *img, int x, int y, double alpha)
{
	char			*painter;
	int				color;
	unsigned int	a;

	if (!alpha)
		return ;
	a = img->color;
	a = a >> 24;
	a = a * alpha;
	color = (a << 24) + (img->color - (img->color & 0xFF000000));
	painter = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int*)painter = color;
}

int invert_endian(int color)
{
	int transp;
	int red;
	int green;
	int blue;

	blue = color & 0xFF000000;
	green = color & 0x00FF0000;
	red = color & 0x0000FF00;
	transp = color & 0x000000FF;
	color = (transp << 24) + (red << 8) + (green >> 8) + (blue >> 24);
	return (color);
}

/*put pixel color argument has to be multiplied by get_fract on the alpha(or T) bit


function plot(x, y, c) is
    plot the pixel at (x, y) with brightness c (where 0 ≤ c ≤ 1)

// integer part of x
function ipart(x) is
    return floor(x)

function round(x) is
    return ipart(x + 0.5)

// fractional part of x
function fpart(x) is
    return x - ipart(x)

function rfpart(x) is
    return 1 - fpart(x)

function drawLine(x0,y0,x1,y1) is
    boolean steep := abs(y1 - y0) > abs(x1 - x0)
    
    if steep then
        swap(x0, y0)
        swap(x1, y1)
    end if
    if x0 > x1 then
        swap(x0, x1)
        swap(y0, y1)
    end if
    
    dx := x1 - x0
    dy := y1 - y0

    if dx == 0.0 then
        gradient := 1.0
    else
        gradient := dy / dx
    end if

    // handle first endpoint
    xend := round(x0)
    yend := y0 + gradient * (xend - x0)
    xgap := rfpart(x0 + 0.5)
    xpxl1 := xend // this will be used in the main loop
    ypxl1 := ipart(yend)
    if steep then
        plot(ypxl1,   xpxl1, rfpart(yend) * xgap)
        plot(ypxl1+1, xpxl1,  fpart(yend) * xgap)
    else
        plot(xpxl1, ypxl1  , rfpart(yend) * xgap)
        plot(xpxl1, ypxl1+1,  fpart(yend) * xgap)
    end if
    intery := yend + gradient // first y-intersection for the main loop
    
    // handle second endpoint
    xend := round(x1)
    yend := y1 + gradient * (xend - x1)
    xgap := fpart(x1 + 0.5)
    xpxl2 := xend //this will be used in the main loop
    ypxl2 := ipart(yend)
    if steep then
        plot(ypxl2  , xpxl2, rfpart(yend) * xgap)
        plot(ypxl2+1, xpxl2,  fpart(yend) * xgap)
    else
        plot(xpxl2, ypxl2,  rfpart(yend) * xgap)
        plot(xpxl2, ypxl2+1, fpart(yend) * xgap)
    end if
    
    // main loop
    if steep then
        for x from xpxl1 + 1 to xpxl2 - 1 do
           begin
                plot(ipart(intery)  , x, rfpart(intery))
                plot(ipart(intery)+1, x,  fpart(intery))
                intery := intery + gradient
           end
    else
        for x from xpxl1 + 1 to xpxl2 - 1 do
           begin
                plot(x, ipart(intery),  rfpart(intery))
                plot(x, ipart(intery)+1, fpart(intery))
                intery := intery + gradient
           end
    end if
end function


*/