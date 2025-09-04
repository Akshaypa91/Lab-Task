#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SUBJECTS 100
#define STUDENTS 100
#define NAME_LEN 50
#define GRADES 8

typedef struct
{
    char name[NAME_LEN];
    int credits;
    int semester;
} Subject;

typedef struct
{
    float ranges[GRADES];
} GradeRange;

typedef struct
{
    char mis[NAME_LEN];
    float marks[SUBJECTS];
} Student;

Subject subjects[SUBJECTS];
GradeRange gradeRanges[SUBJECTS];
Student students[STUDENTS];

int numSubjects = 0;
int numStudents = 0;

void lSubjects();
void lGrades();
void lMarks();
char *getGrade(float marks, int subjectIndex);
float calculateCGPA(char *mis);
void handleQueries();

int main()
{
    printf("Loading data...\n");
    lSubjects();
    printf("Subjects loaded: %d\n", numSubjects);
    lGrades();
    printf("Grades for subjects.\n");
    lMarks();
    printf("Marks for students: %d\n", numStudents);
    handleQueries();
    return 0;
}

void lSubjects()
{
    FILE *file = fopen("subjects.csv", "r");
    if (!file)
    {
        printf("Error: Cannot open subjects.csv\n");
        exit(1);
    }
    while (fscanf(file, "%c,%d,%d\n", &subjects[numSubjects].name,
                  &subjects[numSubjects].credits,
                  &subjects[numSubjects].semester) == 3)
    {
        if (numSubjects >= SUBJECTS)
        {
            printf("Error: Exceeded maximum number of subjects.\n");
            exit(1);
        }
        numSubjects++;
    }
    fclose(file);
}

void lGrades()
{
    FILE *file = fopen("grades.csv", "r");
    if (!file)
    {
        printf("Error: Cannot open grades.csv\n");
        exit(1);
    }
    for (int i = 0; i < numSubjects; i++)
    {
        for (int j = 0; j < GRADES; j++)
        {
            if (fscanf(file, "%f,", &gradeRanges[i].ranges[j]) != 1)
            {
                printf("Error: Invalid grade data in grades.csv\n");
                exit(1);
            }
        }
        fscanf(file, "\n");
    }
    fclose(file);
}

void lMarks()
{
    FILE *file = fopen("marks.csv", "r");
    if (!file)
    {
        printf("Error: Cannot open marks.csv\n");
        exit(1);
    }
    while (fscanf(file, "%c", &students[numStudents].mis) == 1)
    {
        for (int i = 0; i < numSubjects; i++)
        {
            if (fscanf(file, "%f,", &students[numStudents].marks[i]) != 1)
            {
                students[numStudents].marks[i] = -1;
            }
        }
        fscanf(file, "\n");
        if (numStudents >= STUDENTS)
        {
            printf("Error: Exceeded maximum number of students.\n");
            exit(1);
        }
        numStudents++;
    }
    fclose(file);
}

char *getGrade(float marks, int subjectIndex)
{
    if (subjectIndex < 0 || subjectIndex >= numSubjects)
        return "Invalid";
    float *ranges = gradeRanges[subjectIndex].ranges;
    if (marks <= ranges[0])
        return "FF";
    if (marks <= ranges[1])
        return "DD";
    if (marks <= ranges[2])
        return "CD";
    if (marks <= ranges[3])
        return "CC";
    if (marks <= ranges[4])
        return "BC";
    if (marks <= ranges[5])
        return "BB";
    if (marks <= ranges[6])
        return "AB";
    return "AA";
}

float calculateCGPA(char *mis)
{
    int found = 0;
    float totalPoints = 0;
    int totalCredits = 0;

    for (int i = 0; i < numStudents; i++)
    {
        if (strcmp(students[i].mis, mis) == 0)
        {
            found = 1;
            for (int j = 0; j < numSubjects; j++)
            {
                char *grade = getGrade(students[i].marks[j], j);
                int gradePoint = 0;

                if (strcmp(grade, "AA") == 0)
                    gradePoint = 10;
                else if (strcmp(grade, "AB") == 0)
                    gradePoint = 9;
                else if (strcmp(grade, "BB") == 0)
                    gradePoint = 8;
                else if (strcmp(grade, "BC") == 0)
                    gradePoint = 7;
                else if (strcmp(grade, "CC") == 0)
                    gradePoint = 6;
                else if (strcmp(grade, "CD") == 0)
                    gradePoint = 5;
                else if (strcmp(grade, "DD") == 0)
                    gradePoint = 4;
                else
                    gradePoint = 0;

                totalPoints += gradePoint * subjects[j].credits;
                totalCredits += subjects[j].credits;
            }
            break;
        }
    }

    if (!found)
    {
        printf("Error: Student with MIS %s not found\n", mis);
        return -1;
    }
    return totalCredits > 0 ? totalPoints / totalCredits : 0;
}

void handleQueries(void)
{
    char command[100], arg1[50], arg2[50];

    while (1)
    {
        printf("> ");
        scanf("%s", command);

        if (strcmp(command, "exit") == 0)
        {
            break;
        }
        else if (strcmp(command, "grade") == 0)
        {
            scanf("%s %s", arg1, arg2);
            int subjectIndex = -1;

            for (int i = 0; i < numSubjects; i++)
            {
                if (strcmp(subjects[i].name, arg2) == 0)
                {
                    subjectIndex = i;
                    break;
                }
            }

            if (subjectIndex == -1)
            {
                printf("Error: Subject %s not found\n", arg2);
                continue;
            }

            for (int i = 0; i < numStudents; i++)
            {
                if (strcmp(students[i].mis, arg1) == 0)
                {
                    printf("%s\n", getGrade(students[i].marks[subjectIndex], subjectIndex));
                    break;
                }
            }
        }
        else
        {
            printf("Error: Invalid command\n");
        }
    }
}

