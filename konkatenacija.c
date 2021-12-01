#include <stdio.h>
#include <stdlib.h>
int main() {
	char *old_p= NULL, *new_p, c;
	int i=0;
	// ucitavanje karaktera
	while ((c = getchar()) != '\n') {
		if (i % 10 == 0) {
			new_p = realloc(old_p, (i + 10) * sizeof(char));
			if (!new_p) {
				printf("realloc nije uspela.\n");

			}
			else {
				old_p = new_p;
			}

		}
		old_p[i++] = c;
	}
	// dodavanje terminalnog znaka
	new_p=realloc(old_p, (i + 1) * sizeof(char));
	if (!new_p) {
		printf("Realloc nije uspela.\n");
		i--;
	}
	else old_p = new_p;
	old_p[i] = c;
	
	old_p[i] = '\0';

	//ispis
	printf("%s", old_p);

	//oslovadjanje memorije
	free(old_p);

	system("pause");
	return 0;
}