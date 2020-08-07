
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>
#include "ntree.h"
#include "min-max.h"


//----------------------------------------


NTree ntree_new ()
{
    return NULL;
}


//----------------------------------------


NTree ntree_create (const void *data, size_t size, size_t arity)
{
    NTree tree = (NTree) malloc (sizeof (NTree *) + sizeof (size_t) + size);
    if (tree)
    {
        tree->subtrees = (NTree *) malloc (arity * sizeof(NTree));
        if (tree->subtrees)
        {
            size_t i;

            for (i = 0; i < arity; i++)
                tree->subtrees[i] = NULL;
            tree->arity = arity;
            memcpy (tree->data, data, size);
        }
    }
    else
    {
        free (tree);
        tree = NULL;
    }

    return tree;
}


//----------------------------------------


void ntree_delete (NTree tree, void (*deletef) (void *))
{
    if (tree)
    {
        size_t i;

        for (i = 0; i < tree->arity; i++)
            ntree_delete (tree->subtrees[i], deletef);
        if (deletef)
            deletef (tree->data);
        free (tree);
    }
}


//----------------------------------------


void * ntree_get_data(NTree tree){
    if(tree) {
        printf("ntree_get_data() [ok]");
        return tree->data;
    } else {
        printf("Impossible d'appliquer la fonction.");
        return NULL;
    }
}


//----------------------------------------


bool ntree_set_nth(NTree tree, NTree sub, size_t nth){
    /*
    if(tree && (nth <= tree->arity)){
        tree->subtrees[nth-1] = sub;
        printf("ntree_set_nth() [ok]");
        return true;
    }else{
        printf("Impossible d'appliquer la fonction.");
        return false;
    }
    */
}


//----------------------------------------


bool ntree_set_data(NTree tree, const void *data, size_t size){
    if(tree){
        memcpy(tree->data, data, size);
        printf("ntree_set_data() [ok]");
        return true;
    } else {
        printf("Impossible d'appliquer la fonction.");
        return false;
    }
}


//----------------------------------------


size_t ntree_height(NTree tree){ // Trouver la profondeur maximale.
    if(tree){
        int max = 1;
        for(int i = 0; i < tree->arity; i++){
            max = MAX(ntree_height(tree->subtrees[i]), max);
        }
        printf("ntree_height() [ok]");
        return max;
    } else {
        printf("Impossible d'appliquer la fonction.");
        return 0;
    }
}


//----------------------------------------


size_t ntree_size(NTree tree){ // Calculer le nombre d'éléments.
    if(tree){
        int size = 1;
        for(int i = 0; i< tree->arity; i++){
            size = ntree_size(tree->subtrees[i]) + size;
        }
        printf("ntree_size() [ok]");
        return size;
    } else {
        printf("Impossible d'appliquer la fonction.");
        return 0;
    }
}


//----------------------------------------


void ntree_pre_order(NTree tree, void (*func)(void *, void *), void *extra_data){
    if(tree){
        func(tree->data, extra_data);
        for(int i = 0; i < tree->arity; i++){
            ntree_pre_order(tree->subtrees[i], func, extra_data);
        }
        printf("ntree_pre_order() [ok]");
    } else {
        printf("Impossible d'appliquer la fonction.");
    } 
}


//----------------------------------------


void ntree_post_order(NTree tree, void (*func)(void *, void *), void *extra_data){
    if(tree){
        for(int i = 0; i < tree->arity; i++){
            ntree_post_order(tree->subtrees[i], func, extra_data);
        }
        func(tree->data, extra_data);
        printf("ntree_pre_order() [ok]");
    } else {
        printf("Impossible d'appliquer la fonction.");
    }
}


//----------------------------------------


void ntree_in_order(NTree tree, void (*func)(void *, void *), void *extra_data, size_t nth){
    if(tree){
        for(int i = 0; i < nth && i < tree->arity; i++){
            ntree_in_order(tree->subtrees[i], func, extra_data, nth);
        }
        printf("ntree_pre_order() [ok] + PRE_ORDER");
        func(tree->data, extra_data);
        for(int i = nth; i < tree->arity; i++){
            ntree_in_order(tree->subtrees[i], func, extra_data, nth);
        }
        printf("ntree_pre_order() [ok] + POST_ORDER");
    } else {
        printf("Impossible d'appliquer la fonction.");
    }
}


//----------------------------------------

