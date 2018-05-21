#include "Player.h"

class Champion: public Player
{
public:
	const string name() const override{return "Yishay";}
	const Coordinate play(const Board& board) override;
};
