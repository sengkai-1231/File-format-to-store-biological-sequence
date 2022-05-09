#include "Fasta.h"
#include <iostream>

#include <stdio.h>
#include <string>
using namespace std;

int main(int argc, const char * argv[]){
	Fasta s1; 
	string id, version, description, seq; //variables to hold input from user

	cout<<"Enter the sequence details:-"<<endl;
	//get input from user for instance 's1'
	cout << "ID: ";
	cin >> id; //to hold value display Id
	cin.ignore();
	cout << "Version:";
	getline(cin,version);
	cout << "Description: ";
	getline(cin,description);
	cout << "Sequence with a, c, g, t only: "<<endl;
	getline(cin,seq);
	for (int i = 0; i < seq.length(); i++)
    {
        if (seq[i] == 'a' || seq[i] == 'c' || seq[i] == 'g' || seq[i] == 't')
                continue;
        else
        {
            cout << "Invalid input! Please try again with a, c, g, t only: " << endl;
            getline(cin,seq);
        }
    }
	
	s1.setId(id);
	s1.setVersion(version);
	s1.setDescription(description);
	s1.setSeq(seq);
	s1.printDetails(); 
}
