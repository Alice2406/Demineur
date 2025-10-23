#include <iostream>
#include <ctime>

using namespace std;

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define WHITE   "\033[37m"
#define BOLD    "\033[1m"
#define GRAY    "\033[90m"
#define BG_RED  "\033[41m"

struct grille {
	int tab[30][30];
	int reveal[30][30];
	int bonus[30][30];
	int row;
	int column;
	int nb_reveal = 0;
	int nb_mine = 0;
	int cat = 0;
};

//-------------PRINT--------------//

void	print_numbers(int nb);
void	print_tab(grille demineur);
void	print_finish_tab(grille demineur);
void	flood_fill(int i, int j, grille* demineur);
int		win_game(grille demineur);

//--------------INIT--------------//

void	choose_level(int* row, int* column);
void	questions(int* i, int* j, int* type, grille demineur);

//--------------MINE--------------//

void	mine_random(grille* demineur, int x, int y);
void	count_mine(grille* demineur);

//--------------BONUS-------------//

void	bonus_item_random(grille* demineur, int x, int y);
void	bonus_mine_random(grille* demineur, int x, int y);
void    reset_bonus(grille* demineur, int nb);
void    bonus_case_activate(grille* demineur);
void    bonus_mine_activate(grille* demineur);
void    bonus_activate(int nb, grille* demineur);
int		item_bonus_present(grille demineur);

//------------SURPRISE------------//

void	easterEggCat();