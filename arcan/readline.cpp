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