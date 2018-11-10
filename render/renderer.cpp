#include "renderer.h"

renderer::renderer(unsigned int width, unsigned int height)
{
	buf = (int*)calloc(width * height, sizeof(int));
}

renderer::~renderer()
{
	delete buf;
}
