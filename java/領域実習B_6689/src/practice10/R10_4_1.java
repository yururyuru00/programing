package practice10;
import java.util.Enumeration;
import java.util.Random;
import java.util.Vector;

public class R10_4_1 {

	public static void main(String[] args) {
		Random r = new Random();
		r.setSeed(System.currentTimeMillis());

		Vector<Double> v = new Vector<Double>();
		for(int i=0; i<20; i++) v.add(r.nextGaussian());

		Enumeration<Double> e = v.elements();

		while(e.hasMoreElements()) {
			Double d = e.nextElement();
			System.out.println(d);
		}

	}

}
