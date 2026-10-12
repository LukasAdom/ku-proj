#include <iostream>
#include <cstdlib>
#include <cctype>

const int MAP_MIN = 0;
const int MAP_MAX = 9;
const int BAT_MAX = 10;

// Returns true if the position is on the map.
bool is_inside_map(int x, int y) {
    return x >= MAP_MIN && x <= MAP_MAX && y >= MAP_MIN && y <= MAP_MAX;
}

bool has_battery(int battery, int steps){
    return battery >= steps;
}

// Returns the Manhattan distance between two positions:
// the number of steps along the grid lines, |x1 - x2| + |y1 - y2|.
int calculate_distance(int x, int y, int target_x, int target_y) {
    return std::abs(target_x - x) + std::abs(target_y - y);
}

// Returns true if the drone is exactly on the target.
bool has_reached_target(int x, int y, int target_x, int target_y) {
    return x == target_x && y == target_y;
}

bool has_reached_station(int x, int y, int station_x, int station_y){
    return x == station_x && y == station_y;
}

// Returns the x coordinate after moving in the given direction.
int calculate_new_x(int x, char direction, int steps) {
    if (direction == 'e') {
        return x + steps;
    }
    if (direction == 'w') {
        return x - steps;
    }
    return x;
}

// Returns the y coordinate after moving in the given direction.
int calculate_new_y(int y, char direction, int steps) {
    if (direction == 'n') {
        return y + steps;
    }
    if (direction == 's') {
        return y - steps;
    }
    return y;
}

// Asks for a direction until the user gives a valid one.
// Returns 'n', 's', 'e', 'w', or 'q' to quit.
char read_direction() {
    while (true) {
        std::cout << "Direction (N/S/E/W) or q to quit: ";
        char input;
        if (!(std::cin >> input)) {
            return 'q';
        }
        char direction = static_cast<char>(std::tolower(input));
        if (direction == 'n' || direction == 's' || direction == 'e' ||
            direction == 'w' || direction == 'q') {
            return direction;
        }
        std::cout << "Unknown direction.\n";
    }
}

// Asks for a number of steps until the user gives a positive whole number.
int read_steps() {
    while (true) {
        std::cout << "Steps: ";
        int steps;
        if (!(std::cin >> steps)) {
            if (std::cin.eof()) {
                return 0;
            }
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            std::cout << "Please enter a whole number.\n";
            continue;
        }
        if (steps < 1) {
            std::cout << "Steps must be at least 1.\n";
            continue;
        }
        return steps;
    }
}

// Prints the map: @ is the drone, X is the target, . is empty space.
// North is at the top of the picture.
void draw_grid(int x, int y, int target_x, int target_y, int station_x, int station_y) {
    for (int row = MAP_MAX; row >= MAP_MIN; row--) {
        for (int column = MAP_MIN; column <= MAP_MAX; column++) {
            if (column == x && row == y) {
                std::cout << "@ ";
            } else if (column == target_x && row == target_y) {
                std::cout << "X ";
            } else if (column == station_x && row == station_y){
                std::cout << "C";
            } else {
                std::cout << ". ";
            }
        }
        std::cout << "\n";
    }
}

// Prints the drone position and the remaining distance to the target.
void print_status(int x, int y, int target_x, int target_y, int battery) {
    std::cout << "Drone: (" << x << ", " << y << ")   Target: ("
              << target_x << ", " << target_y << ")\n";
    std::cout << "Battery: " << battery << "\n";
    std::cout << "Distance to target: "
              << calculate_distance(x, y, target_x, target_y) << "\n";
}

int main() {
    int x = 1;
    int y = 1;
    int target_x = 8;
    int target_y = 7;
    int station_x = 4;
    int station_y = 4;
    int battery = BAT_MAX;

    std::cout << "=== DRONE ===\n";
    draw_grid(x, y, target_x, target_y, station_x, station_y);
    print_status(x, y, target_x, target_y, battery);

    while (true) {
        char direction = read_direction();
        if (direction == 'q') {
            std::cout << "Flight cancelled.\n";
            break;
        }
        int steps = read_steps();

        int new_x = calculate_new_x(x, direction, steps);
        int new_y = calculate_new_y(y, direction, steps);

        if (is_inside_map(new_x, new_y) && has_battery(battery, steps)) {
            x = new_x;
            y = new_y;
            battery = battery - steps;
        } else if(!is_inside_map(new_x, new_y)){
            std::cout << "Move rejected: the drone would leave the map.\n";
        } else if(!has_battery(battery, steps)){
            std::cout << "Move rejected: the drone does not have enough battery.\n";
        }
        
        if(has_reached_station(x, y, station_x, station_y)){
            std::cout << "Station reached!\n";
            battery = BAT_MAX;
        }

        draw_grid(x, y, target_x, target_y, station_x, station_y);
        print_status(x, y, target_x, target_y, battery);
        
        if(battery <= 0){
            std::cout << "The drone no longer has enough battery to function.\n";
            break;
        }

        if (has_reached_target(x, y, target_x, target_y)) {
            std::cout << "Target reached!\n";
            break;
        }
    }

    return 0;
}