/*
 * Source File: jumble.cpp
 *
 *  Created on: Nov 11, 2017
 *      Author: Darian Lio
 *      Course: CMPE320
 *      Title: Jumble Puzzle
 */
#include "jumble.h"
#include "time.h"

////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////         								  JUMBLE PUZZLE CLASS        						           /////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////

//Constructor containing hidden word and the difficulty of the puzzle
JumblePuzzle::JumblePuzzle(const string& hiddenWord, const string& difficulty){

	srand(time(NULL));

	//Get the length of the word to determine the size of the matrix
	size = hiddenWord.length();

	//Throw exception if the user does not supply the correct word limit
	if(size < 3 || size > 10){
		throw BadJumbleException("Error: The hidden word must be between 3-10 characters long!");
	}

	//Generate the size of the puzzle based on the level of difficulty entered, throw exception if difficulty entered does not exist
	generateSize(difficulty);

	//Generate matrix according to hiddenWord and set difficulty
	initiateJumblePuzzle(hiddenWord);
}

//Clone Constructor
JumblePuzzle::JumblePuzzle(const JumblePuzzle& original){

	//Get all accessors from original jumble
	size = original.getSize();
	row = original.getRowPos();
	col = original.getColPos();
	dir = original.getDirection();

	//Create new jumble copying the original jumble
	jumble = new char*[size];
	for(int i = 0; i < size; i++) {
		jumble[i] = new char[size];
	}

	charArrayPtr* originalJumble = original.getJumble();

	for (int i = 0; i < size; i++){
		for (int j = 0; j < size; j++){
			jumble[i][j] = originalJumble[i][j];
		}
	}
}

//Overload Operator =
JumblePuzzle& JumblePuzzle::operator=(const JumblePuzzle& rhs){

	//If jumble is not the same, then make it so. Else it is already the same.
	if (this != &rhs){

		//Delete everything in the current jumble to be replaced
		for (int i = 0; i < size; i++){
			delete jumble[i];
		}

		delete jumble;

		//Get accessors from rhs to current jumble
		size = rhs.getSize();
		row = rhs.getRowPos();
		col = rhs.getColPos();
		dir = rhs.getDirection();

		if(rhs.getJumble()){
			//Initialize current jumble and copy everything in rhsJumble to jumble
			jumble = new char*[size];
			for (int i = 0; i < size; i++){
				jumble[i] = new char[size];
			}

			charArrayPtr* rhsJumble = rhs.getJumble();
			for (int i = 0; i < size; i++){
				for (int j = 0; j < size; j++){
					jumble[i][j] = rhsJumble[i][j];
				}
			}
		}
	}

	return *this;
}

//Destructor
JumblePuzzle::~JumblePuzzle(){

	//Delete everything in jumble
	for (int i = 0; i < size; i++){
		delete[] jumble[i];
	}
	delete[] jumble;
}

void JumblePuzzle::initiateJumblePuzzle(const string& hiddenWord){
	//Generate matrix according to the size
	jumble = new char*[size];

	//Produce the matrix in 2D
	for (int i = 0; i < size; i++){
		jumble[i] = new char[size];
	}

	//Add random letters to each row and column
	for (int i = 0; i < size; i++){
		for (int j = 0; j < size; j++){
			jumble[i][j] = rand() % 26 + 'a';
		}
	}

	//Hide the word at the specific coordinates
	row = rand() % size;
	col = rand() % size;

	//Place the first letter in the randomized location
	jumble[row][col] = hiddenWord[0];

	//Initiate flag to determine if word is completely placed into the puzzle
	bool isPlaced = false;

	while (!isPlaced){

		//Get random direction "nesw"
		dir = getRandomDir();

		if (dir == 'n'){	//if dir is north
			for (unsigned int i = 1; i < hiddenWord.length(); i++){
				if ((row-i) >= 0){
					jumble[row-i][col] = hiddenWord[i]; 		//fill in the rest of the letters going north
				} else {
					break;
				}

				if (i + 1 == hiddenWord.length()){
					// if i reached the last letter, call true indicating the word has been successfully placed
					isPlaced = true;
				}
			}
		} else if (dir == 'e'){ //if dir is e
			for (unsigned int i = 1; i < hiddenWord.length(); i++){
				if ((col+i) < hiddenWord.length()){
					jumble[row][col-i] = hiddenWord[i]; 		//fill in the rest of the letters going east
				} else {
					break;
				}

				if (i + 1 == hiddenWord.length()){
					// if i reached the last letter, call true indicating the word has been successfully placed
					isPlaced = true;
				}
			}
		} else if (dir == 's'){ //if dir is s
			for (unsigned int i = 1; i < hiddenWord.length(); i++){
				if ((row+i) < hiddenWord.length()){
					jumble[row+i][col] = hiddenWord[i]; 		//fill in the rest of the letters going south
				} else {
					break;
				}

				if (i + 1 == hiddenWord.length()){
					// if i reached the last letter, call true indicating the word has been successfully placed
					isPlaced = true;
				}
			}
		} else { //if dir is w

			for (unsigned int i = 1; i < hiddenWord.length(); i++){
				if ((col-i) >= 0){
					jumble[row][col-i] = hiddenWord[i]; 		//fill in the rest of the letters going west
				} else {
					break;
				}

				if (i + 1 == hiddenWord.length()){
					// if i reached the last letter, call true indicating the word has been successfully placed
					isPlaced = true;
				}
			}
		}
	}
}

void JumblePuzzle::generateSize(const string& difficulty){
	//Change size according to difficulty, throw if difficulty does not match any option
	if (difficulty == "easy"){
		size *= 2;
	} else if (difficulty == "medium"){
		size *= 3;
	} else if (difficulty == "hard"){
		size *= 4;
	} else {
		throw BadJumbleException("Error: The entered difficulty must be 'easy', 'medium', or 'hard'.");
	}
}

//Accessors
//getRandomDir() to generate random direction according to N E S W
char JumblePuzzle::getRandomDir(){

	//Get direction randomly from N E S W
	switch(rand() % 4){
		case 0:
			return 'n';								//return north direction
			break;
		case 1:
			return 'e';								//return east direction
			break;
		case 2:
			return 's';								//return south direction
			break;
		case 3:
			return 'w';								//return west direction
			break;
	}
	return 0;
}

//getJumble() get jumble of the JumblePuzzle
charArrayPtr* JumblePuzzle::getJumble() const{

	//Create copy of jumble and return it
	charArrayPtr* jumbleCopy = new char*[size];
	for (int i = 0; i < size; i++){
		jumbleCopy[i] = new char[size];
	}

	for (int i = 0; i < size; i++){
		for (int j = 0; j < size; j++){
			jumbleCopy[i][j] = jumble[i][j];
		}
	}

	return jumbleCopy;
}

int JumblePuzzle::getSize() const{ return size; }					//get size of puzzle
int JumblePuzzle::getRowPos() const{ return row; }					//get row of jumble
int JumblePuzzle::getColPos() const{ return col; }					//get col of jumble
char JumblePuzzle::getDirection() const{ return dir; }				//get dir of jumble

////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////         								  BAD JUMBLE EXCEPTION      								   /////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////
//throw error message if jumble is illegal
BadJumbleException::BadJumbleException(const string& message) : message(message){}

string BadJumbleException::what() const{
	return message;
}
