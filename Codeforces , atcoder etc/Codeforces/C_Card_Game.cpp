#include <iostream>
#include <vector>
#include <string>
#include <numeric>   // Not strictly needed for this solution
#include <algorithm> // Not strictly needed for this solution

// Function to determine if card c1 beats card c2
// Card i beats card j if i > j, with one exception: card 1 beats card n.
bool beats(int c1, int c2, int n) {
    if (c1 == 1 && c2 == n) {
        return true; // Exception: card 1 beats card n
    }
    // This also implies that card n does NOT beat card 1.
    // We need to handle this when c1=n and c2=1.
    if (c1 == n && c2 == 1) {
        return false; // Card n is beaten by card 1, so card n does not beat card 1.
    }
    // General rule: card i beats card j if i > j
    return c1 > c2;
}

void solve_test_case() {
    int n;
    std::cin >> n;
    std::string s;
    std::cin >> s;

    std::vector<int> alice_cards;
    std::vector<int> bob_cards;

    for (int i = 0; i < n; ++i) {
        if (s[i] == 'A') {
            alice_cards.push_back(i + 1); // Card numbers are 1-indexed
        } else {
            bob_cards.push_back(i + 1); // Card numbers are 1-indexed
        }
    }

    // Constraints: "in each test case, at least one card is initially given to Alice, 
    // and at least one card is initially given to Bob."
    // So, alice_cards and bob_cards are non -empty at the start.

    bool alice_has_a_winning_card = false;
    // Check if Alice has a "super card": a card that beats all of Bob's current cards.
    for (int a_card : alice_cards) {
        bool current_a_card_is_super = true;
        // Bob is guaranteed to have at least one card initially.
        for (int b_card : bob_cards) {
            if (!beats(a_card, b_card, n)) {
                // This a_card does not beat b_card, so it's not a super card.
                current_a_card_is_super = false;
                break; // No need to check other Bob's cards for this a_card
            }
        }
        
        if (current_a_card_is_super) {
            // Alice found a card that beats all of Bob's cards.
            // Alice can play this card. Bob must play one of his cards.
            // Alice will win the round and take Bob's card.
            // Alice can repeat this strategy using the same super card until Bob runs out of cards.
            // Therefore, Alice wins.
            alice_has_a_winning_card = true;
            break; // Alice has a winning strategy, no need to check her other cards.
        }
    }

    if (alice_has_a_winning_card) {
        std::cout << "Alice" << std::endl;
    } else {
        // If Alice does not have a super card, it means for any card Alice plays,
        // Bob has at least one card that can beat Alice's chosen card.
        // (Because if !beats(a,b) then beats(b,a) since no draws and distinct cards).
        // So, Alice plays some card a_i.
        // Bob sees a_i, and Bob can choose a card b_j from his hand such that b_j beats a_i.
        // Bob wins the round and takes Alice's card a_i.
        // Alice loses one card. This process repeats until Alice runs out of cards.
        // Therefore, Bob wins.
        std::cout << "Bob" << std::endl;
    }
}

int main() {
    // Fast I/O
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t;
    std::cin >> t;
    while (t--) {
        solve_test_case();
    }

    return 0;
}