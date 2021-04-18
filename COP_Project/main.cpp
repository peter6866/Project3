#include <fstream>
#include <sstream>
#include <istream>
#include <limits>
#include <chrono>
#include "BST.h"
#include "MAP.h"
using namespace std;
using namespace chrono;

struct dataNode {
	int passengersN, seatsN, flightsN,
		ori_populationN, des_populationN;
	dataNode(int passengersN, int seatsN, int flightsN, int ori_populationN,
		int des_populationN) {

		this->passengersN = passengersN;
		this->seatsN = seatsN;
		this->flightsN = flightsN;
		this->ori_populationN = ori_populationN;
		this->des_populationN = des_populationN;
	}
};

int main() {
	//initialize data source
	ifstream data("test3.csv");
	string temp;
	getline(data, temp);
	int date, passengers, seats, flights, ori_population,
		des_population;
	string ori_city_pre, ori_city_post, des_city_pre, des_city_post, ori_city, des_city;
	
	int DSSelection;
	cout << "Data Structure" << endl;
	cout << "1. Binary Search Tree" << endl;
	cout << "2. Map with hash table" << endl;
	cout << "Select: ";
	cin >> DSSelection;
	BST airport;
	Map<string, dataNode*> airport2;
	string month[12] = { "January", "Febuary", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December" };

	if (DSSelection == 1)
	{
		auto start = system_clock::now();
		while (data.good()) 
		{
			getline(data, ori_city_pre, ',');
			if (ori_city_pre == "")
				break;
			getline(data, ori_city_post, ',');
			getline(data, des_city_pre, ',');
			getline(data, des_city_post, ',');
			ori_city = ori_city_pre + ori_city_post;
			ori_city = ori_city.substr(1, ori_city.size() - 2);
			des_city = des_city_pre + des_city_post;
			des_city = des_city.substr(1, des_city.size() - 2);
			getline(data, temp, ',');
			passengers = stoi(temp);
			getline(data, temp, ',');
			seats = stoi(temp);
			getline(data, temp, ',');
			flights = stoi(temp);
			getline(data, temp, ',');
			date = stoi(temp);
			getline(data, temp, ',');
			ori_population = stoi(temp);
			getline(data, temp, '\n');
			des_population = stoi(temp);
			airport.insert(date, passengers, seats, flights, ori_population,
				des_population, ori_city, des_city);
		}
		auto end = system_clock::now();
		auto duration = duration_cast<microseconds>(end - start);
		cout << "Insertion time using BST: " << double(duration.count()) * microseconds::period::num / microseconds::period::den << " seconds" << endl;
	}
	else if (DSSelection == 2)
	{
		auto start = system_clock::now();
		while (data.good()) {
			getline(data, ori_city_pre, ',');
			if (ori_city_pre.empty())
				break;
			getline(data, ori_city_post, ',');
			getline(data, des_city_pre, ',');
			getline(data, des_city_post, ',');
			ori_city = ori_city_pre + ori_city_post;
			ori_city = ori_city.substr(1, ori_city.size() - 2);
			des_city = des_city_pre + des_city_post;
			des_city = des_city.substr(1, des_city.size() - 2);
			getline(data, temp, ',');
			passengers = stoi(temp);
			getline(data, temp, ',');
			seats = stoi(temp);
			getline(data, temp, ',');
			flights = stoi(temp);
			getline(data, temp, ',');
			date = stoi(temp);
			getline(data, temp, ',');
			ori_population = stoi(temp);
			getline(data, temp, '\n');
			des_population = stoi(temp);
			dataNode* temp1 = new dataNode(passengers, seats, flights, ori_population, des_population);
			string compositeKey = ori_city.append(" ").append(des_city).append(" ").append(to_string(date));
			airport2.push(compositeKey, temp1);
		}
		auto end = system_clock::now();
		auto duration = duration_cast<microseconds>(end - start);
		cout << "Insertion time using MAP: " << double(duration.count()) * microseconds::period::num / microseconds::period::den << " seconds" << endl;
	}

	cout << endl;

	int selection;
	cout << "Select Function" << endl;
	cout << "1. Number of Routes" << endl;
	cout << "2. Seat Occupancy" << endl;
	cout << "3. Population Trend" << endl;
	cout << "4. Quit" << endl;
	cout << "Select: ";
	cin >> selection;
	cout << endl;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	while (selection != 4)
	{
		if (selection == 1)
		{
			//Test Case: Aberdeen SD, Minneapolis MN, 2000
			string inputOriCity, inputDestCity;
			int inputYear;

			cout << "Origin City: ";
			getline(cin, inputOriCity);
			cout << "Destination City: ";
			getline(cin, inputDestCity);
			cout << "Year: ";
			cin >> inputYear;
			if (DSSelection == 1)
			{
				//BST
				//user input origin_city, des_city, and year
				airport.findFlights(inputOriCity, inputDestCity, inputYear);
			}
			else if (DSSelection == 2) 
			{
				int extendedDate = (inputYear * 10000) + 101;
				for (int i = 0; i < 12; i++)
				{
					string key = inputOriCity + " " + inputDestCity + " " + to_string(extendedDate);
					//cout << key << endl;
					int routes = airport2[key]->flightsN;
					cout << "Total routes " << "from " << inputOriCity << " to " << inputDestCity << " in " << month[i] << ": "<< routes << endl;
					extendedDate += 100;
					key = "";
				}
				
			}
			
			cout << endl;
		}
		else if (selection == 2)
		{
			//function 2 test
			//string ori_city, des_city, year;
			string inputOriCity, inputDestCity;

			cout << "Origin City: ";
			getline(cin, inputOriCity);
			cout << "Destination City: ";
			getline(cin, inputDestCity);

			for (int i = 2000; i <= 2009; i++)
				airport.seatOccupancy(inputOriCity, inputDestCity, i);

		}
		else if (selection == 3)
		{
			string inputDestCity;
			cout << "City Name: ";
			getline(cin, inputDestCity);
			//X-axis: 2000 to 2009
			//store Y-axis in a vector
			vector<int> passengerNum;
			vector<int> populationNum;

			for (int i = 2000; i <= 2009; i++)
			{
				passengerNum.push_back(airport.populationTrend(inputDestCity, i).first);
				populationNum.push_back(airport.populationTrend(inputDestCity, i).second);
			}
				
		}
		cout << "Selection: ";
		cin >> selection;
	}

	cout << "Program Terminates" << endl;
	
	return 0;
}
