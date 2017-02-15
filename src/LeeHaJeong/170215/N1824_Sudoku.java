import java.util.Scanner;
import java.util.ArrayList;

class Point{
	int x;
	int y;
	public Point(int x, int y){
		this.x = x;
		this.y = y;
	}
}

public class N1824_Sudoku {
	static int pan[][] = new int[9][9];
	static ArrayList<Point> zeroP;
	static boolean stop = false;
		
	public static void main(String[] args){
		
		Scanner kbd = new Scanner(System.in);
		
		//빈 위치를 저장하는 리스트
		zeroP = new ArrayList<>();
		
		for(int i=0; i<9; i++)
			for(int j=0; j<9; j++){
				pan[i][j] = kbd.nextInt();
				if(pan[i][j] == 0)
					zeroP.add(new Point(i, j));
			}
		
		//백트래킹 함수 시작, parameter는 빈곳 리스트의 index
		calcSudoku(0);
		
		
		
	}
	
	public static void calcSudoku(int num){
		//빈 곳의 마지막까지 도착했을 때,
		//즉 빈 곳이 모두 채워졌을 때 종료
		if(num == zeroP.size()){
			stop = true;
			for(int i=0; i<9; i++){
				for(int j=0; j<9; j++){
					System.out.print(pan[i][j]+" ");
				}
				System.out.println();
			}
			return;
		}
		
		Point p = zeroP.get(num);
		//num 위치에 들어갈 수 있는 숫자목록을 불러옴
		ArrayList<Integer> list = getNum(p.x, p.y);
		
		//경우의 수가 존재 하지 않을 시
		if(list.size() == 0)
			return;
		
		for(int i=0; i<list.size(); i++){
			pan[p.x][p.y] = list.get(i);
			if(stop)
				return;
			else//다음 단계로 이동
				calcSudoku(num+1);
		}
		
		//이전 단계로 돌아갈 때에는 반드시 현재위치를
		//다시 빈 곳으로 변환하여야 한다.
		pan[p.x][p.y] = 0;
	}
	
	
	//가능한 숫자를 얻어오는 함수
	public static ArrayList<Integer> getNum(int x, int y){
		boolean flag = true;
		ArrayList<Integer> list = new ArrayList<>();
		for(int i=1; i<=9; i++)
			if(lineXCheck(x,i) && lineYCheck(y,i) && recCheck(x,y,i))
				list.add(i);
		
		return list;
	}
	
	//가로선을 검사하여 가능한 숫자인지 확인
	public static boolean lineXCheck(int lineX, int input){
		for(int i=0; i<9; i++)
			if(pan[lineX][i] == input)
				return false;
		
		return true;
	}
	
	//세로선을 검사하여 가능한 숫자인지 확인
	public static boolean lineYCheck(int lineY, int input){
		for(int i=0; i<9; i++)
			if(pan[i][lineY] == input)
				return false;
		return true;
	}
	
	//포함된 사각형을 검사하여 가능한 숫자인지 확인
	public static boolean recCheck(int x, int y, int input){
		int startX = x/3*3;
		int startY = y/3*3;
		
		for(int i=startX; i<startX+3; i++)
			for(int j=startY; j<startY+3; j++)
				if(pan[i][j] == input)
					return false;
		
		return true;
	}
}
