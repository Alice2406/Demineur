#include "demineur.h"

void mine_random(grille* demineur, int x, int y)
{
	srand(time(0));
	int k = 0;
	int max = (*demineur).row * (*demineur).column * 0.15;
	int first;
	while (k < max)
	{
		first = 0;
		int i = rand() % (*demineur).row;
		int j = rand() % (*demineur).column;
		if (i == x && j == y)
			first = 1;
		if (!first && (*demineur).tab[i][j] != -1)
		{
			(*demineur).tab[i][j] = -1;
			k++;
		}
	}
	(*demineur).nb_mine = k;
}

void	count_mine(grille* demineur)
{
	int nb;
	int k = 0;
	for (int i = 0; i < (*demineur).row; i++)
	{
		for (int j = 0; j < (*demineur).column; j++)
		{
			nb = 0;
			if ((*demineur).tab[i][j] != -1)
			{
				if ((i - 1) >= 0 && (j - 1) >= 0 && (*demineur).tab[i - 1][j - 1] == -1)
					nb++;
				if ((i - 1) >= 0 && (*demineur).tab[i - 1][j] == -1)
					nb++;
				if ((i - 1) >= 0 && (j + 1) < (*demineur).column && (*demineur).tab[i - 1][j + 1] == -1)
					nb++;
				if ((j - 1) >= 0 && (*demineur).tab[i][j - 1] == -1)
					nb++;
				if ((j + 1) < (*demineur).column && (*demineur).tab[i][j + 1] == -1)
					nb++;
				if ((i + 1) < (*demineur).row && (j - 1) >= 0 && (*demineur).tab[i + 1][j - 1] == -1)
					nb++;
				if ((i + 1) < (*demineur).row && (*demineur).tab[i + 1][j] == -1)
					nb++;
				if ((i + 1) < (*demineur).row && (j + 1) < (*demineur).column && (*demineur).tab[i + 1][j + 1] == -1)
					nb++;
				(*demineur).tab[i][j] = nb;
			}
		}
	}
}