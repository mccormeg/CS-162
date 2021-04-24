import java.util.Scanner;

public class intFun {
	
	public static void main (String[] args){
		int x;
		Scanner input = new Scanner(System.in);
		
		System.out.println("Enter int: ");
		x = input.nextInt();
		int [] data;
		data = initarray(x);
		populate(data, x);
		aprint(data, x);
		
	}
	
	public static void populate(int [] data, int x){
		int j = 0;
		
		for (int i = 0; i<x; i++){
			data[i]= j;
			j++;
			}
		
	}
	public static void aprint(int [] data, int x){
	for (int i = 0; i< x; i++){
			System.out.println(data[i]);

			}
	}
	public static int[] initarray(int x){
		return new int[x];
	}
}