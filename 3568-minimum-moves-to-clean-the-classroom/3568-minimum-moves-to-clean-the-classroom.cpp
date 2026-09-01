class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {
        int m = classroom.size();
        int n = classroom[0].size();

        int startRow, startCol;
        int litterCount = 0;

        // Give every litter a unique number
        vector<vector<int>> litterId(m, vector<int>(n, -1));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (classroom[i][j] == 'S') {
                    startRow = i;
                    startCol = j;
                }
                else if (classroom[i][j] == 'L') {
                    litterId[i][j] = litterCount++;
                }
            }
        }

        int finalMask = (1 << litterCount) - 1;

        // {row, column, remaining energy, collected litter, moves}
        queue<array<int, 5>> q;
        q.push({startRow, startCol, energy, 0, 0});

        // Maximum energy seen at each position and litter mask
        vector<int> best(m * n * (1 << litterCount), -1);

        auto getIndex = [&](int r, int c, int mask) {
            return ((r * n + c) * (1 << litterCount)) + mask;
        };

        best[getIndex(startRow, startCol, 0)] = energy;

        int directions[4][2] = {
            {1, 0}, {-1, 0}, {0, 1}, {0, -1}
        };

        while (!q.empty()) {
            auto [row, col, currentEnergy, mask, moves] = q.front();
            q.pop();

            if (mask == finalMask)
                return moves;

            if (currentEnergy == 0)
                continue;

            for (auto& direction : directions) {
                int newRow = row + direction[0];
                int newCol = col + direction[1];

                if (newRow < 0 || newRow >= m ||
                    newCol < 0 || newCol >= n ||
                    classroom[newRow][newCol] == 'X') {
                    continue;
                }

                int newEnergy = currentEnergy - 1;
                int newMask = mask;

                // Collect litter
                if (classroom[newRow][newCol] == 'L') {
                    newMask |= (1 << litterId[newRow][newCol]);
                }

                // Restore energy
                if (classroom[newRow][newCol] == 'R') {
                    newEnergy = energy;
                }

                int index = getIndex(newRow, newCol, newMask);

                // Skip if we previously reached this state
                // with equal or greater energy
                if (best[index] >= newEnergy)
                    continue;

                best[index] = newEnergy;

                q.push({
                    newRow, newCol, newEnergy,
                    newMask, moves + 1
                });
            }
        }

        return -1;
    }
};