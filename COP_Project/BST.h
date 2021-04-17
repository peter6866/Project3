#pragma once
#include <string>
#include <iostream>
#include <vector>
#include <stack>
#include <iomanip>

using namespace std;
class BST
{
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

private:
	TreeNode* root;

	TreeNode* insert(TreeNode* root, int date, int passengers, int seats, int flights, int ori_population,
		int des_population, const string& ori_city, const string& des_city) {
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

	void searchDate(TreeNode* root, int date) {
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

	vector<TreeNode*> findFlights(TreeNode* root, const string& ori_city, const string& des_city, int year) {
		vector<TreeNode*> result;
		if (root == nullptr)
			return result;

		stack<TreeNode*> s;
		s.push(root);

		while (!s.empty()) {
			TreeNode* temp = s.top();
			s.pop();
			//inorder traversal
			if (temp->left)
				s.push(temp->left);
			if (temp->ori_city == ori_city && temp->des_city == des_city && (temp->date / 10000) == year)
				result.push_back(temp);
			if (temp->right)
				s.push(temp->right);
		}
		return result;
	}

	vector<TreeNode*> findPopulationData(TreeNode* root, const string& des_city, int year)
	{
		vector<TreeNode*> result;
		if (root == nullptr)
			return result;

		//inorder traversal using stack
		stack<TreeNode*> s;
		s.push(root);

		while (!s.empty()) {
			TreeNode* temp = s.top();
			s.pop();
			
			if (temp->left)
				s.push(temp->left);
			if (temp->des_city == des_city && (temp->date / 10000) == year)
				result.push_back(temp);
			if (temp->right)
				s.push(temp->right);
		}
		return result;
	}

public:
	BST()
	{
		root = nullptr;
	}

	void insert(int date, int passengers, int seats, int flights, int ori_population,
		int des_population, string ori_city, string des_city)
	{
		root = insert(root, date, passengers, seats, flights, ori_population, des_population, ori_city, des_city);
	}

	void searchDate(int date)
	{
		searchDate(root, date);
	}

	//according to user input of ori_city, des_city and year
	//output flights_Num of each month
	void findFlights(string ori_city, string des_city, int year) {
		vector<TreeNode*> v = findFlights(root, ori_city, des_city, year);
		//output
		for (int i = 0; i < v.size(); i++) {
			if ((v[i]->date / 100) % 100 == 1)
				cout << "Total routes " << "from " << v[i]->ori_city << " to " << v[i]->des_city << " in January: " << v[i]->flights << endl;
			if ((v[i]->date / 100) % 100 == 2)
				cout << "Total routes " << "from " << v[i]->ori_city << " to " << v[i]->des_city << " in Febuary: " << v[i]->flights << endl;
			if ((v[i]->date / 100) % 100 == 3)
				cout << "Total routes " << "from " << v[i]->ori_city << " to " << v[i]->des_city << " in March: " << v[i]->flights << endl;
			if ((v[i]->date / 100) % 100 == 4)
				cout << "Total routes " << "from " << v[i]->ori_city << " to " << v[i]->des_city << " in Apirl: " << v[i]->flights << endl;
			if ((v[i]->date / 100) % 100 == 5)
				cout << "Total routes " << "from " << v[i]->ori_city << " to " << v[i]->des_city << " in May: " << v[i]->flights << endl;
			if ((v[i]->date / 100) % 100 == 6)
				cout << "Total routes " << "from " << v[i]->ori_city << " to " << v[i]->des_city << " in June: " << v[i]->flights << endl;
			if ((v[i]->date / 100) % 100 == 7)
				cout << "Total routes " << "from " << v[i]->ori_city << " to " << v[i]->des_city << " in July: " << v[i]->flights << endl;
			if ((v[i]->date / 100) % 100 == 8)
				cout << "Total routes " << "from " << v[i]->ori_city << " to " << v[i]->des_city << " in August: " << v[i]->flights << endl;
			if ((v[i]->date / 100) % 100 == 9)
				cout << "Total routes " << "from " << v[i]->ori_city << " to " << v[i]->des_city << " in September: " << v[i]->flights << endl;
			if ((v[i]->date / 100) % 100 == 10)
				cout << "Total routes " << "from " << v[i]->ori_city << " to " << v[i]->des_city << " in October: " << v[i]->flights << endl;
			if ((v[i]->date / 100) % 100 == 11)
				cout << "Total routes " << "from " << v[i]->ori_city << " to " << v[i]->des_city << " in November: " << v[i]->flights << endl;
			if ((v[i]->date / 100) % 100 == 12)
				cout << "Total routes " << "from " << v[i]->ori_city << " to " << v[i]->des_city << " in December: " << v[i]->flights << endl;
		}
	}

	void seatOccupancy(const string& ori_city, const string& des_city, int year) {
		vector<TreeNode*> v = findFlights(root, ori_city, des_city, year);

		int passengerSum = 0;
		int seatSum = 0;
		float percentage;
		for (int i = 0; i < v.size(); i++) {
			passengerSum += v[i]->passengers;
			seatSum += v[i]->seats;
		}

		cout << "Total passengers in " << year << ": " << passengerSum << endl;
		cout << "Total seats in " << year << ": " << seatSum << endl;
		cout.precision(3);
		percentage = ((float)passengerSum / (float)seatSum) * 100;
		cout << "Average seat Occupancy: " << percentage << "%" << endl;
		cout << endl;
	}

	pair<int, int> populationTrend(const string& des_city, int year)
	{
		vector<TreeNode*> v = findPopulationData(root, des_city, year);
		pair<int, int> p;

		int passengerSum = 0;
		int population;
		for (int i = 0; i < v.size(); i++)
			passengerSum += v[i]->passengers;

		cout << "People traveled to " << des_city << " in " << year << ": " << passengerSum << endl;
		cout << "Population of " << des_city << " in " << year << ": " << v[0]->des_population << endl;
		cout << endl;

		p.first = passengerSum;
		p.second = v[0]->des_population;

		return p;
	}

};