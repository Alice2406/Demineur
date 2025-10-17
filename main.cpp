#include <iostream>
using namespace std;

const int TAILLE = 9;

struct grille {
	int tab[TAILLE][TAILLE];
	int reveal[TAILLE][TAILLE];
};

grille demineur;

void	init_tab_reveal()
{
	for (int i = 0; i < 9; i++)
		for (int j = 0; j < 9; j++)
			demineur.tab[i][j] = 0;
	for (int i = 0; i < 9; i++)
		for (int j = 0; j < 9; j++)
			demineur.reveal[i][j] = 0;
}

void	print_tab()
{
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			if (demineur.reveal[i][j] == 1)
			{
				if (demineur.tab[i][j] == 0)
					cout << "[ ]";
				else
					cout << "[" << demineur.tab[i][j] << "]";
			}
			else
				cout << "[ ]";
		}
		cout << endl;
	}
}

void	print_finish_tab()
{
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			if (demineur.tab[i][j] == -1)
				cout << "[*]";
			else if (demineur.reveal[i][j] == 1)
			{
				if (demineur.tab[i][j] == 0)
					cout << "[ ]";
				else
					cout << "[" << demineur.tab[i][j] << "]";
			}
			else
				cout << "[ ]";
		}
		cout << endl;
	}
}

//bombe d'exercice
void mine_exemple()
{
	demineur.tab[1][1] = -1;
	demineur.tab[1][2] = -1;
	demineur.tab[1][6] = -1;
	demineur.tab[4][0] = -1;
	demineur.tab[4][4] = -1;
	demineur.tab[4][8] = -1;
	demineur.tab[6][1] = -1;
	demineur.tab[6][3] = -1;
	demineur.tab[6][7] = -1;
	demineur.tab[7][3] = -1;
}

void	count_mine()
{
	int nb;
	int k = 0;
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			nb = 0;
			if (demineur.tab[i][j] != -1)
			{
				if ((i - 1) >= 0 && (j - 1) >= 0 && demineur.tab[i - 1][j - 1] == -1)
					nb++;
				if ((i - 1) >= 0 && demineur.tab[i - 1][j] == -1)
					nb++;
				if ((i - 1) >= 0 && (j + 1) < 9 && demineur.tab[i - 1][j + 1] == -1)
					nb++;
				if ((j - 1) >= 0 && demineur.tab[i][j - 1] == -1)
					nb++;
				if ((j + 1) < 9 && demineur.tab[i][j + 1] == -1)
					nb++;
				if ((i + 1) < 9 && (j - 1) >= 0 && demineur.tab[i + 1][j - 1] == -1)
					nb++;
				if ((i + 1) < 9 && demineur.tab[i + 1][j] == -1)
					nb++;
				if ((i + 1) < 9 && (j + 1) < 9 && demineur.tab[i + 1][j + 1] == -1)
					nb++;
				demineur.tab[i][j] = nb;
			}
		}
	}
}

void	flood_fill(int i, int j)
{
	if (i < 0 || j < 0 || i > 8 || j > 8 || demineur.tab[i][j] != 0)
	{
		if (demineur.tab[i][j] != 0)
			demineur.reveal[i][j] = 1;
		return;
	}
	demineur.reveal[i][j] = 1;
	flood_fill(i + 1, j);
	flood_fill(i - 1, j);
	flood_fill(i, j + 1);
	flood_fill(i, j - 1);
}

int main()
{
	int i, j;
	cout << "Bonjour et bienvenue sur mon demineur" << endl;
	init_tab_reveal();
	mine_exemple();
	count_mine();
	while (1)
	{
		cout << "Quelle case veut tu reveler ?";
		cin >> i;
		cin >> j;
		if (i > -1 && i < 9 && j > -1 && j < 9)
		{
			demineur.reveal[i][j] = 1;
			if (demineur.tab[i][j] == -1)
			{
				cout << "NULLOOOOOOOSSS" << endl;
				print_finish_tab();
				break;
			}
			else if (demineur.tab[i][j] == 0)
			{
				flood_fill(i, j);
				print_tab();
			}
			else
				print_tab();
		}
		else
			cout << "Mauvaise donnee, veuillez recommencer";

	}
}