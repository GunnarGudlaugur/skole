#pragma once

// Include Graph_lib library files that holds declarations needed for Window,
// and Shape derivatives.
#include "Graph.h"
#include "GUI.h"



using namespace Graph_lib;

// An abstract class. Concrete classes derived from this base class
// has to implement the member function attach_to().
class Emoji
{
public:
	// Disable copying. Disable slicing, etc.
	Emoji(const Emoji&) = delete;
	Emoji& operator=(const Emoji&) = delete;

	// Deleting the copy constructor also deletes the default constructor.
	// Emoji needs a default constructor.
	Emoji() {}
	// Emoji() = default; // is an alternative way of achieving the same.

	// The pure virtual function that has to be overriden for a deriving class
	// to be instantiable. Every class deriving from Emoji is supposed to
	// attach all its Shapes to a window. This makes the class abstract.
	virtual void attach_to(Graph_lib::Window&) = 0;

	// Relevant because Vector_ref can own Emojis and automatically cleans up.
	// Subject will be visited later in the course.
	virtual ~Emoji() {}
};

// A yellow, empty face.
// An abstract class.
class Face : public Emoji
{
	
	

	Point center;
	int radius;
	Circle face;
	/* TODO:
	 *  - add shapes (private)
	 *  - make the class abstract
	 **/

public:
	Face(Point c, int r);
	virtual void attach_to(Graph_lib::Window& win) override=0;
};

class EmptyFace:public Face
{
protected:
	Point leftEyeCenter ;
	int eyeRadius;
	Point rightEyeCenter ;

	Circle rightEye{rightEyeCenter,eyeRadius};
	Circle leftEye{leftEyeCenter,eyeRadius};

public:
	EmptyFace(Point c, int r);
	
	void attach_to(Graph_lib::Window& win) override;


};


class ghaspFace :public EmptyFace
{
private:
	Point mouth_Center;
	int mouth_radius;
	Circle mouth{mouth_Center,mouth_radius};
public:
	ghaspFace(Point c, int r);

	void attach_to(Graph_lib::Window& win) override;
};

class straightFace :public EmptyFace
{
private:
	Point mStart;
	Point mEnd;
	Line mouth{mStart,mEnd};
public:
	straightFace(Point c, int r);
	void attach_to(Graph_lib::Window& win) override;
};


class winkEye :public EmptyFace
{
protected:
	Circle winkEyeE;
	Point mCenter;
	Point eCenter;
	int sDeg{ 0 };
	int eDeg{180};
	int h;
	int w;

	Arc eye{ mCenter,w,h,sDeg,eDeg };

	Arc mouthA{ eCenter,(w*5),h*2,sDeg+180,eDeg+180 };

public:
	winkEye(Point c, int r);
	void attach_to(Graph_lib::Window& win)override;
};


class sadFace :public winkEye
{
public:
	sadFace(Point c, int r);
	void attach_to(Graph_lib::Window& win)override;

};

//class shockedFace :public EmptyFace
//{
//private:
//	Point startMouth;
//	Point endMouth;
//	Rectangle mouth{startMouth,endMouth};
//public:
//	shockedFace(Point c, int r);
//
//	void attach_to(Graph_lib::Window& win) override;
//};