package svm;

import java.io.BufferedReader;
import java.io.File;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;

public class Runtimer {
	Runtime rt;//�R���X�g���N�^Runtimer�ƃ��\�b�hRuntime�ŋ��L���Ďg���ϐ��͂��̕ϐ������Ȃ̂ŁC���̕ϐ��݂̂��̃N���X�̃����o�[�ϐ��ɂ��邱��
				//���̕ϐ���Runtime���\�b�h�̃��[�J���ϐ��ł悢

	//Process p1;
	//InputStream is1;
	//BufferedReader br1;
	//String line1;

	Runtimer() {
		//p1 = null;
		rt = Runtime.getRuntime();
	}

	void Runtime(String[] command, File dir) throws IOException, InterruptedException {
		Process p1 = rt.exec(command, null, dir);

		p1.waitFor();
		InputStream is1 = p1.getInputStream();

		BufferedReader br1 = new BufferedReader(new InputStreamReader(is1));

		String line1;
		while ((line1 = br1.readLine())!=null) {// �S�Ă̍s��ǂݐ؂����甲����
			System.out.println("line : " + line1); // ���s���ʂ�\��
		}
	}
}
