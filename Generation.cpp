#include <iostream>
#include <string>
#include <regex>
#include "windows.h"
using namespace std;

void add_ships(char** field, int field_size, int max_size_of_ship) {
	for (int size = max_size_of_ship; size > 0; size--) {
		for (int ammount = max_size_of_ship - size + 1; ammount > 0; ammount--) {
			while (1) {
				system("cls");
				print_field(field, field_size);
				cout << "Placing the ship: " << size << endl << "Left ammount: " << ammount << endl;
				int x, y;
				string str_direction;
				string row;
				regex row_rgx("^[a-z]{1}[0-9]+$");
				regex row_rgx_cap("^[A-Z]{1}[0-9]+$");

				cout << "Enter coordinates: ";
				getline(cin, row);
				if (regex_match(row, row_rgx)) {
					y = int(row[0] - 96);
					string a = row.erase(0, 1);
					x = stoi(a);
					if (x > field_size || y > field_size) {
						continue;
					}
				}
				else if (regex_match(row, row_rgx_cap)) {
					y = int(row[0] - 64);
					string a = row.erase(0, 1);
					x = stoi(a);
					if (x > field_size || y > field_size) {
						continue;
					}
				}
				else continue;

				if (x > field_size || y > field_size) {
					continue;
				}

				cout << "Enter direction (D - right, W - up, A - left, S - down): ";
				cin >> str_direction;
				int direction = 0;

				if (str_direction == "d" || str_direction == "D") direction = 1;
				else if (str_direction == "w" || str_direction == "W") direction = 2;
				else if (str_direction == "a" || str_direction == "A") direction = 3;
				else if (str_direction == "s" || str_direction == "S") direction = 4;

				int count = 0;
				switch (direction) {
				case 1:
					count = 0;
					if (x - 1 + size > field_size) {
						count++;
						break;
					}
					for (int i = 0; i < 1; i++) {
						for (int i = x - 1; i <= x + size; i++) {
							if (field[y - 1][i] == char(219)) {
								count++;
								break;
							}
						}
						if (count) break;
						for (int i = x - 1; i <= x + size; i++) {
							if (field[y][i] == char(219)) {
								count++;
								break;
							}
						}
						if (count) break;
						for (int i = x - 1; i <= x + size; i++) {
							if (field[y + 1][i] == char(219)) {
								count++;
								break;
							}
						}
					}
					if (!count) {
						for (int i = 0; i < size; i++) {
							field[y][x + i] = char(219);
						}
					}
					break;
				case 2:
					count = 0;
					if (y + 1 - size < 1) {
						count++;
						break;
					}
					for (int i = 0; i < 1; i++) {
						for (int i = y + 1; i >= y - size; i--) {
							if (field[i][x - 1] == char(219)) {
								count++;
								break;
							}
						}
						if (count) continue;
						for (int i = y + 1; i >= y - size; i--) {
							if (field[i][x] == char(219)) {
								count++;
								break;
							}
						}
						if (count) continue;
						for (int i = y + 1; i >= y - size; i--) {
							if (field[i][x + 1] == char(219)) {
								count++;
								break;
							}
						}
					}
					if (!count) {
						for (int i = 0; i < size; i++) {
							field[y - i][x] = char(219);
						}
					}
					break;
				case 3:
					count = 0;
					if (x + 1 - size < 1) {
						count++;
						break;
					}
					for (int i = 0; i < 1; i++) {
						for (int i = x - size; i <= x + 1; i++) {
							if (field[y - 1][i] == char(219)) {
								count++;
								break;
							}
						}
						if (count) break;
						for (int i = x - size; i <= x + 1; i++) {
							if (field[y][i] == char(219)) {
								count++;
								break;
							}
						}
						if (count) break;
						for (int i = x - size; i <= x + 1; i++) {
							if (field[y + 1][i] == char(219)) {
								count++;
								break;
							}
						}
					}
					if (!count) {
						for (int i = 0; i < size; i++) {
							field[y][x - i] = char(219);
						}
					}
					break;
				case 4:
					count = 0;
					if (y - 1 + size > field_size) {
						count++;
						break;
					}
					for (int i = 0; i < 1; i++) {
						for (int i = y - 1; i <= y + size; i++) {
							if (field[i][x - 1] == char(219)) {
								count++;
								break;
							}
						}
						if (count) continue;
						for (int i = y - 1; i <= y + size; i++) {
							if (field[i][x] == char(219)) {
								count++;
								break;
							}
						}
						if (count) continue;
						for (int i = y - 1; i <= y + size; i++) {
							if (field[i][x + 1] == char(219)) {
								count++;
								break;
							}
						}
					}
					if (!count) {
						for (int i = 0; i < size; i++) {
							field[y + i][x] = char(219);
						}
					}
					break;
				default:
					continue;
				}

				if (count) {
					continue;
				}
				break;
			}
		}
	}
	system("cls");
}









char** generate_field(int field_size, int max_size_of_ship, bool* error_check) {
	if (max_size_of_ship >= field_size) {
		cout << "The lack of space, try again.";
		*error_check = 1;
		return 0;
	}
	int flag_max_repeats = field_size * field_size * 10;            //the most optimal??
	int recreates_max_repeats = 30;                                 //the most optimal??

	char** field = new char* [field_size + 2];
	for (int i = 0; i < field_size + 2; i++) {
		field[i] = new char[field_size + 2];
	}
	int flag = 0;
	int recreates = 0;
	while (1) {
		for (int i = 0; i < field_size + 2; i++) {
			for (int j = 0; j < field_size + 2; j++) {
				field[i][j] = char(176);
			}
		}
		for (int size = max_size_of_ship; size > 0; size--) {
			for (int ammount = max_size_of_ship - size + 1; ammount > 0; ammount--) {
				flag = 0;
				while (1) {
					if (flag > flag_max_repeats) break;
					int x, y;
					int direction = rand() % 2 + 1;
					int count = 0;
					switch (direction) {
					case 1:
						x = rand() % (field_size - size + 1) + 1;
						y = rand() % field_size + 1;
						count = 0;
						for (int i = 0; i < 1; i++) {
							for (int i = x - 1; i <= x + size; i++) {
								if (field[y - 1][i] == char(219)) {
									count++;
									break;
								}
							}
							if (count) continue;
							for (int i = x - 1; i <= x + size; i++) {
								if (field[y][i] == char(219)) {
									count++;
									break;
								}
							}
							if (count) continue;
							for (int i = x - 1; i <= x + size; i++) {
								if (field[y + 1][i] == char(219)) {
									count++;
									break;
								}
							}
						}
						if (!count) {
							for (int i = 0; i < size; i++) {
								field[y][x + i] = char(219);
							}
						}
						break;
					case 2:
						x = rand() % field_size + 1;
						y = rand() % (field_size - size + 1) + size;
						count = 0;
						for (int i = 0; i < 1; i++) {
							for (int i = y + 1; i >= y - size; i--) {
								if (field[i][x - 1] == char(219)) {
									count++;
									break;
								}
							}
							if (count) continue;
							for (int i = y + 1; i >= y - size; i--) {
								if (field[i][x] == char(219)) {
									count++;
									break;
								}
							}
							if (count) continue;
							for (int i = y + 1; i >= y - size; i--) {
								if (field[i][x + 1] == char(219)) {
									count++;
									break;
								}
							}
						}
						if (!count) {
							for (int i = 0; i < size; i++) {
								field[y - i][x] = char(219);
							}
						}
						break;
					}
					if (count) {
						flag++;
						continue;
					}
					break;
				}
				if (flag > flag_max_repeats) break;
			}
			if (flag > flag_max_repeats) break;
		}
		if (flag <= flag_max_repeats) {
			break;
		}
		recreates++;
		if (recreates > recreates_max_repeats) {
			cout << "The lack of space, try again.";
			*error_check = 1;
			for (int i = 0; i < field_size + 2; i++) {
				delete[] field[i];
			}
			delete[] field;
			return 0;
		}
	}
	return field;
}



bool ship_capasity_test(int field_size, int max_size_of_ship) {
	bool error_check = 0;
	char** field = generate_field(field_size, max_size_of_ship, &error_check);
	if (error_check) return 0;
	else return 1;
}



int setFieldSize() {
	while (1) {
		int field_size = 0;
		string ent;
		cout << "Enter the field size (1-26): ";
		getline(cin, ent);
		try {
			field_size = stoi(ent);
		}
		catch (...) {
			system("cls");
			cout << "Try again." << endl;
			continue;
		}
		if (field_size > 1 && field_size <= 26) return field_size;;
		system("cls");
		cout << "Try again." << endl;
	}
}




int setMaxShip(int field_size) {
	while (1) {
		int max_size_of_ship;
		string msos;
		cout << "Enter the maximum size of the ship: ";
		getline(cin, msos);
		try {
			max_size_of_ship = stoi(msos);
		}
		catch (...) {
			system("cls");
			cout << "Try again." << endl;
			cout << "Enter the field size (1-26): " << field_size << endl;
			continue;
		}
		if (ship_capasity_test(field_size, max_size_of_ship)) return max_size_of_ship;
		system("cls");
		cout << "Try again." << endl << "Enter the field size (1-26): " << field_size << endl;
	}
}
