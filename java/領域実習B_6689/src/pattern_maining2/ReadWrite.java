package pattern_maining2;

import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;

public class ReadWrite {
	BufferedReader br;
	static int guestSize, itemSize;
	//int i, j, k; inokuchi read���ł����g���Ă��Ȃ��ϐ��́Cread���Œ�`����ׂ�

	ReadWrite(String fileName) throws FileNotFoundException {
		this.br = new BufferedReader(new FileReader(fileName));
	}

	List<List<Integer>> read() throws IOException {
		String[] buffer_s;
		buffer_s = br.readLine().split(",");
		guestSize = Integer.parseInt(buffer_s[0]); //
		itemSize = Integer.parseInt(buffer_s[1]);
		//i = 0;
		//j = 0;
		//k = 0;
		List<List<Integer>> ll = new ArrayList<>();

		for (int i = 0; i < guestSize; i++) { // �����ł��ׂĂ̔������Ă��쐬
			buffer_s = br.readLine().split(",");
			List<Integer> l=new ArrayList<Integer>();
			ll.add(l);
			//List<Integer> l = ll.get(i); //inokuchi get�̕��������ʂȂ̂ŁC��L�̂ق����悢
			for (int j = 0; j < buffer_s.length; j++) {
				l.add(Integer.parseInt(buffer_s[j]));
			}
		}

		br.close();// inokuchi �t�@�C����ǂݏI������C�����ɕ���ׂ��D�������Ȃ��Ƒ��̃\�t�g�E�F�A�����̃t�@�C���ɃA�N�Z�X�ł��Ȃ��ꍇ������D
		return ll; // ���ׂĂ̔������č쐬����
	}
}
