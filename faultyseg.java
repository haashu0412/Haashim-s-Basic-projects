import java.util.Scanner;

public class faultyseg {
    private static final int[] pattern = {
        0b1110111, // 0
        0b0100100, // 1
        0b1011101, // 2
        0b1101101, // 3
        0b0101110, // 4
        0b1101011, // 5
        0b1111011, // 6
        0b0100101, // 7
        0b1111111, // 8
        0b1101111  // 9
    };

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int num = sc.nextInt();
        sc.nextLine();
        char [][] led = new char[3][];
        for(int r = 0 ; r < 3; r++){
           led[r] = sc.nextLine().toCharArray();
        }
        int [] seg = parseDigitSegments(led , num);
        int faultyI = findFaultyDigit(seg);
        System.out.println(faultyI);
    }

    private static int [] parseDigitSegments(char [][] grid,int num){
        int segments = new int[num];
        for( int i = 0 ; i < num ; i++){
            int segval = 0;
            for(int r =0 ; r<3 ; r++){
                for(int c =0 ; c<3;c++){
                    if(grid[r][i *3 +c]=='|'){
                        segval |=1 << (r*3 +c);
                    }
                }
            }
            segments[i] = segval;
        }
        return segments;
    }

    private static int findFaultyDigit(int [] seg){
        for(int i=0 ; i<seg.length ; i++){
            for(int j=0 ; j<10 ;j++){
                int wrong = Integer.bitCount(seg[i]^pattern[j]);
                if(wrong == 1){
                    return i+1;
                }
            }
        }
        return -1;
    }

}
