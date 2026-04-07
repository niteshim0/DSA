// LC 2069 . Walking Robot Simulation II
// https://leetcode.com/problems/walking-robot-simulation-ii/description

// APPROACH:
/*
1. The robot moves only along the boundary of the rectangle.
   So we don’t need to simulate the entire grid, only the perimeter.

2. One full cycle means covering the entire boundary once.
   perimeter = 2 * (width + height) - 4

3. Movement follows a fixed cyclic order:
   East → North → West → South → repeat

4. Optimize the number of steps using modulo:
   num %= perimeter
   - Because after every 'perimeter' steps, the robot returns to the same state
   - If num == 0, it means a full cycle, so treat it as num = perimeter

5. Simulation logic:
   - Move in the current direction as much as possible (until hitting boundary or steps finish)
   - If boundary is reached and steps remain → change direction

6. Repeat until all steps are used

7. Final state:
   - (x, y) represents the current position
   - dir represents the current direction

TIME COMPLEXITY:
O(perimeter) in the worst case per step() call

SPACE COMPLEXITY:
O(1) (constant extra space)
*/


class Robot {
public:
    int w, h;
    int x = 0, y = 0;
    int dir = 0; // 0=East,1=North,2=West,3=South
    int per;

    Robot(int width, int height) {
        w = width;
        h = height;
        per = 2 * (w + h) - 4;
    }
    
    void step(int num) {
        if (per == 0) return;

        num %= per;

        // ✅ FIX: if multiple of perimeter → treat as full loop
        if (num == 0) num = per;

        while (num > 0) {
            if (dir == 0) { // East
                int move = min(num, w - 1 - x);
                x += move;
                num -= move;
                if (num > 0) dir = 1;
            } 
            else if (dir == 1) { // North
                int move = min(num, h - 1 - y);
                y += move;
                num -= move;
                if (num > 0) dir = 2;
            } 
            else if (dir == 2) { // West
                int move = min(num, x);
                x -= move;
                num -= move;
                if (num > 0) dir = 3;
            } 
            else { // South
                int move = min(num, y);
                y -= move;
                num -= move;
                if (num > 0) dir = 0;
            }
        }
    }
    
    vector<int> getPos() {
        return {x, y};
    }
    
    string getDir() {
        if (dir == 0) return "East";
        if (dir == 1) return "North";
        if (dir == 2) return "West";
        return "South";
    }
};