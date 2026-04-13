import java.io.*;
import java.util.Collections;
import java.util.Random;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) {
        InputStream stream = System.in;
        OutputStream outputStream = System.out;
        PrintWriter printWriter = new PrintWriter(outputStream);
        InputReader reader = new InputReader(stream);
        solve(reader, printWriter);
        printWriter.close();
    }

    private static void solve(InputReader in, PrintWriter out) {
        int t = in.nextInt();
        for (int i = 0; i < t; i++) {
            int a = in.nextInt();
            int b = in.nextInt();
            if (a > b) {
                int c = a;
                a = b;
                b = c;
            }
            int k = b - a;
            double res = (double) (k * 1.61803398);
            if ((int) res == a) {
                out.println("second");
            } else {
                out.println("first");
            }
        }

    }


    static class InputReader {
        BufferedReader reader;
        StringTokenizer tokenizer;

        InputReader(InputStream stream) {
            reader = new BufferedReader(new InputStreamReader(stream), 32768);
            tokenizer = null;
        }

        String next() {
            while (tokenizer == null || !tokenizer.hasMoreTokens()) {
                try {
                    tokenizer = new StringTokenizer(reader.readLine());
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
            }
            return tokenizer.nextToken();
        }

        int nextInt() {
            return Integer.parseInt(next());
        }

        Long nextLong() {
            return Long.parseLong(next());
        }
    }
}