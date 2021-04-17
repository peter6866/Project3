#include <fstream>
#include <sstream>
#include <istream>
#include <limits>
#include "BST.h"
using namespace std;

int main() {
	ifstream data("test3.csv");
	string temp;
	getline(data, temp);
	int date, passengers, seats, flights, ori_population,
		des_population;
	string ori_city_pre, ori_city_post, des_city_pre, des_city_post, ori_city, des_city;
	BST airport;
	int num = 0;
	while (data.good()) {
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
		//cout << "ori city is: " << ori_city << endl;
		//cout << "ori city is: " << des_city << endl;
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
	/*cout << "start searching" << endl;
	airport.searchDate(20000101);
	cout << "finish searching" << endl;*/

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
			//Aberdeen SD, Minneapolis MN, 2000
			string inputOriCity, inputDestCity;
			int inputYear;

			cout << "Origin City: ";
			getline(cin, inputOriCity);
			cout << "Destination City: ";
			getline(cin, inputDestCity);
			cout << "Year: ";
			cin >> inputYear;

			//function 1 test
			//user input origin_city, des_city, and year
			airport.findFlights(inputOriCity, inputDestCity, inputYear);
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
