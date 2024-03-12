/*
   
2. **Problem Solving with Arrays and Strings**

   - Given an array of integers, return indices of the two numbers such that they add up to a specific target.
   - Given a string, find the length of the longest substring without repeating characters.
   - Implement the 'strstr' function that finds the first occurrence of a substring in a string.
  
- Indices of Two Numbers
Problem: Given an array of integers, return indices of the two numbers such that they add up to a specific target.

Arrays to test:

Array: [2, 7, 11, 15], Target: 9 (Expected output: [0, 1] because 2 + 7 = 9)
Array: [3, 2, 4], Target: 6 (Expected output: [1, 2] because 2 + 4 = 6)
Array: [5, 8, 12, 7], Target: 19 (Expected output: [2, 3] because 12 + 7 = 19)


- Longest Substring Without Repeating Characters
Problem: Given a string, find the length of the longest substring without repeating characters.

Strings to test:

String: "abcabcbb" (Expected output: 3 for the substring "abc")
String: "bbbbb" (Expected output: 1 for any single character, since all are repeating)
String: "pwwkew" (Expected output: 3 for the substring "wke")


- Implement 'strstr'
Problem: Implement the 'strstr' function that finds the first occurrence of a substring in a string.

String and Substring pairs to test:

String: "hello", Substring: "ll" (Expected output: 2 because "ll" starts at index 2)
String: "aaaaa", Substring: "bba" (Expected output: -1 because "bba" is not found)
String: "abcdeabc", Substring: "de" (Expected output: 3 because "de" starts at index 3)



*/ 

class IndicesOfTwoNumbers {
    
    int target ;
    List<int> nums ;
    String expected ; 
    late List<int> indices ; 

    IndicesOfTwoNumbers(this.target, this.nums, this.expected) ;

    void findTargetIndices() {
      // assuming all positive numbers 
      
      List<int> lessThanTargetNum = nums.where((n) => n < target ).toList() ;

      if (lessThanTargetNum.isEmpty) {
          indices = [] ; 
          return ;
      }

      int i ; int j ; 
      for (i = 0 ; i < lessThanTargetNum.length - 1; i++) {
        for ( j = i + 1; j < lessThanTargetNum.length; j++ ){
          int res = lessThanTargetNum[i] + lessThanTargetNum[j]; 
          if (res == target ) {
            indices = [i, j] ; 
            return ; 
          } ; 
        } ;      
      } ;
    
    }

    void show_result() {
      print("These are the indices for ${indices} for target ${target} ") ;
      print(expected);
    } 

}

typedef CharVisitMap  = Map<String, bool> ;

class FindLongestNonRepeatParser {
  
    late CharVisitMap visitedMap ;
    String searchString ;
    String expected ; 

    int longestNonRepeat = 0 ; 
    String nonRepeatString  = ''; 

    CharVisitMap createNewVisitMap() {
      
      CharVisitMap visitMap = {} ; 
      for (int i = 97; i < 123 ; i++) {

        String char = String.fromCharCode(i); 
        visitMap[char] = false;
    
      }

      return visitMap ; 
    }

    FindLongestNonRepeatParser(this.searchString, this.expected) {
      visitedMap = createNewVisitMap() ;
    }

    void findLongestNonRepeatedString() {
      String currentString = '' ; 
      int strLength = 0 ;
      int pass = 0 ; 
      for (int i = 0 ; i < searchString.length ; i ++ ) {
        String char = searchString[i];

        if (visitedMap[char] == false) {
            visitedMap[char] = true ;
            currentString += char ;
            strLength++ ; 
        } else {
          visitedMap = createNewVisitMap();
          pass++; 
          
          if (strLength > longestNonRepeat) {
            nonRepeatString = currentString ; 
            longestNonRepeat = strLength ; 
          };

          strLength = 0 ; 
          currentString = '' ; 

          if (pass == searchString.length - 1) return ;
          i = pass ; 
        }

      }
    }

    void show_result() {
      print("""This is the longest non-repeat substring ${nonRepeatString} of length ${nonRepeatString.length} - ${longestNonRepeat}""");
      print(expected); 
    }

}

class FindSubstringParser {

    String searchString; 
    String subString ; 
    String expected ; 

    int firstSubIndex = -1;
    FindSubstringParser(this.searchString, this.subString, this.expected); 

    void findSubstringIndex() {
      for (int i = 0 ; i <= (searchString.length - subString.length ); i++) {
        
        for (int j = 0 ; j < subString.length; j++) {
          if (subString[j] != searchString[i + j]) {            
            break;
          }

          if (j == subString.length - 1) {
            firstSubIndex = i ; 
            return ;
          }

        }
      }
    }

    void show_result() {
      print("This is the index ${firstSubIndex} for the first subString ${subString} in string ${searchString}");
      print(expected); 
    }

}


void ps() {print("\n\n");}

int main() {

    IndicesOfTwoNumbers part1_a = IndicesOfTwoNumbers(
      9, 
      [2,7,11,15],
     "Array: [2, 7, 11, 15], Target: 9 (Expected output: [0, 1] because 2 + 7 = 9"
    );
    IndicesOfTwoNumbers part1_b = IndicesOfTwoNumbers(
      6, 
      [3, 2, 4],
      "Array: [3, 2, 4], Target: 6 (Expected output: [1, 2] because 2 + 4 = 6)"
    );

    IndicesOfTwoNumbers part1_c = IndicesOfTwoNumbers( 
      19,
      [5,8,12,7], 
      "Array: [5, 8, 12, 7], Target: 19 (Expected output: [2, 3] because 12 + 7 = 19)"
    );
    part1_a.findTargetIndices();
    part1_b.findTargetIndices();
    part1_c.findTargetIndices();

    part1_a.show_result();
    ps();
    part1_b.show_result();
    ps();
    part1_c.show_result() ;
    ps(); 

    FindLongestNonRepeatParser part2_a =  FindLongestNonRepeatParser(
      "abcabcbb", 
      'String: "abcabcbb" (Expected output: 3 for the substring "abc")'
    ) ; 
    part2_a.findLongestNonRepeatedString();
    part2_a.show_result();
    ps();

    FindLongestNonRepeatParser part2_b =  FindLongestNonRepeatParser(
      "bbbbb" , 
      'String: "bbbbb" (Expected output: 1 for any single character, since all are repeating)'
    ) ; 
    part2_b.findLongestNonRepeatedString();
    part2_b.show_result();
    ps();
    
    FindLongestNonRepeatParser part2_c =  FindLongestNonRepeatParser(
      "pwwkew", 
      'String: "pwwkew" (Expected output: 3 for the substring "wke")'
    ) ; 
    part2_c.findLongestNonRepeatedString();
    part2_c.show_result();
    ps();


    FindSubstringParser part3_a  = FindSubstringParser( 
      "hello",
      "ll",
      'String: "hello", Substring: "ll" (Expected output: 2 because "ll" starts at index 2)'
    );
    part3_a.findSubstringIndex();
    part3_a.show_result();
    ps();

    FindSubstringParser part3_b  = FindSubstringParser( 
      "aaaaa",
      "bba",
      'String: "aaaaa", Substring: "bba" (Expected output: -1 because "bba" is not found)'
    );
    part3_b.findSubstringIndex();
    part3_b.show_result();
    ps();

    FindSubstringParser part3_c  = FindSubstringParser( 
      "abcdeabc",
      "de",
      'String: "abcdeabc", Substring: "de" (Expected output: 3 because "de" starts at index 3)'
    );
    part3_c.findSubstringIndex();
    part3_c.show_result();
    ps();



    return 0 ; 

}


