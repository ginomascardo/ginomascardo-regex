package cs345.regex;

/** Represents a regular expression of the following form (ANTLR notation):
 *
 *  regex    : sequence ('|' sequence)* ;
 *  sequence : closure sequence | ; // same as closure* but easier to build NFA
 *  closure  : element '*' | element ;
 *  element  : letter | '(' regex ')' ;
 *
 *  To learn all about regex, see Russ Cox's amazing document:
 *  https://swtch.com/~rsc/regexp/regexp1.html
 */
public class Regex {
    protected String pattern;

    public Regex(String pattern) {
        this.pattern = pattern;
    }

    /** Parse the regex pattern and return an NFA that matches strings
     *  in the language described by the pattern.
     *
     *  See http://algs4.cs.princeton.edu/lectures/54RegularExpressions.pdf
     *      https://swtch.com/~rsc/regexp/regexp1.html
     *      http://www.cs.may.ie/staff/jpower/Courses/Previous/parsing/node5.html
     *
     *  Here are the pattern constructs to NFA conversions (x,y are themselves
     *  regex patterns and o implies we construct a new state):
     *
     *  Empty string        o--->o
     *
     *  Letter a            o-a->o
     *
     *  xy                  o->[x]->[y]             (x.stop = y.start)
     *
     *  x | y               o->[x]->o
     *                      |       ^
     *                      |->[y]--|
     *
     *                      |------|
     *                      v      |
     *  x*                  o->[x]-|->o
     *                      |         ^
     *                      |---------|
     */
    protected NFA compile() {
        RegexParser parser = new RegexParser(pattern);
        return parser.parse();
    }

    public boolean matches(String input) {
        NFA nfa = compile();
        nfa.stop.accept(1); // mark final state as accept state for alt 1
        int alt = simulate(nfa.start, input.toCharArray(), 0);
        return alt==1;
    }

    public int simulate(NFA.State p, char[] input, int i) {
        /* TODO:
        if accept state:
            if still have input left over, return NFA.FAIL
            return p.accept

        for each edge e of p:
            if epsilon edge:
                simulate e
                if that succeeds, return success
            else if we have more input and e.label is current input symbol:
                simulate e
                if that succeeds, return success
        return NFA.FAIL
        */
    }
}
