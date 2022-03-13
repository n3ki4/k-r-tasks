#include <stdio.h>

#define MAX_LENGTH 100;
#define TAB_STOP 4

int getLine(char line[], int maxLength);

int main() 
{
    char line[MAX_LENGTH];
    int len;
    while((len = getLine(line, MAX_LENGTH)) > 0) {
	printf("%s", line);
	
    }
    
    return 0;
    

}

int getLine(char line[], int maxLength) 
{
    
}
