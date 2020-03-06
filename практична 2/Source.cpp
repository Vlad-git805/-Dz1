#include <iostream>
#include <ctime>
#include <string>
#include <Windows.h>

using namespace std;

//код першого завдання я робив на лекції, я його не зінював, ви задали тоді трішкі іншу умову (не таку як у завданні з дз)

bool win = false;
int money = 0;

void GuessTheNumber(int a, int count);

void GuessThePressent(int countOfPresent);

int main()
{
	srand(time(0));
	int a = 0, count = 0;
	const int present = 10;
	int countOfPresent = 0;
	a = rand() % 10 + 1;
	cout << "Enter your money ";
	cin >> money;
	cout << "You have 5 attempt" << endl;
	GuessTheNumber(a, count);

	if (win == true)
	{
		countOfPresent = rand() % 10;
		GuessThePressent(countOfPresent);
	}

	system("pause");
	return 0;
}

void GuessTheNumber(int a, int count)
{
	int k = 0;
	if (k != a && count != 4 && money >= 200)
	{
		cout << "You have " << money << " money" << endl;
		cout << "Enter number" << endl;
		cin >> k;
		if (k == a)
		{
			cout << "Wiiner" << endl;
			count++;
			money -= 200;
			cout << "You make " << count << " attempt" << endl;
			cout << "You save " << money << "money" << endl;
			win = true;
			return;
		}
		else if (a > k)
		{
			cout << "Number is > " << k << endl;
			count++;
			money -= 200;
			GuessTheNumber(a, count);
		}
		else if (a < k)
		{
			cout << " Number is < " << k << endl;
			count++;
			money -= 200;
			GuessTheNumber(a, count);
		}
	}
	else
	{
		cout << "You lose" << endl;
		exit(0);
	}
}

void GuessThePressent(int countOfPresent)
{
	const int present = 10;
	int agree = 0;
	if (money >= 200)
	{
		cout << "Guess the cell number of your prize (from 0 to 9); one miss - 200$" << endl;
		int lol = 0;
		cin >> lol;
		string Present[present] = { "Car", "House","Plane","1milion$","Computer","Bike","scooter", "laptop","maсbook","1 litr of water" };
		if (lol == countOfPresent)
		{
			cout << "Yes, you guessed, your prize is:" << Present[lol] << endl;
			cout << "You agree with this pressent?(1 - yes, 2 - no)" << endl;
			cin >> agree;
			switch (agree)
			{
			case 1:
				cout << "Congratulation, you win!!!!!!!!" << endl;
				exit(0);
				break;
			case 2:
				cout << "Ok, lets try again, but one miss - 200$" << endl;
				countOfPresent = rand() % 10;
				GuessThePressent(countOfPresent);
				break;
			default:
				break;
			}
		}
		if (lol != countOfPresent)
		{
			money -= 200;
			cout << "Try again;     You have " << money << endl;
			GuessThePressent(countOfPresent);
		}
	}
}

//second task

//#include <iostream>
//using namespace std;
//void hanoiTower(int count, int first, int help, int last);
//int main()
//{
//	int count = 0;
//	cout << "Enter the number of disks" << endl;
//	cin >> count;
//	hanoiTower(count, 1,2,3);
//	cout << endl;
//	system("pause");
//	return 0;
//}
//void hanoiTower(int count, int first, int help, int last)
//{
//	if (count == 0) return;
//	hanoiTower(count - 1, first, last, help);
//	cout << first << " -> " << last << endl;
//	hanoiTower(count - 1, help, first, last);
//}


