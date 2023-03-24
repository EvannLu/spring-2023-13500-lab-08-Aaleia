#pragma once
#include "imageio.h"

void invert(std::string input);
void invert_half(std::string input);
void box(std::string input);
void frame(std::string input); 
void scale(std::string input);
void pixelate(std::string input);
int sobel(int a, int b, int c, int d, int e, int f, int g, int h, int i);
void kernel(std::string input);
