#include<stdio.h>
#include<stdlib.h>
#include"../inc/operations.h"

/*

  typedef struct stack{
   int value;
   struct stack* next;
  } Stack;


  typedef struct Sinfo{
   Stack *top;
   int size;
   int maxval,minval;
  } StackInfo;


*/

/***********       Function Definitions         *************/

                                                   /*  STACK INIT          */
void Stack_init(StackInfo *stk)
{
    stk->top=NULL;
    stk->size=0;
    stk->minval=0;
    stk->maxval=0;
}

                                       /*      UPDATE MINIMUM VALUE      */
void updateMinVal(StackInfo *stk){

  Stack *temp;  
  int min;
  
 if(stk->size>=1) { 

   	temp=stk->top;
   	min=temp->value;
        temp=temp->next;

  	while(temp!=NULL)
  	{
      	  if(temp->value < min)
          min=temp->value;
  
         temp=temp->next;
        } 
 
	  stk->minval=min;
 }
 else
 {
    stk->minval=0;    
 }
 
}

                                       /*   UPDATE MAXIMUM VALUE */
void updateMaxVal(StackInfo *stk){             

  Stack *temp;
  int max;

  if(stk->size>=1) {

          temp=stk->top;
          max=temp->value;
	  temp=temp->next;
 
	  while(temp!=NULL)
	  {
      		if(temp->value > max)
        	max=temp->value;

	       temp=temp->next;
	  } 

	  stk->maxval=max;
  }
  else
  {
      stk->maxval=0;
  }
}


void clearStack(StackInfo* stk)                       /*   CLEAR STACK -> deletes the entire stack   */
{
   Stack* temp;
   while(stk->top!=NULL)
   {
     temp=stk->top;
     stk->top=stk->top->next;
     free(temp);    
   }
   
}

                                                   /*             ADD NODE     */
void addNode(StackInfo *stk )
{
   Stack *temp=(Stack*)malloc(sizeof(Stack));
   int val;
   temp->next=stk->top;
   stk->top=temp;

   printf("\n\n Enter the value of node : ");
   scanf("%d",&(val));   
  
   (stk->size)++;
    temp->value=val;
   if(stk->size == 1)
   {
       stk->minval=stk->maxval=val;
   }
   else
   {
   	if(stk->minval >= val)
      	  stk->minval = val;

   	if(stk->maxval <= val)
          stk->maxval = val;
   }
    
//printf("\n Stack top : %p",stk->top);
 // getchar();
}


                                               /*          SEARCH NODE        */
int searchNode(StackInfo *stk,int key)
{
   Stack *temp=stk->top;
   int count=1,found=0;
  //	printf("\n Stack top : %p",stk->top);
  if(key<=stk->maxval && key>=stk->minval)
   while(temp!=NULL && !found)
   {
       if(temp->value==key)
       {
          found=1;        
          
       }
       else
       {
         temp=temp->next;
         count++;
       }
   }     
   
   getchar();
   if(1==found)
     return count;             
   else
     return 0;                  // if not found, return 0
}


                                        /*             MODIFY NODE            */
void modifyNode(StackInfo *stk)
{
   Stack* temp=stk->top;
   int key;
  // printf("\n Stack top : %p",stk->top);
   printf("\n\n Enter the search value : ");
   scanf("%d",&key);

   int pos=searchNode(stk,key);
   
   if(pos)
   {
       while(pos>1)
       {  
           temp=temp->next;
           pos--;
       }

      printf("\n Enter the new value : ");
      scanf("%d",&key);
 
  
    if(stk->minval > key)
      stk->minval = key;

    if(stk->maxval < key)
      stk->maxval = key;

      (temp->value)=key;
      printf("\n Value modified successfully "); 

     updateMinVal(stk);
     updateMaxVal(stk);     
   }
   else
   {
      printf("\n Value not found in Stack");  
   }
   
     updateMinVal(stk);
     updateMaxVal(stk);

 getchar();
}

                                               /*          SORT NODES           */
void sortNodes(StackInfo *stk)
{
   Stack *cur=stk->top,*temp=cur->next;  
   int swap;
   char order;
   getchar();
   printf("\n Ascending/Descending (a/d) ?");
   scanf("%c",&order);
 
    while(cur->next!=NULL)
    {
        while(temp!=NULL)
        {
           if('a'==order)                                   // ASCENDING ORDER    
            {
               if(cur->value > temp->value)
               {
                   swap=(cur->value);
                   (cur->value)=(temp->value);
                   (temp->value) = swap;                           // swap
               } 
            }
           else						   // DESCENDING ORDER	
            {
               if(cur->value < temp->value)
               {
                   swap=(cur->value);
                   (cur->value)=(temp->value);
                   (temp->value) = swap;                           // swap
               }  
            }           
          temp=temp->next;
        }
        cur=cur->next;
        temp=cur->next;
    }
    traverse(stk->top);
  
}

                                        /*            DELETE NODE              */
void deleteNode(StackInfo *stk)
{

  Stack *temp=stk->top,*temp2=NULL; 
   int key;
 // printf("\n Stack top : %p",stk->top);
   printf("\n\n Enter the search value(to be deleted) : ");
   scanf("%d",&key);

   int pos=searchNode(stk,key);
   
   if(pos!=0)
   {
      if(pos==1)
      {
         stk->top = temp->next;
         free(temp); 
         (stk->size)--;
      }
      else
      {
         while(--pos>0)
         {  
             temp2=temp;
             temp=temp->next;
             //pos--;
         }

        temp2->next=temp->next;
        free(temp);
        (stk->size)--;  
      }
      printf("\n Value deleted successfully "); 
  
     updateMinVal(stk);
     updateMaxVal(stk);     
   }
   else
   {
      printf("\n Value not found in Stack");  
   }
 
}

                                               //             TRAVERSE           //
void traverse(Stack *top)
{
  
   printf("\n ****STACK**** \n");
   //printf("\n Stack top : %p\n\n",top);
  while(top!=NULL)
   { 
       printf("%d",(top->value)); 

       if(top->next != NULL)
           printf("->");

       top=top->next;
     //  printf("\n %p",top);           
   }
    getchar();

}  
