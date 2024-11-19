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