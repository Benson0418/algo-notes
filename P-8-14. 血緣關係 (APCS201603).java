import java.util.*;
import java.io.*;


public class Main{
	public static final int MAXN = 100000;
	public static int[] head = new int[MAXN], edges = new int[MAXN<<1], to = new int[MAXN<<1];
	public static int idx = 0;
	public static void main(String[] args) throws IOException{
		Kattio io = new Kattio();
		int n = io.nextInt();
		Arrays.fill(head, -1);
		Arrays.fill(edges, -1);
		Arrays.fill(to, -1);
		for (int i = 0; i < n-1; i++) {
			int a = io.nextInt();
			int b = io.nextInt();
			edges[idx] = head[a];
			head[a] = idx;
			to[idx] = b;
			idx++;
			edges[idx] = head[b];
			head[b] = idx;
			to[idx] = a;
			idx++;
		}
		ArrayDeque<Map.Entry<Integer, Integer>> q = new ArrayDeque<>();
		q.offer(new AbstractMap.SimpleEntry<>(0, -1));
		int node = 0;
		while (!q.isEmpty()){
			Map.Entry<Integer, Integer> cur = q.poll();
			for (int i = head[cur.getKey()]; i != -1; i = edges[i]) {
				int next = to[i];
				if (next != cur.getValue()) {
					q.offer(new AbstractMap.SimpleEntry<>(next, cur.getKey()));
				}
			}
			if (q.isEmpty()) {
				node = cur.getKey();
			}
		}
		q.offer(new AbstractMap.SimpleEntry<>(node, 0));
		boolean[] visited = new boolean[n];
		while (!q.isEmpty()){
			Map.Entry<Integer, Integer> cur = q.poll();
			visited[cur.getKey()] = true;
			for (int i = head[cur.getKey()]; i != -1; i = edges[i]) {
				int next = to[i];
				if (!visited[next]) {
					q.offer(new AbstractMap.SimpleEntry<>(next, cur.getValue()+1));
				}
			}
			if (q.isEmpty()) {
				io.println(cur.getValue());
			}
		}
		io.close();
	}




	public static class Kattio extends PrintWriter {
		private BufferedReader r;
		private StringTokenizer st;

		public Kattio() {
			this(System.in, System.out);
		}

		public Kattio(InputStream i, OutputStream o) {
			super(o);
			r = new BufferedReader(new InputStreamReader(i));
		}

		public Kattio(String intput, String output) throws IOException {
			super(output);
			r = new BufferedReader(new FileReader(intput));
		}

		public String next() {
			try {
				while (st == null || !st.hasMoreTokens())
					st = new StringTokenizer(r.readLine());
				return st.nextToken();
			} catch (Exception e) {
			}
			return null;
		}

		public int nextInt() {
			return Integer.parseInt(next());
		}

		public double nextDouble() {
			return Double.parseDouble(next());
		}

		public long nextLong() {
			return Long.parseLong(next());
		}
	}

}
