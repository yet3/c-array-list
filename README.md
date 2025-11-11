# C ArrayList

```c
  ArrayList list = ArrayList_init(5, sizeof(int));

  int ints[8] = {42, 12, 13, 14, 32, 75, 59, 91};
  for (int i = 0; i < 5; i++) {
    ArrayList_append(&list, &ints[i]);
  }

  ArrayList_remove(&list, 4);

  for (int i = 5; i < 8; i++) {
    ArrayList_append(&list, &ints[i]);
  }

  ArrayList_pop(&list);
  ArrayList_replace(&list, 1, &r);

  ArrayList_clear(&list);
  ArrayList_free(&list);
```
