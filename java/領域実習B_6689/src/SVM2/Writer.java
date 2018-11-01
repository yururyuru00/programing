package svm;

import java.io.BufferedWriter;
import java.io.IOException;

public class Writer {
	BufferedWriter bw1;
	BufferedWriter bw2;
	//String buffer; inokuchi ���̕ϐ��͎g���Ă��Ȃ��̂ŁC�s�v
	//String[] buffer_s = new String[5]; inokuchi ���̕ϐ��͂���write���\�b�h���ł����g���Ă��Ȃ��̂ŁCwrite���Ő錾�����ق����悢�C�܂�= new String[5]�͕s�v

	Writer(BufferedWriter bw1, BufferedWriter bw2) {
		this.bw1 = bw1;
		this.bw2 = bw2;
	}

	void write(boolean flag, String buffer) throws IOException {
		String[] buffer_s = buffer.split(",");//inokuchi ��2�����͂Ȃ��Ă��悢

		BufferedWriter bw;
		
		if(flag)
			bw=bw1;
		else
			bw=bw2;
	
		//inokuchi flag��true�̏ꍇ��false�̏ꍇ�ŁC���e���d�����Ă��܂����D
		//�������e�̃R�[�h��1�̂ق����ǂ��ł��D�Ⴆ�΁Ctrue���Ńo�O���������Ƃ��āC
		//���̃o�O���C�����C���̌�Dfalse���̃o�O���C�����Y��邩������Ȃ��̂ŁD
		if (buffer_s[4].equals("Iris-setosa"))
			bw.write("+1 ");
		else
			bw.write("-1 ");

		for (int i = 0; i < buffer_s.length - 1; i++)
			bw.write(i + 1 + ":" + buffer_s[i] + " ");
		bw.write("\n");
		
	}
}
