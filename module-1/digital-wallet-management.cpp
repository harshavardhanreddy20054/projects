#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

const int MAX_USERS = 100;

struct User {
    int userID;
    int balance;
};

bool compare(const User& a, const User& b) {
    return a.balance < b.balance;
}

int main() {
    int N;
    cin >> N;

    User users[MAX_USERS];
    int user_index[MAX_USERS] = {0}; 

    for (int i = 0; i < N; i++) {
        int id, balance;
        cin >> id >> balance;
        users[i].userID = id;
        users[i].balance = balance;
        user_index[id] = i; 
    }

    int T; 
    cin >> T;

    for (int i = 0; i < T; i++) {
        int from_userID, to_userID, amount;
        cin >> from_userID >> to_userID >> amount;

        int from_index = user_index[from_userID];
        int to_index = user_index[to_userID];

        if (from_index >= 0 && from_index < N && to_index >= 0 && to_index < N) {
            if (users[from_index].balance >= amount) {
                users[from_index].balance -= amount;
                users[to_index].balance += amount;
                cout << "Success" << endl;
            } else {
                cout << "Failure" << endl;
            }
        } else {
            cout << "Failure" << endl;
        }
    }
    sort(users, users + N, compare);
    for (int i = 0; i < N; i++) {
        cout <<endl<< users[i].userID << " " << users[i].balance;
    }

    return 0;
}

