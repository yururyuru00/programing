package svm;

import java.io.BufferedWriter;
import java.io.IOException;

public class Writer {
	BufferedWriter bw1;
	BufferedWriter bw2;
	//String buffer; inokuchi この変数は使われていないので，不要
	//String[] buffer_s = new String[5]; inokuchi この変数はこのwriteメソッド内でしか使われていないので，write内で宣言したほうがよい，また= new String[5]は不要

	Writer(BufferedWriter bw1, BufferedWriter bw2) {
		this.bw1 = bw1;
		this.bw2 = bw2;
	}

	void write(boolean flag, String buffer) throws IOException {
		String[] buffer_s = buffer.split(",");//inokuchi 第2引数はなくてもよい

		BufferedWriter bw;
		
		if(flag)
			bw=bw1;
		else
			bw=bw2;
	
		//inokuchi flagがtrueの場合とfalseの場合で，内容が重複していました．
		//同じ内容のコードは1つのほうが良いです．例えば，true側でバグを見つけたとして，
		//そのバグを修正し，その後．false側のバグを修正し忘れるかもしれないので．
		if (buffer_s[4].equals("Iris-setosa"))
			bw.write("+1 ");
		else
			bw.write("-1 ");

		for (int i = 0; i < buffer_s.length - 1; i++)
			bw.write(i + 1 + ":" + buffer_s[i] + " ");
		bw.write("\n");
		
	}
}
