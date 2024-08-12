#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

struct Message {

	char* text;

	Message() {
		text = new char[100];
	};

};

string encryptionTask(string);

int main() {

	int numOfMessages;
	
	cout << "Enter number of messages : " << endl;
	cin >> numOfMessages;

	Message* messages = new Message[numOfMessages];

	cin.ignore();

	for (int i = 0; i < numOfMessages; i++)
	{
		cout << "Input your " << i + 1 << " message : " << endl;
		cin.getline((messages + i)->text, 100);
		string encryptedMessage = encryptionTask(string((messages + i)->text));
		cout << "Message to send : " << encryptedMessage << endl;

	}


	for (int i = 0; i < numOfMessages; i++)
	{
		delete[](messages + i)->text;
	}

	delete[] messages;
	messages = nullptr;

	
	
	system("pause<0");
	return 0;

}

string encryptionTask(string text) {
	
	unordered_map<char, string> encryptionMap = {

		{'A', "@1"}, {'B', "8"},  {'C', "("},  {'D', "|)"},
		{'E', "3"},  {'F', "#"},  {'G', "6"},  {'H', "#"},
		{'I', "!"},  {'J', "]"},  {'K', "|<"}, {'L', "1"},
		{'M', "|v|"}, {'N', "^"},  {'O', "0"},  {'P', "|*"},
		{'Q', "0,"}, {'R', "2"},  {'S', "$"},  {'T', "+"},
		{'U', "(_)"}, {'V', "\\/"}, {'W', "\\^/"}, {'X', "><"},
		{'Y', "`/"}, {'Z', "7_"},  {'a', "@"},  {'b', "6"},
		{'c', "["},  {'d', "|)"}, {'e', "€"},  {'f', "ph"},
		{'g', "&"},  {'h', "#"},  {'i', "1"},  {'j', "]"},
		{'k', "|<"}, {'l', "1"},  {'m', "|V|"}, {'n', "^"},
		{'o', "0"},  {'p', "|*"}, {'q', "9"},  {'r', "2"},
		{'s', "$"},  {'t', "7"},  {'u', "(_)"}, {'v', "\\/"},
		{'w', "\\/\\/"}, {'x', "><"}, {'y', "¥"}, {'z', "7"}

	};

	string encryptedText = " ";

	for (char ch : text) {
		if (encryptionMap.find(ch) != encryptionMap.end()) {
			encryptedText += encryptionMap[ch];
		}
		else {

			encryptedText += ch; 

		}
	}

	return encryptedText;
};