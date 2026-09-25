int add(int a, int b);
int add(int a, int b, int c);
std::string add(std::string a, std::string b);
std::string add(char a, char b);
float add(float a, float b) = delete; // does not allow float matches
void echo(std::string phrase = "echo");
void repeat(std::string phrase, int number = 1);
