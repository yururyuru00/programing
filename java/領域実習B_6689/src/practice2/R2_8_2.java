package practice2;

public class R2_8_2 {

	public static void main(String[] args) {
		StringBuffer sb1 = new StringBuffer("c");
		System.out.println("挿入前: " + sb1.toString());

		sb1.insert(0,  "b");
		System.out.println("挿入後: " + sb1.toString());

		StringBuffer sb2 = new StringBuffer("a");
		sb1.insert(0,  sb2);
		System.out.println("更に挿入後: " + sb1.toString());
	}

}
