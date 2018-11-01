package practice10;
import java.util.Vector;

public class R10_4_3 {

	public static void main(String[] args) {
		int i;
		Vector<Double> v = new Vector<Double>();

		for(i=0; i<args.length; i++) {
			v.add(Double.parseDouble(args[i]));
		}


		for(i--; i>=0; i--) {
			System.out.println(v.get(i));
		}
	}

}
