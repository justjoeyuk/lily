#ifndef LILY_STRING_PILE_H
# define LILY_STRING_PILE_H

# include <stdint.h>

/* lily_string_pile is a storage for strings needed by expressions. The
   expression state injects strings at a given index. Later, emitter can fetch
   out the strings by index. The point of this is to have a string storage with
   no waste that is not harmed by the underlying buffer resizing/moving. */

typedef struct  {
    char *buffer;
    uint32_t size;
    uint32_t pad;
} lily_string_pile;

lily_string_pile *lily_new_string_pile(void);

void lily_free_string_pile(lily_string_pile *);

/* Insert a string into the pile at the index given. The index is updated to
   start after the inserted string. */
void lily_sp_insert(lily_string_pile *, char *, uint16_t *);

/* Fetch a string from the pile that starts from the given index. The string is
   a shallow copy of the buffer, and is thus invalidated if the underlying
   buffer happens to grow. */
char *lily_sp_get(lily_string_pile *, int);

#endif
