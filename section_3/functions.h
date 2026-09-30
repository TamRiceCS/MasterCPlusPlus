int add(int a, int b);
int add(int a, int b, int c);
std::string add(std::string a, std::string b);
std::string add(char a, char b);
float add(float a, float b) = delete; // does not allow float matches
// default values must be on the right, prefer providing them in header can't be redeclared
void echo(std::string phrase = "echo");
void repeat(std::string phrase, int number = 1);
// multiple default values are allowed to exist
int multiply(int a = 1, int b = 1, int c = 1);

// forward declare the whole function in header, only way to do it.
template <typename T> // will only be associated w/ the function below it
void report(T elem)
{
    std::cout << "Handed the template fucntion: " << typeid(elem).name() << std::endl;
}

template <>
void report(float elem) = delete; // don't allow float

template <typename T, typename U> // will only be associated w/ the function below it
void report(T elem1, U elem2)
{
    std::cout << "Handed the template fucntion: " << typeid(elem1).name() << std::endl;
    std::cout << "Also handed the template function: " << typeid(elem2).name() << std::endl;
}

template <char l> // declare a non-type template parameter of type int named N
void yolo()
{
    std::cout << l << '\n'; // use value of N here
}