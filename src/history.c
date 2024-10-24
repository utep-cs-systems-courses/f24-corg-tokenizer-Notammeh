#include <stdio.h>
#include <stdlib.h>
#include "history.h"
#include "tokenizer.h"


/* Initialize the linked list to keep the history. */

List* init_history(){

  List *new_list =(List*)malloc(sizeof(List));//memory allocation

  new_list->root = NULL;

  return new_list;

}

/* Add a history item to the end of the list.

   List* list - the linked list

   char* str - the string to store

*/

void add_history(List *list, char *str){

  Item *new_node = (Item*)malloc(sizeof(Item));//create new node
  Item *head = list->root;
  new_node-> next = NULL;



  if(head == NULL){

    list->root = new_node;
    new_node->id = 0;

  }else{

    while(head->next !=NULL){
      head = head -> next;
    }
    head -> next = new_node;
    new_node->id = head -> id+ 1;

  }
  int length = 0;

  while (*str != '\0'){
    length++;
    str++;
  }

  str = str - length;
  char *hist = copy_str(str,length);
  new_node -> str = hist;

}



/* Retrieve the string stored in the node where Item->id == id.

   List* list - the linked list

   int id - the id of the Item to find */

char *get_history(List *list, int id){

  Item *curr = list->root;//beginning of the list

  if (curr ==NULL){
    return "No history";
  }


  while (curr != NULL){

    if (curr->id == id){

      return curr->str;

    }

    curr=curr->next;

  }

  //No nodes with the indicated ID

  return "Error :(";

}



/*Print the entire contents of the list. */

void print_history(List *list){

  Item *curr = list->root;



  while(curr!= NULL){

    printf("ID: %d | Content: %s\n", curr->id,curr->str);

    curr=curr->next;

  }

}



/*Free the history list and the strings it references. */

void free_history(List *list){

  Item *curr;

  //traverse current list

  while(list->root != NULL){
    curr = list -> root;
    list ->root = list->root->next;

    free(curr->str);//fee data

    free(curr);//free node
  }

  free(list);

}

