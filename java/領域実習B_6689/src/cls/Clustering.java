package cls;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;
import java.util.Map;

public class Clustering {

	public static void main(String[] args) throws IOException {
		// TODO 自動生成されたメソッド・スタブ
		String dirStr = "C:\\java\\SVM";
		String separator="\\";
		String inputFileName = "iris.data.kwansei.txt";
		String outputFileName1 = "example_train.txt";
		String outputFileName2 = "example_predict.txt";
		BufferedReader br = new BufferedReader(new FileReader(dirStr + separator+inputFileName));
		BufferedWriter bw1 = new BufferedWriter(new FileWriter(dirStr + separator+outputFileName1));
		BufferedWriter bw2 = new BufferedWriter(new FileWriter(dirStr + separator+outputFileName2));

		int i=0, j, k, counter = 100;
		Distance distance = new Distance(); //ユークリッド距離に関する計算クラス
		double m, min; //最小値検索のときに最小値を保持、更新する
		int i_=0, j_=0; //最小値(i,j)間の検索のときのi,jを保持、更新する
		Map<Integer, ArrayList<Integer>> cmap = new HashMap<Integer, ArrayList<Integer>>();


		double[][] c = distance.classFormat(br); //iris.data.kwanseiからすべてのサンプルのデータを配列cに格納
		double[][] dist = distance.tableFormat(c); //各２点間の計算 100*100のテーブル

		for(i=0; i<100; i++) {
			cmap.put(i, new ArrayList<Integer>());
			cmap.get(i).add(i);
		}

		while(counter>2) {
			min=100;
			for(i=0; i<99; i++) {
				for(j=i+1; j<100; j++) { //min関数を使ってグループ(i, j)間の最小距離を計算
					if( (m=distance.min(cmap, i, j, dist)) < min) {
						min = m; //暫定の最小値を更新
						i_ = i; j_ = j; //暫定の最小グループ区間(i, j)を更新
					}
				}
			}
			counter = distance.update(cmap, i_, j_, dist); //tableのアップデート アップデート後のグループ数も返す
		}

		//	最終的なグループをここでソート
		for(i=0; i<100; i++) {
			if(cmap.get(i)!=null) {
				Collections.sort(cmap.get(i));
				System.out.println(cmap.get(i));
			}
		}

		br.close();
		bw1.close();
		bw2.close();
	}
}
