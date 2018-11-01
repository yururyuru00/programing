package SVM;
import java.io.BufferedWriter;
import java.io.IOException;

public class ReadWrite {
	BufferedWriter bw1;
	BufferedWriter bw2;

	ReadWrite(BufferedWriter bw1, BufferedWriter bw2) {
		this.bw1 = bw1;
		this.bw2 = bw2;
	}

	void write(boolean flag, String buffer) throws IOException {
		String[] buffer_s = buffer.split(",");

		BufferedWriter bw;
		if(flag) bw = bw1;
		else bw = bw2;

		if (buffer_s[4].equals("Iris-setosa"))
			bw.write("+1 ");
		else
			bw.write("-1 ");

		for (int i = 0; i < buffer_s.length - 1; i++)
			bw.write(i + 1 + ":" + buffer_s[i] + " ");
		bw.write("\n");


	}
}
