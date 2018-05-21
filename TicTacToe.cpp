#include "TicTacToe.h"

TicTacToe::TicTacToe(int i)
{
	Board b1{i};
	b=b1;
	this->numOfPlays=i*i;
}
void TicTacToe::play(Player& x,Player& o)
{
	this->b='.';
	this->numOfPlays=b.size()*b.size();
	x.setChar('X');
	o.setChar('O');
	bool isEndFlag=false;
	while(!isEndFlag)
	{
		try{
			b[x.play(b)]=x.getChar();
		}
		catch(const IllegalCharException& ex){
			winneri=&o;
			break;
		}catch (string s) {
			winneri=&o;
			break;
		}
		if(done())
		{
			if(this->numOfPlays==0) winneri=&o;
			else winneri=&x;
			isEndFlag=true;
			break;
		}
		try{
			b[o.play(b)]=o.getChar();
		}catch(const IllegalCharException& ex){
			winneri=&x;
			break;

		}catch (string s) {
			winneri=&x;
			break;
		}
		if(done())
		{
			winneri=&o;
			isEndFlag=true;
			break;
		}
	}
}

bool TicTacToe::done()
{
	this->numOfPlays--;
/*return true if board is full*/
	if(numOfPlays==0)return true;
/*return true if there is row of 'O' or row of 'X'*/	
	for(int row=0;row<b.size();row++)
	{
		
		bool wonFlag=true;
		for(int col=1;col<b.size();col++)
		{
			
			Coordinate c1{row,col-1};
			Coordinate c2{row,col};
			wonFlag=wonFlag && b[c1].get()==b[c2].get() && b[c1].get()!='.';	
		}
		if(wonFlag) return true;
	}
/*return true if there is col of 'O' or col of 'X'*/
	for(int col=0;col<b.size();col++)
	{
		bool wonFlag=true;
		for(int row=1;row<b.size();row++)
		{
			Coordinate c1{row-1,col};
			Coordinate c2{row,col};
			wonFlag=wonFlag && b[c1].get()==b[c2].get() && b[c1].get()!='.';	
		}
		if(wonFlag) return true;
	}
/* main diagonal*/
	bool wonFlag=true;
	for(int i=1;i<b.size();i++)
	{
		
		Coordinate c1{i-1,i-1};
		Coordinate c2{i,i};
		wonFlag=wonFlag && b[c1].get()==b[c2].get() && b[c1].get()!='.';
	}
	if(wonFlag) return true;
/*secondary diagonal*/
	wonFlag=true;
	for(int i=1;i<b.size();i++)
	{
		
		Coordinate c1{i-1,b.size()-(i-1)-1};
		Coordinate c2{i,b.size()-i-1};
		wonFlag=wonFlag && b[c1].get()==b[c2].get() && b[c1].get()!='.';
	}
	if(wonFlag) return true;
	
	return false;
}

Player& TicTacToe::winner()const
{
	return *winneri;
}
