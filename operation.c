#include"operation.h"
#include <ctype.h>
void encryption(char plaintext[], char keyword[]){
	int a, b;
	for(a=0;a<strlen(keyword);a++){ 
		for(b=0;b<strlen(plaintext);b++){
			if(a==b){
				int asciiPlain=(int) toupper(plaintext[a])-65; //Characters of plaintext is converted to ascii number. Because Ascii number of alphabet starts with 65, we subtract to 65.
				int asciiKey=(int) toupper(keyword[a])-65; //Characters of keyword is converted to ascii number. Because Ascii number of alphabet starts with 65, we subtract to 65.
				int asciiCipher=(asciiKey+asciiPlain)%26+65; //Number of Alphabet is 26 so total number is divided by 26 and it is converted to ascii number again.
				printf("%c",asciiCipher);
			}
		}
	}
	printf("\n");

}
void decryption(char ciphertext[], char keyword[]){
	int a,b;
	for(a=0;a<strlen(keyword);a++){
		for(b=0;b<strlen(ciphertext);b++){
			if(a==b){
				int asciiCipher=(int) ciphertext[a]-65; //Characters of ciphertext is converted to ascii number. Because Ascii number of alphabet starts with 65, we subtract to 65.
				int asciiKey=(int) keyword[a]-65; //Characters of keyword is converted to ascii number. Because Ascii number of alphabet starts with 65, we subtract to 65.
				if(asciiCipher < asciiKey){ //If ascii number of cipher is smaller thar ascii number of keyword, it is counted back from end of the alphabet so 26 is added to this number.  
					asciiCipher+=26;
				}
				int asciiPlain = (asciiCipher-asciiKey)%26+65; //Number of Alphabet is 26 so total number is divided by 26 and it is converted to ascii number again.			
				printf("%c",asciiPlain);
			}
		}
	}
	printf("\n");	
}

void append(char* s, char c) //this function appends character to string.
{
        int len = strlen(s);
        s[len] = c;
        s[len+1] = '\0';
}
