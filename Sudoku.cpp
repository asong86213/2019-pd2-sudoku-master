#include <iostream>
#include <fstream>
#include "Sudoku.h"
#include <cstdlib>
#include <vector>

static int k = 0;
using namespace std;

void Sudoku::generate(){
	int i;
	/*ifstream sudokuQ("sudokuQ.in,ios::in");
	for(i = 0; i<sudokuSize;i++){
	sudokuQ>>board[i];
	}*/

	int boardTest[sudokuSize]={8,0,0,0,0,0,0,0,0,0,0,3,6,0,0,0,0,0,0,7,0,0,9,0,2,0,0,0,5,0,0,0,7,0,0,0,0,0,0,0,4,5,7,0,0,0,0,0,1,0,0,0,3,0,0,0,1,0,0,0,0,6,8,0,0,8,5,0,0,0,1,0,0,9,0,0,0,0,4,0,0};
	//transform();
	for(i=0;i<sudokuSize;i++){
		cout<<boardTest[i]<<((i+1)%9==0?'\n':' ');
	}
}

void Sudoku::readIn(){
	for(int i=0;i<sudokuSize;i++)
		cin>>board[i];
}

void Sudoku::solve(){
	int isAvailable(int board2[][9], int row, int col, int num);
	int fillsudoku(int board2[][9], int row, int col);
	int fillsudoku1(int board2[][9], int row, int col);
	int checkboard(int board[][9]);
	int i, j;
	for(i=0;i<9;i++){
		for(j=0;j<9;j++){
			board2[i][j] = board[j+(i*9)];
			board3[i][j] = board[j+(i*9)];
		}
	}
	checkboard(board2);
	if(fillsudoku(board2, 0, 0) && fillsudoku1(board3, 0, 0)){
		for(i=0;i<9;i++){
			for(j=0;j<9;j++){
				if((board2[i][j] != board3[i][j])){
					cout<<"2"<<endl;
					exit(1);
				}
			}
		}
		cout<<"1"<<endl;
		for(i=0; i<9; ++i)
		{
			for(j=0; j<9; ++j)
			{
				cout<<board2[i][j]<<" ";
			}
			cout<<endl;
		}
	}
	else
	{
		cout<<"0"<<endl;
	}
}

int isAvailable(int board2[][9], int row, int col, int num)
{
	int i, j;
	for(i=0; i<9; ++i)
		if( (board2[row][i] == num) || ( board2[i][col] == num )  )//checking in row and col
			return 0;

	//checking in the grid
	int rowStart = (row/3) * 3;
	int colStart = (col/3) * 3;

	for(i=rowStart; i<(rowStart+3); ++i)
	{
		for(j=colStart; j<(colStart+3); ++j)
		{
			if( board2[i][j] == num )
				return 0;
		}
	}    

	return 1;
}    

int checkboard(int board2[][9])
{
	int i,j,k,l;
	for(i=0;i<9;i++){
		for(j=0;j<9;j++){
			if(board2[i][j] != 0){
				for(k=j+1;k<9;k++){
					if((board2[i][k] == board2[i][j])){
						cout<<"0"<<endl;
						exit(1);
					}
				}
				for(l=i+1;l<9;l++){
					if(board2[l][j] == board2[i][j]){
						cout<<"0"<<endl;
						exit(1);
					}
				}
			}
		}
	}

}

int fillsudoku(int board2[][9], int row, int col)
{
	int i;
	if( row<9 && col<9 )
	{
		if( board2[row][col] != 0 )//pre filled 
		{
			if( (col+1)<9 )
				return fillsudoku(board2, row, col+1);
			else if( (row+1)<9 )
				return fillsudoku(board2, row+1, 0);
			else
				return 1;
		}
		else
		{
			for(i=0; i<9; ++i)
			{
				if( isAvailable(board2, row, col, i+1) )
				{
					board2[row][col] = i+1;

					if( (col+1)<9 )
					{
						if( fillsudoku(board2, row, col+1) )
							return 1;
						else
							board2[row][col] = 0;
					}
					else if( (row+1)<9 )
					{
						if( fillsudoku(board2, row+1, 0) )    
							return 1;
						else
							board2[row][col] = 0;
					}
					else

						return 1;
				}
			}
		}
		return 0;
	}
	else
	{
		return 1;
	}
} 
int fillsudoku1(int board2[][9], int row, int col)
{
	int i;
	if( row<9 && col<9 )
	{
		if( board2[row][col] != 0 )//pre filled 
		{
			if( (col+1)<9 )
				return fillsudoku1(board2, row, col+1);
			else if( (row+1)<9 )
				return fillsudoku1(board2, row+1, 0);
			else
				return 1;
		}
		else
		{
			for(i=8; i>=0; i--)
			{
				if( isAvailable(board2, row, col, i+1) )
				{
					board2[row][col] = i+1;

					if( (col+1)<9 )
					{
						if( fillsudoku1(board2, row, col +1) )
							return 1;
						else
							board2[row][col] = 0;
					}
					else if( (row+1)<9 )
					{
						if( fillsudoku1(board2, row+1, 0) )    
							return 1;
						else
							board2[row][col] = 0;
					}
					else
						return 1;
				}
			}
		}
		return 0;
	}
	else
	{
		return 1;
	}
} 

void Sudoku::change(){
	
	while(1){
	
	int arr[3]={};
	vector<int>array(arr,arr+sizeof(arr)/sizeof(int));

	int i = 0;
	size_t pos = 0;
	string line1;
	string token;
	getline(cin, line1);
	
	while ((pos = line1.find(" ")) != string::npos){
	    token = line1.substr(0, pos);
	    array[i]=atoi(token.c_str());
	    line1.erase(0, pos+1);
	    i++;
	}
	array[i]=atoi(line1.c_str());

	if(array[0] == 1){
		changeNum(array[1],array[2]);k++;
	}
	else if(array[0] == 2){
		changeRow(array[1],array[2]);k++;
	}
	else if(array[0] == 3){
		changeCol(array[1],array[2]);k++;
	}
	else if(array[0] == 4){
		rotate(array[1]);k++;
	}
	else if(array[0] == 5){
		flip(array[1]);k++;
	}
	else if(array[0] == 0 && k>0){
		printOut();
		exit(1);
	}
    }
}

void Sudoku::changeNum(int a, int b){
	int i;
	int board_tmp[sudokuSize];
	for(i=0;i<sudokuSize;i++){
		board_tmp[i] = board[i];
		if(board[i]==a){
			board[i] = b;
		}
		if(board_tmp[i]==b){
			board[i] = a;
		}
	}
}

void Sudoku::changeRow(int a, int b){
	int board_tmp[sudokuSize];
	int i;
	if(a == 0){
		for(i=0;i<27;i++){
			board_tmp[i] = board[i];
		}
		switch(b)
		{
			case 0:
				break;
			case 1:
				for(i=0;i<27;i++){
					board[i] = board[i+27];
					board[i+27] = board_tmp[i];
				}
				break;
			case 2:
				for(i=0;i<27;i++){
					board[i] = board[i+54];
					board[i+54] = board_tmp[i];
				}
				break;

		} 
	}
	else if(a == 1){
		for(i=27;i<54;i++){
			board_tmp[i] = board[i];
		}
		switch(b)
		{
			case 0:
				for(i=27;i<54;i++){
					board[i] = board[i-27];
					board[i-27] = board_tmp[i];
				}
				break;
			case 1:
				break;
			case 2:
				for(i=27;i<54;i++){
					board[i] = board[i+27];
					board[i+27] = board_tmp[i];
				}
				break;
		}
	}
	else if(a == 2){
		for(i=54;i<sudokuSize;i++){
			board_tmp[i] = board[i];
		}
		switch(b)
		{
			case 0:
				for(i=54;i<sudokuSize;i++){
					board[i] = board[i-54];
					board[i-54] = board_tmp[i];
				}
				break;
			case 1:
				for(i=54;i<sudokuSize;i++){
					board[i] = board[i-27];
					board[i-27] = board_tmp[i];
				}
				break;
			case 2:
				break;
		}
	}

}

void Sudoku::changeCol(int a, int b){
	int i;
	int board_tmp1[sudokuSize],board_tmp2[sudokuSize],board_tmp3[sudokuSize];
	if(a == 0){
		for(i=0;i<9;i++){
			board_tmp1[0+(i*9)] = board[0+(i*9)];
			board_tmp2[1+(i*9)] = board[1+(i*9)];
			board_tmp3[2+(i*9)] = board[2+(i*9)];
		}
		switch(b)
		{
			case 0:
				break;
			case 1:
				for(i=0;i<9;i++){
					board[0+(i*9)] = board[3+(i*9)];
					board[1+(i*9)] = board[4+(i*9)];
					board[2+(i*9)] = board[5+(i*9)];
					board[3+(i*9)] = board_tmp1[0+(i*9)];
					board[4+(i*9)] = board_tmp2[1+(i*9)];
					board[5+(i*9)] = board_tmp3[2+(i*9)];
				}
				break;
			case 2:
				for(i=0;i<9;i++){
					board[0+(i*9)] = board[6+(i*9)];
					board[1+(i*9)] = board[7+(i*9)];
					board[2+(i*9)] = board[8+(i*9)];
					board[6+(i*9)] = board_tmp1[0+(i*9)];
					board[7+(i*9)] = board_tmp2[1+(i*9)];
					board[8+(i*9)] = board_tmp3[2+(i*9)];
				}
				break;
		}
	}
	else if(a == 1){
		for(i=0;i<9;i++){
			board_tmp1[3+(i*9)] = board[3+(i*9)];
			board_tmp2[4+(i*9)] = board[4+(i*9)];
			board_tmp3[5+(i*9)] = board[5+(i*9)];
		}
		switch(b)
		{
			case 0:
				for(i=0;i<9;i++){
					board[3+(i*9)] = board[0+(i*9)];
					board[4+(i*9)] = board[1+(i*9)];
					board[5+(i*9)] = board[2+(i*9)];
					board[0+(i*9)] = board_tmp1[3+(i*9)];
					board[1+(i*9)] = board_tmp2[4+(i*9)];
					board[2+(i*9)] = board_tmp3[5+(i*9)];
				}
				break;
			case 1:
				break;
			case 2:
				for(i=0;i<9;i++){
					board[3+(i*9)] = board[6+(i*9)];
					board[4+(i*9)] = board[7+(i*9)];
					board[5+(i*9)] = board[8+(i*9)];
					board[6+(i*9)] = board_tmp1[3+(i*9)];
					board[7+(i*9)] = board_tmp2[4+(i*9)];
					board[8+(i*9)] = board_tmp3[5+(i*9)];
				}
				break;
		}
	}
	else if(a == 2){
		for(i=0;i<9;i++){
			board_tmp1[6+(i*9)] = board[6+(i*9)];
			board_tmp2[7+(i*9)] = board[7+(i*9)];
			board_tmp3[8+(i*9)] = board[8+(i*9)];
		}
		switch(b)
		{
			case 0:
				for(i=0;i<9;i++){
					board[6+(i*9)] = board[0+(i*9)];
					board[7+(i*9)] = board[1+(i*9)];
					board[8+(i*9)] = board[2+(i*9)];
					board[0+(i*9)] = board_tmp1[6+(i*9)];
					board[1+(i*9)] = board_tmp2[7+(i*9)];
					board[2+(i*9)] = board_tmp3[8+(i*9)];
				}
				break;
			case 1:
				for(i=0;i<9;i++){
					board[6+(i*9)] = board[3+(i*9)];
					board[7+(i*9)] = board[4+(i*9)];
					board[8+(i*9)] = board[5+(i*9)];
					board[3+(i*9)] = board_tmp1[6+(i*9)];
					board[4+(i*9)] = board_tmp2[7+(i*9)];
					board[5+(i*9)] = board_tmp3[8+(i*9)];
				}
				break;
			case 2:
				break;
		}
	}
}

void Sudoku::rotate(int n){
	int i, j, k;
	int board_tmp[sudokuSize];
	for(k=0; k<n;k++){
		for(i=0;i<sudokuSize;i++){
			board_tmp[i] = board[i];
		}
		for(i=0;i<9;i++){
			for(j=0;j<9;j++){
				board[(8-i)+(j*9)] = board_tmp[(i*9)+j];
			}
		}
	}
}

void Sudoku::flip(int n){
	int i, j;
	int board_tmp[sudokuSize];

	for(i=0;i<sudokuSize;i++){
		board_tmp[i] = board[i];
	}
	if(n==1){
		for(i=0;i<4;i++){
			for(j=0;j<9;j++){
				board[(j*9)+i] = board[(j*9)+(8-i)];
				board[(j*9)+(8-i)] = board_tmp[(j*9)+i];	
			}			
		}
	}
	if(n==0){
		for(i=0;i<4;i++){
			for(j=0;j<9;j++){		
				board[j+(i*9)] = board[j+((8-i)*9)];
				board[j+(8-i)*9] = board_tmp[j+(i*9)];
			}
		}
	}
}

void Sudoku::transform(){
	readIn();
	change();
}

void Sudoku::printOut(){
	int i;
	for(i=0;i<sudokuSize;i++){
		cout<<board[i]<<((i+1)%9==0?'\n':' ');
	}
}
