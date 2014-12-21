class Solution:
    # @param tokens, a list of string
    # @return an integer
    def evalRPN(self, tokens):
        seq = []
        for item in tokens:
            if item == "+":
                cnt1 = seq.pop()
                cnt2 = seq.pop()
                seq.append(cnt1 + cnt2)
            elif item == "-":
                cnt1 = seq.pop()
                cnt2 = seq.pop()
                seq.append(cnt2 - cnt1)
            elif item == "*":
                cnt1 = seq.pop()
                cnt2 = seq.pop()
                seq.append(cnt1 * cnt2)
            elif item == "/":
                cnt1 = seq.pop()
                cnt2 = seq.pop()
                if cnt1 * cnt2 < 0:
                    seq.append(-(abs(cnt2) / abs(cnt1)))
                else:
                    seq.append(cnt2 / cnt1)
            else:
                seq.append(int(item))
        return seq[0]

