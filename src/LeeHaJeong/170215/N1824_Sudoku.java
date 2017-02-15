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
		
		//�� ��ġ�� �����ϴ� ����Ʈ
		zeroP = new ArrayList<>();
		
		for(int i=0; i<9; i++)
			for(int j=0; j<9; j++){
				pan[i][j] = kbd.nextInt();
				if(pan[i][j] == 0)
					zeroP.add(new Point(i, j));
			}
		
		//��Ʈ��ŷ �Լ� ����, parameter�� ��� ����Ʈ�� index
		calcSudoku(0);
		
		
		
	}
	
	public static void calcSudoku(int num){
		//�� ���� ���������� �������� ��,
		//�� �� ���� ��� ä������ �� ����
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
		//num ��ġ�� �� �� �ִ� ���ڸ���� �ҷ���
		ArrayList<Integer> list = getNum(p.x, p.y);
		
		//����� ���� ���� ���� ���� ��
		if(list.size() == 0)
			return;
		
		for(int i=0; i<list.size(); i++){
			pan[p.x][p.y] = list.get(i);
			if(stop)
				return;
			else//���� �ܰ�� �̵�
				calcSudoku(num+1);
		}
		
		//���� �ܰ�� ���ư� ������ �ݵ�� ������ġ��
		//�ٽ� �� ������ ��ȯ�Ͽ��� �Ѵ�.
		pan[p.x][p.y] = 0;
	}
	
	
	//������ ���ڸ� ������ �Լ�
	public static ArrayList<Integer> getNum(int x, int y){
		boolean flag = true;
		ArrayList<Integer> list = new ArrayList<>();
		for(int i=1; i<=9; i++)
			if(lineXCheck(x,i) && lineYCheck(y,i) && recCheck(x,y,i))
				list.add(i);
		
		return list;
	}
	
	//���μ��� �˻��Ͽ� ������ �������� Ȯ��
	public static boolean lineXCheck(int lineX, int input){
		for(int i=0; i<9; i++)
			if(pan[lineX][i] == input)
				return false;
		
		return true;
	}
	
	//���μ��� �˻��Ͽ� ������ �������� Ȯ��
	public static boolean lineYCheck(int lineY, int input){
		for(int i=0; i<9; i++)
			if(pan[i][lineY] == input)
				return false;
		return true;
	}
	
	//���Ե� �簢���� �˻��Ͽ� ������ �������� Ȯ��
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
