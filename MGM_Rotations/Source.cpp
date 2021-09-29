#include <iostream>
#include <random>
#include <time.h>
using namespace std;


string chart[100][100];

struct Lifegaurd {
	bool down = true;
	string name = "No_name";
};

struct Stands {
	string name;
	
};

int SearchChart(int column, string stand, int count) { // searches the given column of the chart for the given name of the stand and returns the y value of it

	for (int y = 0; y < count; y++) {
		if (chart[column][y] == stand) {
			return y;
		}
	}


	return -1;
}

void StandInput(Stands A[], int count){ 

	for (int i = 0; i < count; i++) {
		cout << "Enter the name of the stand:";
		cin >> A[i].name;
	}

	return;
}


void Print(int LG_count, int time) {
	for (int y = 0; y < LG_count; y++) {
		for(int x = 0; x < time; x++){
			if (chart[x][y] != "NULL")
				cout << chart[x][y] << "\t";
			else
				cout << "-\t";
		}
		cout << endl;
	}
}



int main() {

	srand(time(NULL));
	int poolHours = 11;
	int LifegaurdCount = 0;
	int standCount = 0;
	int intervals = poolHours * 2;
	int random_num = 0;
	bool input = false;
	Lifegaurd Gaurdarray[1000];
	Stands StandArray[1000];


	while (input == false) {
		cout << "Enter the amount of lifegaurds:";
		cin >> LifegaurdCount;
		cout << "Enter the amount of stands:";
		cin >> standCount;

		if (LifegaurdCount < standCount) {
			cout << "current values are impossible there must be more lifegaurds than stands. Please try again" << endl;
		}
		else {
			input = true;
			cout << "Thank you" << endl;
		}
	}



	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			chart[i][j] = "NULL";
		}
	}

	


	StandInput(StandArray, standCount);

	for (int y = 0; y < standCount; y++) { // initialize first column of chart.
		chart[0][y] = StandArray[y].name;
	}


	int index = -1;
	bool Lifegaurd_selected = false;
	bool standsLeft = true;
	int remainingStands = 0;

	for (int x = 1; x < intervals; x++) { //for every column x starting with the second column
		remainingStands = standCount;
		while (remainingStands != 0) { //while there are stands that need to be taken
			
			while (Lifegaurd_selected == false) { //loop until a random down lifegaurd is found
				random_num = rand() % LifegaurdCount;//choose a random number from 0 to lifegaurd count - 1
					if (Gaurdarray[random_num].down == true) {
						Lifegaurd_selected = true;
					}
			}

			chart[x][random_num] = StandArray[remainingStands].name;

			index = SearchChart(x - 1, StandArray[remainingStands].name, LifegaurdCount);
			
			chart[x][remainingStands] = StandArray[remainingStands].name;

			if (index != -1) {
				Gaurdarray[index].down = true;
			}





			remainingStands--;
		}

	}
	


	Print(LifegaurdCount, intervals);

	return 0;
}