package practice2;

public class R2_8_1 {

	public static void main(String[] args) {
		StringBuffer sb1 = new StringBuffer("abcd");
		System.out.println(sb1.toString() + ": 追加前のbuffo= " + sb1.capacity() );
		sb1.append("efg");
		System.out.println(sb1.toString() + ": 追加後のbuffo= " + sb1.capacity() );
		sb1.append("hijklmn opqrstu vwxyz");
		System.out.println(sb1.toString() + ": 更に追加後のbuffo= " + sb1.capacity() );
	}

}
