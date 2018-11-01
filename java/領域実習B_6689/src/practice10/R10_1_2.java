package practice10;
import java.util.Random;

public class R10_1_2 {

	public static void main(String[] args) {
		int i;
		Random g1 = new Random();
		g1.setSeed(1);

		for(i=0; i<10; i++) System.out.print(g1.nextInt() + " ");
		System.out.println("");

		Random g2 = new Random();
		g2.setSeed(1);

		for(i=0; i<10; i++) System.out.print(g2.nextInt() + " ");
		System.out.println("");

		Random g3 = new Random();
		g3.setSeed(2);

		for(i=0; i<10; i++) System.out.print(g3.nextInt() + " ");
	}

}

