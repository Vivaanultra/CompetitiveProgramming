#include <iostream>
#include <vector>
#include <algorithm> // For std::sort
#include <cmath>     // For std::ceil

// Structure to hold classroom information (ID and floor)
struct ClassroomData {
    int id;       // Classroom ID
    int floor;    // Floor number

    // Custom comparison for std::sort
    bool operator<(const ClassroomData& other) const {
        if (floor != other.floor) {
            return floor < other.floor;
        }
        return id < other.id; 
    }
};

void solve() {
    int n, m;
    std::cin >> n >> m;

    std::vector<ClassroomData> classrooms(m);
    for (int i = 0; i < m; ++i) {
        std::cin >> classrooms[i].id;
        classrooms[i].floor = classrooms[i].id / 100;
    }

    std::sort(classrooms.begin(), classrooms.end());

    std::vector<std::vector<int>> schedule(n, std::vector<int>(6));

    int num_physical_pairs = static_cast<int>(std::ceil(static_cast<double>(n) / 2.0));

    for (int j = 0; j < num_physical_pairs; ++j) {
        ClassroomData room_L = classrooms[j];
        // Ensure m-1-j is a valid index and refers to a distinct room if possible.
        // If j == m-1-j, then room_L and room_H are the same. This happens if m is odd and j=(m-1)/2.
        // This is fine, that pair will contribute 0 to movement.
        ClassroomData room_H = classrooms[m - 1 - j];

        // Group 2*j
        if (2 * j < n) {
            schedule[2 * j][0] = room_L.id;
            schedule[2 * j][1] = room_H.id;
            schedule[2 * j][2] = room_L.id;
            schedule[2 * j][3] = room_H.id;
            schedule[2 * j][4] = room_L.id;
            schedule[2 * j][5] = room_H.id;
        }

        // Group 2*j + 1
        if (2 * j + 1 < n) {
            schedule[2 * j + 1][0] = room_H.id;
            schedule[2 * j + 1][1] = room_L.id;
            schedule[2 * j + 1][2] = room_H.id;
            schedule[2 * j + 1][3] = room_L.id;
            schedule[2 * j + 1][4] = room_H.id;
            schedule[2 * j + 1][5] = room_L.id;
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int k = 0; k < 6; ++k) {
            std::cout << schedule[i][k] << (k == 5 ? "" : " ");
        }
        std::cout << std::endl;
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t;
    std::cin >> t;
    while (t--) {
        solve();
    }
}