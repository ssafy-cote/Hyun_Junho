package SSAGAKKO;

import java.util.Arrays;

class Solution {
    public boolean solution(String[] phone_book) {
        boolean answer = true;
        
        Arrays.sort(phone_book);
        
        for(int i = 0; i<phone_book.length-1; i++)
        {
        	for(int j = i+1; j<phone_book.length; j++)
        	{
        		//있으면 0, 없으면 -1을 반환
        		int isFind = phone_book[j].indexOf(phone_book[i]);
        		//System.out.println(phone_book[i]+"의 키워드가 "+phone_book[j]+"있나?"+isFind);
        		if(isFind == 0)
        		{
        			answer = false;
        			break;
        		}
        	}
        }
                
        return answer;
    }
}

public class pgl2_전화번호목록 {

	public static void main(String[] args) {
		
		Solution s = new Solution();
		String str[] = {"12", "123", "1235", "567", "88"};
		System.out.println(s.solution(str));
	}

}
