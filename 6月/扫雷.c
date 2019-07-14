#define  _CRT_SECURE_NO_WARNINGS
#define MINE_COUNT 10//���׸���
#define MAX_ROW 9
#define MAX_COL 9
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int menu() {
	printf("========\n");
	printf("1.��ʼ��Ϸ\n");
	printf("0.������Ϸ\n");
	printf("========\n");
	printf("����������ѡ��\n");
	int choice = 0;
	scanf("%d", &choice);
	return choice;
}


	void Init(char show_map[MAX_ROW][MAX_COL],
		char mine_map[MAX_ROW][MAX_COL]) {
		for (int row = 0; row < MAX_ROW; ++row) {
			for (int col = 0; col < MAX_COL; ++col) {
				show_map[row][col] = '*';
			}
		}
		for (int row = 0; row < MAX_ROW; ++row) {
			for (int col = 0; col < MAX_COL; ++col) {
				mine_map[row][col] = '0';
			}
		}
		int n = MINE_COUNT;
		while (n > 0) {
			int row = rand()%MAX_ROW;
			int col = rand()%MAX_COL;
				if (mine_map[row][col] == '1') {
					continue;
				}
			mine_map[row][col] = '1';
			--n;
		}
		srand((unsigned int)time(0));
	}
	void printmap(char map[MAX_ROW][MAX_COL]) {
		printf("    ");

	for (int col = 0; col < MAX_COL ; ++col) {
		printf("%d ", col);
	}
	printf("\n");
	for (int col = 0; col < MAX_COL - 2; ++col) {
		printf("---");
	}
	printf("\n");

	for (int row = 0; row < MAX_ROW; ++row) {
		printf(" %d| ",row);
		for (int col = 0; col < MAX_COL; col++) {
			printf("%c ", map[row][col]);
		}
		printf("\n");
	}
}
	void Updateshowmap(int row, int col,
		char show_map[MAX_ROW][MAX_COL],
		char mine_map[MAX_ROW][MAX_COL]) {
		int count = 0;
		if (row - 1 >= 0 && col - 1 >= 0
			&& row - 1 < MAX_ROW&&col-1 < MAX_COL
			&&mine_map[row - 1][col - 1] == '1') {
			++count;
		}
		if (row - 1 >= 0 && col  >= 0
			&& row - 1 < MAX_ROW&&col < MAX_COL
			&&mine_map[row - 1][col] == '1') {
			++count;
		}
		if (row - 1 >= 0 && col+1 >= 0
			&& row - 1 < MAX_ROW&&col +1< MAX_COL
			&&mine_map[row - 1][col +1] == '1') {
			++count;
		}
		if (row >= 0 && col - 1 >= 0
			&& row  < MAX_ROW&&col < MAX_COL
			&&mine_map[row ][col - 1] == '1') {
			++count;
		}
		if (row  >= 0 && col +1 >= 0
			&& row  < MAX_ROW&&col < MAX_COL
			&&mine_map[row ][col+1] == '1') {
			++count;
		}
		if (row +1 >= 0 && col - 1 >= 0
			&& row +1 < MAX_ROW&&col < MAX_COL
			&&mine_map[row +1][col - 1] == '1') {
			++count;
		}
		if (row +1 >= 0 && col  >= 0
			&& row+1 < MAX_ROW&&col < MAX_COL
			&&mine_map[row+ 1][col ] == '1') {
			++count;
		}
		if (row +1 >= 0 && col +1 >= 0
			&& row +1 < MAX_ROW&&col+1 < MAX_COL
			&&mine_map[row +1][col+1] == '1') {
			++count;
		}
		show_map[row][col] ='0' + count;

	}
	void Game() {
		char show_map[MAX_ROW][MAX_COL];
		char mine_map[MAX_ROW][MAX_COL];
		int blank_count_alreadly_show = 0;
		Init(show_map, mine_map);
		while (1) {
			printmap(show_map);
			//printmap(mine_map);//�������Ժ���Ҫɾ��
			printf("������һ�����꣨row col):");
			int row = 0;
			int col = 0;
			scanf("%d %d", &row, &col);
			system("cls");
			if (row<0 || row>=MAX_ROW || col<0 || col>=MAX_COL) {
				printf("���������������������룺\n");
				continue;
			}
			if (show_map[row][col] != '*') {
				printf("�������λ���Ѿ��������ˣ�\n");
				continue;
			}
			if (mine_map[row][col] == '1' ) {
				printf("��Ϸ������\n");
					printmap(mine_map);
					break;
			}
					++blank_count_alreadly_show;
						if (blank_count_alreadly_show == MAX_COL * MAX_ROW - MINE_COUNT) {
							printf("��Ϸʤ����\n");
								printmap(mine_map);
								break;
						}
					Updateshowmap(row, col, show_map, mine_map);

			
		}
		
	}
	int main() {
		while (1) {
			int choice = menu();
			if (choice == 1) {
				Game();
			}else if (choice == 0) {
				printf("goodbye\n");
				break;
			}else {
				printf("������������\n");
			}
				
		}
		system("pause");
		return 0;
	}