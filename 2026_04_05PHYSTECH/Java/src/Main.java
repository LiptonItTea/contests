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
        int n = in.nextInt();
        int[] arr = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i]=in.nextInt();
        }
    }
    private static long f(int [] arr){
        int n = arr.length;
        int[] arrL = new int[n/2-1];
        int[] arrR = new int[n/2];
        Random random = new Random();
        int k =  random.nextInt(0,n);
        for (int i = 0; i < n; i++) {
            if(arr[i]<arr[k]){
                arr[]
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