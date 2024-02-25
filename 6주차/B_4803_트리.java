package SSAGAKKO;

import java.util.List;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.Scanner;

/*
 * 같은 간선은 여러 번 주어지지 않는다. -> 그래프로 해도됨
 *  
 */
public class tree2 {
	
	//static LinkedList<Integer> list[];
	static int unionArr[];
	static boolean isTree[];
	
	static boolean Union(int a, int b)
	{
		int rootA = UFind(a);
		int rootB = UFind(b);
		
		if(rootA == rootB)
			return false;
		
		unionArr[rootA] = rootB;
		if(isTree[rootA])
			isTree[rootB] = true;
		
		return true;
	}
	
	static int UFind(int a)
	{
		if(unionArr[a] == a)
			return a;
		
		return unionArr[a] = UFind(unionArr[a]);
	}
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		StringBuilder sb = new StringBuilder();

		int N = -1; //정점의 개수, 500이하
		int M = -1; //간선의 개수, n(n-1)/2 개 250*499
		int TC = 0;
		while(TC++ < Integer.MAX_VALUE)
		{
			N = sc.nextInt();  	// 정점의 개수
			M = sc.nextInt();	// 간선의 개수
			
			unionArr = new int[N+1];
			isTree = new boolean[N+1];
			//같은 간선은 여러번 주어지지 않는다.
			
			if(N == 0 && M == 0)
				break;
			
			//1부터 N까지의 그래프
			//list = new LinkedList[N+1];
			
			
			//union make
			for(int i = 1; i<=N; i++)
			{
				//list[i] = new LinkedList<Integer>();
				unionArr[i] = i;
			}
				
			
			for(int i = 0; i <M; i++)
			{
				int nodeA = sc.nextInt();
				int nodeB = sc.nextInt();
				
				if(!Union(nodeA, nodeB))
				{
					isTree[UFind(nodeA)] = true;
					//System.out.println("사이클발생");

				}
					
				//list[nodeA].add(nodeB);
				//list[nodeB].add(nodeA);
			}
			
			//합쳐서 사이클 판단,
			//System.out.println(Arrays.toString(unionArr));
			//System.out.println(Arrays.toString(isTree));
			
			/*분기점
			 * 트리가 없을 때
			 * 트리가 하나만 있을 때
			 * 트리가 없을 때
			 */
			//각 트리의 사이클	
			int treeCnt = 0;
			
			for(int i = 1; i<=unionArr.length-1; i++)
			{
				//자기 자신을 가리키고 있으면 대표이므로 트리이다.
				//사이클이 발생했다면 isTree를 false로 해놨다.
				if(unionArr[i] == i)
				{
					if(isTree[i])
						continue;
					
					treeCnt++;
				}
					
			}
			
			switch(treeCnt)
			{
			case 0:
				System.out.println("Case "+TC+": No trees.");
				break;
			case 1:
				System.out.println("Case "+TC+": There is one tree.");
				break;
			default :
				System.out.println("Case "+TC+": A forest of "+treeCnt+" trees.");
				break;
			}
		}	
	}

}