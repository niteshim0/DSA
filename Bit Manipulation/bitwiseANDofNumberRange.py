class Solution:
    # do remember n&n-1 always results in mitigation of last set bit
    # that's the trick here
    def rangeBitwiseAnd(self, left: int, right: int) -> int:
        while right>left:
            right = right & (right-1)
        
        return right
        