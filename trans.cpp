#include <stdio.h>
#include <conio.h>
#include <string.h>
void rowtrans(char p[10][10]);
void coltrans(char p[10][10]);
int row, col, i, j;
char p[10][10];
int main()
{
	int ch = 0, l = 0;
	char plain[100];
	printf("Enter the plain text = ");
	gets(plain);
	printf("Enter no of rows = ");
	scanf("%d", &row);
	printf("Enter no of columns = ");
	scanf("\n%d", &col);
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			if (plain[l] != '\0')
			{
				if (plain[l] == ' ')
					l++;
				p[i][j] = plain[l];
				l++;
			}
			else
			{
				break;
			}
		}
	}
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			printf("%c ", p[i][j]);
		}
		printf("\n");
	}
	rowtrans(p);
	getch();
}
void rowtrans(char p[10][10])
{
	int l = 0, k[10], u;
	char c[10][10], x[10][10];
	printf("Enter the key to arrange 1 to %d column =\n", col);
	for (i = 0; i < col; i++)
		scanf("%d", &k[i]);
	printf("\n**********Encryption**********\n");
	for (i = 0; i < row; i++)
	{
		l = 0;
		for (j = 0; j < col; j++)
		{
			u = k[l] - 1;
			c[i][j] = p[i][u];
			l++;
		}
	}
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			printf("%c ", c[i][j]);
		}
		printf("\n");
	}
	printf("Cipher Text = ");
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			printf("%c", c[i][j]);
		}
	}
	printf("\n**********Decryption**********\n");
	l = 0;
	for (i = 0; i < row; i++)
	{
		l = 0;
		for (j = 0; j < col; j++)
		{
			u = k[l] - 1;
			x[i][u] = c[i][j];
			l++;
		}
	}
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			printf("%c ", x[i][j]);
		}
		printf("\n");
	}
	printf("Plain Text = ");
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			printf("%c", x[i][j]);
		}
	}
}
