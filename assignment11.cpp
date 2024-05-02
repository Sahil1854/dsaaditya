//assignment 11
#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;
class tel
 {
 public:
 int rollNo,roll1;
 char name[10];
 char div;
 char address[20];
 void accept()
 {
  cout<<"\n\tEnter Roll Number : ";
  cin>>rollNo;
  cout<<"\n\tEnter the Name : ";
  cin>>name;
  cout<<"\n\tEnter the Division:";
  cin>>div;
  cout<<"\n\tEnter the Address:";
  cin>>address;
 }
        void accept2()
        {
               cout<<"\n\tEnter the Roll No. to modify : ";
               cin>>rollNo;
        }
        void accept3()
        {
              cout<<"\n\tEnter the name to modify : ";
              cin>>name;
        }
        int getRollNo()
        {
         return rollNo;
        }
  void show()
  {

  cout<<"\n\t"<<rollNo<<"\t\t"<<name<<"\t\t"<<div<<"\t\t"<<address;
  }
};
int main()
{
 int i,n,ch,ch1,rec,start,count,add,n1,add2,start2,n2,y,a,b,on,oname,add3,start3,n3,y1,add4,start4,n4;
 char name[20],name2[20];
 tel t1;
 count=0;
 fstream g,f;
 do
 {
  cout<<"\n>>>>>>>>>>>>>>>>>>>>>>MENU<<<<<<<<<<<<<<<<<<<<";
  cout<<"\n1.Insert and overwrite\n2.Show\n3.Search & Edit(number)\n4.Search & Edit(name)\n5.Search & Edit(onlynumber)\n6.Search & edit(only name)\n 7.Delete a Student Record\n 8.Exit\n\tEnter the Choice\t:";
  cin>>ch;
  switch(ch)
  {
  case 1:
   f.open("StuRecord.txt",ios::out);
   x:t1.accept();
   f.write((char*) &t1,(sizeof(t1)));
   cout<<"\nDo you want to enter more records?\n1.Yes\n2.No";
   cin>>ch1;
    if(ch1==1)
     goto x;
    else
    {
     f.close();
     break;
    }

  case 2:
   f.open("StuRecord.txt",ios::in);
   f.read((char*) &t1,(sizeof(t1)));
   //cout<<"\n\tRoll No.\t\tName \t\t Division \t\t Address";
   while(f)
   {
    t1.show();
    f.read((char*) &t1,(sizeof(t1)));
   }
   f.close();
   break;
  case 3:
   cout<<"\nEnter the roll number you want to find";
   cin>>rec;
   f.open("StuRecord.txt",ios::in|ios::out);
   f.read((char*)&t1,(sizeof(t1)));
   while(f)
   {
    if(rec==t1.rollNo)
    {
     cout<<"\nRecord found";
     add=f.tellg();
     f.seekg(0,ios::beg);
           start=f.tellg();
     n1=(add-start)/(sizeof(t1));
     f.seekp((n1-1)*sizeof(t1),ios::beg);
     t1.accept();
     f.write((char*) &t1,(sizeof(t1)));
     f.close();
     count++;
     break;
    }
    f.read((char*)&t1,(sizeof(t1)));
       }
   if(count==0)
          cout<<"\nRecord not found";
   f.close();
   break;

  case 4:
    cout<<"\nEnter the name you want to find and edit";
    cin>>name;
   f.open("StuRecord.txt",ios::in|ios::out);
   f.read((char*)&t1,(sizeof(t1)));
   while(f)
   {
    y=(strcmp(name,t1.name));
    if(y==0)
    {
     cout<<"\nName found";
     add2=f.tellg();
     f.seekg(0,ios::beg);
     start2=f.tellg();
     n2=(add2-start2)/(sizeof(t1));
     f.seekp((n2-1)*sizeof(t1),ios::beg);
     t1.accept();
     f.write((char*) &t1,(sizeof(t1)));
     f.close();
     break;
    }
          f.read((char*)&t1,(sizeof(t1)));
   }
   break;
      case 5:
            cout<<"\n\tEnter the roll number you want to modify";
            cin>>on;
            f.open("StuRecord.txt",ios::in|ios::out);
            f.read((char*) &t1,(sizeof(t1)));
            while(f)
            {
              if(on==t1.rollNo)
              {
                cout<<"\n\tNumber found";
                add3=f.tellg();
                f.seekg(0,ios::beg);
                start3=f.tellg();
                n3=(add3-start3)/(sizeof(t1));
                f.seekp((n3-1)*(sizeof(t1)),ios::beg);
                t1.accept2();
                f.write((char*)&t1,(sizeof(t1)));
                f.close();
                break;
              }
              f.read((char*)&t1,(sizeof(t1)));
           }
           break;
      case 6:
            cout<<"\nEnter the name you want to find and edit";
    cin>>name2;
   f.open("StuRecord.txt",ios::in|ios::out);
   f.read((char*)&t1,(sizeof(t1)));
   while(f)
   {
    y1=(strcmp(name2,t1.name));
    if(y1==0)
    {
     cout<<"\nName found";
     add4=f.tellg();
     f.seekg(0,ios::beg);
     start4=f.tellg();
     n4=(add4-start4)/(sizeof(t1));
     f.seekp((n4-1)*sizeof(t1),ios::beg);
     t1.accept3();
     f.write((char*) &t1,(sizeof(t1)));
     f.close();
     break;
    }
          f.read((char*)&t1,(sizeof(t1)));
   }
   break;
    case 7:
      int roll;
      cout<<"Please Enter the Roll No. of Student Whose Info You Want to Delete: ";
     cin>>roll;
     f.open("StuRecord.txt",ios::in);
     g.open("temp.txt",ios::out);
     f.read((char *)&t1,sizeof(t1));
     while(!f.eof())
     {
        if (t1.getRollNo() != roll)
           g.write((char *)&t1,sizeof(t1));
         f.read((char *)&t1,sizeof(t1));
     }
    cout << "The record with the roll no. " << roll << " has been deleted " << endl;
     f.close();
     g.close();
     remove("StuRecord.txt");
     rename("temp.txt","StuRecord.txt");
      break;
    case 8:
       cout<<"\n\tThank you";
       break;
        }
  }while(ch!=8);
}
/*
It is one of the simple methods of file organization. Here each file/records are stored one 
after the other in a sequential manner. This can be achieved in two ways:
 Records are stored one after the other as they are inserted into the tables. This method is 
called pile file method. When a new record is inserted, it is placed at the end of the file. 
In the case of any modification or deletion of record, the record will be searched in the 
memory blocks. Once it is found, it will be marked for deleting and new block of record 
is entered

In the second method, records are sorted (either ascending or descending) each time they 
are inserted into the system. This method is called sorted file method. Sorting of records may be 
based on the primary key or on any other columns. Whenever a new record is inserted, it will be 
inserted at the end of the file and then it will sort – ascending or descending based on key value 
and placed at the correct position. In the case of update, it will update the record and then sort the 
file to place the updated record in the right place. Same is the case with delete.
read adv and disadv from manual.
This C++ program is a simple student record management system that allows users to insert, display, search, edit, and delete student records stored in a file.

It defines a class tel to represent student records with attributes like roll number, name, division, and address.
The program presents a menu-driven interface to perform various operations on student records such as insertion, display, search by roll number or name, editing, and deletion.
User input is accepted for each operation, and the program reads and writes records to a file named "StuRecord.txt".
Operations like search and edit are performed by reading and writing records from/to the file based on user input criteria.
Deletion of a record is accomplished by creating a temporary file, copying all records except the one to be deleted, and then renaming the temporary file to replace the original.
Overall, the program provides basic functionalities for managing student records efficiently.*/