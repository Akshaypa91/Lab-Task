#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_SUBJECTS 100
#define MAX_STUDENTS 100
#define MAX_NAME_LEN 50
#define MAX_GRADES 8

typedef struct {
    char name[MAX_NAME_LEN];
    int credits;
    int semester;
} Subject;

typedef struct {
    float ranges[MAX_GRADES];
} GradeRange;

typedef struct {
    char mis[MAX_NAME_LEN];
    float marks[MAX_SUBJECTS];
} Student;

Subject subjects[MAX_SUBJECTS];
GradeRange gradeRanges[MAX_SUBJECTS];
Student students[MAX_STUDENTS];

int numSubjects = 0;
int numStudents = 0;

// Function prototypes
void loadSubjects();
void loadGrades();
void loadMarks();
char *getGrade(float marks, int subjectIndex);
float calculateCGPA(char *mis);
float calculateSGPA(char *mis, int semester);
void listFailedSubjects(char *mis);
void listTopperInSemester(int semester);
void listTopperInSubject(char *subject);
void listTopNInSubject(char *subject, int n);
void printAllGrades();
float calculateStdDev(char *subject);
void handleQueries();

int main() {
    loadSubjects();
    loadGrades();
    loadMarks();
    handleQueries();
    return 0;
}

// Load subjects from subjects.csv
void loadSubjects() {
    FILE *file = fopen("subjects.csv", "r");
    if (!file) {
        printf("Error: Cannot open subjects.csv\n");
        exit(1);
    }
    while (fscanf(file, "%[^,],%d,%d\n", subjects[numSubjects].name, 
                  &subjects[numSubjects].credits, 
                  &subjects[numSubjects].semester) == 3) {
        numSubjects++;
    }
    fclose(file);
}

// Load grade ranges from grades.csv
void loadGrades() {
    FILE *file = fopen("grades.csv", "r");
    if (!file) {
        printf("Error: Cannot open grades.csv\n");
        exit(1);
    }
    for (int i = 0; i < numSubjects; i++) {
        for (int j = 0; j < MAX_GRADES; j++) {
            fscanf(file, "%f,", &gradeRanges[i].ranges[j]);
        }
        fscanf(file, "\n");
    }
    fclose(file);
}

// Load marks from marks.csv
void loadMarks() {
    FILE *file = fopen("marks.csv", "r");
    if (!file) {
        printf("Error: Cannot open marks.csv\n");
        exit(1);
    }
    while (fscanf(file, "%[^,],", students[numStudents].mis) == 1) {
        for (int i = 0; i < numSubjects; i++) {
            fscanf(file, "%f,", &students[numStudents].marks[i]);
        }
        fscanf(file, "\n");
        numStudents++;
    }
    fclose(file);
}

// Get grade based on marks and grade ranges
char *getGrade(float marks, int subjectIndex) {
    float *ranges = gradeRanges[subjectIndex].ranges;
    if (marks <= ranges[0]) return "FF";
    if (marks <= ranges[1]) return "DD";
    if (marks <= ranges[2]) return "CD";
    if (marks <= ranges[3]) return "CC";
    if (marks <= ranges[4]) return "BC";
    if (marks <= ranges[5]) return "BB";
    if (marks <= ranges[6]) return "AB";
    return "AA";
}

// Calculate CGPA for a student
float calculateCGPA(char *mis) {
    int found = 0;
    float totalPoints = 0;
    int totalCredits = 0;
    for (int i = 0; i < numStudents; i++) {
        if (strcmp(students[i].mis, mis) == 0) {
            found = 1;
            for (int j = 0; j < numSubjects; j++) {
                char *grade = getGrade(students[i].marks[j], j);
                int gradePoint = (grade[0] - 'A' + 10) - (grade[0] == 'F' ? 10 : 0);
                totalPoints += gradePoint * subjects[j].credits;
                totalCredits += subjects[j].credits;
            }
            break;
        }
    }
    if (!found) {
        printf("Error: Student with MIS %s not found\n", mis);
        return -1;
    }
    return totalPoints / totalCredits;
}

// Handle user queries
void handleQueries() {
    char command[100], arg1[50], arg2[50];
    while (1) {
        printf("> ");
        scanf("%s", command);

        if (strcmp(command, "exit") == 0) {
            break;
        } else if (strcmp(command, "grade") == 0) {
            scanf("%s %s", arg1, arg2);
            int subjectIndex = -1;
            for (int i = 0; i < numSubjects; i++) {
                if (strcmp(subjects[i].name, arg2) == 0) {
                    subjectIndex = i;
                    break;
                }
            }
            if (subjectIndex == -1) {
                printf("Error: Subject %s not found\n", arg2);
                continue;
            }
            int found = 0;
            for (int i = 0; i < numStudents; i++) {
                if (strcmp(students[i].mis, arg1) == 0) {
                    found = 1;
                    printf("%s\n", getGrade(students[i].marks[subjectIndex], subjectIndex));
                    break;
                }
            }
            if (!found) {
                printf("Error: Student with MIS %s not found\n", arg1);
            }
        } else if (strcmp(command, "cgpa") == 0) {
            scanf("%s", arg1);
            float cgpa = calculateCGPA(arg1);
            if (cgpa >= 0) {
                printf("CGPA: %.2f\n", cgpa);
            }
        } else {
            printf("Error: Invalid command\n");
        }
    }
}