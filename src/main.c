#include<stdio.h>
#include<stdlib.h>
#include"../inc/operations.h"

void mainMenu()
{
    printf("\n      ****** Stack operations ******");
    printf("\n\n 0-> Exit ");
    printf("\n 1-> Add node(PUSH)");
    printf("\n 2-> Modify node");
    printf("\n 3-> Search node");
    printf("\n 4-> Sort nodes ");
    printf("\n 5-> Delete node(POP) ");
    printf("\n 6-> Traverse ");
    printf("\n 7-> View stack details");
}

int main()
{
   StackInfo *stack=(StackInfo *)malloc(sizeof(StackInfo));
   //Stack *temp;
   char cont='n';
   int option;
   int key;
   Stack_init(stack);
  do
  {
    
    system("clear");

    mainMenu();

    printf("\n\n\t Enter your choice : "); 
    scanf("%d",&option);
 
    switch(option)
    {
       case 0: /* EXIT */
               break;
 
       case 1: /* Add a Node */
               addNode(stack);
               break;
    
       case 2: /* Modify a node */
               if(!(stack->top))
                 printf("\n Error: Stack is empty");            
               else
                modifyNode(stack);
               break; 
       
       case 3: /* Search for a Node */
               
               if(stack->top==NULL)
                 printf("\n Error: Stack is empty");
               else
               {
                 
                 printf("\n Enter the search value : "); 
                 scanf("%d",&key);             
                 key=searchNode(stack,key); 
           
                  if(key)
                    printf("\n Value found at position %d",key);
                  else
                    printf("\n Value not found");                
               } 
               break;

       case 4: /* Sort nodes */
               if(stack->top==NULL)
                 printf("\n Error: Stack is empty");  
               else  
                 sortNodes(stack);
               //option/=0;                                         // CRASH introduced
               break;
  
       case 5: /* Delete a node */
               if(stack->top==NULL)
                printf("\n Error: Stack is empty");
               else
                deleteNode(stack);
               
               break;

       case 6: /*  Traverse stack  */
                 traverse(stack->top);
                
                 
                  break; 
 
       case 7: /*   View stack details */
                system("clear");
                printf("\n Stack top : %p",stack->top);
                printf("\n Stack size : %d",stack->size);
                printf("\n Minimum value : %d",stack->minval);
                printf("\n Maximum value : %d",stack->maxval);
                getchar();
                break;

       default: printf("\n Invalid option entered "); 
                break;                            
    }
    getchar();
    
   if(option==0)
   {
     printf("\n\n Sure to exit? (y/n)");
     scanf("%c",&cont);
     getchar();
     system("clear");
   } 
   
  }while(cont!='y'); 
 
  if((stack->top)!=NULL)
  {
    clearStack(stack);                           // memory cleanup before exiting program
    free(stack); 
  }
  return 0;
}
