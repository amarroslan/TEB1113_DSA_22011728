/*

ID: 22011728
Name: Muhammad Amar bin Roslan
Contact: 0195154165
Email: muhammad_22011728@utp.edu.my
LAb: 1
*/

#include <iostream>
#include <string>

using namespace std;

struct Student{
    string name;
    int id;
    int phone;
    string email;
};

int main(){
    Student students[2];
    
    for (int i = 0; i < 2; i++){
        cout<<"Input student id: ";
        cin>>students[i].id;
        cout<<"Name: ";
        cin>>students[i].name;
        cout<<"Phone: ";
        cin>>students[i].phone;
        cout<<"EMail: ";
        cin>>students[i].email;
        
    }
    
    for (int i = 0; i < 2; i++){
        cout<<"Student " << i + 1<< endl;
        cout<<"ID: " << students[i].id<<endl;
        cout<<"Name: "<<students[i].name<<endl;
        cout<<"Phone: " << students[i].phone<<endl;
        cout<<"Email: " <<students[i].email<<endl;
    }
    
    
    return 0;
}