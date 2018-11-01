package pattern_maining;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;

class A {
	static int i=0;
	A() {i++;}
	int returnInt() {return i;}
}

public class Test {

	public static void main(String[] args) throws IOException {
		String dirStr = "C:\\java\\Pattern_Maining";
		String separator="\\";
		String inputFileName = "sample_in.txt";
		String outPutFileName = "sample_in.txt";
		BufferedReader br = new BufferedReader(new FileReader(dirStr + separator+inputFileName));
		BufferedWriter bw = new BufferedWriter(new FileWriter(dirStr + separator+outPutFileName));

		for(int i=0; i<10; i++) bw.write(2*i + " ");

		bw.close();
	}


}


