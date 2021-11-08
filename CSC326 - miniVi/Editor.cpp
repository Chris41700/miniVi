#include <iostream>
#include <fstream>
#include "Editor.h"

using namespace std;

Editor::Editor() {

}

Editor::Editor(string filename) {
	ifstream inFile;
	int linePosition = 0;
	string line;

	inFile.open(filename);

	if (!inFile) {
		cout << "Error opening the file." << endl;
		exit(1);
	}

	while (!inFile.eof()) {
		linePosition++;
		getline(inFile, line);
		lines.insert(linePosition, line);
	}

	inFile.close();

	displayLines();
}

void placeCursorAt(Position coordinate) {			//Starts at (0, 0)
	COORD coord;
	coord.X = coordinate.getX();
	coord.Y = coordinate.getY();
	SetConsoleCursorPosition(
		GetStdHandle(STD_OUTPUT_HANDLE),
		coord);
}

void Editor::displayLines() {
	for (int position = 1; position <= lines.getLength(); position++) {
		cout << lines.getEntry(position) << endl;
	}

	placeCursorAt(point);
}

void Editor::run() {
	char command;
	int bottom = lines.getLength() + 5;
	Position endOfScreen(0, bottom);
	command = _getwch();

	while (command != QUIT) {
		switch (command) {
		case 'x':					//Deletes character				

			break;
		case ':':					
			placeCursorAt(Position (endOfScreen));					//Brings cursor to bottom of the screen
			
			cout << ':';
			
			command = _getwche();									//Gets the next character enter by end-user
			
			if (command == 'w') {									//Saves file

			} 
			break;
		}
	}
}
