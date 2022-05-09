#ifndef Fasta_h
#define Fasta_H

#include <stdio.h>
#include <string>
using namespace std;

class Fasta{
private:
	string id;
	string version;
	string description; 
	string seq; 


public:
	Fasta();
	
	Fasta(const string& theId, const string& theVersion, const string &theDescription, const string &theSeq);
	
	void setId (const string &theId);
	
	void setVersion (const string &theVersion);
	
	void setDescription (const string &theDescription);
	
	void setSeq (const string &theSeq);
	
	string getId() const;
	
	string getVersion() const;
	
	string getDescription() const;
	
	string getSeq() const ;
	
	string conUpper();
	
	void newVersion();
	
	void printDetails(); // to display the results of sequence analysis
};	
#endif
