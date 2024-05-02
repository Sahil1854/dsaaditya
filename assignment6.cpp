//ASSIGNMENT 6
#include<iostream>
#include<stdlib.h>
#include<string.h>
using namespace std;
struct node
{   string vertex;
    int time;
    node *next;
};    
class adjmatlist
{    int m[10][10],n,i,j; char ch;  string v[20];   node *head[20];  node *temp=NULL;

     public:
     adjmatlist()
     {      for(i=0;i<20;i++)
            {    head[i]=NULL;  }
     }           
     void getgraph();
     void adjlist();
  
     void displaym();
     void displaya();
};
void adjmatlist::getgraph()
{
   cout<<"\n enter no. of cities(max. 20)";
   cin>>n;
   cout<<"\n enter name of cities";
   for(i=0;i<n;i++)
     cin>>v[i];          
   for(i=0;i<n;i++)
   {  
      for(j=0;j<n;j++)
      {  cout<<"\n if path is present between city "<<v[i]<<" and "<<v[j]<<" then press enter y otherwise n";  
         cin>>ch;
         if(ch=='y')
         {  
           cout<<"\n enter time required to reach city "<<v[j]<<" from "<<v[i]<<" in minutes";
           cin>>m[i][j];
         }
         else if(ch=='n')
         {  m[i][j]=0;  }
         else
         { cout<<"\n unknown entry";  }
      }
   }        
      adjlist();
         
}
void adjmatlist::adjlist()
{      cout<<"\n ****";
       for(i=0;i<n;i++)
       {  node *p=new(struct node);
          p->next=NULL;
          p->vertex=v[i];    
          head[i]=p;      cout<<"\n"<<head[i]->vertex;
       }
      
       for(i=0;i<n;i++)
       {  for(j=0;j<n;j++)
          {
                   if(m[i][j]!=0)
                   {       
                         node *p=new(struct node);
                         p->vertex=v[j];
                         p->time=m[i][j];
                         p->next=NULL;
                         if(head[i]->next==NULL)
                         {  head[i]->next=p;   }
                         else
                         {  temp=head[i];
                         while(temp->next!=NULL)
                         {   temp=temp->next;  }
                             temp->next=p;
                         }

                   }

          }
       }   
      
}
void adjmatlist::displaym()
{    cout<<"\n";
     for(j=0;j<n;j++)
     {  cout<<"\t"<<v[j];  }

     for(i=0;i<n;i++)
     {  cout<<"\n "<<v[i];
        for(j=0;j<n;j++)
        {   cout<<"\t"<<m[i][j];
        }
            cout<<"\n";
     }
}    
void adjmatlist::displaya()
{      
       cout<<"\n adjacency list is";
      
       for(i=0;i<n;i++)
       {  
                  
              
                         if(head[i]==NULL)
                         {   cout<<"\n adjacency list not present";  break;   }
                         else
                         {  
                            cout<<"\n"<<head[i]->vertex;
                         temp=head[i]->next;
                         while(temp!=NULL)
                         {  cout<<"-> "<<temp->vertex;
                            temp=temp->next;  }
                             
                         }

                   

          
       }
      
         cout<<"\n path and time required to reach cities is";
        
       for(i=0;i<n;i++)
       {  
                  
              
                         if(head[i]==NULL)
                         {   cout<<"\n adjacency list not present";  break;   }
                         else
                         {  
                            
                         temp=head[i]->next;
                         while(temp!=NULL)
                         {  cout<<"\n"<<head[i]->vertex;
                            cout<<"-> "<<temp->vertex<<"\n   [time required: "<<temp->time<<" min ]";
                            temp=temp->next;  }
                             
                         }

                   

          
       }
}
int main()
{  int m;    
   adjmatlist a;

   while(1)
   {
   cout<<"\n\n enter the choice";
   cout<<"\n 1.enter graph";
   cout<<"\n 2.display adjacency matrix for cities";
   cout<<"\n 3.display adjacency list for cities";
   cout<<"\n 4.exit";
   cin>>m;
   
        switch(m)
       {              case 1: a.getgraph();
                                    break;
                     case 2: a.displaym();
                                   break;
                           
                           case 3: a.displaya();
                                   break;
                            case 4: exit(0);
                 
                            default:  cout<<"\n unknown choice";
         }
    }
    return 0;
}                        
/*Graph is a non-linear data structure consisting of vertices and edges.a Graph is composed of a set of vertices( V ) and a set of edges( E ). 
The graph is denoted by G(V, E).

An undirected graph is a set of nodes and a set of links between the nodes. 
 Each node is called a vertex, each link is called an edge, and each edge connects two 
vertices.
 The order of the two connected vertices is unimportant.
 An undirected graph is a finite set of vertices together with a finite set of edges. Both sets 
might be empty, which is called the empty graph.


A graph can be represented in mainly two ways. They are: 
Adjacency List: An Adjacency list is an array consisting of the address of all the linked lists. The first node of the linked list represents the vertex and the remaining lists connected to this node represents the vertices to which this node is connected. 
This representation can also be used to represent a weighted graph. 
The linked list can slightly be changed to even store the weight of the edge.
Adjacency Matrix: Adjacency Matrix is a 2D array of size V x V where V is the number of vertices in a graph.
 Let the 2D array be adj[][], a slot adj[i][j] = 1 indicates that there is an edge from vertex i to vertex j.
  Adjacency matrix for undirected graph is always symmetric. Adjacency Matrix is also used to represent weighted graphs. 
If adj[i][j] = w, then there is an edge from vertex i to vertex j with weight w.

n: This program gives us the knowledge of adjacency matrix graph
*/