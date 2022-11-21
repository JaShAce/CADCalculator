#include <stdio.h>

int GWA();
int CAD(int GWA);

int main () {
	char name[50];
	int regStudent, GradeAverage;
	
	printf("What is your full name? ");
	scanf("%s", &name);
	printf("Are you a regular student? Type \"1\" if yes and \"0\" if no: ");
	scanf("%d", &regStudent);

	GWA();
	
	return 0;
}

int GWA() { // Calculate GWA
	int i, j, sum1, sum2, avg1, avg2, CourseGrades1[12], CourseGrades2[11];
	size_t m = sizeof(CourseGrades1)/sizeof(int);
	size_t n = sizeof(CourseGrades2)/sizeof(int);
	// some variables redundant need to check
	
	// first semester grade 12 subject unit rating
	int CourseUnits1[12] = {3, 1, 0, 3, 3, 3, 3, 1, 3, 1, 3, 3};
	
	// second semester grade 12 subjects
	int CourseUnits2[11] = {3, 1, 0, 3, 3, 3, 1, 3, 1, 3, 3};
	
	// first semester grade 12 subjects
	char CourseNames1[12][10] = 
	{"BIO 01", "BIO 01L", "CCF 03", "EIP 01S", 
	 "ELEC 01", "ENGL 01", "LIT 01", "PE 03", 
	 "PHYS 01", "PHYS 01L", "REED 03", "RES 02S"};
	
	// second semester grade 12 subjects
	char CourseNames2[11][10] = 
	{"BIO 02", "BIO 02L", "CCF 04", "CONARTS 01", 
	 "ENTREP 01", ""}; // add more subjects refer to gc for list
	
 	 
	// grade input loop first semester
	for(i=0;i<=(m-1);i++) {
		printf("Input Grade for %s: ", CourseNames1[i]);
		scanf("%d", &CourseGrades1[i]);
		
	}
	

	printf("test\n"); /* test */
	
	// grade input loop second semester
	for(i=0;i<=(n-1);i++) {
		printf("Input Grade for %s: ", CourseNames2[i]);
		scanf("%d", &CourseGrades2[i]);
	}
	
	// Average first semester
	for(j=0; j<= m; j++) {
		sum1 = sum1 + CourseGrades1[i];
		avg1 = sum1/i;
	}
	
	// Average second semester
	for(j=0; j<=n; j++) {
		sum2 = sum2 + CourseGrades2[i];
		avg2 = sum2/i;
	}
	
	// GWA/GPA(i forgor which one) - both semesters together average
	
	
}

int CAD(int GWA) { // Check if passes CAD requirements
	// check flowchart for program flow
}
