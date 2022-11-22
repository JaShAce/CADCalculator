#include <stdio.h>


int GPA(int CourseGrades1[], int CourseGrades2[]); // GPA Calc semestral no unit
int GWA(int CourseGrades1[], int CourseGrades2[]); // GWA Calc with unit weight
int CAD(); // Cad Checker

int main () {
	char name[50];
	char CourseNames1[12][10] = // first semester grade 12 subjects
	{"CCF 03", "BIO 01", "BIO 01L", "EIP 01S", "ELEC 01", "ENGL 01", "LIT 01", "PE 03", "PHYS 01", "PHYS 01L", "REED 03", "RES 02S"};
	char CourseNames2[11][10] = // second semester grade 12 subjects
	{"CCF 04", "BIO 02", "H", "L", "N", "AWDJJI"};
	int i, regStudent, GradeAverage, CourseGrades1[12], CourseGrades2[11];
	size_t m = (sizeof(CourseGrades1)/sizeof(int)) - 1;
	size_t n = (sizeof(CourseGrades2)/sizeof(int)) - 1;	
	
	for(i=0;i<=m;i++) {
		printf("%s\n", CourseNames1[i]);
	}
	for(i=0;i<=n;i++) {
		printf("%s\n", CourseNames2[i]);
	}
		
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
	
	GPA(CourseGrades1, CourseGrades2);
	GWA(CourseGrades1, CourseGrades2);
	
	return 0;
}

int GPA(int CourseGrades1[], int CourseGrades2[]) { // Calculate GWA
	int i, avg1, avg2;	
	int sum1 = 0;
	int sum2 = 0;
	
		
	// Average first semester
	for(i=0; i<=11; i++) {
		sum1 = sum1 + CourseGrades1[i];
	}
	avg1 = sum1 / 12;
	// Average second semester
	for(i=0; i<=10; i++) {
		sum2 = sum2 + CourseGrades2[i];
	}
	avg2 = sum2 / 11;


	printf("%d\n", sum1);
	printf("%d\n", avg1);	
	printf("%d\n", sum2);
	printf("%d\n", avg2);
}

int GWA(int CourseGrades1[], int CourseGrades2[]) {
	int i, avg1, avg2, unitcount1, unitcount2;	
	int sum1 = 0, sum2 = 0, unitcount1 = 0, 
	// first semester grade 12 subject unit score
	int CourseUnits1[12] = {0, 1, 3, 3, 3, 3, 3, 1, 3, 1, 3, 3};
	// second semester grade 12 subject unit score
	int CourseUnits2[11] = {0, 1, 3, 3, 3, 3, 1, 3, 1, 3, 3};

	// Average first semester
	for(i=0; i<=11; i++) {
		sum1 = sum1 + (CourseGrades1[i] * CourseUnits1[i]);
	}
	avg1 = sum1 / 12;
	// Average second semester
	for(i=0; i<=10; i++) {
		sum2 = sum2 + (CourseGrades2[i] * CourseUnits2[i]);
		unitcount2 = unitcount2 + ;
	}
	avg2 = sum2 / ;

	printf("%d\n", sum1);
	printf("%d\n", avg1);	
	printf("%d\n", sum2);
	printf("%d\n", avg2);
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
