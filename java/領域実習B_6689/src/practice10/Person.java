package practice10;

public class Person {
	String name;
	String phone;
	String fax;
	String mail;
	int age;
	float income;

	Person() {;}

	Person(String name, int age, float income) {
		this.name = name;
		this.age = age;
		this.income = income;
	}

	Person(String name, String phone, String fax, String mail) {
		this.name = name;
		this.phone = phone;
		this.fax = fax;
		this.mail = mail;
	}

	void print() {
		System.out.printf("%s %s %s %s\n", name, phone, fax, mail);
	}

}
