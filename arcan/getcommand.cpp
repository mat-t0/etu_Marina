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