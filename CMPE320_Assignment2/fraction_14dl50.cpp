/*
 * fraction_14dl50.cpp
 *
 *  Created on: Oct 16, 2017
 *      Author: Darian Lio
 *      NETID: 14dl50
 *      Course: CISC/CMPE320
 *      Prof: Alan Mcleod
 *      Title: Assignment 2 - The Fraction Class
 */

#include <string>
#include "fraction_14dl50.h"

using namespace std;


////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////         								  FRACTION EXCEPTION      								       /////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////
//throw error message if fraction is illegal
FractionException::FractionException(const string& message) : message(message){}

string FractionException::what() const{
	return message;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////         								  FRACTION CLASS        								       /////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////

//Default Constructor - Zero Fraction
Fraction::Fraction(){
	numVal = 0;
	denVal = 1;
}

//Constructor with Single Integer
Fraction::Fraction(const int& n){
	numVal = n;
	denVal = 1;
}

//Constructor with Numerator and Denominator
Fraction::Fraction(const int& n, const int& d){
	if (d == 0){															//denominator = 0
		throw FractionException("Illegal denominator, cannot be zero.");	//throw exception
	}

	//Normalize the fraction
	normalizeAndReduce(n, d);												//normalize and reduce the fraction
}

//accessor for numerator
int Fraction::numerator() const{
	return numVal;
}

//accessor for denominator
int Fraction::denominator() const{
	return denVal;
}

//GCD using recursive algorithm example
int Fraction::GCD(const int& n, const int &m){

	//make integers absolute to prevent negative GCD
	int x = abs(n);
	int y = abs(m);

	if ((y <= x) && (x % y == 0)){
		return y;
	} else if (x < y){
		return GCD(y, x);
	} else {
		return GCD(y, x % y);
	}

}

void Fraction::normalizeAndReduce(const int &n, const int &d){
	//Normalize the fraction
	int normN, normD;

	normN = n;
	normD = d;

	if (normD < 0){ //if both negative, it will flipped to positive / if denominator negative, it will be flipped to numerator
		normN = normN * -1;
		normD = normD * -1;
	}

	//Reduce value using GCD
	if (normN != 0){
		int gcd = GCD(normN, normD);
		numVal = normN/gcd;
		denVal = normD/gcd;
	} else {
		numVal = normN;
		numVal = normD;
	}
}

//Overload Unary Operators
//Negation (-t)
Fraction Fraction::operator-() const{
	return Fraction(-numVal, denVal);
}

//Post-Increment (t++)
Fraction Fraction::operator++(int unused){
	Fraction f = *this;
	numVal += denVal;
	return f;
}

//Pre-Increment (++t)
Fraction& Fraction::operator++(){
	numVal += denVal;
	return *this;
}

//Addition and Assignment (+=)
Fraction& Fraction::operator+=(const Fraction &rhs){
	numVal = numVal*rhs.denominator() + denVal*rhs.numerator();
	denVal = denVal*rhs.denominator();
	normalizeAndReduce(numVal, denVal);
	return *this;
}

Fraction& Fraction::operator+=(const int& rhs){
	numVal = numVal + denVal*rhs;
	normalizeAndReduce(numVal, denVal);
	return *this;
}

//cin >>
istream& operator>>(istream& in, Fraction& f){
	string number;
	in >> number;							//read the number

	size_t delimiter = number.find("/");	//find the delimiter in the string "/"

	if (delimiter != string::npos){			//if delimiter is not empty

		int n = stoi(number.substr(0, delimiter));		//set numerator from string to integer before the "/"
		int d = stoi(number.substr(delimiter + 1));		//set denominator from string to integer after the "/"

		if (d == 0){ //if denominator is 0
			throw FractionException("Illegal denominator, cannot divide by zero.");  //illegal argument throw
		} else if (n == 0 && d != 0){	//numerator is 0, then set values as zero fraction
			f.numVal = 0;
			f.denVal = 1;
		} else {						//set the values into the fraction and normalize and reduce fraction to minimum
			f.numVal = n;
			f.denVal = d;

			f.normalizeAndReduce(f.numVal, f.denVal);
		}
	} else {	//else if there is no delimiter it would be a single integer
		f.numVal = stoi(number);
		f.denVal = 1;
	}

	return in;
}

//cout <<
ostream& operator<<(ostream& out, const Fraction& f){
	out << f.numerator() << "/" << f.denominator();			//display the fraction in fraction form
	return out;
}

//Overload Math Operators For All Three Conditions
//Addition (+)
Fraction operator+(const int& lhs, const Fraction& rhs ) {
	int n = (lhs * rhs.denominator()) + rhs.numerator();
	int d = rhs.denominator();
	return Fraction(n, d);
}

Fraction operator+(const Fraction& lhs, const int& rhs ){
	int n = lhs.numerator() + (lhs.denominator()*rhs);
	int d = lhs.denominator();
	return Fraction(n, d);
}

Fraction operator+(const Fraction& lhs, const Fraction& rhs){
	int n = (lhs.numerator()*rhs.denominator()) + (lhs.denominator()*rhs.numerator());
	int d = lhs.denominator() * rhs.denominator();
	return Fraction(n, d);
}

//Subtraction (-)
Fraction operator-(const int& lhs, const Fraction& rhs ){
	int n = (lhs*rhs.denominator()) - rhs.numerator();
	int d = rhs.denominator();
	return Fraction(n, d);
}

Fraction operator-(const Fraction& lhs, const int& rhs ){
	int n = lhs.numerator() - (lhs.denominator()*rhs);
	int d = lhs.denominator();
	return Fraction(n, d);
}

Fraction operator-(const Fraction& lhs, const Fraction& rhs){
	int n = (lhs.numerator()*rhs.denominator()) - (lhs.denominator()*rhs.numerator());
	int d = lhs.denominator() * rhs.denominator();
	return Fraction(n, d);
}

//Multiplication (*)
Fraction operator*(const int& lhs, const Fraction& rhs ){
	int n = (lhs*rhs.denominator()) * rhs.numerator();
	int d = rhs.denominator();
	return Fraction(n, d);
}

Fraction operator*(const Fraction& lhs, const int& rhs ){
	int n = lhs.numerator() * (lhs.denominator()*rhs);
	int d = lhs.denominator();
	return Fraction(n, d);
}

Fraction operator*(const Fraction& lhs, const Fraction& rhs){
	int n = lhs.numerator() * rhs.numerator();
	int d = lhs.denominator() * rhs.denominator();
	return Fraction(n, d);
}

//Division (/)
Fraction operator/(const int& lhs, const Fraction& rhs ){
	int n = lhs * rhs.denominator();
	int d = rhs.numerator();
	return Fraction(n, d);
}

Fraction operator/(const Fraction& lhs, const int& rhs ){
	int n = lhs.numerator();
	int d = lhs.denominator() * rhs;
	return Fraction(n, d);
}

Fraction operator/(const Fraction& lhs, const Fraction& rhs){
	int n = lhs.numerator() * rhs.denominator();
	int d = lhs.denominator() * rhs.numerator();
	return Fraction(n, d);;
}

//Overload Comparison Operators
//Less Than (<)
bool operator<(const int& lhs, const Fraction& rhs){
	return lhs * rhs.denominator() < rhs.numerator();
}

bool operator<(const Fraction& lhs, const int& rhs){
	return lhs.numerator() < rhs * lhs.denominator();
}

bool operator<(const Fraction& lhs, const Fraction& rhs){
	return lhs.numerator()*rhs.denominator() < lhs.denominator() * rhs.numerator();
}

//Less Than Or Equal (<=)
bool operator<=(const int& lhs, const Fraction& rhs){
	return lhs * rhs.denominator() <= rhs.numerator();
}

bool operator<=(const Fraction& lhs, const int& rhs){
	return lhs.numerator() <= rhs * lhs.denominator();
}

bool operator<=(const Fraction& lhs, const Fraction& rhs){
	return lhs.numerator()*rhs.denominator() <= lhs.denominator() * rhs.numerator();
}

//Equal (==)
bool operator==(const int& lhs, const Fraction& rhs){
	return (lhs == rhs.numerator() && rhs.denominator() == 1);
}

bool operator==(const Fraction& lhs, const int& rhs){
	return (lhs.numerator() == rhs && lhs.denominator() == 1);
}

bool operator==(const Fraction& lhs, const Fraction& rhs){
	return (lhs.numerator() == rhs.numerator() && lhs.denominator() == rhs.denominator());
}

//Not Equal (!=)
bool operator!=(const int& lhs, const Fraction& rhs){
	return (lhs != rhs.numerator() || rhs.denominator() != 1);
}

bool operator!=(const Fraction& lhs, const int& rhs){
	return (lhs.numerator() != rhs || lhs.denominator() != 1);
}

bool operator!=(const Fraction& lhs, const Fraction& rhs){
	return (lhs.numerator() != rhs.numerator() || lhs.denominator() != rhs.denominator());
}

//Greater Than or Equal (>=)
bool operator>=(const int& lhs, const Fraction& rhs){
	return lhs*rhs.denominator() >= rhs.numerator();
}

bool operator>=(const Fraction& lhs, const int& rhs){
	return lhs.numerator() >= lhs.denominator() * rhs;
}

bool operator>=(const Fraction& lhs, const Fraction& rhs){
	return lhs.numerator()*rhs.denominator() >= lhs.denominator() * rhs.numerator();
}

//Greater Than (>)
bool operator>(const int& lhs, const Fraction& rhs){
	return lhs*rhs.denominator() > rhs.numerator();
}

bool operator>(const Fraction& lhs, const int& rhs){
	return lhs.numerator() > lhs.denominator() * rhs;
}

bool operator>(const Fraction& lhs, const Fraction& rhs){
	return lhs.numerator()*rhs.denominator() >= lhs.denominator() * rhs.numerator();
}




