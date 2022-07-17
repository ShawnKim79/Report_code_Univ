    0  $accept : lines $end

    1  lines : lines expr '\n'
    2        | lines '\n'
    3        |
    4        | error '\n'

    5  expr : expr '+' expr
    6       | expr '-' expr
    7       | expr '*' expr
    8       | expr '/' expr
    9       | '(' expr ')'
   10       | '-' expr
   11       | NUMBER


state 0
	$accept : . lines $end
	lines : .  (3)

	error  shift 1
	.  reduce 3

	lines goto 2


state 1
	lines : error . '\n'

	'\n'  shift 3


state 2
	$accept : lines . $end  (0)
	lines : lines . expr '\n'
	lines : lines . '\n'

	$end  accept
	'\n'  shift 4
	'('  shift 5
	'-'  shift 6
	NUMBER  shift 7

	expr goto 8


state 3
	lines : error '\n' .  (4)

	.  reduce 4


state 4
	lines : lines '\n' .  (2)

	.  reduce 2


state 5
	expr : '(' . expr ')'

	'('  shift 5
	'-'  shift 6
	NUMBER  shift 7

	expr goto 9


state 6
	expr : '-' . expr

	'('  shift 5
	'-'  shift 6
	NUMBER  shift 7

	expr goto 10


state 7
	expr : NUMBER .  (11)

	.  reduce 11


state 8
	lines : lines expr . '\n'
	expr : expr . '+' expr
	expr : expr . '-' expr
	expr : expr . '*' expr
	expr : expr . '/' expr

	'\n'  shift 11
	'*'  shift 12
	'+'  shift 13
	'-'  shift 14
	'/'  shift 15


state 9
	expr : expr . '+' expr
	expr : expr . '-' expr
	expr : expr . '*' expr
	expr : expr . '/' expr
	expr : '(' expr . ')'

	')'  shift 16
	'*'  shift 12
	'+'  shift 13
	'-'  shift 14
	'/'  shift 15


state 10
	expr : expr . '+' expr
	expr : expr . '-' expr
	expr : expr . '*' expr
	expr : expr . '/' expr
	expr : '-' expr .  (10)

	.  reduce 10


state 11
	lines : lines expr '\n' .  (1)

	.  reduce 1


state 12
	expr : expr '*' . expr

	'('  shift 5
	'-'  shift 6
	NUMBER  shift 7

	expr goto 17


state 13
	expr : expr '+' . expr

	'('  shift 5
	'-'  shift 6
	NUMBER  shift 7

	expr goto 18


state 14
	expr : expr '-' . expr

	'('  shift 5
	'-'  shift 6
	NUMBER  shift 7

	expr goto 19


state 15
	expr : expr '/' . expr

	'('  shift 5
	'-'  shift 6
	NUMBER  shift 7

	expr goto 20


state 16
	expr : '(' expr ')' .  (9)

	.  reduce 9


state 17
	expr : expr . '+' expr
	expr : expr . '-' expr
	expr : expr '*' expr .  (7)
	expr : expr . '*' expr
	expr : expr . '/' expr

	.  reduce 7


state 18
	expr : expr '+' expr .  (5)
	expr : expr . '+' expr
	expr : expr . '-' expr
	expr : expr . '*' expr
	expr : expr . '/' expr

	'*'  shift 12
	'/'  shift 15
	.  reduce 5


state 19
	expr : expr . '+' expr
	expr : expr '-' expr .  (6)
	expr : expr . '-' expr
	expr : expr . '*' expr
	expr : expr . '/' expr

	'*'  shift 12
	'/'  shift 15
	.  reduce 6


state 20
	expr : expr . '+' expr
	expr : expr . '-' expr
	expr : expr . '*' expr
	expr : expr '/' expr .  (8)
	expr : expr . '/' expr

	.  reduce 8


11 tokens, 3 nonterminals
12 grammar rules, 21 states
