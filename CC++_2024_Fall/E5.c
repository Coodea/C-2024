/*
Name: Connor O'Dea
CWID: A20450243
Email-ID: connor.odea@okstate.edu
*/
#include <stdio.h>
#include <stdlib.h>

#define NUM_MARKS 3
struct Student {
    char name[50];
    int rollNumber;
    float marks[NUM_MARKS];
    float total;
    float average;
};

void calculateTotalAndAverage(struct Student *student) {
    student->total = 0;
    for (int i = 0; i < NUM_MARKS; i++) {
        student->total += student->marks[i];
    }
    student->average = student->total / NUM_MARKS;
}
int main() {
    int numStudents;

    printf("Enter the number of students: ");
    scanf("%d", &numStudents);

    struct Student *students = (struct Student *)malloc(numStudents * sizeof(struct Student));

    for (int i = 0; i < numStudents; i++) {
        printf("\nEnter details for student %d\n", i + 1);

        printf("Enter name: ");
        scanf("%s", students[i].name);

        printf("Enter number: ");
        scanf("%d", &students[i].rollNumber);

        for (int j = 0; j < NUM_MARKS; j++) {
            printf("Enter marks for subject %d: ", j + 1);
            scanf("%f", &students[i].marks[j]);
        }

        calculateTotalAndAverage(&students[i]);
    }
    printf("\nStudent Records:\n");
    for (int i = 0; i < numStudents; i++) {
        printf("\nStudent %d:\n", i + 1);
        printf("Name: %s\n", students[i].name);
        printf("Roll Number: %d\n", students[i].rollNumber);
        printf("Marks: ");
        for (int j = 0; j < NUM_MARKS; j++) {
            printf("%.2f ", students[i].marks[j]);
        }
        printf("\nTotal Marks: %.2f\n", students[i].total);
        printf("Average Marks: %.2f\n", students[i].average);
    }

    free(students);

    return 0;
}