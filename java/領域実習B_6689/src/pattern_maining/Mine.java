package pattern_maining;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.Iterator;
import java.util.List;

public class Mine {
	int i, count, itemSize;
	HashMap<List<Integer>, Integer> sup = new HashMap<List<Integer>, Integer>();

	Mine()  {
		count=0;
		itemSize = ReadWrite.itemSize;
	}

	void mine(List<Integer> l, List<List<Integer>> ll, int limit) {
		for(int i=Max(l)+1; i<=itemSize; i++) {
			Iterator<List<Integer>> it = ll.iterator();
			List<Integer> l2 = new ArrayList<Integer>();
			l2.addAll(l); l2.add(i);
			count=0;
			while(it.hasNext()) {if(search(l2, it.next())==true) count++;} //各買い物籠リストに対して含まれるか判定
			if(count>=limit) {
				sup.put(l2, count); //閾値より支持度が高ければ、リストに追加
				this.mine(l2, ll, limit); //ここで再帰処理
			}
		}
	}

	HashMap<List<Integer>,Integer> returnSup () {return sup;}

	static int Max(List<Integer> l) { //リスト内の最大値を返す
		if(l.size()==0) return 0;
		else return l.get(l.size()-1);
	}

	static boolean search(List<Integer> l1, List<Integer> l2) { //包含関係にあるかを判定
		Iterator<Integer> it1 = l1.iterator();
		Iterator<Integer> it2 = l2.iterator();
		boolean flag = true;
		Integer a; int counter=0;

		while(it1.hasNext()) {
			a = it1.next();
			while(it2.hasNext()) {
				if(a == it2.next()) {
					counter++;
					break;
				}
			}
		}
		if(counter!=l1.size()) flag = false;

		return flag;
	}

}
