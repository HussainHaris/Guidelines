#include <iostream>

using std::cout;
using std::endl;
using std::string;

string generate_message() {
  return "Hello world!";

}
int main() {
  cout << generate_message() << endl;
  return 0;
}

