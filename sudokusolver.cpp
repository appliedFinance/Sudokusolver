#include "../RLS/rdist.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define MINVALUE 1
#define MAXVALUE 9
#define SPACE '.'
#define SIZE 81
#define TRUE 1
#define FALSE 0

typedef int Bool;
typedef int Cell;
typedef char Value;
typedef Value SudokuBoard[SIZE];
int mycounter;

// -----------------------------------------------------------
void showBoard(SudokuBoard board)
{
	int m= 0;
	for(Cell i=0; i<SIZE; i++)
	{
		printf("%c ", board[i]);
		if ( (i+1)%3 == 0 ) printf(" ");
		if ( (i+1)%9 == 0 ) 
		{
			printf("\n");
			m++;
			if (m%3 == 0) printf("\n");
		}
	}
	printf("---------------------\n");
}//showBoard

// -----------------------------------------------------------
Value toValue(int i) 
{
	if (i == 1) return '1';
	if (i == 2) return '2';
	if (i == 3) return '3';
	if (i == 4) return '4';
	if (i == 5) return '5';
	if (i == 6) return '6';
	if (i == 7) return '7';
	if (i == 8) return '8';
	if (i == 9) return '9';
}

// -----------------------------------------------------------
int toInt(Value c) {	return atoi(&c); }

// -----------------------------------------------------------
void clearCell(SudokuBoard game, Cell cell)
{
	if(0<=cell && cell<SIZE)  game[cell]= SPACE;
}

// -----------------------------------------------------------
void setCell(SudokuBoard game, Cell cell, Value value)
{
	if(0<=cell && cell<SIZE) game[cell]= value;
}

// -----------------------------------------------------------
void clearArray(int *a, int n) {for(int i=0; i<n; i++) a[i]= 0;}

// -----------------------------------------------------------
Bool isLegal(SudokuBoard g, Cell c, Value v)
{
	setCell(g,c,v);
	int a[10]; clearArray(a,10);
	int b[10]; clearArray(b,10);

//	system("clear"); showBoard(g); //usleep(30000);

	//check rows & cols
	for(Cell m=0; m<9; m++)
	{
		clearArray(a,10);
		clearArray(b,10);
		for(Cell n=0; n<9; n++)
		{
			int k = toInt( g[ m*9 + n ] );
			a[k]++;			
			int w = toInt( g[ n*9 + m ] );
			b[w]++;			
		}

		for(int i=1; i<=9; i++)
			if (a[i]>1 || b[i]>1)
			{
				clearCell(g,c);
				return FALSE;
			}
	}

	// check sub-sections
	clearArray(a,10);
	a[ toInt( g[0] ) ]++;
	a[ toInt( g[1] ) ]++;
	a[ toInt( g[2] ) ]++;
	a[ toInt( g[9] ) ]++;
	a[ toInt( g[10] ) ]++;
	a[ toInt( g[11] ) ]++;
	a[ toInt( g[18] ) ]++;
	a[ toInt( g[19] ) ]++;
	a[ toInt( g[20] ) ]++;

	for(int i=1; i<=9; i++)
		if (a[i]>1)
		{ 
			clearCell(g,c);
			return FALSE;
		}

	clearArray(a,10);
	a[ toInt( g[3] ) ]++;
	a[ toInt( g[4] ) ]++;
	a[ toInt( g[5] ) ]++;
	a[ toInt( g[12] ) ]++;
	a[ toInt( g[13] ) ]++;
	a[ toInt( g[14] ) ]++;
	a[ toInt( g[21] ) ]++;
	a[ toInt( g[22] ) ]++;
	a[ toInt( g[23] ) ]++;

	for(int i=1; i<=9; i++)
		if (a[i]>1)
		{ 
			clearCell(g,c);
			return FALSE;
		}

	clearArray(a,10);
	a[ toInt( g[6] ) ]++;
	a[ toInt( g[7] ) ]++;
	a[ toInt( g[8] ) ]++;
	a[ toInt( g[15] ) ]++;
	a[ toInt( g[16] ) ]++;
	a[ toInt( g[17] ) ]++;
	a[ toInt( g[24] ) ]++;
	a[ toInt( g[25] ) ]++;
	a[ toInt( g[26] ) ]++;

	for(int i=1; i<=9; i++)
		if (a[i]>1)
		{ 
			clearCell(g,c);
			return FALSE;
		}

	clearArray(a,10);
	a[ toInt( g[27] ) ]++;
	a[ toInt( g[28] ) ]++;
	a[ toInt( g[29] ) ]++;
	a[ toInt( g[36] ) ]++;
	a[ toInt( g[37] ) ]++;
	a[ toInt( g[38] ) ]++;
	a[ toInt( g[45] ) ]++;
	a[ toInt( g[46] ) ]++;
	a[ toInt( g[47] ) ]++;

	for(int i=1; i<=9; i++)
		if (a[i]>1)
		{ 
			clearCell(g,c);
			return FALSE;
		}

	clearArray(a,10);
	a[ toInt( g[30] ) ]++;
	a[ toInt( g[31] ) ]++;
	a[ toInt( g[32] ) ]++;
	a[ toInt( g[39] ) ]++;
	a[ toInt( g[40] ) ]++;
	a[ toInt( g[41] ) ]++;
	a[ toInt( g[48] ) ]++;
	a[ toInt( g[49] ) ]++;
	a[ toInt( g[50] ) ]++;

	for(int i=1; i<=9; i++)
		if (a[i]>1)
		{ 
			clearCell(g,c);
			return FALSE;
		}

	clearArray(a,10);
	a[ toInt( g[33] ) ]++;
	a[ toInt( g[34] ) ]++;
	a[ toInt( g[35] ) ]++;
	a[ toInt( g[42] ) ]++;
	a[ toInt( g[43] ) ]++;
	a[ toInt( g[44] ) ]++;
	a[ toInt( g[51] ) ]++;
	a[ toInt( g[52] ) ]++;
	a[ toInt( g[53] ) ]++;

	for(int i=1; i<=9; i++)
		if (a[i]>1)
		{ 
			clearCell(g,c);
			return FALSE;
		}

	clearArray(a,10);
	a[ toInt( g[54] ) ]++;
	a[ toInt( g[55] ) ]++;
	a[ toInt( g[56] ) ]++;
	a[ toInt( g[63] ) ]++;
	a[ toInt( g[64] ) ]++;
	a[ toInt( g[65] ) ]++;
	a[ toInt( g[72] ) ]++;
	a[ toInt( g[73] ) ]++;
	a[ toInt( g[74] ) ]++;

	for(int i=1; i<=9; i++)
		if (a[i]>1)
		{ 
			clearCell(g,c);
			return FALSE;
		}

	clearArray(a,10);
	a[ toInt( g[57] ) ]++;
	a[ toInt( g[58] ) ]++;
	a[ toInt( g[59] ) ]++;
	a[ toInt( g[66] ) ]++;
	a[ toInt( g[67] ) ]++;
	a[ toInt( g[68] ) ]++;
	a[ toInt( g[75] ) ]++;
	a[ toInt( g[76] ) ]++;
	a[ toInt( g[77] ) ]++;

	for(int i=1; i<=9; i++)
		if (a[i]>1)
		{ 
			clearCell(g,c);
			return FALSE;
		}

	clearArray(a,10);
	a[ toInt( g[60] ) ]++;
	a[ toInt( g[61] ) ]++;
	a[ toInt( g[62] ) ]++;
	a[ toInt( g[69] ) ]++;
	a[ toInt( g[70] ) ]++;
	a[ toInt( g[71] ) ]++;
	a[ toInt( g[78] ) ]++;
	a[ toInt( g[79] ) ]++;
	a[ toInt( g[80] ) ]++;

	for(int i=1; i<=9; i++)
		if (a[i]>1)
		{ 
			clearCell(g,c);
			return FALSE;
		}

	return TRUE;
}//isLegal

// -----------------------------------------------------------
Bool isFull(SudokuBoard game)
{
	for(Cell i=0; i<SIZE; i++)
	{
		if (game[i] == SPACE)  return FALSE;
	}
	return TRUE;
}//solved

// -----------------------------------------------------------
Cell findEmptyCell(SudokuBoard game)
{
	for(Cell i=0; i<SIZE; i++)
		if (game[i] == SPACE)
		{
			return i;
		}
}//findEmptyCell

// -----------------------------------------------------------
Bool hasSolution(SudokuBoard game)
{
	Bool solved;
	Cell tryCell;
	Value tryValue;
	int val; // loop counter

	if ( isFull(game) )
	{
		solved= TRUE;
	}
	else
	{
		val = MINVALUE;
		tryCell = findEmptyCell(game);
		solved= FALSE;

		while( !solved && (val <= MAXVALUE) )
		{
			tryValue = toValue(val);
			if (isLegal(game, tryCell, tryValue))
			{
				//				setCell(game, tryCell, tryValue);
				if ( hasSolution(game) )
				{
					solved= TRUE;
				}
				else
				{
					clearCell(game, tryCell);
				}
			}
			val++;
		}//while
	}//else
if (++mycounter % 100000 == 0)	printf("+");
	return solved;
}//solve

// -----------------------------------------------------------
void readBoard(SudokuBoard board)
{
	int count= SIZE;
	while(count-- > 0)
	{
		board[count]= SPACE;
	}
	char piece[]= {'1','2','3','4','5','6','7','8','9'};
	for(int i=0; i<8; i++)
	{
		int drawPiece = nUniform(0,8);
		int drawCell = nUniform(0,SIZE-1);
		board[drawCell]= piece[drawPiece];
	}
}//readBoard


// -----------------------------------------------------------
int main()
{
	srand(time(NULL));
	system("clear");

	SudokuBoard sample;
	readBoard(sample);
	showBoard(sample);
	mycounter= 0;
	if ( hasSolution(sample) )
	{
		printf("\n");
		showBoard(sample);
		printf("Solved !!\n\n");
	}
	else
		printf("Cannot solve your sudoku.\n\n");

	return 0;
}
