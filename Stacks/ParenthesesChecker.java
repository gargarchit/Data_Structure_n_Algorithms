package Stacks;

import java.util.Stack;

public class ParenthesesChecker {
    public boolean check(String combination) {
        Stack<Character> stack = new Stack<>();
        for(char ch : combination.toCharArray()) {
            switch (ch) {
                case '(':
                case '[':
                case '{':
                    stack.push(ch);
                    break;
                case ')':
                case ']':
                case '}':
                    if(stack.isEmpty() || !isMatchingBracesType(stack.pop(), ch))
                        return false;
                    break;
                default:
                    System.out.println("Illegal combination out of character set (){}[] found: " + ch);
                    return false;
            }
        }

        return stack.isEmpty();
    }

    private boolean isMatchingBracesType(char open, char close) {
        switch (open) {
            case '(':
                return close == ')';
            case '{':
                return close == '}';
            case '[':
                return close == ']';
        }
        return false;
    }
}