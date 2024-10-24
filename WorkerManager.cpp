#include"head.h"
#define WM WorkerManager
#define Mg Manager
#define sI showInof
Employee::Employee(int ID,string NAME,int DID){
 this->m_Id=ID;
 this->m_Name=NAME;
 this->m_DeptId=DID;
}
void Employee::sI(){
 cout<<"Employee's number："<<this->m_Id
      <<"\tName of employee："<<this->m_Name
      <<"\tpostion："<<this->get_DeptN()
      <<"\tduty：Complete the tasks assigned by the manager"<<endl;
}
string Employee::get_DeptN(){
   return string("employee");
}
Mg::Mg(int ID,string NAME,int DID){
 this->m_Id=ID;
 this->m_Name=NAME;
 this->m_DeptId=DID;
}
void Mg::sI(){
 cout<<"Employee's number："<<this->m_Id
      <<"\tName of employee："<<this->m_Name
      <<"\tpostion："<<this->get_DeptN()
      <<"\tduty：Complete the tasks assigned by the boss"<<endl;
}
string Mg::get_DeptN(){
   return string("manager");
}
Boss::Boss(int ID,string NAME,int DID){
 this->m_Id=ID;
 this->m_Name=NAME;
 this->m_DeptId=DID;
}
void Boss::sI(){
 cout<<"Employee's number："<<this->m_Id
      <<"\tName of employee："<<this->m_Name
      <<"\tposition："<<this->get_DeptN()
      <<"\tduty：Management of all affairs of the company"<<endl;
}
string Boss::get_DeptN(){
   return string("boss");
}
WM::WM(){
    ifstream ifs;
    ifs.open(FILENAME,ios::in);
    if(ifs.is_open()==NULL){
        printf("The file does not exist!\n");
        this->m_EmpNum=0;
        this->m_EmpArray=NULL;
        this->m_File_Is_Empty=true;
        ifs.close();
        return;
    }
    char ch;
    ifs>>ch;
    if(ifs.eof()){
        printf("The file is empty!\n");
        this->m_EmpNum=0;
        this->m_EmpArray=NULL;
        this->m_File_Is_Empty=true;
        ifs.close();
        return;
    }
    int num=this->get_EmpNum();
    this->m_EmpNum=num;
    this->m_EmpArray=new Worker*[this->m_EmpNum];
    this->init_Emp();
}
void WM::SHOW_MENU(){
    printf( "Welcome to the employee management systom!\n" );
    printf( "0. Exit the management program\n");
    printf( "1. Add employee information\n" );
    printf( "2. Display employee information\n" );
    printf( "3. Delete job-hopping employees\n" );
    printf( "4. Modify employee information\n" );
    printf( "5. Find employee information\n" );
    printf( "6. Sort by number\n" );
    printf( "7. Clear all documentsy\n" );
    cout <<endl;
}
void WM::EXIT_SYSTEM(){
  cout<<"Welcome to use next time【~v~】"<<endl;
  system("pause");
  exit(1);
}
void WM::Add_Emp(){
  cout<<"Please enter the number of added employees："<<endl;
  int ADDNUM=0;
  cin>>ADDNUM;
  if(ADDNUM>0){
    int new_Size=this->m_EmpNum+ADDNUM;
    Worker **new_Space=new Worker*[new_Size];
    if(this->m_EmpArray!=0){
        for(int j=0;j<this->m_EmpNum;j++){
            new_Space[j]=this->m_EmpArray[j];
        }
    }
    for(int i=0;i<ADDNUM;i++){
        int id;
        string name;
        int a;
       printf("Please enter the number of %d employees\n",i+1);
       cin>>id;
       printf("Please enter the name of employees\n");
       cin>>name;
       cout<<"Please select an employee position："<<endl;
       cout<<"1.Ordinary staff"<<endl;
       cout<<"2.Manager"<<endl;
       cout<<"3.Boss"<<endl;
       cin>>a;
       Worker* worker=NULL;
       switch(a){
     case 1:
        worker=new Employee(id,name,1);
        break;
     case 2:
        worker=new Mg(id,name,2);
        break;
     case 3:
        worker=new Boss(id,name,3);
        break;
     default:
        break;
       }
       new_Space[this->m_EmpNum+i]=worker;
    }
    delete[]this->m_EmpArray;
    this->m_EmpArray=new_Space;
    this->m_EmpNum=new_Size;
    this->m_File_Is_Empty=false;
    cout<<"Successfully added"<<ADDNUM<<"employ"<<endl;
    this->save();
  }
  else{
    cout<<"Incorrect input data（~-~）"<<endl;
  }
  system("pause");
  system("cls");
}
void WM::save(){
  ofstream ofs;
  ofs.open(FILENAME,ios::out);
  for(int j=0;j<this->m_EmpNum;j++){
    ofs<<this->m_EmpArray[j]->m_Id<<" "
       <<this->m_EmpArray[j]->m_Name<<" "
       <<this->m_EmpArray[j]->m_DeptId<<endl;
  }
  ofs.close();
}
int WM::get_EmpNum(){
  ifstream ifs;
  ifs.open(FILENAME,ios::in);
  int _ID;
  string _NAME;
  int _DID;
  int n=0;
  while(ifs>>_ID&&ifs>>_NAME&&ifs>>_DID){
    n++;
  }
  return n;
}
void WM::init_Emp(){
    ifstream ifs;
    ifs.open(FILENAME,ios::in);
    int ID;
    string NAME;
    int DID;
    int a=0;
    while(ifs>>ID&&ifs>>NAME&&ifs>>DID){
        Worker* worker=NULL;
    if(DID==1){
        worker=new Employee(ID,NAME,DID);
        }
    if(DID==2){
        worker=new Mg(ID,NAME,DID);
        }
    if(DID==3){
        worker=new Boss(ID,NAME,DID);
    }
    this->m_EmpArray[a]=worker;
    a++;
    }
    ifs.close();
}
void WM::Show_Emp(){
    if(this->m_File_Is_Empty){
        cout<<"The file does not exist or is empty|~@~|"<<endl;
    }
    else
    {
        for(int i=0;i<m_EmpNum;i++){
            this->m_EmpArray[i]->sI();
        }
    }
    system("pause");
    system("cls");
}
void WM:: Del_Emp(){
   if(this->m_File_Is_Empty==true){
    cout<<"The file does not exist or is empty"<<endl;
   }
   if(this->m_File_Is_Empty==false){
    cout<<"Please enter the employee you want to delete："<<endl;
    int a=0;
    cin>>a;
    long x=this->Is_Exist(a);
    if(x!=-1){
        for(long i=x;i<this->m_EmpNum-1;i++){
            this->m_EmpArray[i]=this->m_EmpArray[i+1];
        }
        this->m_EmpNum-=this->m_EmpNum;
        cout<<"Delete succeeded^w^"<<endl;
        this->save();
    }
    else{
        cout<<"Failed to delete.The employee was not found[-m-]"<<endl;
    }
   }
   system("pause");
   system("cls");
}
int WM::Is_Exist(int id){
   int x=-1;
   for(int i=0;i<this->m_EmpNum;i++){
     if(this->m_EmpArray[i]->m_Id==id)
     {
         x=i;
         break;
     }
   }
   return x;
}
void WM::Mod_Emp(){
    if(this->m_File_Is_Empty==true){
        cout<<"The file does not exist or is empty!"<<endl;
    }
    else{
        cout<<"Please enter the number of the modified employee："<<endl;
        int id;
        cin>>id;
        int ret=this->Is_Exist(id);
        if(ret!=-1){
            delete this->m_EmpArray[ret];
            int new_id=0;
            string new_name="";
            int d_Select=0;
            cout<<"Find NO."<<id<<"staff,Please enter a new number："<<endl;
            cin>>new_id;
            cout<<"Please enter a new name："<<endl;
            cin>>new_name;
            cout<<"Please enter a new post："<<endl;
            cout<<"Please select an employee position："<<endl;
            cout<<"1.Ordinary staff"<<endl;
            cout<<"2.Manager"<<endl;
            cout<<"3.Boss"<<endl;
            cin>>d_Select;
            Worker *worker=NULL;
    switch(d_Select)
     {
    case 1:
        worker=new Employee(new_id,new_name,d_Select);
        break;
    case 2:
         worker=new Mg(new_id,new_name,d_Select);
        break;
    case 3:
         worker=new Boss(new_id,new_name,d_Select);
        break;
    default:
        break;
     }
     this->m_EmpArray[ret]=worker;
     cout<<"Modified successfully！"<<endl;
     this->save();
        }
        else{
            cout<<"Search failed. There is no such person（ >_< ）"<<endl;
        }
    }
    system("pause");
    system("cls");
}
void WM::File_Emp(){
   if(this->m_File_Is_Empty){
    cout<<"The file does not exist or is empty！"<<endl;
   }
   else{
    cout<<"Please enter the search method："<<endl;
    cout<<"1.Search by employee number"<<endl;
    cout<<"2.Search by employee name"<<endl;
    int select=0;
    cin>>select;
    if(select==1){
        int id;
        cout<<"Please enter the employee number to search："<<endl;
        cin>>id;
        int ret=Is_Exist(id);
        if(ret!=-1){
            cout<<"Search succeeded. The employee information is as follows："<<endl;
            this->m_EmpArray[ret]->sI();
        }
        if(ret==-1){
            cout<<"Search failed. There is no such person."<<endl;
        }
    }
        if(select==2){
        string name;
        bool flag=false;
        cout<<"Please enter the search name："<<endl;
        cin>>name;
        for(int i=0;i<m_EmpNum;i++){
            if(this->m_EmpArray[i]->m_Name==name){
            cout<<"Search succeeded, employee number is："<<this->m_EmpArray[i]->m_Id<<"Employee information is as follows："<<endl;
            flag=true;
            this->m_EmpArray[i]->sI();
            }
        }
        if(flag=false){
            cout<<"Search failed. There is no such person."<<endl;
        }
    }
    else{
        cout<<"Wrong input option！"<<endl;
    }
   }
   system("pause");
    system("cls");
}
void WM::Sort_Emp(){
    if(this->m_File_Is_Empty){
        cout<<"The file does not exist or is empty!"<<endl;
        system("pause");
        system("cls");
    }
    else{
        cout<<"Please select sorting method："<<endl;
        cout<<"1.Sort in ascending order by employee number"<<endl;
        cout<<"2.Sort by employee number in descending order"<<endl;
        int x=0;
        cin>>x;
        for(int i=0;i<m_EmpNum-1;i++){
        for(int j=0;j<m_EmpNum-i-1;j++){
         if(x==1){
            if(this->m_EmpArray[j]->m_Id>this->m_EmpArray[j+1]->m_Id)
                {
                    Worker* t=this->m_EmpArray[j];
                        this->m_EmpArray[j]=this->m_EmpArray[j+1];
                        this->m_EmpArray[j+1]=t;
                    }
                }
            if(x==2){
                if(this->m_EmpArray[j]->m_Id<this->m_EmpArray[j+1]->m_Id)
                {
                    Worker* t1=this->m_EmpArray[j];
                        this->m_EmpArray[j]=this->m_EmpArray[j+1];
                        this->m_EmpArray[j+1]=t1;
                    }
            }
         }
        }
         cout<<"success！"<<endl;
                    this->save();
                    this->Show_Emp();
        }
    }
void WM::Clean_File(){
     cout<<"Are you sure?"<<endl;
     cout<<"1.OK!"<<endl;
     cout<<"2.NO!"<<endl;
     int a=0;
     cin>>a;
     if(a==1)
     {
         ofstream ofs(FILENAME,ios::trunc);
         ofs.close();
         if(this->m_EmpArray!=NULL){
        for(int i=0;i<this->m_EmpNum;i++){
            if(this->m_EmpArray[i]!=NULL){
                delete this->m_EmpArray[i];
            }
        }
    delete[]this->m_EmpArray;
    this->m_EmpArray=NULL;
    this->m_EmpNum=0;
    this->m_File_Is_Empty=true;
   }
   cout<<"Clear about success！"<<endl;
  }
  system("pause");
    system("cls");
}
WM::~WM()
{
if(this->m_EmpArray!=NULL)
    {
        for(int i=0;i<this->m_EmpNum;i++)
        {
            if(this->m_EmpArray[i]!=NULL)
            {
                delete this->m_EmpArray[i];
            }
        }
    delete[]this->m_EmpArray;
    this->m_EmpArray=NULL;
}
}
