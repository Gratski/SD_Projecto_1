#include "data.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


/* view .h doc */
struct data_t *data_create(int size){

	struct data_t *d = (struct data_t *) malloc(sizeof( struct data_t ));
	d->datasize = size;
	d->data = (void *) malloc(size);
	return d;

}


/* view .h doc */
struct data_t *data_create2(int size, void * data){

	struct data_t *d = data_create(size);
	memcpy(d->data, data, d->datasize);
	return d;

}

/* view .h doc */
void data_destroy(struct data_t *data){

	// se a data foi alocada
	if( data->data != NULL ){
		free(data->data);
	}
	// liberta struct itself
	free(data);

}

/* view .h doc */
struct data_t *data_dup(struct data_t *data){

	return data_create2(data->datasize, data->data);

}
