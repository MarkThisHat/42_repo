double floor_round(double x)
{
	return (floor(x + 0.5));
}

double fpart(double x)
{
	return (x - floor_round(x));
}

double rfpart(double x)
{
	return (1 - fpart(x));
}

void	xiao(t_mlxs *ms, int x0, int x1, int y0, int y1)
{
	double	dx;
	double	dy;

	if (fabs(y1 - y0) > fabs(x1 - x0))
		ms->steep = 1;
	if (ms->steep)
	{
		swap(x0, y0);
		swap(x1, y1);
	}
	if (x0 > x1)
	{
		swap(x0, x1);
		swap(y0, y1);
	}
	dx = x1 - x0;
	dy = y1 - y0;
	if (!dx)
		ms->gradient = 1;
	else
		ms->gradient = dy / dx;
	//first endpoint?
	double xend = floor_round(x0);
	double yend = y0 + ms->gradient * (xend - x0);
	double xgap = rfpart(x0 + 0.5);
	double xpxl1 = xend;
	double ypxl1 = floor(yend);
	if (ms->steep)
	{
		put_pixel(ms, ypxl1, xpxl1, rfpart(yend) * xgap);
		put_pixel(ms, ypxl1 + 1, xpxl1, fpart(yend) * xgap);
	}
	else
	{
		put_pixel(ms, xpxl1, ypxl1, rfpart(yend) * xgap);
		put_pixel(ms, xpxl1, ypxl1 + 1, fpart(yend) * xgap);
	}
	double intery = yend + gradient //tf is an y-intersection for main loop?
	//second endpoint?
	xend = floor_round(x1);
	yend = y1 + gradient * (xend - x1);
	xgap = fpart(x1 + 0.5);
	xpxl2 = xend; //main loop?
	ypxl2 = floor(yend);
	if(ms->steep)
	{
		put_pixel(ms, ypxl2, xpxl2, rfpart(yend) * xgap);
		put pixel(ypxl2 + 1, xpxl2,  fpart(yend) * xgap);
	}
	else
	{
		put_pixel(ms, xpxl2, ypxl2, rfpart(yend) * xgap);
		put_pixel(ms, xpxl2, ypxl2 + 1, fpart(yend) * xgap);
	}
	//main loop
	if (ms->steep)
	{
		int x = xpxl1 + 1;
		while(x < xpxl2 - 1)
		{
			put_pixel(ms, floor(intery), x, rfpart(intery));
			put_pixel(ms, floor(intery)+1, x, fpart(intery));
			intery += gradient;
			x++;
		}
	}
	else
	{
		x = xpxl1 + 1;
		while(x < xpxl2 - 1)
		{
			put_pixel(ms, x, floor(intery),  rfpart(intery));
			put_pixel(ms, x, floor(intery) + 1, fpart(intery));
			intery += gradient;
			x++;
		}
	}
}

/*

//ORIGINAL ALGORITHM FROM https://en.wikipedia.org/wiki/Xiaolin_Wu%27s_line_algorithm
function plot(x, y, c) is
    plot the pixel at (x, y) with brightness c (where 0 ≤ c ≤ 1)

// integer part of x should be ok (using math floor func)
function ipart(x) is
    return floor(x)

function round(x) is //changed to floor_round (could be ceil?)
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

/*
first draft
void	xiao(t_mlxs *ms, t_vect p1, t_vect p2)
{
	double	dx;
	double	dy;

	if (fabs(y1 - y0) > fabs(x1 - x0))
		ms->steep = 1;
	if (ms->steep)
	{
		swap(x0, y0);
		swap(x1, y1);
	}
	if (x0 > x1)
	{
		swap(x0, x1);
		swap(y0, y1);
	}
	dx = x1 - x0;
	dy = y1 - y0;
	if (!dx)
		ms->gradient = 1;
	else
		ms->gradient = dy / dx;
	//first endpoint?
	xend = round(x0);
	yend = y0 + ms->gradient * (xend - x0);
	xgap = rfpart(x0 + 0.5);
	xpxl1 = xend;
	ypxl1 = ipart(yend);
	if (ms->steep)
	{
		plot(ypxl1, xpxl1, rfpart(yend) * xgap);
		plot(ypxl1 + 1, xpxl1, fpart(yend) * xgap);
	}
	else
	{
		plot(xpxl1, ypxl1, rfpart(yend) * xgap);
		plot(xpxl1, ypxl1 + 1, fpart(yend) * xgap);
	}
	intery += yend + gradient //tf is an y-intersection for main loop?
	//second endpoint?
	xend = round(x1);
	yend = y1 + gradient * (xend - x1);
	xgap = fpart(x1 + 0.5);
	xpxl2 = xend; //main loop?
	ypxl2 = ipart(yend);
	if(ms->steep)
	{
		plot(ypxl2, xpxl2, rfpart(yend) * xgap);
		plot(ypxl2 + 1, xpxl2,  fpart(yend) * xgap);
	}
	else
	{
		plot(xpxl2, ypxl2, rfpart(yend) * xgap);
		plot(xpxl2, ypxl2 + 1, fpart(yend) * xgap);
	}
	//main loop
	if (ms->steep)
	{
		x = xpxl1 + 1;
		while(x < xpxl2 - 1)
		{
			plot(ipart(intery), x, rfpart(intery));
			plot(ipart(intery)+1, x, fpart(intery));
			intery := intery + gradient;
			x++;
		}
	}
	else
	{
		x = xpxl1 + 1;
		while(x < xpxl2 - 1)
		{
			plot(x, ipart(intery),  rfpart(intery));
			plot(x, ipart(intery)+1, fpart(intery));
			intery := intery + gradient;
			x++;
		}
	}
}

*************
FIRST DRAFT
***********


void	wu_xiao(t_mlxs *ms, double x0, double x1, double y0, double y1)
{
	ft_printf("got to wuxiao\n");
	double	dx;
	double	dy;

	if (fabs(y1 - y0) > fabs(x1 - x0))
		ms->steep = 1;
	if (ms->steep)
	{
		swap(&x0, &y0);
		swap(&x1, &y1);
	}
	if (x0 > x1)
	{
		swap(&x0, &x1);
		swap(&y0, &y1);
	}
	dx = x1 - x0;
	dy = y1 - y0;
	if (!dx)
		ms->gradient = 1;
	else
		ms->gradient = dy / dx;
	//first endpoint?
	double xend = floor_round(x0);
	double yend = y0 + ms->gradient * (xend - x0);
	double xgap = rfpart(x0 + 0.5);
	double xpxl1 = xend;
	double ypxl1 = floor(yend);
	if (ms->steep)
	{
		put_pixel(ms->img1, ypxl1, xpxl1, rfpart(yend) * xgap);
		put_pixel(ms->img1, ypxl1 + 1, xpxl1, fpart(yend) * xgap);
	}
	else
	{
		put_pixel(ms->img1, xpxl1, ypxl1, rfpart(yend) * xgap);
		put_pixel(ms->img1, xpxl1, ypxl1 + 1, fpart(yend) * xgap);
	}
	double intery = yend + ms->gradient; //tf is an y-intersection for main loop?
	//second endpoint?
	xend = floor_round(x1);
	yend = y1 + ms->gradient * (xend - x1);
	xgap = fpart(x1 + 0.5);
	int xpxl2 = xend; //main loop?
	int ypxl2 = floor(yend);
	if(ms->steep)
	{
		put_pixel(ms->img1, ypxl2, xpxl2, rfpart(yend) * xgap);
		put_pixel(ms->img1, ypxl2 + 1, xpxl2,  fpart(yend) * xgap);
	}
	else
	{
		put_pixel(ms->img1, xpxl2, ypxl2, rfpart(yend) * xgap);
		put_pixel(ms->img1, xpxl2, ypxl2 + 1, fpart(yend) * xgap);
	}
	//main loop
	if (ms->steep)
	{
		int x = xpxl1 + 1;
		while(x < xpxl2 - 1)
		{
			put_pixel(ms->img1, floor(intery), x, rfpart(intery));
			put_pixel(ms->img1, floor(intery)+1, x, fpart(intery));
			intery += ms->gradient;
			x++;
		}
	}
	else
	{
		int x = xpxl1 + 1;
		while(x < xpxl2 - 1)
		{
			put_pixel(ms->img1, x, floor(intery),  rfpart(intery));
			put_pixel(ms->img1, x, floor(intery) + 1, fpart(intery));
			intery += ms->gradient;
			x++;
		}
	}
}

*/