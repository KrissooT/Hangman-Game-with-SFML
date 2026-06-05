#pragma once

#include<string>
#include<vector>

#include "Difficulty.h"

class Word {
	private:
		std::string word_;
		std::vector<std::string> words_;
	public:

		Word();
		void RandomWord(Difficulty difficulty);
		const std::string& GetWord()const;
};