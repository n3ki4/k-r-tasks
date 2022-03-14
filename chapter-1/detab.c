#include <stdio.h>

#define MAX_LENGTH 100
#define TAB_STOP 4

int getLine(char line[], int maxLength);
/*
 *                         Exercise 1-20 
 *   Program that replaces tabs in the input with the proper
     number of blanks to space to the next tab stop. There is
     a fixed set of tab stops, every N columns(TAB_STOP in program)
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
	    spaces = TAB_STOP - (i % TAB_STOP);nn
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
