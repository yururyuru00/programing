package pattern_maining;

import java.io.BufferedReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;

public class ReadWrite {
	BufferedReader br;
	static int guestSize, itemSize;
	int i, j, k;

	ReadWrite(BufferedReader br) {
		this.br = br;
	}

	List<List<Integer>> read() throws IOException {
		String[] buffer_s;
		buffer_s = br.readLine().split(",");
		guestSize = Integer.parseInt(buffer_s[0]); //
		itemSize = Integer.parseInt(buffer_s[1]);
		i=0; j=0; k=0; List<List<Integer>> ll = new ArrayList<>();

		for(i=0; i<guestSize; i++) { //ここですべての買い物籠を作成
			buffer_s = br.readLine().split(",");
			ll.add(new ArrayList<Integer>());
			List<Integer> l = ll.get(i);
			for(j=0; j<buffer_s.length; j++) {
				l.add(Integer.parseInt(buffer_s[j]));
			}
		}
		return ll; //すべての買い物籠作成完了
	}
}

