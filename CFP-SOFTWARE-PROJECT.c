#include <stdio.h>


int GradeInput(int Grade); // Grade Input
int GWA(int CourseGrades1[12], int CourseGrades2[11]); // GWA Calc
int CAD(); // Cad Checker

int main () {
	char name[50];
	char CourseNames1[12][10] = // first semester grade 12 subjects
	{"CCF 03", "BIO 01", "BIO 01L", "EIP 01S", 
	 "ELEC 01", "ENGL 01", "LIT 01", "PE 03", 
	 "PHYS 01", "PHYS 01L", "REED 03", "RES 02S"};	
	char CourseNames2[11][10] = // second semester grade 12 subjects
	{"CCF 04", "BIO 02", "BIO 02L", "CONARTS 01", "ENTREP 01", ""}; // add more subjects refer to gc for list
	int i, regStudent, GradeAverage, CourseGrades1[12], CourseGrades2[11];
	size_t m = sizeof(CourseGrades1)/sizeof(int);
	size_t n = sizeof(CourseGrades2)/sizeof(int);	
	
	
	printf("What is your full name? ");
	scanf("%s", &name);
	printf("Are you a regular student? Type \"1\" if yes and \"0\" if no: ");
	scanf("%d", &regStudent);
	
	
	for(i=0;i<=m;i++) { // Input Grades First Semester
		printf("Input Grade for %s: ", CourseNames1[i]);
		scanf("%d", &CourseGrades1[i]);
	}
	for(i=0;i<=n;i++) { // Input Grades Second Semester
		printf("Input Grade for %s: ", CourseNames2[i]);
		scanf("%d", &CourseGrades2[i]);
	}
	
	GWA(CourseGrades1, CourseGrades2);
	
	return 0;
}

int GWA(int CourseGrades1[12], int CourseGrades2[11]) { // Calculate GWA
	int i, sum1, sum2, avg1, avg2;
	size_t m = sizeof(CourseGrades1)/sizeof(int);
	size_t n = sizeof(CourseGrades2)/sizeof(int);	
	
	// first semester grade 12 subject unit score
	int CourseUnits1[12] = {0, 1, 3, 3, 3, 3, 3, 1, 3, 1, 3, 3};
	// second semester grade 12 subject unit score
	int CourseUnits2[11] = {0, 1, 3, 3, 3, 3, 1, 3, 1, 3, 3};
	 	 
	printf("test\n");
	
	// Average first semester
	for(i=0; i<=m; i++) {
		sum1 = sum1 + CourseGrades1[i];
		avg1 = sum1/i;
	}
	printf("%d", sum1);
	printf("%d", avg1);
	
	// Average second semester
	for(i=0; i<=n; i++) {
		sum2 = sum2 + CourseGrades2[i];
		avg2 = sum2/i;
	}
	printf("%d", sum2);
	printf("%d", avg2);
	
	// GWA/GPA(i forgor which one) - both semesters together average
	
	
}

int CAD(int GWA) { // Check if passes CAD requirements
	// check flowchart for program flow
	int regStudent;
	
	if(regStudent == 1) {
		if(GWA >= 85) {
			printf("You are eligible for CAD");		
		}
		else {
			printf("You are not eligible for CAD");
		}
	}
	else {
		printf("You are not eligible for CAD");
	}
	
	return 0;
}

