/*
This is the start of where I will create my own String.h library with all of it's component.
I will make sure not to look at anything but details as to what function does what. 
In this header file, I will have the name of the functions as well as the descriptions as to what 
each function does as comment above. I will have a separate .c file that has all the code that runs the funciton as it is described. This will act as my practice of becomming a better coder.

CODER: IN JAE CHO
*/
#include <stddef.h>

// Searches for the first occurence of the character c (an unsigned char) in the first n bytes of the string pointed to, by the argument str.
void *MyMemChr(const void *str, int c, size_t n);

// Compares the first n bytes of str1 and str2
int myMemCmp(const void *str1, const void *str2, size_t n); //this talks about how memcmp is different than strcmp become they compare the binary values? hmmm... will need to understand what they really mean.

// Copies n characters from src to dest.
void *myMemCpy(void *dest, const void *src, size_t n);

// Another function to copy n characters from str2 to str1
void *myMemMove(void *dest, const void *src, size_t n);

// Copies the character c (an unsigned char) to the first n characters to the string pointed to, by the argument str.
void *myMemSet(void *str, int c, size_t n);

// Appends the string spointed to, by src to the end of the string pointed to by dest.
char *myStrCat(char *dest, const char *src);

// Searches for the first occurrence of the character c (an unsigned char) in the string pointed to, by the argument str.
char *myStrChr(const char *str, int c);

// Compares the string pointed to, by str1 to the string pointed to by str2.
int myStrCmp(const char *str1, const char *str2);

// Compares at most the first n bytes of str1 and str2.
int myStrnCmp(const char *str1, const char *str2, size_t n);

// Compares string str1 and str2. The result is dependent on the LC_COLLATE setting of the location.
int myStrColl(const char *str1, const char *str2);   // This is similar to strcmp but become of collation, I have no idea how to approach the comparison difference.

// Copies the string pointed to, by src to dest.
char *myStrCpy(char *dest, const char *src);

// Copies up to n characters from the string pointed to, by src to dest. 
char *myStrnCpy(char *dest, const char *src, size_t n);

// Calculates the length of the initial segment of str1 which consists entirely of characters not in str2.
size_t myStrcSpn(const char *str1, const char *str2);

// Searches an internal array for the error number errnum and returns a pointer to an error message string.
char *myStrError(int errnum);

// Computes the length of the string str up to but not including the terminating null character. 
size_t myStrLen(const char *str);

// Find the first character in the string str1 that matches any character specified in str2.
char *myStrpBrk(const char *str1, const char *str2);

// Searches for the last occurence of the character c (an unsigned char) in the string pointer to by the argument str.
char *myStrrChr(const char *str, int c);

// Calculates the length of the initial segment of str1 which consists entirely of characters in str2.
size_t myStrSpn(const char *str1, const char *str2);

// Finds the first occurrence of the entire string 'needle' (not including the terminating null character) which appears in the string 'haystack'.
char *myStrStr(const char *haystack, const char *needle);

// Breaks string str into a series of tokens separated by delim.The examples on the man page shows that every time you call strtok after the first time you pass in a null instead of an actual char *str. This means I need to somehow keep it stored somewhere....
char *myStrTok(char *str, const char *delim);

// Transforms the first n characters of the string src into current locale and places them into the string dest.
size_t myStrxFrm(char *dest, const char *src, size_t n);
//I will have to understand how to utilize LC_COLLATE before I can actually work on converting the src into dest through the locale.h file.






















