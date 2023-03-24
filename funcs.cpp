#include <iostream>
#include <cmath>
#include "imageio.h"


// Task A

void invert(std::string input) {
  int image[MAX_H][MAX_W];
  int height, width;
  readImage(input, image, height, width);
  int inverted[MAX_H][MAX_W];

  for (int row = 0; row < height; row++) {
    for(int col = 0; col < width; col++) {
      inverted[row][col] = abs(255 - image[row][col]);
    }
  }
  writeImage("taskA.pgm", inverted, height, width);
}


// Task B

void invert_half(std::string input) {
  int image[MAX_H][MAX_W];
  int h, w;
  readImage(input, image, h, w); 
  int inverted2[MAX_H][MAX_W];
  for (int row = 0; row < h; row++) {
    for (int col = 0; col < w; col++) {
      if (col >= w/2){
	inverted2[row][col] = abs(255 - image[row][col]);
      } else if (col < w/2) {
	inverted2[row][col] = image[row][col];
      }
    }
  }
  writeImage("taskB.pgm", inverted2, h, w);
}


// Task C

void box(std::string input) {
  int img[MAX_H][MAX_W];
  int box[MAX_H][MAX_W];
  int h, w;
  readImage(input, img, h, w);

  for (int row = 0; row < h; row++) {
    for (int col = 0; col < w; col++) {
      if ((row > h/4) && (row < h*0.75) && (col < w*0.75) && (col > w/4)) {
        box[row][col] = 255;
      } else {
        box[row][col] = img[row][col];
      }
    }
  }
  writeImage("taskC.pgm", box, h, w);
}


// Task D

void frame(std::string input) {
  int height, width;
  int image[MAX_H][MAX_W];
  int framed[MAX_H][MAX_W] = {0};
  readImage(input, image, height, width);
  for (int row = 0; row < height; row++) {
    for (int col = 0; col < width; col++) {
      framed[row][col] = image[row][col];
    }
  }
  for (int row = height/4; row < height * 3/4; row++) {
    for (int col = width/4; col < width * 3/4; col++) {
      if (row == height / 4 || row == height * 3/4 - 1 || col == width / 4 || col == width * 3/4 - 1) {
        framed[row][col] = 255;
      }
    }
  }
  writeImage("taskD.pgm", framed, height, width);
}



// Task E

void scale(std::string input) {
  int img[MAX_H][MAX_W]; 
  int scaled[MAX_H][MAX_W];
  int height, width;
  readImage(input, img, height, width);
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      scaled[i*2][j*2] = img[i][j];
      scaled[i*2][j*2 + 1] = img[i][j];
      scaled[i*2 + 1][j*2] = img[i][j];
      scaled[i*2 + 1][j*2 + 1] = img[i][j];
    }
  }
  height *= 2;
  width *= 2;
  writeImage("taskE.pgm", scaled, height, width);
}


// Task F

void pixelate(std::string input) {
  int img[MAX_H][MAX_W];
  int h, w;
  readImage(input, img, h, w);
  int pixelated[MAX_H][MAX_W];
  for (int row = 0; row < h; row += 2) {
    for (int col = 0; col < w; col += 2) {
      int avg = round((img[row][col] + img[row + 1][col] + img[row][col + 1] + img[row + 1][col + 1]) / 4);
      pixelated[row][col] = avg;
      pixelated[row+1][col] = avg;
      pixelated[row][col+1] = avg;
      pixelated[row+1][col+1] = avg;
    }
  }
  writeImage("taskF.pgm", pixelated, h, w);
}


// Bonus - Task G

int sobel(int a, int b, int c, int d, int e, int f, int g, int h, int i) {
  if (a > 255) {
    a = 0;
  }
  if (b > 255) {
    b = 0;
  }
  if (c > 255) {
   c = 0;
  }
  if (d > 255) {
    d = 0;
  }
  if (e > 255) {
    e = 0;
  }
  if (f > 255) {
    f = 0;
  }
  if (g > 255) {
    g = 0;
  }
  if (h > 255) {
    h = 0;
  }
  if (i > 255) {
    i = 0;
  }
  return ((g+(2*h)+i) - (a+(2*b)+c));
}

void kernel(std::string input) {
  int img[MAX_H][MAX_W];
  int h, w;
  readImage(input, img, h, w);
  int kerneled[MAX_H][MAX_W];
  for (int row = 0; row < h; row++) {
    for (int col = 0; col < w; col++) {
      int value = sobel(img[row-1][col-1], img[row-1][col], img[row-1][col+1], img[row][col-1], img[row][col], img[row][col+1], img[row+1][col-1], img[row+1][col], img[row+1][col+1]);
      if (value < 0){
	value = 0;
      } else if (value > 255) {
	value = 255;
      }
      if (row == 0 || row == h - 1 || col == 0 || col == w - 1) {
        value = 0;
      }
      kerneled[row][col] = value;
    }
  }
  writeImage("taskG.pgm", kerneled, h, w);
}
