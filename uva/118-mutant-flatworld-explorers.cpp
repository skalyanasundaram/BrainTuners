#include <iostream>
#include <vector>

using namespace std;

enum COMPUS {EAST = 0, NORTH, WEST, SOUTH};
char COMPUS_STR[4] = {'E', 'N', 'W', 'S'};

class Location {
public:
    int x, y;
    Location():x(0), y(0) {}

    Location(int x, int y): x(x), y(y) {}

    bool operator==(Location &l) {
        return (x == l.x && y == l.y);
    }
};

class Robot {
private:
    Location loc;
    COMPUS direction;
    bool lost;

public:
    Robot(int x, int y, COMPUS d) {
        this->loc.x = x;
        this->loc.y = y;
        this->direction = d;
        this->lost = false;
    }

    void move_left() {
        if (!lost) {
            int i = (int) direction;
            // in c -1 % 4 is -1 and not 3 
            direction = (COMPUS) ((((i + 1) % 4) + 4) % 4);
        }
    }

    void move_right() {
        if (!lost) {
            int i = (int) direction;
            direction = (COMPUS) ((((i-1) % 4) + 4) % 4);
        }
    }

    void move_forward() {
        if (!lost) {
            if (direction == EAST)
                loc.x++;
            else if (direction == WEST)
                loc.x--;
            else if (direction == NORTH)
                loc.y++;
            else 
                loc.y--;
        }
    }
    void move_backward() {
        if(!lost) {
            if (direction == EAST)
                loc.x--;
            else if (direction == WEST)
                loc.x++;
            else if (direction == NORTH)
                loc.y--;
            else
                loc.y++;
        }
    }

    Location getLocation() {
        return loc;
    }

    void set_lost() {
        this->lost = true;
    }

    void print() {
        cout << loc.x << " " << loc.y << " " << COMPUS_STR[direction] << ((lost)? " LOST" : "") << endl;
    }

    bool does_fell_of_grid(Location grid) {
        return (loc.x < 0 || loc.x > grid.x || loc.y < 0 || loc.y > grid.y);
    }
};

class Command {
public:
    virtual void move() = 0;
    virtual void undo() = 0;
    virtual bool check_if_fell_of_grid(Location &grid) = 0;
    virtual Location getLocation() = 0;
    virtual void set_lost() = 0;
};

class CommandMoveLeft : public Command {
private:
    Robot &robot;
public:
    CommandMoveLeft(Robot &robot):robot(robot) { }

    void move() {
        this->robot.move_left();
    }

    void undo() {
        this->robot.move_right();
    }

    bool check_if_fell_of_grid(Location &grid) {
        return this->robot.does_fell_of_grid(grid);
    }

    Location getLocation() {
        return this->robot.getLocation();
    }

    void set_lost() {
        this->robot.set_lost();
    }
};

class CommandMoveRight : public Command {
private:
    Robot &robot;
public:
    CommandMoveRight(Robot &robot):robot(robot) {}

    void move() {
        this->robot.move_right();
    }

    void undo() {
        this->robot.move_left();
    }

    bool check_if_fell_of_grid(Location &grid) {
        return this->robot.does_fell_of_grid(grid);
    }

    Location getLocation() {
        return this->robot.getLocation();
    }

    void set_lost() {
        this->robot.set_lost();
    }

};

class CommandMoveForward : public Command {
private:
    Robot &robot;
public:
    CommandMoveForward(Robot &robot):robot(robot) { }

    void move() {
        this->robot.move_forward();
    }

    void undo() {
        this->robot.move_backward();
    }

    bool check_if_fell_of_grid(Location &grid) {
        return this->robot.does_fell_of_grid(grid);
    }

    Location getLocation() {
        return this->robot.getLocation();
    }

    void set_lost() {
        this->robot.set_lost();
    }

};

class Controller {
private:
    vector<Location> scent;
    Location grid;
public:

    Controller(int x, int y) {
        grid.x = x;
        grid.y = y;
    }

    void store_and_execute(Command &command) {
        //commands.push_back(command);
        bool prevStat = command.check_if_fell_of_grid(grid);
        command.move();
        bool curStat = command.check_if_fell_of_grid(grid);


        if (!prevStat && curStat) {
            command.undo();
            Location loc = command.getLocation();

            if (not_in_scent(loc)) {
                scent.push_back(loc);
                command.set_lost();
            }
        }
    }

    bool not_in_scent(Location loc) {
        for(vector<Location>::iterator it = scent.begin(); it != scent.end(); it++) {
            if (loc == (*it))
                return false;
        }
        return true;
    }
};

int main() {
    int x, y;
    char e;
    string cmds;

    cin >> x >> y;

    Controller controller(x, y);

    while(true) {

        cin >> x >> y >> e;

        if (cin.eof())
            break;

        e = toupper(e);

        Robot r(x, y, (e == 'E') ? EAST : (e == 'W') ? WEST : (e == 'N') ? NORTH : SOUTH);

        cmds.clear();
        cin >> cmds;

        for(string::iterator it = cmds.begin(); it != cmds.end(); it ++ ) {

            if (toupper(*it) == 'L') {
                CommandMoveLeft c(r);
                controller.store_and_execute(c);
            }
            else if (toupper(*it) == 'R') {
                CommandMoveRight c(r);
                controller.store_and_execute(c);
            }
            else if (toupper(*it) == 'F') {
                CommandMoveForward c(r);
                controller.store_and_execute(c);
            }
        }

        r.print();

    }
    return 0;
}



//command pattern
