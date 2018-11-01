package practice1;

public class R1_15_3 {

	public static void main(String[] args) {
		double d[] = new double[4];
		double sum=0;
		int i;
		for(i=0; i<4; i++) {
			d[i] = i*i;
			System.out.println(d[i]);
		}
		for(i=0; i<4; i++) sum += d[i];
		System.out.println(sum/i);
	}

}
