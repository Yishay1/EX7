
#include "Board.h"
Board::Board(int sizei) {
	this->sizei =sizei;
	this->board = new square*[sizei];
	for (int i=0;i<sizei;i++) {
		board[i] = new square[sizei];
	}
}
ostream & operator<<(ostream & os,const Board & b) {
	for(int i = 0;i<b.sizei;i++){
		for(int j = 0;j<b.sizei;j++){
			os<<b.board[i][j];
		}
		os<<"\n";
	}
	return os;
}

Board& Board::operator=(char c) {
	if(c=='X'||c=='O'||c=='.') {
		for (int i = 0; i < sizei; i++) {
			for (int j = 0; j < sizei; j++) {
				this->board[i][j] = c;
			}
		}
	}
	else throw IllegalCharException(c);
	return *this;
}
Board& Board::operator=(Board & b) {
	free(this->board);
	this->sizei = b.sizei;
	this->board = new square*[b.sizei];
	for (int i=0;i<b.sizei;i++) {
		board[i] = new square[b.sizei];
	}
	for (int i = 0; i < b.sizei; i++) {
		for (int j = 0; j < b.sizei; j++) {
			this->board[i][j].set(b.board[i][j].get());
		}
	}
	return *this;
}
 square& Board::operator [](Coordinate c)const {
	if(c.x<sizei && c.y<sizei){
		return this->board[c.x][c.y];
	}
	else throw IllegalCoordinateException(c.x,c.y);

}

Board::Board()
{
	this->sizei=0;
	this->board=NULL;
}

Board::Board(const Board& b)
{
	this->sizei=b.sizei;
	this->board= new square*[sizei];
	for (int i=0;i<sizei;i++) {
		board[i] = new square[sizei];
	}
	for (int i = 0; i < b.sizei; i++) {
		for (int j = 0; j < b.sizei; j++) {
			this->board[i][j].set(b.board[i][j].get());
		}
	}
}

Board::~Board(){
    for (int i = 0; i <sizei ; ++i) {
            delete[] board[i];
    }delete[] board;
}
