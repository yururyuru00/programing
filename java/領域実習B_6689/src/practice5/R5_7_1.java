package practice5;

class translation {
	static String _spain(String eng) {
		if(eng.equals("One")) return "Uno";
		else if(eng.equals("Two")) return "Dos";
		else if(eng.equals("Three")) return "Tres";
		else if(eng.equals("Four")) return "Quatro";
		else if(eng.equals("Five")) return "Cinco";
		else return "翻訳出来ません";
	}
}

public class R5_7_1 {

	public static void main(String[] args) {
		System.out.println(args[0] + ": " + translation._spain(args[0]));
	}

}
