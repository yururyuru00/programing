package pattern_maining;

import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;

public class Pattern_Maining {

	public static void main(String[] args) throws IOException {
		String dirStr = "C:\\java\\Pattern_Maining";
		String separator="\\";
		String inputFileName = "sample_in.txt";
		//BufferedReader br = new BufferedReader(new FileReader(dirStr + separator+inputFileName));
		BufferedWriter bw = new BufferedWriter(new FileWriter(dirStr + separator+inputFileName));

		SampleMaker sm = new SampleMaker(bw);
		sm.Make(100, 10);

		/*ReadWrite rw = new ReadWrite(br); //読み書きクラス
		List<List<Integer>> ll = rw.read(); //ファイルから読み込み買い物籠リスト作成
		Mine m = new Mine(); //各買い物籠の評価値を計算するクラス

		List<Integer> l = new ArrayList<Integer>();
		int bottom = Integer.parseInt(args[0]);
		m.mine(l, ll, bottom); //ここで計算開始 再帰処理は関数内部で行う

		HashMap<List<Integer>,Integer> sup = m.returnSup(); //計算後、支持度をMineクラスから受け取る

		for(List<Integer> key : sup.keySet()) //閾値を超えた支持度の組み合わせを表示
			System.out.println(key + " " + sup.get(key) + "回");

		br.close();
		*/
	}
}
