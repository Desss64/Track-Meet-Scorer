#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int totalPoints = 0;
void printEvents(vector<string>);
void addPoints(int);

int main() {

	ifstream inFile;
	vector<string> eventList;

	//Opens file with list of track and field events
	inFile.open("Events.txt");

	//If file was successfully opened continue
	if (inFile)
	{
		string trackEvent;
		while (getline(inFile, trackEvent))
		{
			eventList.push_back(trackEvent);
		}
	}
	else
	{
		//Displays an error message
		cerr << "Error opening file" << endl;
		return 1;
	}

	int eventChoice, entryAmount, place;
	char reply;
	bool done = false;

	while (done != true)
	{
		//Displays list of events to choose from
		printEvents(eventList);

		//Takes event choice from user and validates it
		do
		{
			cout << "Choose an event to enter places for: ";
			cin >> eventChoice;

		} while (eventChoice < 0 || eventChoice > eventList.size());

		cout << endl;

		//Takes number of entries to make and validates them
		do
		{
			cout << "Number of entries for " << eventList[eventChoice - 1] << ": ";
			cin >> entryAmount;

		} while (entryAmount < 0);

		cout << endl;

		//Takes place numbers for event
		for (int i = 0; i < entryAmount; i++)
		{
			int pos = eventList[eventChoice - 1].find("relay");

			//Validates place input
			do
			{
				//If track and field event is a team event print team otherwise print athlete
				if (pos >= 0)
					cout << "Team " << (i + 1) << "'s place (Top 8 score pts): ";
				else
					cout << "Athlete " << (i + 1) << "'s place (Top 8 score pts): ";

				cin >> place;

			} while (place < 0);

			//Adds point earned to overall team score
			addPoints(place);
		}

		cout << endl;
		cout << "Total points scored: " << totalPoints << endl;
		cout << endl;

		//Takes reply for continuation of event placements and validates it
		do
		{
			cout << "Would you like to select another event? e.g Y/y for yes, N/n for no." << endl;
			cin >> reply;

			//If user is done entering place numbers exit loop
			if (reply == 'N' || reply == 'n')
			{
				done = true;
			}

		} while (reply != 'Y' && reply != 'y' && reply != 'N' && reply != 'n');
		cout << endl;
	}

	return 0;
}

void printEvents(vector<string> events)
{
	for (int i = 0; i < events.size(); i++)
	{
		if (i < 9)
			cout << (i + 1) << ".  " << events[i] << endl;
		else
			cout << (i + 1) << ". " << events[i] << endl;
	}
	cout << endl;
}

void addPoints(int placeNumber)
{
	switch (placeNumber)
	{
	case 1:
		totalPoints += 10;
		break;
	case 2:
		totalPoints += 8;
		break;
	case 3:
		totalPoints += 6;
		break;
	case 4:
		totalPoints += 5;
		break;
	case 5:
		totalPoints += 4;
		break;
	case 6:
		totalPoints += 3;
		break;
	case 7:
		totalPoints += 2;
		break;
	case 8:
		totalPoints += 1;
		break;
	}
}
