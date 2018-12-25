//  Project vFinal
//
//  Created by Gökhan Parlakyıldız and Baha Demircioğlu on 27/12/16.
//  Gökhan Parlakyıldız - 1408797
//  Baha Demircioğlu - 1409872
//  All rights reserved.

#include <iostream>
#include <sstream>//string
#include <fstream>//input
#include <ctime>//for clock
using namespace std;

void heapify(int a[], int i, int n) {
	int l, r, largest, loc;
	l = 2 * i;
	r = (2 * i + 1);
	if ((l <= n) && a[l]>a[i]) largest = l;
	else largest = i;
	if ((r <= n) && (a[r]>a[largest])) largest = r;
	if (largest != i) {
		loc = a[i];
		a[i] = a[largest];
		a[largest] = loc;
		heapify(a, largest, n);
	}
}

void build_max_heap(int a[], int n) {
	for (int k = n / 2; k >= 1; k--)
	{
		heapify(a, k, n);
	}
}

void heapsort(int a[], int n, int k) {
	build_max_heap(a, n);
	int i, temp;
	for (i = n; i >= k; i--) {
		temp = a[i];
		a[i] = a[1];
		a[1] = temp;
		heapify(a, 1, i - 1);
	}
}
/*
void checker(int a[], int k, int capacity) {
for (int i = capacity; i < capacity - k; i--) {
for (int b = capacity - 1; b < capacity - k -1; b--) {
if ((a[i] == a[b]) && (i != b)) {
a[b] = -999999;
}
}
heapsort(a, capacity, k);
}
}
*/
void printarray(int arr[], int capacity, int k) {
	for (int i = capacity; i >= capacity - k; i--) {
		cout << arr[i] << " " << endl;
	}
}//printing numbers based on "k", which taken from user.

int main() {
	string file;
	fstream input;
	//information of txt file
	cout << "\t\t-------The Top \"k\" Largest Numbers Finder-------" << endl;
	cout << "Enter the name of file without \".txt\": ";
	cin >> file;
	input.open("C:/Users/Baha/Documents/Visual Studio 2015/Projects/dataEski/" + file + ".txt"); //I open file from my project folder in docs 
	//txt file opened
	int numberfromfile;
	int capacity = 0;
	int counter = 1;
	//checking if txt is opened or not. something like try/catch.
	if (!input.is_open()) {
		cout << "\nUnavailable to open the file!\nPlease run the program again and enter a correct name of file!" << endl;
		return 0;
	}

	while (input >> numberfromfile) {
		capacity++;
	}
	//sorting settings
	int *a = new int[capacity];//array capacity
	input.clear();//clearing input in our hand
	input.seekg(0, ios::beg); //position setting at input time

	while (input >> numberfromfile) {
		a[counter] = numberfromfile; //adding numbers to array
		counter++;
	}

	input.close();
	int k = -1;

	do {
		cout << "How many largest numbers do you want? Enter an integer between 0-101:";//asking user the "k", how many sorted numbers they want
		cin >> k;
	} while (k>100 || k>capacity || k<1);

	clock_t baslangic = clock(); //starting time
	heapsort(a, capacity, k); //sorting
							  //checker(a, k, capacity);//same element control
	printarray(a, capacity, k); //print time

	clock_t son = clock();//finish time
	double passed = double(son - baslangic);//passed time
	cout << endl << "The time passed: " << passed << "ms\n" << endl;
	return 0;
}