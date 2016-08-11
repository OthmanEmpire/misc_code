#include <stdio.h>


int main()
{
	int encrypted, decrypted;
	int TRUE = 1;
	
	printf("\nPlease enter Le input: ");
	scanf("%d", &encrypted);
	
	while(TRUE == 1)
	{
		if( 100 < encrypted && encrypted < 999 )
		{
			
			decrypted = encrypted + 1;
		
			printf("\nHere is Le deciphered: %d\n", decrypted);
		
			return 0;
		}
		else
		{
			
			printf("\n --- Noob, please insert 3 digit number --- \n");
			
			scanf("%d", &encrypted);
		
		}
	}
}