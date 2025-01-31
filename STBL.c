// Assignment on Table operation
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>
#define _OPEN_SYS_ITOA_EXT
#define MAX_STUDENTS 1024
#define MAX_SUBJECTS 10
#define LINESIZE 1024
#define MAXLEN 100

// Using Enum for switch-case later on in the code
enum Command {
    DISPLAY_FILE,
    DISPLAY_MARKS,
    DISPLAY_HIGHEST_MARKS,
    AVERAGE_MARKS,
    FIND_SGPA,
    ADD_ENTRY,
    PRINT_COUNT_OF_GRADES,
    UPDATE_ENTRY,
    STANDARD_DEVIATION,
    PRINT_TOP_STUDENTS,
    EXIT,
    INVALID_COMMAND,
};

// function to get command from user input which will be used in switch-case
enum Command GetCommandFromName( char *command) {
    if (strcmp(command, "print") == 0) {
        return DISPLAY_FILE;
    } else if (strcmp(command, "marks") == 0) {
        return DISPLAY_MARKS;
    } else if (strcmp(command, "highest") == 0) {
        return DISPLAY_HIGHEST_MARKS;
    } else if (strcmp(command, "avg") == 0) {
        return AVERAGE_MARKS;
    } else if (strcmp(command, "sgpa") == 0) {
        return FIND_SGPA;
    } else if (strcmp(command, "add") == 0) {
        return ADD_ENTRY;
    } else if (strcmp(command, "count") == 0) {
        return PRINT_COUNT_OF_GRADES;
    } else if (strcmp(command, "update") == 0) {
        return UPDATE_ENTRY;
    } else if (strcmp(command, "stdev") == 0) {
        return STANDARD_DEVIATION;
    } else if (strcmp(command, "top") == 0) {
        return PRINT_TOP_STUDENTS;
    } else if (strcmp(command, "exit") == 0) {
        return EXIT;
    } else {
        return INVALID_COMMAND;
    }
}

// structure to store data
typedef struct Studentv{
    char name[128];
    long long MIS;
    int year_of_admission;
    char subjects[MAX_SUBJECTS][30];
    int semester_numbers[MAX_SUBJECTS];
    float marks[MAX_SUBJECTS];
    int credits[MAX_SUBJECTS];
    int grades[MAX_SUBJECTS];
    int total_semesters;
    float SGPA[MAX_SUBJECTS];
    float CGPA;
} Student;

// readline function used for reading the csv file
int readline(int fd, char line[], int max) {
    int i = 0;
    char ch;
    while (i < max && read(fd, &ch, 1) && ch != '\n')
    {
        line[i] = ch;
        i++;
    }
    line[i] = '\0';
    return i;
}

// readcsv function stores data into an array of structures
int readcsv(char *filename, Student student[], int size) {
    char line[LINESIZE];
    int fd;
    int count = 0;
    char *p;
    fd = open(filename, O_RDONLY);
    if (fd == -1) {
        perror("open failed:");
        return -1;
    }
    readline(fd, line, LINESIZE);
    while (count < size && readline(fd, line, LINESIZE)) {
        p = strtok(line, ",");
        student[count].MIS = atoll(p);

        p = strtok(NULL, ",");
        strcpy(student[count].name, p);

        p = strtok(NULL, ",");
        student[count].year_of_admission = atoi(p);

        for (int i = 0; i < MAX_SUBJECTS; i++) {
            p = strtok(NULL, ",");
            strcpy(student[count].subjects[i], p);

            p = strtok(NULL, ",");
            student[count].credits[i] = atoi(p);

            p = strtok(NULL, ",");
            student[count].marks[i] = atof(p);

            p = strtok(NULL, ",");
            student[count].grades[i] = atoi(p);

            p = strtok(NULL, ",");
            student[count].semester_numbers[i] = atoi(p);
        }
        count++;
    }
    close(fd);
    return count;
}

// function to display the CSV file which was read by readcsv function
void print_student(Student student[], int len) {
    int i;
    for (i = 0; i < len; i++) {
        printf("%llu,%s,%d,",
               student[i].MIS,
               student[i].name,
               student[i].year_of_admission);
        for (int j = 0; j < MAX_SUBJECTS; j++) {
            printf("%s,%d,%.2f,%d,%d,",
                   student[i].subjects[j],
                   student[i].credits[j],
                   student[i].marks[j],
                   student[i].grades[j],
                   student[i].semester_numbers[j]);
        }
        printf("\n\n");
    }
}

// function to find index of subject rfom its name which is used a lot in the program
int SubjectIndex(Student student[], char subject[]) {
    for (int j = 0; j < MAX_SUBJECTS; j++) {
        if (strcmp(subject, student[0].subjects[j]) == 0) {
            return j;
        }
    }
    return -1;
}

// Qa.2 function to display marks of a given student, specified by name, in a particular subject
void display_marks(Student student[], int limit, char subject[], char name[]) {
    int subjectIndex = SubjectIndex(student, subject);

    for (int i = 0; i < limit; i++) {
        if (strcmp(name, student[i].name) == 0) {
            printf("%.2f\n", student[i].marks[subjectIndex]);
            return;
        }
    }
    printf("Not found\n");
}

// Qa.3 function to show name(s) and MISID(s) of all students with the highest marks in a given subject
void findHighestMarks(Student student[], int numstudents, char subject[]) {
    float highestMarks = -1.0;
    int subjectIndex = SubjectIndex(student, subject);

    if (subjectIndex == -1) {
        printf("Subject Not Found\n");
        return;
    }

    for (int i = 0; i < numstudents; i++) {
        if (student[i].marks[subjectIndex] > highestMarks) {
            highestMarks = student[i].marks[subjectIndex];
        }
    }

    for (int j = 0; j < numstudents; j++) {
        if (student[j].marks[subjectIndex] == highestMarks) {
            printf("%s %llu\n", student[j].name, student[j].MIS);
        }
    }
}

// Qa.4 function to show average marks in a given subject
float calculateSubjectAverage(Student student[], int numStudents, char subject[]) {
    float totalMarks = 0.0;

    int subjectIndex = SubjectIndex(student, subject);

    if (subjectIndex == -1) {
        printf("Subject Not Found\n");
        return -1;
    }

    for (int i = 0; i < numStudents; i++) {
        totalMarks += student[i].marks[subjectIndex];
    }
    float averageMarks = (totalMarks / numStudents);

    printf("%lf\n", averageMarks);

    return averageMarks;
}
// function to find the SGPA of a student in a particular semester
void calculateSGPA(Student students[], int count, int sem, long long mis) {
    float grades_credits = 0;
    int credits = 0;

    for (int i = 0; i < count; i++) {
        if (students[i].MIS == mis) {
            for (int j = 0; j < MAX_SUBJECTS; j++) {
                if (students[i].semester_numbers[j] == sem) {
                    grades_credits += (students[i].grades[j]) * (students[i].credits[j]);
                    credits += students[i].credits[j];
                }
            }
        }
    }

    if (credits > 0) {
        float SGPA = (float)grades_credits / credits;
        printf("%.2f\n", SGPA);
    }
    else {
        printf("No data found");
    }
}

// I used this function for Qa.10 while listing top n students based on cgpa
float calculateCGPA(Student student) {
    float totalGradePoints = 0.0;
    int totalCredits = 0;

    for (int i = 0; i < MAX_SUBJECTS; i++) {
        totalGradePoints += (student.grades[i] * student.credits[i]);
        totalCredits += student.credits[i];
    }

    float SGPA = (totalGradePoints / totalCredits);
    return SGPA;
}

// Qa.7 function to Print the count of number of students with each grade in a given course
void printGradeCount(Student students[], int numStudents, char subject[]) {
    int gradeCount[11] = {0}; // Array to store the count of each grade

    int subjectIndex = SubjectIndex(students, subject);

    if (subjectIndex == -1) {
        printf("Subject Not Found\n");
        return;
    }

    for (int i = 0; i < numStudents; i++) {
        int grade = students[i].grades[subjectIndex];
        gradeCount[grade]++;
    }

    for (int i = 0; i <= 10; i++) {
        printf("%2d %d\n", i, gradeCount[i]);
    }
    printf("\n");
}

// I used this function to calculate mean required to find standard deviation in Qa.9
float calculateMean(Student student[], int numStudents, int subjectIndex) {
    float sum = 0.0;

    for (int i = 0; i < numStudents; i++) {
        sum += student[i].marks[subjectIndex];
    }

    return sum / numStudents;
}

// Qa.9 function to Find the standard deviation of the marks of students in a particular course
float calculateStandardDeviation(Student student[], int numStudents, char subject[]) {
    float sumSquaredDifferences = 0.0;
    int subjectIndex = SubjectIndex(student, subject);
    printf("\n");
    if (subjectIndex == -1) {
        printf("Subject Not Found\n");
        return -1.0;
    }

    float mean = calculateMean(student, numStudents, subjectIndex);

    for (int i = 0; i < numStudents; i++) {
        float difference = student[i].marks[subjectIndex] - mean;
        sumSquaredDifferences += difference * difference;
    }

    float meanSquaredDifferences = sumSquaredDifferences / numStudents;

    float stddev = sqrt(meanSquaredDifferences);

    printf("%.2f\n", stddev);
    return stddev;
}

// Qa.10 function to List the top n students in a class based on their CGPA, where n is specified
void listTopStudents(Student students[], int numStudents, int topN, int year) {

    for (int i = 0; i < numStudents - 1; i++) {
        for (int j = 0; j < numStudents - i - 1; j++) {
            if (calculateCGPA(students[j]) < calculateCGPA(students[j + 1])) {
                Student temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }
    int count = 0;
    for (int i = 0; (i < numStudents) && count < topN; i++) {
        if(students[i].year_of_admission == year){
          printf("%llu %-35s\n", students[i].MIS , students[i].name);
          count++;
        }
    }
}

// prints a menu for diplaying users various commands that can be given
void PrintMenu() {
    printf("***********************************************\n");
    printf("Enter any command: \n");
    printf("1. print : print the array of structures as CSV listing\n\n");
    printf("2. marks <name> <subject>: display the marks of student whose name is given in <name>\n\n");
    printf("3. highest <subject> : show name, MISID of all students with highest marks in the given subject\n\n");
    printf("4. avg <subject> : show average marks in a give subject\n\n");
    printf("5. sgpa <misid> <sem> : show sgpa of student given by <misid> in the semester\n\n");
    printf("6. add mis,name,year-of-admission,subject1,credit1,marks1,grade1,sem1,subject2,credit2,... : add entries where data is specified as a comma separated list\n\n");
    printf("7. count <subject>: Print the count of number of students with each grade in a given course\n\n");
    printf("8. update <misid> <field> <new-value>: update the entry of student with MISID in <misid>, for the column specified by <field> with new value given in <new-value>\n\n");
    printf("9. stdev <course>: find standard deviation of marks in a given subject \n\n");
    printf("10. top <n> <year-of-admission>: list top<n> students in class given by <year-of-admission> based on CGPA\n\n");
    printf("11. exit\n\n");
    printf("***********************************************\n");
}

void reverse(char str[],int len){
  int i = 0, j = len - 1;
  char temp;
  while(i < j){
    temp = str[i];
    str[i] = str[j];
    str[j] = temp;
    i++;
    j--;
  }
}


int int_to_string(int num, char str[], int digits){
  int len = 0;
  while(num > 0){
    str[len++] = (num%10) + '0';
    num = num / 10;
  }
  while(len < digits){
    str[len++] = '0';
  }
  reverse(str, len);
  str[len] = '\0';
  return len;
}


void Float_to_string(float n, char str[], int precision){
  int ipart = (int)n;
  float fpart = n - (float)ipart;
  int len = int_to_string(ipart, str, 0);
  
  if(precision != 0){
    fpart = fpart * pow(10, precision);
    str[len] = '.';
    int_to_string(floor(fpart), str+len+1, precision);
  }
}

void convert_MIS_to_string(unsigned long mis, char *str){
  char *p = str;
  while(mis > 0){
    *str = (mis%10) + '0';
    str++;
    mis = mis / 10;    
  } 
  reverse(p, 9);
  *str = '\0';
}

void writecsv(char *filename, Student students[], int MAX){
  int i, fd;
  char token[256];
  fd = open(filename, O_RDWR | O_TRUNC);
  write(fd, "mis,name,year-of-admission,subject1,credit1,marks1,grade1,sem1,subject2,credit2,marks2,grade2,sem2,subject3,credit3,marks3,grade3,sem3,subject4,credit4,marks4,grade4,sem4,subject5,credit5,marks5,grade5,sem5,subject6,credit6,marks6,grade6,sem6,subject7,credit7,marks7,grade7,sem7,subject8,credit8,marks8,grade8,sem8,subject9,credit9,marks9,grade9,sem9,subject10,credit10,marks10,grade10,sem10\n", 392);
  for(i = 0; i < MAX; i++){
    convert_MIS_to_string(students[i].MIS, token);
    write(fd, token, strlen(token));
    write(fd, ",", 1);
    
    strcpy(token, students[i].name);
    write(fd, token, strlen(token));
    write(fd, ",", 1);

    int_to_string(students[i].year_of_admission, token, 4);
    write(fd, token, strlen(token));
    write(fd, ",", 1);

    for(int j = 0; j < 10; j++){
      strcpy(token, students[i].subjects[j]);
      write(fd, token, strlen(token));
      write(fd, ",", 1);

      int_to_string(students[i].credits[j], token, sizeof(students[i].credits[j])/sizeof(int));
      write(fd, token, strlen(token));
      write(fd, ",", 1);  

      Float_to_string(students[i].marks[j], token, 2);
      write(fd, token, strlen(token));
      write(fd, ",", 1);
      
      int_to_string(students[i].grades[j], token, sizeof(students[i].grades[j])/sizeof(int));
      write(fd, token, strlen(token));
      write(fd, ",", 1);      
      
      int_to_string(students[i].semester_numbers[j], token, sizeof(students[i].semester_numbers[j])/sizeof(int));
      write(fd, token, strlen(token));
      write(fd, ",", 1);
    }
    write(fd, "\n", 1);
  }
  close(fd);
}

int main(int argc, char *argv[]) {
    Student student[MAX_STUDENTS];
    int count;
    count = readcsv(argv[1], student, MAX_STUDENTS);
    char choice[50];
    if (count == -1) {
        printf("ERROR: CSV File has no Data");
    }
    else {
        PrintMenu();
        while (1) {
            scanf(" %[^\n]", choice);
            printf("\n");

            char *p = choice;
            while(*p != ' ' && *p != '\n')
            p++;
            *p = '\0';
            char subject[50];
            char name[128];
            long long mis;
            enum Command command = GetCommandFromName(choice);

            
            switch (command) {

            case DISPLAY_FILE:
                print_student(student, count);
                break;
            case DISPLAY_MARKS:

                p++;
                while(*p != '\n' && *p != '\0'){
                    p++;
                }
                while(*p != ' '){
                    p--;
                }
                p++;

                strcpy(subject, p);

                p--;
                *p = '\0';
                p--;
                while(*p != '\0'){
                    p--;
                }
                p++;
                strcpy(name, p);


                display_marks(student, count, subject, name);
                break;
            case DISPLAY_HIGHEST_MARKS:
                p++;
                strcpy(subject, p);

                findHighestMarks(student, count, subject);
                break;
            case AVERAGE_MARKS:
                p++;
                strcpy(subject, p);

                calculateSubjectAverage(student, count,subject);
                break;
            case FIND_SGPA:
                p++;
                while(*p != '\n' && *p != '\0'){
                    p++;
                }
                while(*p != ' '){
                    p--;
                }
                p++;

                int sem;
                sem = atoi(p);

                p--;
                *p = '\0';
                p--;
                while(*p != '\0'){
                    p--;
                }
                p++;

                mis = atoll(p);

                calculateSGPA(student, count, sem, mis);
                break;
            case ADD_ENTRY:{
                int fd = open(argv[1], O_APPEND | O_WRONLY);
                if(fd == -1){
                    perror("open failed!\n");
                    close(fd);
                }
                char arg[LINESIZE];
                p++;
                strcpy(arg, p);
                char *p = arg;
                while(*p)
                    p++;
                *p = '\n';
                *(++p) = '\0';
                ssize_t wr = write(fd, arg, strlen(arg));
                if(wr == -1){
                    perror("error writing file");
                }
                close(fd);
                count = readcsv(argv[1], student, MAX_STUDENTS);
                break;
            }
            case PRINT_COUNT_OF_GRADES:
                p++;
                strcpy(subject, p);

                printGradeCount(student, count, subject);
                break;
            case UPDATE_ENTRY:
                p++;
                while(*p != '\n' && *p != '\0'){
                    p++;
                }
                while(*p != ' '){
                    p--;
                }
                p++;

                char newvalue[32];
                strcpy(newvalue, p);

                p--;
                *p = '\0';
                p--;
                while(*p != ' '){
                    p--;
                }
                p++;

                char field[32];
                strcpy(field, p);


                p--;
                *p = '\0';
                p--;
                while(*p != '\0'){
                    p--;
                }
                p++;

                mis = atoll(p);
                int index;
                for (int i = 0; i < count; i++) {
                    if (student[i].MIS == mis) {
                        index = i;
                    }
                }
                int field_index;
                char *s;
                s = field;
                while(*s != '\0')
                    s++;
                s--;
                field_index = atoi(s);
                *s = '\0';

                
                if(strcmp(field, "credit") == 0){
                    student[index].credits[field_index-1] = atoi(newvalue);
                } else if(strcmp(field, "marks") == 0){
                    student[index].marks[field_index-1] = atof(newvalue);
                } else if(strcmp(field, "grade") == 0){
                    student[index].grades[field_index-1] = atoi(newvalue);
                } else if(strcmp(field, "sem") == 0){
                    student[index].semester_numbers[field_index-1] = atoi(newvalue);
                }

                writecsv(argv[1],student,count);
                break;
            case STANDARD_DEVIATION:
                p++;
                strcpy(subject, p);

                calculateStandardDeviation(student, count, subject);
                break;
            case PRINT_TOP_STUDENTS:
                p++;
                while(*p != '\n' && *p != '\0'){
                    p++;
                }
                while(*p != ' '){
                    p--;
                }
                p++;

                int year;
                year = atoi(p);
                p--; 
                *p = '\0';
                p--;
                while(*p != '\0'){
                    p--;
                }
                p++;
                int n;
                n = atoi(p);

                listTopStudents(student, count, n, year);
                break;
            case EXIT:
                exit(0);
                break;
            case INVALID_COMMAND:
                printf("Invalid command. Please enter a valid command.\n");
                break;
            }
        }
    }
}