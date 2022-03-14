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
    int chars, ch, spaces, i;
    i = chars = spaces = 0;
    //  123456789123456789123456789
    //  asdask    nkl   asd 
    while(i < maxLength - 1 && (ch = getchar()) != EOF && ch != '\n') {
	while(ch == ' ') {
	    spaces++;
	    ch = getchar();
	}
	

	while(spaces > 0) {
	    if (spaces >= (TAB_STOP - (chars % TAB_STOP))) {
		line[i] = '\t';
		i++;
		spaces -= TAB_STOP - (chars % TAB_STOP);
		chars += TAB_STOP - (chars % TAB_STOP);
	    }
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
	    chars += TAB_STOP - (chars % TAB_STOP);
	else
	    chars++;
	     
    }
    if (ch == '\n') {
	line[i] = ch;
	i++;
    }
    line[i] = '\0';

    return i;
}
