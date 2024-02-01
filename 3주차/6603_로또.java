import java.util.Scanner;
/*
접근법
 1~49의 수 중에서 6개를 고른다.
 
 6 을 초과하는 k개의 숫자와 배열 테이블을 받고 
 이 중 6가지 [조합]을 만든다.
 
 모든 경우의 수를 따지고 사전 순으로 출력한다.
 
 마지막에 0을 적으면 출력이 종료된다.
 1. [k] a, b, c, d. e.. k-1 입력받기
 
 2. 만든 배열로 kC6 조합식 작성하기
  2-1 idx와 cnt를 이용한 재귀 함수, 
  
  
 오늘 배운 조합 이용해서 문제 풀기
1.  
	if 이전 직전까지 뽑은 개수 (cnt) == 6 
	조합 출력
	return;
	
	idx =  in ~ k-1까지 반복문
		자릿수 [cnt]에 조합 숫자[idx] 
		재귀(cnt+1, idx+1)			
*/
public class Main {
	static final int combNum = 6;
	static int K = -1;
	static int combTable[] = new int[combNum];
	static int kTable[];
	
	static void rec(int cnt, int idx)
	{
		//기저조건
		if(cnt == combNum)
		{
			for(int i : combTable)
				System.out.print(i + " ");
			
			System.out.println();
			return;
		}
		
		for(int i = idx; i<=K-1; i++)
		{			
			combTable[cnt] = kTable[i];
			rec(cnt+1, i+1);
		}
		

	}	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		while(K != 0)
		{
			K = sc.nextInt();
			if(K == 0)
				break;
			
			kTable= new int[K];
			
			for(int i = 0; i< K; i++)
				kTable[i] = sc.nextInt();
			
			//메인로직
			rec(0, 0);		
			
			//케이스 끝
			System.out.println();						
		}				
	}

}