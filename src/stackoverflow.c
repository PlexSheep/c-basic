int mem = 0x1337;

void foo() {
  int buf = 0;
  foo();
}

int main() {
  foo();
  return 0;
}
