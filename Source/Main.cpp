#include "Game.h"

int main() {

	Game Hangman;

	while (Hangman.IsRunning()) {
		Hangman.ProcessEvents();
		Hangman.Update();
		Hangman.Render();
	}
}