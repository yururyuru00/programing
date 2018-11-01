package practice10;
import java.util.Enumeration;
import java.util.Hashtable;

public class R10_6_1 {

	public static void main(String[] args) {
		Hashtable<String, Person> tb = new Hashtable<String, Person>();
		tb.put("1111", new Person("A君", "080-5563-432", "03-6891-6800", "A_1111@kwansei.ac.jp"));
		tb.put("1112", new Person("B君", "080-5423-522", "03-6241-2450", "B_1112@kwansei.ac.jp"));
		tb.put("1113", new Person("C君", "080-2423-122", "03-3245-1450", "C_1113@kwansei.ac.jp"));

		Enumeration<String> e = tb.keys();

		while(e.hasMoreElements()) {
			String k = e.nextElement();
			Person v = tb.get(k);
			System.out.print(k + " ");
			v.print();
		}
	}

}
