package practice10;
import java.util.Random;

public class R10_1_1 {

	public static void main(String[] args) {
		int i, sum=0;
		Random generator = new Random();

		if(args.length!=0) {
			for(i=0; i<Integer.parseInt(args[0]); i++) {
				sum += generator.nextInt();
			}
			System.out.println(sum/Integer.parseInt(args[0]));
		}
		else {
			for(i=0; i<100; i++) {
				sum += generator.nextInt();
			}
			System.out.println(sum/100);
		}

	}

}
