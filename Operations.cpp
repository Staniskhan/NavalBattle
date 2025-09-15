#include <iostream>
#include <string>
#include <regex>
#include "windows.h" //_____________
using namespace std;





void print_el(int x_start, int y_start, int x, int y, char el) {
	int a;
	HANDLE hCon;
	COORD cPos;

	hCon = GetStdHandle(STD_OUTPUT_HANDLE);
	cPos.Y = y_start + (y - 1) * 2;
	cPos.X = x_start + (x - 1) * 4;
	SetConsoleCursorPosition(hCon, cPos);

	if (el == char(176)) {
		cout << char(176) << char(176) << char(176) << char(176);
		cPos.Y++;
		SetConsoleCursorPosition(hCon, cPos);
		cout << char(176) << char(176) << char(176) << char(176);
		cPos.Y--;
		SetConsoleCursorPosition(hCon, cPos);
	}
	else if (el == 'h') {
		cout << '#' << '#' << '#' << '#';
		cPos.Y++;
		SetConsoleCursorPosition(hCon, cPos);
		cout << '#' << '#' << '#' << '#';
		cPos.Y--;
		SetConsoleCursorPosition(hCon, cPos);
	}
	else if (el == 'm') {
		cout << ' ' << '\\' << '/' << ' ';
		cPos.Y++;
		SetConsoleCursorPosition(hCon, cPos);
		cout << ' ' << '/' << '\\' << ' ';
		cPos.Y--;
		SetConsoleCursorPosition(hCon, cPos);
	}
	else if (el == 'c') {
		cout << char(201) << char(205) << char(205) << char(187);
		cPos.Y++;
		SetConsoleCursorPosition(hCon, cPos);
		cout << char(200) << char(205) << char(205) << char(188);
		cPos.Y--;
		SetConsoleCursorPosition(hCon, cPos);
	}
	else if (el == 'a') {
		cout << char(218) << char(196) << char(196) << char(191);
		cPos.Y++;
		SetConsoleCursorPosition(hCon, cPos);
		cout << char(192) << char(196) << char(196) << char(217);
		cPos.Y--;
		SetConsoleCursorPosition(hCon, cPos);
	}
}





bool showYourField() {
	while (1) {
		string showYourFieldStr;
		cout << "Choose whether to show only the attack field (Q) or both fields (E)" << endl;
		getline(cin, showYourFieldStr);
		if (showYourFieldStr == "e" || showYourFieldStr == "E") {
			system("cls");
			return 1;
		}
		else if (showYourFieldStr == "q" || showYourFieldStr == "Q") {
			system("cls");
			return 0;
		}
		else {
			system("cls");
			cout << "Try again" << endl;
		}
	}
}




void print_field_horizontically(char** field, char** attack_field, int field_size) {
	cout << " Your field.";
	for (int i = field_size + 1; i > 0; i--) {
		cout << "    ";
	}

	cout << " Enemy's field." << endl;
	cout << "    ";
	for (int fs = 1; fs <= field_size; fs++) {
		cout << fs;
		if (fs < 10) cout << "   ";
		else if (fs >= 10 && fs < 100) cout << "  ";
		else if (fs >= 100) cout << ' ';
	}
	cout << "          ";
	cout << "      ";
	for (int fs = 1; fs <= field_size; fs++) {
		cout << fs;
		if (fs < 10) cout << "   ";
		else if (fs >= 10 && fs < 100) cout << "  ";
		else if (fs >= 100) cout << ' ';
	}
	cout << endl;

	cout << ' ' << char(201);
	for (int i = field_size * 4 + 2; i > 0; i--) {
		cout << char(205);
	}
	cout << char(187);
	cout << "           ";
	cout << ' ' << char(201);
	for (int i = field_size * 4 + 2; i > 0; i--) {
		cout << char(205);
	}
	cout << char(187);
	cout << endl;

	for (int i = 0; i < field_size; i++) {
		cout << char(i + 65) << char(186) << ' ';
		string dbl;
		for (int j = 0; j < field_size; j++) {
			if (field[i + 1][j + 1] == char(219)) {
				cout << char(219) << char(219) << char(219) << char(219);
				dbl += char(219);
				dbl += char(219);
				dbl += char(219);
				dbl += char(219);
			}
			else if (field[i + 1][j + 1] == char(176)) {
				cout << char(176) << char(176) << char(176) << char(176);
				dbl += char(176);
				dbl += char(176);
				dbl += char(176);
				dbl += char(176);
			}
			else if (field[i + 1][j + 1] == 'm') {
				cout << ' ' << '\\' << '/' << ' ';
				dbl += ' ';
				dbl += '/';
				dbl += '\\';
				dbl += ' ';
			}
			else if (field[i + 1][j + 1] == 'h') {
				cout << '#' << '#' << '#' << '#';
				dbl += '#';
				dbl += '#';
				dbl += '#';
				dbl += '#';
			}
		}
		cout << ' ' << char(186) << char(i + 65);
		cout << "          ";
		cout << char(i + 65) << char(186) << ' ';
		string dbl_att;
		for (int j = 0; j < field_size; j++) {
			if (attack_field[i + 1][j + 1] == char(219)) {
				cout << char(219) << char(219) << char(219) << char(219);
				dbl_att += char(219);
				dbl_att += char(219);
				dbl_att += char(219);
				dbl_att += char(219);
			}
			else if (attack_field[i + 1][j + 1] == char(176)) {
				cout << char(176) << char(176) << char(176) << char(176);
				dbl_att += char(176);
				dbl_att += char(176);
				dbl_att += char(176);
				dbl_att += char(176);
			}
			else if (attack_field[i + 1][j + 1] == 'm') {
				cout << ' ' << '\\' << '/' << ' ';
				dbl_att += ' ';
				dbl_att += '/';
				dbl_att += '\\';
				dbl_att += ' ';
			}
			else if (attack_field[i + 1][j + 1] == 'h') {
				cout << '#' << '#' << '#' << '#';
				dbl_att += '#';
				dbl_att += '#';
				dbl_att += '#';
				dbl_att += '#';
			}
		}
		cout << ' ' << char(186) << char(i + 65);
		cout << endl;
		cout << '_' << char(186) << '_' << dbl << '_' << char(186) << '_';
		cout << "          ";
		cout << '_' << char(186) << '_' << dbl_att << '_' << char(186) << '_';
		cout << endl;
	}

	cout << ' ' << char(200);
	for (int i = field_size * 4 + 2; i > 0; i--) {
		cout << char(205);
	}
	cout << char(188);
	cout << "           ";
	cout << ' ' << char(200);
	for (int i = field_size * 4 + 2; i > 0; i--) {
		cout << char(205);
	}
	cout << char(188);
	cout << endl;

	cout << "    ";
	for (int fs = 1; fs <= field_size; fs++) {
		cout << fs;
		if (fs < 10) cout << "   ";
		else if (fs >= 10 && fs < 100) cout << "  ";
		else if (fs >= 100) cout << ' ';
	}
	cout << "          ";
	cout << "      ";
	for (int fs = 1; fs <= field_size; fs++) {
		cout << fs;
		if (fs < 10) cout << "   ";
		else if (fs >= 10 && fs < 100) cout << "  ";
		else if (fs >= 100) cout << ' ';
	}
	cout << endl;
}




void print_field(char** field, int field_size) {
	cout << "    ";
	for (int fs = 1; fs <= field_size; fs++) {
		cout << fs;
		if (fs < 10) cout << "   ";
		else if (fs >= 10 && fs < 100) cout << "  ";
		else if (fs >= 100) cout << ' ';
	}
	cout << endl;

	cout << ' ' << char(201);
	for (int i = field_size * 4 + 2; i > 0; i--) {
		cout << char(205);
	}
	cout << char(187) << endl;

	for (int i = 0; i < field_size; i++) {
		cout << char(i + 65) << char(186) << ' ';
		string dbl;
		for (int j = 0; j < field_size; j++) {
			if (field[i + 1][j + 1] == char(219)) {
				cout << char(219) << char(219) << char(219) << char(219);
				dbl += char(219);
				dbl += char(219);
				dbl += char(219);
				dbl += char(219);
			}
			else if (field[i + 1][j + 1] == char(176)) {
				cout << char(176) << char(176) << char(176) << char(176);
				dbl += char(176);
				dbl += char(176);
				dbl += char(176);
				dbl += char(176);
			}
			else if (field[i + 1][j + 1] == 'm') {
				cout << ' ' << '\\' << '/' << ' ';
				dbl += ' ';
				dbl += '/';
				dbl += '\\';
				dbl += ' ';
			}
			else if (field[i + 1][j + 1] == 'h') {
				cout << '#' << '#' << '#' << '#';
				dbl += '#';
				dbl += '#';
				dbl += '#';
				dbl += '#';
			}
		}
		cout << ' ' << char(186) << char(i + 65);
		cout << endl << '_' << char(186) << '_' << dbl << '_' << char(186) << '_' << endl;
	}

	cout << ' ' << char(200);
	for (int i = field_size * 4 + 2; i > 0; i--) {
		cout << char(205);
	}
	cout << char(188) << endl;

	cout << "    ";
	for (int fs = 1; fs <= field_size; fs++) {
		cout << fs;
		if (fs < 10) cout << "   ";
		else if (fs >= 10 && fs < 100) cout << "  ";
		else if (fs >= 100) cout << ' ';
	}
	cout << endl;
}



char** generate_new_field(int field_size) {
	char** field = new char* [field_size + 2];
	for (int i = 0; i < field_size + 2; i++) {
		field[i] = new char[field_size + 2];
	}
	for (int i = 0; i < field_size + 2; i++) {
		for (int j = 0; j < field_size + 2; j++) {
			field[i][j] = char(176);
		}
	}
	return field;
}





char** clearing(char** field, int field_size) {
	for (int i = 0; i < field_size + 2; i++) {
		for (int j = 0; j < field_size + 2; j++) {
			field[i][j] = char(176);
		}
	}
	return field;
}




void delete_field(char** field, int field_size) {
	for (int i = 0; i < field_size + 2; i++) {
		delete[] field[i];
	}
	delete[] field;
}


bool check_destruction(char** attack_field, char** field, int x, int y) {
	if (field[y + 1][x] == char(219) || field[y][x + 1] == char(219) || field[y - 1][x] == char(219) || field[y][x - 1] == char(219)) return 0;
	if ((field[y + 1][x] == 'm' || field[y + 1][x] == char(176)) && (field[y][x + 1] == 'm' || field[y][x + 1] == char(176)) && (field[y - 1][x] == 'm' || field[y - 1][x] == char(176)) && (field[y][x - 1] == 'm' || field[y][x - 1] == char(176))) {    // SINGLE SHIP
		field[y - 1][x - 1] = 'm';
		field[y - 1][x] = 'm';
		field[y - 1][x + 1] = 'm';
		field[y][x - 1] = 'm';
		field[y][x + 1] = 'm';
		field[y + 1][x - 1] = 'm';
		field[y + 1][x] = 'm';
		field[y + 1][x + 1] = 'm';

		attack_field[y - 1][x - 1] = 'm';
		attack_field[y - 1][x] = 'm';
		attack_field[y - 1][x + 1] = 'm';
		attack_field[y][x - 1] = 'm';
		attack_field[y][x + 1] = 'm';
		attack_field[y + 1][x - 1] = 'm';
		attack_field[y + 1][x] = 'm';
		attack_field[y + 1][x + 1] = 'm';
		return 1;
	}
	if (field[y + 1][x] == 'h' && (field[y - 1][x] == 'm' || field[y - 1][x] == char(176))) { // DOWN
		for (int i = 1; field[y - 1 + i][x] == 'h'; i++) {
			if (field[y + i][x] == 'h') continue;
			else if (field[y + i][x] == char(219)) return 0;
			else if (field[y + i][x] == char(176) || field[y + i][x] == 'm') {
				field[y - 1][x - 1] = 'm';
				field[y - 1][x] = 'm';
				field[y - 1][x + 1] = 'm';
				field[y + i][x - 1] = 'm';
				field[y + i][x] = 'm';
				field[y + i][x + 1] = 'm';
				attack_field[y - 1][x - 1] = 'm';
				attack_field[y - 1][x] = 'm';
				attack_field[y - 1][x + 1] = 'm';
				attack_field[y + i][x - 1] = 'm';
				attack_field[y + i][x] = 'm';
				attack_field[y + i][x + 1] = 'm';
				i--;
				for (; i >= 0; i--) {
					field[y + i][x - 1] = 'm';
					field[y + i][x + 1] = 'm';
					attack_field[y + i][x - 1] = 'm';
					attack_field[y + i][x + 1] = 'm';
				}
				break;
			}
		}
	}
	if (field[y - 1][x] == 'h' && (field[y + 1][x] == 'm' || field[y + 1][x] == char(176))) { // UP
		for (int i = 1; field[y + 1 - i][x] == 'h'; i++) {
			if (field[y - i][x] == 'h') continue;
			else if (field[y - i][x] == char(219)) return 0;
			else if (field[y - i][x] == char(176) || field[y - i][x] == 'm') {
				field[y + 1][x - 1] = 'm';
				field[y + 1][x] = 'm';
				field[y + 1][x + 1] = 'm';
				field[y - i][x - 1] = 'm';
				field[y - i][x] = 'm';
				field[y - i][x + 1] = 'm';
				attack_field[y + 1][x - 1] = 'm';
				attack_field[y + 1][x] = 'm';
				attack_field[y + 1][x + 1] = 'm';
				attack_field[y - i][x - 1] = 'm';
				attack_field[y - i][x] = 'm';
				attack_field[y - i][x + 1] = 'm';
				i--;
				for (; i >= 0; i--) {
					field[y - i][x - 1] = 'm';
					field[y - i][x + 1] = 'm';
					attack_field[y - i][x - 1] = 'm';
					attack_field[y - i][x + 1] = 'm';
				}
				break;
			}
		}
	}
	if (field[y][x + 1] == 'h' && (field[y][x - 1] == 'm' || field[y][x - 1] == char(176))) { // RIGHT
		for (int i = 1; field[y][x - 1 + i] == 'h'; i++) {
			if (field[y][x + i] == 'h') continue;
			else if (field[y][x + i] == char(219)) return 0;
			else if (field[y][x + i] == char(176) || field[y][x + i] == 'm') {
				field[y - 1][x - 1] = 'm';
				field[y][x - 1] = 'm';
				field[y + 1][x - 1] = 'm';
				field[y - 1][x + i] = 'm';
				field[y][x + i] = 'm';
				field[y + 1][x + i] = 'm';
				attack_field[y - 1][x - 1] = 'm';
				attack_field[y][x - 1] = 'm';
				attack_field[y + 1][x - 1] = 'm';
				attack_field[y - 1][x + i] = 'm';
				attack_field[y][x + i] = 'm';
				attack_field[y + 1][x + i] = 'm';
				i--;
				for (; i >= 0; i--) {
					field[y - 1][x + i] = 'm';
					field[y + 1][x + i] = 'm';
					attack_field[y - 1][x + i] = 'm';
					attack_field[y + 1][x + i] = 'm';
				}
				break;
			}
		}
	}
	if (field[y][x - 1] == 'h' && (field[y][x + 1] == 'm' || field[y][x + 1] == char(176))) { // LEFT
		for (int i = 1; field[y][x + 1 - i] == 'h'; i++) {
			if (field[y][x - i] == 'h') continue;
			else if (field[y][x - i] == char(219)) return 0;
			else if (field[y][x - i] == char(176) || field[y][x - i] == 'm') {
				field[y - 1][x + 1] = 'm';
				field[y][x + 1] = 'm';
				field[y + 1][x + 1] = 'm';
				field[y - 1][x - i] = 'm';
				field[y][x - i] = 'm';
				field[y + 1][x - i] = 'm';
				attack_field[y - 1][x + 1] = 'm';
				attack_field[y][x + 1] = 'm';
				attack_field[y + 1][x + 1] = 'm';
				attack_field[y - 1][x - i] = 'm';
				attack_field[y][x - i] = 'm';
				attack_field[y + 1][x - i] = 'm';
				i--;
				for (; i >= 0; i--) {
					field[y - 1][x - i] = 'm';
					field[y + 1][x - i] = 'm';
					attack_field[y - 1][x - i] = 'm';
					attack_field[y + 1][x - i] = 'm';
				}
				break;
			}
		}
	}
	if (field[y][x - 1] == 'h' && field[y][x + 1] == 'h') { // LEFT & RIGHT
		int checkLeft, checkRight;
		for (int i = 1; field[y][x + 1 - i] == 'h'; i++) {
			if (field[y][x - i] == 'h') continue;
			else if (field[y][x - i] == char(219)) return 0;
			else if (field[y][x - i] == char(176) || field[y][x - i] == 'm') {
				checkLeft = i;
				break;
			}
		}
		for (int i = 1; field[y][x - 1 + i] == 'h'; i++) {
			if (field[y][x + i] == 'h') continue;
			else if (field[y][x + i] == char(219)) return 0;
			else if (field[y][x + i] == char(176) || field[y][x + i] == 'm') {
				checkRight = i;
				break;
			}
		}
		field[y - 1][x - checkLeft] = 'm';
		field[y][x - checkLeft] = 'm';
		field[y + 1][x - checkLeft] = 'm';
		attack_field[y - 1][x - checkLeft] = 'm';
		attack_field[y][x - checkLeft] = 'm';
		attack_field[y + 1][x - checkLeft] = 'm';
		checkLeft--;
		for (; checkLeft > 0; checkLeft--) {
			field[y - 1][x - checkLeft] = 'm';
			field[y + 1][x - checkLeft] = 'm';
			attack_field[y - 1][x - checkLeft] = 'm';
			attack_field[y + 1][x - checkLeft] = 'm';
		}
		field[y - 1][x + checkRight] = 'm';
		field[y][x + checkRight] = 'm';
		field[y + 1][x + checkRight] = 'm';
		attack_field[y - 1][x + checkRight] = 'm';
		attack_field[y][x + checkRight] = 'm';
		attack_field[y + 1][x + checkRight] = 'm';
		checkRight--;
		for (; checkRight >= 0; checkRight--) {
			field[y - 1][x + checkRight] = 'm';
			field[y + 1][x + checkRight] = 'm';
			attack_field[y - 1][x + checkRight] = 'm';
			attack_field[y + 1][x + checkRight] = 'm';
		}
	}
	if (field[y - 1][x] == 'h' && field[y + 1][x] == 'h') { // UP & DOWN
		int checkUp, checkDown;
		for (int i = 1; field[y + 1 - i][x] == 'h'; i++) {
			if (field[y - i][x] == 'h') continue;
			else if (field[y - i][x] == char(219)) return 0;
			else if (field[y - i][x] == char(176) || field[y - i][x] == 'm') {
				checkUp = i;
				break;
			}
		}
		for (int i = 1; field[y - 1 + i][x] == 'h'; i++) {
			if (field[y + i][x] == 'h') continue;
			else if (field[y + i][x] == char(219)) return 0;
			else if (field[y + i][x] == char(176) || field[y + i][x] == 'm') {
				checkDown = i;
				break;
			}
		}
		field[y - checkUp][x - 1] = 'm';
		field[y - checkUp][x] = 'm';
		field[y - checkUp][x + 1] = 'm';
		attack_field[y - checkUp][x - 1] = 'm';
		attack_field[y - checkUp][x] = 'm';
		attack_field[y - checkUp][x + 1] = 'm';
		checkUp--;
		for (; checkUp > 0; checkUp--) {
			field[y - checkUp][x - 1] = 'm';
			field[y - checkUp][x + 1] = 'm';
			attack_field[y - checkUp][x - 1] = 'm';
			attack_field[y - checkUp][x + 1] = 'm';
		}
		field[y + checkDown][x - 1] = 'm';
		field[y + checkDown][x] = 'm';
		field[y + checkDown][x + 1] = 'm';
		attack_field[y + checkDown][x - 1] = 'm';
		attack_field[y + checkDown][x] = 'm';
		attack_field[y + checkDown][x + 1] = 'm';
		checkDown--;
		for (; checkDown >= 0; checkDown--) {
			field[y + checkDown][x - 1] = 'm';
			field[y + checkDown][x + 1] = 'm';
			attack_field[y + checkDown][x - 1] = 'm';
			attack_field[y + checkDown][x + 1] = 'm';
		}
	}
}




char** attack(char** attack_field, char** field, int field_size, int* left_hits, bool* error_check) {
	int x, y;
	while (1) {
		string row;
		regex row_rgx("^[a-z]{1}[0-9]+$");
		regex row_rgx_cap("^[A-Z]{1}[0-9]+$");

		cout << "Enter coordinates: ";
		getline(cin, row);
		if (regex_match(row, row_rgx)) {
			y = int(row[0] - 96);
			string a = row.erase(0, 1);
			x = stoi(a);
			if (x > field_size || y > field_size || x <= 0 || y <= 0) {
				*error_check = 1;
				return 0;
			}
		}
		else if (regex_match(row, row_rgx_cap)) {
			y = int(row[0] - 64);
			string a = row.erase(0, 1);
			x = stoi(a);
			if (x > field_size || y > field_size || x <= 0 || y <= 0) {
				*error_check = 1;
				return 0;
			}
		}
		else {
			*error_check = 1;
			return 0;
		}
		break;
	}



	if (x > field_size || y > field_size || x <= 0 || y <= 0) {
		*error_check = 1;                                                             //throw("You've gone out of the field")
		return 0;
	}
	if (field[y][x] == 'm' || field[y][x] == 'h') {
		*error_check = 1;                                                             //throw("You've already fired here");
		return 0;
	}
	if (field[y][x] == char(219)) {
		field[y][x] = 'h';
		attack_field[y][x] = 'h';
		*left_hits -= 1;
		check_destruction(attack_field, field, x, y);
	}
	if (field[y][x] == char(176)) {
		field[y][x] = 'm';
		attack_field[y][x] = 'm';
	}
	return field;
}





int number_of_hits(int max_size_of_ship) {
	int ans = 0;
	for (int size = max_size_of_ship; size > 0; size--) {
		for (int ammount = max_size_of_ship - size + 1; ammount > 0; ammount--) {
			ans += size;
		}
	}
	return ans;
}



// attack(player_1_attack_field, player_2_field, field_size, &player_1_left_hits, &error_check);
// arrow_keys_attack(player_1_attack_field, player_2_field, field_size, &left_hits);
char** arrow_keys_attack(char** attack_field, char** field, int field_size, int* left_hits) {
	HANDLE hCon;
	COORD cPos;
	int x = 1, y = 1;
	char buffer;

	int x_start = 9 + field_size*4 + 10;
	int y_start = 5;

	buffer = attack_field[y][x];
	print_el(x_start, y_start, x, y, 'c');
	int periods = 0;
	char cursor = 'c';

	while (1)
	{
		if (periods > 4) {
			if (cursor == 'c') {
				cursor = 'a';
				print_el(x_start, y_start, x, y, cursor);
			}
			else if (cursor == 'a') {
				cursor = 'c';
				print_el(x_start, y_start, x, y, cursor);
			}
			periods = 0;
		}
		if (GetAsyncKeyState(VK_RIGHT) != 0) {
			if (x + 1 > field_size) continue;
			print_el(x_start, y_start, x, y, buffer);
			x++;
			buffer = attack_field[y][x];
			print_el(x_start, y_start, x, y, cursor);
		}
		if (GetAsyncKeyState(VK_LEFT) != 0) {
			if (x - 1 < 1) continue;
			print_el(x_start, y_start, x, y, buffer);
			x--;
			buffer = attack_field[y][x];
			print_el(x_start, y_start, x, y, cursor);
		}
		if (GetAsyncKeyState(VK_UP) != 0) {
			if (y - 1 < 1) continue;
			print_el(x_start, y_start, x, y, buffer);
			y--;
			buffer = attack_field[y][x];
			print_el(x_start, y_start, x, y, cursor);
		}
		if (GetAsyncKeyState(VK_DOWN) != 0) {
			if (y + 1 > field_size) continue;
			print_el(x_start, y_start, x, y, buffer);
			y++;
			buffer = attack_field[y][x];
			print_el(x_start, y_start, x, y, cursor);
		}
		if (GetAsyncKeyState(VK_SPACE) != 0) {
			if (field[y][x] == char(219)) {
				field[y][x] = 'h';
				attack_field[y][x] = 'h';
				*left_hits -= 1;
				check_destruction(attack_field, field, x, y);
			}
			else if (field[y][x] == char(176)) {
				field[y][x] = 'm';
				attack_field[y][x] = 'm';
			}
			else if (attack_field[y][x] == 'm' || attack_field[y][x] == 'h') {
				throw("You've already fired here");
			}
			return field;
		}
		Sleep(100);
		periods++;
	}


}