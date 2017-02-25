
struct node
{
   int data;
   node * next;
};

int length(node * head);
void push(node *& head, int newData);
int pop(node *& head);
void pushBack(node *& head, int newData);
void pushBackV2(node *& head, int newData);

void print(node * head);
void del(node *& head);
void delNode(node * Node);

node * buildOneTwoThree();
void buildSpecial();

int getNth(node * head, int index);
void insertNth(node *& head, int index, int data);
int getNthLast(node * head, int index);

void sortedInsert(node *& head, node * newNode);
void insertSort(node *& head);

void append(node *& a, node *& b);
void frontBackSplit(node * source, node *& front, node *& back);
void removeDuplicates(node * head);
void moveNode(node *& dest, node *& source);
void alternatingSplit(node * source, node *& a, node *& b);
node * shuffleMerge(node * a, node * b);

node * sortedMerge(node * a, node * b);
void mergeSort(node *& head);

node * sortedIntersect(node * a, node * b);

void reverse(node *& head);
void recursiveReverse(node *& head);

void pairwiseSwap(node * head);

void basicCaller();
void test1();
void test2();
void test3();
void test4();
void test5();
