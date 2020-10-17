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

