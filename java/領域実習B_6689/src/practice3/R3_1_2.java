package practice3;

public class R3_1_2 {

	public static void main(String[] args) {
		double d = Double.parseDouble(args[0]);
		if(args[1].equals("feet")) System.out.println("feet>>>meters " + d/3.2808);
		else if(args[1].equals("meters")) System.out.println("meters>>>feet " + d*3.2808);
		else System.out.println("この単位は認識できません");

	}

}
