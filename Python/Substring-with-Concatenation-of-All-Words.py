class Solution:
    # @param S, a string
    # @param L, a list of string
    # @return a list of integer
    def findSubstring(self, S, L):
        len2 = len(L)
        wordlen = len(L[0])
        seq = []
        d = {}
        for item in L:
            if item not in d:
                d[item] = 1
            else:
                d[item] += 1
        for i in range(len(S) - wordlen * len2 + 1):
            d1 = {}
            tag = 1
            for j in range(len2):
                word = S[i+j*wordlen:i+(j+1)*wordlen]
                if word in d:
                    if word in d1:
                        if d1[word] < d[word]:
                            d1[word] += 1
                        else:
                            tag = 0
                            break
                    else:
                        d1[word] = 1
                else:
                    tag = 0
                    break
            if tag == 1:
                seq.append(i)
        return seq