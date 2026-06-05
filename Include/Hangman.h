#pragma once

#include <string>
#include <unordered_set>

#include "GameState.h"
#include "Word.h"
#include "Difficulty.h"

class Hangman {
	private:
		Word word;
		Difficulty difficulty;
		std::string secretWord;
		std::string maskedWord;
		std::unordered_set<char> guessedLetters;
		int lives = 6;

	public:

		Hangman(){}

		int RandomLetter(int& secondIndex);
		void Run(Difficulty difficulty);
		bool GuessLetter(char letter);

		int GetLives()const;
		const std::string& GetMaskedWord()const;
		const std::string& GetSecretWord()const;

		GameState CheckLives();
};