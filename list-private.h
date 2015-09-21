#ifndef _LIST_PRIVATE_H
#define _LIST_PRIVATE_H

/* No de uma lista duplamente ligada */
struct node{
	struct entry_t *entry;	// entry
	struct node *next;		// proxima entry
};

/* ver list.h doc */
struct list_t{
	int size;			// numero de entradas da lista
	struct node *head;	// head da lista
}; 


/* Imprime lista no ecra */
void list_print(struct list_t *list);

#endif