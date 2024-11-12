#define _CRT_SECURE_NO_WARNINGS
#include <conio.h>
#include <stdio.h>
#include <locale.h>
#include <windows.h>
#include <stdlib.h>
#include <stdbool.h>
#include <fstream>
#include <string>
#include <iostream>

using namespace std;
int n_readline(const char* fname, int n, char* buf, int len) {
	char  c;
	FILE* fp = fopen(fname, "rt");
	if (fp == NULL)
		return 0;

	while (!feof(fp) && (n > 0)) {
		fscanf(fp, "%*[^\n\r]%c", &c);
		--n;
	}

	if (!feof(fp))
		fgets(buf, len - 1, fp);
	else
		*buf = '\0';

	fclose(fp);
	return (int)(*buf != '\0');
}

void print_panel(int iItem)
{
	system("color B8");
	HANDLE h;
	h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(h, 2);
	setlocale(LC_CTYPE, "");
	system("cls");
	if (iItem == 1)
		printf("->");
	else
		printf("  ");
	printf("1 - Ввести дату\n");
	if (iItem == 2)
		printf("->");
	else
		printf("  ");
	printf("2 - Вывести файл\n");
	if (iItem == 3)
		printf("->");
	else
		printf("  ");
	printf("3 - Выход из программы\n");
}

int get_command()
{

	setlocale(LC_CTYPE, "");
	unsigned char a;
	a = _getch();

	if (a == 224)
		a = _getch();


	if (("%d", a) != 49 && ("%d", a) != 50 && ("%d", a) != 51 && ("%d", a) != 27 && ("%d", a) != 13 && ("%d", a) != 72 && ("%d", a) != 80)
		printf("Неверный ввод. Нажмите 'Enter' и повторите попытку\n");

	return ("%d", a);
}

long long data()
{

	setlocale(LC_CTYPE, "");
	char a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, k, y;
	y = 0;
	k = 0;
	char day[3];
	char month[3];
	char year[5];
	//1 simbol
	a1 = _getch();
	if (("%d", a1) < 48 || ("%d", a1) > 57)
	{
		return -1;

	}
	else
	{
		day[0] = ("%d", a1) - 48;
		printf("%d", day[0]);
	}
	//2 simbol
	a2 = _getch();
	if ((("%d", a2) < 48 || ("%d", a2) > 57) && ("%d", a2) != 46)
	{
		return -1;

	}
	else if (("%d", a2) == 46)
	{
		day[2] = '.';
		printf("\b\b%d%d.", 0, day[0]);
		day[1] = day[0];
		day[0] = 0;
	}
	else
	{
		day[1] = ("%d", a2) - 48;
		printf("%d", day[1]);
	}
	//3 simbol
	a3 = _getch();
	if ((("%d", a3) < 48 || ("%d", a3) > 57) && ("%d", a3) != 46)
	{
		return -1;

	}
	else if (("%d", a3) == 46)
	{
		if (day[2] == '.')
		{
			return -1;
		}
		else
		{
			k = 3;
			day[2] = '.';
			printf(".");

		}
	}
	else
	{
		k = 1;
		month[0] = ("%d", a3) - 48;
		if (day[2] != '.')
		{
			printf(".%d", month[0]);
		}
		else
		{
			printf("%d", month[0]);
		}
	}
	//4 simbol
	a4 = _getch();
	if ((("%d", a4) < 48 || ("%d", a4) > 57) && ("%d", a4) != 46)
	{
		return -1;

	}
	else if (("%d", a4) == 46)
	{
		if (k == 3)
		{
			return -1;
		}
		else
		{
			month[2] = '.';
			printf("\b%d%d.", 0, month[0]);
			month[1] = month[0];
			month[0] = 0;
		}

	}
	else
	{
		if (k == 1)
		{
			month[1] = ("%d", a4) - 48;
			printf("%d", month[1]);
		}
		else
		{
			month[0] = ("%d", a4) - 48;
			printf("%d", month[0]);
		}

	}

	//5 simbol
	a5 = _getch();
	if ((("%d", a5) < 48 || ("%d", a5) > 57) && ("%d", a5) != 46)
	{
		return -1;

	}
	else if (("%d", a5) == 46)
	{
		if (month[2] == '.')
		{
			return -1;
		}
		else
		{
			y = 1;
			if (k == 1)
			{
				month[2] = '.';
				printf(".");
			}
			else
			{
				month[2] = '.';
				printf("\b%d%d.", 0, month[0]);
				month[1] = month[0];
				month[0] = 0;
			}
		}
	}
	else
	{
		if (k == 1)
		{
			year[0] = ("%d", a5) - 48;
			if (month[2] != '.')
			{
				printf(".%d", year[0]);
				month[2] == '.';
			}
			else
			{
				printf("%d", year[0]);
			}
		}
		else
		{
			y = 3;
			month[1] = ("%d", a5) - 48;
			printf("%d", month[1]);
		}


	}
	//6 simbol
	a6 = _getch();
	if ((("%d", a5) < 48 || ("%d", a5) > 57) && ("%d", a5) != 46)
	{
		return -1;

	}
	else if (("%d", a6) == 46)
	{
		if (month[2] == '.')
		{
			return -1;
		}
		else
		{
			y = 2;
			printf(".");
		}


	}
	else
		if (y == 1)
		{
			year[0] = ("%d", a6) - 48;
			printf("%d", year[0]);
		}
		else if (y == 3)
		{
			y = 1;
			year[0] = ("%d", a6) - 48;
			printf(".%d", year[0]);
		}
		else
		{
			year[1] = ("%d", a6) - 48;
			printf("%d", year[1]);
		}
	//7 simbol
	a7 = _getch();
	if (("%d", a7) < 48 || ("%d", a7) > 57)
	{
		return -1;

	}

	else
	{
		if (y == 1)
		{
			year[1] = ("%d", a7) - 48;
			printf("%d", year[1]);
		}
		else if (y == 2)
		{
			year[0] = ("%d", a7) - 48;
			printf("%d", year[0]);
		}
		else
		{
			year[2] = ("%d", a7) - 48;
			printf("%d", year[2]);
		}
	}
	//8 simbol
	a8 = _getch();
	if (("%d", a8) < 48 || ("%d", a8) > 57)
	{
		return -1;

	}
	else
	{
		if (y == 1)
		{
			year[2] = ("%d", a8) - 48;
			printf("%d", year[2]);
		}
		else if (y == 2)
		{
			year[1] = ("%d", a8) - 48;
			printf("%d", year[1]);
		}
		else
		{
			year[3] = ("%d", a8) - 48;
			printf("%d", year[3]);
		}
	}
	//9 simbol
	if (y == 1 || y == 2)
	{
		a9 = _getch();
		if (("%d", a8) < 48 || ("%d", a8) > 57)
		{
			return -1;

		}
		else if (y == 1)
		{
			year[3] = ("%d", a9) - 48;
			printf("%d", year[3]);
		}
		else
		{
			year[2] = ("%d", a9) - 48;
			printf("%d", year[2]);
		}
	}
	//10 simbol
	if (y == 2)
	{
		a10 = _getch();
		if (("%d", a8) < 48 || ("%d", a8) > 57)
		{
			return -1;

		}
		else
		{
			year[3] = ("%d", a10) - 48;
			printf("%d", year[3]);
		}
	}
	long long llday = ("%d", day[0] * 10 + day[1]);
	long long llmonth = ("%d", month[0] * 10 + month[1]);
	long long llyear = ("%d", year[0] * 1000 + year[1] * 100 + year[2] * 10 + year[3]);
	if (llday == 0 || llmonth == 0 || llmonth > 12 || llyear > 2030 || llyear < 1930)
	{
		{
			return -1;
		}
	}
	if (llmonth == 1 || llmonth == 3 || llmonth == 5 || llmonth == 7 || llmonth == 8 || llmonth == 10 || llmonth == 12)
	{
		if (llday > 31)
		{
			return -1;
		}
	}
	else if (llmonth == 4 || llmonth == 6 || llmonth == 9 || llmonth == 11)
	{
		if (llday > 30)
		{
			return -1;
		}
	}
	else
	{
		if (llyear % 4 == 0)
		{
			if (llday > 29)
			{
				return -1;
			}
		}
		else
			if (llday > 28)
			{
				return -1;
			}
	}
	char data1 = ("%d%d.%d%d.%d%d%d%d", day[0], day[1], month[0], month[1], year[0], year[1], year[2], year[3]);
	ofstream fout;
	fout.open("data.txt");
	fout << "data1";
	fout.close();
	system("cls");
	print_panel(1);
	printf("Введённая дата: %d%d.%d%d.%d%d%d%d\n", day[0], day[1], month[0], month[1], year[0], year[1], year[2], year[3]);
	return llyear * 10000 + llmonth * 100 + llday;



}

int main()
{
	system("color B8");
	HANDLE h;
	h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(h, 2);
	setlocale(LC_CTYPE, "");
	char d;
	char iItem = 1;
	char nLast = 3;
	setlocale(LC_CTYPE, "");
	system("cls");
	print_panel(iItem);
	do
	{

		d = get_command();
		if (d == 72)
		{
			system("cls");
			if (0 < iItem - 1)
				iItem = iItem - 1;
			else
				iItem = nLast;
			print_panel(iItem);
		}
		if (d == 80)
		{
			system("cls");
			if (iItem < nLast)
				iItem = iItem + 1;
			else
				iItem = 1;
			print_panel(iItem);
		}
		if ((d == 49) || (d == 13 && iItem == 1))
		{
			system("cls");
			print_panel(1);
			printf("Введите дату: ");
			int data1 = data();
			if (data1 == -1)
			{
				printf("\nНекорректный ввод, повторите попытку, нажав '1'");
			}
			else
			{
				int arcan = data1 / 10000000 + (data1 / 1000000) % 10 + (data1 / 100000) % 10 + (data1 / 10000) % 10 + (data1 / 1000) % 10 + (data1 / 100) % 10 + (data1 / 10) % 10 + data1 % 10;
				if (arcan > 22)
				{
					arcan = arcan - 22;
					printf("\nВаш аркан равен %d\n", arcan);
				}
				else
				{
					printf("\nВаш аркан равен %d\n", arcan);
				}
				char str[50];
				snprintf(str, sizeof str, "%02d.%02d.%d", data1 % 100, (data1 % 10000) / 100, data1 / 10000);
				std::ofstream out("data.txt", std::ios::app);
				if (out.is_open())
				{
					out << str << std::endl;
				}
				out.close();

				char buf[255];


				//считать строку
				if (n_readline("arc.txt", arcan - 1, buf, sizeof(buf)))
				{
					puts(buf);
				}


			}



		}
		if ((d == 50) || (d == 13 && iItem == 2))
		{
			system("cls");
			print_panel(2);
			std::string line;

			std::ifstream in("data.txt"); // окрываем файл для чтения
			if (in.is_open())
			{
				while (std::getline(in, line))
				{
					std::cout << line << std::endl;
				}
			}
			in.close();

		}

		if ((d == 51) || (d == 13 && iItem == 3))
		{
			system("cls");
			print_panel(3);
			return 0;
		}

	} while (d != 51 && d != 27);
	return 0;
}

