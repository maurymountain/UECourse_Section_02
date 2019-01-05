/* The game logic (no view code or direct user interaction)
the game is a simple guess the word game based on Mastermind
*/

#pragma once
#include <string>

// make syntax unreal friendly
using FString = std::string;
using int32 = int;

struct FBullCowCount
{
	int32 Bulls = 0;
	int32 Cows = 0;
};

enum class EGuessStatus
{
	Invalid_Status,
	OK,
	Not_Isogram,
	Number_Entry,
	No_Entry,
	Duplicate_Entry,
	Wrong_Length,
	Not_Lowercase
};


class FBullCowGame {
public: 
	FBullCowGame(); // constructor

	int32 GetMaxTries() const;
	int32 GetCurrentTry() const;
	int32 GetHiddenWordLength() const;
	bool IsGameWon() const;
	EGuessStatus CheckGuessValidity(FString) const;
	
	void Reset();
	
	FBullCowCount SubmitValidGuess(FString);

private: 
	//see constructor for initilization
	int32 MyCurrentTries;
	int32 MyMaxTries;
	FString MyHiddenWord;
	bool bGameWon;

	bool IsIsogram(FString) const;
	bool IsLowercase(FString) const;
};