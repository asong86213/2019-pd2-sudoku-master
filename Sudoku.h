using namespace std;

class Sudoku{
	public:
	static const int sudokuSize = 81;
	void generate();	//create a sudoku board
	void readIn();		//read in sudoku board(cin, 81 digits)
	void solve();	//judge first by readIn() function(solvable =>1, usolvable =>0, more than one solution => 2)
	void change();
	void changeNum(int a, int b);
	void changeRow(int a, int b);
	void changeCol(int a, int b);
	void rotate(int n);
	void flip(int n);
	void transform();
	void printOut();	
	private:
	int board[sudokuSize];
	int board2[9][9];
	int board3[9][9];
};
