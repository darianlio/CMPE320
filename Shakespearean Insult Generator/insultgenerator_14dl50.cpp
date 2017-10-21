/*
 * insultgenerator_14dl50.cpp
 *  Created on: Sep 25, 2017
 *  Author: Darian Lio
 *  Course: CISC/CMPE 320
 *  Title: Assignment 1
 */

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <set>
#include <ctime>

#include "insultgenerator_14dl50.h"

using namespace std;

////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////         								     FILE EXCEPTION   								           /////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////

//throws error if file is not read
FileException::FileException(const string& message) : message(message) {}

string FileException::what() const{
	return message;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////     								NUMBER OF INSULTS OUT OF BOUNDS								      /////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////

//throws error if the insults are out of bounds
NumInsultsOutOfBounds::NumInsultsOutOfBounds(const string& message) : message(message){}

string NumInsultsOutOfBounds::what() const{
	return message;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////      								      INSULT GENERATOR								              /////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////

//empty default constructor
InsultGenerator::InsultGenerator() {
	countFile = 0;
}

//initialize method to read the file and store it in a vector<string>
void InsultGenerator::initialize(){

	//variable declarations
	srand(time(0));												//initialize random seed
	string getLine;												//string to get the line of each insult
	countFile = 0;												//initialize size of file to be empty

	//read file and open it
	ifstream readFile;
	readFile.open("InsultsSource.txt");

	//if the file cannot be read, throw exception
	if(readFile.fail()){
		throw FileException("Error! Cannot open the file.");
	}

	//read the file
	while(!readFile.eof()){  									//while the file has not reached the end

		readFile >> getLine;									//get first line
		firstWord.push_back(getLine);							//store word in first column
		readFile >> getLine;									//get second line
		secondWord.push_back(getLine);							//store word in second column
		readFile >> getLine;									//get third line
		thirdWord.push_back(getLine);							//store word in last column

		countFile++;											//count the size of the file
	}

	//close the file being read
	readFile.close();
}

//method to return a random unique insult
string InsultGenerator::talkToMe(){

	//store randomized values into the string
	string insult = ("Thou " + firstWord.at(rand() % countFile) + " " + secondWord.at(rand() % countFile) + " " + thirdWord.at(rand() % countFile) + "!");

	//return the string
	return insult;
}

//method to generate a number of unique random insults depending on size entered
vector <string> InsultGenerator::generate(const int insultNum){

	//declare constant min and max bounds
	const int insultMin = 1;
	const int insultMax = 10000;

	//if the size entered does not meet the bounds, throw exception
	if (insultNum < insultMin || insultNum > insultMax){
		throw NumInsultsOutOfBounds("Error! The number you entered is not in the range of 1-10,000.");
	}

	set<string> insultSet;												//use set to avoid redundancy as well as sort alphabetically!

	//while the set is less than the size entered, keep adding insult values
	while(insultSet.size() < (unsigned int)insultNum){					//parse to unsigned to prevent mismatch
		insultSet.insert(talkToMe());									//insert a random generated unique insult into the set
	}

	//move the insults in the set back to vector
	vector<string> insultVector(insultSet.begin(), insultSet.end());

	//return vector string
	return insultVector;
}

//generate and save file in alphabetical order
void InsultGenerator::generateAndSave(const string saveFile, const int insultNum){

	//Save to the file
	ofstream fileName;
	fileName.open(saveFile);

	//If file cannot read, throw exception
	if (fileName.fail()){
			throw FileException("Error! Cannot open the file.");
	}

	vector<string> saveInsult = generate(insultNum);			// call generate function to create strings of insults
	int count(0);												// initialize integer to count each line

	//while the number of lines is less than the size entered
	while (count < insultNum){
		fileName << saveInsult.at(count) << endl;				//store each insult into the file until loop breaks
		count++;												//continue to next index
	}

	//close the file being read
	fileName.close();
}


