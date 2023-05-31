#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "Assignment.hpp"
 
using namespace std;
 
int main()
{
 string line, word;
 
 	string dump;
	string Rankstr;
	int Rank;
	string ArScorestr, ErScorestr, FsrScorestr, CpfScorestr, IfrScorestr, IsrScorestr, IrnScorestr, GerScorestr, ScoreScaledstr;
	double ArScore, ErScore, FsrScore, CpfScore, IfrScore, IsrScore, IrnScore, GerScore, ScoreScaled;
	string Name, Location, LocationCode, ArRank, ErRank, FsrRank, CpfRank, IfrRank, IsrRank, IrnRank, GerRank;
 
	ifstream file ("Institution.csv");
	bool header = true;
	while(file.good()){
		if(header){
			getline(file, dump, '\n');
		}
		else{
			getline(file, Rankstr, ',');
			getline(file, Name, ',');
			getline(file, LocationCode, ',');
			getline(file, Location, ',');
			getline(file, ArScorestr, ',');
			getline(file, ArRank, ',');
			getline(file, ErScorestr, ',');
			getline(file, ErRank, ',');
			getline(file, FsrScorestr, ',');
			getline(file, FsrRank, ',');	
			getline(file, CpfScorestr, ',');
			getline(file, CpfRank, ',');
			getline(file, IfrScorestr, ',');
			getline(file, IfrRank, ',');
			getline(file, IsrScorestr, ',');
			getline(file, IsrRank, ',');
			getline(file, IrnScorestr, ',');
			getline(file, IrnRank, ',');
			getline(file, GerScorestr, ',');
			getline(file, GerRank, ',');
			getline(file, ScoreScaledstr, '\n');
			
			//Debugging stuff
			cout << Rankstr << " " << Name << " " << LocationCode << endl;
			
			//Converting datatypes
			Rank = stoi(Rankstr);
			ArScore = stod(ArScorestr);
			ErScore = stod(ErScorestr);
			FsrScore = stod(FsrScorestr);
			CpfScore = stod(CpfScorestr);
			IfrScore = stod(IfrScorestr);
			IsrScore = stod(IsrScorestr);
			IrnScore = stod(IrnScorestr);
			GerScore = stod(GerScorestr);
			ScoreScaled = stod(ScoreScaledstr);
			
			Institution* temp = CreateNewNode(Rank, Name, LocationCode, Location, ArScore, ArRank, ErScore, ErRank, FsrScore, FsrRank, CpfScore, CpfRank, IfrScore, IfrRank, IsrScore, IsrRank, IrnScore, IrnRank, GerScore, GerRank, ScoreScaled);
			InsertIntoEndofList(temp);
		}
		header = false;				
	}

	return 0;
}
