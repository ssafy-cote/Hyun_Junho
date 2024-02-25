package SSAGAKKO;

import java.util.Scanner;

class Node {
	int start;
	int size;
	int cost;

	public Node(int start, int size, int cost) {
		this.start = start;
		this.size = size;
		this.cost = cost;
	}

	// 기간이 퇴사일을 넘기면 true 반환
	boolean isEnable(int N) {
		return start + size - 1 > N;
	}
}

public class B_14501_퇴사 {

	/*
	 * N일동안 상담을 진행한다.
	 * 
	 * 최대한 많은 상담 -> 그리디? 하루에 하나씩 서로 다른 사람의 상담 중복 불가.
	 * 
	 * 프로세스 (완탐) a1 ~ aN까지 한 파트를 선택한다.
	 * 
	 * a(i)가 끝나고 난 이후 가장 가깝고 짧은 회의를 선택한다. 담는다
	 */

	static int N;
	static Node schedule[];
	static boolean isUsed[];
	static int maxCost = 0;

	static void PowerSet(int dep) {
		if (dep == N) {
			int curMaxCost = 0;
			for (int day = 0; day < N; day++) {
				if (isUsed[day]) {
					// 코스트 증가시켜주기
					curMaxCost += schedule[day].cost;
					if ((schedule[day].size + day) > N)
						return;

					for (int j = 1; j < schedule[day].size; j++) {
						if (isUsed[day + j])
							return;
					}
					// 1의 길이 + 1이 N보다 크면
					// 2의 길이 + 2가 N보다 크면
					// 3의 길이 + 3이 N보다 크면
				}
			}

			maxCost = Math.max(curMaxCost, maxCost);
			return;
		}

		isUsed[dep] = true;
		PowerSet(dep + 1);
		isUsed[dep] = false;
		PowerSet(dep + 1);

	}

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		N = sc.nextInt();
		schedule = new Node[N];
		isUsed = new boolean[N];

		for (int i = 0; i < N; i++) {
			int time = sc.nextInt();
			int cost = sc.nextInt();
			schedule[i] = new Node(i, time, cost);
		}

		PowerSet(0);
		System.out.println(maxCost);
	}

}
