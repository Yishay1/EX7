#include "Player.h"

class TicTacToe
{
	public:
		
		Player* winneri;
		Board b;
		int numOfPlays;

		TicTacToe(int);
		void play(Player&,Player&);
		Player& winner()const;
		Board board()const{return b;}
	private:
		bool done();
};

