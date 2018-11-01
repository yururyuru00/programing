package SVM;
import java.io.BufferedReader;
import java.io.File;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;

public class Runtimer {
	Runtime rt;

	Runtimer() { rt = Runtime.getRuntime(); }

	void Runtime(String[] command, File dir) throws IOException, InterruptedException {
		Process p1 = rt.exec(command, null, dir);

		p1.waitFor();
		InputStream is1 = p1.getInputStream();

		BufferedReader br1 = new BufferedReader(new InputStreamReader(is1));

		String line1;
		while ((line1 = br1.readLine())!=null) {// 全ての行を読み切ったら抜ける
			System.out.println("line : " + line1); // 実行結果を表示
		}
	}
}
