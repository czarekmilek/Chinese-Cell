#include <iostream>
#include <vector>
#include <climits>

using namespace std;

// Oblicza sumę ważoną dla fragmentu od `start` do `end`
int calculateWeightedSum(const vector<int> &prefixSum, const vector<int> &weightedPrefixSum, int start, int end)
{
    return weightedPrefixSum[start] - weightedPrefixSum[end + 1] - (end - start + 1) * prefixSum[end + 1];
}

// Oblicza minimalny kosztu podziału sufiksu na `j` kawałków
int minCostPartition(const vector<int> &nums, int n, int k, vector<int> &segmentLengths)
{
    // Suma częściowa
    vector<int> prefixSum(n + 1, 0), weightedPrefixSum(n + 1, 0);

    for (int i = n - 1; i >= 0; i--)
    {
        prefixSum[i] = nums[i] + prefixSum[i + 1];
        weightedPrefixSum[i] = prefixSum[i] + weightedPrefixSum[i + 1];
    }

    // Tablica z kosztami podziału sufiksów
    vector<vector<int>> dp(n + 1, vector<int>(k + 1, INT_MAX));

    // Tablica z indeksami dla optymalnego podziału
    vector<vector<int>> optimalIndex(n + 1, vector<int>(k + 1, 0));

    // Koszt dla `k = 0`
    for (int i = 0; i <= n; i++)
    {
        dp[i][0] = 0;
    }

    // Koszt dla `k = 1`
    for (int i = 0; i <= n; i++)
    {
        dp[i][1] = calculateWeightedSum(prefixSum, weightedPrefixSum, i, n - 1);
    }

    // Koszt dla pozostałych `k`
    for (int j = 2; j <= k; j++)
    {
        for (int i = 0; i <= n; i++)
        {
            for (int s = i + 1; s <= n; s++)
            {
                if (dp[s][j - 1] != INT_MAX)
                {
                    int cost = dp[s][j - 1] + calculateWeightedSum(prefixSum, weightedPrefixSum, i, s - 1);
                    if (cost < dp[i][j])
                    {
                        dp[i][j] = cost;
                        optimalIndex[i][j] = s;
                    }
                }
            }
        }
    }

    // Rekonstrukcja długości segmentów
    int start = 0;
    for (int j = k; j >= 1; j--)
    {
        int end = optimalIndex[start][j];
        segmentLengths.push_back(end - start);
        start = end;
    }

    int lastSegmentLength = segmentLengths.back();
    segmentLengths.pop_back();
    segmentLengths.push_back(lastSegmentLength + n - start);

    return dp[0][k];
}

int main()
{
    // Liczba klawiszy
    int K;
    // Liczba liter
    int L;
    cin >> K >> L;

    // Częstotliwość występowania liter
    vector<int> nums(L);
    for (int i = 0; i < L; ++i)
    {
        cin >> nums[i];
    }

    // Tablica z długościami segmentów
    vector<int> segmentLengths;

    // Minimalny koszt podziału
    int minCost = minCostPartition(nums, L, K, segmentLengths);

    cout << minCost << endl;

    for (int length : segmentLengths)
    {
        cout << length << " ";
    }
    cout << endl;

    return 0;
}
