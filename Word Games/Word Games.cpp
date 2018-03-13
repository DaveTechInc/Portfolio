#include "stdafx.h"
#include <string> 
#include <iostream>

using namespace std;

string sanitise(string);

bool palindrome(const string);
string pigLatin(string);
string reverse(const string);
void vowelCount(const string, int*);
int wordCount(string);

int main(int argc, char* argv[])
{
	string selection;
	cout << "What do you want to do? \n";
	cout << "Press p for palindrome checker \n";
	cout << "Press l for pig latin \n";
	cout << "Press r for reverse \n";
	cout << "Press v for vowel count \n";
	cout << "Press w for word count \n";
	cout << "Any other key to exit \n";
	cin >> selection;

	string input;
	cout << "Please input a string \n";
	cin.ignore();
	getline(cin, input);

	if (selection == "p") {
		if (palindrome(input)) {
			cout << "This word is a palindrome \n";
		}
		else {
			cout << "This word is not a palindrome \n";
		}
	}
	else if (selection == "l") {
		cout << pigLatin(input) + "\n";
	}
	else if (selection == "r") {
		cout << reverse(input) + "\n";
	}
	else if (selection == "v") {
		int vowelTotals[5] = {0, 0, 0, 0, 0};
		vowelCount(input, vowelTotals);
		cout << "Number of times a occurs in text: " << vowelTotals[0] << endl;
		cout << "Number of times e occurs in text: " << vowelTotals[1] << endl;
		cout << "Number of times i occurs in text: " << vowelTotals[2] << endl;
		cout << "Number of times o occurs in text: " << vowelTotals[3] << endl;
		cout << "Number of times u occurs in text: " << vowelTotals[4] << endl;
	}
	else if (selection == "w") {
		cout << "There are " << wordCount(input) << " words contained in this string \n";
	}

	cout << "Press return to exit \n";
	getline(cin, input);
	return 0;
}

string sanitise(string input)
{
	for (int i = 0; i < input.size(); i++) {
		if (isspace(input[i])) {
			input.replace(i, 1, " ");
			i++;
			while (isspace(input[i])) {
				input.erase(i, 1);
			}
		}
	}
	return input;
}

bool palindrome(const string input)
{
	bool isPalindrome = true;
	for (int i = 0; i < input.size() / 2; i++) {
		if (input[i] != input[(input.size() - 1) - i]) {
			isPalindrome = false;
		}
	}
	return isPalindrome;
}

string pigLatin(string in)
{
	string input = sanitise(in);
	string output;
	string word;
	size_t position = input.find_first_of(' ');
	while (position != std::string::npos) {
		word = input.substr(0, position);  //Extracting the next word from input
		word = word + word[0] + "ay";  //Copying the first letter to the end and adding "ay"
		word.erase(0, 1);  //Removing the first letter
		output = output + word + " ";
		input = input.substr(position + 1);  //Removing the word just processed from input along with the space following it
		position = input.find_first_of(' ');
	}
	input = input + input[0] + "ay";
	input.erase(0, 1);
	output = output + input;
	return output;
}

string reverse(const string input)
{
	string reversed = input;
	for (int i = 0; i < input.size(); i++) {
		reversed[i] = input[(input.size()-1)-i];
	}
	return reversed;
}

void vowelCount(const string input, int* vowelCount)
{
	for (int i = 0; i < input.size(); i++) {
		if (input[i] == 'a') {
			vowelCount[0] = vowelCount[0]+1;
		}
		else if (input[i] == 'e') {
			vowelCount[1] = vowelCount[1]+1;
		}
		else if (input[i] == 'i') {
			vowelCount[2] = vowelCount[2]+1;
		}
		else if (input[i] == 'o') {
			vowelCount[3] = vowelCount[3]+1;
		}
		else if (input[i] == 'u') {
			vowelCount[4] = vowelCount[4]+1;
		}
	}
}

int wordCount(string in)
{
	string input = sanitise(in);
	int wordCount = 0;
	size_t position = input.find_first_of(' ');
	while (position != std::string::npos) {
		wordCount++;
		input = input.substr(position + 1);
		position = input.find_first_of(' ');
	}
	wordCount++;
	return wordCount;
}
