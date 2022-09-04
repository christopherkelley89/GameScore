/*
* Christopher Kelley
* IT-312 SNHU
* 6-1 Programming Assignment: Writing to a File
*/
// GameScore.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main()
{
	int numOfPlayers, rounds;
	string playerName;
	int playerScore, p, s;

	//Get user input for num. of players playing the game
	cout << "\n\n How many players will be playing the game? ";
	cin >> numOfPlayers;

	//Get user input for num of rounds
	cout << "\n\n How many rounds will be played? ";
	cin >> rounds;

	//opening file to write
	fstream fout("GameScore.txt", ios::out);

	//writing to file
	fout << "\n ========= Score =========";
	fout << "\n Player Name: ";
	cin.ignore();

	//player names 
	for (p = 0; p < numOfPlayers; p++)
	{
		//Reading each player name from user
		cout << "\n\n Input player " << (p + 1) << " Name: ";
		getline(cin, playerName);

		//Writing name to file
		fout << playerName << " \t ";
	}

	//Read Scores for ea. round 
	for (s = 1; s <= rounds; s++)
	{
		//write header
		fout << "\n\n Round " << s << " Scores: ";
		cout << "\n\n Round " << s << " Scores: ";

		//scores of ea player
		for (p = 1; p <= numOfPlayers; p++)
		{
			//player scores
			cout << "\n Enter Player " << p << " Score: ";
			cin >> playerScore;

			//writing score to file...
			fout << playerScore << " \t ";
			cout << "Writing Score to file successful!";
		}

	}

	//Close file
	fout.close();

	//output GameScore.txt to console
	string line;
	ifstream myFile("GameScore.txt");
	
	// This will check if the file is open
	if (myFile.is_open())
	{
		while (getline(myFile, line))
		{
			cout << line << '\n';
		}
		myFile.close();
	}
	else cout << "Cannot Open File!!!\n";

	return 0;




}
