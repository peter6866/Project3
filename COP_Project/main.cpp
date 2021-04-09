#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;

struct TreeNode {
	int date;
	int passengers, seats, flights,
		ori_population, des_population;
	string ori_city, des_city;
	TreeNode* left, * right;
	TreeNode(int date, int passengers, int seats, int flights, int ori_population,
		int des_population, string ori_city, string des_city) {
		this->date = date;
		this->passengers = passengers;
		this->seats = seats;
		this->flights = flights;
		this->ori_population = ori_population;
		this->des_population = des_population;
		this->ori_city = ori_city;
		this->des_city = des_city;
		left = nullptr;
		right = nullptr;
	}
};

TreeNode* insert(TreeNode* root, int date, int passengers, int seats, int flights, int ori_population,
	int des_population, string ori_city, string des_city) {
	if (root == nullptr) {
		TreeNode* temp = new TreeNode(date, passengers, seats, flights, ori_population,
			des_population, ori_city, des_city);
		//cout << "date is: " << date << endl;
		return temp;
	}
	if (date < root->date) {
		root->left = insert(root->left, date, passengers, seats, flights, ori_population,
			des_population, ori_city, des_city);
		//cout << "go left" << endl;
	}
	else {
		root->right = insert(root->right, date, passengers, seats, flights, ori_population,
			des_population, ori_city, des_city);
		//cout << "go right" << endl;
	}
	return root;
}

void SearchDate(TreeNode* root, int date) {
	if (root == nullptr) {
		cout << "nullptr" << endl;
		return;
	}
	while (root != nullptr) {
		if (date < root->date)
			root = root->left;
		else if (date > root->date)
			root = root->right;
		else {
			cout << "successful" << endl;
			cout << root->ori_city << "-->" << root->des_city << " date is: " << root->date << endl;
			root = root->right;
		}

	}
}

int main() {
	ifstream data("test.csv");
	string temp;
	getline(data, temp);
	int date, passengers, seats, flights, ori_population,
		des_population;
	string ori_city_pre, ori_city_post, des_city_pre, des_city_post, ori_city, des_city;
	TreeNode* root = nullptr;
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
		root=insert(root, date, passengers, seats, flights, ori_population,
			des_population, ori_city, des_city);
		//cout << "insertion complete" << endl;
		cout << num++ << endl;
	}
	cout << "start searching" << endl;
	SearchDate(root, 20061201);
	cout << "finish searching" << endl;
	return 0;
}
