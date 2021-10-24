//
// Created by 柴长林 on 2021/10/22.
//
class Base {
 public:
  void pub_mem() {}

 protected:
  int prot_mem;

 private:
  char priv_mem;
};
struct Pub_Derv : public Base {
  int f() { return prot_mem; }
};
struct Priv_Derv : private Base {
  int f1() const { return prot_mem; }
};
struct Prot_Derv : protected Base {
  int f2() const { return prot_mem; }
};
struct Derived_from_Public : public Pub_Derv {
  int use_base() { return prot_mem; }
};
struct Derived_from_Private : public Priv_Derv {
  // error: Base::prot_mem is private in Priv_Derv
  // int use_base() { return prot_mem; }
};
struct Derived_from_Protected : public Prot_Derv {
  int use_base() { return prot_mem; }
};

int main() {
  Pub_Derv d1;
  Priv_Derv d2;
  Prot_Derv d3;
  Derived_from_Public dd1;
  Derived_from_Private dd2;
  Derived_from_Protected dd3;

  Base *p = &d1;  // legal
  p = &d2;        // illegal, user may use the derived-to-base conversion
  p = &d3;        // illegal
  p = &dd1;       // legal
  p = &dd2;       // illegal
  p = &dd3;       // illegal
}