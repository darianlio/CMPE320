/*
 *  insultgenerator_14dl50.h
 *
 *  Created on: Sep 25, 2017
 *  Author: Darian Lio
 *  Course: CISC/CMPE 320
 *  Title: Assignment 1
 */

#ifndef INSULTGENERATOR_14DL50_H_
#define INSULTGENERATOR_14DL50_H_

#include <string>
#include <vector>

using namespace std;

////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////         								     FILE EXCEPTION   								           /////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////

//Implemented a file exception class to throw an error when the file fails to be read or written.
class FileException{
public:
	FileException(const string&);							//FileException constructor method to display error
	string what() const;									//method to be called when thrown

private:
	string message;											//message to be called and displayed
};

///////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////     								NUMBER OF INSULTS OUT OF BOUNDS								      /////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////

//Implemented a out of bounds except for the number of insults if it is not between the range of 1-10,000.
class NumInsultsOutOfBounds{
public:
	NumInsultsOutOfBounds(const string&);					//NumInsultsOutOfBounds constructor method to display error
	string what() const;									//method to be called when thrown

private:
	string message;											//message to be called and displayed
};

///////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////      								      INSULT GENERATOR								              /////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////

//Implemented the insult generator class
class InsultGenerator{

public:
	InsultGenerator();														//initialize default InsultGenerator constructor method
	void initialize();														//void method to read from insult source file and store each column to vector string
	string talkToMe();														//method generates one random string insult in the form "Thou ___ ___ ___!"
	vector <string> generate(const int insultNum);							//generates 1-10,000 number of random unique insults in a sorted list
	void generateAndSave(const string saveFile, const int insultNum);  		//generates 1-10,000 number of random unique insults in a sorted list and saves it in a file

private:
	vector<string> firstWord;												//insults in first column from the insult source
	vector<string> secondWord;												//insults in second column from the insult source
	vector<string> thirdWord;												//insults in third column from the insult source
	int countFile;															//for declaration of the size of file, used as a counter
};


#endif /* INSULTGENERATOR_14DL50_H_ */
