class Solution:
    # @param path, a string
    # @return a string
    def simplifyPath(self, path):
        seq = path.split('/')
        st = []
        for i in range(len(seq)):
            if seq[i] == '..' and len(st) > 0:
                st.pop()
            elif seq[i] != '.' and seq[i] != '' and seq[i] != '..':
                st.append(seq[i])
        if len(st) == 0:
            return "/"
        s = ""
        for i in range(len(st)):
            s += "/"
            s += st[i]
        return s