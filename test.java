import java.util.Dictionary;
import java.util.Hashtable;

class test {
  public static void main(String[] args) {
    System.out.println(maxNumberOfBalloons("balllllllllllloooooooooon"));
  }

  public static int maxNumberOfBalloons(String text) {
    Dictionary<Character, Integer> dict = new Hashtable<>();
    dict.put('b', 0);
    dict.put('a', 0);
    dict.put('l', 0);
    dict.put('o', 0);
    dict.put('n', 0);
    text = text.replaceAll("[cdefghijkmpqrstuvwxyz]", "");
    return 0;
  }
}
