// this is an AI solution so I am not putting this in the submission right now and will review it to not artificially deflate my rank.
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <map> // Not strictly needed with vector mf

const int INF = 1e9; // A large enough value for infinity
const int MAX_CALC_VAL = 1000000; // Max value for x, y, k, and for mf computation

std::vector<int> mf_global; // min factors > 1 to make i from 1

void precompute_mf_once(int k_limit_overall_max) { // k can change per test case
    // This precomputation is if k is fixed. Since k varies, mf must be computed or used carefully.
    // For this problem, let's compute mf for each k.
    // If k_limit_overall_max is small, this could be feasible. But k can be 10^6.
    // The BFS for mf will be inside solve() or solve_one() then.
}

int solve_one() {
    int x, y, k;
    std::cin >> x >> y >> k;

    if (x == y) {
        return 0;
    }

    // mf[v] = min operations (factors a_i > 1, a_i <= k) to make v from 1.
    std::vector<int> mf(MAX_CALC_VAL + 1, INF);
    mf[1] = 0;
    std::queue<int> q_mf;
    q_mf.push(1);

    while(!q_mf.empty()){
        int u = q_mf.front();
        q_mf.pop();

        // Optimization: if mf[u] is already large, further products will exceed typical small op counts
        // For this problem, we might need mf values that are results of 2 or 3 ops.
        // If mf[u] >= 3 might be too aggressive if overall ans is mf[P] and P is large. Max mf can be ~20.
        // But we only check mf[P] for P up to 3 for 3-op solution.

        for (long long a = 2; a <= k; ++a) {
            if ((long long)u > MAX_CALC_VAL / a) { // Avoid overflow for u * a
                break; 
            }
            long long v_long = (long long)u * a;
            // v_long will not exceed MAX_CALC_VAL due to check above
            int v = static_cast<int>(v_long);
            
            if (mf[v] == INF) { // Found shorter path or first path
                mf[v] = mf[u] + 1;
                q_mf.push(v);
            }
        }
    }
    
    int ans = INF;

    // 0 ops: handled by x == y check upfront.

    // Pure M...M or D...D paths (includes 1 op if P <= k, or P=1)
    if (y % x == 0) {
        ans = std::min(ans, mf[y/x]);
    }
    if (x % y == 0) {
        ans = std::min(ans, mf[x/y]);
    }

    // 2 operations (Mixed: M-D or D-M)
    // Path x --*a1--> X1 --/a2--> y
    for (long long a1 = 1; a1 <= k; ++a1) {
        if ((long long)x > MAX_CALC_VAL / a1 && x != 0) break; 
        if (x == 0 && a1 > 0 && MAX_CALC_VAL / 1 < a1 ) break; // special handle x=0 not needed x,y >=1
        
        long long X1 = (long long)x * a1;
        if (X1 == 0 && y != 0) continue;


        if (X1 % y == 0) {
            long long a2 = X1 / y;
            if (a2 >= 1 && a2 <= k) {
                int current_ops = 0;
                if (a1 != 1) current_ops++;
                if (a2 != 1) current_ops++;
                ans = std::min(ans, current_ops);
            }
        }
    }
    // Path x --/a1--> X1 --*a2--> y
    for (long long a1 = 1; a1 <= k; ++a1) {
        if (x % a1 == 0) {
            long long X1 = x / a1;
            // X1 * a2 = y
            if (X1 == 0 && y != 0) continue;
            if (X1 != 0 && y % X1 == 0) {
                 long long a2 = y / X1;
                 if (a2 >= 1 && a2 <= k) {
                    int current_ops = 0;
                    if (a1 != 1) current_ops++;
                    if (a2 != 1) current_ops++;
                    ans = std::min(ans, current_ops);
                 }
            } else if (X1 == 0 && y == 0) { // x/a1 = 0, target y=0
                 // a2 can be 1. ops = (a1!=1?1:0) + 0 = (a1!=1?1:0)
                 int current_ops = (a1!=1?1:0);
                 ans = std::min(ans, current_ops);
            }
        }
    }
    
    // 3 operations
    // x --op1--> X1 --(2 ops pure)--> y
    // x --op1--> X1 --(2 ops mixed)--> y
    for (long long a_op1 = 1; a_op1 <= k; ++a_op1) {
        // Case 1: X1 = x * a_op1
        if ((long long)x <= MAX_CALC_VAL / a_op1) {
            long long X1 = (long long)x * a_op1;
            int c1 = (a_op1 != 1 ? 1 : 0);

            if (y % X1 == 0) ans = std::min(ans, c1 + mf[y/X1]);
            if (X1 % y == 0) ans = std::min(ans, c1 + mf[X1/y]);
            
            // X1 --*a2--> X2 --/a3--> y
            for (long long a2 = 1; a2 <= k; ++a2) {
                if (X1 > MAX_CALC_VAL / a2 && X1 != 0) break;
                if (X1 == 0 && a2 > 0 && MAX_CALC_VAL / 1 < a2 && y !=0 ) break;


                long long X2 = X1 * a2;
                 if (X2 == 0 && y != 0) continue;
                if (X2 % y == 0) {
                    long long a3 = X2 / y;
                    if (a3 >= 1 && a3 <= k) {
                        ans = std::min(ans, c1 + (a2!=1?1:0) + (a3!=1?1:0));
                    }
                }
            }
            // X1 --/a2--> X2 --*a3--> y
            for (long long a2 = 1; a2 <= k; ++a2) {
                if (X1 % a2 == 0) {
                    long long X2 = X1 / a2;
                    if (X2 == 0 && y != 0) continue;
                    if (X2 != 0 && y % X2 == 0) {
                        long long a3 = y / X2;
                        if (a3 >= 1 && a3 <= k) {
                           ans = std::min(ans, c1 + (a2!=1?1:0) + (a3!=1?1:0));
                        }
                    } else if (X2 == 0 && y == 0) {
                         ans = std::min(ans, c1 + (a2!=1?1:0) + 0);
                    }
                }
            }
        }
        // Case 2: X1 = x / a_op1
        if (x % a_op1 == 0) {
            long long X1 = x / a_op1;
            int c1 = (a_op1 != 1 ? 1 : 0);

            if (y % X1 == 0) ans = std::min(ans, c1 + mf[y/X1]);
            if (X1 % y == 0) ans = std::min(ans, c1 + mf[X1/y]);
            
            // X1 --*a2--> X2 --/a3--> y
             for (long long a2 = 1; a2 <= k; ++a2) {
                if (X1 > MAX_CALC_VAL / a2 && X1 != 0) break;
                if (X1 == 0 && a2 > 0 && MAX_CALC_VAL / 1 < a2 && y !=0) break;
                
                long long X2 = X1 * a2;
                 if (X2 == 0 && y != 0) continue;
                if (X2 % y == 0) {
                    long long a3 = X2 / y;
                    if (a3 >= 1 && a3 <= k) {
                        ans = std::min(ans, c1 + (a2!=1?1:0) + (a3!=1?1:0));
                    }
                }
            }
            // X1 --/a2--> X2 --*a3--> y
            for (long long a2 = 1; a2 <= k; ++a2) {
                if (X1 % a2 == 0) {
                    long long X2 = X1 / a2;
                     if (X2 == 0 && y != 0) continue;
                    if (X2 != 0 && y % X2 == 0) {
                        long long a3 = y / X2;
                        if (a3 >= 1 && a3 <= k) {
                           ans = std::min(ans, c1 + (a2!=1?1:0) + (a3!=1?1:0));
                        }
                    } else if (X2 == 0 && y == 0) {
                         ans = std::min(ans, c1 + (a2!=1?1:0) + 0);
                    }
                }
            }
        }
    }

    return (ans == INF) ? -1 : ans;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int t;
    std::cin >> t;
    // precompute_mf_once(MAX_CALC_VAL); // If k was fixed globally.
    while (t--) {
        std::cout << solve_one() << std::endl;
    }
    return 0;
}