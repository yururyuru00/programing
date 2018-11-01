package SVM;

import java.util.Random;

public class Random2_ {

	int c1 = 0, c2 = 0;
	Random r;

	Random2_() {
		long seed = System.currentTimeMillis();
		r = new Random(seed);
	}

	boolean make() {
		/* このクラスのc1はbw1側に書き込んだサンプル数，c2はbw2側に書き込んだサンプル数ですね．
		 * そうすると．c1が90, あるいはc2が10ならば，乱数を取る必要がなく，書き込む先が決まりますね．
		 * 書き込み先が決まっていない場合にのみ，乱数をとって，書き込み先にしたがって，c１かｃ２を増やすのが適切だと思います．
		 * それに従って下記を書き直しました．
		 * */


		if(c1==90){
			c2++;
			return false;
		}else if(c2==10){
			c1++;
			return true;
		}else{
			int r2 = r.nextInt(10);//inokuchi r2はこの関数のみで使われているので，ここで定義したほうがよい． あと，９ではなく１０では？

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