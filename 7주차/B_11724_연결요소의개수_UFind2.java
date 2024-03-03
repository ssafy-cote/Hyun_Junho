package SSAGAKKO;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class B_11724_연결요소의개수_UFind2 {
	 /*
	 * 방향없는 그래프(양방향)
	 * N은 1000개 (인접행렬 가능)
	 * M은 N*(N-1) / 2 -> 완전그래프까지 가능하다는 의미
	 * 같은 간선은 한번만 주어진다(그래프로 해도 된다)
	 * 
	 * 유니온 파인드 버전
	 * 
	 */
	static int vertex[];
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		int V = Integer.parseInt(st.nextToken());
		int E = Integer.parseInt(st.nextToken());
		
		vertex = new int[V+1];
		
		//set
		for(int i= 1; i<=V; i++)
			vertex[i] = i;
				
		for(int i = 0; i<E; i++)
		{
			st = new StringTokenizer(br.readLine());
			
			int a = Integer.parseInt(st.nextToken());
			int b = Integer.parseInt(st.nextToken());
			
			Union(a, b);		
		}
		
		int cnt = 0;
		for(int i =1; i<=V; i++ )
			if(vertex[i] == i)
				cnt++;
		
		System.out.println(cnt);
	}
	
	static int UFind(int x)
	{
		if(vertex[x] == x)
			return x;
		
		return vertex[x] = UFind(vertex[x]);
	}
	static void Union(int a, int b)
	{
		int x = UFind(a);
		int y = UFind(b);
		
		if(x != y)
			vertex[x] = y; // 더 큰 인덱스가 작은 숫자를 붙인다.
	}
}
