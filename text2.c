#define _CRT_SECURE_NO_WARNINGS
#define MAX_ROW 3
#define MAX_COL 3
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int menu() {
	printf("========\n");
	printf("1.开始游戏\n");
    printf("0.结束游戏\n");
    printf("========\n");
	printf("请输入您的选择\n");
	int choice = 0;
	scanf("%d", &choice);
	return choice;
}

char chess_board[MAX_ROW][MAX_COL];
void Init() {
	for (int row = 0; row < MAX_ROW; ++row) {
		for (int col=0; col < MAX_COL; ++col) {
			  chess_board[row][col] = ' ';
		}
	}
	srand((unsigned int)time(0));
}

void print(){
	for (int row = 0; row < MAX_ROW; ++row) {
		printf("| %c | %c | %c |\n", chess_board[row][0], chess_board[row][1], chess_board[row][2]);
		if (row != MAX_ROW - 1) {
			printf("|---|---|---|\n");
		}
	}
}
void Playermove() {
	printf("玩家落子！\n");
	while (1) {
		printf("请输入落子位置的坐标（row col):");
		int row = 0;
		int col = 0;
		scanf("%d %d", &row, &col);
		if (row < 0 || row >= MAX_ROW || col<0 || col>=MAX_COL){
			printf("您的输入有误！请重新输入！\n");
			continue;
		}
		if (chess_board[row][col] != ' ') {
				printf("您要落子的位置已经被占用！\n");
					continue;
		}
		chess_board[row][col] = 'x';
			break;
	}
	printf("玩家落子完毕！\n");
}
void Computermove(){
	printf("电脑落子!\n");
	while (1){
		int row = rand() % 3;
		int col = rand() % 3;
		if(chess_board[row][col] != ' ') {
			continue;
		}
		chess_board[row][col] = 'o';
		break;
	}
	printf("电脑落子完毕\n");
}
int ISFULL() {
	for (int row = 0; row < MAX_ROW; ++row) {
		for (int col = 0; col < MAX_COL; ++col) {
			if (chess_board[row][col] == ' ') {
				return 0;
			}
		}
	}
	return 1;
} 
char checkwinner() { 
	for(int row = 0; row < MAX_ROW; ++row) {
		if (chess_board[row][0] == chess_board[row][1]
			&& chess_board[row][0] == chess_board[row][2]) {
			return chess_board[row][0];
		}
	}
    for (int col=0; col < MAX_COL; ++col) {
	    if (chess_board[0][col] == chess_board[1][col]
		&& chess_board[0][col] == chess_board[2][col]) {
		return chess_board[0][col];
	    }
	}
	if (chess_board[0][0] == chess_board[1][1]
		&& chess_board[0][0] == chess_board[2][2]) {
		return chess_board[0][0];
    }
	if(chess_board[0][2] == chess_board[1][1]
		&& chess_board[0][2] == chess_board[2][0]) {
		return chess_board[0][2];
	}
	if (ISFULL()) {
		return 'q';
	}
	return ' ';
}
void Game() {
	Init();
	char winner = ' ';
	while (1) {
		print();
		Playermove();
		winner = checkwinner();
		if (winner != ' ') {
			break;
		}
		Computermove();
		winner = checkwinner();
		if (winner != ' ') {
			break;
		}
	}
	    print();
		if (winner == 'x') {
			printf("您赢了！\n");
		}else if (winner == 'o') {
			printf("你个垃圾!\n");

		}else if (winner == 'q') {
			printf("您和电脑半斤八两！\n");
		}else {
			printf("代码好像bug了！\n");
		}

}
int main() {
	while (1) {
		int choice = menu();
		if (choice == 1) {
			Game();
		}
		else if (choice ==0) {
			printf("goodbye!\n");
			break;
		}else {
			printf("您的输入有误!\n");
		}
	}
	system("pause");
	return 0;
}