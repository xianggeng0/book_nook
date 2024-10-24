#pragma once
#include <iostream>
#include<string>
#define WM WorkerManager
using namespace std;
#include<fstream>
#define FILENAME "empFile.txt"
#define sI showInof
class Worker{
public:
    virtual void sI()=0;
    virtual string get_DeptN()=0;
    int m_Id;
    string m_Name;
    int m_DeptId;
};
class WM{
public:
   WM();
   void SHOW_MENU();
   void EXIT_SYSTEM();
   ~WM();
   Worker** m_EmpArray;
   int m_EmpNum;
   void Add_Emp();
   void save();
   bool m_File_Is_Empty;
   int get_EmpNum();
   void init_Emp();
   void Show_Emp();
   void Del_Emp();
   int Is_Exist(int id);
   void Mod_Emp();
   void File_Emp();
   void Sort_Emp();
   void Clean_File();
};

class Employee:public Worker{
    public:
    Employee(int ID,string NAME,int DID);
    /*virtual*/ void sI();
    /*virtual*/ string get_DeptN();
};
class Manager:public Worker{
    public:
   Manager(int ID,string NAME,int DID);
   /*virtual*/ void sI();
   /*virtual*/ string get_DeptN();
};
class Boss:public Worker{
    public:
   Boss(int ID,string NAME,int DID);
   /*virtual*/ void sI();
   /*virtual*/ string get_DeptN();
};
