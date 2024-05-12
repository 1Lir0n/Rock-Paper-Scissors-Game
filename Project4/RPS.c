#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main() {

	// 1 = single player(vs cpu) default ; 2 = multiplayer(vs local players)
	int playerAmount = 1;

	srand(time(0));

	int diff = 1;//normal = 1 default ; impossible = 2

	int playerChoice = 0;
	int playerBChoice = 0;
	int _AI_Choice;
	int contin = 1;
	while (contin) {
		printf("Select Player Amount: (1-2)\n");
		scanf("%d", &playerAmount);

		switch (playerAmount) {

		//Singleplayer
		case 1:

			printf("Select Difficulty: (Normal->1, Impossible->2)\n");
			scanf("%d", &diff);

			switch (diff)
			{

			case 1:

				printf("Enter your choice: (Rock->1,Paper->2,Scissors->3)\n");
				scanf("%d", &playerChoice);

				_AI_Choice = rand() % 3 + 1;

				switch (playerChoice)
				{

				case 1:
					if (_AI_Choice == 1) {
						printf("You Chose: Rock, AI Chose: Rock\n");
						printf("It's a Draw!");
					}
					else if (_AI_Choice == 2) {
						printf("You Chose: Rock, AI Chose: Paper\n");
						printf("You Lost!");
					}
					else if (_AI_Choice == 3) {
						printf("You Chose: Rock, AI Chose: Scissors\n");
						printf("You Won!");
					}
					break;

				case 2:
					if (_AI_Choice == 2) {
						printf("You Chose: Paper, AI Chose: Paper\n");
						printf("It's a Draw!");
					}
					else if (_AI_Choice == 3) {
						printf("You Chose: Paper, AI Chose: Scissors\n");
						printf("You Lost!");
					}
					else if (_AI_Choice == 1) {
						printf("You Chose: Paper, AI Chose: Rock\n");
						printf("You Won!");
					}
					break;

				case 3:
					if (_AI_Choice == 3) {
						printf("You Chose: Scissors, AI Chose: Scissors\n");
						printf("It's a Draw!");
					}
					else if (_AI_Choice == 1) {
						printf("You Chose: Scissors, AI Chose: Rock\n");
						printf("You Lost!");
					}
					else if (_AI_Choice == 2) {
						printf("You Chose: Scissors, AI Chose: Paper\n");
						printf("You Won!");
					}
					break;

				default:
					printf("Wrong Data Please Debug.@playerChoiceNorm");
					break;
				}
				break;

			case 2:

				printf("Enter your choice: (Rock->1,Paper->2,Scissors->3)\n");
				scanf("%d", &playerChoice);

				switch (playerChoice)
				{
				case 1:
					_AI_Choice = 2;
					printf("You Chose: Rock, AI Chose: Paper");
					printf("You Lost!");
					break;
				case 2:
					_AI_Choice = 3;
					printf("You Chose: Paper, AI Chose: Scissors");
					printf("You Lost!");
					break;
				case 3:
					_AI_Choice = 1;
					printf("You Chose: Scissors, AI Chose: Rock");
					printf("You Lost!");
					break;
				}

			default:
				printf("\nWrong Input Please Debug. @PlyaerChoiceImpp\n");
				break;
			}

			break;


		//multiplayer
		case 2:
			//get player a choice
			while (!(playerChoice <= 3 && playerChoice >= 1)) {
				printf("Player A Chose: (Rock->1,Paper->2,Scissors->3)\n");
				scanf("%d", &playerChoice);
				printf("\x1b[1F"); // Move to beginning of previous line
				printf("\x1b[2K*****\n"); // Clear entire line

				if (!(playerChoice <= 3 && playerChoice >= 1)) {
					printf("\x1b[1F"); // Move to beginning of previous line
					printf("\x1b[2K");
					printf("Please Choose Between 1-3.\n");

				}
			}
			//get player b choice
			while (!(playerBChoice <= 3 && playerBChoice >= 1)) {
				printf("Player B Chose: (Rock->1,Paper->2,Scissors->3)\n");
				scanf("%d", &playerBChoice);
				printf("\x1b[1F"); // Move to beginning of previous line
				printf("\x1b[2K*****\n"); // Clear entire line

				if (!(playerBChoice <= 3 && playerBChoice >= 1)) {
					printf("\x1b[1F"); // Move to beginning of previous line
					printf("\x1b[2K");
					printf("Please Choose Between 1-3.\n");

				}
			}

			switch (playerChoice)
			{

			case 1:
				if (playerBChoice == 1) {
					printf("A Chose: Rock, B Chose: Rock\n");
					printf("It's a Draw!");
				}
				else if (playerBChoice == 2) {
					printf("A Chose: Rock, B Chose: Paper\n");
					printf("B Won!");
				}
				else if (playerBChoice == 3) {
					printf("A Chose: Rock, B Chose: Scissors\n");
					printf("A Won!");
				}
				break;

			case 2:
				if (playerBChoice == 2) {
					printf("A Chose: Paper, B Chose: Paper\n");
					printf("It's a Draw!");
				}
				else if (playerBChoice == 3) {
					printf("A Chose: Paper, B Chose: Scissors\n");
					printf("B Won!");
				}
				else if (playerBChoice == 1) {
					printf("A Chose: Paper, B Chose: Rock\n");
					printf("A Won!");
				}
				break;

			case 3:
				if (playerBChoice == 3) {
					printf("A Chose: Scissors, B Chose: Scissors\n");
					printf("It's a Draw!");
				}
				else if (playerBChoice == 1) {
					printf("A Chose: Scissors, B Chose: Rock\n");
					printf("B Won!");
				}
				else if (playerBChoice == 2) {
					printf("A Chose: Scissors, B Chose: Paper\n");
					printf("A Won!");
				}
				break;

			default:
				printf("Wrong Data Please Debug.@PlayerChoiceMulti");
				break;
			}
			break;

		default:
			printf("\nWrong Data Please Debug. @PlayerAmount\n");
			break;
		}

		//reset game or stop game
		contin = 3;
		while (contin == 3) {
			printf("\nDo You Wish To Continue Playing? (y/n)\n");
			char choice;
			scanf(" %c", &choice);
			switch (choice)
			{
			case 'y':
				contin = 1;
				playerAmount = 0;
				playerBChoice = 0;
				playerChoice = 0;
				break;
			case 'n':
				contin = 0;
				break;
			default:
				printf("Please Use Only y OR n .\n");
				break;
			}
		}
	}

	printf("\nThank You For Playing!\n");
	return 0;
}