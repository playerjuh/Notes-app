#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

struct Note {

	char title [100];
	char body [1000];

};

int main() {

	struct Note notesT[100];
	struct Note notesB[100];
	int select, numNotes = 0;

	printf(" Welcome to your notepad!\n ========================\n");



	do {

		printf("\n -------------------------\n");
		printf("|         OPTIONS         |\n");
		printf("| 1: Add a new note       |\n");
		printf("| 2: Change a note        |\n");
		printf("| 3: Display all notes    |\n");
		printf("| 4: Delete a note        |\n");
		printf("| 5: Leave the app        |\n");
		printf(" -------------------------\n");

		printf("\nWhat you want to do today? ");
		scanf("%d", &select);

		switch (select) {

		case 1: {

			getchar();
			printf("\nChoose the note title: ");
			
			fgets(notesT[numNotes].title, 100, stdin);

			printf("Write your note: ");
			fgets(notesB[numNotes].body, 1000, stdin);

			printf("--------------------------------------\n");
			printf("%s\n", notesT[numNotes].title);
			printf("\n%s", notesB[numNotes].body);
			printf("--------------------------------------\n\n");

			numNotes++;

			printf("------------------------------------------------------------------------------------------------------------------------");


			break;
		}
		case 2: {

			char title[100], choose2;

			getchar();
			printf("Which note you want to change? ");
			fgets(title, 100, stdin);

			for (int i = 0; i < numNotes; i++) {

				if (strcmp(notesT[i].title, title) == 0) {\

					printf("\nNote found!\n===========\n");
					printf("\n--------------------------------------------\n");
					printf("%s", notesT[i].title);
					printf("\n\n%s", notesB[i].body);
					printf("\n--------------------------------------------\n");

					printf("\nWhich part you want to change?\n");
					printf("1: title\n");
					printf("2: body\n");
					printf("3: all\n\n");
					printf("Choose an option: ");
					scanf("%d", &choose2);

					if (choose2 == 1) {
						getchar();
						printf("Choose a new title: ");
						fgets(notesT[i].title, 100, stdin);
						printf("\n\n");
					}

					else if (choose2 == 2) {

						getchar();
						printf("Choose the new body: ");
						fgets(notesB[i].body, 1000, stdin);
						printf("\n\n");
					}

					else if (choose2 == 3) {

						getchar();
						printf("Choose a new title: ");
						fgets(notesT[i].title, 100, stdin);
						printf("Choose the new body: ");
						fgets(notesB[i].body, 1000, stdin);

					}

					else {

						printf("Invalid! Please choose a valid option");
					}

				}

			}
			printf("------------------------------------------------------------------------------------------------------------------------");


			break;
		}

		case 3: {


			for (int i = 0; i < numNotes; i++) {

				printf("\n--------------------------------------------\n");
				printf("%s", notesT[i].title);
				printf("\n\n%s", notesB[i].body);
				printf("\n--------------------------------------------\n");

			}
			printf("------------------------------------------------------------------------------------------------------------------------");

			break;

		}

		case 4: {

			char title[100];

			getchar();
			printf("Which note you want to delete? Please tell the note's title: ");
			fgets(title, 100, stdin);

			for (int i = 0; i < numNotes; i++) {

				if (strcmp(notesT[i].title, title) == 0) {

					for (int j = i; j < numNotes; j++) {

						notesT[j] = notesT[j + 1];
						notesB[j] = notesB[j + 1];
					}

					numNotes--;

					printf("\n=========================\nNote deleted successfully\n=========================\n\n");


				}
				printf("------------------------------------------------------------------------------------------------------------------------");
			}
			break;
		}

		case 5: {

			printf("\n\n================Closing the app================\n\n");
			break;
		}
		

		default: {

			printf("Please choose a valid option");
			break;

		}

		}
	} while (select != 5);


	return 0;
}