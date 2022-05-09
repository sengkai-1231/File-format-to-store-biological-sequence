
#include "Genbank.h"
#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

int main(int argc, const char * argv[])
{
   
   Genbank g1;
	string id,accessionNo, sequence, description, version;

    cout<<"Enter sequence details:- " << endl;
    //get input from user for instance g1
    cout << "ID: ";
    cin >> id;
    cin.ignore();
    cout <<"Accession No.: ";
	getline(cin,accessionNo);
    cout << "Version:";
	getline(cin,version);
	cout <<"Description: ";
    getline(cin,description);
	cout << "Sequence with a, c, g, t only: "<<endl;
	getline(cin,sequence);
	for (int i = 0; i < sequence.length(); i++)
    {
        if (sequence[i] == 'a' || sequence[i] == 'c' || sequence[i] == 'g' || sequence[i] == 't')
                continue;
        else
        {
            cout << "Invalid input! Please try again with a, c, g, t only: " << endl;
            getline(cin,sequence);
        }
	}   
	g1.setId(id);
	g1.setSeq(sequence);
	g1.setVersion(version);
	g1.setDesc(description);
	g1.setAccession(accessionNo);	
	g1.printDetails();

 return 0;
 
}
