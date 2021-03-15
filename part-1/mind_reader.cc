
// TODO: Add a #include for the iostream, cstdlib, and string header files

using namespace std;

// TODO: Write a function that prints out an error message; the function returns
// void and has no parameters

/// Prints out an error message. Takes no arguments and returns nothing.
void ErrorMessage() {}

// TODO: Write a function named CardValue; the function returns an int and takes
// a const string& as a parameter

/// SimpleValue takes the \p face_value of a card as a string
/// and returns the simple_value of the card as an int
///
/// \param face_value A string representing the value of a card
/// (A, 2, ..., Q, K)
///
/// \returns The simple_value of the card as an int (0, 1, ..., 11, 12)
///
/// \remark This is in the inverse of SimpleValueToFaceValueString()
int SimpleValue(const string& face_value) {}

// TODO: Write a function named SimpleValueToFaceValueString; the function
// returns a string and takes an int as a parameter

/// SimpleValueToFaceValueString takes the \p simple_value of a card and returns
/// the face_value.
///
/// \param simple_value An int representing the value of a card as an int
/// (0, 1, ..., 11, 12)
///
/// \returns A string representing the value of a card (A, 2, ..., Q, K)
///
/// \remark This is the inverse of SimpleValue()
string SimpleValueToFaceValueString(int simple_value) {}

// TODO: Write a function named SecretCardValue; it returns an int and takes two
// ints as parameters

/// SecretCardValue returns the face_value of the secret card given the
/// \p simple_base_value and the \p steps.
///
/// Since the \p simple_base_value of the base card is an integer between 0
/// and 12, we can add \p steps to the \p simple_base_value to find the
/// simple value of the secret card. To wrap the count around
/// (from K to A), use modulo 13.
/// \f$\left(simple\_base\_value + steps \right) \% 13\f$
///
/// \param simple_base_value The simple_value of the base card, for
/// example 3C -> 2
/// \param steps The number of steps from the base simple_value to the secret
/// card value
///
/// \returns The simple_value of the secret card as an int (0, 1, ..., 11, 12)
int SecretCardValue(int simple_base_value, int steps) {}

// TODO: Write a function named SuitMultiplier; the function returns an int and
// takes a const string& as a parameter.

/// The offset of each suit; since the cards are ordered value first, suit
/// second, the function returns the rank of a given \p suit. Suits are
/// ranked in alphabetical order (C=1, D, H, S).
///
/// \param suit A single letter string representing the suit (C, D, H, S)
///
/// \returns An int between [1,4] representing the rank of the given suit
int SuitOffset(const string& suit) {}

// TODO: Write a function named Suit which returns the suit of a given card

/// Given a two to three letter string that represents a \p card, return
/// a single letter string that represents the card's suit
///
/// \param card A two to three letter string representing a card,
/// ex. AS, 4D, 10H, QS
///
/// \returns A single letter string which has the suit of the given card
string Suit(const string& card) {}

// TODO: Write a function named FaceFalue which returns the face value of
// a card

/// Given a two to three letter string that represents a \p card, return
/// a single letter string that represents the card's face_value
///
/// \param card A two to three letter string representing a card,
/// ex. AS, 4D, 10H, QS
///
/// \returns A single letter string that which has the face_value of the
/// card (A, 2, 3, 4, 5, 6, 7, 8, 9, 1, J, Q, K)
///
/// \remark Although a 10 has two letters, only the first letter is needed
/// since it is the only card that has a value that starts with 1.
string FaceValue(const string& card) {}

// TODO: Write a function named SecretSteps; the function returns an int and
// takes three const string& as parameters.

/// SecretSteps calculates the number of steps that are being signaled given
/// the order of the three cards.
///
/// There are four cards given on the command line. The first card is the base
/// card. The remaining three cards are \p card_one (argv[2]),
/// \p card_two (arg[3]), \p card_three (argv[4]).
///
/// Given the relative order of these cards, determine the steps to return
/// (labeled Value to Add in the table).
///
/// | Order | Value to Add |
/// | :--- | :---: |
/// | low, middle, high | 1 |
/// | low, high, middle | 2 |
/// | middle, low, high | 3 |
/// | middle, high low | 4 |
/// | high, low, middle | 5 |
/// | high, middle, low | 6 |
///
/// \param card_one The first card, expressed as a 2-3 letter string
/// \param card_two The second card, expressed as a 2-3 letter string
/// \param card_three The third card, expressed as a 2-3 letter string
///
/// \returns The number of steps to add (labeled Value Add in the table)
int SecretSteps(const string& card_one, const string& card_two,
                const string& card_three) {}

/// Entry point to the mind_reader program
/// \remark Must have at least 5 command line arguments. Each argument
/// represents a card.
int main(int argc, char const* argv[]) {
  if (argc < 5) {
    ErrorMessage();
    return 1;
  }
  string base_card = string(argv[1]);
  string card_one = string(argv[2]);
  string card_two = string(argv[3]);
  string card_three = string(argv[4]);

  return 0;
}