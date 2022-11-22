#include <stdio.h>

// functions
void GPA(int* avg1, int* avg2); // GPA Calc semestral no unit
void GWA(int GPA1, int GPA2, int* WeightedAve); // GWA Calc with unit weight
int CAD(int GWA, int regStudent); // Cad Checker

// global variables
int CourseGrades1[12], CourseGrades2[11];
const size_t m = sizeof(CourseGrades1)/sizeof(int) - 1, n = sizeof(CourseGrades2)/sizeof(int) - 1; 
	
	
	
int main () {	
	const char CourseNames1[12][10] = // first semester grade 12 subjects
	{"CCF 03", "BIO 01", "BIO 01L", "EIP 01S", 
	 "ELEC 01", "ENGL 01", "LIT 01", "PE 03", 
	 "PHYS 01", "PHYS 01L", "REED 03", "RES 02S"};
	const char CourseNames2[11][10] = // second semester grade 12 subjects
	{"CCF 04", "BIO 02", "H", "L", "N", "AWDJJI"};
	
	char name[50];
	int i, regStudent, GPAve[2], GWAve;
	
	// input	
	printf("What is your full name? ");
	fgets(name, 50, stdin);
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
	GPA(&GPAve[0], &GPAve[1]);
	GWA(GPAve[0], GPAve[1], &GWAve);
	
	// output
	system("cls");
	printf("Student Name: %s\n", name);
	printf("First Semester GPA: %d\n", GPAve[0]);
	printf("Second Semester GPA: %d\n", GPAve[1]);
	printf("General Weighted Average (GWA): %d\n", GWAve);
	if(CAD(GWAve, regStudent) == 1) {
		printf("You are eligible for CAD");	
	}
	else {
		printf("You are not eligible for CAD");
	}
	
	return 0;
}

void GPA(int* avg1, int* avg2) { // Calculate GWA
	int i, sum1 = 0, sum2 = 0;
			
	// Average first semester
	for(i=0; i<=m; i++) {
		sum1 = sum1 + CourseGrades1[i];
	}
	*avg1 = sum1 / m;
	// Average second semester
	for(i=0; i<=n; i++) {
		sum2 = sum2 + CourseGrades2[i];
	}
	*avg2 = sum2 / n;

	return;
}

void GWA(int GPA1, int GPA2, int* WeightedAve) {
	int i, avg1, avg2, sum1 = 0, sum2 = 0, unitcount1 = 0, unitcount2 = 0;

	// first semester grade 12 subject unit score
	const int CourseUnits1[12] = {0, 1, 3, 3, 3, 3, 3, 1, 3, 1, 3, 3};
	// second semester grade 12 subject unit score
	const int CourseUnits2[11] = {0, 1, 3, 3, 3, 3, 1, 3, 1, 3, 3};


	// Average first semester w/out CCF
	for(i=0; i<=m; i++) {
		sum1 = sum1 + (CourseGrades1[i] * CourseUnits1[i]);
		unitcount1 = unitcount1 + CourseUnits1[i];
	}
	avg1 = sum1 / unitcount1;
	
	// Average second semester w/out CCF
	for(i=0; i<=n; i++) {
		sum2 = sum2 + (CourseGrades2[i] * CourseUnits2[i]);
		unitcount2 = unitcount2 + CourseUnits2[i];
	}
	avg2 = sum2 / unitcount2;
	
	*WeightedAve = (avg1 + avg2) / 2;
	
	return;
}

int CAD(int GWA, int regStudent) { // Check if passes CAD requirements
	int i;
	
	if(regStudent != 0 && GWA >= 90) {
		for(i=0;i<=m;i++) {
			if (CourseGrades1[i] < 85) {
				return 0;
			}
		}
		for(i=0;i<=n;i++) {
			if (CourseGrades2[i] < 85) {
				return 0;
			}
		}	
		return 1;	
	}
	return 0;
}
