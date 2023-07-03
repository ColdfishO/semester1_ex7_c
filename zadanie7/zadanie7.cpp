#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
#include<string.h>
void autor(void) {
	printf("\n");
	for (int i = 1; i <= 120; i++) printf("*");
	printf("Autor programu: Simon Dudek\n\n");
	for (int i = 1; i <= 120; i++) printf("*");
}
int main() {
	int s=0, z=0;
	char x[255], y[33];
	setlocale(LC_ALL, "");
	autor();
	printf("Podaj nazwę pliku, który ma zostać odczytany przez program: ");
	scanf_s("%s", x, 255);
	FILE* plik;
	errno_t err= fopen_s(&plik, x, "r");
	if (plik != NULL) {
		printf("Zawartość pliku:\n");
		while (feof(plik) == 0) {
			fscanf_s(plik, "%s", &y, 33);
			printf("%s ", y);
			if (fgetc(plik) == '\n') printf("\n");
			s += 1;
			z += strlen(y);
		}
		fclose(plik);
		printf("\nIlość słów wyniosła %d a ilość znaków %d\n", s, z);
	}
	else
	{
		printf("Błąd w otwarciu pliku!\n");
		printf("\nIlość słów wyniosła %d a ilość znaków %d\n", s, z);
	}
	system("pause");
	return 0;
}