#include <iostream>
#include <string>
#include "windows.h"
#include <conio.h>
#include "Generation.h"
using namespace std;





int main() {
	// Setting field size and maximum size of ship
	srand(time(0));
	int field_size = setFieldSize();
	int max_size_of_ship = setMaxShip(field_size);
	system("cls");


	string next;


	string name_1;
	string name_2;
	int player_1_left_hits = number_of_hits(max_size_of_ship);
	int player_2_left_hits = player_1_left_hits;
	char** player_1_field;
	char** player_1_attack_field;
	char** player_2_field;
	char** player_2_attack_field;


	string check_ans;


	// Gamemode with showing only attack field or both fields
	bool show_your_field = showYourField();


	// Setting names of players, generation of field and ship placement
	cout << "Player 1" << endl << "Enter name: ";
	getline(cin, name_1);
	system("cls");

	while (1) {
		cout << name_1 << endl;
		cout << "Generate field automaticly? Y-N" << endl;
		getline(cin, check_ans);
		if (check_ans == "Y" || check_ans == "y") {
			bool error_check = 0;
			player_1_field = generate_field(field_size, max_size_of_ship, &error_check);
			if (error_check) return 1;
			player_1_attack_field = generate_new_field(field_size);
			system("cls");
			while (1) {
				cout << name_1 << endl << endl;
				print_field(player_1_field, field_size);
				next.clear();
				cout << "Press E to continue" << endl << "Press Q to quit the game" << endl;
				getline(cin, next);
				if (next == "q" || next == "Q") {
					delete_field(player_1_field, field_size);
					delete_field(player_1_attack_field, field_size);
					return 1;
				}
				else if (next == "e" || next == "E") break;
				else system("cls");
			}
			break;
		}
		else if (check_ans == "N" || check_ans == "n") {
			player_1_field = generate_new_field(field_size);
			player_1_attack_field = generate_new_field(field_size);
			add_ships(player_1_field, field_size, max_size_of_ship);
			system("cls");
			while (1) {
				cout << name_1 << endl << endl;
				print_field(player_1_field, field_size);
				next.clear();
				cout << "Press E to continue" << endl << "Press Q to quit the game" << endl;
				getline(cin, next);
				if (next == "q" || next == "Q") {
					delete_field(player_1_field, field_size);
					delete_field(player_1_attack_field, field_size);
					return 1;
				}
				else if (next == "e" || next == "E") break;
				else system("cls");
			}
			break;
		}
		system("cls");
	}
	system("cls");

	cout << "Player 2" << endl << "Enter name: ";
	getline(cin, name_2);
	system("cls");
	while (1) {
		cout << name_2 << endl;
		cout << "Generate field automaticly? Y-N" << endl;
		getline(cin, check_ans);
		if (check_ans == "Y" || check_ans == "y") {
			bool error_check = 0;
			player_2_field = generate_field(field_size, max_size_of_ship, &error_check);
			if (error_check) return 1;
			player_2_attack_field = generate_new_field(field_size);
			system("cls");
			while (1) {
				cout << name_2 << endl << endl;
				print_field(player_2_field, field_size);
				next.clear();
				cout << "Press E to continue" << endl << "Press Q to quit the game" << endl;
				getline(cin, next);
				if (next == "q" || next == "Q") {
					delete_field(player_1_field, field_size);
					delete_field(player_1_attack_field, field_size);
					delete_field(player_2_field, field_size);
					delete_field(player_2_attack_field, field_size);
					return 1;
				}
				else if (next == "e" || next == "E") break;
				else system("cls");
			}
			break;
		}
		else if (check_ans == "N" || check_ans == "n") {
			player_2_field = generate_new_field(field_size);
			player_2_attack_field = generate_new_field(field_size);
			add_ships(player_2_field, field_size, max_size_of_ship);
			system("cls");
			while (1) {
				cout << name_2 << endl << endl;
				print_field(player_2_field, field_size);
				next.clear();
				cout << "Press E to continue" << endl << "Press Q to quit the game" << endl;
				getline(cin, next);
				if (next == "q" || next == "Q") {
					delete_field(player_1_field, field_size);
					delete_field(player_1_attack_field, field_size);
					delete_field(player_2_field, field_size);
					delete_field(player_2_attack_field, field_size);
					return 1;
				}
				else if (next == "e" || next == "E") break;
				else system("cls");
			}
			break;
		}
		system("cls");
	}



	// Game starts
	int check_hit;
	next.clear();
	while (1) {


		if (show_your_field) {
			system("cls");
			while (1) {
				cout << name_1 << ", your turn, press E to continue, press Q to quit the game" << endl;
				getline(cin, next);
				if (next == "e" || next == "E" || next == "q" || next == "Q") break;
				system("cls");
				cout << "Try again" << endl;
			}
		}


		while (1) {
			system("cls");
			cout << name_1 << endl << endl;
			switch (show_your_field) {
			case 0:
				print_field(player_1_attack_field, field_size);
				break;
			case 1:
				print_field_horizontically(player_1_field, player_1_attack_field, field_size);
				break;
			}
			if (!player_1_left_hits || next == "q" || next == "Q")	break;


			check_hit = player_1_left_hits;
			bool error_check = 0;
			if (GetAsyncKeyState(VK_SPACE) != 0) {
				continue;
			}
			try {
				arrow_keys_attack(player_1_attack_field, player_2_field, field_size, &player_1_left_hits);
			}
			catch (...) {
				continue;
			}
			if (!player_1_left_hits) {
				break;
			}
			if (check_hit - player_1_left_hits) continue;
			system("cls");
			cout << name_1 << endl << endl;
			switch (show_your_field) {
			case 0:
				print_field(player_1_attack_field, field_size);
				break;
			case 1:
				print_field_horizontically(player_1_field, player_1_attack_field, field_size);
				break;
			}

			while (1) {
				cout << "Press E to continue." << endl << "Press Q to stop the game." << endl;
				getline(cin, next);
				if (next == "e" || next == "E" || next == "q" || next == "Q") break;
				system("cls");
				cout << name_1 << endl << endl;
				switch (show_your_field) {
				case 0:
					print_field(player_1_attack_field, field_size);
					break;
				case 1:
					print_field_horizontically(player_1_field, player_1_attack_field, field_size);
					break;
				}
			}
			if (next == "e" || next == "E" || next == "q" || next == "Q") break;
		}
		if (!player_1_left_hits || next == "q" || next == "Q")	break;

		if (show_your_field) {
			system("cls");
			while (1) {
				cout << name_2 << ", your turn, press E to continue, press Q to quit the game" << endl;
				getline(cin, next);
				if (next == "e" || next == "E" || next == "q" || next == "Q") break;
				system("cls");
				cout << "Try again" << endl;
			}
		}
		if (!player_1_left_hits || next == "q" || next == "Q")	break;





		while (1) {
			system("cls");
			cout << name_2 << endl << endl;
			switch (show_your_field) {
			case 0:
				print_field(player_2_attack_field, field_size);
				break;
			case 1:
				print_field_horizontically(player_2_field, player_2_attack_field, field_size);
				break;
			}
			check_hit = player_2_left_hits;
			bool error_check = 0;
			if (GetAsyncKeyState(VK_SPACE) != 0) {
				continue;
			}
			try {
				arrow_keys_attack(player_2_attack_field, player_1_field, field_size, &player_2_left_hits);
			}
			catch (...) {
				continue;
			}
			if (!player_2_left_hits) {
				break;
			}
			if (check_hit - player_2_left_hits) {
				continue;
			}
			system("cls");
			cout << name_2 << endl << endl;
			switch (show_your_field) {
			case 0:
				print_field(player_2_attack_field, field_size);
				break;
			case 1:
				print_field_horizontically(player_2_field, player_2_attack_field, field_size);
				break;
			}

			while (1) {
				cout << "Press E to continue." << endl << "Press Q to stop the game." << endl;
				getline(cin, next);
				if (next == "e" || next == "E" || next == "q" || next == "Q") break;
				system("cls");
				cout << name_2 << endl << endl;
				switch (show_your_field) {
				case 0:
					print_field(player_2_attack_field, field_size);
					break;
				case 1:
					print_field_horizontically(player_2_field, player_2_attack_field, field_size);
					break;
				}
			}
			if (next == "e" || next == "E" || next == "q" || next == "Q") break;
		}
		if (!player_2_left_hits || next == "q" || next == "Q")	break;
	}

	// The end of the game. Winner determination.
	if (!player_1_left_hits) {
		system("cls");
		cout << name_1 << " WON!";
		Sleep(2000);
		system("cls");
		cout << name_1 << " -- WINNER" << endl << endl;
		print_field_horizontically(player_1_field, player_1_attack_field, field_size);
		cout << endl << endl << endl;
		cout << name_2 << endl << endl;
		print_field_horizontically(player_2_field, player_2_attack_field, field_size);
	}
	else if (!player_2_left_hits) {
		system("cls");
		cout << name_2 << " WON!";
		Sleep(2000);
		system("cls");
		cout << name_1 << endl << endl;
		print_field_horizontically(player_1_field, player_1_attack_field, field_size);
		cout << endl << endl << endl;
		cout << name_2 << " -- WINNER" << endl << endl;
		print_field_horizontically(player_2_field, player_2_attack_field, field_size);
	}
	else {
		system("cls");
		cout << name_1 << endl << endl;
		print_field_horizontically(player_1_field, player_1_attack_field, field_size);
		cout << endl << endl << endl;
		cout << name_2 << endl << endl;
		print_field_horizontically(player_2_field, player_2_attack_field, field_size);
	}

	// Clearing memory
	delete_field(player_1_field, field_size);
	delete_field(player_1_attack_field, field_size);
	delete_field(player_2_field, field_size);
	delete_field(player_2_attack_field, field_size);

	//Press any key to end
	cout << "Press any key to end the game." << endl;
	_getch();
}