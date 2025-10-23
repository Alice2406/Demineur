#include "Demineur.h"

int main()
{
	grille demineur;
	int i, j, type;
	cout << CYAN << "Bonjour et Bienvenue sur mon demineur" << RESET << endl;
	choose_level(&demineur.row, &demineur.column);
	for (int i = 0; i < demineur.row; i++)
		for (int j = 0; j < demineur.column; j++)
		{
			demineur.tab[i][j] = 0;
			demineur.reveal[i][j] = 0;
			demineur.bonus[i][j] = 0;
		}
	questions(&i, &j, &type, demineur);
	mine_random(&demineur, i, j);
	bonus_item_random(&demineur, i, j);
	bonus_mine_random(&demineur, i, j);
	count_mine(&demineur);
	while (1)
	{
		if (type == 24)
			demineur.cat = 1;
		else if (type == 2)
		{
			cout << BLUE << "Triste que tu partes" << RESET << endl;
			return 0;
		}
		else if (type == 1)
		{
			if (demineur.reveal[i][j] == 0)
				demineur.reveal[i][j] = -1;
			else if (demineur.reveal[i][j] == -1)
				demineur.reveal[i][j] = 0;
		}
		else
		{
			if (demineur.tab[i][j] == -1)
			{
				print_finish_tab(demineur);
				break;
			}
			else if (demineur.tab[i][j] == 0)
				flood_fill(i, j, &demineur);
			else
			{
				demineur.reveal[i][j] = 1;
				demineur.nb_reveal++;
			}
		}
		if (item_bonus_present(demineur) == -1)
			bonus_activate(-1, &demineur);
		if (item_bonus_present(demineur) == 1)
			bonus_activate(1, &demineur);
		if (win_game(demineur))
			break;
		system("cls");
		print_tab(demineur);
		questions(&i, &j, &type, demineur);
	}
}