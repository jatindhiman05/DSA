#include <iostream>
#include <queue>
#include <vector>
using namespace std;

// method - 1
class Solution
{
public:
    int maxProfitAssignment(vector<int> &difficulty, vector<int> &profit, vector<int> &worker)
    {
        long long maxProfit = 0;

        priority_queue<pair<int, int>> pq;

        for (int i = 0; i < difficulty.size(); i++)
        {
            pq.push({profit[i], difficulty[i]});
        }

        sort(worker.begin(), worker.end(), greater<int>()); // enable pop in pq

        int i = 0;

        while (i < worker.size() && !pq.empty())
        {
            if (pq.top().second > worker[i])
            {
                pq.pop();
            }
            else
            {
                maxProfit += pq.top().first;
                i++; // job assigned to a worker
            }
        }

        return maxProfit;
    }
};

// method- 2
class Solution
{
public:
    int maxProfitAssignment(vector<int> &difficulty, vector<int> &profit, vector<int> &worker)
    {
        int maxProfit = 0;
        vector<pair<int, int>> job;

        for (int i = 0; i < difficulty.size(); i++)
        {
            job.push_back({difficulty[i], profit[i]});
        }

        sort(job.begin(), job.end());

        // to find max profit till idx i
        for (int i = 1; i < job.size(); i++)
        {
            job[i].second = max(job[i].second, job[i - 1].second);
        }

        for (int i = 0; i < worker.size(); i++)
        {
            int workerAbility = worker[i];

            // BS on job
            int start = 0;
            int end = job.size() - 1;
            int mid = start + (end - start) / 2;
            int max_profit = 0;

            while (start <= end)
            {
                if (job[mid].first <= workerAbility)
                {
                    max_profit = max(max_profit, job[mid].second);
                    start = mid + 1;
                }
                else
                {
                    end = mid - 1;
                }
                mid = start + (end - start) / 2;
            }

            maxProfit += max_profit;
        }

        return maxProfit;
    }
};