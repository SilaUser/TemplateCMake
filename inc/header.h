class Test
{
    int a;
    double b;

  public:
    Test () : a{1}, b{2} {}

    int getA ();
    double getB ();

    void setA (int val);
    auto setB (double val) -> void;
};
