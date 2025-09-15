#include "Operations.h"
#include "Generation.cpp"

void add_ships(char** field, int field_size, int max_size_of_ship);               // Manual ship placement.
char** generate_field(int field_size, int max_size_of_ship, bool* error_check);   // Automatic (random) ship placement.
bool ship_capasity_test(int field_size, int max_size_of_ship);                    // Checks if all ships will fit into the field.
int setFieldSize();                                                               // Set field size.
int setMaxShip(int field_size);                                                   // Set maximum size of ship.