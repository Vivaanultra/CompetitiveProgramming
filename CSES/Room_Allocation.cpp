#include <bits/stdc++.h>
using namespace std;

struct Customer {
    int arrival, departure, id;
    
    
    bool operator<(const Customer& other) const {
        if (arrival == other.arrival)
            return departure < other.departure;
        return arrival < other.arrival;
    }
};

int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    vector<Customer> customers(n);
    for (int i = 0; i < n; i++) {
        cin >> customers[i].arrival >> customers[i].departure;
        customers[i].id = i; 
    }

    sort(customers.begin(), customers.end());

    
    
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    
    vector<int> room_assignments(n);
    int last_room_id = 0;

    for (int i = 0; i < n; i++) {
        
        
        if (!pq.empty() && pq.top().first < customers[i].arrival) {
            
            int room_id = pq.top().second;
            pq.pop();
            
            pq.push({customers[i].departure, room_id});
            room_assignments[customers[i].id] = room_id;
        } else {
            
            last_room_id++;
            pq.push({customers[i].departure, last_room_id});
            room_assignments[customers[i].id] = last_room_id;
        }
    }

    cout << last_room_id << "\n";
    for (int i = 0; i < n; i++) {
        cout << room_assignments[i] << (i == n - 1 ? "" : " ");
    }
    cout << "\n";

    return 0;
}