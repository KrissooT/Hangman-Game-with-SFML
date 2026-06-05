#include <set>
#include <unordered_map>
//#include <iostream>

#include "Hangman.h"

bool Hangman::GuessLetter(char letter) {

	if (guessedLetters.count(letter) != 0) {
		return false;
	}

	bool found = false;

	for (int i = 0; i < secretWord.size(); i++) {
		if (secretWord[i] == letter) {
			maskedWord[i] = letter;
			found = true;
		}
	}

	if (!found) {
		lives--;
	}

	guessedLetters.insert(letter);

	return found;
}

int Hangman::RandomLetter(int& secondIndex) {

	std::vector<int> validIndexes;
	std::set<char> invalidLetters;
	char firstLetter, secondLetter;
	int firstIndex = 0;
	bool isSame = false;

	if (secretWord.size() == 3) {
		for (size_t i = 0; i < secretWord.size(); i++) {
			for (size_t k = i + 1; k < secretWord.size(); k++) {
				if (secretWord[i] == secretWord[k]) {
					isSame = true;
					firstIndex = i;
					secondIndex = k;
					firstLetter = secretWord[firstIndex];
					secondLetter = secretWord[secondIndex];
					break;
				}
			}
			if (isSame)break;
		}
	}

	if (!isSame || secretWord.size() > 3) {

		std::unordered_map<char, int> letters;

		for (const char& c : secretWord) {
			letters[c]++;
		}

		for (const std::pair<char, int>& pair : letters) {
			if (pair.second > 1) {
				invalidLetters.insert(pair.first);
			}
		}

		for (size_t i = 0; i < secretWord.size(); i++) {
			if (invalidLetters.find(secretWord[i]) == invalidLetters.end()) {
				validIndexes.push_back(i);
			}
		}

		firstIndex = std::rand() % validIndexes.size();
		secondIndex = std::rand() % validIndexes.size();
		if (firstIndex == secondIndex) {
			while (firstIndex == secondIndex) {
				secondIndex = std::rand() % validIndexes.size();
			}
		}

		firstIndex = validIndexes[firstIndex];
		secondIndex = validIndexes[secondIndex];

		firstLetter = secretWord[firstIndex];
		secondLetter = secretWord[secondIndex];

		guessedLetters.insert(firstLetter);
		guessedLetters.insert(secondLetter);


	}
	return firstIndex;
}

void Hangman::Run(Difficulty difficulty) {

	guessedLetters.clear();
	lives = 6;

	word.RandomWord(difficulty);
	secretWord = word.GetWord();
	maskedWord = secretWord;
	int secondIndex;
	int firstIndex = RandomLetter(secondIndex);

	for (size_t i = 0; i < maskedWord.size(); i++) {
		if (i == firstIndex || i == secondIndex) {
			continue;
		}
		else {
			maskedWord[i] = '_';
		}
	}

	std::string spaced;
	for (char c : maskedWord) {
		spaced += c;
		spaced += ' ';
	}
	maskedWord = spaced;

	//std::cout << secretWord << "\n";  //Just for testing
	//std::cout << maskedWord;
}

int Hangman::GetLives()const {
	return lives;
}

const std::string& Hangman::GetMaskedWord()const {
	return maskedWord;
}