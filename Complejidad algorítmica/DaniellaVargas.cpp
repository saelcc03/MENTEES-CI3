#include <bits/stdc++.h>
using namespace std;

// solo funciona para los test cases xd
// mientras que queden ks se debería hallar el kadane de cada subarray de tamaño mínimo 1 restante y añadirlo a suma, luego descartarlo
// se debería aplicar recursividad pero no estoy segura de cómo implementarlo

int main() {
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int n, k;
    cin >> n >> k;

    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    int suma = 0;

    int max_so_far = INT_MIN, max_ending_here = 0;
    int start = 0, end = 0;
    int current_start = 0;

    for (int i = 0; i < n; i++) {
        max_ending_here = max_ending_here + v[i];
        if (max_so_far < max_ending_here) {
            max_so_far = max_ending_here;
            start = current_start;
            end = i;
        }

        if (max_ending_here < 0) {
            max_ending_here = 0;
            current_start = i + 1;
        }
    }

    for (int i = start; i <= end; i++) {
        v[i] = 0;
    }

    k--;
    suma += max_so_far;

    vector<int> subarray;

    for (int i = 0; i < n; i++) {
        if (v[i] != 0) {
            subarray.push_back(v[i]);
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            vector<int> temp;
            for (int k = i; k <= j; k++) {
                temp.push_back(v[k]);
            }
            if (!temp.empty()) {
                subarray.push_back(accumulate(temp.begin(), temp.end(), 0));
            }
        }
    }
    sort(subarray.begin(), subarray.end());
    for(auto elem:subarray)cout<<elem<<endl;
    while (k--) {
        suma += subarray.back();
        subarray.pop_back();
    }

    cout << suma << endl;
    return 0;
}
