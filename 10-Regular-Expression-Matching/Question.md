# 10. Regular Expression Matching

[Original Page](https://leetcode.com/problems/regular-expression-matching/)

Implement regular expression matching with support for `'.'` and `'*'`.

<pre>'.' Matches any single character.
'*' Matches zero or more of the preceding element.

The matching should cover the **entire** input string (not partial).

The function prototype should be:
bool isMatch(const char *s, const char *p)

Some examples:
isMatch("aa","a") → false
isMatch("aa","aa") → true
isMatch("aaa","aa") → false
isMatch("aa", "a*") → true
isMatch("aa", ".*") → true
isMatch("ab", ".*") → true
isMatch("aab", "c*a*b") → true
</pre>

<div>

[Subscribe](/subscribe/) to see which companies asked this question

</div>

<div>

<div id="tags" class="btn btn-xs btn-warning">Show Tags</div>

<span class="hidebutton" style="display: none;">[Dynamic Programming](/tag/dynamic-programming/) [Backtracking](/tag/backtracking/) [String](/tag/string/)</span></div>

<div>

<div id="similar" class="btn btn-xs btn-warning">Show Similar Problems</div>

<span class="hidebutton">[(H) Wildcard Matching](/problems/wildcard-matching/)</span></div>