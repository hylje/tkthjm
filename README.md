ABOUT
====

A Helsinki University C programming course project, fall 2011 
URL: http://www.cs.helsinki.fi/node/62063 

Our topic:
----------

Write a program that reads one text file. A user can choose how he or
she gives the name of the text file. He can give it either as a
command line parameter or the program can assume that the name comes
from the stdin file.

The program must output the words (at least two sequental letters) and
the number of every word. Every line contains just one word and its
number.  In addition, the program prints the number of sentences and
the distribution how many words the sentences contain. The name of the
output file is given either as a command line parameter or it is read
from stdin.

Use balanced binary trees as your data structure.


PARTICIPANTS
============

* Leo Honkanen 
* Juuso Hyvönen
* Miika Sirén

Division of labour
------------------

* Leo Honkanen: The actual word calculation function
* Juuso Hyvönen: Parsing parameters, small tool functions
* Miika Sirén: AVL Tree


HELP
====
Program structure
-----------------

### avl_test.c
    Tests the Tree functions
### avl_tree.c
    AVL Tree structure used for storing word counts
### avl_tree.h
    Headers for avl_tree.c
### functions.c
    Implementations of all the functions except AVL tree
### functions.h
    Headers for functions.c
### main.c
    Parses command line parameters.
    Calculates word counts.
    Outputs the counts.
    
Functions are commented in .h files except main() which is commented in main.c.    

How to use
----------

Name of the file to be processed is given either as a command line parameter or
it is read from stdin.

EXAMPLE './tkthjm coolfile.txt'

Output file is assumed to be stdout. It can also be specified as the
second command line parameter. 

EXAMPLE './tkthjm coolfile.txt coolout.txt'

If it is desired to output stdin input to a file, use explicit '-' to
signify stdin as the first argument.

EXAMPLE './tkthjm - coolout.txt'

Use -h flag for help.

EXAMPLE './tkthjm -h'

