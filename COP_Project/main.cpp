#include <fstream>
#include <sstream>
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

	//function 1 test
	//user input origin_city, des_city, and year
	cout << "Find flights" << endl;
	airport.findFlights("Aberdeen SD", "Minneapolis MN", 2000);
	cout << endl;

	//function 2 test
	//string ori_city, des_city, year;
	cout << "Seat Occupancy" << endl;
	airport.seatOccupancy("Aberdeen SD", "Minneapolis MN", 2000);
	cout << endl;
	airport.seatOccupancy("Aberdeen SD", "Minneapolis MN", 2001);
	cout << endl;
	airport.seatOccupancy("Aberdeen SD", "Minneapolis MN", 2002);
	cout << endl;
	airport.seatOccupancy("Aberdeen SD", "Minneapolis MN", 2003);
	cout << endl;
	airport.seatOccupancy("Aberdeen SD", "Minneapolis MN", 2004);
	cout << endl;
	airport.seatOccupancy("Aberdeen SD", "Minneapolis MN", 2005);
	cout << endl;
	airport.seatOccupancy("Aberdeen SD", "Minneapolis MN", 2006);
	cout << endl;
	airport.seatOccupancy("Aberdeen SD", "Minneapolis MN", 2007);
	cout << endl;
	airport.seatOccupancy("Aberdeen SD", "Minneapolis MN", 2008);
	cout << endl;
	airport.seatOccupancy("Aberdeen SD", "Minneapolis MN", 2009);
	cout << endl;
	//ÓÐÇ÷ÊÆ
	
	airport.seatOccupancy("Aberdeen SD", "Pierre SD", 2000);
	
	return 0;
}
