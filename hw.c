#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include"operation.c"

int main() {
	char text1[100];
	char key[100];
	char selection;
	printf("Enter 1 for encryption\nEnter 2 for decryption\n");
	scanf("%c",&selection);
	if(selection =='1'){  //If user enters 1, program runs for encryption operation and the user enters plaintext and keyword
		printf("Enter plaintext: ");
		scanf("%s", text1);
		printf("Enter keyword that will not have longer than plaintext: ");
		scanf("%s", key);
	}
	else if(selection =='2'){   //If user enters 2, program runs for decryption operation and the user enters ciphertext and keyword
		printf("Enter ciphertext: ");
		scanf("%s", text1);
		printf("Enter keyword that will not have longer than ciphertext: ");
		scanf("%s", key);
	}
	
	int p=0; // p represents length of string for text1.
	while (text1[p] != '\0') {       // Loop stops when we reach the null-character. 
	    p++;
	} 
	int k=0; //k represent length of string for keywor
	while (key[k] != '\0') {       // Loop stops when we reach the null-character.
	    k++;
	}
	int mod=p%k; // mod represents length of character for last repetation. 
										 
	int rep=p/k; //rep represents number of repetation
	char keyword[100]; //keyword represents new keyword that will be created. 
	//For example if text1 is ATTACKATDAWN and keyword is LEMON, mod is 2 and rep is 2. Because length of text1 is 12 and length of keyword is 5. These length must be equal so new keyword should be LEMONLEMONLE. First of all, keyword appends to new keyword length of rep times.Then keyword characters are append number of mod times. 
	for(int i=0;i<rep;i++){ 
		strcat(keyword,key); 	 
	}
	for(int i=0;i<mod;i++){
 		append(keyword, key[i]); //append method adds characters to keyword. 
	}
	if(selection=='1'){
		encryption(text1,keyword);
	}
	else if(selection == '2'){
		decryption(text1,keyword);
	}
	return 0;
}


