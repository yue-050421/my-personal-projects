#pragma once
/*
头文件 
*/
#include<iostream>
#include<conio.h> 
#include<fstream>            
#include<string>               
#include<vector>                
#include<cstdlib>   
#include<sstream>            
using namespace std;
//密码输入 
static void inputPassword(string &str, int size) 
{
    char c;
    int count = 0;
    char *password = new char[size]; 

    cout << "输入密码：" << endl;

    while ((c = getch()) != '\r') { 
        if (c == 8) { 
            if (count > 0) {
                putchar('\b'); 
                putchar(' ');  
                putchar('\b'); 
                count--;
            }
        } else if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9')) { 
            if (count < size - 1) { 
                putchar('*');  
                password[count] = c;
                count++;
            }
        }
    }

    password[count] = '\0'; 
    str = password;        
    delete[] password;      
    cout << endl;
}
