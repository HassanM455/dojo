#include <stdio.h>
#include "../1-arrays-and-string/utilities.c"

typedef struct Node {
  struct Node *next;
  int value;
} Node ; 

typedef struct LinkedList {
  struct Node* head;
  struct Node* current ; 
  void (*iter_next)(struct LinkedList* ) ;
  void (*make_ll)(struct LinkedList*, int[], int);
  void (*traverse_ll)(struct LinkedList*); 
} LinkedList ; 

void iter_next(struct LinkedList* ll) {

  Node *node = (ll->current)->next ;
  if (node == NULL) {
    ll->current = NULL ; 
    return ;
  }
  ll->current = node ; 
  
}

void make_ll(struct LinkedList *ll, int values[], int size){

  int value ; 
  struct Node *head = (struct Node*)malloc(sizeof(Node)); 
  head->value = values[0];
  ll->head = head ;
  ll->current = head ; 
  struct Node *n; 

  for(int i = 1 ; i < size; i++) {
    n = (struct Node*)malloc(sizeof(Node));
    n->next = NULL ; 
    n->value = values[i];
    (ll->current)->next = n; // setting current node's next to new node
    ll->current = n; // setting current node to new node
  }

  ll->current = head ; 

}

void traverse_ll(struct LinkedList *ll) {
    ll->current = ll->head; 

    while (ll->current != NULL) {
      struct Node *curr = ll->current ;
      printf("This is the value for the current node at addr %p %d \n", curr, curr->value) ; 
      ll->iter_next(ll);
    }

}

int main(int argc, char *argv[]) {
    int values[10] = {0,1,2,3,4,5,6,7,8,9};
    struct LinkedList ll ; 
    ll.make_ll = make_ll; 
    ll.iter_next = iter_next; 
    ll.make_ll(&ll, values, 10);
    ll.traverse_ll = traverse_ll;
    ll.traverse_ll(&ll);

    return 0 ; 
}
