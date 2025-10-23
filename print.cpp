#include "Demineur.h"

void	print_numbers(int nb)
{
	switch (nb)
	{
	case 0:
		cout << "[" << WHITE << nb << RESET << "]";
		break;
	case 1:
		cout << "[" << CYAN << nb << RESET << "]";
		break;
	case 2:
		cout << "[" << GREEN << nb << RESET << "]";
		break;
	case 3:
		cout << "[" << RED << nb << RESET << "]";
		break;
	case 4:
		cout << "[" << BLUE << nb << RESET << "]";
		break;
	case 5:
		cout << "[" << YELLOW << nb << RESET << "]";
		break;
	case 6:
		cout << "[" << MAGENTA << nb << RESET << "]";
		break;
	case 7:
		cout << "[" << CYAN << nb << RESET << "]";
		break;
	case 8:
		cout << "[" << GRAY << nb << RESET << "]";
		break;
	}
}

void	print_tab(grille demineur)
{
	if (demineur.cat == 1)
		easterEggCat();
	cout << "  ";
	for (int k = 0; k < demineur.column; k++)
	{
		cout << " " << k;
		if (k < 10)
			cout << " ";
	}
	cout << endl;
	for (int i = 0; i < demineur.row; i++)
	{
		cout << i;
		if (i < 10)
			cout << " ";
		for (int j = 0; j < demineur.column; j++)
		{
			if (demineur.reveal[i][j] == 1)
				print_numbers(demineur.tab[i][j]);
			else if (demineur.reveal[i][j] == -1)
				cout << "[" << YELLOW << "F" << RESET << "]";
			else
				cout << "[ ]";
		}
		cout << endl;
	}
}

void	print_finish_tab(grille demineur)
{
	system("cls");
	cout << "  ";
	for (int k = 0; k < demineur.column; k++)
	{
		cout << " " << k;
		if (k < 10)
			cout << " ";
	}
	cout << endl;
	for (int i = 0; i < demineur.row; i++)
	{
		cout << i;
		if (i < 10)
			cout << " ";
		for (int j = 0; j < demineur.column; j++)
		{
			if (demineur.tab[i][j] == -1)
				cout << "[" << RED << "*" << RESET << "]";
			else if (demineur.reveal[i][j] == 1)
				print_numbers(demineur.tab[i][j]);
			else
				cout << "[ ]";
		}
		cout << endl;
	}
	cout << RED << "LOOOOOOOOSER" << RESET << endl;
}

void	flood_fill(int i, int j, grille* demineur)
{
	if (i < 0 || j < 0 || i >(*demineur).row - 1 || j >(*demineur).column - 1 || (*demineur).reveal[i][j] == 1)
		return;
	(*demineur).reveal[i][j] = 1;
	(*demineur).nb_reveal++;
	if ((*demineur).tab[i][j] == 0)
	{
		flood_fill(i + 1, j, demineur);
		flood_fill(i - 1, j, demineur);
		flood_fill(i, j + 1, demineur);
		flood_fill(i, j - 1, demineur);
		flood_fill(i + 1, j + 1, demineur);
		flood_fill(i - 1, j - 1, demineur);
		flood_fill(i + 1, j - 1, demineur);
		flood_fill(i - 1, j + 1, demineur);
	}
}

int win_game(grille demineur)
{
	for (int i = 0; i < demineur.row; i++)
		for (int j = 0; j < demineur.column; j++)
			if (demineur.reveal[i][j] == 0 && demineur.tab[i][j] != -1)
				return (0);
	system("cls");
	print_tab(demineur);
	cout << GREEN << "BRAVOOOOO !" << RESET << endl;
	return (1);
}