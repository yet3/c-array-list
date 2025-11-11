#ifndef ARRAY_LIST_H
#define ARRAY_LIST_H

#include <stdbool.h>
#include <stdio.h>

typedef struct {
  void *p_data;
  size_t init_capicity;
  size_t capicity;
  size_t len;
  size_t item_size;
} ArrayList;

ArrayList *ArrayList_init(size_t, size_t);
void ArrayList_free(ArrayList *);
void ArrayList_clear(ArrayList *);

bool ArrayList_resize(ArrayList *, size_t);
bool ArrayList_remove(ArrayList *, size_t);
bool ArrayList_pop(ArrayList *);
bool ArrayList_append(ArrayList *, void *);
bool ArrayList_replace(ArrayList *, size_t, void *);
void *ArrayList_at(ArrayList *, size_t);
size_t ArrayList_len(ArrayList *);

#endif
