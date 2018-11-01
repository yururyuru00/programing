package practice2;

public class R2_10_2 {

	public static void main(String[] args) {
		double r = Double.parseDouble(args[0]);
		double area = Math.PI*r*r;
		System.out.printf("半径%.2fの面積は%.2f", r, area);
	}

}
