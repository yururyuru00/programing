package svm;

import java.util.Random;

public class Random_ {

	int c1 = 0, c2 = 0;
	//long seed; inokuchi ���̕ϐ��͕s�v
	Random r;

	Random_() {
		long seed = System.currentTimeMillis();
		r = new Random(seed);
	}

	boolean make() {
		/* ���̃N���X��c1��bw1���ɏ������񂾃T���v�����Cc2��bw2���ɏ������񂾃T���v�����ł��ˁD
		 * ��������ƁDc1��90, ���邢��c2��10�Ȃ�΁C���������K�v���Ȃ��C�������ސ悪���܂�܂��ˁD
		 * �������ݐ悪���܂��Ă��Ȃ��ꍇ�ɂ̂݁C�������Ƃ��āC�������ݐ�ɂ��������āCc�P�����Q�𑝂₷�̂��K�؂��Ǝv���܂��D
		 * ����ɏ]���ĉ��L�����������܂����D
		 * */
		
		
		if(c1==90){
			c2++;
			return false;
		}else if(c2==10){
			c1++;
			return true;
		}else{
			int r2 = r.nextInt(10);//inokuchi r2�͂��̊֐��݂̂Ŏg���Ă���̂ŁC�����Œ�`�����ق����悢�D ���ƁC�X�ł͂Ȃ��P�O�ł́H

			if (r2 != 0) {
				c1++;
				return true;
			} else {
				c2++;
				return false;
			}
		}
	}
	
}
