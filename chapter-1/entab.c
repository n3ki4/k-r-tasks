#include <stdio.h>

#define MAX_LENGTH 100
#define TAB_STOP 8

int getLine(char line[], int maxLength);

/*
  Exercise 1-21
  
  This program replaces strings of blanks by the minimum number of tabs
  and blanks to achieve the same spacing. We will use the same tab stops
  as for "detab" task.

*/

int main() 
{
    char line[MAX_LENGTH];
    int  len;

    while((len = getLine(line, MAX_LENGTH)) > 0) {
	for(int i = 1; i <= 9; i++)
	    printf("%1d", i);
        putchar('\n');
	printf("%s", line);	
    }
	
    return 0;
    

}

// reads line from user and replaces blanks with the
// minimum amount of tabs and blanks to achieve same spacing
int getLine(char line[], int maxLength) 
{
    int chars, ch, spaces, i;
    i = chars = spaces = 0;

    while(i < maxLength - 1 && (ch = getchar()) != EOF && ch != '\n') {
	chars++;
	if (ch == ' ') {
	    // i should check current char amount to check when next tab stop
	    // if I have enough spaces to fill it with tab - I do it
	    if (spaces == (TAB_STOP - (chars % TAB_STOP))) {
		line[i] = '\t';
		i++;
		spaces = 0;	    
	    }
	    else
		spaces++;

	    continue;
	}
	else if (spaces > 0) {
   	    if (spaces == (TAB_STOP - (chars % TAB_STOP))) {
		line[i] = '\t';
		i++;
	    }
	    else {
		for (int j = 0; j < spaces; j++) {
		    line[i] = ' ';
		    i++;
		}
		
	    }
	    spaces = 0;
	}
	line[i] = ch;
	i++;	    
    }
    if (ch == '\n') {
	line[i] = ch;
	i++;
    }
    line[i] = '\0';

    return i;
}
