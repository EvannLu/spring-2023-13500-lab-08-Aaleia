main: main.o imageio.o funcs.o
	g++ -o main main.o imageio.o funcs.o

sample: sample.o imageio.o
	g++ -o sample sample.o imageio.o

sample.o: sample.cpp imageio.h

imageio.o: imageio.cpp imageio.h

main.o: main.cpp imageio.h funcs.h

funcs.o: imageio.h funcs.cpp funcs.h

clean:
	rm -f *.o main sample outImage.pgm taskA.pgm taskB.pgm taskC.pgm taskD.pgm taskE.pgm taskF.pgm taskG.pgm
