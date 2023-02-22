/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bres3d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 15:08:24 by maalexan          #+#    #+#             */
/*   Updated: 2023/02/22 16:52:32 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
//https://www.geeksforgeeks.org/bresenhams-algorithm-for-3-d-line-drawing/
//https://youtu.be/EzJP9uwV3ms
//https://www.baeldung.com/cs/3d-point-2d-plane
//https://en.wikipedia.org/wiki/Isometric_projection
int xs;
int ys;
int zs;

l->dx = abs(x2 - x1);
l->dy = abs(y2 - y1);
l->dz = abs(z2 - z1);
if (x2 > x1)
	xs = 1;
else
	xs = -1;
if (y2 > y1)
	ys = 1;
else
	ys = -1;
if (z2 > z1)
	zs = 1;
else
	zs = -1;

// Driving axis is X-axis"
if (l->dx >= l->dy && l->dx >= l->dz) {
	int p1 = 2 * l->dy - l->dx;
	int p2 = 2 * l->dz - l->dx;
	while (x1 != x2) {
	x1 += xs;
	if (p1 >= 0) {
		y1 += ys;
		p1 -= 2 * l->dx;
	}
	if (p2 >= 0) {
		z1 += zs;
		p2 -= 2 * l->dx;
	}
	p1 += 2 * l->dy;
	p2 += 2 * l->dz;
	}

	// Driving axis is Y-axis"
}
else if (l->dy >= l->dx && l->dy >= l->dz) {
	int p1 = 2 * l->dx - l->dy;
	int p2 = 2 * l->dz - l->dy;
	while (y1 != y2) {
	y1 += ys;
	if (p1 >= 0) {
		x1 += xs;
		p1 -= 2 * l->dy;
	}
	if (p2 >= 0) {
		z1 += zs;
		p2 -= 2 * l->dy;
	}
	p1 += 2 * l->dx;
	p2 += 2 * l->dz;
	}

	// Driving axis is Z-axis"
}
else {
	int p1 = 2 * l->dy - l->dz;
	int p2 = 2 * l->dx - l->dz;
	while (z1 != z2) {
	z1 += zs;
	if (p1 >= 0) {
		y1 += ys;
		p1 -= 2 * l->dz;
	}
	if (p2 >= 0) {
		x1 += xs;
		p2 -= 2 * l->dz;
	}
	p1 += 2 * l->dy;
	p2 += 2 * l->dx;
	}
}
return ListOfPoints;


/**\



void plotLine3d(int x0, int y0, int z0, int x1, int y1, int z1)
{
	int	dx = abs(x1-x0);
	int	dy = abs(y1-y0); 
	int	dz = abs(z1-z0); 
	int	sx = x0<x1 ? 1 : -1;
	int	sy = y0<y1 ? 1 : -1; 
	int	sz = z0<z1 ? 1 : -1; 
	int	dm = max(dx,dy,dz), 
	int	i = dm; //maximum difference
	x1 = dm/2;
	y1 = dm/2;
	z1 = dm/2; //error offset
 
   for(;;) {  //loop
	  setPixel(x0,y0,z0);
	  if (i-- == 0) break;
	  x1 -= dx; if (x1 < 0) { x1 += dm; x0 += sx; } 
	  y1 -= dy; if (y1 < 0) { y1 += dm; y0 += sy; } 
	  z1 -= dz; if (z1 < 0) { z1 += dm; z0 += sz; } 
   }
}

\**/




/***************************************\
starting cpp modded code
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;



vector<vector<int> > Bresenham3D(int x1, int y1, int z1,
								int x2, int y2, int z2)
{
vector<vector<int> > ListOfPoints;
ListOfPoints.push_back({ x1, y1, z1 });


int dx = abs(x2 - x1);
int dy = abs(y2 - y1);
int dz = abs(z2 - z1);
int xs;
int ys;
int zs;
if (x2 > x1)
	xs = 1;
else
	xs = -1;
if (y2 > y1)
	ys = 1;
else
	ys = -1;
if (z2 > z1)
	zs = 1;
else
	zs = -1;

// Driving axis is X-axis"
if (dx >= dy && dx >= dz) {
	int p1 = 2 * dy - dx;
	int p2 = 2 * dz - dx;
	while (x1 != x2) {
	x1 += xs;
	if (p1 >= 0) {
		y1 += ys;
		p1 -= 2 * dx;
	}
	if (p2 >= 0) {
		z1 += zs;
		p2 -= 2 * dx;
	}
	p1 += 2 * dy;
	p2 += 2 * dz;
	ListOfPoints.push_back({ x1, y1, z1 });
	}

	// Driving axis is Y-axis"
}
else if (dy >= dx && dy >= dz) {
	int p1 = 2 * dx - dy;
	int p2 = 2 * dz - dy;
	while (y1 != y2) {
	y1 += ys;
	if (p1 >= 0) {
		x1 += xs;
		p1 -= 2 * dy;
	}
	if (p2 >= 0) {
		z1 += zs;
		p2 -= 2 * dy;
	}
	p1 += 2 * dx;
	p2 += 2 * dz;
	ListOfPoints.push_back({ x1, y1, z1 });
	}

	// Driving axis is Z-axis"
}
else {
	int p1 = 2 * dy - dz;
	int p2 = 2 * dx - dz;
	while (z1 != z2) {
	z1 += zs;
	if (p1 >= 0) {
		y1 += ys;
		p1 -= 2 * dz;
	}
	if (p2 >= 0) {
		x1 += xs;
		p2 -= 2 * dz;
	}
	p1 += 2 * dy;
	p2 += 2 * dx;
	ListOfPoints.push_back({ x1, y1, z1 });
	}
}
return ListOfPoints;

// This code is contributed by ishankhandelwals.

/**\ originalcode


void plotLine3d(int x0, int y0, int z0, int x1, int y1, int z1)
{
   int dx = abs(x1-x0), sx = x0<x1 ? 1 : -1;
   int dy = abs(y1-y0), sy = y0<y1 ? 1 : -1; 
   int dz = abs(z1-z0), sz = z0<z1 ? 1 : -1; 
   int dm = max(dx,dy,dz), i = dm; //
   x1 = y1 = z1 = dm/2; //
 
   for(;;) {  //
      setPixel(x0,y0,z0);
      if (i-- == 0) break;
      x1 -= dx; if (x1 < 0) { x1 += dm; x0 += sx; } 
      y1 -= dy; if (y1 < 0) { y1 += dm; y0 += sy; } 
      z1 -= dz; if (z1 < 0) { z1 += dm; z0 += sz; } 
   }
}

\**/





/****************************************\
cpp bresenham origi:
 
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

vector<vector<int> > Bresenham3D(int x1, int y1, int z1,
								int x2, int y2, int z2)
{
vector<vector<int> > ListOfPoints;
ListOfPoints.push_back({ x1, y1, z1 });
int dx = abs(x2 - x1);
int dy = abs(y2 - y1);
int dz = abs(z2 - z1);
int xs;
int ys;
int zs;
if (x2 > x1)
	xs = 1;
else
	xs = -1;
if (y2 > y1)
	ys = 1;
else
	ys = -1;
if (z2 > z1)
	zs = 1;
else
	zs = -1;

// Driving axis is X-axis"
if (dx >= dy && dx >= dz) {
	int p1 = 2 * dy - dx;
	int p2 = 2 * dz - dx;
	while (x1 != x2) {
	x1 += xs;
	if (p1 >= 0) {
		y1 += ys;
		p1 -= 2 * dx;
	}
	if (p2 >= 0) {
		z1 += zs;
		p2 -= 2 * dx;
	}
	p1 += 2 * dy;
	p2 += 2 * dz;
	ListOfPoints.push_back({ x1, y1, z1 });
	}

	// Driving axis is Y-axis"
}
else if (dy >= dx && dy >= dz) {
	int p1 = 2 * dx - dy;
	int p2 = 2 * dz - dy;
	while (y1 != y2) {
	y1 += ys;
	if (p1 >= 0) {
		x1 += xs;
		p1 -= 2 * dy;
	}
	if (p2 >= 0) {
		z1 += zs;
		p2 -= 2 * dy;
	}
	p1 += 2 * dx;
	p2 += 2 * dz;
	ListOfPoints.push_back({ x1, y1, z1 });
	}

	// Driving axis is Z-axis"
}
else {
	int p1 = 2 * dy - dz;
	int p2 = 2 * dx - dz;
	while (z1 != z2) {
	z1 += zs;
	if (p1 >= 0) {
		y1 += ys;
		p1 -= 2 * dz;
	}
	if (p2 >= 0) {
		x1 += xs;
		p2 -= 2 * dz;
	}
	p1 += 2 * dy;
	p2 += 2 * dx;
	ListOfPoints.push_back({ x1, y1, z1 });
	}
}
return ListOfPoints;
}

int main()
{
int x1 = -1;
int y1 = 1;
int z1 = 1;
int x2 = 5;
int y2 = 3;
int z2 = -1;
vector<vector<int> > ListOfPoints
	= Bresenham3D(x1, y1, z1, x2, y2, z2);
cout << "The generated points are:" << endl;
for (auto it : ListOfPoints)
	cout << it[0] << " " << it[1] << " " << it[2]
	<< endl;
return 0;
}

// This code is contributed by ishankhandelwals.






/*************************************************************\


function Matrice = bresenham_line_3D(x1, y1, z1, x2, y2, z2,Matrice)
%Jean CHAOUI
%ENST Bretagne
%15-11-2007
%x1, y1, z1: coordinates of first point
%x2, y2, z2: coordinates of second point
%Matrice: 3D matrix which represents the volume that we draw the line
%inside.


    pixel(1) = x1;
    pixel(2) = y1;
    pixel(3) = z1;
    dx = x2 - x1;
    dy = y2 - y1;
    dz = z2 - z1;
    
	if (dx < 0)
		x_inc = -1; 
	else
		x_inc=1;

	l = abs(dx);

	if (dy < 0)
		y_inc = -1 ;
    else
		y_inc=1;

	m = abs(dy);
    
    if (dz < 0)
    z_inc = -1 ;
    else
        z_inc=1;
    end
    
    n = abs(dz);
    
	dx2 = 2*l ;//dx2 = 2^l ;
	dy2 = 2*m ;//dy2 = 2^m ;
	dz2 = 2*n ;//dz2 = 2^n ; 

    if ((l >= m) & (l >= n))
	{
        err_1 = dy2 - l;
        err_2 = dz2 - l;
        for (i = 1:1:l) 
			Matrice(pixel(1),pixel(2),pixel(3))=Matrice(pixel(1),pixel(2),pixel(3))+1;
			if (err_1 > 0)
			{
				pixel(2)= pixel(2) + y_inc;
				err_1 = err_1 - dx2;
			}
			if (err_2 > 0) 
			{
                pixel(3) = pixel(3)+ z_inc;
                err_2 = err_2 - dx2;
			}
            err_1 = err_1 + dy2;
            err_2 = err_2 + dz2;
            pixel(1) = pixel(1)+x_inc;
	}  
    else if ((m >= l) & (m >= n))
	{
		err_1 = dx2 - m;
		err_2 = dz2 - m;
		for (i =1:1: m) 
			Matrice(pixel(1),pixel(2),pixel(3))=Matrice(pixel(1),pixel(2),pixel(3))+1;
			if (err_1 > 0)
			{
				pixel(1) = pixel(1) + x_inc;
				err_1 = err_1 - dy2;
			}
			if (err_2 > 0)
			{
                pixel(3) = pixel(3) + z_inc;
                err_2 = err_2 - dy2;
			}
			err_1 = err_1 + dx2;
			err_2 = err_2 + dz2;
			pixel(2) = pixel(2) + y_inc;
	}
    else
	{
		err_1 = dy2 - n;
		err_2 = dx2 - n;
		for (i=1:1:n) 
			Matrice(pixel(1),pixel(2),pixel(3))=Matrice(pixel(1),pixel(2),pixel(3))+1;
            if (err_1 > 0)
			{
				pixel(2) = pixel(2) + y_inc;
				err_1 = err_1 - dz2;
			}
			if (err_2 > 0)
			{
				pixel(1) = pixel(1) + x_inc;
				err_2 = err_2 - dz2;
			}
            err_1 = err_1 + dy2;
            err_2 = err_2 + dx2;
            pixel(3) = pixel(3) + z_inc;  
    }
	Matrice(pixel(1),pixel(2),pixel(3))=Matrice(pixel(1),pixel(2),pixel(3))+1;

	\*******************************************************/
