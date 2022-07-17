    0  $accept : lines $end

    1  lines : lines expr '\n'
    2        | lines '\n'
    3        |

    4  expr : term
    5       | expr '+' term
    6       | expr '-' term

    7  term : factor
    8       | term '*' factor
    9       | term '/' factor

   10  factor : NUMBER
   11         | '(' expr ')'


state 0
	$accept : . lines $end
	lines : .  (3)

	.  reduce 3

	lines goto 1


state 1
	$accept : lines . $end  (0)
	lines : lines . expr '\n'
	lines : lines . '\n'

	$end  accept
	'\n'  shift 2
	'('  shift 3
	NUMBER  shift 4

	expr goto 5
	term goto 6
	factor goto 7


state 2
	lines : lines '\n' .  (2)

	.  reduce 2


state 3
	factor : '(' . expr ')'

	'('  shift 3
	NUMBER  shift 4

	expr goto 8
	term goto 6
	factor goto 7


state 4
	factor : NUMBER .  (10)

	.  reduce 10


state 5
	lines : lines expr . '\n'
	expr : expr . '+' term
	expr : expr . '-' term

	'\n'  shift 9
	'+'  shift 10
	'-'  shift 11


state 6
	expr : term .  (4)
	term : term . '*' factor
	term : term . '/' factor

	'*'  shift 12
	'/'  shift 13
	.  reduce 4


state 7
	term : factor .  (7)

	.  reduce 7


state 8
	expr : expr . '+' term
	expr : expr . '-' term
	factor : '(' expr . ')'

	')'  shift 14
	'+'  shift 10
	'-'  shift 11


state 9
	lines : lines expr '\n' .  (1)

	.  reduce 1


state 10
	expr : expr '+' . term

	'('  shift 3
	NUMBER  shift 4

	term goto 15
	factor goto 7


state 11
	expr : expr '-' . term

	'('  shift 3
	NUMBER  shift 4

	term goto 16
	factor goto 7


state 12
	term : term '*' . factor

	'('  shift 3
	NUMBER  shift 4

	factor goto 17


state 13
	term : term '/' . factor

	'('  shift 3
	NUMBER  shift 4

	factor goto 18


state 14
	factor : '(' expr ')' .  (11)

	.  reduce 11


state 15
	expr : expr '+' term .  (5)
	term : term . '*' factor
	term : term . '/' factor

	'*'  shift 12
	'/'  shift 13
	.  reduce 5


state 16
	expr : expr '-' term .  (6)
	term : term . '*' factor
	term : term . '/' factor

	'*'  shift 12
	'/'  shift 13
	.  reduce 6


state 17
	term : term '*' factor .  (8)

	.  reduce 8


state 18
	term : term '/' factor .  (9)

	.  reduce 9


10 tokens, 5 nonterminals
12 grammar rules, 19 states
