#include <stdio.h>

// functions
void GPA(float* avg1, float* avg2); // GPA Calc semestral no unit
void GWA(float GPA1, float GPA2, float* WeightedAve); // GWA Calc with unit weight
int CAD(float GWA, int regStudent); // CAD Checker

// global variables
float CourseGrades1[12], CourseGrades2[11];
const size_t m = sizeof(CourseGrades1)/sizeof(int) - 1, n = sizeof(CourseGrades2)/sizeof(int) - 1; 
	
	
/* 
===============================================================
FILE: GRADE 12 CAD AWARDEE CHECKER BASED ON GENERAL WEIGHTED AVERAGE SOFTWARE.c
AUTHORS: Derama, Jeskha Samantha; Acebes, Jared Sheohn; Bitero, John Christion; Lllanto, Miguel Anthony;
GRADE LEVEL & BLOCK: STEM 12-T2
DESCRIPTION: This function asks the user’s name, if they’re a regular grade 12 student, input grades, calls the other functions, and display outputs.
COPYRIGHT: November 28, 2022
===============================================================
*/ 	
	
int main () {	
	const char CourseNames1[12][10] = 	// Declares first semester grade 12 subjects
	{"CCF 03", "BIO 01", "BIO 01L", "EIP 01S", 
	 "ELEC 01", "ENGL 01", "LIT 01", "PE 03", 
	 "PHYS 01", "PHYS 01L", "REED 03", "RES 02S"};
	const char CourseNames2[11][11] = 	// Declares second semester grade 12 subjects
	{"CCF 04", "BIO 02", "BIO 02L", "CONARTS 01", "ENTREP 01", "MIL 01", "PE 04", "PHYS 02", 
	 "PHYS 02L", "REED 04", "RES 03S"};
	
	// Variable Declarations
	char name[50];
	int i, regStudent;
	float GPAve[2], GWAve;
	
	// Title Page
	
	// Reads the name of the user	
	printf("What is your full name? ");
	fgets(name, 50, stdin);
	
	
	// Asks if the user is a regular student or not, as one of the requirements for the CAD Award
	printf("\nAre you a regular student? Type \"0\" if no and any integer if yes (e.g. \"1\"): ");	
	while(scanf("%d", &regStudent)!=1) { 	// Scans input and validates if an integer
	    printf("\nInvalid input, please enter an integer: ");
	    scanf("%s");
    } 
    // Identify if the user is a regular student
	if (regStudent != 0){ 
    	printf("\n\nYou are a regular student.\n");
	}
	else {
		printf("\n\nYou are an irregular student.\n");
	}
	
	printf("\n...Press Any Key to Continue:");
	getch();
	system("cls");
	
	printf("=================================================================\n");
	
	// Declares program limitations
	printf("\nImportant Note: If the input is invalid (e.g. not an integer), \nthe program will automatically declare you ineligible for CAD Award.\n\n");
	
	printf("=================================================================\n");
	
	// Gives instructions to user
	printf("\nEnter first semester grades\n\n");
	
	// Input First Semester Grades
	for(i=0;i<=m;i++) { 
		printf("Input Grade for %s: ", CourseNames1[i]);
		scanf("%f", &CourseGrades1[i]);
	}
	
	printf("\n\n");
	
	// Gives instructions to user
	printf("Enter second semester grades\n\n");

	// Input Second Semester Grades
	for(i=0;i<=n;i++) { 
		printf("Input Grade for %s: ", CourseNames2[i]);
		scanf("%f", &CourseGrades2[i]);
	}
	
	// Calls functions
	GPA(&GPAve[0], &GPAve[1]);
	GWA(GPAve[0], GPAve[1], &GWAve);
	
	// Displys Outputs
	system("cls"); 	// Clears the screen
	printf("Student Name: %s\n", name); 	// Displays the student's name
	printf("First Semester GPA: %.2f\n", GPAve[0]); 	// Displays the calculated first semester GPA
	printf("Second Semester GPA: %.2f\n", GPAve[1]); 	// Displays the calculated second semester GPA
	printf("General Weighted Average (GWA): %.2f\n", GWAve); 	// Displays the calculated GWA
	// Displays eligibilty for CAD award
	if(CAD(GWAve, regStudent) == 1) { 	
		printf("\nYou are eligible for a CAD Award. Congratulations!");	
	}
	else {
		printf("\nYou are not eligible for a CAD Award.");
	}
	
	return 0;
}


/*
================================================================
FUNCTION: GPA Function
DESCRIPTION: This function calculates the first and second semester GPA.
ARGUMENTS: This function includes the global variables avg1, and avg2.
RETURNS: This returns the value of the first and second semester GPA.
================================================================
*/

void GPA(float* avg1, float* avg2) { 
	// Variable Declaratons
	int i;
	float sum1 = 0, sum2 = 0;
			
	// Average first semester
	for(i=0; i<=m; i++) {
		sum1 = sum1 + CourseGrades1[i];
	}
	*avg1 = sum1 / 12;
	
	// Average second semester
	for(i=0; i<=n; i++) {
		sum2 = sum2 + CourseGrades2[i];
	}
	*avg2 = sum2 / 11;

	return;
}


/*
===============================================================
FUNCTION: GWA Function
DESCRIPTION: This function calculates the GWA using the GPA calculated from the GPA Function
ARGUMENTS: This function uses the variables GPA1 (first semester) and GPA2 (second semester)
RETURNS: This returns the GWA (General Weighted Average)
===============================================================
*/

void GWA(float GPA1, float GPA2, float* WeightedAve) {
	int i, unitcount1 = 0, unitcount2 = 0;
	float avg1, avg2, sum1 = 0, sum2 = 0;
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


/*
===============================================================
FUNCTION: CAD Function
DESCRIPTION: This function determines if the user is qualified for being a CAD Awardee using the criterion and qualifications set by the university.
ARGUMENTS: This function includes the variables GWA and regStudent. 
RETURNS: This function returns 1 or 0, which means if it returns 1, the student will be eligible for a CAD award. However, if it returns 0 then the user is ineligble for the CAD award.
===============================================================
*/

int CAD(float GWA, int regStudent) { // Check if passes CAD requirements
	int i;
	
	if(regStudent != 0 && GWA >= 90 && GWA <= 100) {
		for(i=0;i<=m;i++) {
			if (CourseGrades1[i] < 85 || CourseGrades1[i] > 100 ) {
				return 0;
			}
		}
		for(i=0;i<=n;i++) {
			if (CourseGrades2[i] < 85|| CourseGrades1[i] > 100 ) {
				return 0;
			}
		}	
		return 1;	
	}
	return 0;
}
