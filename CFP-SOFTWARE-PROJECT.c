#include <stdio.h>
#include <windows.h>



// Declaring Functions
void GPA(float* avg1, float* avg2); // GPA Calc semestral no unit
void GWA(float GPA1, float GPA2, float* WeightedAve); // GWA Calc with unit weight
int CAD(float GWA, int regStudent); // CAD Checker

// Declaring Global Variables
float CourseGrades1[12], CourseGrades2[11];
const size_t m = sizeof(CourseGrades1)/sizeof(int) - 1, n = sizeof(CourseGrades2)/sizeof(int) - 1; 
	
	
/* 
===============================================================
FILE: GRADE 12 CAD AWARDEE CHECKER BASED ON GENERAL WEIGHTED AVERAGE SOFTWARE.c
AUTHORS: Derama, Jeskha Samantha; Acebes, Jared Sheohn; Bitero, John Christion; Llanto, Miguel Anthony
GRADE LEVEL & BLOCK: STEM 12-T2
DESCRIPTION: This function asks the user’s name, if they’re a regular grade 12 student, input grades, calls the other functions, and display outputs.
COPYRIGHT: November 28, 2022
===============================================================
*/ 	
	
int main () {	
	// color
	HANDLE hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	
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
	SetConsoleTextAttribute(hConsole, 15);
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	printf("Welcome! \n\nThis software will calculate your GWA, and determine your eligibility for a CAD Award.\n"); //Tells the user what the software does
	printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	printf("\n--\n\nTo use this software, press any key to continue:"); // Asks the user if they want to proceed
	getch();
	printf("\n\n...Press any key to confirm choice:"); // Asks the user to confirm their choice
	getch();
	system("cls"); // Clears screen
	
	
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	printf("Section 1\n"); // Indicates what section the user is in
	printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	printf("--\n");

	// Reads the name of the user	
	printf("\nEnter full name: ");
	SetConsoleTextAttribute(hConsole, 11);
	fgets(name, 50, stdin);
	
	
	// Asks if the user is a regular student or not, as one of the requirements for the CAD Award
	SetConsoleTextAttribute(hConsole, 15);
	printf("\n--\n\nAre you a regular student? \nType \"0\" if no and any integer if yes (e.g. \"1\"): ");
	SetConsoleTextAttribute(hConsole, 11);	
	while(scanf("%d", &regStudent)!=1) { 	// Scans input and validates if an integer
		SetConsoleTextAttribute(hConsole, 15);
	    printf("\nInvalid input, please enter an integer: ");
	    scanf("%s");
	    SetConsoleTextAttribute(hConsole, 11);
    } 
    // Identify if the user is a regular student
    SetConsoleTextAttribute(hConsole, 15);
	if (regStudent != 0){ 
    	printf("\nYou are a regular student.\n");
	}
	else {
		printf("\nYou are an irregular student.\n");
	}
	
	printf("\n--\n\n...Press Any Key to Continue:"); // Asks the user if they want to proceed
	getch();
	system("cls"); // Clears screen
	
	SetConsoleTextAttribute(hConsole, 15);
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	printf("Section 2\n"); // Indicates what section the user is in
	printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	printf("--\n");

	// Gives instructions to user
	printf("\nEnter first semester grades\n\n--\n\n");
	
	// Input First Semester Grades
	for(i=0;i<=m;i++) { 
		SetConsoleTextAttribute(hConsole, 15);
		printf("Input Grade for %s: ", CourseNames1[i]);
		SetConsoleTextAttribute(hConsole, 11);
		while(scanf("%f", &CourseGrades1[i])!=1 || CourseGrades1[i] <65 || CourseGrades1[i] >100){ // Validates input
			fflush(stdin);
			SetConsoleTextAttribute(hConsole, 15);
			printf("Invalid input, please input a valid grade (between 65 and 100): ");
			SetConsoleTextAttribute(hConsole, 11);
		}
	}
	
	system("cls"); // Clears screen
	
	SetConsoleTextAttribute(hConsole, 15);
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	printf("Section 3\n"); // Indicates what section the user is in
	printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	printf("--\n");
	
	// Gives instructions to user
	printf("\nEnter second semester grades\n\n--\n\n");

	// Input Second Semester Grades
	for(i=0;i<=n;i++) { 
		SetConsoleTextAttribute(hConsole, 15);
		printf("Input Grade for %s: ", CourseNames2[i]);
		SetConsoleTextAttribute(hConsole, 11);
		while(scanf("%f", &CourseGrades2[i])!=1 || CourseGrades2[i] <65 || CourseGrades2[i] >100){ // Validates input
			fflush(stdin);
			SetConsoleTextAttribute(hConsole, 15);
			printf("Invalid input, please input a valid grade (between 65 and 100): ");
			SetConsoleTextAttribute(hConsole, 11);
		}
	}
	
	// Calls functions
	GPA(&GPAve[0], &GPAve[1]);
	GWA(GPAve[0], GPAve[1], &GWAve);
	
	SetConsoleTextAttribute(hConsole, 15);
	system("cls"); 	// Clears the screen

	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	printf("Results Section\n"); // Indicates what section the user is in
	printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n--\n");
	// Displays Outputs
	printf("\nHere are the results, "); // Displays the student's name
	SetConsoleTextAttribute(hConsole, 11);
	printf("%s", name);
	SetConsoleTextAttribute(hConsole, 15);
	printf("\n--\n\n");
	printf("First Semester GPA: "); // Displays the calculated first semester GPA
	SetConsoleTextAttribute(hConsole, 11);
	printf("%.2f\n", GPAve[0]);
	SetConsoleTextAttribute(hConsole, 15);
	printf("Second Semester GPA: "); // Displays the calculated second semester GPA
	SetConsoleTextAttribute(hConsole, 11);
	printf("%.2f\n", GPAve[1]);
	SetConsoleTextAttribute(hConsole, 15);
	printf("General Weighted Average (GWA): "); // Displays the calculated GWA
	SetConsoleTextAttribute(hConsole, 11);
	printf("%.2f\n", GWAve);
	
	int GW = (int)GWAve;
	SetConsoleTextAttribute(hConsole, 15);
	// Displays eligibilty for a CAD Award
	if(CAD(GWAve, regStudent) == 1) { 	
		printf("\nYou are eligible for a CAD Award ");	
		if(GW >= 98) {
			SetConsoleTextAttribute(hConsole, 14);
			printf("with highest honors");
		}
		else if (GW >= 95) {
			SetConsoleTextAttribute(hConsole, 10);
			printf("with high honors");
		}
		else if (GW >= 90){
			SetConsoleTextAttribute(hConsole, 13);
			printf("with honors");
		}
		else {
		 printf("invalid");
		}
		SetConsoleTextAttribute(hConsole, 15);
		printf(". Congratulations!");
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
	// Variable Declarations
	int i, unitcount1 = 0, unitcount2 = 0;
	float avg1, avg2, sum1 = 0, sum2 = 0;
	// First semester grade 12 subject unit score
	const int CourseUnits1[12] = {0, 1, 3, 3, 3, 3, 3, 1, 3, 1, 3, 3};
	// Second semester grade 12 subject unit score
	const int CourseUnits2[11] = {0, 1, 3, 3, 3, 3, 1, 3, 1, 3, 3};


	// Weighted Average for first semester
	for(i=0; i<=m; i++) {
		sum1 = sum1 + (CourseGrades1[i] * CourseUnits1[i]);
		unitcount1 = unitcount1 + CourseUnits1[i];
	}
	avg1 = sum1 / unitcount1;
	
	// Weighted Average for second semester
	for(i=0; i<=n; i++) {
		sum2 = sum2 + (CourseGrades2[i] * CourseUnits2[i]);
		unitcount2 = unitcount2 + CourseUnits2[i];
	}
	avg2 = sum2 / unitcount2;
	
	// General Weighted Average of the two semesters
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
int CAD(float GWA, int regStudent) { 
	// Variable declaration
	int i;
	
	// Checks if the user is a regular student and examines if the GWA is within 90-100 
	if(regStudent != 0 && GWA >= 90 && GWA <= 100) {
		// Checks if the user has a grade in the first semester outside the grade range for the CAD award 
		for(i=0;i<=m;i++) {
			if (CourseGrades1[i] < 85 || CourseGrades1[i] > 100 ) {
				return 0;
			}
		}
		// Checks if the user has a grade in the second semester outside the grade range for the CAD award 
		for(i=0;i<=n;i++) {
			if (CourseGrades2[i] < 85|| CourseGrades1[i] > 100 ) {
				return 0;
			}
		}	
		// Returns 1 if the CAD requirements are met, thus user is eligible for a CAD award
		return 1;	
	}
	// Returns 0 if the CAD requirements are not met, thus user is ineligible for a CAD award
	return 0;
}
