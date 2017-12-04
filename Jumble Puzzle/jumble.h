/*
 * Header File: jumble.h
 *
 *  Created on: Nov 11, 2017
 *      Author: Darian Lio
 *      Course: CMPE320
 *      Title: Jumble Puzzle
 */

#ifndef JUMBLE_H_
#define JUMBLE_H_

#include <string>

using namespace std;

typedef char* charArrayPtr;												//type of 2D array of char


////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////         									  JUMBLE PUZZLE									    	   /////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Implementation of the Jumble Puzzle Class to generate a puzzle depending on the hidden word and difficulty level
class JumblePuzzle{

public:
	//Main Constructor
	JumblePuzzle(const string& hiddenWord, const string& difficulty);

	//BIG THREE
	JumblePuzzle(const JumblePuzzle&);									//Copy Constructor
	~JumblePuzzle();													//Destructor
	JumblePuzzle& operator=(const JumblePuzzle&);						//Overload Operator

	void generateSize(const string&);									//set size of puzzle according to difficulty
	void initiateJumblePuzzle(const string&);							//create jumble puzzle after getting hidden word and size of difficulty

	//Accessors
	charArrayPtr* getJumble() const;									//getter to get jumble
	int getSize() const;												//getter to get size of jumble
	int getRowPos() const;												//getter to acquire row position of jumble
	int getColPos() const;												//getter to acquire column position of jumble
	char getRandomDir();												//getter to get random direction 'nesw' of jumble
	char getDirection() const;											//getter to get current direction of jumble

private:
	//Initialize variables
	charArrayPtr* jumble;
	int size;
	int row;
	int col;
	char dir;

};

////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////         								  BAD JUMBLE EXCEPTION      								   /////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Implemented a bad jumble exception class in order to throw an exception on illegal arguments such as invalid word length or invalid difficulty
class BadJumbleException{

public:
	BadJumbleException(const string&);				//Bad Jumble Exception constructor method to display error
	string what() const;							//method to be called when thrown

private:
	string message;									//message to be displayed

};


#endif /* JUMBLE_H_ */
