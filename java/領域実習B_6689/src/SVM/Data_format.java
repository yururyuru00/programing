package SVM;//inokuchi パッケージ名は小文字にするのが，Javaの慣例

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;

public class Data_format {//inokuchi クラス名の一文字目は大文字にするのが慣例

	public static void main(String[] args) throws Exception {
		String dirStr = "C:\\java\\SVM";
		String separator="\\";

		String inputFileName = "iris.data.kwansei.txt";
		String outputFileName1 = "example_train.txt";
		String outputFileName2 = "example_predict.txt";

		BufferedReader br = new BufferedReader(new FileReader(dirStr + separator+inputFileName));
		BufferedWriter bw1 = new BufferedWriter(new FileWriter(dirStr + separator+outputFileName1));
		BufferedWriter bw2 = new BufferedWriter(new FileWriter(dirStr + separator+outputFileName2));

		String buffer;
		Random2_ random = new Random2_();
		ReadWrite writer = new ReadWrite(bw1, bw2);

		while ((buffer = br.readLine()) != null)
			writer.write(random.make(), buffer);

		br.close();
		bw1.close();
		bw2.close();

		String[] command_t = { dirStr + separator+"svm-train", outputFileName1, "modelFile" };
		String[] command_p = { dirStr + separator+"svm-predict", outputFileName2, "modelFile", "output.txt" };
		File dir = new File(dirStr);
		Runtimer rt = new Runtimer();

		rt.Runtime(command_t, dir);
		rt.Runtime(command_p, dir);

	}

}