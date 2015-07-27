# Definition for a undirected graph node
class UndirectedGraphNode:
    def __init__(self, x):
        self.label = x
        self.neighbors = []

class Solution:
    # @param node, a undirected graph node
    # @return a undirected graph node
    def cloneGraph(self, node):
        if node == None:
            return None
        d = {}
        seq = []
        que = []
        res = UndirectedGraphNode(node.label)
        seq.append(node)
        que.append(res)
        d[node.label] = res
        while len(seq) > 0:
            cnt = seq.pop(0)
            ans = que.pop(0)
            for item in cnt.neighbors:
                if item.label not in d:
                    cur = UndirectedGraphNode(item.label)
                    d[item.label] = cur
                    ans.neighbors.append(cur)
                    seq.append(item)
                    que.append(cur)
                else:
                    ans.neighbors.append(d[item.label])
        return res
