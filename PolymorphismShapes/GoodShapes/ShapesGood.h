/*
 *  Header File: ShapesGood.h
 *
 *  Created on: Nov 27, 2017
 *      Author: Darian Lio
 *      Course: CMPE320
 *      Title: ShapesGood
 */

#ifndef SHAPESGOOD_H_
#define SHAPESGOOD_H_

#include <string>

using namespace std;

////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////         									  FILLABLE										    	   /////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Parent class that is called when a shape needs to be filled
class Fillable{
public:
	Fillable();							//Default Constructor
	Fillable(const string&);			//Main constructor with input parameter of the fillable colour
	virtual ~Fillable();				//Destructor
	string getFillColour() const;		//Getter to get filled colour
protected:
	virtual void fill() = 0;			//initialize empty method fill()
private:
	string fillColour;					//initialize string of colour to be filled
};

////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////         									  LABELED													/////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Parent class that is called when a shape needs to be labeled
class Labeled{
public:
	Labeled();							//Default Constructor
	Labeled(const string&);				//Main constructor with input parameter of the text label
	virtual ~Labeled();					//Destructor
	string getText() const;				//Getter to get text label
protected:
	virtual void fillText() = 0;		//initialize empty method fillText() that will be inherited
private:
	string text;						//initialize string of text label
};

////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////         									  SHAPE													   /////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Base class that is inherited from the rest of the shapes
class Shape {
public:
	Shape();											//Default Constructor
	Shape(const int&, const int&, const string&);		//Initialize Main constructor with input parameter of the width, length, and borderColour respectively
	virtual ~Shape();									//Destructor
	int getLength() const;								//Getter to get length of shape
	int getWidth() const;								//Getter to get width of shape
	string getBorderColour() const;						//Getter to get border colour of shape
	virtual void draw() = 0;							//Initialize empty method draw() that will be inherited
private:
	int width;											//initialize width of shape
	int length;											//initialize length of shape
	string borderColour;								//initialize border colour of the shape

protected:
	virtual void drawOutside() = 0;						//initialize empty method drawOutside() that will be inherited
};

////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////         									  SQUARE										    	   /////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Sub Class Square that is inherited from the Shape class
class Square : public Shape{
public:
	Square(const int&, const int&, const string&);		//Main constructor with input parameter of the width, length, and border colour respectively
	virtual ~Square();									//Destructor
	virtual void draw(){								//Adding argument in inherited draw() indicating that border colour is used to draw the outside shape
		drawOutside();
	}
protected:
	virtual void drawOutside();							//inherited from base class to be called
};

////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////         									  FILLED SQUARE											   /////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Sub Class FilledSquare inherited from the Square class, and extending parent class Fillable to indicate a filled shape
class FilledSquare : public Square, Fillable{
public:
	FilledSquare(const int&, const int&, const string&, const string&);				//Main Constructor containing input parameters of width, length, border colour, and fill colour respectively
	virtual ~FilledSquare();														//Destructor
	virtual void draw(){															//Adding argument in inherited draw() to indicate square can draw border and filled with with a colour
		drawOutside();
		fill();
	}
protected:
	virtual void fill();															//inherited from the extended class Fillable
};

////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////         									  FILLED TEXT SQUARE									   /////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Sub Class FilledTextSquare inherited from the FilledSquare class, and extending parent class Labeled to get the text label
class FilledTextSquare : public FilledSquare, Labeled{
public:
	FilledTextSquare(const int&, const int&, const string&, const string&, const string&);		//Main constructor containing input parameters of width, length, border colour, fill colour, and text label
	virtual ~FilledTextSquare();																//Destructor
	virtual void draw(){																		//Adding argument in inherited draw() to indicate filled text square has a drawn border colour, filled colour, and label
		drawOutside();
		fill();
		fillText();
	}
protected:
	virtual void fillText();																	//inherited from extended class Labeled
};

////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////         									  CIRCLE												   /////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Sub Class Circle inherited from base class Shape
class Circle : public Shape{
public:
	Circle(const int&, const int&, const string&);		//Main constructor containing input parameters of width, length, and border colour
	virtual ~Circle();									//Destructor
	virtual void draw(){								//inherited draw() from base class shape to indicate circle can be drawn using border colour
		drawOutside();
	}
protected:
	virtual void drawOutside();							//inherited from base class Shape
};

////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////         									  FILLED CIRCLE											   /////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Sub Class FilledCircle inherited from base class Circle, and extended parent class Fillable
class FilledCircle : public Circle, Fillable{
public:
	FilledCircle(const int&, const int&, const string&, const string&);		//Main constructor containing input parameters of width, length, border colour, and filled colour
	virtual ~FilledCircle();												//Destructor
	virtual void draw(){													//inherited draw from base class circle with arguments to draw border and fill shape with colour
		drawOutside();
		fill();
	}
protected:
	virtual void fill();													//inherited from extended parent class fillable
};

////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////         									  		ARC												   /////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Sub Class Arc inherited from base class Shape
class Arc : public Shape{
public:
	Arc(const int&, const int&, const string&);		//Main constructor containing input parameters of width, length, and border colour
	virtual ~Arc();									//Destructor
	virtual void draw(){							//inherited draw from base class shape with arguments to draw border of the shape
		drawOutside();
	}
protected:
	virtual void drawOutside();						//inherited from base class shape
};

#endif /* SHAPESGOOD_H_ */
