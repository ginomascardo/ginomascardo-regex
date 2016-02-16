package cs345.regex;

import java.util.ArrayList;
import java.util.List;

public class RegexParser {
	protected final char[] pattern;	// the regex pattern to parse
	protected int p = 0;	 		// pattern[p] is next char to match
	protected final int n;
	protected final List<String> errors = new ArrayList<>();

	public RegexParser(String pattern) {
		this.pattern = pattern.toCharArray();
		n = this.pattern.length;
	}

	public List<String> getErrors() {
		return errors;
	}

	public NFA parse() {
		NFA nfa = regex();
		if ( p<n ) {
			error("unrecognized input");
			return NFA.error();
		}
		return nfa;
	}

	// P a r s e  m e t h o d s

	/** Parse regex : sequence ('|' sequence)* ; */
	public NFA regex() {
		// TODO:
	}

	/** Parse sequence : closure sequence | ; */
	public NFA sequence() {
		// TODO:
	}

	/** Parse closure : element '*' | element ; */
	public NFA closure() {
                // TODO:
	}

	/** Parse element : letter | '(' regex ')' ; */
	public NFA element() {
                // TODO:
	}

	// S u p p o r t

	public void match(char c) {
                // TODO:
	}

	public void consume() {
		p++;
	}

	public void error(String msg) {
		StringBuilder buf = new StringBuilder();
		buf.append(msg+" in "+new String(pattern));
		buf.append("\n");
		int spaces = p+msg.length()+" in ".length();
		for (int i=0; i<=spaces; i++) buf.append(" ");
		buf.append("^");
		errors.add(buf.toString());
	}
}
