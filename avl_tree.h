/** Tiedosto määrittelee avl-puun toteutukseen tarvittavat funkiot ja alkiot.
 * Käytettävät funkiot on listattu ja määritelty alla.
 * Tiedosto ei käytä muiden tiedostojen funktioita.
 */

#ifndef AVL_TREE_H
#define	AVL_TREE_H

/** Avl-puun alkion määrittely
 */
typedef struct node {
    char * data;
    int height;
    int count;
    struct node * left;
    struct node * right;
    struct node * parent;
} node;

/** Avl-puun juuren määrittely
 */
struct node * root;

/**
 * Tarkoitus: Palauttaa kahdesta arvosta suuremman.
 * Parametrit: Kokonaisluku a ja kokonaisluku b.
 * Palauttaa: Palauttaa arvon a, jos a on suurempi kuin b. Muutoin palauttaa 
 * arvon b
 * Muuttaa: Ei mitään
 */
int max(int a, int b);

/**
 * Tarkoitus: Palauttaa solmun korkeuden.
 * Parametrit: Viite solmuun.
 * Palauttaa: Jos solmu on olemassa, palautetaan solmun korkeus. Muutoin
 * palautetaan -1.
 * Muuttaa: Ei mitään
 */
int height(node * nod);

/**
 * Tarkoitus: Vapauttaa puun alkoille varatun tilan.
 * Parametrit: Viite solmuun.
 * Palauttaa: Ei mitään
 * Muuttaa: Vapauttaa puun alkoille varatun tilan.
 */
void delete_tree(node * nod);

/**
 * Tarkoitus: Luo uuden solmun, varaa solmulle ja sen datalle tilan ja asettaa 
 * kentille alkuarvot.
 * Parametrit: Viiten solmun vanhempaan ja solmuun talletettavaan dataan.
 * Palauttaa: Kaiken onnistuessa uuden solmun, muutoin arvon NULL.
 * Muuttaa: Ei mitään.
 */
node * create_node(node * parent, char * data);

/**
 * Tarkoitus: Lisää puuhun uuden alkion.
 * Parametrit: Viite lisättävään solmuun ja solmuun talletettavaan dataan.
 * Palauttaa: Ei mitään.
 * Muuttaa: Lisää uuden alkion puuhun, muuttaa tarvittaessa uuden alkion ja 
 * puun juuren välisten solmujen korkeutta.
 */
void insert(node * nod, char * data);

/**
 * Tarkoitus: Tekee tarvittavat kierto-operaatiot puun saattamiseksi tasapainoon.
 * Parametrit: Viite tasapainotettavaan solmuun.
 * Palauttaa: Tasapainotetun solmun.
 * Muuttaa: Ei mitään.
 */
node * balance_tree(node * nod);

/**
 * Tarkoitus: Suorittaa avl-puun kierto-operaation vasemmalle.
 * Parametrit: Viite epätasapainossa olevaan solmuun
 * Palauttaa: Kierretyn alipuun uuden juuren.
 * Muuttaa: Solmun ja sen oikean lapsen korkeutta, viitteitä juuren, solmun
 * vanhemman, solmun ja sen oikean lapsen välillä.
 */
node * rotate_left(node * k1);

/**
 * Tarkoitus: Suorittaa avl-puun kierto-operaation oikealle.
 * Parametrit: Viite epätasapainossa olevaan solmuun
 * Palauttaa: Kierretyn alipuun uuden juuren.
 * Muuttaa: Solmun ja sen vasemman lapsen korkeutta, viitteitä juuren, solmun
 * vanhemman, solmun ja sen vasemman lapsen välillä.
 */
node * rotate_right(node * k1);

/**
 * Tarkoitus: Tulostaa puun solmujen datan ja näiden korkeuden.
 * Parametrit: Viite solmuun.
 * Palauttaa: Ei mitään.
 * Muuttaa: Ei mitään-
 */
void print_inorder(node * nod);

#endif

