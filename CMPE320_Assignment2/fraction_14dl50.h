/*
 * fraction_14dl50.h
 *
 *  Created on: Oct 16, 2017
 *      Author: Darian Lio
 *      NETID: 14dl50
 *      Course: CISC/CMPE320
 *      Prof: Alan Mcleod
 *      Title: Assignment 2 - The Fraction Class
 */

#ifndef FRACTION_14DL50_H_
#define FRACTION_14DL50_H_

#include <iostream>
using namespace std;

////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////         							     FRACTION EXCEPTION   								          /////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////

//Implemented a fraction exception class in order to throw an exception on illegal arguments such as dividing by zero
class FractionException {

public:
	FractionException(const string&);		//Fraction Exception constructor method to display error
	string what() const;					//method to be called when thrown

private:
	string message;							//message to be displayed
};

////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////         								     FRACTION CLASS  								           /////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////

//Implementation of the Fraction Class to create fractions and overload unary and binary operators
class Fraction {

public:
	Fraction();													//default constructor - zero fraction
	Fraction(const int& n);										//constructor taking single integer
	Fraction(const int& n, const int& d);						//constructor taking two integers (numerator and denominator)

	int numerator() const;										//access for numerator
	int denominator() const;									//access for denominator

	int GCD(const int& n, const int& m);						//greatest common divisor for a fraction

	void normalizeAndReduce(const int& n, const int& d);		//void method to take in numerator and denominator
																//to normalize and reduce fraction
	//Overload Unary Operators
	Fraction operator-() const;									//negation
	Fraction operator++(int unused);							//post-increment
	Fraction& operator++();										//pre-increment
	Fraction& operator+=(const Fraction& rhs);					//addition and assignment with Fraction object
	Fraction& operator+=(const int& rhs);						//addition and assignment with int

	//Overload I/O Operators as friend functions
	friend ostream& operator<<(ostream& out, const Fraction& value); //cout
	friend istream& operator>>(istream& in, Fraction& value);		 //cin

private:
	int numVal;												 	 //value of numerator
	int denVal;													 //value of denominator
};

/* Each binary operator +,-,*,/ and the comparison operators must meet the following cases:
 * 1) int on LHS of operator
 * 2) int on RHS of operator
 * 3) Fraction objects on both sides
 */
//Overload Math Operators
Fraction operator+(const int& lhs, const Fraction& rhs );			//addition int + obj
Fraction operator+(const Fraction& lhs, const int& rhs );			//addition obj + int
Fraction operator+(const Fraction& lhs, const Fraction& rhs); 		//addition obj + obj

Fraction operator-(const int& lhs, const Fraction& rhs );			//subtraction int + obj
Fraction operator-(const Fraction& lhs, const int& rhs );			//subtraction obj + int
Fraction operator-(const Fraction& lhs, const Fraction& rhs); 		//subtraction obj + obj

Fraction operator*(const int& lhs, const Fraction& rhs );			//multiplication int + obj
Fraction operator*(const Fraction& lhs, const int& rhs );			//multiplication obj + int
Fraction operator*(const Fraction& lhs, const Fraction& rhs); 		//multiplication obj + obj

Fraction operator/(const int& lhs, const Fraction& rhs );			//division int + obj
Fraction operator/(const Fraction& lhs, const int& rhs );			//division obj + int
Fraction operator/(const Fraction& lhs, const Fraction& rhs); 		//division obj + obj

//Overload Comparison Operators
bool operator<(const int& lhs, const Fraction& rhs);			//less than int + obj
bool operator<(const Fraction& lhs, const int& rhs);			//less than obj + int
bool operator<(const Fraction& lhs, const Fraction& rhs);		//less than obj + obj

bool operator<=(const int& lhs, const Fraction& rhs);			//less than or equal int + obj
bool operator<=(const Fraction& lhs, const int& rhs);			//less than or equal obj + int
bool operator<=(const Fraction& lhs, const Fraction& rhs);		//less than obj + obj

bool operator==(const int& lhs, const Fraction& rhs);			//equal int + obj
bool operator==(const Fraction& lhs, const int& rhs);			//equal obj + int
bool operator==(const Fraction& lhs, const Fraction& rhs);		//equal obj + obj

bool operator!=(const int& lhs, const Fraction& rhs);			//not equal int + obj
bool operator!=(const Fraction& lhs, const int& rhs);			//not equal obj + int
bool operator!=(const Fraction& lhs, const Fraction& rhs);		//not equal obj + obj

bool operator>=(const int& lhs, const Fraction& rhs);			//greater or equal int + obj
bool operator>=(const Fraction& lhs, const int& rhs);			//greater or equal obj + int
bool operator>=(const Fraction& lhs, const Fraction& rhs);		//greater or equal obj + obj

bool operator>(const int& lhs, const Fraction& rhs);			//greater than int + obj
bool operator>(const Fraction& lhs, const int& rhs);			//greater than obj + int
bool operator>(const Fraction& lhs, const Fraction& rhs);		//greater than obj + obj


#endif /* FRACTION_14DL50_H_ */
