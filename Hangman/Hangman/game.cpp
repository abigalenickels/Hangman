#include <iostream>
#include <string>
#include <utility>
#include <cstdlib>

#include <random>
#include<ctime>

#include <iomanip>

#include <sstream>
#include <vector>
#include <fstream>

using namespace std;


const int MAXWORDS = 200;
const int MAXWORDLEN = 15;
const vector<string> STD_LIST =
	{ "committee", "jelly", "club", "pizza", 
	  "dapper", "previous", "bat", "trash",
	  "partner", "humor", "mirror", "theory", 
	  "senses", "corny", "horny", "giraffe",
	  "tennis", "precious", "green", "salad",
	  "catfish", "playtime", "sexy", "bottle" };

int importing(vector<string> &TEXT_LIST)
{
	string list;

	//input file
	string file = "allwords.txt";

	//num lines
	int i = 0;

	//importation
	ifstream input_stream(file);
	if (input_stream.is_open()) //if file is open
	{
		//ignore first line
		string line;
		getline(input_stream, line);

		while (getline(input_stream, line))
		{
			getline(input_stream, list, '\n');
			TEXT_LIST.push_back(list);

			i++;
		}
		input_stream.close();
	}
	else
	{
		cout << "Failed to open file." << endl;
		TEXT_LIST = STD_LIST;
		return 26;
	}
	return i;
}
string input()
{
	bool valid = false;
	string user_entry;
	cout << "Enter a word between 1 and 15 characters long." << endl;

	while (!valid)
	{
		getline(cin, user_entry);
		for (int i = 0; i < user_entry.size(); i++)
		{
			if (!isalpha(user_entry.at(i)))
			{
				cout << "That is not a valid word! Try again." << endl;
				valid = false;
				break;
			}
			else
				valid = true;
		}
	}
	cout << endl;
	return user_entry;
}

class Hangman
{
public:
	Hangman(int players);
	string answer;
	char filled[MAXWORDLEN];
	int fill(char c, string answer);
	void print();
	char guess();

	int nCorrect();
	int nIncorrect();

private:
	vector<string>TEXT;
	int numWords;
	string pick();
	int correct;
	int incorrect;
	string guesses;
};

Hangman::Hangman(int players)
{
	correct = 0;
	incorrect = 0;

	if (players == 1)
	{
		numWords = importing(TEXT);
		answer = pick();
	}
	else
	{
		numWords = 1;
		answer = input();
	}

	for (int i = 0; i < answer.size(); i++)
	{
		filled[i] = '%';
	}
}

int Hangman::nCorrect()
{
	return correct;
}

int Hangman::nIncorrect()
{
	return incorrect;
}

string Hangman::pick()
{
	srand(time(0));

	int r = rand() % numWords;
	return TEXT[r];
}

void Hangman::print()
{
	if (incorrect == 0)
	{
		cout << "    ___________" << endl;
		cout << "   |          |" << endl;
		cout << "   |          |" << endl;
		cout << "              |" << endl;
		cout << "              |" << endl;
		cout << "              |" << endl;
		cout << "              |" << endl;
		cout << "              |" << endl;
		cout << "              |" << endl;
		cout << "              |" << endl;
		cout << "              |" << endl;
		cout << "         _____|_____" << endl << endl;
		cout << "You have " << 7 - incorrect << " strikes remaining!" << endl << endl;
	}
	else if (incorrect == 1)
	{
		cout << "    ___________" << endl;
		cout << "   |          |" << endl;
		cout << " __|__        |" << endl;
		cout << " |   |        |" << endl;
		cout << " |___|        |" << endl;
		cout << "              |" << endl;
		cout << "              |" << endl;
		cout << "              |" << endl;
		cout << "              |" << endl;
		cout << "              |" << endl;
		cout << "              |" << endl;
		cout << "         _____|_____" << endl << endl;
		cout << "You have " << 7 - incorrect << " strikes remaining!" << endl << endl;
	}
	else if (incorrect == 2)
	{
		cout << "    ___________" << endl;
		cout << "   |          |" << endl;
		cout << " __|__        |" << endl;
		cout << " |   |        |" << endl;
		cout << " |___|        |" << endl;
		cout << "   |          |" << endl;
		cout << "   |          |" << endl;
		cout << "   |          |" << endl;
		cout << "              |" << endl;
		cout << "              |" << endl;
		cout << "              |" << endl;
		cout << "         _____|_____" << endl << endl;
		cout << "You have " << 7 - incorrect << " strikes remaining!" << endl << endl;
	}
	else if (incorrect == 3)
	{
		cout << "    ___________" << endl;
		cout << "   |          |" << endl;
		cout << " __|__        |" << endl;
		cout << " |   |        |" << endl;
		cout << " |___|        |" << endl;
		cout << "   |          |" << endl;
		cout << "  /|          |" << endl;
		cout << " / |          |" << endl;
		cout << "              |" << endl;
		cout << "              |" << endl;
		cout << "              |" << endl;
		cout << "         _____|_____" << endl << endl;
		cout << "You have " << 7 - incorrect << " strikes remaining!" << endl << endl;
	}
	else if (incorrect == 4)
	{
		cout << "    ___________" << endl;
		cout << "   |          |" << endl;
		cout << " __|__        |" << endl;
		cout << " |   |        |" << endl;
		cout << " |___|        |" << endl;
		cout << "   |          |" << endl;
		cout << "  /|\\         |" << endl;
		cout << " / | \\        |" << endl;
		cout << "              |" << endl;
		cout << "              |" << endl;
		cout << "              |" << endl;
		cout << "         _____|_____" << endl << endl;
		cout << "You have " << 7 - incorrect << " strikes remaining!" << endl << endl;
	}
	else if (incorrect == 5)
	{
		cout << "    ___________" << endl;
		cout << "   |          |" << endl;
		cout << " __|__        |" << endl;
		cout << " |   |        |" << endl;
		cout << " |___|        |" << endl;
		cout << "   |          |" << endl;
		cout << "  /|\\         |" << endl;
		cout << " / | \\        |" << endl;
		cout << "  /           |" << endl;
		cout << " /            |" << endl;
		cout << "              |" << endl;
		cout << "         _____|_____" << endl << endl;
		cout << "You have " << 7 - incorrect << " strikes remaining!" << endl << endl;
	}
	else if (incorrect == 6)
	{
		cout << "    ___________" << endl;
		cout << "   |          |" << endl;
		cout << " __|__        |" << endl;
		cout << " |   |        |" << endl;
		cout << " |___|        |" << endl;
		cout << "   |          |" << endl;
		cout << "  /|\\         |" << endl;
		cout << " / | \\        |" << endl;
		cout << "  / \\         |" << endl;
		cout << " /   \\        |" << endl;
		cout << "              |" << endl;
		cout << "         _____|_____" << endl << endl;
		cout << "You have " << 7 - incorrect << " strikes remaining!" << endl << endl;

	}
	else
	{
		cout << "   _________    " << endl;
		cout << "  /         \\  " << endl;
		cout << " /           \\ " << endl;
		cout << " |  R. I. P  |   x===========x" << endl;
		cout << " |     _     |   |   Y O U   |" << endl;
		cout << " |   _(_)_   |   |  L O S E  |" << endl;
		cout << " |  (_)@(_)  |   x===========x" << endl;
		cout << " |   /(_)    |  " << endl;
		cout << " |  \\|/      |  " << endl;
		cout << " |  \\|///    |  " << endl;
		cout << " |^^^^^^^^^^^|  " << endl << endl;
		cout << "You have " << 7 - incorrect << " strikes remaining!" << endl << endl;
	}

	if (incorrect < 7)
	{
		cout << "LETTERS GUESSED: ";
		for (int i = 0; i < guesses.size(); i++)
		{
			cout << guesses.at(i) << " ";
		}

		cout << endl;
		cout << "MYSTERY WORD: ";
		for (int i = 0; i < answer.size(); i++)
		{
			if (filled[i] == '%')
			{
				cout << "_ ";
			}
			else
			{
				cout << filled[i] << " ";
			}
		}
		cout << endl << endl;
	}
}

void printTitle()
{
	cout << "/////////////////////////////" << endl;
	cout << "///  H  A  N  G  M  A  N  ///" << endl;
	cout << "/////////////////////////////" << endl << endl;
	cout << "Instructions:\nEnter a letter one by one to make a guess.\nEnter \"0\" at any time to quit." << endl << endl;
	cout << "==========================================" << endl << endl;
}

char Hangman::guess()
{
	char c;
	cin >> c;
	c = toupper(c);

	if (c == '0')
		return '0';

	else if (!isalpha(c))
		return '@';

	else
	{
		if (guesses.find(c) == -1)
		{
			guesses += c;
			return c;
		}
	}
	
	return '\0';
}

int Hangman::fill(char c, string answer)
{
	int num = 0;

	for (int i = 0; i < answer.size(); i++)
	{
		if (answer.at(i) == tolower(c))
		{
			filled[i] = toupper(c);
			num++;
		}
	}

	if (num > 0)
		correct += num;
	else
		incorrect++;

	return num;
}

void clear()
{
	cout << string(50, '\n');
}

int main ()
{
	cout << "THIS IS THE TEST BRANCH!!" << endl << endl;
	/////////////////////////
	//// INITIALIZE GAME ////
	/////////////////////////
	int players = 0;
	cout << "Welcome. Enter [1] for single player or [2] for multiplayer: ";
	while (players == 0)
	{
		cin >> players;
		if (players != 1 && players != 2)
		{
			cout << "Please enter a valid digit, 1 or 2." << endl;
			players = 0;
		}
		else
		{
			cout << "Welcome to HANGMAN." << endl << endl;
		}
	}
	Hangman h(players);

	printTitle();
	h.print();

	char c = '.';

	while (c != '0' && h.nCorrect() != h.answer.size() && h.nIncorrect() != 7)
	{
		cout << "Please enter a letter to guess: ";
		c = h.guess();
		cout << "==========================================" << endl;
		
		clear();
		printTitle();

		if (c == '0')
			break;
		else if (c == '\0')
			cout << "[!!!] You've already guessed that letter [!!!]\n" << endl;
		else if (c == '@')
			cout << "[!!!] That is not a valid entry [!!!]\n" << endl;
		else
		{
			int matches = h.fill(c, h.answer);
			if (matches == 1)
				cout << "There is 1 match for \"" << c << "\"" << endl;
			else
				cout << "There are " << matches << " matches for \"" << c << "\"" << endl;
		}
		
		h.print();
	}

	if (c == '0')
	{
		clear();
		cout << "Thanks for playing!\n\nSHUTTING DOWN GAME..." << endl;
	}

	else if (h.nIncorrect() == 7)
	{
		cout << "The mystery word was: \"" << h.answer << "\"" << endl;
	}

	else
	{
		cout << "Y O U  W I N ! ! !" << endl << endl;
		cout << "You guessed the mystery word, \"" << h.answer << "\"!" << endl;
	}
}