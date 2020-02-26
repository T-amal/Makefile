/*       Structure definitions     */

typedef struct stack{
 int value;
 struct stack* next;
} Stack;

typedef struct Sinfo{
 Stack *top;
 int size;
 int maxval,minval;

} StackInfo;

extern void Stack_init(StackInfo *stk);

extern void clearStack(StackInfo* stk);

extern void addNode(StackInfo* stk);

extern int searchNode(StackInfo* stk,int key);

extern void modifyNode(StackInfo* stk);

extern void sortNodes(StackInfo* top);

extern void deleteNode(StackInfo* top);

extern void traverse(Stack *top);
