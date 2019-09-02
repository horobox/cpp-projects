/* The guessing game board
	Written by: Shreevathsa
*/
#include<iostream>
#include<iomanip>
#include<cstdlib>
#include<ctime>
using namespace std;

void printChoice();
int choice(int, char carChoice[], int riskedPoints[]);
int randNum();
void randProp(int, int &row , int &col);
void checkArray(char [], int, int, int );
void compareArray(char [], char[], int, int &,int [], int []);

int main(){
	cout << "\nWelcome to The Guessing Game Board\n";
	printChoice();
	char shree;
	int points;

	cout << "\nHow much points would you like:  ";
	cin  >> points;

	do{

	int oldPoints = points;
	cout << "\nHow many guesses would you like: ";
	int guess;

	cin  >> guess;
	char carChoice[guess];

	int riskedPoints[guess];

	 choice(guess, carChoice, riskedPoints);
	int randNumber = randNum();

	char carArray [9];
	 int row, col;

	randProp(randNumber, row, col);

	checkArray(carArray,randNumber, row, col);

	int pointsArray[guess];
	compareArray(carChoice, carArray, guess, points, riskedPoints, pointsArray);
	// for(int c = 0; c < guess; c++){
	// 	cout << pointsArray[c] << endl;
	// 	}
	// altPoints = points;

	cout << "\nMy number is: " << randNumber << endl;

	cout << "\nYou won " <<  points - oldPoints << " points in this turn.\n";

	cout << "Your new balance is : " << points <<" points.\n";
	if(points > 0){
	cout << "\nDo you want to play again(Y or N)? " ;
	cin  >> shree;
}
}
	while( (points > 0) && shree != 'n');

	return 0;
}
int choice(int guess, char carChoice[], int riskedPoints[]){
	int guessedNumber;
	for(int i = 0; i < guess; i++){
		cout << "\nGuess " << i + 1 << "\t:" << endl;
		cout << "Enter your choice: ";
		cin  >> carChoice[i];
			if(carChoice[i] == 'N'){
				cout << "Enter your number: ";
				cin  >> guessedNumber;
			}
		cout << "Points at risk? ";
		cin  >> riskedPoints[i];

}
	return guessedNumber;

}
void checkArray(char array[],int randN, int checkI, int checkJ){
	int s = 0;
	//cout << checkI << "\t" << checkJ << endl;
	if(checkI == 1 || checkI == 2 || checkI == 3 || checkI == 4){
		array[s] = 'L';
		s++;
	}
	 else if(checkI== 5 || checkI == 6 || checkI == 7 || checkI == 8){
		array[s] = 'M';
		s++;
	}
	 else{
		array[s] = 'H';
		s++;
	}
	//column check
	if(checkJ == 1){
		array[s] = 'F';
		s++;
	}
	 else if(checkJ == 2){
		array[s] = 'C';
		s++;
	}
	 else{
		array[s] = 'R';
		s++;
	}

	//odd or ever
	if(randN % 2 == 0){
		array[s] = 'E';
		s++;
	}
	else{
		array[s] = 'O';
		s++;
	}
	return;
}

void compareArray(char carChoice[], char carArray[], int guess, int &points,int riskedPoints[], int pointsArray[]){
	for(int i = 0; i < guess; i++){
		bool flag1 = false;
		for(int looker = 0; looker < 3; looker++){
			if(carChoice[i] == carArray[looker]){
			flag1 = true;
			}
		}
		if(flag1){
			pointsArray[i] = riskedPoints[i];
			points += riskedPoints[i];
		}
		else{
			pointsArray[i] = -riskedPoints[i];
			points -= riskedPoints[i];
		}

	}

		return;
}


int randNum(){
	srand(time(0));
	int randNum = rand() % 36 + 1;
	return randNum;
}
void randProp(int randN, int &checkRow, int &checkCol){
	int index = 0;
	int number = 1;

	int arrayList[12][4];
	for(int a = 0; a < 12; a++){
		for(int b = 0; b < 3; b++){
			arrayList[a][b] = number;
			number++;
		}
	}

	bool flag;
	int i, j;
	for(i = 0; i < 12; i++){
		for(j = 0; j < 3; j++){
			if(randN == arrayList[i][j]){
				flag = true;
				break;
			}
		}
		if(flag == true){
			break;
		}
	}
	checkRow = i + 1;
	checkCol = j + 1;

	// cout << randN << endl;
//	cout << i << "\t" << j << endl;
	// cout << checkRow << "\t" << checkCol << endl;

	return;
}




void printChoice(){
	cout << endl << endl << "Guesses Choices :\n";
	cout << setw(3) << "O" << "  Odd\n";
	cout << setw(3) << "E" << "  Even\n";
	cout << setw(3) << "L" << "  Low\n";
	cout << setw(3) << "M" << "  Med\n";
	cout << setw(3) << "H" << "  High\n";
	cout << setw(3) << "F" << "  Left\n";
	cout << setw(3) << "C" << "  Center\n";
	cout << setw(3) << "R" << "  Right\n";
	cout << setw(3) << "N" << "  Number\n";

	cout << endl;
	cout << "The Guessing Game Board :\n";
	cout << "----------------------------\n";

	cout << "       " << setw(5) << "01" << setw(7) << "02" << setw(7) << "03" << endl;

	cout << "   LOW    " << setw(2) <<  "04" << setw(7) << "05" << setw(7) << "06" << endl;

	cout << "       " << setw(5) << "07" << setw(7) << "08" << setw(7) << "09" << endl;

	cout << "       " << setw(5) << "10" << setw(7) << "11" << setw(7) << "12" << endl;

	cout << "----------------------------\n";

	cout << "       " << setw(5) << "13" << setw(7) << "14" << setw(7) << "15" << endl;

	cout << "  MEDIUM  " << setw(2) <<  "16" << setw(7) << "17" << setw(7) << "18" << endl;

	cout << "       " << setw(5) << "19" << setw(7) << "20" << setw(7) << "21" << endl;

	cout << "       " << setw(5) << "22" << setw(7) << "23" << setw(7) << "24" << endl;

	cout << "----------------------------\n";

	cout << "       " << setw(5) << "25" << setw(7) << "26" << setw(7) << "27" << endl;

	cout << "   HIGH   "<< setw(2) <<  "28" << setw(7) << "29" << setw(7) << "30" << endl;

	cout << "       " << setw(5) << "31" << setw(7) << "32" << setw(7) << "33" << endl;

	cout << "       " << setw(5) << "34" << setw(7) << "35" << setw(7) << "36" << endl;

	cout << "----------------------------\n";

	cout << "         LEFT " << " CENTER " << " RIGHT  " << endl << endl;

	return;
}
