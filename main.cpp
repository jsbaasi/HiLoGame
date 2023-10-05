#include <iostream>
#include "Random.h"

void ignoreLine()
{
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int getGuess(int guessPosition)
{
	while(true)
	{
		std::cout << "Guess #" << guessPosition << ": ";
		int guess{};
		std::cin >> guess;

		if (!std::cin)
		{
			if (std::cin.eof())
			{
				exit(0);
			}
			std::cin.clear();
			ignoreLine();
		}
		else if (guess < 1 || guess > 100)
		{
			std::cout << "Guess is out of range.\n";
		}
		else
		{
			ignoreLine();
			return guess;
		}
	}
}

bool playAgain()
{
	while (true)
	{
		std::cout << "Would you like to play again (y/n)? ";
		char inputplay{};
		std::cin >> inputplay;

		if (!std::cin)
		{
			if (std::cin.eof())
			{
				exit(0);
			}
			std::cin.clear();
			ignoreLine();
		}
		else if (inputplay != 'y' && inputplay != 'n')
		{
			std::cout << "Please enter y or n.\n";
		}
		else
		{
			ignoreLine();
			switch (inputplay)
			{
			case 'y': return true;
			case 'n': return false;
			default:
				continue;
			}
		}
	}
}

void HiLo()
{
	constexpr int maxGuesses{ 7 };
	const int	targetNumber{ Random::get(1, 100) };
	int			guessPosition{ 1 };

	std::cout << "Let's play a game. I'm thinking of a number between 1 and 100. You have "
		<< maxGuesses << " tries to guess what it is.\n";

	
	while ((guessPosition <= maxGuesses))
	{
		int guess{ getGuess(guessPosition) };

		if (guess > targetNumber)
			std::cout << "Your guess is too high.\n";
		else if (guess < targetNumber)
			std::cout << "Your guess is too low.\n";
		else
		{
			std::cout << "Correct! You win!\n";
			return;
		}

		++guessPosition;
	}

	std::cout << "Sorry, you lose. The correct number was " << targetNumber << ".\n";
}
int main()
{
	do
	{
		HiLo();
	} while (playAgain());

	std::cout << "Thank you for playing my queen.\n";
	
	return 0;
}