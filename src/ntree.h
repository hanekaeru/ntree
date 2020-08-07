


/*--------------------------------------------------------------------*/

#ifndef _NTREE_H_
#define _NTREE_H_

#include <stdlib.h>

typedef struct _NTreeNode *NTree;

struct _NTreeNode
  {
    NTree *subtrees;
    size_t arity; // n-aire
    char data[1];
  };

/*--------------------------------------------------------------------*/
NTree ntree_new ();


NTree ntree_create (const void *data, size_t size,
                    size_t arity);


void ntree_delete (NTree tree, void (*delete) (void
*));



NTree ntree_get_nth (NTree tree, size_t nth);

void *ntree_get_data (NTree tree);

bool ntree_set_nth (NTree tree, NTree sub, size_t nth);

bool ntree_set_data (NTree tree, const void *data,
size_t size);


size_t ntree_height (NTree tree);

size_t ntree_size (NTree tree);



void ntree_pre_order (NTree tree,
                      void (*func) (void *, void *),
                      void *extra_data);

void ntree_in_order (NTree tree,
                     void (*func) (void *, void *),
                     void *extra_data,
                     size_t nth);

void ntree_post_order (NTree tree,
                       void (*func) (void *, void *),
                       void *extra_data);




#endif



