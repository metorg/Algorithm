package com.company;

class Solution {
    public static String solution(String s) {
        String answer = "";
        StringBuilder sb= new StringBuilder();

        sb.append(String.valueOf(s.charAt(0)).toUpperCase());

        char[] ans =s.toCharArray();

        for(int i=1;i<s.length();i++){
            if(ans[i-1]==' '){
                sb.append(String.valueOf(ans[i]).toUpperCase());
            }
            else sb.append(String.valueOf(ans[i]).toLowerCase());
        }

        return sb.toString();
    }
}
public class Main {

    public static void main(String[] args) {
	    String s= "Hello world";
        System.out.println(Solution.solution(s));
    }
}
