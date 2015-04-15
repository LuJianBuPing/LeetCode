#include <iostream>
#include <string.h>
#include <stdio.h>

using namespace std;

#define INVALID 1
#define X_WIN 2
#define O_WIN 3
#define DRAW 4

#define NEXT_X 5
#define NEXT_O 6
#define NEXT_WIN 7
#define NEXT_NOT_WIN 8

char* resultStr[] = {"","Invalid","X win", "O win", "Draw", "", "", "Next win", "Next cannot win"};

int valid(char board[3][3])
{
	int cx = 0, co = 0, c_ = 0;
	for (int i = 0; i < 3; ++i)
		for (int j = 0; j < 3; ++j)
		{
		if (board[i][j] == 'X')
			++cx;
		else if (board[i][j] == 'O')
			++co;
		else if (board[i][j] == '_')
			++c_;
		}

	if (cx>co + 1 || co > cx)
		return INVALID;

	int linex = 0, lineo = 0;
	for (int i = 0; i < 3; ++i)
	{
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2])
		{
			if (board[i][0] == 'X')
				++linex;
			else if (board[i][0] == 'O')
				++lineo;
		}
		if (board[0][i] == board[1][i] && board[1][i] == board[2][i])
		{
			if (board[0][i] == 'X')
				++linex;
			else if (board[0][i] == 'O')
				++lineo;
		}
	}

	if (board[0][0] == board[1][1] && board[1][1] == board[2][2])
	{
		if (board[0][0] == 'X')
			++linex;
		else if (board[0][0] == 'O')
			++lineo;
	}

	if (board[2][0] == board[1][1] && board[1][1] == board[0][2])
	{
		if (board[0][2] == 'X')
			++linex;
		else if (board[0][2] == 'O')
			++lineo;
	}

	//cout << "cx" << cx << "co" << co << "c_" << c_ <<"lx"<<linex << "lo"<<lineo << endl;


	if (linex != 0 && lineo != 0)
		return INVALID;
	if (linex > 0)
	{
		if (cx == co)
			return INVALID;
		return X_WIN;
	}
	if (lineo > 0)
	{
		if (cx != co)
			return INVALID;
		return O_WIN;
	}
	if (cx + co == 9)
		return DRAW;

	if (cx == co)
		return NEXT_X;
	else
		return NEXT_O;
}

int find(char board[3][3])
{
	int flag = valid(board);
	if (flag < 5)
		return flag;

	//cout << flag << endl;
	char nextP = (flag == NEXT_X ? 'X' : 'O');

	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			if (board[i][j] != '_')
				continue;
			board[i][j] = nextP;

			/*
			for (int i = 0; i < 3; ++i)
			{
				for (int j = 0; j < 3; ++j)
					cout << board[i][j];
				cout << endl;
			}
			*/

			int flag2 = valid(board);
			if (flag2 == X_WIN || flag2 == O_WIN)
				return NEXT_WIN;

			//cout << flag2 << endl;

			board[i][j] = '_';
		}
	}
	return NEXT_NOT_WIN;
}
//
//int main()
//{
//	int T;
//
//	scanf("%d", &T);
//
//	//cin >> T;
//	char buf[10];
//	char board[3][3];
//	for (int _case = 0; _case < T; ++_case)
//	{
//		//getchar();
//		for (int i = 0; i < 3; ++i)
//		{
//			memset(buf, 0, sizeof(buf));
//			scanf("%s", buf);
//			//printf("%s",buf);
//			for (int j = 0; j < 3; ++j)
//			{
//				if (buf[j] == '_' || buf[j] == 'X' || buf[j] == 'O')
//					board[i][j] = buf[j];
//				else
//					printf("invalid char\n");
//			}
//		}
//		printf("%s\n", resultStr[find(board)]);
//	}
//
//	return 0;
//	//system("pause");
//}