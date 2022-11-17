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

int GWA() {
	int i, j, sum1, sum2, avg1, avg2, CourseGrades1[12], CourseGrades2[11];
	size_t m = sizeof(CourseGrades1)/sizeof(int);
	size_t n = sizeof(CourseGrades2)/sizeof(int);
	
	int CourseUnits1[12] = {3, 1, 0, 3, 3, 3, 3, 1, 3, 1, 3, 3};
	int CourseUnits2[11] = {3, 1, 0, 3, 3, 3, 1, 3, 1, 3, 3};
	
	char CourseNames1[12][10] = 
	{"BIO 01", "BIO 01L", "CCF 03", "EIP 01S", 
	 "ELEC 01", "ENGL 01", "LIT 01", "PE 03", 
	 "PHYS 01", "PHYS 01L", "REED 03", "RES 02S"};
	char CourseNames2[11][10] = 
	{"BIO 02", "BIO 02L", "CCF 04", "CONARTS 01", 
	 "ENTREP 01", ""};
 	 
	for(i=0;i<=(m-1);i++) {
		printf("Input Grade for %s: ", CourseNames1[i]);
		scanf("%d", &CourseGrades1[i]);
		
	}
	

	printf("balls\n");
	
	for(i=0;i<=(n-1);i++) {
		printf("Input Grade for %s: ", CourseNames2[i]);
		scanf("%d", &CourseGrades2[i]);
	}
	
	for(j=0; j<=m; j++) {
		sum1 = sum2 + CourseGrades2[i];
		avg1 = sum2/i;
	}
	for(j=0; j<= m; j++) {
		sum1 = sum1 + CourseGrades1[i];
		avg1 = sum1/i;
	}
	
}

int CAD(int GWA) {
	
}
