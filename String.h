/*
This is the start of where I will create my own String.h library with all of it's component.
I will make sure not to look at anything but details as to what function does what. 
In this header file, I will have the name of the functions as well as the descriptions as to what 
each function does as comment above. I will have a separate .c file that has all the code that runs the funciton as it is described. This will act as my practice of becomming a better coder.

CODER: IN JAE CHO
*/


// Searches for the first occurence of the character c (an unsigned char) in the first n bytes of the string pointed to, by the argument str.
void *memchr(const void *str, int c, size_t n);


// Compares the first n bytes of str1 and str2
int memcmp(const void *str1, const void *str2, size_t n);


// Copies n characters from src to dest.
void *memcpy(void *dest, const void *src, size_t n);


// Another function to copy n characters from str2 to str1
void *memmove(void *dest, const void *src, size_t n);


// Copies the character c (an unsigned char) to the first n characters to the string pointed to, by the argument str.
void *memset(void *str, int c, size_t n);


// Appends the string spointed to, by src to the end of the string pointed to by dest.
char *strcat(char *dest, const char *src);


// Searches for the first occurrence of the character c (an unsigned char) in the string pointed to, by the argument str.
char *strchr(const char *str, int c);


// Compares the string pointed to, by str1 to the string pointed to by str2.
int strcmp(const char *str1, const char *str2);


// Compares at most the first n bytes of str1 and str2.
int strncmp(const char *str1, const char *str2, size_t n);


// Compares string str1 and str2. The result is dependent on the LC_COLLATE setting of the location.
int strcoll(const char *str1, const char *str2);


// Copies the string pointed to, by src to dest.
char *strcpy(char *dest, const char *src){
	size_t length_src = strlen(src);
	size_t length_dest = strlen(dest);
	
	//checking to see if dest is large enough for src.
	if(length_src > length_dest){
		return error;
	}	
	
	//place dest into src
	for(int i = 0; i < length_src-1; i++){
		dest[i] = src[i];
	}
	dest[length_src] = '\0';

	return dest;
}


// Copies up to n characters from the string pointed to, by src to dest. 
char *strncpy(char *dest, const char *src, size_t n){
	
	return dest;
}


// Calculates the length of the initial segment of str1 which consists entirely of characters not in str2.
size_t strcspn(const char *str1, const char *str2);


// Searches an internal array for the error number errnum and returns a pointer to an error message string.
char *strerror(int errnum);


// Computes the length of the string str up to but not including the terminating null character. 
size_t strlen(const char *str){
	size_t length = 0;
	int i = 0;
	
	while(str[i] != '\0'){
		i++;
		length++;	
	}
	//fence post problem
	length++;

	return length;
}

// Find the first character in the string str1 that matches any character specified in str2.
char *strpbrk(const char *str1, const char *str2);


// Searches for the last occurence of the character c (an unsigned char) in the string pointer to by the argument str.
char *strrchr(const char *str, int c){
	int index = 0;
	int last_occurence = -1;

	while(str[index] != 0){
		
		if(str[last_occurence] == c){
			last_occurence = index;		
		}
		index++;
		
	}

	//malloc a char* place
	char *new;
	if(last_occurence != -1){
	
		new = malloc(sizeof(char) * (index - last_occurence + 1));

	} 
}


// Calculates the length of the initial segment of str1 which consists entirely of characters in str2.
size_t strspn(const char *str1, const char *str2);


// Finds the first occurrence of the entire string 'needle' (not including the terminating null character) which appears in the string 'haystack'.
char *strstr(const char *haystack, const char *needle);


// Breaks string str into a series of tokens separated by delim.
char *strtok(char *str, const char *delim);


// Transforms the first n characters of the string src into current locale and places them into the string dest.
size_t strxfrm(char *dest, const char *src, size_t n);























