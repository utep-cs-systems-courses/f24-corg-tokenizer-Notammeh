#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define _TOKENIZER_


/* Return true (non-zero) if c is a whitespace characer

   ('\t' or ' ').  

   Zero terminators are not printable (therefore false) */

int space_char(char c){
  return (c == ' ' || c == '\t');
}

/* Return true (non-zero) if c is a non-whitespace 

   character (not tab or space).  

   Zero terminators are not printable (therefore false) */

int non_space_char(char c){
  return c != '\0' && !space_char(c);
}

/* Returns a pointer to the first character of the next 

   space-separated token in zero-terminated str.  Return a zero pointer if 

   str does not contain any tokens. */

char *token_start(char *str){
  while (*str != '\0' && space_char(*str)){
    str++;
  }

  return *str!= '\0'? str:NULL;
}



/* Returns a pointer terminator char following *token */

char *token_terminator(char *token){
  while (*token != '\0' && non_space_char(*token)){
      token++;
  }
  return token;
}



/* Counts the number of tokens in the string argument. */

int count_tokens(char *str){
  char *token = token_start(str);
  int count = 0;

  do{
    count++;
    token = token_terminator(token);//end of current
    token = token_start(token);//pointer to next token
  }while(token != NULL);
  
  return count;
}

  
/* Returns a fresly allocated new zero-terminated string 

   containing <len> chars from <inStr> */

  char *copy_str(char *inStr, short len){

    char *resultString = malloc((len + 1)* sizeof(char)); // allocating memory for new string

    //check if the memory allocation was cerated succesfully
    if (resultString == NULL){
      return NULL;
    }

    //Copy the characters from inStr to resultString
    for (int i = 0; i < len; i++){
      resultString[i] = inStr[i];
    }
    
    //Add the termination
    resultString[len] = '\0';

    return resultString;
    
  }



/* Returns a freshly allocated zero-terminated vector of freshly allocated 

   space-separated tokens from zero-terminated str.
   For example, tokenize("hello world string") would result in:

     tokens[0] = "hello"

     tokens[1] = "world"

     tokens[2] = "string" 

     tokens[3] = 0

*/

  char **tokenize(char* str){
    //use the count_tokens to determine how many tokens has the string
    int tokensNum = count_tokens(str);
    
    //allocate memory
    char **tokens = malloc((tokensNum + 1) * sizeof(char*));

    if (tokens == NULL){
      return NULL;
    }

    char *tokenStart = token_start(str);
    char *stop;

    for (int i = 0; i < tokensNum; i++){
      stop = token_terminator(tokenStart);

      //no more tokens
      if (tokenStart == NULL){
	break;
      }

      *(tokens+i)= copy_str(tokenStart, (stop - tokenStart));
      tokenStart = token_start(stop);

    }
    *(tokens + tokensNum)= NULL;
    return tokens;
      
  }



/* Prints all tokens. */

    void print_tokens(char **tokens){
      if (tokens == NULL){
	printf("No tokens\n");
	return;
      }

      for (int i = 0; tokens[i] != NULL; i++){
	printf("Token: %s \n", tokens[i]);
      }
    }



/* Frees all tokens and the vector containing themx. */

    void free_tokens(char **tokens){
      if (tokens ==NULL){
	return;
      }

      for(int i = 0;tokens[i] != NULL; i++){
	free(tokens[i]);
      }
	  free(tokens);
    }
