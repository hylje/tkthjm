/** Tiedostossa testataan alkioiden lisäämistä avl-puuhun ja samalla myös muiden
 * avl-puun funktioiden toimintaa.
 * Testiaineistona on käytetty Tietorakenteet-kurssin vuoden 2010 luentomonisteen
 * sivujen 194-207 esimerkkejä sillä muutoksella, että numerot on korvattu
 * aakkoston vastaavalla kirjaimella (a = 1, b = 2 jne)
 */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "avl_tree.h"

int main(void) {
    char * data;

    data = "c";
    insert(root, data);
    data = "b";
    insert(root, data);
    data = "a";
    insert(root, data);

    print_inorder(root);
    
    printf("root %s\n", root->data);
    printf("left %s\n", root->left->data);
    printf("right %s\n", root->right->data);
    
    data = "d";
    insert(root, data);
    data = "e";
    insert(root, data);
    
    print_inorder(root);
    
    printf("right child %s\n", root->right->data);
    printf("left %s\n", root->right->left->data);
    printf("right %s\n", root->right->right->data);
    
    data = "f";
    insert(root, data);
    
    print_inorder(root);
    
    printf("root %s\n", root->data);
    printf("left %s\n", root->left->data);
    printf("right %s\n", root->right->data);
    
    data = "g";
    insert(root, data);
    
    print_inorder(root);
    
    printf("right child %s\n", root->right->data);
    printf("left %s\n", root->right->left->data);
    printf("right %s\n", root->right->right->data);
    
    data = "p";
    insert(root, data);
    data = "o";
    insert(root, data);
    
    print_inorder(root);
    
    printf("right child's right child %s\n", root->right->right->data);
    printf("left %s\n", root->right->right->left->data);
    printf("right %s\n", root->right->right->right->data);
    
    data = "n";
    insert(root, data);
    
    print_inorder(root);
    
    printf("right child %s\n", root->right->data);
    printf("left %s\n", root->right->left->data);
    printf("right %s\n", root->right->right->data);
    
    data = "m";
    insert(root, data);
    
    print_inorder(root);
    
    printf("root %s\n", root->data);
    printf("left %s\n", root->left->data);
    printf("right %s\n", root->right->data);  
    
    data = "l";
    insert(root, data);
    data = "k";
    insert(root, data);
    data = "j";
    insert(root, data);
    data = "h";
    insert(root, data);
    
    print_inorder(root);
    
    printf("root %s\n", root->data);
    printf("left %s\n", root->left->data);
    printf("right %s\n", root->right->data);
    
    data = "i";
    insert(root, data);
    
    print_inorder(root);
    
    printf("right child's left child's left child %s\n", root->right->left->left->data);
    printf("left %s\n", root->right->left->left->left->data);
    printf("right %s\n", root->right->left->left->right->data);
    
    delete_tree(root);
    
    return EXIT_SUCCESS;
}