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

	//function 1
	//输入起始和重点和年份
	airport.findFlights("Aberdeen SD", "Minneapolis MN", 2000);

	cout << "Program Finished" << endl;
	return 0;
}
