#include <stdio.h>
#include <math.h>
#include <time.h>



// Objectives:
//
// 1. Extract critical information from text (Function)
// 2. Draw diagram (Function)
// 3. Do (only necessary?) SUVAT calculations (Function)
// 4. Output results also on diagram (Function)
// 5. Correct S.F. rounding 
// 6. 
// 7. Use a fail safe mechanism when Murphy's law kicks in
// 8. Modify own code (learned behaviour algorithm) (Function?)



typedef struct
{
	
	float A;		// Angle
	
	float s;
	float u;
	float v;
	float a;
	float t;
	
} Asuvat;



// Navigation Functions //

int Welcome();
int Terminal();
// ******************** //



// Data Manipulating Functions //

int dataRead(char **data);
char* dataTranslate(char **data);
void compatibleASCII(char **data);

float* searchVal(char *data);
char* checkDecimal(char *data);
// *************************** //



// SUVAT Functions //

// Inclined_Plane();
// Vertical_Trajectory();
// Parabolic_Trajectory();
// Horizontal_Plane();
// Pulley();
// critFailure();
// *************** //



// Misc Functions //

void Timer(float duration);
void printSlow(char printme);
// ************** //



int main()
{
		char *data;
		
		
		// Welcome();		
		Terminal();
		
		
		
		// dataRead(&data);
		// compatibleASCII(&data);
		
		
		// dataTranslate(&data);
		
		
		// printf("%s", data);
		
		
		
		
		
		// printf("Press any key to terminate KINE");
		
		// getchar();
		
		
		
		// free(all arrays);			// Perhaps print log of data and even perhaps of errors?
		
		
		return 0;
	}




// COMPLETE //

int Welcome()
{
	int noob;
	char code[3];
	
	
	
	printf("\nWelcome to KINE, Kinematics Is Now Exterminated (inshAllah). Version 1.0 X.\n");
	printf("\nWhen you are ready, please enter the extermination code: ");
	
	scanf("%s", code);		// A code of length 4 characters is necessary to proceed
	
	if(strcmp(code, "KINE") == 0)
	{
		printf("\n\nOPEN SESAME!\n\n");
	}
	else		// This is the noob radar; it detects noob password guesses.
	{
		
		printf("\n\n >>> WARNING: Radar is picking up something... <<< \n\n");
		
		Timer(3);
		
		
		for(noob = 0; noob < 7; noob++)
		{
		
			Timer(1);
		
			printf("\nNOOB ALERT!\n");
		
		}
		
		printf("\n\nYou will now be booted from KINE in a friendly manner...");
		
		Timer(2);
		
		printf("\n\nGood-bye! =)\n\n");
		
		Timer(1);
		
		return 0;
	}
}





// INCOMPELTE //

int Terminal()		// This is the menu of KINE, not asthetically beautiful I must say myself :o
{
	char nightmare = 0;
	char decision = 'Y';
	
	printf("\n\n\n**************************************");
	printf("\n\t >> KINE TERMINAL <<");
	printf("\n**************************************\n");
	
	printf("\nThe type of SUVAT problem that has been causing frequent nightmares?");
	printf("\n\nA. Inclined planes\nB. Vertical trajectory\nC. Parabolic trajectory\nD. Horizontal planes\nE. Pulleys\n");
	printf("\nCategory: ");
	scanf("%c", &nightmare);
	

	printf("%c %d", nightmare, nightmare);
	
	
	// 65 = A
	// 66 = B
	// 67 = C
	// 68 = D
	// 69 = E
	
	
	
	while(nightmare != 65)		// Filter to catch out noob input
	{
		printf("\n\t>>>  It seems that you are suffering from the illness of... stupidity.  <<<");
		Timer(0.5);
		print("seems");
		Timer(0.5);
		printf("that");
		Timer(0.5);
		"printf";
		
		
		
		
		
		Timer(0.5);
		printf("\nPlease attempt to enter even a slightly intelligent category of nightmare.");
		printf("\nCAT: ");
		
		scanf("%c", &nightmare);
	}
	
	
	
	// printf("\n\nWould you like to manually enter your SUVAT variables? (Y or N)\n");
	
	// printf("\n%c", decision);
	// scanf("%c", &decision);
	// printf("\n%c", decision);
	
	// while( (decision != 'Y') || (decision != 'N') )
	// {
		// printf("\n\t>>>  Please enter a NON-noob decision.  <<<\t\n\nChoice: ");
		
		// scanf("%c", &decision);
		// printf("\nLOOP %c", decision);
		
		
	// }
	
	
	
	
	switch(nightmare)
	{
		case '1' :						// "option" is of type integer. While '1' is of type character. Therefore the mapping between them will be incorrect. CHECK TO LEARN.
			// Inclined_Plane();
			break;
			
		case '2' : 
			// Vertical_Trajectory();
			break;
			
		case '3' : 
			// Parabolic_Trajectory();
			break;
			
		case '4' : 
			// Horizontal_Plane();
			break;		
			
		case '5' : 
			// Pulley();
			break;
			
		case '6' : 
			// critFailure();
			break;	
	
	
	
		default : 
		// Noobing around
		;
	}
	
	
	return 0;		
}



// INCOMPLETE //

// Note: Yahoo Answers text format UTF-8. text file unicode but saved as ANSI so it loses it's format?


int dataRead(char **data)						// Double pointer so that the pointer from int main can be passed by reference/address rather than value. This is needed
{												// because "Realloc" (below) has the potential of changing the address that the pointer in int main is pointing to. If we 
												// passed by value i.e. the arguement of this function being a single pointer, we might lose the address of our data considering
												// how this function doesn't use a return of type char*
	FILE *fp;
	char *temp_data;							// Pointer to dynamic array
	char *data_start;							// Another pointer to the start of the same dynamic array
	char *temp;									// This avoids memory override when using "realloc" if new memory cannot be allocated to the dynamic array
	char suitable_key;
	int n = 1, init_size = 256;					// Variables used for dynamic array
	int i = 0; 
	
	
	
	printf("\nPlease create a clone (copy and paste) your data into a text file named: \"KINE_data\"\n");
	printf("\nWhen you are fully prepared, press a suitable key to proceed\n\n\n");
	
	suitable_key = getch();
	
	fp = fopen("KINE_data.txt", "r");
	
	if(fp == NULL)
	{
		printf("\nThe file cannot be opened right now, please try once more.\n(Some doors are perhaps never meant to be opened :o)\n");
		return 1;	
	}
	
	
	// printf("\n--- START OF FILE ---\n\n");
	
	
	temp_data = malloc(init_size*sizeof(char));
	
	if(temp_data == NULL)
	{
		printf("\nError allocating initial requested memory\n");
		return 0;
	}
	
	
	data_start = temp_data;			// The data pointer will be incremented in the while loop below. Therefore, I have "data_start" for the start address.
	
	
	while( fread(temp_data, sizeof(char), 1, fp) == 1 ) 
	{
			
		// printf("%c", *data);
	
		temp_data++;				// Stores the next read character from file into the next array index
		i++;		
		
		
		if(i == init_size)			// This statement checks whether the array has hit its last available memory spot
		{	
			n++;					// The amount the "init_size" increases by. (e.g. n = 4, means that the array will be increased by 4 times relative to its original size)
			i = 0;					// Resets the count
			
			
			temp = realloc(data_start, n*init_size*sizeof(char));
			
			if( temp == NULL )
			{
				printf("\nError allocating dynamic memory\n");
			}
			else
			{
				data_start = temp;
				temp_data = temp + init_size*(n - 1);			// The new chunk of free data is between address init_size*(n - 1) & initsize*n. Therefore, we start writing
			}													// data immediately to the first free spot which starts at the address data = temp + init_size*(n - 1). 
		}
	}

	temp_data++;		// RECHECK THIS
	*temp_data = '\0';			// fread doesn't terminate strings, therefore one has to manually do it.
	
	if( feof(fp) )
	{
		// printf("\n--- END OF FILE ---\n");
	}
	else
	{
		printf("\n--- A mysterious error has occured while reading the file ---\n");
	}
	
	
	*data = data_start;			// Assigning the address of the variable from int main to the local variable (CHECK LIFE SCOPE i.e. CHECK LOGIC)
	
	
	if( fclose(fp) )
	{
		printf("Stream has not been closed successfully");
	}
	else
	{
		return 0;
	}
}




// INCOMPLETE //

char* dataTranslate(char **data)						// Extracts useful information like SUVAT variables from the block of text from the question
{															
	
	
	
	Asuvat info;
	

	
	char *origin;
	int digit, dot;
	
	
	
	origin = *data;								// Storing starting location of array
	
		
	
	
	
	
	
	
	
	// storeValue 
	
	
	while(*data != '\0')
	{
	
		// Scan for digits
		// However, if an encounter with decimal place occurs
		// Include decimal place in number
		// Terminate number when it is attached to space or another character
		
		
		
		
		if( isdigit(*data) != 0  )
		{
		
			
		
		
		}
		
		
		else if(*data == '.')
		{
			dot = 1;
		}
		else
		{
			dot = 0;
		}
		
		
		
		if( (digit || dot) == 1 )			// True when there is a digit or dot (looking for decimal point)
		{
		
			
		
		}
		
			
			
		*data++;
	}	
		
		
		
		
		
		// Methods:
		
		// 1. Extract all numbers
		// 2. Use degree symbol to extract angle + words like "horizontal", "vertical" etc
		// 3. Use units + synonyms of variable names such as displacement/distance etc
		// 4.

		


		printf("\n\n\n%s", origin);



	// Extract critical data.
	
	
	
}



	
// INCOMPLETE //

char* checkDecimal(char *data)		// This function is incase a numerical value is written in the form, ".XXXXX", where the zero before the decimal point is not written.
{									// Without this function, the value to be stored in "searchVal" would be "XXXXX" rather than ".XXXXX" 

	data--;
	
	if(*data == '.')			
	{							
		
		data--;

		while(isdigit(*data))
		{
			data--;
		}
		
	}
	
	data++;
	
	return data;
}
	

// float* searchVal(*data)						// Searches for a numerical value (which includes decimal point values) in text
// {
	
	// int end_text = 0, value_found = 0, init_size = 20;
	// float *value;
	
	
	
	// value = malloc(init_size*sizeof(float));
	// memset(value, '\0', init_size*sizeof(float));
	
	
	
	// while(!end_text || !value_found)
	// {
		// if(isdigit(*data))
		// {
			
			// value_found = 1;
			
			
			
			// value = checkDecimal(*data);		// realloc
			
			
			
			// while(
			// {
			
			
			
			
				// value++
				
				
				
				
				
			// }
				
				
				
		// }
			
			
			// else if(*data == '\0')
			// {
				// end_text = 1;
			// }
			
		// }
		
	
		


	
		// data++;
	// }
// }
	
	
	

	
// INCOMPLETE //

void compatibleASCII(char **data)				// Replaces any non-ASCII character with a question mark in a block of text.
{

	char *modified_data;
	int print, cntrl;
	
		
	modified_data = *data;						// This assignment is that so pointer of pointer syntax errors can be avoided; I noob programmer.
	
	
	while(*modified_data != '\0')
	{
	
		print = isprint(*modified_data);
		cntrl = iscntrl(*modified_data);

		if( (print || cntrl) == 0 )			// Checks whether the read char in array is a "printable char" or a "control char". (i.e. checks whether char is ASCII or not) 
		{
			printf("\nNon ASCII:  ");
			printf("Char: %c || True Val: %d || Hex: %X", *modified_data, *modified_data, *modified_data);
			
			*modified_data = '?';			
		}
		
		modified_data++;		
	
	}
}





	
	
	


	

	
	
// This line:

// *name = "testing"; 
// is invalid, as you assign the pointer to "testing" into a char pointed by name. You need to copy the data into the buffer. It should be:

// int GetComputerName(char *name, char *ip_address){
    // strcpy(name,"testing");
    // return 0;
// }
// or even better (to avoid overflows):

// int GetComputerName(char *name, size_t buff_len, char *ip_address){
    // strncpy(name,"testing", buff_len);
    // name[buff_len - 1] = '\0';
    // return 0;
// }
// And call it:

// GetComputerName(comp_name, sizeof(comp_name), serverIP);








// }	
	
	
	
	// The format below is the answer format. It has been written in such a way that
	// it is easy to understand yet looks reasonably nice.
		
		
// F_normal···············?·········· 
// ··············?·······?·F_friction·· 
// ·················??·················· 
// ···············?? 55.0N············ 
// ···········?·························· 
// ·······?18.0°······················· 
// ·······????????········· 










// COMPLETE //

void Timer(float duration)
{
	float time_difference = 0;
	clock_t start, end;
	
		
	start = clock();
	
	while(time_difference < duration)
	{
	
		end = clock();
	
		time_difference = (float)(end - start) / CLOCKS_PER_SEC;
	
	}

}


// INCOMPLETE //

void printSlow(char printme)
{
	
	from all 
	
	
	DO THIS ON BOOTUP (I.E. NEXT TIME YOU PROGRAMME.)







}













// INCOMPLETE //

void critFailure()
{
	
	int kool;
	float s, u, v, a, t;
	
	for(kool = 0 ; kool < 3 ; kool++)		// Adding dramatic emphasis to code; makes life more dynamic
	{
		
		printf("\n\n >>> WARNING: CRITICAL FAILURE DETECTED! <<< \n\n");
		
		Timer(1);
	}
	
	printf("\n\nKINE IS NOW ENTERING MODE: N.I.E.K, NULLIFYING INCOMING EXTRATERRISTRIAL KREATURES\n\n");
	printf("\nPlease swiftly enter your corresponding \'SUVAT\' variables to solve:\n"); 	

	printf("\ns = ");
	scanf("%f", &s);

	printf("\nu = ");
	scanf("%f", &u);
	
	printf("\nv = ");
	scanf("%f", &v);
	
	printf("\ns = ");
	scanf("%f", &a);
	
	printf("\nt = ");
	scanf("%f", &t);
	
	
	printf("\n%.2f %.2f %.2f %.2f %.2f\n", s, u, v, a, t);
	
	
	
	// s = u*t + 0.5*a*t*t;
	// v^2 = u^2 + 2*a*s;
	// v = u + at
	// a = (v-u)/t
	
}














// Objectives:
//
// 1. Extract critical information from text (Function)		[Future bonus: the directory of the cloned data can be varied for so called user friendliness]
// 2. Draw diagram (Function)
// 3. Do (only necessary?) SUVAT calculations (Function)
// 4. Output results also on diagram (Function)
// 5. Correct S.F. rounding 
// 6. Use switchcase for multiple versions of SUVAT problems (e.g. horizontal surface, pulley, etc)
// 7. Use a fail safe mechanism when Murphy's law kicks in
// 8. Modify own code (learned behaviour algorithm) (Function?)



/*
In terms of modular programming, the general idea is as follows:

1. Navigation Functions (i.e. UI terminal)

2. Data manipulation functions

3. SUVAT functions (just mathematical calculations)

4. Misc functions
*/
