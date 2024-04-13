import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Collections;
import java.util.LinkedList;
import java.util.StringTokenizer;
 
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.StringTokenizer;
  
public class Solution {
  
    /*
     * NxN 정사각형 안에 K군집의 의 미생물이 있다. 이 미생물은 하나에 X개의 미생물 수를 포함하고 있다.
     * 
     *■ 미생물이 테두리에 부딫히면 절반으로 줄어들고 방향이 반대쪽으로 바뀐다.
     *■ 미생물끼리 부딫히면 더 큰 미생물이 되고 더 큰 미생물 기준으로 방향이 잡힌다. (같은 경우는 없다.)
     *
     *N은 5이상 100 이하 (100 * 100) 10000
     *M은 시간 -> (1 이상 1000이하)
     *미생물군집 K는 5 이상 1000이하
     * 미생물 수는 10000 이하 (다 더해도 1000만 안넘어감 - > int)
     */
  
    static class Bacteria implements Comparable<Bacteria>
    {
        int posX, posY, count, dirX, dirY, index;
          
        public Bacteria(int x, int y, int cnt, int dirX, int dirY, int index)
        {
            posX = x;
            posY = y;
            count = cnt;
            this.dirX = dirX;
            this.dirY = dirY;
            this.index = index;
        }
          
        //move 함수
        public int Move(int N)
        {
            posX += dirX;
            posY += dirY;
            index = (posX * N) + posY;
              
            if(isEdge(posX, posY, N))
            {
                //System.out.println(posX+" "+posY+"의 좌표 바뀜");
                count /= 2;
                  
                dirX *= -1;
                dirY *= -1;
            }
              
            return count;
        }
          
        public boolean isEdge(int x, int y, int N)
        {
            return x < 1 || x >=N-1 || y < 1 || y >= N-1;
        }
 
        @Override
        public int compareTo(Bacteria o) {
            if(this.index == o.index)
                return o.count - this.count;
             
            return o.index - this.index;
        }
         
         
    }
      
    static LinkedList<Bacteria> bacList;
      
    static int N, M, K;
    //static int arr[][];
    static final int dir[][] = {{0,0},{-1,0},{1,0},{0, -1}, {0, 1}};//무, 상 하 좌 우
    public static void main(String[] args) throws NumberFormatException, IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
          
        int TC = Integer.parseInt(br.readLine());
        int tc = 0;
        while(tc++ < TC)
        {
            st = new StringTokenizer(br.readLine());
            N = Integer.parseInt(st.nextToken());
            M = Integer.parseInt(st.nextToken());
            K = Integer.parseInt(st.nextToken());
              
            //arr = new int[N][N];
              
            int x, y, k, d;
            bacList = new LinkedList<>();
              
            for(int i = 0; i<K; i++)
            {
                st = new StringTokenizer(br.readLine());
                x = Integer.parseInt(st.nextToken());
                y = Integer.parseInt(st.nextToken());
                k = Integer.parseInt(st.nextToken());
                d = Integer.parseInt(st.nextToken());
                  
                int dirX = dir[d][0];
                int dirY = dir[d][1];
                int index = (x * N)+y;
                bacList.add(new Bacteria(x, y, k, dirX, dirY, index));
            }
              
            //오른쪽이 크면(양수가 나오면) 순서를 바꾼다.
            //박테리아가 많은 수를 우선해서 내림차순
                          
            //메인로직
            while(M-- >0)
            {
                //카운트가 가장 큰 미생물 순으로 정렬한다.
                //bacList.sort((o1, o2)->{return o2.count - o1.count;});
                 
                //미생물 이동    
                for(int i = 0; i<bacList.size(); i++)
                {
                    Bacteria bac = bacList.get(i);
                      
                    //카운트가 0인 미생물은 리스트에서 삭제된다.
                    if(bac.Move(N) == 0)
                    {
                        bacList.remove(i);
                        i--; //인덱스 벗어나지 않게 당겨주기
                    }
                }
                Collections.sort(bacList);
                  
                for(int i = 0; i< bacList.size()-1; i++)
                {
                    Bacteria bac = bacList.get(i);
                    Bacteria bac2 = bacList.get(i+1);
                     
                    //같은 좌표가 나온다면 합친다.
                    if(bac.index == bac2.index)
                    {
                        //System.out.println("A의 위치: "+bac.posX+" "+bac.posY + " B의 위치: "+bac2.posX+" "+bac2.posY);
                        //System.out.println("A의 카운트 "+bac.count+" B의 카운트"+bac2.count+"더해줌");
                        bac.count += bac2.count;
                        bacList.remove(i+1);
                        i--;
                    }
                }
                 
                //DebugPrint();
            }
              
            int answer = 0;
            for(Bacteria b : bacList)
                answer += b.count;
          
            System.out.println("#"+tc+" "+answer);              
        }
    }
  
      
    static void DebugPrint()
    {
        //#####DEBUG
        int arrDebug[][] = new int[N][N];
        for(Bacteria b : bacList)
        {
            arrDebug[b.posX][b.posY] = b.count;
        }
          
        for(int i = 0; i<N; i++)
        {
            for(int j = 0; j<N; j++)
            {
                System.out.print(arrDebug[i][j]+"\t");
            }
            System.out.println();
        }
        System.out.println();
        //#############
    }
}