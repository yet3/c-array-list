#include "array-list.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool try_to_upsize(ArrayList *list) {
  if (list->len >= list->capicity) {
    if (!ArrayList_resize(list, list->capicity * 2)) {
      return false;
    }
  }
  return true;
}

bool try_to_downsize(ArrayList *list) {
  if (list->len <= list->capicity / 2 && list->capicity > list->init_capicity) {
    if (!ArrayList_resize(list, list->capicity / 2)) {
      return false;
    }
    return true;
  }
  return false;
}

bool is_idx_in_bounds(ArrayList *list, size_t idx) {
  if (idx < 0 || idx >= list->len) {
    printf("Index out of bounds: Trying to access index %zu\n in list of "
           "length %zu\n",
           idx, list->len);
    return false;
  }
  return true;
}

bool is_list_empty(ArrayList *list) {
  if (list->len == 0) {
    printf("The list is empty, nothing to do\n");
    return true;
  }
  return false;
}

//

ArrayList ArrayList_init(size_t capicity, size_t item_size) {
  return (ArrayList){
      .init_capicity = capicity,
      .capicity = capicity,
      .len = 0,
      .p_data = calloc(capicity, item_size),
      .item_size = item_size,
  };
}

void ArrayList_free(ArrayList *list) { free(list->p_data); }

void ArrayList_clear(ArrayList *list) {
  free(list->p_data);
  list->capicity = list->init_capicity;
  list->len = 0;
  list->p_data = calloc(list->capicity, list->item_size);
}

bool ArrayList_resize(ArrayList *list, size_t capicity) {
  if (list->len > capicity) {
    printf("Error resizing list's capicity, length of the list %zu, is bigger "
           "then target capicity of %zu\n",
           list->len, capicity);
    return false;
  }

  list->capicity = capicity;
  list->p_data = realloc(list->p_data, list->item_size * capicity);

  if (list->p_data == NULL) {
    printf("Error re-allocating list's data memory\n");
    return false;
  }
  return true;
}

bool ArrayList_pop(ArrayList *list) {
  if (is_list_empty(list)) {
    return false;
  }

  list->len--;

  if (!try_to_downsize(list)) {
    return false;
  }

  return true;
}

bool ArrayList_remove(ArrayList *list, size_t idx) {
  if (!is_idx_in_bounds(list, idx)) {
    return false;
  }

  if (idx == list->len - 1) {
    return ArrayList_pop(list);
  }

  void *dest = &list->p_data[idx * list->item_size];
  void *src = &list->p_data[(idx + 1) * list->item_size];
  memcpy(dest, src, list->item_size * (list->len - idx + 2));
  list->len--;

  if (!try_to_downsize(list)) {
    return false;
  }

  return true;
}

bool ArrayList_append(ArrayList *list, void *item) {
  if (!try_to_upsize(list)) {
    return false;
  }

  void *dest = &list->p_data[list->len * list->item_size];
  memcpy(dest, item, list->item_size);
  list->len++;

  return true;
}

bool ArrayList_replace(ArrayList *list, size_t idx, void *item) {
  if (!is_idx_in_bounds(list, idx) || is_list_empty(list)) {
    return false;
  }

  void *dest = &list->p_data[idx * list->item_size];
  memcpy(dest, item, list->item_size);

  return true;
}

void *ArrayList_at(ArrayList *list, size_t idx) {
  if (!is_idx_in_bounds(list, idx)) {
    return NULL;
  }

  return &list->p_data[idx * list->item_size];
}
