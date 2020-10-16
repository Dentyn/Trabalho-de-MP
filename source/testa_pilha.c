#include <gtest/gtest.h> // googletest header file
#include "pilha.h"

#define StackSizeNull 0
#define StackSizeNegative -10
#define StackSizePositive 20
#define StackElement 675

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv); 
    return RUN_ALL_TESTS();
}

TEST(Stack, CreateStackSizeNull) {
    Structure_Stack * stack = CreateStack(StackSizeNull);
    ASSERT_EQ(StackSizeNull, Size(stack));
    DestroyStack(stack);
}
TEST(Stack, CreateStackSizeNegative) {
    Structure_Stack * stack = CreateStack(StackSizeNegative);
    ASSERT_NE(StackSizeNegative, Size(stack));
    DestroyStack(stack);
}
TEST(Stack, CreateStackSizePositive) {
    Structure_Stack * stack = CreateStack(StackSizePositive);
    ASSERT_EQ(StackSizePositive, Size(stack));
    DestroyStack(stack);
}

TEST(Stack, PushEmptyStack) {
    Structure_Stack * stack = CreateStack(StackSizePositive);
    ItemType Element;
    Element.Item = StackElement;
    Push(stack, Element);
    EXPECT_FALSE(IsEmpty(stack));
    DestroyStack(stack);
}
TEST(Stack, PushFullStack) {
    Structure_Stack* stack = CreateStack(1);
    ItemType Element;
    Element.Item = 100;
    Push(stack, Element);
    Element.Item+=50;
    Push(stack, Element);
    EXPECT_NE(Element.Item, Pop(stack).Item);
    DestroyStack(stack);
}

TEST(Stack, PopEmptyStack) {
    Structure_Stack* stack = CreateStack(1);
    EXPECT_EQ(Top(stack),Pop(stack).Item);
    DestroyStack(stack);
}
TEST(Stack, PopFullStack) {
    Structure_Stack* stack = CreateStack(StackSizePositive);
    ItemType Element;
    Element.Item = StackElement;
    while(!IsFull(stack))
    {
       Element.Item += 5;
       Push(stack, Element);
    }
    EXPECT_EQ(Element.Item, Pop(stack).Item);
    DestroyStack(stack);
}

TEST(Stack, TopEmptyStack) {
    Structure_Stack* stack = CreateStack(StackSizePositive);
    EXPECT_TRUE(Top(stack));
    DestroyStack(stack);
}
TEST(Stack, TopFullStack) {
    Structure_Stack* stack = CreateStack(StackSizePositive);
    ItemType Element;
    Element.Item = StackElement;
    while(!IsFull(stack))
    {
       Push(stack, Element);
    }
    EXPECT_EQ(Size(stack)-1,Top(stack));
    DestroyStack(stack);
}

TEST(Stack, SizeStack) {
    Structure_Stack* stack = CreateStack(StackSizePositive);
    EXPECT_EQ(StackSizePositive, Size(stack));
    DestroyStack(stack);
}

TEST(Stack, SetSizeNegativeStack) {
    Structure_Stack* stack = CreateStack(StackSizePositive);
    EXPECT_EQ(StackSizePositive, Size(stack));
    SetSize(stack,StackSizeNegative);
    EXPECT_NE(StackSizeNegative, Size(stack));
    DestroyStack(stack);
}
TEST(Stack, SetSizePositiveStack) {
    Structure_Stack* stack = CreateStack(StackSizePositive);
    EXPECT_EQ(StackSizePositive, Size(stack));
    SetSize(stack,10);
    EXPECT_EQ(10, Size(stack));
    DestroyStack(stack);
}

TEST(Stack, IsFullStack) {
    Structure_Stack* stack = CreateStack(StackSizePositive);
    ItemType Element;
    Element.Item = StackElement;
    while(!IsFull(stack))
    {
       Push(stack, Element);
    }
    EXPECT_TRUE(IsFull(stack));
    DestroyStack(stack);
}
TEST(Stack, IsNotFullStack) {
    Structure_Stack* stack = CreateStack(StackSizePositive);
    ItemType Element;
    Element.Item = StackElement;
    while(!IsFull(stack))
    {
       Push(stack, Element);
    }
    Pop(stack);
    EXPECT_FALSE(IsFull(stack));
    DestroyStack(stack);
}

TEST(Stack, IsEmptyStack) {
    Structure_Stack* stack = CreateStack(StackSizePositive);
    EXPECT_TRUE(IsEmpty(stack));
    DestroyStack(stack);
}
TEST(Stack, IsNotEmptyStack) {
    Structure_Stack* stack = CreateStack(StackSizePositive);
    ItemType Element;
    Element.Item = StackElement;
    while(!IsFull(stack))
    {
       Push(stack, Element);
    }
    EXPECT_FALSE(IsEmpty(stack));
    DestroyStack(stack);
}

TEST(Stack, DestroyStack) {
    Structure_Stack* stack = CreateStack(StackSizePositive);
    DestroyStack(stack);
    EXPECT_TRUE(stack);
}