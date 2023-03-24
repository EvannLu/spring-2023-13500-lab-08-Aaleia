#include <iostream> 
#include "imageio.h"
#include "funcs.h"

int main() {
  invert("inImage.pgm");
  invert_half("inImage.pgm");
  box("inImage.pgm");
  frame("inImage.pgm");
  scale("inImage.pgm");
  pixelate("inImage.pgm");
  kernel("inImage.pgm");
}
