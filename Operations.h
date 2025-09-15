#include "Operations.cpp"

class Game {
private:

public:
    bool showYourField();                                                                                      // Suggests to chose gamemode (showing only attack field or both your and attack field). 
    // Returns 0 in case player has chosen gamemode with showing only attack field and 1 -- with both.
    void print_field_horizontically(char** field, char** attack_field, int field_size);                        // Print 2 fields one by one.
    void print_field(char** field, int field_size);                                                            // Print field.
    char** generate_new_field(int field_size);                                                                 // Generate new field filled with "sea".
    char** clearing(char** field, int field_size);                                                             // Filling field with "sea".
    void delete_field(char** field, int field_size);                                                           // Deletes field, clears memory.
    bool check_destruction(char** attack_field, char** field, int x, int y);                                   // Checks whether the ship is completely destroyed or only part of it.
    // If the ship is completely destroyed, it circles the cells around it with "misses".
    char** attack(char** attack_field, char** field, int field_size, int* left_hits, bool* error_check);       // Is used to make attack
    int number_of_hits(int max_size_of_ship);                                                                  // Counts the number of decks of all ships
    void print_el(int x_start, int y_start, int x, int y, char el);                                            // Prints one cell of field (size 4*2)
    char** arrow_keys_attack(char** attack_field, char** field, int* left_hits);                               // Attack with arrow keys
};