
#include <iostream>
using namespace std;

int main() {
    int M, N;
    cin >> M >> N;
    
    // Each domino covers 2 squares
    // Maximum number of dominoes is floor(total squares / 2)
    cout << (M * N) / 2 << endl;
    
    return 0;
}
