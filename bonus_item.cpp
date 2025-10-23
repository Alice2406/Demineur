#include "Demineur.h"

void    bonus_item_random(grille* demineur, int x, int y)
{
    srand(time(0));

    int first;
    int nb = 0;
    while (!nb)
    {
        first = 0;
        int i = rand() % (*demineur).row;
        int j = rand() % (*demineur).column;
        if (i == x && j == y)
            first = 1;
        if (!first && (*demineur).tab[i][j] != -1)
        {
            (*demineur).bonus[i][j] = 1;
            nb++;
        }
    }
}

void    bonus_mine_random(grille* demineur, int x, int y)
{
    srand(time(0));

    int first;
    int nb = 0;
    while (!nb)
    {
        first = 0;
        int i = rand() % (*demineur).row;
        int j = rand() % (*demineur).column;
        if (i == x && j == y)
            first = 1;
        if (!first && (*demineur).tab[i][j] != -1 && (*demineur).bonus[i][j] != 1)
        {
            (*demineur).bonus[i][j] = -1;
            nb++;
        }
    }
}

int    item_bonus_present(grille demineur)
{
    int max = demineur.row * demineur.column - demineur.nb_reveal;
    for (int i = 0; i < demineur.row; i++)
        for (int j = 0; j < demineur.column; j++)
            if ((demineur.bonus[i][j] == 1 || demineur.bonus[i][j] == -1) && demineur.reveal[i][j] == 1 && max >= 10)
                return (demineur.bonus[i][j]);
    return (0);
}

void    reset_bonus(grille* demineur, int nb)
{
    for (int i = 0; i < (*demineur).row; i++)
        for (int j = 0; j < (*demineur).column; j++)
            if ((*demineur).bonus[i][j] == nb)
                (*demineur).bonus[i][j] = 0;
}

void    bonus_case_activate(grille* demineur)
{
    srand(time(0));
    int nb = 0;
    while (nb < 3)
    {
        int i = rand() % (*demineur).row;
        int j = rand() % (*demineur).column;
        if ((*demineur).tab[i][j] != -1 && (*demineur).reveal[i][j] != 1 && (*demineur).tab[i][j] != 0)
        {
            (*demineur).reveal[i][j] = 1;
            reset_bonus(demineur, 1);
            nb++;
        }
    }
}

void    bonus_mine_activate(grille* demineur)
{
    srand(time(0));
    int nb = 0;
    while (nb < 3)
    {
        int i = rand() % (*demineur).row;
        int j = rand() % (*demineur).column;
        if ((*demineur).tab[i][j] != -1 && (*demineur).reveal[i][j] != 1)
        {
            (*demineur).tab[i][j] = -1;
            count_mine(demineur);
            reset_bonus(demineur, -1);
            nb++;
        }
    }
}

void    bonus_activate(int nb, grille* demineur)
{
    if ((*demineur).row * (*demineur).column - (*demineur).nb_reveal - (*demineur).nb_mine < 10)
        return;
    if (nb == 1)
    {
        cout << MAGENTA << "Item Bonus debloque : 3 nouvelles cases" << RESET << endl;
        bonus_case_activate(demineur);
    }
    else
    {
        cout << RED << "Item Bonus debloque : 3 nouvelles mines" << RESET << endl;
        bonus_mine_activate(demineur);
    }
}