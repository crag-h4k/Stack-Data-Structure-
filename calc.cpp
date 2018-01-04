#include <cctype> 
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <map>
#include "stack.h"

using namespace std;
using namespace main_savitch_7B;

void read_and_evaluate(istream& ins);
void readFile();

int main(){
	readFile();

	cout << "\n\nHit Enter to close...";
	cin.get();
	return EXIT_SUCCESS;
}

void readFile(){
	ifstream input;
	string fileName;
	cout << "Which file would you like to read? (FULL FILE PATH REQUIRED)" << endl;
	getline(cin, fileName);
	input.open(fileName);
	if (input.fail()){
		cout << "Could not open file." << endl;
		exit(0);
	}
	while(input && input.peek() != EOF){
		read_and_evaluate(input);
		cout << "\n";
		input.ignore();
	}
	input.close();
}

void read_and_evaluate(istream& ins){
	const char DECIMAL = '.';
	const char RIGHT_PARENTHESIS = ')';
	const char LEFT_PARENTHESIS = '(';
	map<char, int> SYMBOLS;
	SYMBOLS['+'] = 0;
	SYMBOLS['-'] = 0;
	SYMBOLS['*'] = 1;
	SYMBOLS['/'] = 1;
	stack<char> s;
	double number;
	char symbol;

	while(ins && ins.peek() != '\n'){
		if (ins.peek() == LEFT_PARENTHESIS){
			ins.ignore();
			s.push(LEFT_PARENTHESIS);
		}
		else if (isdigit(ins.peek()) || (ins.peek() == DECIMAL)){
			ins >> number;
			cout << number << " ";
		}
		else if (strchr("+-*/", ins.peek()) != NULL){
			ins >> symbol;
			char item;
			while(s.size()){
				item = s.top();
				if((item != LEFT_PARENTHESIS) && (SYMBOLS[item] >= SYMBOLS[symbol])){
					cout << item << " ";
					s.pop();
				}
				else{
					break;
				}
			}
			s.push(symbol);
		}
		else{
			ins.ignore();
			char item;
			while (s.size()){
				item = s.top();
				s.pop();
				if(item == LEFT_PARENTHESIS){
					break;
				}
				cout << item << " ";
			}
		}
	}
}
