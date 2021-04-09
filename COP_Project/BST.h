#pragma once
#include <string>
#include <iostream>
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
};