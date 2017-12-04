/*
 *  Source File: ShapesGood.cpp
 *
 *  Created on: Nov 27, 2017
 *      Author: Darian Lio
 *      Course: CMPE320
 *      Title: ShapesGood
 */
#include "ShapesGood.h"
#include <iostream>

using namespace std;

////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////         									  FILLABLE										    	   /////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////
Fillable::Fillable() : fillColour("N/A"){}

Fillable::Fillable(const string& colour) : fillColour(colour){}

Fillable::~Fillable(){}

string Fillable::getFillColour() const{
	return fillColour;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////         									  LABELED													/////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////
Labeled::Labeled() : text("N/A"){}

Labeled::Labeled(const string& textLabel) : text(textLabel){}

Labeled::~Labeled(){}

string Labeled::getText() const {
	return text;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////         									  SHAPE													   /////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////
Shape::Shape() : width(0), length(0), borderColour("N/A"){}

Shape::Shape(const int& width, const int& length, const string& borderColour) : width(width), length(length), borderColour(borderColour){}

Shape::~Shape(){}

int Shape::getLength() const{
	return length;
}

int Shape::getWidth() const{
	return width;
}

string Shape::getBorderColour() const{
	return borderColour;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////         									  SQUARE										    	   /////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////
Square::Square(const int& width, const int& length, const string& borderColour) : Shape(width, length, borderColour){}

Square::~Square(){}

void Square::drawOutside(){
	cout << "\nDrawing a " + borderColour + " square.";
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////         									  FILLED SQUARE											   /////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////
FilledSquare::FilledSquare(const int& width, const int& length, const string& borderColour, const string& fillColour) : Square(width, length, borderColour), Fillable(fillColour){}

FilledSquare::~FilledSquare(){}

void FilledSquare::fill(){
	cout << " With " + getFillColour() + " fill.";
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////         									  FILLED TEXT SQUARE									   /////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////
FilledTextSquare::FilledTextSquare(const int& width, const int& length, const string& borderColour, const string& fillColour, const string& textLabel) : FilledSquare(width, length, borderColour, fillColour), Labeled(textLabel){}

FilledTextSquare::~FilledTextSquare(){}

void FilledTextSquare::fillText(){
	cout << " Containing the text: \"" << getText() << "\".";
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////         									  CIRCLE												   /////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////
Circle::Circle(const int& width, const int& length, const string& borderColour) : Shape(width, length, borderColour){}

Circle::~Circle(){}

void Circle::drawOutside(){
	cout << "\nDrawing a " + borderColour + " circle.";
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////         									  FILLED CIRCLE											   /////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////
FilledCircle::FilledCircle(const int& width, const int& length, const string& borderColour, const string& fillColour) : Circle(width, length, borderColour), Fillable(fillColour){}

FilledCircle::~FilledCircle(){}

void FilledCircle::fill(){
	cout << " With " + getFillColour() + " fill.";
}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////         									  		ARC													/////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////
Arc::Arc(const int& width, const int& length, const string& borderColour) : Shape(width, length, borderColour){}

Arc::~Arc(){}

void Arc::drawOutside(){
	cout << "\nDrawing a " + borderColour + " arc.";
}


