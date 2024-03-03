package SSAGAKKO;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.Queue;
import java.util.StringTokenizer;

public class B_11724_연결요소의개수 {
	 /*
	 * 방향없는 그래프(양방향)
	 * N은 1000개 (인접행렬 가능)
	 * M은 N*(N-1) / 2 -> 완전그래프까지 가능하다는 의미
	 * 같은 간선은 한번만 주어진다(그래프로 해도 된다)
	 * 
	 * BFS 하면될듯
	 * 
	 */
	
	static boolean arr[][];
	static boolean isUsed[];
	//static boolean isVisited[][];
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		int V = Integer.parseInt(st.nextToken());
		int E = Integer.parseInt(st.nextToken());
		
		arr = new boolean[V+1][V+1]; //1부터 시작
		isUsed = new boolean[V+1];
		for(int i = 0; i<E; i++)
		{
			st = new StringTokenizer(br.readLine());
			
			int a = Integer.parseInt(st.nextToken());
			int b = Integer.parseInt(st.nextToken());
			
			arr[a][b] = true;
			arr[b][a] = true;
		}
		
		int answer = 0;
		for(int i =0; i<V; i++)
		{
			for(int j =0; j<V; j++)
			{
				if(arr[i][j])
				{
					BFS(i);
					isUsed[i] = true;
					answer++;
				}
					
			}
		}
		int sum = 0;
		for(int i = 1; i<=V; i++)
			if(!isUsed[i])
				sum++;
		
		System.out.println(answer+sum);
	}
	
	static void BFS(int a)
	{
		Queue<Integer> q = new ArrayDeque<>();
		q.add(a);
		
		while(!q.isEmpty())
		{
			int col = q.poll();		
			for(int j = 0; j<arr.length; j++)
			{
				if(arr[col][j])
				{
					q.add(j);
					arr[col][j] = false;
					arr[j][col] = false;
					isUsed[col] = true;
					isUsed[j] = true;
				}
			}
		}
		
	}
}
