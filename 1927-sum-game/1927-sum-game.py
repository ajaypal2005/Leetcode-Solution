class Solution(object):
    def sumGame(self, num):
        n = len(num)
        half = n // 2

        left_sum = right_sum = 0
        left_q = right_q = 0

        # Process both halves
        for i in range(n):
            if num[i] == '?':
                if i < half:
                    left_q += 1
                else:
                    right_q += 1
            else:
                if i < half:
                    left_sum += int(num[i])
                else:
                    right_sum += int(num[i])

        total_questions = left_q + right_q

        # Alice gets the final move when the number of '?' is odd
        if total_questions % 2 != 0:
            return True

        sum_difference = left_sum - right_sum
        question_difference = right_q - left_q

        # False means Bob can make both halves equal
        return 2 * sum_difference != 9 * question_difference