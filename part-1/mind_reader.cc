
// TODO: Add a #include for the iostream, cstdlib, and string header files

using namespace std;

// TODO: Write a function that prints out an error message; the function returns
// void and has no parameters
void ErrorMessage() {}

// TODO: Write a function named CardValue; the function returns an int and takes
// a const string& as a parameter
int CardValue(const string& string_value) {}

// TODO: Write a function named IntCardValueToString; the function returns a
// string and takes an int as a parameter
string IntCardValueToString(int value) {}

// TODO: Write a function named SecretCardValue; it returns an int and takes two
// ints as parameters
int SecretCardValue(int base_value, int steps) {}

// TODO: Write a function named SuitMultiplier; the function returns an int and
// takes a const string& as a parameter.
int SuitOffset(const string& suit) {}

string Suit(const string& card) {}

string Value(const string& card) {}

// TODO: Write a function named SecretSteps; the function returns an int and
// takes three const string& as parameters.
int SecretSteps(const string& card_one, const string& card_two,
                const string& card_three) {}

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