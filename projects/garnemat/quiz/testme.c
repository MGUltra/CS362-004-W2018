#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

char inputChar()
{
		
    int randomNumber = rand() % 9;
		
		char randomChar;
		
		char charArray[9] = "[({ ax})]";
		
		randomChar = charArray[randomNumber];
		
    return randomChar;
}

char *inputString()
{
		int x;
    
		char randomChar2;
		
		char *randomString = malloc(6 * sizeof(char));
		
		char charArray2[6] = "reset";
		
		for(x=0; x < 6; x ++)
		{
			int randomNumber2 = rand() % 6;
			
			randomChar2 = charArray2[randomNumber2];
		
			randomString[x] = randomChar2;
		
		}
		
    return randomString;
}

void testme()
{
  int tcCount = 0;
  char *s;
  char c;
  int state = 0;
	

	
  while (1)
  {
    tcCount++;
    c = inputChar();
    s = inputString();
    printf("Iteration %d: c = %c, s = %s, state = %d\n", tcCount, c, s, state);

    if (c == '[' && state == 0) state = 1;
    if (c == '(' && state == 1) state = 2;
    if (c == '{' && state == 2) state = 3;
    if (c == ' ' && state == 3) state = 4;
    if (c == 'a' && state == 4) state = 5;
    if (c == 'x' && state == 5) state = 6;
    if (c == '}' && state == 6) state = 7;
    if (c == ')' && state == 7) state = 8;
    if (c == ']' && state == 8) state = 9;
    if (s[0] == 'r' && s[1] == 'e'
       && s[2] == 's' && s[3] == 'e'
       && s[4] == 't' && s[5] == '\0'
       && state == 9)
    {
      printf("error ");
      exit(200);
    }
  }
}


int main(int argc, char *argv[])
{
    srand(time(NULL));
    testme();
    return 0;
}
