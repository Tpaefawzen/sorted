The Sorted! Manual

Every Sorted! program consists of fourteen declarations. Every
declaration has a type and a series of objects of that type. For
example, the Number declaration (Type=number) has a series of objects
(in that particular case, roman-catholic cardinals). For every
declaration, there are three possible alternatives:

1. you can either declare no objects,
2. a single object,
3. or a series of objects.

A typical syntax element would be the following:

	This code does not use any objects.
	This code uses the object blablabla.
	This code uses the objects foo, bar, and blablabla.

As you can see, the statement syntax is a little bit different for
each of the three alternatives. When you use more than one object, you
typically will have a syntax element

	"This""code""uses""the"
	"objects" { OBJECT_DESCRIPTION","}"and"
	OBJECT_DESCRIPTION.

which means that',' is an indicator that there are more objects coming
your way. Note that there is a comma before the last"and". Keywords
are not-case-sensitive, but you are encouraged to write code vaguely
resembling english (or american) customs, even though you have nothing
to declare; or of course DEUTSCHER KOT because of course Sorted! is
bilingual. Because Sorted! is also environment-friendly, the code will
not allow you to do the same declaration more than once: each object
declaration must be unique.

# Cardinals

The first statement in every Sorted! program is a declaration of
cardinals. You can either declare no cardinals, or just a single
cardinal, or any number of cardinals (well, you cannot declare a
transfinite number of cardinals, but neither can the VAX assembler).
You must use either ordinary english cardinals or ordinary german
cardinals. Here are some examples.

	This code does not use any numbers.
	This code uses the number fivemilliontwentytwothousandeightynine.
	This code uses the numbers Eins, Zwei, and Drei.

You cannot use a single cardinal more than once. They get fed up
easily.

=> Identifiers (aka Ordinals)

Lets interrupt this program for a short talk about ordinals. When you
refer to an object in Sorted!, you must use ordinal numbers, somewhat
like in the following examples:

	The first number
	The twentyfifth logical operation
	The twohundredandfirst condition.

End of interruption.

# Going somewhere

The second statement in every Sorted! program is a declaration of
things you plan to visit. In Sorted!, you are free to decide not to go
anywhere in your program. In that case, choose any one of the
following statements:

	This code does never go anywhere.
	Dieses Programm geht nirgendwo hin.

Otherwise, you can decide in a single branch, or a series of branches,
in typical fashion. There are two types of gotos, unconditional and
conditional. Here is a basic example for unconditional jumps:

	This code always goes to the second label.
	Dieses Programm geht immer zum zweiten Sprungziel.

The target of an unconditional jump must always be a label. Here now
is a basic example for a conditional jump:

	This code always sometimes to the second label if the
	twentyfourth condition is true.
	Dieses Programm springt immer an das zweite Sprungziel wenn die
	vierundzwanzigste
	Bedingung wahr ist.

You will understand easily, that only conditions can be conditions. Of
course, you can combine jumps, across language-barriers. Here is a
nice example taken from itoa.s:

	This code sometimes goes to the second label if the first
	condition is true, sometimes goes to Das Zweite Sprungziel if the
	second condition is true, and sometimes goes to the second label
	if the third condition is true.

# Output

The third statement in every Sorted! describes the output you want to
generate. Here are some examples:

	This code cannot write.
	This code writes the first cell as a decimal integer.
	This code writes the first cell as a series of sanscrit numbers,
	and the cell indexed by the second cell as an insult.

Valid output formats are

- "a character",
- "a english cardinal",
- "a english ordinal",
- "a german cardinal",
- "a german ordinal",
- "a series of sanscrit numbers",
- "a series of basque numbers",
- "a series of Tagalog numbers",
- "a series of Classical Nahuatl numbers",
- "a series of Kwakiutl numbers",
- "a series of random numbers",
- "the german word APFELSTRUDEL.",
- "an english ordinal",
- "an english cardinal",
- "an insult".

Some of these will be familiar to anyone who ever was lucky enough to
be able to code in GODS OWN LANGUAGE, the VAX assembler; others are
used to dismiss the common prejudice that output must be meaningful or
in any way resemble input.

Note: Currently, due to a lack of motivation, only the first five
output formats are implemented for the interpreter, and only the first
output format is implemented for the compiler. This may restrict the
usefullness of other output formats.

# Input

The fourth statement in every Sorted! describes the input you want to
eat. Here are some examples:

	This code cannot read.
	This code reads the first number as a character.
	This code reads the first number as a character,
	and the cell indexed by the second cell as a character.

Currently, there is only one valid input format, namely,"a character".

# Declaring sums

The fifth statement in every Sorted! is a declaration of sums used by
this program. You will not be surprised when I tell you that you can
declare no sums, one sum, or any number of sums. Here are some
examples:

	This code does not use any sums.
	This code uses the sum of the first number and the second number.
	This code uses the sum of the first number and the second sum,
	and of the second number and the third number.

The last example shows you how to calculate sums with more than two
elements.

# Conditions

The sixth statement in every Sorted! is a declaration of conditions
used by this program. In Sorted!, two elements can be equal, or one
element can be less than the other. This is pretty much conformant
with most peoples experiences in life. Combinations such as"not equal"
or"higher than", prominent in more bloated programming languages, are
not really necessary and have been omitted for claritys' sake. In
combination with NAND, the powerful logical operation provided by
Sorted!, you should be able to express all of these, and then some.
You can choose to not use any conditions in your program by writing

	This code does not use any conditions.
	Dieses Programm benutzt keine Bedingungen.

Or, in typical fashion, you can decide to use any number of
conditions. Conditions are specified as"x is equal to y" ("x ist
gleich" y) or"x is less than y" (x ist weniger als y). Here is a
working example:

	This code uses the condition that the first number is equal
	to the eight number, the condition that the eight number is less
	than the first number, and the condition that the fifth number is
	less than the sixth number.

# Labels

The seventh statement in every Sorted! is a declaration of the number
of labels your program has. You must use all labels in your program,
or you are harming the environment.

	This code does not use any labels.
	This code uses twohundredmillion labels.

# Ordered Differences

The eigth statement in every Sorted! is a declaration of ordered
differences you want to use. Here is an example:

	This code does not use any ordered differences.
	This code uses the ordered difference between the second number
	and the fifth number, and the cell indexed by the twentieth
	number and the first number.

# Assignments

The ninth statement in every Sorted! describes the assignments you
want to make. The rest of this paragraph has been omitted on purpose.

	This code does not use any assignments.
	This code assigns the first cell to the second cell.
	This code assigns the first number to the first cell,
	and the second sum to the twentyfifth cell.

# Products

The tenth statement in every Sorted! is a declaration of products you
want to use. Here is an example:

	This code does not use any products.
	This code uses the products of the second number and
	the fifth number, and of the first number and the second number.

# Implementation

The eleventh statement in every Sorted! is a declaration of the main
program logic, as a series of implemented statements. Here is a
typical example, you'll get the idea:

	This code implements the first assignment, the second assignment,
	the third assignment, the fourth assignment, the third assignment,
	the fifth assignment, the third assignment, the first label, the
	second
	jump, the first output, the third assignment, the first jump, and
	the second label.

Its very easy to understand, isn't it?

# Ratios

The twelveth statement in every Sorted! is a declaration of ratios you
want to use. Here is an example:

	This code does not use any ratios.
	This code uses the ratios of the second number to the fifth number,
	and of the first number to the second number.

# Logical Operations

The thirteenth statement in every Sorted! is a declaration of logical
operations you want to use. Actually, it is more like the declaration
of the logical operations you CAN use; because Sorted! supports only
NAND. Here is an example:

	This code does not use any logical operations.
	This code uses the logical operation of not the second number
	and not the fifth number, and of not the first number and not
	the second number.

Refer to the Java2K documentation for examples on how to use NAND to
express more fancy operations such as OR or AND.

# Coolness

The fourteenth and probably most important statement in every Sorted!
is a declaration of coolness. Coolness can be specified in either of
the following ways:

	This code is cool.
	Cool.

Everything after the declaration of coolness can only be a downer and
is ignored. It is good programming practice to add extensive code
documentation after the declaration of coolness (because Sorted! has
not other means of encoding comments).
