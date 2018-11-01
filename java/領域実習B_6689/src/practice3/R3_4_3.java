package practice3;

public class R3_4_3 {

	public static void main(String[] args) {
		int a = Integer.parseInt(args[0]);
		double root = Math.sqrt(Double.parseDouble(args[0]));
		for(int i=2; i<=root; i++)
			if(a%i==0) System.out.println(i + " " + a/i + " ");
			else ;
	}

}
