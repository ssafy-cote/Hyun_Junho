import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.StringTokenizer;

/*
5종류의 카메라 (-, <ㅡ>, ㄴ, ㅗ, +)
 
  카메라는 90도 회전할 수 있다. 대각선은 없다
  카메라는 벽을 통과할 수 없다.
  카메라는 다른 카메라를 통과할 수 있다.
  
  카메라를 세팅하고도 0이 남으면 그것을 사각지대라 칭한다.
  주어진 맵 정보를 토대로 사각지대의 최소 크기 구하기.
  
  카메라가 회전하는 경우의 수를 중복순열로 표현할 수 있다.
  0번방향(상), 1번방향(우), 2번방향(하), 3번방향(좌)
  4ㅠ4 -> 4^4 
*/

class Camera
{
	//상, 우, 하, 좌 	
	static final int dir[][] = {{-1,0},{0,1},{1,0},{0,-1}};
	static int N;
	static int M;
	
	int posX;
	int posY;
	int cameraNum;
	int[] cameraDirIdx;
	
	public Camera(int num, int x, int y)
	{
		posX = x;
		posY = y;
		cameraNum = num;
		InitCamera();
	}
	void InitCamera()
	{
		switch(cameraNum)
		{
		case 1 :
			cameraDirIdx = new int[]{0};				
			break;
		case 2 :
			cameraDirIdx = new int[]{1, 3};
			break;
		case 3 :
			cameraDirIdx = new int[]{0, 1};
			break;
		case 4 :
			cameraDirIdx = new int[]{0, 1, 3};
			break;
		case 5 :
			cameraDirIdx = new int[]{0, 1, 2, 3};
			break;
		}
	}
	
	void RotateCamera(int cnt)
	{
		if(cameraNum == 5)
			return;
		
		int rot = cnt;
		//카메라가 가지고있는 방향 배열 갯수만큼 회전한다.  
		while(rot-- >0)
		{
			for(int i = 0; i<cameraDirIdx.length; i++)
				cameraDirIdx[i] = (cameraDirIdx[i] +1)%4;
		}						
	}
	
	void RayCamera(int arr[][])
	{
		//카메라를 투시한다.
		int N = arr.length;
		int M = arr[0].length;
		
		for(int i = 0; i<cameraDirIdx.length; i++)
		{
			//벽을 만날때까지 반복한다.
			//boolean isWall = false;
			
			int curPosX = posX;
			int curPosY = posY;
			
			while(true)
			{
				//dir 한 칸 증가해보기
				curPosX += dir[cameraDirIdx[i]][0];
				curPosY += dir[cameraDirIdx[i]][1]; 
				
				//벽이거나 6이면 빠져나오고 다음 방향 살펴보기
				if(isWall(curPosX, curPosY, N, M) || arr[curPosX][curPosY] == 6) 
					break;
														
				//해당 지역 투시로 바꾸기, 숫자면 패스					
				if(arr[curPosX][curPosY] == 0)
					arr[curPosX][curPosY] = -1;
			}
		}
	}
	
	private boolean isWall(int x, int y, int N, int M)
	{
		return x < 0 || x >= N || y< 0 || y >= M;
	}
	//방향, 회전, ray;
}

public class Main {	
	static int N;
	static int M;
	static int arr[][];
	static ArrayList<Camera> cam;
	static int camCnt;
	static int answer = Integer.MAX_VALUE;
	
	//카메라 개수만큼 경우의수
	static int input[];
	
	static void Perm(int dep)
	{
		if(dep == camCnt)
		{
			//System.out.println(Arrays.toString(input));
			
			int copyArr[][] = new int[N][M];
			for(int i = 0; i<N; i++)
				for(int j = 0; j<M; j++)
					copyArr[i][j] = arr[i][j];
			
			//카메라를 경우의 수 대로 방향을 조절하고 복사한 배열에 투시해본다.
			for(int i = 0; i<camCnt; i++)
			{
				Camera c = cam.get(i);
				c.RotateCamera(input[i]);
				c.RayCamera(copyArr);
				c.InitCamera();				
			}
			
			//###DEBUG	
			//for(int ar[] : copyArr)
			//	System.out.println(Arrays.toString(ar));
			
			//System.out.println();
			//###
						
			//복사한 배열에서 0의 개수를 세고 최소값을 구한다.			
			int sagak = 0;
			for(int i = 0; i<N; i++)
			{
				for(int j = 0; j < M; j++)
				{
					if(copyArr[i][j] == 0)
						sagak++;
				}
			}			
			answer = Math.min(answer, sagak);			
			return;
		}
		
		for(int i = 0; i<4; i++)
		{
			input[dep] = i;
			Perm(dep +1);
		}
	}
	
	public static void main(String[] args) throws IOException{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		
		arr = new int[N][M];
		
		cam = new ArrayList<>();
		
		for(int i = 0; i< N; i++)
		{
			st = new StringTokenizer(br.readLine());
			
			for(int j = 0; j<M; j++)
			{
				arr[i][j] = Integer.parseInt(st.nextToken());
				
				//숫자 1~ 5 사이이면 카메라 만들기
				//카메라는 방향을 가지며 투시, 회전 기능을 수행한다.
				if(arr[i][j] > 0 && arr[i][j] < 6)
				{
					Camera c = new Camera(arr[i][j], i, j);
					cam.add(c);
				}
			}
		}
		camCnt = cam.size();
		input = new int[camCnt];
		//0부터 3까지 중복순열
		Perm(0);
		System.out.println(answer);
		//
	}
}
