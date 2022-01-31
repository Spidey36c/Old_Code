package editor;
/*
 * Name: James Nordquist
 * Description: Simple Text Editor
 */
import javax.swing.JFrame;
import javax.swing.JScrollPane;

public class MainWindow {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		JFrame myFrame = new JFrame();
		myFrame.setSize(600, 400);
		myFrame.setTitle("James Nordquist");
		myFrame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		
		MyTextArea textArea = new MyTextArea();
		JScrollPane scrollPane = new JScrollPane(textArea);
		myFrame.add(scrollPane);
		
		myFrame.setJMenuBar(new MyMenu(textArea, myFrame));
		
		myFrame.setVisible(true);
	}

}
