#include "data.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct data_t *data_create(int size){
	if (size < 0)
		return NULL;

	struct data_t *d = (struct data_t *) malloc(sizeof( struct data_t ));
	d->datasize = size;
	d->data = (void *) malloc(size);
	return d;

}

struct data_t *data_create2(int size, void * data){
	if (size < 0 || data == NULL)
		return NULL;

	struct data_t *d = data_create(size);
	memcpy(d->data, data, d->datasize);
	return d;

}

void data_destroy(struct data_t *data){
	if (data == NULL)
		return;

	// se a data foi alocada
	if(data->data != NULL)
		free(data->data);

	// liberta data
	free(data);

}

struct data_t *data_dup(struct data_t *data){
	if (data == NULL)
		return NULL;

	return data_create2(data->datasize, data->data);

}
