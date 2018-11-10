#pragma once
#define _USE_MATH_DEFINES
#include <memory>
#include <cmath>

class renderer
{
public:
	renderer(int width = 0, int height = 0);
	~renderer();

	void setpixel(int x, int y);
	void bresenham(int x0, int y0, int x1, int y1);
	void testLine();

	unsigned char *buf; // buffer
	int W = 0;
	int H = 0;
};

