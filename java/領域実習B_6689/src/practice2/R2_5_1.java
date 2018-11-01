package practice2;

public class R2_5_1 {

	public static void main(String[] args) {
		Integer i1 = new Integer(3);
		Integer i2 = new Integer("3");
		if(i1.equals(i2)==true) System.out.println("同じ");
		else System.out.println("違う");
	}

}
