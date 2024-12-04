
package SEE;

import CIE.Student;

public class External extends Student {
    public int[] seeMarks;

    public External(String usn, String name, int sem, int[] seeMarks) {
        super(usn, name, sem);
        this.seeMarks = seeMarks;
    }

    public void displaySeeMarks() {
        System.out.println("SEE Marks: ");
        for (int i = 0; i < seeMarks.length; i++) {
            System.out.println("Course " + (i + 1) + ": " + seeMarks[i]);
        }
    }
}
