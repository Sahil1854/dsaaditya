#include <iostream>
#define MAX 10
using namespace std;
struct node{
 string name;
 long long int telephone_number;
};
class hash_functions{
private:
 node data[MAX];
public:
 hash_functions(){
 for (int i = 0; i < MAX; i++){
 data[i].name = " ";
 data[i].telephone_number = 0;
 }
 }
 void insert();
 int hash(string client_name);
 void search();
 void display();
};
int main(){
 std::cout << "\n--------------------------------------------------" << std::endl;
 std::cout << "--------------------------------------------------" << std::endl;
 hash_functions obj;
 int choice;
 do{
 std::cout << "1.Insert" << std::endl;
 std::cout << "2.Search" << std::endl;
 std::cout << "3.Display" << std::endl;
 std::cout << "4.Exit" << std::endl;
 std::cout << "--------------------------------------------------" << std::endl;
 std::cout << "Enter your choice: ";
 cin >> choice;
 std::cout << "--------------------------------------------------" << std::endl;
 switch (choice){
 case 1:
 obj.insert();
 break;
 case 2:
 obj.search();
 break;
 case 3:
 obj.display();
 break;
 case 4:
 std::cout << "Thank You" << std::endl;
 break;
 default:
 std::cout << "Invalid Choice" << std::endl;
 std::cout << "--------------------------------------------------" << std::endl;
 break;
 }
 }while (choice != 4);
 std::cout << "--------------------------------------------------" << std::endl;
 std::cout << "--------------------------------------------------" << std::endl;
 return 0;
}
void hash_functions::insert(){
 int pos;
 string client_name;
 long int telephone_number;
 std::cout << "Enter the name of client: ";
 cin >> client_name;
 std::cout << "Enter the client telephone number: ";
 cin >> telephone_number;
 pos = hash(client_name);
 int c = pos;
 bool flag = false;
 while (flag != true){
 if (data[pos].name == " " && data[pos].telephone_number == 0){
 data[pos].name = client_name;
 data[pos].telephone_number = telephone_number;
 flag = true;
 cout << "Hash is: " << pos << endl;
 break;
 }
 pos = (pos + 1) % 10;
 if (c == pos){
 std::cout << "Hash Table is Full." << std::endl;
 break;
 }
 }
 std::cout << "--------------------------------------------------" << std::endl;
}
int hash_functions::hash(string client_name){
 int sum = 0;
 for (int i = 0; i < client_name.length(); i++){
 sum += (int)client_name[i];
 }
 return (sum / client_name.length()) % 10;
}
void hash_functions::search(){
 int pos;
 string client_name;
 std::cout << "Enter client name to be searched: ";
 cin >> client_name;
 pos = hash(client_name);
 int c = pos;
 bool flag = false;
 while (flag != true){
 if (data[pos].name == client_name){
 std::cout << "Data Found. Telephone number is: " << data[pos].telephone_number << 
std::endl;
 flag = true;
 break;
 }
 pos = (pos + 1) % 10;
 if (c == pos){
 std::cout << "Data Not Found" << std::endl;
 break;
 }
 }
 std::cout << "--------------------------------------------------" << std::endl;
}
void hash_functions::display(){
 for (int i = 0; i < MAX; i++){
 std::cout << i << ". Name: " << data[i].name << "\n Telephone_number: " << 
data[i].telephone_number << std::endl;
 }
 std::cout << "--------------------------------------------------" << std::endl;
}
/*Hashing is a fundamental data structure that efficiently stores and retrieves data in a way that allows for quick access. 
It involves mapping data to a specific index in a hash table using a hash function that enabling fast retrieval of information based on its key. This method is commonly used in databases, caching systems, and various programming applications to optimize search and retrieval operations.

In linear probing, the hash table is searched sequentially that starts from the original location of the hash. If in case the location that we get is already occupied, then we check for the next location. 
The function used for rehashing is as follows: rehash(key) = (n+1)%table-size. 
Quadratic probing is a method to resolve collisions that can occur during the insertion of data into a hash table. When a collision takes place (two keys hashing to the same location), quadratic probing calculates a new position by adding successive squares of an incrementing value (usually starting from 1) to the original position until an empty slot is found.

How Quadratic Probing Works
Quadratic Probing, as the name suggests, uses a quadratic function to resolve collisions.
When a collision occurs (i.e., when the desired slot is already occupied), Quadratic Probing calculates the next available slot using a formula like (hash(key) + i^2) % table_size, 
where i is the number of probing attempts. This ensures a more even distribution of data in the hash table
In the provided program, the hash function calculates the hash value for a given client name. The hash function used here is a basic one that computes the sum of the ASCII values of the characters in the client name 
and then takes the modulo of this sum by the size of the hash table (which is 10 in this case).
conc: In this way we have implemented Hash table for quick lookup using C++
*/
