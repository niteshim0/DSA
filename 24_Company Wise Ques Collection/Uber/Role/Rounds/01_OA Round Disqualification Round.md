// Duration 65 minutes

Problem 1 — Uber City Network Construction
Uber is expanding its infrastructure to support faster dispatching across a city. The city is represented as a coordinate grid where n hubs are located at coordinates:

(x_i, y_i)
You can connect any two hubs i and j with a direct communication link.

The cost of connecting two hubs is defined as:

min(|x_i - x_j|, |y_i - y_j|)
Determine the minimum total cost required to connect all hubs so that every hub can communicate with every other hub either directly or indirectly.

Constraints
2 ≤ n ≤ 10^5
0 ≤ x_i, y_i ≤ 10^9

Problem 2 — Uber Zone Clusters
Uber optimizes driver dispatch by analyzing connectivity between city zones.

Each zone i has a traffic signature:

S_i
Two zones are considered directly connected if:

gcd(S_i, S_j) > 1
Connectivity is transitive, meaning if zone A connects to B and B connects to C, all belong to the same cluster.

Task
Given an array of n signatures, return an array where each element represents the size of the cluster to which that zone belongs.


Problem 3 — Uber Demand Trend Analysis
You are given an array of integers:

demandLevels
For each index i, determine the index of the k-th element to the right (j > i) such that:

demandLevels[j] > demandLevels[i]
If such an element does not exist, return -1.

Output indices follow 1-based indexing.

Constraints
1 ≤ n ≤ 10^5
1 ≤ k ≤ 50
1 ≤ demandLevels[i] ≤ 10^9