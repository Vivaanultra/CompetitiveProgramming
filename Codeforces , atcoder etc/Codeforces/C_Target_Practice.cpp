#include <iostream>
#include <string>
using namespace std;
int main()
{
    int n;
    cin >> n;
    for (int i=0; i<n; i++)
    {
        string a;
        cin >> a;
        int points = 0;
                char grid[10][10];
                
                // Read the 10x10 grid
                for(int row = 0; row < 10; row++) {
                    cin >> a;
                    for(int col = 0; col < 10; col++) {
                        grid[row][col] = a[col];
                    }
                }
                
                // Calculate points based on position of X
                for(int row = 0; row < 10; row++) {
                    for(int col = 0; col < 10; col++) {
                        if(grid[row][col] == 'X') {
                            // Check which ring the X is in (from outer to inner)
                            if(row == 0 || row == 9 || col == 0 || col == 9) {
                                points += 1;
                            }
                            else if(row == 1 || row == 8 || col == 1 || col == 8) {
                                points += 2;
                            }
                            else if(row == 2 || row == 7 || col == 2 || col == 7) {
                                points += 3;
                            }
                            else if(row == 3 || row == 6 || col == 3 || col == 6) {
                                points += 4;
                            }
                            else {
                                points += 5;
                            }
                        }
                    }
                }
                cout << points << endl;
        
            }
        }