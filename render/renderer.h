#pragma once

#include <memory>

class renderer
{
public:
	renderer(unsigned int width = 0, unsigned int height = 0);
	~renderer();

	int *buf; // buffer
};

