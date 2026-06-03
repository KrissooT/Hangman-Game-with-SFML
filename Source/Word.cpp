#include <random>
#include <fstream>
#include <stdexcept>

#include "Word.h"

Word::Word(){}

void Word::RandomWord(Difficulty difficulty) {

	std::ifstream file;

	switch (difficulty) {
	case Difficulty::Easy: file.open("Content/Words/Easy.txt"); break;
	case Difficulty::Medium: file.open("Content/Words/Medium.txt"); break;
	case Difficulty::Hard: file.open("Content/Words/Hard.txt"); break;
	case Difficulty::Extreme: file.open("Content/Words/Extreme.txt"); break;
	}

	if (!file.is_open()) {
		throw std::runtime_error("Failed to open word file");
	}

	words_.clear();

	std::string w;
	while (file >> w) {
		words_.push_back(w);
	}

	if (words_.empty()) {
		throw std::runtime_error("No words loaded");
	}

	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> dist(0, words_.size() - 1);

	word_ = words_[dist(gen)];

	for (int i = 0; i <= word_.size() - 1; i++) {
		word_[i] = std::toupper(word_[i]);
	}

}

std::string Word::GetWord()const {
	return word_;
}