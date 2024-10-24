#include<iostream>
using namespace std;
#include"head.h"
int main(){
   WorkerManager w_m;
   int n=0;
   while(true){
     w_m.SHOW_MENU();
   printf("Please enter a selection：");
    scanf("%d",&n);
     switch(n)
     {
    case 0:
        w_m.EXIT_SYSTEM();
        break;
    case 1:
        w_m.Add_Emp();
        break;
    case 2:
        w_m.Show_Emp();
        break;
    case 3:
        w_m.Del_Emp();
        break;
    case 4:
        w_m.Mod_Emp();
        break;
    case 5:
        w_m.File_Emp();
        break;
    case 6:
        w_m.Sort_Emp();
        break;
    case 7:
        w_m.Clean_File();
        break;
    default:
        system("cls");
        break;
     }
   }
}
