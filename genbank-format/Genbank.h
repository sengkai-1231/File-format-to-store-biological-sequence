#ifndef Genbank_h
#define Genbank_h
#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>

using namespace std;



class Genbank
{
    private:
        string id;
        string accessionNo;
        string description;
        string version;
		long seqLength;
		struct GenFeatures{
            char features[100];
            string value;
            string addVal;
            string addVal2;
            string addVal3;
            }genfeat[10];
	protected:
		 string sequence;
	public:
		Genbank();
		//Genbank(const string& theSequence, const string& theDefinition);
		Genbank(const string& theId,const string& theDescription, const string& theSequence, const string& theAccession, const string& theVersion);
		string getSeq() const;
		string getAccession() const;
		string getVersion() const;
		string getId() const;
		string getDesc() const;
		
		void setId(const string& theId);
		void setSeq(const string& theSequence);
		void setDesc(const string& theDesciption);
		void setAccession(const string& theAccession);
		void setVersion(const string& theVersion);
       
       
		long getSeqLength();
		void makefeatures();
		void displayfeatures();
		void calcBaseCount();
		void printOrigin();
		void printDetails();


	};
#endif