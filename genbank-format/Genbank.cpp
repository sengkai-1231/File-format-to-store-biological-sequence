#include <stdio.h>
#include <iostream>
#include <string>
#include <iomanip>
#include <bits/stdc++.h> 

#include "Genbank.h"

using namespace std;
int featNum;

    Genbank::Genbank():id("No locus yet"), description("No definition yet"), sequence("No sequence yet"), accessionNo("No accession no. yet"), version("No version yet"){}
	Genbank::Genbank(const string& theId, const string& theDescription, const string& theSequence,  const string& theAccession, const string& theVersion)
	{   
		sequence = theSequence;
		description = theDescription;
		id = theId;
		accessionNo = theAccession;
		version = theVersion;
		/*source = theSource;
		organism = theOrganism;
		strain = theStrain;
		feature = theFeature;*/
	}
		
	void Genbank::setSeq(const string& theSequence)
	{
		sequence = theSequence;
	}
    void Genbank::setDesc(const string& theDescription)
	{
		description = theDescription;
	}
	void Genbank::setId(const string& theId)
	{
		id = theId;
	}
	void Genbank::setAccession(const string& theAccession)
	{
		accessionNo = theAccession;
	}
	void Genbank::setVersion(const string& theVersion)
	{
		version = theVersion;
	}
/*	void Genbank::setSource(const string& newSource)
	{
		source = newSource;
	}
	void Genbank::setOrganism(const string& newOrganism)
	{
		organism = newOrganism;
	}
	void Genbank::setStrain(const string& newStrain)
	{
		strain = newStrain;
	}
	void Genbank::setFeature(const string& newFeature)
	{
		feature = newFeature;
	}*/
		
    string Genbank::getSeq() const
    {
        return sequence;
    }
	string Genbank::getDesc() const
	{
        return description;
	}
	string Genbank::getId() const
	{
		return id;
	}
	string Genbank::getAccession() const
	{
		return accessionNo;
	}
	string Genbank::getVersion() const
	{
		return version;
	}
/*	string Genbank::getSource() const
	{
		return source;
	}
	string Genbank::getOrganism() const
	{
		return organism;
	}
	string Genbank::getStrain() const
	{
		return strain;
	}
	string Genbank::getFeature() const
	{
		return feature;
	}*/
	
	long Genbank::getSeqLength() {
		return seqLength = sequence.length();
	}
	
	void Genbank::calcBaseCount()
	{
		float aCount = 0;
		float cCount = 0;
		float tCount = 0;
		float gCount = 0;

		for (int i = 0; i < sequence.length(); i++)         //calculate number of bases
		{
			if (sequence[i] == 'a')
			{
				aCount++;
			}
			else if (sequence[i] == 'c')
			{
				cCount++;
			}
			else if (sequence[i] == 't')
			{
				tCount++;
			}
			else if (sequence[i] == 'g')
			{
				gCount++;
			}
		}
        
        cout << "BASE COUNT     "<< aCount<<"a "<<setw(5)<<cCount<<"c "<<setw(5)<<tCount<<"t "<<setw(5)<<gCount<<"g"<<endl;
	}
 
	void Genbank::makefeatures(){
	    char option;
	    bool run = false; 
	    cout<<"Enter the total features needed"<<endl;
	    cin>>featNum;
        
	    for(int i =0; i< featNum; ++i)
	    {
	        cout<<"Enter the feature "<<i+1<<" name: ";
	        cin>>genfeat[i].features;
	        cin.ignore();
	        
	        cout<<"Enter the "<<i+1<<" value:";
	        getline(cin,(genfeat[i].value));
	        
	       cout<<"Need to insert addtional value? Press 'a' :";
	       cin>> option;
	       
	        if(option =='A'||option =='a'){
	        cin.ignore();
            cout<<"Addtional value: ";
	        getline(cin,(genfeat[i].addVal));
	        cout<<endl;
	       
	        cout<<"Need to insert addtional value? Press 'a' :";
	        cin>> option;
	       
	        if(option =='A'||option =='a'){
	        cin.ignore();
            cout<<"Addtional value: ";
	        getline(cin,(genfeat[i].addVal2));
	        cout<<endl;
	        
	        cout<<"Need to insert addtional value? Press 'a' :";
	        cin>> option;
	       
	            if(option =='A'||option =='a'){
	            cin.ignore();
                cout<<"Addtional value: ";
	            getline(cin,(genfeat[i].addVal2));
	            }     
	        }
	       }
	       
	      
	       
	       
	        
	    }  
	}
	void Genbank::displayfeatures(){
	    cout<<"Features        Location/Qualifiers"<<endl;
	    for(int i =0;i<featNum;++i)
	    {
	       cout<<genfeat[i].features<<"            "<<genfeat[i].value<<endl;
	       cout<<"               "<<genfeat[i].addVal<<endl;
	       cout<<"               "<<genfeat[i].addVal2<<endl;
	       cout<<"               "<<genfeat[i].addVal3<<endl;
	    }
	}
	
	void Genbank::printOrigin()
	{
	    cout << "ORIGIN         \n" ;
	    char arr[sequence.length()]; 
		strcpy(arr, sequence.c_str()); 
		for (int i = 0; i<sequence.length(); i++) 
		{
			if (i%10 ==0)//EACH 10 SEPARATE
			{
				cout<<" ";
			} 
			if(i%60==0 && i <50){
				cout<<" "<<i+1 <<" ";
			}
			else if(i%60== 0 && i <100) 
			{
			    cout<<endl;
			    cout<<" "<<i+1<<" ";
			}
			else if (i%60 ==0 && i<1000)
			{
			    cout<<endl;
			    cout<<i+1 <<" ";
			}
			cout <<arr[i];
		} 
	}
		
	void Genbank::printDetails() 
	{
		makefeatures();
		cout <<"\nGenbank format\n\n";
		cout << "LOCUS          "  << getId() <<"    "<<getSeqLength()<<"bp  "<<"DNA"<<endl;
		cout << "DEFINITION     " << getDesc() << endl;
		cout << "ACCESSION      " << getAccession() << endl;
		cout << "VERSION        " << getVersion() << endl;
		displayfeatures();
	/*	cout << "SOURCE " << " " << getSource() << endl;
		cout << "ORGANISM " << " " << getOrganism() << endl;
		cout << "STRAIN " << " " << getStrain() << endl;
		cout << "FEATURE " << " " << getFeature() << endl;*/
		calcBaseCount();
		printOrigin();
	}

