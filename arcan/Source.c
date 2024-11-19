#include <stdio.h>
#include <locale.h>
#include <windows.h>
#include <stdlib.h>
#include <stdbool.h>
#include <fstream>
#include <string>
#include <iostream>
#include "data.h"
#include "panel.h"
#include "readline.h"
#include "getcommand.h"
#pragma once
using namespace std;


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
			char data10 = ("%02d.%02d.%d", data1%100, (data1/100)%100, data1/10000);
			ofstream fout;
			fout.open("data.txt");
			fout << data10;
			fout.close();
			system("cls");
			print_panel(1);
			printf("Введённая дата: %02d.%02d.%d", data1 % 100, (data1 / 100) % 100, data1 / 10000);
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
