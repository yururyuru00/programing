package 第一回;

import java.applet.Applet;
import java.awt.Color;
import java.awt.Graphics;

public class MyGraphic extends Applet {
	public void init(){
		setBackground(Color.white);
	}
	public void paint(Graphics g){
		g.setColor(Color.red);
		g.drawString("This is My First Applet",5,20);
	}
}