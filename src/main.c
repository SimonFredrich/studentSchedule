#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char fileLocation[] = "/home/simplex/Documents/studentSchedule/storage/homework.txt";

struct homework {
    int id;
    char title[30];
    char desciption[100];
};

void saveHomework(struct homework detailsWrite);
void displayAllHomework(struct homework detailsRead);
void userWrite();
void userRead();

int main(int argc, char **argv) {

    userRead();

    return 0;
}

void saveHomework(struct homework detailsWrite) {
    FILE *pfile;

    printf("%d\n", detailsWrite.id);
    printf("%s\n", detailsWrite.title);
    printf("%s\n", detailsWrite.desciption);

    pfile = fopen(fileLocation, "ab");

    fwrite(&detailsWrite, sizeof(detailsWrite), 1, pfile);

    fclose(pfile);
}

void displayAllHomework(struct homework detailsRead) {
    FILE *pfile;

    pfile = fopen(fileLocation, "rb");

    while(1) {
        fread(&detailsRead, sizeof(detailsRead), 1, pfile);

        if (feof(pfile)) {
            break;
        }

        printf("%d\n", detailsRead.id);
        printf("%s\n", detailsRead.title);
        printf("%s\n", detailsRead.desciption);
    }
    fclose(pfile);
}

void userWrite() {
    struct homework detailsWrite;

    printf("Enter homework id: ");
    scanf(" %d", &detailsWrite.id);

    printf("Enter homework title: ");
    scanf(" %s", detailsWrite.title);

    printf("Enter homework desciption: ");
    scanf(" %s", detailsWrite.desciption);

    saveHomework(detailsWrite);
}

void userRead() {
    struct homework detailsRead;

    displayAllHomework(detailsRead);
}
