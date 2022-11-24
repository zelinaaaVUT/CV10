// CV09.cpp : Defines the entry point for the application.
//

#include "CV09.h"
#include <stdio.h>


int main()
{
	const char* vstupniCesta = "D:\\vstup.txt";
	const char* vystupniCesta = "D:\\vysledky.txt";
	int pismena = 0;
	int cisla = 0;
	int slova = 0;
	int vety = 0;

	FILE* vstupniSoubor;
	FILE* vystupniSoubor;

	if (fopen_s(&vstupniSoubor, vstupniCesta, "r") != 0) {
		printf("Soubor se nepodarilo otevrit\n");
		return -1;
	}
	else
	{
		while (!feof(vstupniSoubor)) {

			char c = getc(vstupniSoubor);

			if (isalpha(c) != 0) {
				pismena++;
			}
			else if (isdigit(c) != 0) {
				cisla++;
			}
			else if (c == '.') {
				vety++;
			}
			else if (c == ' ' || c == '\n' || c == '\t' || c == '\0') {
				slova++;
			}
		}
	}

	if (fopen_s(&vystupniSoubor, vystupniCesta, "w") != 0) {
		printf("Soubor se nepodarilo otevrit\n");
		return -1;
	}
	else
	{
		fprintf(vystupniSoubor, "Pocet pismen: %d\n", pismena);
		fprintf(vystupniSoubor, "Pocet cisel: %d\n", cisla);
		fprintf(vystupniSoubor, "Pocet slov: %d\n", slova);
		fprintf(vystupniSoubor, "Pocet vet: %d\n", vety);
	}

	fclose(vstupniSoubor);
	fclose(vystupniSoubor);

	printf("Pismena: %d\n", pismena);
	printf("Cisla: %d\n", cisla);
	printf("Slova: %d\n", slova);
	printf("Vety: %d\n", vety);
	return 0;
}
