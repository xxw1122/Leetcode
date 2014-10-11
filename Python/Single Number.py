import functools

class Solution:
    # @param A, a list of integer
    # @return an integer
    def singleNumber(self, A):
        return functools.reduce(lambda x,y:x^y,A)