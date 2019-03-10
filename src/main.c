#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char fileLocation[] = "/home/simplex/Documents/studentSchedule/storage/homework.txt";

struct homework {
    int id;
    char title[30];
    char desciption[100];
};

void saveHomework(struct homework details);

int main(int argc, char **argv) {

    struct homework details;

    printf("Enter homework id: ");
    scanf(" %d", &details.id);

    printf("Enter homework title: ");
    scanf(" %s", details.title);

    printf("Enter homework desciption: ");
    scanf(" %s", details.desciption);

    saveHomework(details);

    return 0;
}

void saveHomework(struct homework details) {
    FILE *pfile;

    printf("%d\n", details.id);
    printf("%s\n", details.title);
    printf("%s\n", details.desciption);

    pfile = fopen(fileLocation, "ab");

    fwrite(&details, sizeof(details), 1, pfile);

    fclose(pfile);
}
