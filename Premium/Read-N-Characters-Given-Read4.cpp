// Forward declaration of the read4 API.
int read4(char *buf);

class Solution {
public:
    /**
     * @param buf Destination buffer
     * @param n   Maximum number of characters to read
     * @return    The number of characters read
     */
    int read(char *buf, int n) {
        if (buf == NULL) return 0;
        int t = 0;
        for (int i = 0; i <= n / 4; i ++) {
        	t += read4(buf + i * 4);
        }
        if (n > t) {
        	buf[t] = NULL;
        	return t;
        }
        return n;
    }
};