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
	printf("%s", line);	
    }
	
    return 0;
    

}

// reads line from user and replaces blanks with the
// minimum amount of tabs and blanks to achieve same spacing
int getLine(char line[], int maxLength) 
{
    int chars;	// total chars read from user input
    int ch;	// char that we read
    int spaces; // total spaces that we read
    int i;	// line array index
    
    i = chars = spaces = 0;

    while(i < maxLength - 1 && (ch = getchar()) != EOF && ch != '\n') {
	// read all spaces 
	while(ch == ' ') {
	    spaces++;
	    ch = getchar();
	}
	
     
	while(spaces > 0) {
	    // we place tab, if we have enough spaces
	    if (spaces >= (TAB_STOP - (chars % TAB_STOP))) {
		line[i] = '\t';
		i++;
		spaces -= TAB_STOP - (chars % TAB_STOP);
		chars += TAB_STOP - (chars % TAB_STOP);
	    }
	    // or we just place spaces instead of tab
	    else {
		for (int j = 0; j < spaces; j++) {
		    line[i] = ' ';
		    i++;
		   		    
		}
		chars += spaces;
		spaces = 0;
	    }
	}
	line[i] = ch;
	i++;
	if (ch == '\t')
	    // add amount of spaces of this tab to chars
	    chars += TAB_STOP - (chars % TAB_STOP);
	else
	    chars++;
	     
    }
    // because cycle ends on '\n' we add it afterwards
    if (ch == '\n') {
	line[i] = ch;
	i++;
    }
    line[i] = '\0';

    return i;
}
