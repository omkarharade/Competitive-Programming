package basics;

public class First {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		
		
		try {
			int sum;sum = 10;
			for(int i = -1; i < 3; i++) {
				sum = (sum/i);
			}
		}
		catch(ArithmeticException e) {
			System.out.print("0");
		}
		System.out.println(sum);

	}

}
