//============================================================================
// Name        : editor.cpp
// Author      : 
// Version     :
//============================================================================

#include <iostream>
#include <fstream>
#include <string>
#include <conio.h>
#include "LinkedList.h"
using namespace std;

List<List<string> > allLines;

Node<List<string> > *curLine;

Node<string> *locateStr = NULL;

Node<List<string> > *locateLine = NULL;

Node<string>* search(string key, List<List<string> >& allLines) {
	
	Node<List<string> >* cur = allLines.first;
	if (cur == NULL) {
		return NULL;
	}
	Node<string>* node;
	do {
		node = cur->data.search(key);
		if (node != NULL) {
			curLine = cur;
			return node;
		}
		cur = cur->next;
	} while (cur != NULL);
	return NULL;
}

void readingFile(string fileName) {
	string line;
	ifstream file;
	file.open(fileName.c_str(), ios::in);
	if (file.is_open()) {
		while (getline(file, line)) {
			cout << line << endl;
		}
		file.close();
	}
	else
		cout << "Unable to open file" << endl;

}

void writingFile(List<List<string> > allLine, string fileName) {
	ofstream file;
	file.open(fileName.c_str(), ios::out);
	if (file.is_open()) {
		file << allLine;
		file.close();
	} else
		cout << "Unable to open file" << endl;
}

int main() {



	string fileName;
	string key;
	char character;
	int kalameNumber = 0, lineNumber = 0;
	cout << "------------ Menu -----------" << endl;
	cout << "press ctrl+W to write in a file" << endl;
	cout << "press ctrl+R to read from a file" << endl;
	cout << "press ctrl+S to search" << endl;
	cout << "press ctrl+I to insert" << endl;
	cout << "press ctrl+D to delete" << endl;
	cout << "press ctrl+E to Exit" << endl;
	char click;
	while (true) {

		click = getch();
		if (click == 23) {
			cout << " enter your file name" << endl;
			cin >> fileName;
			writingFile(allLines, fileName);
			cout << "saved! " << endl;

		} else if (click == 18) {
			cout << "enter your file name" << endl;
			cin >> fileName;
			readingFile(fileName);

		} else if (click == 9) {
			cout << " Enter Line:" << endl;
			List<string> line;
			kalameNumber = 0;
			do {
				List<char> harf;
				string a;
				do {
					character = getch();
					if (character == 13) {
						kalameNumber = 11;
						break;
					}
					cout << character;
					if (character != 32) {
						harf.insert(harf.last, character);
					}
				} while (character != ' ');
				a = harf.toString();
				if (a != " ") {
					line.insert(line.last, a);
				}

				kalameNumber++;
			} while (kalameNumber < 10 || character != 13);
			allLines.insert(allLines.last, line);
			locateLine = allLines.last;
			locateStr = locateLine->data.first;
			lineNumber++;
		} else if (click == 19) {//search
			cout << "enter key for searching" << endl;
			cin >> key;
			Node<string>* s = search(key, allLines);
			if (s != NULL) {
				cout << s->data << endl;
				locateStr=s;
			} else {
				cout << "Not found!" << endl;
			}

		} //up
		else if (click == 72) {
			if (locateLine != NULL && locateLine->prev != NULL) {
				cout<<endl;
				cout << "----------------------------------" << endl;
				cout << locateLine->prev->data << endl;
				locateLine = locateLine->prev;
				cout << "----------------------------------" << endl;

			}

		} //right
		else if (click == 77) {
			if (locateStr != NULL && locateStr->next != NULL) {
				cout<<endl;
				cout << "----------------------------------" << endl;
				locateStr = locateStr->next;
				cout << locateStr->data << endl;
				cout << "----------------------------------" << endl;

			}

		} //left
		else if (click == 75) {
			if (locateStr != NULL && locateStr->prev != NULL) {
				cout<<endl;
				cout << "----------------------------------" << endl;
				locateStr = locateStr->prev;
				cout << locateStr->data << endl;
				cout << "----------------------------------" << endl;

			}

		} //down
		else if (locateLine != NULL && click == 80) {
			if (locateLine->next != NULL) {
				cout<<endl;
				cout << "----------------------------------" << endl;
				locateLine = locateLine->next;
				cout << locateLine->data << endl;
				cout << "----------------------------------" << endl;

			}

		} else if (click == 4) {
			cout << " enter word to delete" << endl;
			string deletWord;
			cin >> deletWord;
			Node<string>* s = search(deletWord, allLines);
			if (s != NULL) {
				if (s->next != NULL) {
					locateStr = s->next;
				} else {
					locateStr = s->prev;
				}
				curLine->data.deleteNode(s);
				cout << "deleted! " << endl;

			} else {
				cout << "Not found inorder to delete  " << endl;
			}
		} else if (click == 5) {
			cout << "Good Bye! " << endl;
			break;
		} else if (click != -32) {
			cout << " invalid choice" << endl;
		}
	}
	getch();
	return 0;
}
