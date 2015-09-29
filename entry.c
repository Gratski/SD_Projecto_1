#include "entry.h"
#include "data.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

/* view .h doc */
struct entry_t *entry_create(char *key, struct data_t *data){
	if (key == NULL || data == NULL)
		return NULL;

	//aqui falar com o prof prq falta um arg
	struct entry_t *e = (struct entry_t *) malloc( sizeof( struct entry_t ) );
	e->key   = strdup(key);
	e->value = data_dup(data);
	return e;

}

/* view .h doc */
void entry_destroy(struct entry_t *entry){
	if (entry == NULL)
		return;

	// liberta data_t
	data_destroy(entry->value);
	// liberta string
	free(entry->key);
	// liberta struct itself
	free(entry);

}

/* view .h doc */
struct entry_t *entry_dup(struct entry_t *entry){
	if (entry == NULL)
		return NULL;

	// cria nova struct
	return entry_create(entry->key, entry->value);

}