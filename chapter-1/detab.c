#include <stdio.h>
#define MAX_LENGTH 100
#define TAB_STOP 4

int getLine(char line[], int maxLength);
int detab(char line[], int maxLength);

/*
 * How to replace each tab? 
    - After reading the line 
       I should shift some chars to enter 4 chars instead \t :)
    - in the getLine function
       My function is not clear(because it does 2 things at the same time)
    - 
 * 
 * 
*/

int main()
{
    int len;
    char line[MAX_LENGTH];
    
    while((len = getLine(line, MAX_LENGTH)) > 0) {
      printf("%s", line);
    }		       	

    return 0;
}
	
int getLine(char line[], int maxLength)
{
    int i, ch, spaces;
    i = spaces = 0;
    
    while(i < maxLength - 1 && (ch = getchar()) != EOF && ch != '\n') {
	if(ch == '\t'){
	    spaces = TAB_STOP - (i % TAB_STOP);
	    for (int j = 0; j < spaces; j++) {
		line[i] = ' ';
		i++;
	    }
	}
	else {
	    line[i] = ch;
	    i++;
	}
    }
    if (ch == '\n'){
	line[i] = ch;
	i++;
    }
    line[i] = '\0';

    return i;
}
