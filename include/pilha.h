
typedef struct ItemType{
    int Item;
    ItemType* NextItem;
}ItemType;
typedef struct{
    ItemType* DataStack;
    int TopStack;
    int SizeStack;
}Structure_Stack;

void Push (Structure_Stack * Stack, ItemType Element);
ItemType Pop (Structure_Stack * Stack);
int Top(Structure_Stack * Stack);
int Size(Structure_Stack * Stack);
void SetSize(Structure_Stack * Stack, int SizeStack);
int IsFull(Structure_Stack * Stack);
int IsEmpty(Structure_Stack * Stack);
Structure_Stack* CreateStack(int SizeStack);
void DestroyStack(Structure_Stack * Stack);