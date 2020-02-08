//
//  main.cpp
//  顺序栈
//
//  Created by WuTao on 2020/2/1.
//  Copyright © 2020 WuTao. All rights reserved.
//
#include "SqStack.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main(int argc, const char * argv[])
{
    string filepath = "/Users/WuTao/数据结构考研复习/栈和队列/栈/顺序栈/顺序栈/input.txt";
    fstream inFile;
    inFile.open(filepath,ios::in);
    if (!inFile)
    {
        cout << "文件打开错误" << endl;
        return 0;
    }
    char str[256];
    inFile >> str;
    cout << str << endl;
    inFile.close();
    int length = 0;
    while(str[length] != '\0')
    {
        length++;
    }
    if (bracketCheck(str, length))
    {
        cout << "匹配成功" << endl;
    }
    else
    {
        cout << "匹配失败" << endl;
    }
    return 0;
}
