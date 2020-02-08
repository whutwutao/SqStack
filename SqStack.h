#ifndef SqStack_h
#define SqStack_h
#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 50

typedef struct
{
    char data[MAXSIZE];
    int top;
}SqStack;

//初始化
void InitStack(SqStack &S)
{
    S.top = -1;
}

//判空
bool StackEmpty(SqStack S)
{
    if (S.top == -1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

//进栈
bool Push(SqStack &S, char x)
{
    if (S.top == MAXSIZE - 1)//栈已满
    {
        return false;
    }
    else
    {
        S.data[++S.top] = x;
        return true;
    }
}

//出栈
bool Pop(SqStack &S, char &x)
{
    if (S.top == -1)//栈为空
    {
        return false;
    }
    else
    {
        x = S.data[S.top--];
        return true;
    }
}

//获取栈顶元素
bool GetTop(SqStack S, char &x)
{
    if (S.top == -1)
    {
        return false;
    }
    else
    {
        x = S.data[S.top];
        return true;
    }
}


//括号匹配
bool bracketCheck(char str[], int length)
{
    SqStack S;
    InitStack(S);
    for (int i = 0; i < length; i++)
    {
        if (str[i] == '(' || str[i] == '[' || str[i] == '{')
        {
            Push(S,str[i]);//扫描到左括号则进栈
        }
        //扫描到右括号则进行匹配
        else if (str[i] == ')' || str[i] == ']' || str[i] == '}')
        {
            if (StackEmpty(S))
            {
                return false;//栈空则匹配失败
            }
            else
            {
                char elemTop;
                Pop(S,elemTop);//栈顶括号出栈
                if (elemTop != '(' && str[i] == ')')
                {
                    return false;
                }
                if (elemTop != '[' && str[i] == ']')
                {
                    return false;
                }
                if (elemTop != '{' && str[i] == '}')
                {
                    return false;
                }
            }
        }
        else
        {
            //如果不是括号则什么也不做
        }
    }
    return StackEmpty(S);//若最后栈空则匹配成功
}



#endif /* SqStack_h */
