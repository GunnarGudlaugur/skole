#include "Emoji.h"
#include "Graph_lib.h"

/*
 * Implement your emojis in this file.
 **/

// A yellow, empty face.
Face::Face(Point c, int r) :center{ c }, radius{ r }, face{ c, r }
{
	/* TODO:
	 *  - add member initializer list
	 *  - implement the constructor. I.e. fill color
	 **/
	face.set_fill_color(Color::yellow);
}


void Face::attach_to(Graph_lib::Window& win){
	win.attach(face);
}

EmptyFace::EmptyFace(Point c, int r) :leftEyeCenter{ c.x - (r / 3),c.y - (r / 5) }, rightEyeCenter{ c.x + (r / 3),c.y - (r / 5) }, eyeRadius{r/6}, Face(c, r) {
	rightEye.set_fill_color(Color::black);
	leftEye.set_fill_color(Color::black);

}
void EmptyFace::attach_to(Graph_lib::Window& win) {
	Face::attach_to(win);
	win.attach(leftEye);
	win.attach(rightEye);
}



ghaspFace::ghaspFace(Point c, int r) :mouth_Center{ c.x ,c.y+ (r / 2) }, mouth_radius{r/4}, EmptyFace{ c,r }{
	mouth.set_fill_color(Color::black);
}

void ghaspFace::attach_to(Graph_lib::Window& win){
	EmptyFace::attach_to(win);
	win.attach(mouth);
}

straightFace::straightFace(Point c, int r) :mStart{ c.x - (r / 3),c.y + (r / 5) }, mEnd{ c.x + (r / 3),c.y + (r / 4) }, EmptyFace{ c,r }{
	mouth.set_color(Color::black);
}

void straightFace::attach_to(Graph_lib::Window& win) {
	EmptyFace::attach_to(win);
	win.attach(mouth);
}

winkEye::winkEye(Point c, int r) :winkEyeE{ {c.x - (r / 3), c.y - (r / 5)},r / 6 }, EmptyFace{ c,r }, mCenter{ c.x - (r / 3),c.y - (r / 3) }, w{ r / 5 }, h{ r / 4 }, eCenter{c.x,c.y+(r/5)}{
	eye.set_color(Color::black);
	mouthA.set_color(Color::black);
	leftEye.set_fill_color(Color::yellow);
	leftEye.set_color(Color::yellow);
}


void winkEye::attach_to(Graph_lib::Window& win) {
	EmptyFace::attach_to(win);
	win.attach(eye);
	win.attach(mouthA);
}

sadFace::sadFace(Point c, int r) :winkEye{ c,r }{
	leftEye.set_fill_color(Color::black);
	eye.set_color(Color::yellow);
	
}

void sadFace::attach_to(Graph_lib::Window& win) {
	winkEye::attach_to(win);
}




/* TODO:
 *  - define more emojis.
 **/

//shockedFace::shockedFace(Point c, int r) :startMouth{ c.x,c.y }, endMouth{ c.x,c.y }, EmptyFace{ c,r }{
//	mouth.set_fill_color(Color::white);
//}
//void shockedFace::attach_to(Graph_lib::Window& win) {
//	EmptyFace::attach_to(win);
//	win.attach(mouth);
//}