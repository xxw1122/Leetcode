class Solution:
    # @param a, a string
    # @param b, a string
    # @return a boolean
    def compareVersion(self, version1, version2):
        seq1 = []
        seq2 = []
        if version1.find('.') >= 0:
            seq1 = version1.split('.')
        else:
            seq1.append(version1)
        if version2.find('.') >= 0:
            seq2 = version2.split('.')
        else:
            seq2.append(version2)
        for i in range(len(seq1)):
            seq1[i] = int(seq1[i])
        for i in range(len(seq2)):
            seq2[i] = int(seq2[i])
        maxlen = max(len(seq1), len(seq2))
        for i in range(len(seq1), maxlen):
            seq1.append(0)
        for i in range(len(seq2), maxlen):
            seq2.append(0)
        if seq1 < seq2:
            return -1
        elif seq1 > seq2:
            return 1
        else:
            return 0