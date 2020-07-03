#include "PicrossSystem.h"
#include <iostream>
#include "Matrix.h"
#include <sstream>
#include <fstream>
#include <iostream>
using namespace std;

PicrossSystem::PicrossSystem()
{
	this->puzzles = new LinkedListPuzzle();
}

int PicrossSystem::insertOption(int options)
{
	int n;
	cout << "\tInserte una option: ";
	cin >> n;
	if (!cin) // o también if(cin.fail())
	{
		// El usuario no introdujo un número
		cin.clear(); // Borrar la entrada fallida
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //Saltar la entrada no válida
		// Aquí poner código para volver a pedirle al usuario que introduzca un número
	}

	if (n > options || n <= 0) {
		cout << "\t\tPor favor ingrese una opcion valida" << endl;
		return -1;
	}

	return n;
}

void PicrossSystem::readFiles()
{
	string line;
	ifstream file;
	file.open("soluciones.txt");

	if (file.fail()) {
		cout << " No se encontro el archivo soluciones.txt \n" << endl;
		exit(EXIT_FAILURE);
	}

	string name;
	string rows;
	string columns;

	while (getline(file, line)) {
		stringstream ss(line);
		getline(ss, name);
		//cout << name << endl;

		getline(file, line);
		stringstream ss2(line);
		getline(ss2, rows, ',');
		//cout << rows << " ";
		getline(ss2, columns, ',');
		//cout << columns << endl;

		int iRows = stoi(rows);
		int iColumns = stoi(columns);

		Matrix* matrix = new Matrix(iRows, iColumns);

		string line;

		for (int i = 1; i <= iRows; i++) {
			getline(file, line);
			stringstream ss3(line);
			for (int j = 1; j <= iColumns; j++) {
				string campo;
				getline(ss3, campo, ',');
				if (campo._Equal("B")) {
					matrix->addNode(1, i, j);
				}
				//cout << campo;
			}
			//cout << endl;
		}
		Puzzle* puzzle = new Puzzle(name, matrix);
		PuzzleNode* puzzleNode = new PuzzleNode(puzzle);
		this->puzzles->insert(puzzleNode);
		//matrix->print();

	}

	/*
	while (!text.eof()) {
		string name;
		string rows;
		getline(text, line);
		if (line != "") {
			stringstream ss(line);
			getline(ss, name);
			cout << "nombre: " << name << endl;
			getline(text, line);
			getline(ss, rows, ',');
			cout << "rows: " << rows << endl;
		}
	}
	*/
	file.close();
}

void PicrossSystem::mainMenu()
{
	readFiles();

	this->puzzles->getHead()->getNext()->getNext()->getNext()->getNext()->getNext()->getNext()->getPuzzle()->getMatrix()->print();

	while (true) {
		cout << "\t\tBienvenido al Sistema" << endl;
		cout << "\t[1] Mostrar soluciones" << endl;
		cout << "\t[2] Crear puzzle" << endl;
		cout << "\t[3] Modificar solucion" << endl;
		cout << "\t[4] Salir" << endl;

		switch (insertOption(4)) {
		case 1:
			solutionsMenu();
			break;
		case 2:
			puzzleMenu();
			break;
		case 3:
			modifyPuzzleMenu();
			break;
		case 4:
			save();
			break;
		}
	}
	
}

void PicrossSystem::solutionsMenu()
{
}

void PicrossSystem::puzzleMenu()
{
}

void PicrossSystem::modifyPuzzleMenu()
{
}

void PicrossSystem::save()
{
	cout << "\t\tXao que le baia bonito" << endl;
	exit(1);
}
