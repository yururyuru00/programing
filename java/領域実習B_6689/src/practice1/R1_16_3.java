package practice1;

public class R1_16_3 {

	public static void main(String[] args) {
		byte b[][][] = new byte[3][3][3];
		int i, j, k, c=0;

		for(i=0; i<3; i++) {
			for(j=0; j<3; j++) {
				for(k=0; k<3; k++) {
					b[i][j][k] = (byte)(i+j+k);
					System.out.printf("b[%d][%d][%d] = %d\n", i, j, k, b[i][j][k]);
					c++;
				}
				if(j!=2) System.out.println("");
				else ;
			}
			System.out.println("--------------");
		}


	}
}
