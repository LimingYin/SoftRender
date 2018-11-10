#include "renderer.h"

renderer::renderer(int width, int height):W(width), H(height)
{
	buf = new unsigned char[W * H * 3];
	memset(buf, 255, W*H*3);
}

renderer::~renderer()
{
	delete buf;
}

void renderer::setpixel(int x, int y) {
	unsigned char* p = buf + (y * W + x) * 3;
	p[0] = p[1] = p[2] = 0;
}

// Modified from  https://rosettacode.org/wiki/Bitmap/Bresenham%27s_line_algorithm#C
void renderer::bresenham(int x0, int y0, int x1, int y1) {
	int dx = abs(x1 - x0), sx = x0 < x1 ? 1 : -1;
	int dy = abs(y1 - y0), sy = y0 < y1 ? 1 : -1;
	int err = (dx > dy ? dx : -dy) / 2;

	while (setpixel(x0, y0), x0 != x1 || y0 != y1) {
		int e2 = err;
		if (e2 > -dx) { err -= dy; x0 += sx; }
		if (e2 < dy) { err += dx; y0 += sy; }
	}
}

void renderer::testLine()
{
	float cx = W * 0.5f - 0.5f, cy = H * 0.5f - 0.5f;
	for (int j = 0; j < 5; j++) {
		float r1 = fminf(W, H) * (j + 0.5f) * 0.085f;
		float r2 = fminf(W, H) * (j + 1.5f) * 0.085f;
		float t = j * M_PI / 64.0f;
		for (int i = 1; i <= 64; i++, t += 2.0f * M_PI / 64.0f) {
			float ct = cosf(t), st = sinf(t);
			bresenham((int)(cx + r1 * ct), (int)(cy - r1 * st), (int)(cx + r2 * ct), (int)(cy - r2 * st));
		}
	}
}
