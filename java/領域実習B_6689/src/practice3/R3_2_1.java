package practice3;

public class R3_2_1 {

	public static void main(String[] args) {
		double d1 = Double.parseDouble(args[0]);
		double d2= Double.parseDouble(args[1]);
		if(d2!=0) System.out.println(d1/d2);
		else System.out.println("∞");
	}

}
