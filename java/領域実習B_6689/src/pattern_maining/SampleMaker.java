package pattern_maining;

import java.io.BufferedWriter;
import java.io.IOException;
import java.util.Random;

public class SampleMaker {
	BufferedWriter bw;
	Random r;

	SampleMaker(BufferedWriter bw) {
		this.bw = bw;
		r = new Random(System.currentTimeMillis());
	}

	void Make(int guestSize, int itemSize) throws IOException {

		/*int i, j, jLimit; List<Integer> item = new ArrayList<Integer>();

		for(i=0; i<guestSize; i++) {
			jLimit = r.nextInt(itemSize);
			for(j=0; j<jLimit; j++) item.add(r.nextInt(itemSize));
			Collections.sort(item);
			for(int k : item) System.out.println(k + " ");
			//System.out.println("\n");
		}*/

		for(int i=0; i<10; i++) bw.write(i);

		bw.close();
	}
}
