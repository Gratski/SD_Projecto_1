#include "list.h"
#include "list-private.h"
#include "entry.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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


void list_destroy(struct list_t *list){
	if( list == NULL )
		return;

	struct node_t *cur = list->head;
	struct node_t *aux = list->head;

	while(cur != NULL){
		entry_destroy(cur->entry);
		cur = cur->next;

		free(aux);
		aux = cur;
	}

	free(list);
}


int list_add(struct list_t *list, struct entry_t *entry){
	if (list == NULL)
		return -1;

	struct node_t* node = malloc(sizeof (struct node_t));

	if (node == NULL)
		return -1;

	// preparar node a ser inserido na lista
	node->entry = entry;
	node->next = NULL;
	

	struct node_t* current = current = list->head;
	struct node_t* previous = current;

	// lista vazia
	if (list->head == NULL)
		list->head = node;

	// adicionar no ao inicio da lista se nao existe
	else if (strcmp(entry->key, list->head->entry->key) < 0) {
		node->next = list->head;
		list->head = node;
	}

	else {
		
		int str_cmp;

		// encontrar posicao para o novo no
		do
		{
			str_cmp = strcmp(entry->key, current->entry->key);
			previous = current;
			current = current->next;
		} while( str_cmp > 0 && current != NULL );

		// key jah presente na lista
		if (str_cmp == 0)
			return -1;
		// adicionar no ao final da lista
		else if (current == NULL)
			previous->next = node;
		// adicionar no noutra posicao
		else {
			node->next = current;
			previous->next = node;
		}
	}

	list->size += 1;
	return 0;
}


/* view .h doc */
int list_remove(struct list_t *list, char *key){

	// se estah vazia ou nao foi alocada
	if ( list == NULL || list->size == 0 || key == NULL)
		return -1;

	struct node_t *cur = list->head;
	struct node_t *auxPrev = NULL;		// aponta para o indice anterior ao actual

	while( cur != NULL )
	{
		if( strcmp(key, cur->entry->key) == 0 )
		{
			// se nao estah na 1a posicao
			if( auxPrev != NULL )
				auxPrev->next = cur->next;
			else
				list->head = cur->next;

			list->size--;
			entry_destroy(cur->entry);
			free(cur);

			return 0;
		}

		auxPrev = cur;
		cur = cur->next;

	}

	return -1;
}

/* view .h doc */
struct entry_t *list_get(struct list_t *list, char *key){
	if (list == NULL || key == NULL)
		return NULL;

	struct node_t *cur = list->head;

	// percorre a lista
	while(cur != NULL)
	{
		// verifica se eh o que deve retornar
		if( strcmp( cur->entry->key, key ) == 0 )
			return cur->entry;

		cur = cur->next;
	}

	// caso nao tenha encontrado nada
	return NULL;
}

/* view .h doc */
int list_size(struct list_t *list){

	// se erro
	if( list == NULL )
		return -1;
	// se OK devolve size
	else
		return list->size;
}

/* view .h doc */
char **list_get_keys(struct list_t *list){
	if (list == NULL)
		return NULL;

	// array com tamanho para todos os pointers para strings
	char **arr = malloc(sizeof(char *) * list_size(list) + 1);

	if (arr == NULL)
		return NULL;

	//primeiro node da lista
	struct node_t *cur = list->head;
	int i = 0;

	//ciclo para obter as keys da lista
	while( cur != NULL )
	{
		// escreve em indice "i" a current entry key
		arr[i] = strdup(cur->entry->key);

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
	if (keys == NULL)
		return;

	int i = 0;
	// percorre ateh ao final do array
	for(i = 0; keys[i] != NULL; i++)
		free(keys[i]);

	// liberta memoria de array
	free(keys);
}

/*
	faz o print da lista ligada
	util para debug
*/
void list_print(struct list_t *list){
	if (list == NULL)
		return;

	struct node_t *cur = list->head;

	while(cur != NULL)
	{
		printf("%s\n", cur->entry->key);
		cur = cur->next;
	}
}





