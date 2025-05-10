#include <bits/stdc++.h> // Includes all standard C++ libraries (common in competitive programming, but not standard practice in production code)
using namespace std;      // Brings all names from the std namespace into the current scope (avoids writing std::)
using ll = long long;     // Creates a type alias 'll' for 'long long' for convenience, useful for large numbers.

int main() {
    // Optimize input/output operations for speed, common in competitive programming.
    ios::sync_with_stdio(false); // Disables synchronization between C-style I/O (printf/scanf) and C++ I/O (cout/cin).
    cin.tie(nullptr);           // Unties cin from cout, preventing automatic flushing of cout before cin operations.

    ll N; // Number of people
    ll M; // Minimum required people using the bridge
    ll K; // Number of locations on each side (0 to K-1)
    ll B; // Time to cross by boat

    // Read the main input parameters.
    cin >> N >> M >> K >> B;

    // Vector to store home (H) and work (W) locations for each person.
    // We'll store them as pairs.
    vector<pair<ll, ll>> hw(N);

    // Read the N pairs of home and work locations.
    for (int i = 0; i < N; i++) {
        ll H, W;
        cin >> H >> W; // Read home (H) and work (W) locations for person i.

        // --- Preprocessing Step ---
        // Ensure that H (home) <= W (work) in the pair.
        // This simplifies the interval calculation later, as the first element
        // of the pair will always be the smaller coordinate (min(H, W))
        // and the second element will be the larger coordinate (max(H, W)).
        if (H > W) swap(H, W);

        // Store the processed pair (where first <= second).
        hw[i] = {H, W}; // hw[i].first is min(H,W), hw[i].second is max(H,W)
    }

    // --- Lambda function 'feasible' ---
    // This function checks if a given tolerance level 'T' is sufficient.
    // It returns true if there exists *any* bridge location 'L' such that
    // at least 'M' people would use the bridge with tolerance 'T'.
    // It uses a sweep line algorithm to determine the maximum overlap.
    auto feasible = [&](ll T) {
        // --- Calculate Acceptable Bridge Location Interval ---
        // A person uses the bridge at L if: Time(Bridge at L) <= Time(Boat) + T
        // Time(Bridge at L) = |H - L| + 1 + |L - W|
        // Time(Boat) = |H - W| + B
        // Condition: |H - L| + 1 + |L - W| <= |H - W| + B + T
        // Rearranging: (|H - L| + |L - W|) - |H - W| <= T + B - 1
        // Let D = T + B - 1. This 'D' represents the maximum "extra" walking distance
        // allowed (|H - L| + |L - W|) compared to the minimum possible walking distance (|H - W|).
        ll D = T + B - 1;

        // The location L can deviate from the interval [min(H,W), max(H,W)]
        // by at most floor(D/2) on each side. Let's call this deviation K_range.
        // If D < 0, the condition can't be met even for L between H and W, so K_range is effectively negative (no valid L).
        // Note: Since T>=0 and B>=1, D = T+B-1 will always be >= 0, so the ternary check might be redundant here.
        ll K_range = D >= 0 ? (D / 2) : -1;

        // Vector to store sweep line events: pair<location, type>
        // type = +1 for interval start, -1 for interval end.
        vector<pair<ll, int>> events;
        // Reserve memory for potentially 2*N events to improve efficiency.
        events.reserve(2 * N);

        // Iterate through each person's preprocessed (lo, hi) location pair.
        for (auto &p : hw) {
            ll lo = p.first;  // The smaller coordinate (min(H, W))
            ll hi = p.second; // The larger coordinate (max(H, W))

            // Calculate the theoretical interval bounds [a, b] for acceptable bridge location L.
            ll a = lo - K_range; // Theoretical lower bound
            ll b = hi + K_range; // Theoretical upper bound

            // Clamp the interval to the actual valid range of locations [0, K-1].
            if (a < 0) a = 0;
            if (b > K - 1) b = K - 1;

            // If the clamped interval is invalid (start > end), this person
            // cannot use the bridge for this tolerance T. Skip them.
            if (a > b) continue;

            // --- Add Sweep Line Events ---
            // Add a "start" event at location 'a'.
            events.emplace_back(a, +1);

            // Add an "end" event. This marks the location *after* the interval ends.
            // The event location should be b + 1.
            // *** Possible Issue Note ***: The condition `if (b + 1 <= K - 1)` seems incorrect.
            // Standard sweep line adds the end event at `b + 1` unconditionally if `a <= b`.
            // This code omits the end event if `b == K-1`, which might lead to incorrect results
            // if the maximum overlap occurs exactly up to K-1. However, we comment based on the code provided.
            if (b + 1 <= K - 1) { // Only add end event if b+1 is within the valid index range [0, K-1]
                 events.emplace_back(b + 1, -1);
            }
            // If b == K-1, no end event is added in this implementation.
        }

        // --- Check Event Count (Potential Issue) ---
        // *** Possible Issue Note ***: The condition `if ((int)events.size() < M) return false;`
        // seems logically flawed. The number of events doesn't directly correlate with the
        // maximum *overlap*. M people could potentially overlap even if the total number
        // of events is less than M (e.g., M=3, N=2 people, 4 events, max overlap could be 2).
        // Or, even if events.size() >= M, the max overlap might still be less than M.
        // This check is likely incorrect but present in the provided code.
        if ((int)events.size() < M) return false;

        // Sort the events.
        // *** Possible Issue Note ***: The default `std::pair` comparison sorts first by `first` (location),
        // then by `second` (type). Since -1 < +1, this means `(loc, -1)` events will be processed
        // *before* `(loc, +1)` events at the same location. For finding the maximum overlap *at*
        // integer locations, the standard sweep line usually processes +1 before -1.
        // This sorting order might work due to specifics of the problem or test data, but differs
        // from the typical approach.
        sort(events.begin(), events.end());

        // --- Execute Sweep Line ---
        ll cover = 0; // Stores the current overlap count.
        // Iterate through the sorted events.
        for (auto &ev : events) {
            // Update the overlap count based on the event type (+1 or -1).
            cover += ev.second;
            // If the overlap count reaches or exceeds M at any point,
            // it means we found a location where at least M intervals overlap.
            // Therefore, the tolerance T is sufficient.
            if (cover >= M) return true;
        }

        // If the loop finishes and the overlap count never reached M,
        // then the tolerance T is not sufficient.
        return false;
    };

    // --- Binary Search on Tolerance T ---
    // We are looking for the minimum non-negative tolerance T for which feasible(T) is true.
    ll lo = 0; // Minimum possible tolerance.
    // Upper bound for binary search. max_diff ~ 2K-B+1.
    // 2*(K-1)+1 is approx 2K, potentially sufficient if B isn't too large.
    // A safer bound might be 2*K+B or ~3e9. This bound might depend on test case constraints.
    ll hi = 2 * (K - 1) + 1;
    // Adjust if K is 0 or 1 edge case? If K=1, hi=1. ok.

    // Binary search loop: find the smallest 'lo' such that feasible(lo) is true.
    while (lo < hi) {
        // Calculate midpoint, avoiding overflow.
        ll mid = lo + (hi - lo) / 2;
        // Check if tolerance 'mid' is feasible.
        if (feasible(mid)) {
            // If mid works, it's a possible answer. Try smaller values (including mid).
            hi = mid;
        } else {
            // If mid doesn't work, the minimum required T must be larger than mid.
            lo = mid + 1;
        }
    }

    // After the loop, 'lo' holds the minimum tolerance T found.
    // The problem implies T >= 0. The binary search maintains lo >= 0.
    // The `max(0LL, lo)` might be unnecessary but ensures output is non-negative.
    cout << max(0LL, lo) << "\n"; // Print the minimum required tolerance.

    return 0; // Indicate successful execution.
}