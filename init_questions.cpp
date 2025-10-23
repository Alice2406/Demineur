#include "Demineur.h"

void	choose_level(int* row, int* column)
{
	int level;
	while (1)
	{
		cout << CYAN << "Quelle niveau voulez vous jouer ?" << RESET << endl;
		cout << BLUE << "0. Facile" << RESET << endl;
		cout << GREEN << "1. Normal" << RESET << endl;
		cout << RED << "2. Difficile" << RESET << endl;
		cin >> level;
		if (cin.fail() || level < 0 || level > 2)
		{
			cin.clear();
			cin.ignore(10000, '\n');
		}
		else
			break;
	}
	if (level == 2)
	{
		*row = 16;
		*column = 30;
	}
	else if (level == 1)
	{
		*row = 16;
		*column = 16;
	}
	else
	{
		*row = 9;
		*column = 9;
	}
}

void	questions(int* i, int* j, int* type, grille demineur)
{
	*type = -1;
	while (1)
	{
		cout << CYAN << "0. Reveler une case" << RESET << endl;
		cout << CYAN << "1. Mettre un drapeau" << RESET << endl;
		cout << CYAN << "2. Quitter le jeu" << RESET << endl;
		cin >> *type;
		if (cin.fail() || !(*type == 0 || *type == 1 || *type == 2 || *type == 24))
		{
			cin.clear();
			cin.ignore(10000, '\n');
		}
		else
			break;
	}
	while (1)
	{
		if (*type == 0)
			cout << CYAN << "Quelle case veut tu reveler ?" << RESET;
		else if (*type == 1)
			cout << MAGENTA << "Sur quelle case veux tu mettre un drapeau ?" << RESET;
		else
			return;
		cin >> *i;
		cin >> *j;
		if (cin.fail() || *i < 0 || *j < 0 || *i >= demineur.row || *j >= demineur.column)
		{
			cin.clear();
			cin.ignore(10000, '\n');
		}
		else
			break;
	}
}