#include "Fasta.h"
#include <iostream>
#include <string>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

Fasta::Fasta():id("No Id yet"),version("No version yet"),description("No description yet"),seq("No Seq yet"){}

Fasta::Fasta(const string& theId, const string& theVersion, const string &theDescription, const string &theSeq){
		id = theId;
		version = theVersion;
		description = theDescription;
    	seq = theSeq;
}

void Fasta::setId (const string& theDisplayId){
		id = theDisplayId;
	}
	void Fasta::setVersion (const string& theVersion){
		version = theVersion;
	}
	void Fasta::setDescription (const string& theDescription){
		description = theDescription;
	}
	void Fasta::setSeq (const string& theSeq){
		seq = theSeq;
	}
	string Fasta::getId() const{
		return id;
	}
	string Fasta::getVersion() const{
		return version;
   }
	
	string Fasta::getDescription() const{
		return description;
	}
	string Fasta::getSeq() const {
		return seq;
	}
	void Fasta::newVersion(){
		istringstream ss (version);
		
		string word;
		
		while(ss>>word){
			cout<<word<<"|";
		}
	}
	string Fasta::conUpper(){
		string upperSeq = seq;
		transform(upperSeq.begin(),upperSeq.end(),upperSeq.begin(),::toupper);
		return upperSeq;
	}

	void Fasta::printDetails(){
		cout << "\nSequence in Fasta format:-\n\n";
		cout <<">";
		newVersion();
		cout<< getId() <<" "<< getDescription()<<endl;
		cout << conUpper()<< endl;
	}; 

