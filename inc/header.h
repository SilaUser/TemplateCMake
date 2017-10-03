int add (int a, int b);

class TestClass
{
    int a;
    double b;

  public:
    TestClass () : a{1}, b{2} {}

    int getA ();
    double getB ();

    void setA (int val);
    auto setB (double val) -> void;
};
