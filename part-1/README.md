# CPSC 120

## Fitch Cheney's Five Card Trick

In this exercise, we shall write a program that will masquerade as a artificial intelligence. Imagine telling a friend or family member that in your introductory computer science class, you have learned how to write programs that can calculate what cards you have selected from a deck of cards. You may go on to explain that with a little more work, your computer program can predict what everyone was dealt in a poker game. For now, your program can predict the fifth card in a poker hand given the first four cards.

William Fitch Cheney, Jr. was a mathematics professor at Tufts University, University of Connecticut, and the University of Hartford in the middle third of the 20th century passing away in 1974. Other than being a professor, he was a published amateur magician. In the book Math Miracles by Wallace Lee, a trick was published that is credited to Fitch Cheney. This trick uses discrete math, which is very important to a computer science student, to create an astounding effect.

The trick is performed with two magicians. In our case, one of the magicians will be our computer program. The trick can be performed with any deck of playing cards. The deck can be a borrowed deck and can be shuffled as many times as one would like. The trick requires no preparation or gaffs. Five cards are randomly selected from the deck and given to the the human magician. The human magician then shows (inputs) four of the five cards to the computer magician. The computer magician reveals the unseen fifth card.

To get an idea of how a similar trick is performed, watch a performance of [Al Stanger's Miracle Poker Machine](https://youtu.be/Ef0zy6cXvkY) presented by [Andy Martin](https://www.martinsmagic.com/). There are many videos of the Five Card Trick presented by [two amateur magicians](https://youtu.be/8rfuV12dGjA) and [one magician with a computer](https://youtu.be/MRGTA9y72nA).

# Background
Let's first review some basic terminology. A deck of cards has four suits: clubs ♣️, diamonds ♦️, hearts ♥️, and spades ♣️. Each suit has 13 cards: Ace, 2, 3, 4, 5, 6, 7, 8, 9, 10, Jack, Queen, King. Let's abbreviate Ace as _A_, Jack as _J_, Queen as _Q_, and King as _K_. Let's assume that Ace is the lowest value card, with a value of 1, and King is the highest value card, with a value of 13. Let's abbreviate the suits as _C_ for clubs, _D_ for diamonds, _H_ for hearts, and _S_ for spades. Additionally, if there are two cards with the same value, then the suit will break the tie. The suits are valued in alphabetical order.

Here are some examples of abbreviations using the given schema:

* The 5 of diamonds is _5D_
* The Jack of hearts is _JH_
* The 2 of clubs is _2C_
* The 7 of clubs is less than the King of clubs, or _7C_ < _KC_
* The Ace of spades is greater than the Ace of diamonds, or _AS_ > _AD_

Typically, a deck of cards is ordered by suit and then by value. This means that all the clubs are together from Ace to King, all the diamonds are together from Ace to King, all the hearts are together from Ace to King, and all the spades are together from Ace to King. To facilitate the calculations in this trick, the sorting of the deck has to be changed. The trick requires that cards be ordered by value and then by suit. This means that the cards are ordered as _AC, AD, AH, AS, 1C, 1D, 1H, 1S,…, QC, QD, QH, QS, KC, KD, KH, KS_. (This detail should not be shared with the spectator.)

# Explanation

The trick is a self working card trick which uses a scheme to encode the hidden fifth card's suit and value in the way the other four other cards are presented.

The foundation of this trick is discrete math and Michael Kleber wrote a wonderful article about this trick in [The Mathematical Intelligencer 24, 9–11 (2002)](https://doi-org.lib-proxy.fullerton.edu/10.1007/BF03025305) which explains the math in great detail. (You can also [find this article](https://bfy.tw/QW56) through your favorite search engine.)

Starting with a deck of cards, five cards are selected. Let's imagine the following cards are selected:  or 3 of clubs, 7 of diamonds, 2 of clubs, 10 of spades, and the 3 of hearts.

The cards are handed to the human magician. The magician will first sort the cards into identical suits. Given the hand described above, the magician mentally organizes the cards into:

* clubs: _3C_, _2C_
* diamonds: _7D_
* hearts: _3H_
* spades: _10S_

We need to use a suit that has at least two cards. In this example, the only suit that has this is the clubs. One card must be the _base_ card and the other card will be the _secret_ card.

The rules for the base card are:

* Must be the same suit as the secret card

The rules for the secret card are:

* The secret card must be less than or equal to the (_base_ _card_ _value_ + 6) % 13
* The secret card is not revealed until the end

In our example, let's select the base card as _2C_ and the secret card as _3C_. This means that the secret card is only +1 away from the base.

The magician begins by presenting the base card to the computer. This tells the computer the suit and the base value to start from.

Next the magician must present the remaining three cards in a certain order to signal how much to add to the base card. Let's call this _secret steps_. This requires a little bit of subterfuge. Using the table below, order the cards such that they communicate what you want to add to the base card. In the given example, we wish to add one so the cards will be order low, middle, high which is _3H_, _7D_, _10S_.

| Order | Value to Add |
| :--- | :---: |
| low, middle, high | 1 |
| low, high, middle | 2 |
| middle, low, high | 3 |
| middle, high low | 4 |
| high, low, middle | 5 |
| high, middle, low | 6 |

The computer getting this input will do the math and print out the secret card, in this case _3C_ because _2C_ + 1 is _3C_.

Another example is how we can use modulo arithmetic to perform the trick. Let's imagine the following cards are selected:  or Jack of diamonds, 7 of diamonds, Ace of clubs, King of hearts, and the 5 of hearts. Let's select the base card as the King of hearts and the secret card as the 5 of hearts.

This means we need to tell the computer to add 5 to the King and that the secret card's suit is heart.

We tell the computer the first card is _KH_, and then order the cards high, low, middle to tell the computer to add 5 to the King. We enter _JD_, _AC_, _7D_ which means the _secret steps_ is +5. Remember to use the formula (_base card value_ + 5) % 13 which evaluates to 5. Since the base card is a heart, the computer responds with 5H.

## Tips

To facilitate calculations, imagine the deck as one continuous series of cards that are numbered from 1 to 52. Instead of ordering them by suit, order the cards by value. This means that the cards are ordered as _AC, AD, AH, AS, 1C, 1D, 1H, 1S,…, QC, QD, QH, QS, KC, KD, KH, KS_. This subtlety can be accomplished by first taking the cards value and then adding 0 for clubs, 1 for diamonds, 2, for hearts, and 3 for spades. In this fashion the cards _6C_, _6D_, _6H_, and _6S_ will have the values 6, 7, 8, 9. This facilitates looking up the _secret steps_.

Convert the cards to initially have values between 0 and 12 where Ace is 0 and King is 12. Then use the formula card_value * 4 + SuitOffset() to map the card into the range 1 through 52. The value card_value is the value of the card between 0 and 12, and SuiteOffset() returns 1 for clubs, 2 for diamonds, 3 for hearts, and 4 for spades.

When working with if-else-if-else conditions here are some tips to keep in mind:

* Always handle the exceptions first and leave the general case for the else statement
* Try to have one entry point and one exit for conditions and functions; use a variable such as `return_value` to hold on to the value you wish to return and then return the variable at the end of the function.
* Write comments in clear, plain english that explain to you what each case is supposed to do. This will help keep your code organized and help you fix any errors.

## Requirements

Write a program that reads in 4 cards using the two letter abbreviation codes from the command line using `argc` and `argv`.

Check to make sure you have the correct number of inputs on the command line before proceeding. (Your program must have a total of 5 arguments before it can perform the trick.)

Each command line argument, must be converted to a `std::string` type variable.

Use the [`at()` method](https://en.cppreference.com/w/cpp/string/basic_string/at) of the [`std::string` class](https://en.cppreference.com/w/cpp/string/basic_string) to access the value and suit of the inputted card. (Do not use the `[]` operators!)

When using the `at()` method it will return a `char` type. Convert the `char` type to a `string` type. For example:

```
string hello = "Hello World";
// The first letter is at position 0
string letter_H = string(1, hello.at(0));
// The second letter is at position 1
string letter_e = string(1, hello.at(1));
// The letter d
// Get the size of the string, subtract 1 which will give the location of the last letter
string last_letter = string(1, hello.at(hello.size() - 1));
```

When using `at()` you should wrap each usage with a try/catch just like the try/catch pattern learned from the previous lab to catch errors.

```
string hello = "Hello World";
string letter_e;

try {
  letter_e = string(1, hello.at(1));
}catch (const std::exception& e) {
  ErrorMessage();
  // exit will end the program abruptly and return 1 to the operating system.
  exit(1);
}
```

Use the [`exit()`](https://en.cppreference.com/w/cpp/utility/program/exit) function to exit from your program if an error occurs in a function. Remember to `#include <cstdlib>` to take advantage of the `exit()` function.

If you need to, use  [`std::stoi()`](https://en.cppreference.com/w/cpp/string/basic_string/stol) to convert a string to an integer. Use the try/catch pattern learned from the previous lab to catch errors.

Write a function which will convert a string which represents a card's value to an integer. Remember that a card can have the numerical value of 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13 yet the values are represented by strings "A", "1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K". Handle the exceptional cases "A", "J", "Q", and "K" by mapping those strings onto the integer values 1, 11, 12, and 13 and use `stoi()` for all the other cases. Always use `try` and `catch` with `stoi()` to catch errors. The functions prototype is `int CardValue(const string& string_value);`.

Write a function which will convert an integer value to a card's string value. The function prototype is `string IntCardValueToString(int value);`. The input is an integer such as 1 and it returns a string 'A'. If the value doesn't need to be converted to a letter, use the [`to_string()`](https://en.cppreference.com/w/cpp/string/basic_string/to_string) function to convert from an integer to a string.

Write a function which will calculate the secret card's value. The function prototype is `int SecretCardValue(int base_value, int steps);`. You may find that converting a cards value from a string to an integer is best done by writing many if and else-if statements.

Write a function that will return what value to add to the base card given the three other cards inputted. The function prototype is `int SecretSteps(const string& card_one, const string& card_two, const string& card_three);`. If two or more cards have the same value, use the card's suit to determine the order.

The function `SecretSteps()` has very complicated logic if we mix integer values with string suits. Instead, follow the advice given in the tip to imagine the cards ordered by value and then by suit. Write a function named `SuitOffset()` which maps a given card's suit to an offset.

* Clubs have a 1 offset
* Diamonds have a 2 offset
* Hearts have a 3 offset
* Spaders have a 4 offset

For example, _6C_, _6D_, _6H_, and _6S_ will have the values 6, 7, 8, 9 because _6C_ is 6 + 0, _6D_ is 6 + 1, _6H_ is 6 + 2, and _6S_ is 6 + 3. This way, comparing the three cards given to `SecretSteps()` is straightforward. The function prototype is `int SuitOffset(const string& suit);`. The function takes a suit as a parameter and returns the starting index of that suit.

Write a function `void ErrorMessage();` which prints out `"This program may only be used by a qualified technician.\n"` whenever an error is encountered. Exit with a return status of 1 when there is an error.

You may wish to write functions that retrive the suit or value of a given card represented by a string. These are short utility functions that make your program more readable.

* string Suit(const string& card);
* string Value(const string& card);

You shall use [cout](https://en.cppreference.com/w/cpp/io/cout) to print messages to the terminal.

The starting code defines a series of `TODO` comments which you can use to formulate your plan and develop your program.

Write your program progressively. Compile your program often and check that you're making progress. Make sure your program behaves the way you expect.

The output of your program must match the output given in the section Example Output below.

To compile your program, you use the `make` command. A Makefile is provided for this exercise.

The Makefile has the following targets:
  
* all: builds the project
* clean: removes object and dependency files
* spotless: removes everything the clean target removes and all binaries
* format: outputs a [`diff`](https://en.wikipedia.org/wiki/Diff) showing where your formatting differes from the [Google C++ style guide](https://google.github.io/styleguide/cppguide.html)
* tidy: output of the [linter](https://en.wikipedia.org/wiki/Lint_(software)) to give you tips on how to improve your code
* headercheck: check to make sure your files have the appropriate header

## Don't Forget

Please remember that:

- You need to put a header in every file.
- You need to follow the [Google C++ Style Guide](https://google.github.io/styleguide/cppguide.html).
- Remove the `TODO` comments.

## Testing Your Code

Computers only ever do exactly what they are told, exactly the way they are told it, and never anything else. Testing is an important process to writing a program. You need to test for the program to behave correctly and test that the program behaves incorrectly in a predictable way.

As programmers we have to remember that there are a lot of ways that we can write the wrong program and only one to a few ways to write the correct program. We have to be aware of [cognitive biases](https://en.wikipedia.org/wiki/List_of_cognitive_biases) that we may exercise that lead us to believe we have correctly completed our program. That belief may be incorrect and our software may have errors. [Errors in software](https://www.wired.com/2005/11/historys-worst-software-bugs/) may lead to loss of [life](https://www.nytimes.com/2019/03/14/business/boeing-737-software-update.html), [property](https://en.wikipedia.org/wiki/Mariner_1), [reputation](https://en.wikipedia.org/wiki/Pentium_FDIV_bug), or [all of the above](https://en.wikipedia.org/wiki/2009%E2%80%9311_Toyota_vehicle_recalls).

### Test strategy

Start simple, and work your way up. Good tests are specific, cover a broad range of fundamentally different possibilities, can identify issues quickly, easily, and directly, without need for much set up, and can almost be diagnosed by inspection if the code fails to execute the test correctly.

## Example Output

Please ensure your program's output is identical to the example below.

```
$ make
set -e; clang++ -MM -g -Wall -pipe -std=c++14  mind_reader.cc \
	| sed 's/\(mind_reader\)\.o[ :]*/\1.o mind_reader.d : /g' > mind_reader.d; \
	[ -s mind_reader.d ] || rm -f mind_reader.d
clang++ -g -Wall -pipe -std=c++14  -c mind_reader.cc
clang++ -g -Wall -pipe -std=c++14 -o mind_reader mind_reader.o 
$ ./mind_reader 
This program may only be used by a qualified technician.
$ ./mind_reader JC 6C KC 5D
The card is 2C.
$ ./mind_reader 6S QD JC KC
The card is 9S.
$ ./mind_reader 8D 8S AH 7S
The card is KD.
```

