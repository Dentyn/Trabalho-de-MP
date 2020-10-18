#include <stdlib.h>
#include "pilha.h"

#define EMPTY -1

/*-----------------------STACK-ARRAY--------------------------------*/
void Push (Structure_Stack * Stack, ItemType Element)
{
    if(!IsFull(Stack))
        Stack->DataStack[++Stack->TopStack] = Element;
}

ItemType Pop(Structure_Stack * Stack)
{
    if(!IsEmpty(Stack))
    {
        return Stack->DataStack[Stack->TopStack--];
    }
    ItemType error;
    error.Item = -1;
    return error;
}

int Top(Structure_Stack * Stack)
{
    return Stack->TopStack;
}

int Size(Structure_Stack * Stack)
{
    return Stack->SizeStack;
}

void SetSize(Structure_Stack * Stack, int SizeStack)
{
    if(SizeStack > EMPTY)
    {
        Stack->DataStack = (ItemType *)realloc(Stack->DataStack, SizeStack*sizeof(ItemType));
        Stack->SizeStack = SizeStack;
    }
}

int IsFull(Structure_Stack * Stack)
{
    return Top(Stack) == Size(Stack)-1;
}

int IsEmpty(Structure_Stack * Stack)
{
    return Top(Stack) == EMPTY;
}

Structure_Stack* CreateStack(int SizeStack)
{
    if(SizeStack < 0)
        SizeStack = 0;
    Structure_Stack* stack = (Structure_Stack *) malloc(sizeof(Structure_Stack));
    stack->DataStack = (ItemType *) malloc(SizeStack*sizeof(ItemType));
    stack->TopStack = EMPTY;
    stack->SizeStack = SizeStack;
    return stack;
}

void DestroyStack(Structure_Stack * Stack)
{
    free(Stack->DataStack);
    free(Stack);
}
/*------------------------------------------------------------------------*/
/*-----------------------STACK-LINKED-LIST--------------------------------*/
/*void Push (Structure_Stack * Stack, ItemType Element)
{
    if(!IsFull(Stack))
    {
        ItemType* ElementSupport = (ItemType *) malloc(sizeof(ItemType));
        ElementSupport->Item = Element.Item;
        ElementSupport->NextItem = Stack->DataStack;
        Stack->DataStack = ElementSupport;
        Stack->TopStack+=1;
    }
}

ItemType Pop(Structure_Stack * Stack)
{
    ItemType* ElementSupport;
    ItemType Value;
    if(!IsEmpty(Stack))
    {
        ElementSupport = Stack->DataStack;
        Value.Item = ElementSupport->Item;
        Stack->DataStack = ElementSupport->NextItem;
        free(ElementSupport);
        Stack->TopStack-=1;
        return Value;
    }
    Value.Item = -1;
    return Value;
}

int Top(Structure_Stack * Stack)
{
    return Stack->TopStack;
}

int Size(Structure_Stack * Stack)
{
    return Stack->SizeStack;
}

void SetSize(Structure_Stack * Stack, int SizeStack)
{
    if(SizeStack > EMPTY)
    {
        Stack->SizeStack = SizeStack;
    }
}

int IsFull(Structure_Stack * Stack)
{
    return Top(Stack) == Size(Stack)-1;
}

int IsEmpty(Structure_Stack * Stack)
{
    return Stack->DataStack == NULL;
}

Structure_Stack* CreateStack(int SizeStack)
{
    if(SizeStack < 0)
        SizeStack = 0;
    Structure_Stack* stack = (Structure_Stack *) malloc(sizeof(Structure_Stack));
    stack->DataStack = (ItemType *) malloc(sizeof(ItemType));
    stack->DataStack = NULL;
    stack->TopStack = EMPTY;
    stack->SizeStack = SizeStack;
    return stack;
}

void DestroyStack(Structure_Stack * Stack)
{
    ItemType* Element, *ElementSupport;
    ElementSupport = Stack->DataStack;
    
    while(ElementSupport != NULL){
        Element = ElementSupport->NextItem;
        free(ElementSupport);
        ElementSupport = Element;
    }
    free(Stack);
}

/*------------------------------------------------------------------------*/
