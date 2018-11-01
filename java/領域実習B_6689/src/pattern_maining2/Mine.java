package pattern_maining2;

import java.util.ArrayList;
//import java.util.HashMap;
import java.util.Iterator;
import java.util.List;

public class Mine {
	//int i;
	//int count; inokuchi �ϐ��̃X�R�[�v�͒Z���ق����C�ǂݎ�ɂƂ��Ė]�܂����D
	int itemSize;
	//HashMap<List<Integer>, Integer> sup = new HashMap<List<Integer>, Integer>();

	Mine(int itemSize) {
		//count = 0;
		this.itemSize = itemSize;
	}

	void mine(List<Integer> l, List<List<Integer>> ll, int limit) {


		for (int i = Max(l) + 1; i <= itemSize; i++) {
			List<Integer> l2 = new ArrayList<Integer>();
			l2.addAll(l);
			l2.add(i);
			int count = 0;
			for (List<Integer> transaction : ll) {//inokuchi ����ȏ��������ł��܂��Diterator���g��Ȃ����Ƃ�1�s�Z���Ȃ�܂����D
				if (search(l2, transaction)) //inokluchi ==true�͂Ȃ��Ă��悢�D�ނ���Ȃ��ق����悢�D
					count++;
			} // �e�������ă��X�g�ɑ΂��Ċ܂܂�邩����
			if (count >= limit) {
				System.out.println(l2 + " " + count + "��");
				//sup.put(l2, count); // 臒l���x���x��������΁A���X�g�ɒǉ�
				this.mine(l2, ll, limit); // �����ōċA����
			}
		}
	}

	/*HashMap<List<Integer>, Integer> returnSup() {
		return sup;
	}*/

	//static inokuchi static �s�v
	int Max(List<Integer> l) { // ���X�g���̍ő�l��Ԃ�
		if (l.size() == 0)
			return 0;
		else
			return l.get(l.size() - 1);
	}

	//static
	boolean search(List<Integer> l1, List<Integer> l2) { // ��܊֌W�ɂ��邩�𔻒�

		Iterator<Integer> it1 = l1.iterator();
		Iterator<Integer> it2 = l2.iterator();

		while (it1.hasNext()) {
			boolean notFind = true;
			int a = it1.next();
			while (it2.hasNext()) {
				if (a == it2.next()) {
					notFind=false;
					break;
				}
			}
			if(notFind)//inokuchi l1�̂P�̗v�f��������Ȃ����_�ŁCfalse��Ԃ����Ƃ��ł���
				return false;
		}
		return true;
	}


	boolean search2(List<Integer> l1, List<Integer> l2) { // ��܊֌W�ɂ��邩�𔻒�

		//inokuchi ���̂悤�ɁC�v���O�����̒�����Z���ł��܂��D�����Clist���\�[�g����Ă��邱�Ƃ�O��ɂ�����Csearch�̂悤�ɓ�������̗ǂ��v���O�������������Ƃ��ł��܂��D
		//l1,l2�̒��������ꂼ��|l1|, |l2|�Ƃ���ƁC���̃��\�b�h�̌v�Z���Ԃ�O(|l1||l2|)������܂����C
		//���search��O(|l1|+|l2|)�ł��݂܂��D
		for(Integer item : l1){
			if(!l2.contains(item))
				return false;
		}
		return true;

	}

}
