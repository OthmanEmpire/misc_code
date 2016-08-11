#include <stdio.h>
#include <string.h>
#define IP 16		// +1 due to buffer
#define PORT 6		// +1 due to buffer



/* Code is designed to list the port numbers obtained from the output 
of a netstat command in the form (so to be able to graph vs time):


12:  TCP    0.0.0.0:11100          0.0.0.0:0              LISTENING
60:  TCP    127.0.0.1:11100        127.0.0.1:51808        ESTABLISHED
66:  TCP    127.0.0.1:51808        127.0.0.1:11100        ESTABLISHED
04:31 PM

Hence roughly: netstat -a -n -p TCP | find /N "127.0.0.1 11100" >>%USERPROFILE%/RoR.txt


INEFFICIENCIES:

1. Pointer of pointer used to enable passing by reference rather than value.
This is not needed as one can just pass by reference via the "&" operator.

2. Retarded variable names such as "start_data", "data", etc which even more
so are used in a retarded paradoxical manner. Please learn to imagine.

3. Perhaps include a stand-alone function that dynamically allocates array
memory as this task is repeated several times and is an eyesore.

4. The rate of increase of the buffer should be non-linear.
E.g. Following an exponential growth by a factor of 2 rather than +8 per increment.

*/

void dataStore(char **data, char **start_data, FILE *fp);
void dataDecipher(char ip_address[], char port_number[], char *data);
// void dataArrange(              FILE *fp);


int main()
{

	FILE *fp;
	int m = 0;
	char ip_address[IP], port_number[PORT];
	char *start_data, *data;
	
	
	memset(ip_address, '\0', IP);
	memset(port_number, '\0', PORT);
	
	
	printf("\nEnsure that your text file being read is named \"RoR.txt\" "); 
	printf("\nand placed in the same directory");
	printf("\n\nEnter the network socket that telnet is using to connect ");
	printf("to the RoR server:");
	
	printf("\n\nIP Address: ");
	scanf("%s", ip_address);
	
	printf("\nPort Number: ");
	scanf("%s", port_number);
	
	
	
	dataStore(&data, &start_data, fp);
	dataDecipher(ip_address, port_number, &start_data);
	
	free(start_data);
	printf("\n\n<< Code was successfully executed, al7umdulillah >>\n\n");
	
	return 0;
}



void dataStore(char **data, char **start_data, FILE *fp)
{
	int i = 0, n = 1;
	int init_size = 8;
	char suitable_key;

	
	fp = fopen("RoR.txt", "r");
	
	if(fp == NULL)
	{
		printf("\nERROR: File cannot be opened");
		return;
	}
	
	
	*data = calloc(init_size, sizeof(char));
	if(*data == NULL)
	{
		printf("\nERROR: Memory could not be allocated");
		return;
	}
	
	*start_data = *data;

	
	while(feof(fp) == 0)
	{
		
		fread(*data, sizeof(char), 1, fp);
			
		(*data)++;
		i++;
		
		if(i == init_size)
		{
			i = 0;
			
			n++;
			*data = realloc(*start_data, n*init_size*sizeof(char));
			
			if(*data == NULL)
			{
				printf("\nERROR: Memory reallocation was unsuccessful");
				free(*start_data);
				exit(1);
			}
			
			*start_data = *data;
			*data = *data + (n - 1)*init_size;		// Prevents overwriting previous *data
			
			
		}
		
	}
	
	(*data)--;
	**data = '\0';	// fread does not include null terminator 
	
	
	if(fclose(fp) != 0)
	{
		printf("ERROR: File pointer did not successfully disjoint from stream");
		printf("Press any key to continue");
		
		suitable_key = getch();
		
		return;
	}
}



void dataDecipher(char ip_address[], char port_number[], char *data)
{
	FILE *log;
	int m = 0, n = 1, i = 0, init_size = 8;
	char *unsorted_array;
	char suitable_key;
	char *match = (char*)1;		// Unneccessary initialization; learning purposes
	
	
	unsorted_array = calloc(init_size, sizeof(char));
	
	do
	{	
		match = strstr(data, ip_address);
		
		while(match != NULL)
		{
		
			match++;		// Skips past matched phrase to just before port no.
			
			if(*match == ':')
			{
				while(*match != ' ')
				{
					match++;
					*unsorted_array = *match;
					unsorted_array++;
					
					i++;
					
					if(i == init_size - 1)		// "-1" so that the buffer is not overloaded due to '\n' at the end
					{
						i = 0;
						
						n++;
						unsorted_array = realloc(unsorted_array, n*init_size*sizeof(char));
					
						if(unsorted_array == NULL)
						{
							printf("\nERROR: Memory reallocation was unsuccessful");
							free(unsorted_array);
							exit(1);
						}
						
						unsorted_array = unsorted_array + (n - 1)*init_size;		// Prevents overwriting previous data
					}
				}
				
				*unsorted_array = '\n';
				
				data = match;		// To proceed to find another search for a matching phrase via "strstr" 				
									// while ignoring any match previously found
				break;
			}
		}
	} while(match != NULL);
	


	

	
	// while(feof(log) != 0)
	// {
		
		// if(*match == *port_number)
		// {
			
			// port_number++;		

			// n++;		// Necessary so that the host port number
						// // e.g. "11100" is not printed via printf 
						
			// if(n == 5)
			// {
				// match == match - n;
			
				// for(n ; n => 0 ; n--)
				// {
					// printf("%c", *match);
					// fwrite(match, sizeof(char), 1 , log);
					
					// match++;
					
					
				// }
			// }
		// }
						// m++;	// for printf
		
						// fprintf(log, "\n"); 		// separates port numbers 
	
	// }
	
	
	
	
	
	
	
	
	
	// log = fopen("RoR_Log.txt", "w");
	// if(log == NULL)
	// {
		// printf("Log file could not be generated");
		// return;
	// }	
	

	
	
	
		
	// fprintf(log, "\n\n-- Total matches: %i --", m);
	// printf("\n\n     -- A total of %i matches were found --", m);
	// printf("\n(Visit the log generated for the enumerated list)");
	
	
	
	
	
	
	
	
	
	
	
	
	
	// if(fclose(log) != 0)
	// {
		// printf("\nStream associated with log file did not close successfully");
		// suitable_key = getch();
		
		// return;
	// }
}





array dynamicChecker(void array[], int size, int slot)	// A convenient function that deals
{														// with dynamic arrays & issues
	int overflow;
	
	
	overflow = slot%size;
	
	if(overflow == 0)
	{
		
		n++;
		
		2^n = y
		
		array = realloc(array, n*n*init_size*sizeof(*array));			// CHANGE TO EXPONENTIAL GROWTH
		
		if(array == NULL)
		{
			printf("\nERROR: Memory reallocation was unsuccessful");
			free(array);
			exit(1);
		}
		
		
		*array= *data;
		*data = *data + (n - 1)*init_size;		// Prevents overwriting previous *data
				
			
	}
}














// Include Time