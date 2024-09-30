#include <bits/stdc++.h>
using namespace std;

int longestNonIncreasingSubsequence(vector<int> &arr)
{
    vector<int> seq; // This will store the current subsequence
    vector<int> maximum;

    for (int i = 0; i < arr.size(); i++)
    {
        // Find the first element in seq that is smaller than the current element
        auto it = upper_bound(seq.begin(), seq.end(), arr[i], greater<int>());

        // If such element is found, replace it with current element
        if (it != seq.end())
        {
            *it = arr[i];
            auto index = it - seq.begin();
            index++;
            seq.resize(index);
        }
        else
        {
            // Otherwise, append the current element
            seq.push_back(arr[i]);
        }
        if (maximum.size() < seq.size())
        {
            maximum = seq;
        }
    }

    // The size of seq gives the length of LNIS
    for (auto a : maximum)
        cout << a << " ";
    cout << endl;
    return maximum.size();
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (auto &a : arr)
            cin >> a;
        cout << longestNonIncreasingSubsequence(arr) << endl;
    }

    return 0;
}
