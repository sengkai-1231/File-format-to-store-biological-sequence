#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <iomanip>
using namespace std;



class Sequence{
private:
	string id;
	string version;
	string description; 
	string seq; 


public:
	
	void setId (const string &newDisplayId){
		id = newDisplayId;
	}
	void setVersion (const string &newVersion){
		version = newVersion;
	}
	void setDescription (const string &newDescription){
		description = newDescription;
	}
	void setSeq (const string &newSeq){
		seq = newSeq;
	}
	string getId() const{
		return id;
	}
	string getVersion() const{
		return version;
   }
	
	string getDescription() const{
		return description;
	}
	string getSeq() const {
		return seq;
	}
	void printDetails(); // to display the results of sequence analysis
};	

int main(int argc, const char * argv[]){
	Sequence s1; 
	string id, version, description, seq; //variables to hold input from user
//get input from user for instance 's1'
	cout << "Display Id: ";
	cin >> id; //to hold value display Id
	cin.ignore();
	cout << "Version:";
	getline(cin,version);
	cout << "Description: ";
	getline(cin,description);
	cin.ignore();
	cout << "Sequence: ";
	getline(cin,seq);
	
	s1.setId(id);
	s1.setVersion(version);
	s1.setDescription(description);
	s1.setSeq(seq);
	s1.printDetails(); 
}


//member functions' definition for 'Sequence' class
//instructs compiler that member function named 'printDetails' is from 'Sequence' class
void Sequence::printDetails() {
	cout << "\nFASTA format record\n\n";
	cout <<getVersion()<< getId() <<" "<< getDescription()<<endl;
	cout << getSeq()<< endl;	
}






