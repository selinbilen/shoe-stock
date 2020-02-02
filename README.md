Scenario:
Suppose you run a shoe shop and you want to write a stock tracking program for the shoes in the
shop. Design and implement a stock tracking program based on a linked list structure to keep
your stock information.

WORKFLOW:

1. You will read the input.txt. The positive numbers are the sizes of pair of shoes you are
getting into your stock this morning. First, you will add them to your stock following the
rules:
a. Your stock will be a linked list in a struct form, containing 2 parameters (shoe size
and quantity).
b. The linked list will be in increasing order with respect to shoe size.
c. If the pair of shoe you are adding is not in the list, you will create a node in a
proper space and set the quantity of this pair of shoe as 1.
d. If the pair of shoe you are adding is in the list, you will increment it’s quantity by 1.

2. The negative numbers are the customers wanting a shoe in specified size. You will sell
those shoes following the rules:
a. If there are more than 1 pair of shoes of that size, you will decrease the quantity
of that size of pair of shoe by 1.
b. If there is only 1 pair of shoe of that size, you will delete the node of that pair of
shoe from the linked list.
c. If there is no pair of shoe of that size, the program will print out the message
“NO_STOCK”

3. Zero (0) is the command for the printing the stock info. You will print out the remaining
stock following the format: “<size>:<quantity>\n”. Example:
36:2
38:1
40:3
41:1
	
4. At the end, you need to delete all of the nodes of your list to free up the space.
	
Example:
Input file “input.txt”
36 41 45 38 35 37 45 42 40 36
-35 -40 -36 -35 -38
0
-35 -41
0
	
Output
NO_STOCK
36:1
37:1
41:1
42:1
45:2
NO_STOCK
36:1
37:1
42:1
45:2

Implementation: Implement the following methods with appropriate arguments and return types for your structure:
create(): Creates the stock list.
add_stock(): Adds a pair of shoe to the stock list. (workflow 1)
sell(): Sells a pair of shoe. (workflow 2)
current_stock(): Prints the current stock list. (workflow 3)
clear(): Deletes all of the nodes of the list. (workflow 4)

STRUCTURE: 
struct node{
int size;
int quant;
node *next;
};
struct stock{
node *head;
void create();
void add_stock(int);
void sell(int);
void current_stock();
void clear();
};
