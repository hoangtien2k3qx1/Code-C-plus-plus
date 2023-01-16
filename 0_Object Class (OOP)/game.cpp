
#include<bits/stdc++.h>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <math.h>
#include <conio.h>
#define max 500

// kêu người dùng nhập kích thước bàn cờ và khởi tạo trạng thái bàn cờ ban đầu là 0.
void khoidong(char a[][max], int &m)
{

	printf("Moi ban nhap kich thuoc dong va cot\n");
	scanf("%d", &m);
	while (m <= 5)
	{
		printf("Moi ban lai nhap kich thuoc dong va cot\n");
		scanf("%d", &m);
	}
	for (int i = 0; i < m; i++)
		for (int j = 0; j < m; j++)
		{
			a[0][j] = j;
			a[i][0] = i;
			if (i != 0 || j != 0)
				a[i][j] = '.';
		}
}

// kiểm tra đã đầy quân cờ trên bàn cờ chưa
int isfull(char a[][max], int m)
{
	int dem = 0;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < m; j++)
			if (i != 0 && j != 0)
				if (a[i][j] == '.')
					dem++;
	}
	if (dem == 0)
		return 0;
	return 1;
}

// hàm người chơi nhập quân cờ, và kiểm tra tính hợp lệ khi chọn ô cần đánh
void nhap1(char a[][max], int m, int &i1, int &j1, char s1[])
{
	printf("\n Moi %s nhap o can danh", s1);
	printf("   nhap dong:");
	scanf("%d", &i1);
	printf("   nhap cot:");
	scanf("%d", &j1);
	if ((i1 == 100 && j1 == 100) || (i1 == 0 && j1 == 0))
		return;
	while (i1 <= 0 || j1 <= 0 || a[i1][j1] == 'X' || a[i1][j1] == 'O' || i1 >= m || j1 >= m)
	{
		printf("\n Moi %s nhap lai o can danh", s1);
		scanf("%d", &i1);
		scanf("%d", &j1);
		if ((i1 == 100 && j1 == 100) || (i1 == 0 && j1 == 0))
			return;
	}

	a[i1][j1] = 'O';
}

void nhap2(char a[][max], int m, int &i2, int &j2, char s2[])
{
	printf("\n Moi %s nhap o can danh:", s2);
	printf("   nhap dong:");
	scanf("%d", &i2);
	printf("   nhap cot:");
	scanf("%d", &j2);
	if (i2 == 100 && j2 == 100)
		return;
	while (i2 <= 0 || j2 <= 0 || a[i2][j2] == 'O' || a[i2][j2] == 'X' || i2 >= m || j2 >= m)
	{
		printf("\n Moi %s lai nhap o can danh", s2);
		scanf("%d", &i2);
		scanf("%d", &j2);
		if (i2 == 100 && j2 == 100)
			return;
	}
	a[i2][j2] = 'X';
}

// kiểm tra có win chưa
void xet_dong(char a[][max], int m, char s1[], char s2[], int &win)
{
	int demo = 0, demx = 0;
	for (int i = 0; i < m; i++)
	{
		demo = 0;
		demx = 0;
		for (int j = 0; j < m; j++)
		{

			if (a[i][j] == 'O')
				demo++;
			else
			{
				if (a[i][j] == 'X')
				{
					if (demo >= 5 && a[i][j - (demo + 1)] != 'X')
						demo = 5;
					else
						demo = 0;
				}
				if (a[i][j] == '.')
					if (demo >= 5)
						demo = 5;
					else
						demo = 0;
			}

			if (a[i][j] == 'X')
				demx++;
			else
			{
				if (a[i][j] == 'O')
				{
					if (demx >= 5 && a[i][j - (demx + 1)] != 'O')
						demx = 5;
					else
						demx = 0;
				}
				if (a[i][j] == '.')
					if (demx >= 5)
						demx = 5;
					else
						demx = 0;
			}
		}
		if (demo >= 5)
		{
			printf("\nNGUOI CHOI %s DA WIN\n", s1);
			win = 1;
		}
		if (demx >= 5)
		{
			printf("\nNGUOI CHOI %s DA WIN\n", s2);
			win = 1;
		}
	}
}

void xet_cot(char a[][max], int m, char s1[], char s2[], int &win)
{
	int demo = 0, demx = 0;
	for (int j = 0; j < m; j++)
	{
		demo = 0;
		demx = 0;
		for (int i = 0; i < m; i++)

		{
			if (a[i][j] == 'O')
				demo++;
			else
			{
				if (a[i][j] == 'X')
				{
					if (demo >= 5 && a[i - (demo + 1)][j] != 'X')
						demo = 5;
					else
						demo = 0;
				}
				if (a[i][j] == '.')
					if (demo >= 5)
						demo = 5;
					else
						demo = 0;
			}

			if (a[i][j] == 'X')
				demx++;
			else
			{
				if (a[i][j] == 'O')
				{
					if (demx >= 5 && a[i - demx + 1][j] != 'O')
						demx = 5;
					else
						demx = 0;
				}
				if (a[i][j] == '.')
					if (demx >= 5)
						demx = 5;
					else
						demx = 0;
			}
		}
		if (demo >= 5)
		{
			printf("\nNGUOI CHOI %s DA WIN\n", s1);
			win = 1;
		}
		if (demx >= 5)
		{
			printf("\nNGUOI CHOI %s DA WIN\n", s2);
			win = 1;
		}
	}
}

void xet_cheo_tren_chinh(char a[][max], int m, char s1[], char s2[], int &win)
{
	int demo = 0, demx = 0;
	int i = 0, k = 0;
	for (int j = 1; j < m; j++)
	{
		demo = 0;
		demx = 0;

		k = j;
		i = 0;
		while (k < m)
		{
			if (a[i][k] == 'O')
				demo++;
			else
			{
				if (a[i][k] == 'X')
				{
					if (demo >= 5 && a[i - demo + 1][k - demo + 1] != 'X')
						demo = 5;
					else
						demo = 0;
				}
				if (a[i][k] == '.')
					if (demo >= 5)
						demo = 5;
					else
						demo = 0;
			}
			if (a[i][k] == 'X')
				demx++;
			else
			{
				if (a[i][k] == 'O')
				{
					if (demx >= 5 && a[i - demx + 1][k - demx + 1] != 'O')
						demx = 5;
					else
						demx = 0;
				}
				if (a[i][k] == '.')
					if (demx >= 5)
						demx = 5;
					else
						demx = 0;
			}
			k++;
			i++;
		}

		if (demo >= 5)
		{
			printf("\nNGUOI CHOI %s DA WIN\n", s1);
			win = 1;
		}
		if (demx >= 5)
		{
			printf("\nNGUOI CHOI %s DA WIN\n", s2);
			win = 1;
		}
	}
}
void xet_cheo_duoi_phu(char a[][max], int m, char s1[], char s2[], int &win)
{
	int demo = 0, demx = 0;
	int j = 0, k = 0;
	for (int i = 1; i < m; i++)
	{
		demo = 0;
		demx = 0;

		k = i;
		j = m - 1;
		while (k < m)
		{

			if (a[k][j] == 'O')
			{
				demo++;
			}
			else
			{
				if (a[k][j] == 'X')
				{
					if (demo >= 5 && a[k - demo + 1][j + demo + 1] != 'X')
						demo = 5;
					else
						demo = 0;
				}
				if (a[k][j] == '.')
					if (demo >= 5)
						demo = 5;
					else
						demo = 0;
			}
			if (a[k][j] == 'X')
				demx++;
			else
			{
				if (a[k][j] == 'O')
				{
					if (demx >= 5 && a[k - demx + 1][j + demx + 1] == 'O')
						demx = 5;
					else
						demx = 0;
				}
				if (a[k][j] == '.')
					if (demx >= 5)
						demx = 5;
					else
						demx = 0;
			}
			k++;
			j--;
		}

		if (demo >= 5)
		{
			printf("\nNGUOI CHOI %s DA WIN\n", s1);
			win = 1;
		}
		if (demx >= 5)
		{
			printf("\nNGUOI CHOI %s DA WIN\n", s2);
			win = 1;
		}
	}
}

void xet_cheo_duoi_chinh(char a[][max], int m, char s1[], char s2[], int &win)
{
	int demo = 0, demx = 0;
	int j = 0, k = 0;
	for (int i = 1; i < m; i++)
	{
		demo = 0;
		demx = 0;

		k = i;
		j = 0;
		while (k < m)
		{
			if (a[k][j] == 'O')
				demo++;
			else
			{
				if (a[k][j] == 'X')
				{
					if (demo >= 5 && a[k - demo + 1][j - demo + 1] != 'X')
						demo = 5;
					else
						demo = 0;
				}
				if (a[k][j] == '.')
					if (demo >= 5)
						demo = 5;
					else
						demo = 0;
			}
			if (a[k][j] == 'X')
				demx++;
			else
			{
				if (a[k][j] == 'O')
					if (demx >= 5 && a[k - demx + 1][j - demx + 1] != 'O')
						demx = 5;
					else
						demx = 0;
				if (a[k][j] == '.')
					if (demx >= 5)
						demx = 5;
					else
						demx = 0;
			}
			k++;
			j++;
		}

		if (demo >= 5)
		{
			printf("\nNGUOI CHOI %s DA WIN\n", s1);
			win = 1;
		}
		if (demx >= 5)
		{
			printf("\nNGUOI CHOI %s DA WIN\n", s2);
			win = 1;
		}
	}
}

void xet_cheo_tren_phu(char a[][max], int m, char s1[], char s2[], int &win)
{
	int demo = 0, demx = 0;
	int i = 0, k = 0;
	for (int j = 1; j < m; j++)
	{
		demo = 0;
		demx = 0;

		k = j;
		i = 0;
		while (k > 0)
		{
			if (a[i][k] == 'O')
				demo++;
			else
			{
				if (a[i][k] == 'X')
				{
					if (demo >= 5 && a[i - demo + 1][k + demo + 1] != 'X')
						demo = 5;
					else
						demo = 0;
				}
				if (a[i][k] == '.')
					if (demo >= 5)
						demo = 5;
					else
						demo = 0;
			}
			if (a[i][k] == 'X')
				demx++;
			else
			{
				if (a[i][k] == 'O')
				{
					if (demx >= 5 && a[i - demx + 1][k + demx + 1] != 'O')
						demx = 5;
					else
						demx = 0;
				}
				if (a[i][k] == '.')
					if (demx >= 5)
						demx = 5;
					else
						demx = 0;
			}
			k--;
			i++;
		}

		if (demo >= 5)
		{
			printf("\nNGUOI CHOI %s DA WIN\n", s1);
			win = 1;
		}
		if (demx >= 5)
		{
			printf("\nNGUOI CHOI %s DA WIN\n", s2);
			win = 1;
		}
	}
}

void xet_chinh(char a[][max], int m, char s1[], char s2[], int &win)
{
	int demo = 0, demx = 0;
	for (int i = 0; i < m; i++)
	{
		if (a[i][i] == 'X')
			demx++;
		else
		{
			if (a[i][i] == 'O')
			{
				if (demx >= 5 && a[i - demx + 1][i - demx + 1] != 'O')
					demx = 5;
				else
					demx = 0;
			}
			if (a[i][i] == '.')
				if (demx >= 5)
					demx = 5;
				else
					demx = 0;
		}
		if (a[i][i] == 'O')
			demo++;
		else
		{
			if (a[i][i] == 'X')
			{
				if (demo >= 5 && a[i - demo + 1][i - demo + 1] != 'X')
					demo = 5;
				else
					demo = 0;
			}
			if (a[i][i] == '.')
				if (demo >= 5)
					demo = 5;
				else
					demo = 0;
		}
	}
	if (demo >= 5)
	{
		printf("\nNGUOI CHOI %s DA WIN\n", s1);
		win = 1;
	}
	if (demx >= 5)
	{
		printf("\nNGUOI CHOI %s DA WIN\n", s2);
		win = 1;
	}
}

void xet_phu(char a[][max], int m, char s1[], char s2[], int &win)
{
	int demo = 0, demx = 0;
	for (int i = 0; i < m; i++)
	{
		demx = 0;
		demo = 0;
		for (int j = 0; j < m; j++)
		{
			if (i + j == m - 1)
			{
				if (a[i][j] == 'O')
					demo++;
				else
				{
					if (a[i][j] == 'X')
					{
						if (demo >= 5 && a[i - demo + 1][j + demo + 1] != 'X')
							demo = 5;
						else
							demo = 0;
					}
					if (a[i][j] == '.')
						if (demo >= 5)
							demo = 5;
						else
							demo = 0;
				}
				if (a[i][j] == 'X')
					demx++;
				else
				{
					if (a[i][j] == 'O')
					{
						if (demx >= 5 && a[i - demx + 1][j + demx + 1] != 'O')
							demx = 5;
						else
							demx = 0;
					}
					if (a[i][j] == '.')
						if (demx >= 5)
							demx = 5;
						else
							demx = 0;
				}
			}
		}
		if (demo >= 5)
		{
			printf("\nNGUOI CHOI %s DA WIN\n", s1);
			win = 1;
		}
		if (demx >= 5)
		{
			printf("\nNGUOI CHOI %s DA WIN\n", s2);
			win = 1;
		}
	}
}

// xuất ra bàn cờ
void xuat(char a[][max], int m)
{

	printf("\nban co la:\n");
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (i == 0 || j == 0)
				printf("%4d", a[i][j]);
			else
				printf("%4c", a[i][j]);
		}
		printf("\n");
		printf("\n");
	}
}

// hàm hướng dẫn người chơi
void huong_dan()
{
	printf("Ban lan luot nhap toa do=(so dong,so cot)\n");
	printf("Ban khong duoc nhap len toa do da nhap,neu ban nhap sai se nhap lai\n");
	printf("Neu ben nao co >=5 quan co cua minh giong nhau lien tiep thi se thang\n ");
	printf("VD:XXXXX->Win\n");
	printf("Neu ban bi doi phuong chan 2 dau khi ben trong co 5 quan co cua minh nhung van chua Thang\n");
	printf("VD:OXXXXXO->NO WIN\n");
	printf("Neu ban bi doi phuong chan 2 dau khi ben trong co 5 quan co cua minh nhung khong sat thi se Thang\n");
	printf("VD OXXXXX O->WIN\n");
	printf("Neu ban muon Thoat, exit= so dong=100 va  so cot=100\n");
	printf("toa do chet(100,100)\n");
	printf("Neu muon choi lai thi nhap: dong:0 va cot 0\n");
	printf("(0,0)\n");
	printf("Neu ma tat ca cac o bi danh het ma chua co nguoi thang thi 2 ben se hoa\n");
	printf("thank you! chuc ban choi vui(^_^)\n");
	printf("     2-Bat Dau Choi\n");
	printf("     3-Thoat\n");
	printf("Ban muon chon:");
}

int main()
{
	system("cls");

	int k, n, win = 0;
	char s1[20], s2[20], kt;
	char a[max][max];
	int m, i1, j1, i2, j2;
	printf("Xin nhap yeu cau\n");
	printf("     1-Huong Dan Choi\n");
	printf("     2-Bat Dau Choi\n");
	printf("     3-Thoat\n");
	printf("Ban muon chon:");
	scanf("%d", &n);
	do
	{
		switch (n)
		{

		case 1:
			huong_dan();
			scanf("%d", &n);
			break;
		case 2:
			printf("\nGAME START\n");
			printf("Nhap ten cua nguoi choi thu 1: ");
			scanf("%s", s1);
			printf("Nhap ten cua nguoi choi thu 2: ");
			scanf("%s", s2);
			khoidong(a, m);
			system("cls");
			xuat(a, m);
			do
			{

				k = isfull(a, m);
				if (k == 1)
				{
					nhap1(a, m, i1, j1, s1);
				}
				system("cls");
				xuat(a, m);
				xet_dong(a, m, s1, s2, win);
				xet_cot(a, m, s1, s2, win);
				xet_cheo_tren_chinh(a, m, s1, s2, win);
				xet_cheo_tren_phu(a, m, s1, s2, win);
				xet_cheo_duoi_phu(a, m, s1, s2, win);
				xet_cheo_duoi_chinh(a, m, s1, s2, win);
				xet_chinh(a, m, s1, s2, win);
				xet_phu(a, m, s1, s2, win);
				if (win == 1 || k == 0 || (i1 == 100 && j1 == 100) || (i2 == 100 && j2 == 100) || (i1 == 0 && j1 == 0) || (i2 == 0 && j2 == 0))
				{
					printf("ban co muon choi lai khong? Y/N \n");
					scanf("%s", &kt);
					if ((i1 == 0 && j1 == 0) || (i2 == 0 && j2 == 0) || kt == 'Y' || kt == 'y' || k == 0)
					{
						if (k == 0)
							printf("%s HOA %s\n", s1, s2);
						win = 0;
						break;
					}

					else
					{

						return 0;
					}
				}
				k = isfull(a, m);
				if (k == 1)
				{
					nhap2(a, m, i2, j2, s2);
				}
				system("cls");
				xuat(a, m);
				xet_dong(a, m, s1, s2, win);
				xet_cot(a, m, s1, s2, win);
				xet_cheo_tren_chinh(a, m, s1, s2, win);
				xet_cheo_tren_phu(a, m, s1, s2, win);
				xet_cheo_duoi_phu(a, m, s1, s2, win);
				xet_cheo_duoi_chinh(a, m, s1, s2, win);
				xet_chinh(a, m, s1, s2, win);
				xet_phu(a, m, s1, s2, win);
				if (win == 1 || k == 0 || (i1 == 100 && j1 == 100) || (i2 == 100 && j2 == 100) || (i1 == 0 && j1 == 0) || (i2 == 0 && j2 == 0))
				{
					printf("ban co muon choi lai khong? Y/n \n");
					scanf("%s", &kt);
					if ((i1 == 0 && j1 == 0) || (i2 == 0 && j2 == 0) || kt == 'Y' || kt == 'y' || k == 0)
					{
						if (k == 0)
							printf("%s HOA %s\n", s1, s2);
						win = 0;
						break;
					}

					else
					{

						return 0;
					}
				}

			} while (k == 1 && win == 0);
			break;
		case 3:
			break;
		default:
			printf("Ban da chon sai\n Moi ban nhap lai:");
			scanf("%d", &n);
		}
	} while (n != 3);

	std::cin.get();
	return 0;
}

