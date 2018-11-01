package cls;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.Map;

public class Test {

	public static void main(String[] args) {
		// TODO 自動生成されたメソッド・スタブ
		int i=0;
		ArrayList<Integer> l = new ArrayList<Integer>();
		l.add(1); l.add(2);

		Map<Integer, ArrayList<Integer>> cmap = new HashMap<Integer, ArrayList<Integer>>();
		for(i=0; i<10; i++) {
			cmap.put(i, new ArrayList<Integer>());
			cmap.get(i).add(i);
		}

		cmap.get(3).addAll(l);
		cmap.remove(4);

		for(i=0; i<10; i++) System.out.println(cmap.get(i));
		System.out.println(cmap.get(4));
	}

}
