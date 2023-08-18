package week7;

public class p115 {
	public int numDistinct(String s, String t) {
        int[][] f = new int[s.length()][t.length()];
        if(s.charAt(0) == t.charAt(0)) {
            f[0][0] = 1;
        }
        for(int i = 1; i < s.length(); i++) {
            f[i][0] = f[i - 1][0];
            if(s.charAt(i) == t.charAt(0)) {
                f[i][0]++;
            }
        }

        for(int i = 1; i < s.length(); i++) {
            for(int j = 1; j < t.length() && j <= i; j++) {
                f[i][j] = f[i - 1][j];
                if(s.charAt(i) == t.charAt(j)) {
                    f[i][j] += f[i - 1][j - 1];
                }
            }
        }

        return f[s.length() - 1][t.length() - 1];
    }
}
