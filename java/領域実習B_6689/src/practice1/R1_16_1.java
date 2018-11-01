package practice1;

public class R1_16_1 {

	public static void main(String[] args) {
		int i, j = 0;
		float f[][] = new float[3][3];
		f[0][0] = -1.2f;
		f[0][1] = -56.7f;
		f[0][2] = 11.3f;
		f[1][0] = 500.1f;
		f[1][1] = 70.70f;
		f[1][2] = 13.33f;
		f[2][0] = 100.9f;
		f[2][1] = 0.5f;
		f[2][2] = 20.20f;

		for(i=0; i<f.length; i++) {
			for(j=0; j<f[i].length; j++) System.out.printf("f[%d][%d] = %f\n", i, j, f[i][j]);
			System.out.println("------------------");
		}

		System.out.println("要素数は" + i*j);
	}

}
