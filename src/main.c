#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char fileLocation[] = "/home/simplex/Documents/studentSchedule/storage/homework.txt";

struct homework {
    int id;
    char title[30];
    char descritiption[100];
};

void saveHomework(struct homework detailsWrite);
void displayAllHomework(struct homework detailsRead);
void userWrite();
void userRead();

int main(int argc, char **argv) {

    char decision;
    int decisionBool;

    printf("Insert homework (i) or view homework (v): ");
    scanf(" %c", &decision);


    switch (decision) {
        case 105:
            userWrite();
            decisionBool = 0;
            break;
        case 118:
            userRead();
            decisionBool = 0;
            break;
        default:
            printf("\nYou did something wrong.\n\n");
            decisionBool = 1;
            break;
    }
    return 0;
}

void saveHomework(struct homework detailsWrite) {
    FILE *pfile;

    printf("%d\n", detailsWrite.id);
    printf("%s\n", detailsWrite.title);
    printf("%s\n", detailsWrite.descritiption);

    pfile = fopen(fileLocation, "ab");

    fwrite(&detailsWrite, sizeof(detailsWrite), 1, pfile);

    fclose(pfile);
}

void displayAllHomework(struct homework detailsRead) {
    FILE *pfile;

    pfile = fopen(fileLocation, "rb");

    system("clear");

    printf("\nHomework:\n\n\n");
    printf("id:\t\ttitle:\t\tdescritiption:\n\n");

    while(1) {
        fread(&detailsRead, sizeof(detailsRead), 1, pfile);

        if (feof(pfile)) {
            break;
        }

        printf("%d\t\t", detailsRead.id);
        printf("%s\t", detailsRead.title);
        printf("%s\n", detailsRead.descritiption);
        printf("-------------------------------------------------------------------------\n");
    }
    fclose(pfile);
}

void userWrite() {
    struct homework detailsWrite;

    printf("Enter homework id (int): ");
    scanf(" %d", &detailsWrite.id);

    printf("Enter homework title (string): ");
    scanf(" %[^\n]s", detailsWrite.title);

    printf("Enter homework descritiption (string): ");
    scanf(" %[^\n]s", detailsWrite.descritiption);

    saveHomework(detailsWrite);
}

void userRead() {
    struct homework detailsRead;

    displayAllHomework(detailsRead);
}
