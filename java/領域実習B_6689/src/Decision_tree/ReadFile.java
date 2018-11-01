package Decision_tree;

import java.io.BufferedReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;

public class ReadFile {
	BufferedReader br;

	ReadFile(BufferedReader br) {
		this.br = br;
	}

	List<HashMap<String, Integer>> reader() throws IOException {
		int i, j, k;
		String buffer; String[] buffer_s;
		buffer = br.readLine();
		buffer_s = buffer.split(",");
		int kind = buffer_s.length-1;

		List<HashMap<String, Integer>> lm = new ArrayList<HashMap<String, Integer>>();
		for(i=0; i<kind; i++) lm.add(new HashMap<String, Integer>());
		for(i=0; i<kind; i++) {
			buffer_s = br.readLine().split(",");
			for(j=0; j<buffer_s.length-1; j++) lm.get(i).put(buffer_s[j+1], j);
		} //‚±‚±‚Å—v‘f‚Æ’l‚Ì‘Î‰ž•\Š®¬

		br.close();
		return lm;
	}

}
