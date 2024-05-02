/* A book consists of chapters, chapters consist of sections and sections consist of subsections.
Construct a tree and print the nodes.
Find the time and space requirements of your method. */

#include <iostream>
#include <string.h>
using namespace std;

struct node
{
    char name[20];
    node *next;
    node *down;
    int flag;
};

class Gll
{
    char ch[20];
    int n, i;
    node *head = NULL, *temp = NULL, *t1 = NULL, *t2 = NULL;

public:
    node *create();
    void insertb();
    void insertc();
    void inserts();
    void insertss();
    void displayb();
};

node *Gll::create()
{
    node *p = new (struct node);
    p->next = p->down = NULL;
    p->flag = 0;
    cout << "\n enter the name: ";
    cin >> p->name;
    return p;
}

void Gll::insertb()
{
    if (head == NULL)
    {
        t1 = create();
        head = t1;
    }
    else
    {
        cout << "\n book exist";
    }
}

void Gll::insertc()
{
    if (head == NULL)
    {
        cout << "\n there is no book";
    }
    else
    {
        cout << "\n how many chapters you want to insert: ";
        cin >> n;
        for (i = 0; i < n; i++)
        {
            t1 = create();
            if (head->flag == 0)
            {
                head->down = t1;
                head->flag = 1;
            }
            else
            {
                temp = head;
                temp = temp->down;
                while (temp->next != NULL)
                    temp = temp->next;
                temp->next = t1;
            }
        }
    }
}
void Gll::inserts()
{

    if (head == NULL)
    {
        cout << "\n there is no book";
    }
    else
    {
        cout << "\n Enter the name of chapter on which you want to enter the section: ";
        cin >> ch;
        temp = head;
        if (temp->flag == 0)
        {
            cout << "\n their are no chapters on in book";
        }
        else
        {
            temp = temp->down;
            while (temp != NULL)
            {
                if (!strcmp(ch, temp->name))
                {
                    cout << "\n how many sections you want to enter: ";
                    cin >> n;
                    for (i = 0; i < n; i++)
                    {
                        t1 = create();
                        if (temp->flag == 0)
                        {
                            temp->down = t1;
                            temp->flag = 1;
                            cout << "\n******";
                            t2 = temp->down;
                        }
                        else
                        {
                            cout << "\n#####";
                            while (t2->next != NULL)
                            {
                                t2 = t2->next;
                            }
                            t2->next = t1;
                        }
                    }
                    break;
                }
                temp = temp->next;
            }
        }
    }
}
void Gll::insertss()
{
    if (head == NULL)
    {
        cout << "\n there is no book";
    }
    else
    {
        cout << "\n Enter the name of chapter on which you want to enter the section: ";
        cin >> ch;
        temp = head;
        if (temp->flag == 0)
        {
            cout << "\n their are no chapters on in book";
        }
        else
        {
            temp = temp->down;
            while (temp != NULL)
            {
                if (!strcmp(ch, temp->name))
                {
                    cout << "\n enter name of section in which you want to enter the sub section: ";
                    cin >> ch;
                    if (temp->flag == 0)
                    {
                        cout << "\n their are no sections ";
                    }

                    else
                    {
                        temp = temp->down;
                        while (temp != NULL)
                        {
                            if (!strcmp(ch, temp->name))
                            {
                                cout << "\n how many subsections you want to enter: ";
                                cin >> n;
                                for (i = 0; i < n; i++)
                                {
                                    t1 = create();
                                    if (temp->flag == 0)
                                    {
                                        temp->down = t1;
                                        temp->flag = 1;
                                        cout << "\n******";
                                        t2 = temp->down;
                                    }
                                    else
                                    {
                                        cout << "\n#####";
                                        while (t2->next != NULL)
                                        {
                                            t2 = t2->next;
                                        }
                                        t2->next = t1;
                                    }
                                }
                                break;
                            }
                            temp = temp->next;
                        }
                    }
                }
                temp = temp->next;
            }
        }
    }
}
void Gll::displayb()
{
    if (head == NULL)
    {
        cout << "\n book not exist";
    }
    else
    {
        temp = head;
        cout << "\n NAME OF BOOK:  " << temp->name;
        if (temp->flag == 1)
        {
            temp = temp->down;

            while (temp != NULL)
            {
                cout << "\n\t\tNAME OF CHAPTER:  " << temp->name;
                t1 = temp;
                if (t1->flag == 1)
                {
                    t1 = t1->down;
                    while (t1 != NULL)
                    {
                        cout << "\n\t\t\t\tNAME OF SECTION:  " << t1->name;
                        t2 = t1;
                        if (t2->flag == 1)
                        {
                            t2 = t2->down;
                            while (t2 != NULL)
                            {
                                cout << "\n\t\t\t\t\t\tNAME OF SUBSECTION:  " << t2->name;
                                t2 = t2->next;
                            }
                        }
                        t1 = t1->next;
                    }
                }
                temp = temp->next;
            }
        }
    }
}

int main()
{
    Gll g;
    int x;

    do
    {
        cout << "\n 1.insert book";
        cout << "\n 2.insert chapter";
        cout << "\n 3.insert section";
        cout << "\n 4.insert subsection";
        cout << "\n 5.display book";
        cout << "\n 6.exit";
        cout << "\n Enter your choice: ";
        cin >> x;
        switch (x)
        {
        case 1:
            g.insertb();
            break;
        case 2:
            g.insertc();
            break;
        case 3:
            g.inserts();
            break;
        case 4:
            g.insertss();
            break;
        case 5:
            g.displayb();
            break;
        default:
            std::cout << "Invalid Choice" << std::endl;
            break;
        }
    } while (x != 6);

    return 0;
}

/* A tree T is a set of nodes storing elements such that the nodes have a parent-child relationship 
that satisfies the following
• if T is not empty, T has a special tree called the root that has no parent
• each node v of T different than the root has a unique parent node w; each node with parent w is 
a child of w.Tree is a widely-used data structure that emulates a tree structure with a set of linked 
nodesTrees are usualy used to store and represent data in some hierarhical order. The data are 
stored in the nodes, from which the tree is consisted of

here are two basic types of trees. In an unordered tree, a tree is a tree in a purely 
structural sense — that is to say, given a node, there is no order for the children of that node. A 
tree on which an order is imposed — for example, by assigning different natural numbers to each 
child of each node — is called an ordered tree, and data structures built on them are called 
ordered tree data structures. Ordered trees are by far the most common form of tree data 
structure. Binary search trees are one kind of ordered tree




Trees are so useful and frequently used, because they have some very serious advantages: 
 Trees reflect structural relationships in the data 
 Trees are used to represent hierarchies 
 Trees provide an efficient insertion and searching 
 Trees are very flexible data, allowing to move subtrees around with minumum effort 
A subtree is a portion of a tree data structure that can be viewed as a complete tree in 
itself. Any node in a tree T, together with all the nodes below his height, that are reachable from 
the node, comprise a subtree of T. The subtree corresponding to the root node is the entire tree; 
the subtree corresponding to any other node is called a proper subtree (in analogy to the term 
proper subset).

Time complexity: Constructing the tree and printing the nodes involves traversing all chapters, sections, and subsections, resulting in a time complexity of O(n), where n is the total number of nodes (chapters, sections, and subsections) in the book.

Space complexity: The space complexity depends on the number of chapters, sections, and subsections in the book. 
In the worst case, if each chapter has multiple sections and each section has multiple subsections, the space complexity would be O(n), 
where n is the total number of nodes in the book.

*/