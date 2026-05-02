// LC 788. Rotated Digits
// https://leetcode.com/problems/rotated-digits/description/

// Concepts :: Simulation + Enumeration

// Key Idea :: Iterating through numbers to simulate digit rotation and validating constraints based on specific digit properties.

const isGoodInteger = function(x) {
    let valid = true, changed = false;
    let temp = x;

    while (temp != 0) {
        let rem = temp % 10;

        if (rem == 3 || rem == 4 || rem == 7) {
            valid = false;
            break;
        }

        if (rem == 2 || rem == 5 || rem == 6 || rem == 9) {
            changed = true;
        }

        temp = Math.floor(temp / 10); 
    }

    return valid && changed;
};

const rotatedDigits = function(n) {
    let cnt = 0;

    for (let i = 1; i <= n; i++) {
        if (isGoodInteger(i)) cnt++;
    }

    return cnt;
};

// Time Complexity : O(NlogN)
// Space Complexity : O(1)