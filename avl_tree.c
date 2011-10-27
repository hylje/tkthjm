/** Tiedosto sisältää toteutuksen avl-puun funktioille.
 * Tiedosto ei käytä muiden tiedostojen funktioita.
 */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include "avl_tree.h"

int max(int a, int b) {
    if (a > b) {
        return a;
    } else {
        return b;
    }
}

int height(node * nod) {
    if (nod != NULL) {
        return nod->height;
    } else {
        return -1;
    }
}

//TODO: fix this

void delete_tree(node * nod) {
    if (nod != NULL) {
        delete_tree(nod->left);
        delete_tree(nod->right);
        //printf("data: %s\n", ptr->data);
        //free(nod->data);
        free(nod);
    }
    return;
}

node * create_node(node * parent, char * data) {
    node * new = malloc(sizeof (node));

    if (new == NULL) {
        printf("Virhe tilan varaamisessa");
        return NULL;
    }

    new->data = malloc(sizeof (char) * (strlen(data) + 1));

    if (new->data == NULL) {
        printf("Virhe tilan varaamisessa");
        free(new);
        return NULL;
    }

    new->data = data;
    new->height = 0;
    new->left = NULL;
    new->right = NULL;
    new->parent = parent;

    return new;
}

void insert(node * nod, char * data) {
    node * current = nod;

    if (nod == NULL && nod == root) {
        root = create_node(NULL, data);
        return;
    }

    while (strcmp(current->data, data) != 0) {
        if (strcmp(data, current->data) < 0) {
            if (current->left != NULL) {
                current = current->left;
            } else {
                current->left = create_node(current, data);
                current = current->left;
            }
        } else if (strcmp(data, current->data) > 0) {
            if (current->right != NULL) {
                current = current->right;
            } else {
                current->right = create_node(current, data);
                current = current->right;
            }
        } else { //arvo on jo puussa
            current->count++;
            return;
        }
    }

    do {
        current = current->parent;
        current->height = max(height(current->left), height(current->right)) + 1;
        current = balance_tree(current);
    } while (current->parent != NULL);
}

node * balance_tree(node * nod) {
    if (abs(height(nod->left) - height(nod->right)) < 2) {
        return nod;
    } else if (height(nod->left) == (height(nod->right) + 2)) {
        if (height(nod->left->left) > height(nod->left->right)) {
            nod = rotate_right(nod);
        } else {
            rotate_left(nod->left);
            nod = rotate_right(nod);
        }
        //} else if (height(nod->right) == (height(nod->left) + 2)) {
    } else {
        if (height(nod->right->right) > height(nod->right->left)) {
            nod = rotate_left(nod);
        } else {
            rotate_right(nod->right);
            nod = rotate_left(nod);
        }
    }
    return nod;
}

node * rotate_right(node * k1) {
    node * k2 = k1->left;

    k2->parent = k1->parent;

    if (k1->parent != NULL) {
        if (k1 == k1->parent->left) {
            k1->parent->left = k2;
        } else {
            k1->parent->right = k2;
        }
    } else {
        root = k2;
    }

    k1->parent = k2;
    k1->left = k2->right;

    if (k1->left != NULL) {
        k1->left->parent = k1;
    }

    k2->right = k1;

    k1->height = max(height(k1->left), height(k1->right)) + 1;
    k2->height = max(height(k2->left), height(k2->right)) + 1;

    return k2;

}

node * rotate_left(node * k1) {
    node * k2 = k1->right;

    k2->parent = k1->parent;

    if (k1->parent != NULL) {
        if (k1 == k1->parent->right) {
            k1->parent->right = k2;
        } else {
            k1->parent->left = k2;
        }
    } else {
        root = k2;
    }

    k1->parent = k2;
    k1->right = k2->left;

    if (k1->right != NULL) {
        k1->right->parent = k1;
    }

    k2->left = k1;

    k1->height = max(height(k1->left), height(k1->right)) + 1;
    k2->height = max(height(k2->left), height(k2->right)) + 1;

    return k2;
}

void print_inorder(node * nod) {
    if (nod != 0) {
        print_inorder(nod->left);
        printf("data: %s, height: %d\n", nod->data, nod->height);
        print_inorder(nod->right);
    }
}

node* findNode(node* nod, char* word) {
    node* left;
    if (nod != 0) {
        if (strcmp(nod->data, word)) {
            return nod;
        }
        left = findNode(nod->left);
        if (left != NULL) {
            return left;
        }
        return findNode(nod->right);

    }
    return nod;
}