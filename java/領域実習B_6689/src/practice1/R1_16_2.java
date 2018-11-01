package practice1;

public class R1_16_2 {

	public static void main(String[] args) {
		int i, j = 0, c = 0;
		int iarray[][] = {
				{1},
				{1, 2},
				{1, 2, 3}
		};

		for(i=0; i<iarray.length; i++) {
			for(j=0; j<iarray[i].length; j++) System.out.printf("iarray[%d][%d] = %d\n", i, j, iarray[i][j]);
			System.out.println("------------------");
			c += j;
		}

		System.out.println("要素数は" + c);
	}

}
