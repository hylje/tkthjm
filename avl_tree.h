/** Tiedosto m‰‰rittelee avl-puun toteutukseen tarvittavat funkiot ja alkiot.
 * K‰ytett‰v‰t funkiot on listattu ja m‰‰ritelty alla.
 * Tiedosto ei k‰yt‰ muiden tiedostojen funktioita.
 */

#ifndef AVL_TREE_H
#define	AVL_TREE_H

/** Avl-puun alkion m‰‰rittely
 */
typedef struct node {
    char * data;
    int height;
    int count;
    struct node * left;
    struct node * right;
    struct node * parent;
} node;

/** Avl-puun juuren m‰‰rittely
 */
struct node * root;

/**
 * Tekij‰ Miika SirÈn
 * Tarkoitus: Palauttaa kahdesta arvosta suuremman.
 * Parametrit: Kokonaisluku a ja kokonaisluku b.
 * Palauttaa: Palauttaa arvon a, jos a on suurempi kuin b. Muutoin palauttaa 
 * arvon b
 * Muuttaa: Ei mit‰‰n
 */
int max(int a, int b);

/**
 * Tekij‰ Miika SirÈn
 * Tarkoitus: Palauttaa solmun korkeuden.
 * Parametrit: Viite solmuun.
 * Palauttaa: Jos solmu on olemassa, palautetaan solmun korkeus. Muutoin
 * palautetaan -1.
 * Muuttaa: Ei mit‰‰n
 */
int height(node * nod);

/**
 * Tekij‰ Miika SirÈn
 * Tarkoitus: Vapauttaa puun alkioille varatun tilan.
 * Parametrit: Viite solmuun.
 * Palauttaa: Ei mit‰‰n
 * Muuttaa: Vapauttaa puun alkioille varatun tilan.
 */
void delete_tree(node * nod);

/**
 * Tekij‰ Miika SirÈn
 * Tarkoitus: Luo uuden solmun, varaa solmulle ja sen datalle tilan ja asettaa 
 * kentille alkuarvot.
 * Parametrit: Viiten solmun vanhempaan ja solmuun talletettavaan dataan.
 * Palauttaa: Kaiken onnistuessa uuden solmun, muutoin arvon NULL.
 * Muuttaa: Ei mit‰‰n.
 */
node * create_node(node * parent, char * data);

/**
 * Tekij‰ Miika SirÈn
 * Tarkoitus: Lis‰‰ puuhun uuden alkion.
 * Parametrit: Viite lis‰tt‰v‰‰n solmuun ja solmuun talletettavaan dataan. 
               Tekee kopion solmuun talletettavasta datasta.
 * Palauttaa: Ei mit‰‰n.
 * Muuttaa: Lis‰‰ uuden alkion puuhun, muuttaa tarvittaessa uuden alkion ja 
 * puun juuren v‰listen solmujen korkeutta.
 */
void insert(node * nod, char * data);

/**
 * Tekij‰ Miika SirÈn
 * Tarkoitus: Tekee tarvittavat kierto-operaatiot puun saattamiseksi tasapainoon.
 * Parametrit: Viite tasapainotettavaan solmuun.
 * Palauttaa: Tasapainotetun solmun.
 * Muuttaa: Ei mit‰‰n.
 */
node * balance_tree(node * nod);

/**
 * Tekij‰ Miika SirÈn
 * Tarkoitus: Suorittaa avl-puun kierto-operaation vasemmalle.
 * Parametrit: Viite ep‰tasapainossa olevaan solmuun
 * Palauttaa: Kierretyn alipuun uuden juuren.
 * Muuttaa: Solmun ja sen oikean lapsen korkeutta, viitteit‰ juuren, solmun
 * vanhemman, solmun ja sen oikean lapsen v‰lill‰.
 */
node * rotate_left(node * k1);

/**
 * Tekij‰ Miika SirÈn
 * Tarkoitus: Suorittaa avl-puun kierto-operaation oikealle.
 * Parametrit: Viite ep‰tasapainossa olevaan solmuun
 * Palauttaa: Kierretyn alipuun uuden juuren.
 * Muuttaa: Solmun ja sen vasemman lapsen korkeutta, viitteit‰ juuren, solmun
 * vanhemman, solmun ja sen vasemman lapsen v‰lill‰.
 */
node * rotate_right(node * k1);

/**
 * Tekij‰ Miika SirÈn
 * Tarkoitus: Tulostaa puun solmujen datan ja n‰iden korkeuden.
 * Parametrit: Viite solmuun.
 * Palauttaa: Ei mit‰‰n.
 * Muuttaa: Ei mit‰‰n-
 */
void print_inorder(node * nod);


/**
 * Tekij‰: Juuso Hyvˆnen
 * Tarkoitus: Tulostaa puun sanat ja sanojen lukum‰‰r‰t
 * Parametrit: Viite solmuun.
 * Palauttaa: Ei mit‰‰n.
 * Muuttaa: Ei mit‰‰n-
 */
void print_counts(node * nod);

/**
 * Tekij‰: Juuso Hyvˆnen
 * Tarkoitus: Etsii solmun, joka kuvaa etsitty‰ sanaa
 * Parametrit: Viite solmuun, viite etsitt‰v‰‰n sanaan.
 * Palauttaa: Viitteen etsittyyn solmuun.
 * Muuttaa: Ei mit‰‰n-
 */
node* findNode(node*, char*);

#endif

