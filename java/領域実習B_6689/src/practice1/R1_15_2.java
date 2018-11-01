package practice1;

public class R1_15_2 {

	public static void main(String[] args) {
		byte byte1[] = new byte[4];

		for(int i=0; i<4; i++) byte1[i] = (byte)(i*i);

		for(int i=0; i<4; i++) System.out.println(byte1[i]);
	}

}
