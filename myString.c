/*
This is the start of where I will create my own String.h library with all of it's component.
I will make sure not to look at anything but details as to what function does what.
In this header file, I will have the name of the functions as well as the descriptions as to what
each function does as comment above. I will have a separate .c file that has all the code that runs the funciton as it is described. This will act as my practice of becomming a better coder.

CODER: IN JAE CHO
*/
//This is only for the size_t function 
#include <stddef.h>

//This apparently is needed for malloc
#include <stdlib.h>

//This is to perhaps fix the implicite declaration of strlen and strcpy
#include "myString.h"

//defining null apparently null isn't the original... you have to do nullptr
#define null 0

// Searches for the first occurence of the character c (an unsigned char) in the first n bytes of the string pointed to, by the argument str.
void *myMemChr(const void *str, int c, size_t n){
        char *new_str = (char*)str;

        for(int i = 0; i < n; i++){
                if(new_str[i] == (char)c){
                        //void * first_occurence = str + sizeof(char)*i;
			//return first_occurence;
			return new_str + sizeof(char)*i;
                }
        }
        return null;
}


// Compares the first n bytes of str1 and str2
int myMemCmp(const void *str1, const void *str2, size_t n){
        char *new_str1 = (char*)str1;
        char *new_str2 = (char*)str2;

        for(size_t i = 0; i < n; i++){
                if(new_str1[i] < new_str2[i]){
                        return -1;
                }
                if(new_str1[i] > new_str2[i]){
                        return 1;
                }
        }
        return 0; 
          
         
          
} //this talks about how memcmp is different than strcmp become they compare the binary values? hmmm... will need to understand what they really mean.

             
// Copies n characters from src to dest.
void *myMemCpy(void *dest, const void *src, size_t n){
        char *new_src = (char*)src;
        char *new_dest = (char*)dest; 
         
        //no error??? and also destructive... difference between memcpy and memmove..?
        for(size_t i = 0; i < n; i++){
                new_dest[i] = new_src[i];
        }
        return dest;

}


// Another function to copy n characters from str2 to str1
void *myMemMove(void *dest, const void *src, size_t n){
        char *new_src = (char*)src;
        char *new_dest = (char *)dest;
        //char *temp = malloc(sizeof(char)*(n+1));
	void *tempor = malloc(sizeof(char)*(n+1));
	char *temp = tempor;

        for(size_t i = 0; i < n; i++){
                if(new_src[i] == '\0'){
                        return null;
                }
                temp[i] = new_src[i];

        }
        temp[n] = '\0';

        for(size_t i = 0; i < n; i++){
                if(new_dest[i] == '\0'){
                        return null;
                }
                new_dest[i] = temp[i];
        }
        free(temp);
	return new_dest;	

}


// Copies the character c (an unsigned char) to the first n characters to the string pointed to, by the argument str.
void *myMemSet(void *str, int c, size_t n){
        char *new = (char*)str;
        for(size_t i = 0; i < n; i++){
                new[i] = (char)c;
        }
        return str;
}


// Appends the string spointed to, by src to the end of the string pointed to by dest.
char *myStrCat(char *dest, const char *src){
        char *new = dest;
        size_t length_dest = myStrLen(dest);
        size_t length_src = myStrLen(src);
        dest = realloc(dest, sizeof(char)*(length_dest+length_src+1));

        for(size_t i= length_dest; i <= length_dest+length_src; i++){
                dest[i] = src[i-length_dest];
        }
        dest[length_dest+length_src+1] = '\0';
        return dest;
}

// Searches for the first occurrence of the character c (an unsigned char) in the string pointed to, by the argument str.
char *myStrChr(const char *str, int c){
        //char *origin = str;
        char *origin = malloc(myStrLen(str) + 1);
	myStrCpy(origin, str);
	
	size_t length = myStrLen(str);
        size_t index = 0;
        for(size_t i = 0; i < length; i++){
                if(origin[i] == c){
                        index = c;
                        break;
                }
        }
        if(index == 0){
                return null;
        }
        return origin + sizeof(char)*index;
	
}


// Compares the string pointed to, by str1 to the string pointed to by str2.
int myStrCmp(const char *str1, const char *str2){
        size_t length_one = myStrLen(str1);
        size_t length_two = myStrLen(str2);

        for(size_t i = 0; i < length_one; i++){
                if(str1[i] == str2[i]){
                        continue;
                }else if(str1[i] < str2[i]){
                        return -1;
                }else{
                        return 1;
                }
        }
        if(length_one < length_two){
                return -1;
        }
        if(length_one > length_two){
                return 1;
        }
        return 0;

}


// Compares at most the first n bytes of str1 and str2.
int myStrnCmp(const char *str1, const char *str2, size_t n){
        //size_t length_one = strlen(str1);
        //size_t length_two = strlen(str2);

        for(size_t i = 0; i < n; i++){
                if(str1[i] == str2[i]){
                        continue;
                }else if(str1[i] < str2[i]){
                        return -1;
                }else{
                        return 1;
                }

        }
        return 0;
}


// Compares string str1 and str2. The result is dependent on the LC_COLLATE setting of the location.
int myStrColl(const char *str1, const char *str2);   // This is similar to strcmp but become of collation, I have no idea how to approach the comparison difference.


// Copies the string pointed to, by src to dest.
char *myStrCpy(char *dest, const char *src){
        size_t length_src = myStrLen(src);
        size_t length_dest = myStrLen(dest);

        //checking to see if dest is large enough for src.
        if(length_src > length_dest){
                //return error;
		return null;
        }

        //place dest into src
        for(int i = 0; i < length_src-1; i++){
                dest[i] = src[i];
        }
        dest[length_src] = '\0';

        return dest;
}


// Copies up to n characters from the string pointed to, by src to dest.
char *myStrnCpy(char *dest, const char *src, size_t n){
        size_t length_one = myStrLen(src);
        size_t length_two = myStrLen(dest);
        size_t null_termin = 0;
        if(n == 0){
                for(int i = 0; i < length_two; i++){
                        dest[i] = '\0';
                }
                return dest;
        }

        for(size_t i = 0; i < n; i++){
                dest[i] = src[i];
        }
        for(size_t i = n; n < length_two; i++){
                dest[i] = '\0';
        }

        return dest;
}


// Calculates the length of the initial segment of str1 which consists entirely of characters not in str2.
size_t myStrcSpn(const char *str1, const char *str2){
        size_t length_one = myStrLen(str1);
        size_t length_two = myStrLen(str2);

        for( size_t i = 0; i < length_one; i++){
                for( size_t j = 0; j < length_two; j++){
                        if(str1[i] == str2[j]){
                                return i+1;
                        }
                }
        }
        return length_one;
}


// Searches an internal array for the error number errnum and returns a pointer to an error message string.
char *myStrError(int errnum);


// Computes the length of the string str up to but not including the terminating null character.
size_t myStrLen(const char *str){
        size_t length = 0;
        //int i = 0;

        while(str[length] != '\0'){
        //        i++;
                length++;
        }

        return length;
}

// Find the first character in the string str1 that matches any character specified in str2.
char *myStrpBrk(const char *str1, const char *str2){
        size_t length_one = myStrLen(str1);
        size_t length_two = myStrLen(str2);

        for (size_t i = 0; i < length_one; i++){
                for(size_t j = 0; j < length_two; j++){
                        if(str1[i] == str2[j]){
                                //return &str1 + sizeof(str1)*i; //maybe not??
				char *return_temp = malloc(length_one + 1);
				myStrCpy(return_temp, str1);
				return return_temp + sizeof(str1)*i;
                        }
                }
        }
}


// Searches for the last occurence of the character c (an unsigned char) in the string pointer to by the argument str.
char *myStrrChr(const char *str, int c){
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

                void *new_temp = malloc(sizeof(char) * (index - last_occurence + 1));
		new = new_temp;
	
        }
}


// Calculates the length of the initial segment of str1 which consists entirely of characters in str2.
size_t myStrSpn(const char *str1, const char *str2){
        size_t length_one = myStrLen(str1);
        size_t length_two = myStrLen(str2);
        size_t count = 0;
        size_t match = 0;
        for(size_t i = 0; i < length_one; i++){
                match = 0;
                for(size_t j = 0; j < length_two; j++){
                        if(str1[i] == str2[j]){
                                match = 1;
                        }
                }
                if(match == 0){
                        break;
                }
                count++;
        }

        return count;

}


// Finds the first occurrence of the entire string 'needle' (not including the terminating null character) which appears in the string 'haystack'.
char *myStrStr(const char *haystack, const char *needle){
        //char *big = haystack;
        //char *small = needle;
	char *big = malloc(myStrLen(haystack)+1);
	char *small = malloc(myStrLen(needle)+1);

	if(myStrLen(needle) == 0){
                //return haystack;
		return big;
	}

        size_t length_big = myStrLen(big);
        size_t length_small = myStrLen(small);
        size_t match;

        for(size_t i = 0; i < length_big; i++){
                match = 0;
                for(size_t j = 0; j < length_small; j++){
                        if(big[i+j] != small[j]){
                                match = 1;
                        }
                }
                if(match == 0){
                        //return haystack + sizeof(char)*i;
			char *position = malloc(myStrLen(haystack)+1);
			myStrCpy(position,haystack);
			return position + sizeof(char*)*i;
                }

        }
        return null;
}


// Breaks string str into a series of tokens separated by delim.The examples on the man page shows that every time you call strtok after the first time you pass in a null instead of an actual char *str. This means I need to somehow keep it stored somewhere....

//variable stored outside of the function
char* current = NULL;

char *myStrTok(char *str, const char *delim){
        if(str != NULL){
                current = str;
        }

        size_t delim_length = myStrLen(delim);
        size_t current_length = myStrLen(current);
        if(current_length == 0){
                return null;
        }
        size_t match = 0;
        size_t index = 0;
        //find the end point
        for(size_t i = 0; i < current_length; i++){
                for(size_t j = 0; j < delim_length; j++){
                        if(current[i] == delim[j]){
                                match = 1;
                        }
                }
                if(match == 1){
                        index = i;
                }
        }

        //if there is no match
        if(match == 0){
                return null;
        }

        //copy the words before into store
        //char *store = malloc(sizeof(char)*index+1);
	
	void *store_temp = malloc(sizeof(char)*index+1);
	char *store = store_temp;

        for(size_t i = 0; i < index; i++){
                store[i] = current[i];
        }
        current = current + sizeof(char)*(index+1);
        return store;

}

// Transforms the first n characters of the string src into current locale and places them into the string dest.
size_t myStrxFrm(char *dest, const char *src, size_t n){
	return 0;
}
//I will have to understand how to utilize LC_COLLATE before I can actually work on converting the src into dest through the locale.h file.

int main(){
	return 0;
}
