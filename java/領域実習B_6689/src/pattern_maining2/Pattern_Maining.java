package pattern_maining2;

//import java.io.BufferedReader;
//import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
//import java.util.HashMap;
import java.util.List;
public class Pattern_Maining {

	public static void main(String[] args) throws IOException {
		String dirStr = "";//"C:\\java\\Pattern_Maining";
		String separator = "";//"\\";
		String inputFileName = "sample_in.txt";

		ReadWrite rw = new ReadWrite(dirStr + separator+inputFileName); // �ǂݏ����N���X
		List<List<Integer>> ll = rw.read(); // �t�@�C������ǂݍ��ݔ������ă��X�g�쐬

		Mine m = new Mine(ReadWrite.itemSize); // �e�������Ă̕]���l���v�Z����N���X
		//inokuchi Mine�̃R���X�g���N�^�́CReadWrite��read�����Ȃ��Ƃ�1�񓮍삵�Ă��邱�Ƃ�O��ɍ���Ă��܂��D
		//�����łȂ��ꍇ�����̃R���X�g���N�^�����삷��悤�ɁCReadWrite.itemSize�������ŗ^����悤�ɏC�����܂����D
		//���̂ق����CMine�̃R���X�g���N�^�̔ėp���������ł��D�����ł́C����rw.read();���Ă�ł��āC
		//ReadWrite��read��1�񓮍삵�Ă��邱�Ƃ��ۏ؂����̂�ReadWrite.itemSize�������Ƃ��ė^���邱�Ƃ͖��Ȃ��ł��D

		List<Integer> l = new ArrayList<Integer>();
		int bottom = Integer.parseInt(args[0]);
		m.mine(l, ll, bottom); // �����Ōv�Z�J�n �ċA�����͊֐������ōs��

		//HashMap<List<Integer>, Integer> sup = m.returnSup(); // �v�Z��A�x���x��Mine�N���X����󂯎��

		//for (List<Integer> key : sup.keySet()) // 臒l�𒴂����x���x�̑g�ݍ��킹��\��
		//System.out.println(key + " " + sup.get(key) + "��");
		//inokuchi ���i����n�Ƃ���ƁC���ƂȂ����2��n��-1���݂��܂��D
		//�����ł́Cn=10�Ȃ̂ŁC���̌��̌��͍��X1023�ł����Cn�������ȏ�̏ꍇ�ł����̃v���O���������삷��悤��
		//�݌v�ł��Ă���Ƃ悢�v���O�������Ƃ����܂��D���ׂẲ�����������ɕێ����邱�Ƃ͌����I�ł͂Ȃ��̂ŁC
		//���������邽�тɁC�o�͂���i�W���o�͂�t�@�C���ցj�ق����K�؂ƂȂ�܂��D
		//�����ŁC�\���̕�����Mine�N���X��mine�Ɉړ������܂����D


		//br.close();
	}
}
