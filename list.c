#include "list.h"
#include "list-private.h"
#include "entry.h"

#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

/*
	alterar para lista simplesmente ligada
*/

/* view .h doc */
struct list_t *list_create(){

	struct list_t *list = (struct list_t *) malloc(sizeof(struct list_t));

	// se nao tem espaco de memoria
	if( list == NULL )
		return NULL;

	list->size = 0;
	list->head = NULL;

	return list;
}

/* view .h doc */
void list_destroy(struct list_t *list){

	if( list == NULL )
		return;

	struct node *cur = list->head;
	struct node *aux = list->head;

	printf("a apagar...\n");

	while(cur != NULL){
		
		entry_destroy(cur->entry);		

		cur = cur->next;

		free(aux);
		aux = cur;
	}

	//after remove all list nodes
	free(list);
}

/* view .h doc */
int list_add(struct list_t *list, struct entry_t *entry){

	struct node *node = (struct node *) malloc(sizeof( struct node ));
	node->entry = entry;

	// se a lista eh vazia
	if ( list == NULL )
	{
		return -1;
	}

	// se ainda estah vazia
	if( list->size == 0 )
	{
		list->head = node;
		node->next = NULL;
	}
	//se jah tem elems
	else
	{

		int added = 0;	
		
		struct node *cur = list->head;
		struct node *auxPrev = NULL;

		while( cur != NULL )
		{

			int code = strcmp(entry->key, cur->entry->key);

			if ( code < 0 )
			{

				node->next = cur;

				if( auxPrev != NULL )
				{
					auxPrev->next = node;
				}
				else{

					list->head = node;
				}

				added = 1;
				break;
			}

			auxPrev = cur;
			cur = cur->next;

		}

		// se chegou ao fim sem adicionar
		if (added == 0)
		{
			auxPrev->next = node;
			node->next = NULL;
		}

	}

	list->size = list->size + 1;
	return 0;
	
}


/* view .h doc */
int list_remove(struct list_t *list, char *key){

	
	

}

/* view .h doc */
struct entry_t *list_get(struct list_t *list, char *key){

	struct node *cur = list->head;

	// percorre a lista
	while(cur != NULL)
	{
		// verifica se eh o que deve retornar
		if( strcmp( cur->entry->key, key ) == 0 )
		{
			return cur->entry;
		}

		cur = cur->next;
	}

	// caso nao tenha encontrado nada
	return NULL;
}

/* view .h doc */
int list_size(struct list_t *list){
	
	// se erro
	if( list == NULL )
	{
		return -1;
	}

	// se OK devolve size
	else
	{
		return list->size;
	}
}

/* view .h doc */
char **list_get_keys(struct list_t *list){

	// array com tamanho para todos os pointers para strings
	char **arr = malloc(sizeof(char *) * list_size(list));
	
	//primeiro node da lista
	struct node *cur = list->head;
	int i = 0;

	//ciclo para obter as keys da lista
	while( cur != NULL )
	{
		// escreve em indice "i" a current entry key
		arr[i] = cur->entry->key;

		//avança pointer de lista
		cur = cur->next;
		//avança indice de array
		i++;
	}

	// escreve um null no final para servir de limiter
	arr[i] = NULL;
	return arr;
}

/* view .h doc */
void list_free_keys(char **keys){

	int i = 0;
	char *cur = keys[i];

	// percorre ateh ao final do array
	while(cur != NULL)
	{
		
		free(keys[i]);
		cur = keys[++i];

	}

	// liberta memoria de array
	free(keys);

}

/*
	faz o print da lista ligada
	util para debug
*/
void list_print(struct list_t *list){

	struct node *cur = list->head;

	while(cur != NULL)
	{

		printf("%s\n", cur->entry->key);
		cur = cur->next;

	}

}





