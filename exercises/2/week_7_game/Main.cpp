#include <iostream>
#include <time.h>

using namespace std;

int random(int min, int max)
{
	static bool first = true;
	if (first)
	{
		srand(time(NULL));
		first = false;
	}
	return min + rand() % (max + 1 - min);
}

int main() {

	int tunnel[500];
	int size;

	do {
		cout << "Enter the lenght of the tunnel" << endl;
		cin >> size;
	} while (size > 500 || size < 0);

	tunnel[0] = 0;
	tunnel[size - 1] = 0;

	for (int i = 1; i < size - 1; i++)
	{
		tunnel[i] = random(-3, 3);
	}

	for (int i = 0; i < size; i++)
	{
		cout << tunnel[i] << " ";
	}

	bool turn;

	if (random(0, 1) == 0)
	{
		turn = false;
	}
	else
	{
		turn = true;
	}

	bool end = false;
	int player1LastMove = 0, player2LastMove = 0;
	while (end == false)
	{
		if (turn)
		{
			int number;
			do {
				cout << "Player 1, enter a number between 1 and 6: ";
				cin >> number;
			} while (number < 1 || number > 6);

			if (player1LastMove + number < 0)
			{
				player1LastMove = 0;
			}
			else
			{
				if (player1LastMove + number > size)
				{
					cout << "Player 1 won! :)" << endl;
					//end = true; // moje i taka no trqbva da se dobavi i drug kod, za da ne se izpulni i drugiq kod nadolu
					break;
				}

				int tile = tunnel[player1LastMove + number];
				if (tile == 4)
				{
					player1LastMove = player1LastMove;
				}
				else
				{
					tunnel[player1LastMove + number] = 4;
					if (player1LastMove + tile + number > size)
					{
						cout << "Player 1 won! :)" << endl;
						break;
					}
					player1LastMove = player1LastMove + tile + number;
				}
			}

			
			turn = false;
		}
		for (int i = 0; i < size; i++)
		{
			cout << tunnel[i] << " ";
		}
		cout << endl;
		cout << "Player1 Possition: " << player1LastMove;
		cout << endl;

		if (turn == false)
		{
			int number;
			do {
				cout << "Player 2, enter a number between 1 and 6: ";
				cin >> number;
			} while (number < 1 || number > 6);

			if (player2LastMove + number < 0)
			{
				player2LastMove = 0;
			}
			else
			{
				if (player2LastMove + number > size)
				{
					cout << "Player 2 won! :)" << endl;
					//end = true; // moje i taka
					break;
				}

				int tile = tunnel[player2LastMove + number];
				if (tile == 4)
				{
					player2LastMove = player2LastMove;
				}
				else
				{
					tunnel[player2LastMove + number] = 4;
					if (player2LastMove + tile + number > size)
					{
						cout << "Player 2 won! :)" << endl;
						break;
					}
					player2LastMove = player2LastMove + tile + number;
				}
			}
			turn = true;
		}
		for (int i = 0; i < size; i++)
		{
			cout << tunnel[i] << " ";
		}
		cout << endl;
		cout << "Player 2 Possition: " << player2LastMove;
		cout << endl;
	}

	cout << "Thanks for playing! :)";

	return 0;
}

//Когато в началото попаднем на отрицателно число - се връщаме на позиция 0. Обаче не бях сложил else и така изпълни и кода надолу и правеше проблеми. 
//А големият проблем с това, че имах грешни позиции беше, че като променях новата позиция - не добавях number, а само tile. Така реално все едно се движих от старата позиция - към новата само от плочката, на която съм стъпил
//А на мен ми трябва и с колко плочки напред съм отишъл от избора ми.
//Помислете как ще разделите задачата на функции
