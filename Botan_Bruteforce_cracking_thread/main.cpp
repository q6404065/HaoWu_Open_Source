#include <iostream>
#include "Cracking_thread.h"
#include "Cracking.h"

int main() {
//    Test lenght 2 to 12 SHA-256 estimate time
//    The Output Estimate time:
//    SHA-256 length 2 should be cracked: 0.013000s
//    SHA-256 length 3 should be cracked: 0.639242s
//    SHA-256 length 4 should be cracked: 36.289290s
//    SHA-256 length 5 should be cracked: 2037.707571s
//    SHA-256 length 6 should be cracked: 114111.623987s
//    SHA-256 length 7 should be cracked: 6770211.810181s
//    SHA-256 length 8 should be cracked: 432326382.735852s
//    SHA-256 length 9 should be cracked: 20852252375.357853s
//    SHA-256 length 10 should be cracked: 1116164199873.700195s
//    SHA-256 length 11 should be cracked: 65052961301334.570312s
//    SHA-256 length 12 should be cracked: 3509802590941977.500000s
    std::cout << Estimate_time_thread("ab", 2, "SHA-256", 1) << "\n";
    std::cout << Estimate_time_thread("abc", 3, "SHA-256", 1) << "\n";
    std::cout << Estimate_time_thread("abc!", 4, "SHA-256", 1) << "\n";
    std::cout << Estimate_time_thread("abc!@", 5, "SHA-256", 1) << "\n";
    std::cout << Estimate_time_thread("abc!@#", 6, "SHA-256", 1) << "\n";
    std::cout << Estimate_time_thread("abc!@#1", 7, "SHA-256", 1) << "\n";
    std::cout << Estimate_time_thread("abc!@#12", 8, "SHA-256", 1) << "\n";
    std::cout << Estimate_time_thread("abc!@#123", 9, "SHA-256", 1) << "\n";
    std::cout << Estimate_time_thread("abc!@#123d", 10, "SHA-256", 1) << "\n";
    std::cout << Estimate_time_thread("abc!@#123de", 11, "SHA-256", 1) << "\n";
    std::cout << Estimate_time_thread("abc!@#123def", 12, "SHA-256", 1) << "\n";

//    Test lenght 2 to 12 SHA-256-I 10000 iterates estimate time
//    The Output Estimate time:
//    SHA-256 iterated 1000 length 2 should be cracked: 7.679280s
//    SHA-256 iterated 1000 length 3 should be cracked: 455.723520s
//    SHA-256 iterated 1000 length 4 should be cracked: 23836.359680s
//    SHA-256 iterated 1000 length 5 should be cracked: 1341720.289280s
//    SHA-256 iterated 1000 length 6 should be cracked: 75444745.994240s
//    SHA-256 iterated 1000 length 7 should be cracked: 4190363878.686720s
//    SHA-256 iterated 1000 length 8 should be cracked: 294262420463.943726s
//    SHA-256 iterated 1000 length 9 should be cracked: 16201116861763.421875s
//    SHA-256 iterated 1000 length 10 should be cracked: 736653206642187.375000s
//    SHA-256 iterated 1000 length 11 should be cracked: 40615638044860648.000000s
//    SHA-256 iterated 1000 length 12 should be cracked: 2313711328581669888.000000s
    std::cout << Estimate_time_thread("ab", 2, "SHA-256-I", 1000) << "\n";
    std::cout << Estimate_time_thread("abc", 3, "SHA-256-I", 1000) << "\n";
    std::cout << Estimate_time_thread("abc!", 4, "SHA-256-I", 1000) << "\n";
    std::cout << Estimate_time_thread("abc!@", 5, "SHA-256-I", 1000) << "\n";
    std::cout << Estimate_time_thread("abc!@#", 6, "SHA-256-I", 1000) << "\n";
    std::cout << Estimate_time_thread("abc!@#1", 7, "SHA-256-I", 1000) << "\n";
    std::cout << Estimate_time_thread("abc!@#12", 8, "SHA-256-I", 1000) << "\n";
    std::cout << Estimate_time_thread("abc!@#123", 9, "SHA-256-I", 1000) << "\n";
    std::cout << Estimate_time_thread("abc!@#123d", 10, "SHA-256-I", 1000) << "\n";
    std::cout << Estimate_time_thread("abc!@#123de", 11, "SHA-256-I", 1000) << "\n";
    std::cout << Estimate_time_thread("abc!@#123def", 12, "SHA-256-I", 1000) << "\n";

//    Test lenght 2 to 12 SHA-256-I 100000 iterates estimate time
//    The Output Estimate time:
//    SHA-256 iterated 10000 length 2 should be cracked: 76.361600s
//    SHA-256 iterated 10000 length 3 should be cracked: 4094.048000s
//    SHA-256 iterated 10000 length 4 should be cracked: 252008.960000s
//    SHA-256 iterated 10000 length 5 should be cracked: 14140038.348800s
//    SHA-256 iterated 10000 length 6 should be cracked: 744424141.619200s
//    SHA-256 iterated 10000 length 7 should be cracked: 44407926318.694405s
//    SHA-256 iterated 10000 length 8 should be cracked: 2370783099958.067383s
//    SHA-256 iterated 10000 length 9 should be cracked: 164380742751197.593750s
//    SHA-256 iterated 10000 length 10 should be cracked: 7438567120082200.000000s
//    SHA-256 iterated 10000 length 11 should be cracked: 398937709808118976.000000s
//    SHA-256 iterated 10000 length 12 should be cracked: 23149002860989263872.000000s
    std::cout << Estimate_time_thread("ab", 2, "SHA-256-I", 10000) << "\n";
    std::cout << Estimate_time_thread("abc", 3, "SHA-256-I", 10000) << "\n";
    std::cout << Estimate_time_thread("abc!", 4, "SHA-256-I", 10000) << "\n";
    std::cout << Estimate_time_thread("abc!@", 5, "SHA-256-I", 10000) << "\n";
    std::cout << Estimate_time_thread("abc!@#", 6, "SHA-256-I", 10000) << "\n";
    std::cout << Estimate_time_thread("abc!@#1", 7, "SHA-256-I", 10000) << "\n";
    std::cout << Estimate_time_thread("abc!@#12", 8, "SHA-256-I", 10000) << "\n";
    std::cout << Estimate_time_thread("abc!@#123", 9, "SHA-256-I", 10000) << "\n";
    std::cout << Estimate_time_thread("abc!@#123d", 10, "SHA-256-I", 10000) << "\n";
    std::cout << Estimate_time_thread("abc!@#123de", 11, "SHA-256-I", 10000) << "\n";
    std::cout << Estimate_time_thread("abc!@#123def", 12, "SHA-256-I", 10000) << "\n";

//    Test lenght 2 to 12 SHA-256-I 100000 iterates estimate time
//    The Output Estimate time:
//    SHA-256 iterated 100000 length 2 should be cracked: 835.744000s
//    SHA-256 iterated 100000 length 3 should be cracked: 49062.720000s
//    SHA-256 iterated 100000 length 4 should be cracked: 2758576.128000s
//    SHA-256 iterated 100000 length 5 should be cracked: 145599713.280000s
//    SHA-256 iterated 100000 length 6 should be cracked: 7949262454.784000s
//    SHA-256 iterated 100000 length 7 should be cracked: 445374584324.096008s
//    SHA-256 iterated 100000 length 8 should be cracked: 25617997903167.488281s
//    SHA-256 iterated 100000 length 9 should be cracked: 1469135962809303.250000s
//    SHA-256 iterated 100000 length 10 should be cracked: 80868826030251440.000000s
//    SHA-256 iterated 100000 length 11 should be cracked: 4256892539463962624.000000s
//    SHA-256 iterated 100000 length 12 should be cracked: 237315920444450799616.000000s
    std::cout << Estimate_time_thread("ab", 2, "SHA-256-I", 100000) << "\n";
    std::cout << Estimate_time_thread("abc", 3, "SHA-256-I", 100000) << "\n";
    std::cout << Estimate_time_thread("abc!", 4, "SHA-256-I", 100000) << "\n";
    std::cout << Estimate_time_thread("abc!@", 5, "SHA-256-I", 100000) << "\n";
    std::cout << Estimate_time_thread("abc!@#", 6, "SHA-256-I", 100000) << "\n";
    std::cout << Estimate_time_thread("abc!@#1", 7, "SHA-256-I", 100000) << "\n";
    std::cout << Estimate_time_thread("abc!@#12", 8, "SHA-256-I", 100000) << "\n";
    std::cout << Estimate_time_thread("abc!@#123", 9, "SHA-256-I", 100000) << "\n";
    std::cout << Estimate_time_thread("abc!@#123d", 10, "SHA-256-I", 100000) << "\n";
    std::cout << Estimate_time_thread("abc!@#123de", 11, "SHA-256-I", 100000) << "\n";
    std::cout << Estimate_time_thread("abc!@#123def", 12, "SHA-256-I", 100000) << "\n";

//    Test lenght 2 to 12 Bcrypt iterates estimate time
//    The Output Estimate time:
//    Bcrypt length 2 should be cracked: 933.744000s
//    Bcrypt length 3 should be cracked: 52355.520000s
//    Bcrypt length 4 should be cracked: 2938055.680000s
//    Bcrypt length 5 should be cracked: 167835508.736000s
//    Bcrypt length 6 should be cracked: 9379512877.056000s
//    Bcrypt length 7 should be cracked: 525900381683.711975s
//    Bcrypt length 8 should be cracked: 30429684153974.785156s
//    Bcrypt length 9 should be cracked: 2181362245240357.000000s
//    Bcrypt length 10 should be cracked: 123407420875981456.000000s
//    Bcrypt length 11 should be cracked: 6244150104021702656.000000s
//    Bcrypt length 12 should be cracked: 371192536887562797056.000000s
    std::cout << Estimate_time_thread("ab", 2, "Bcrypt", 1) << "\n";
    std::cout << Estimate_time_thread("abc", 3, "Bcrypt", 1) << "\n";
    std::cout << Estimate_time_thread("abc!", 4, "Bcrypt", 1) << "\n";
    std::cout << Estimate_time_thread("abc!@", 5, "Bcrypt", 1) << "\n";
    std::cout << Estimate_time_thread("abc!@#", 6, "Bcrypt", 1) << "\n";
    std::cout << Estimate_time_thread("abc!@#1", 7, "Bcrypt", 1) << "\n";
    std::cout << Estimate_time_thread("abc!@#12", 8, "Bcrypt", 1) << "\n";
    std::cout << Estimate_time_thread("abc!@#123", 9, "Bcrypt", 1) << "\n";
    std::cout << Estimate_time_thread("abc!@#123d", 10, "Bcrypt", 1) << "\n";
    std::cout << Estimate_time_thread("abc!@#123de", 11, "Bcrypt", 1) << "\n";
    std::cout << Estimate_time_thread("abc!@#123def", 12, "Bcrypt", 1) << "\n";
//    Correct password is: !@#$%^&*
    std::string password = "DDECC8CB389410AE750E4C5D506AA550DD7E159EB44DB1D26E0EE144E39C0274";
    Cracking_SHA_256_salt(password, "SALT", 8);
    std::string password_ = "$2a$04$zpxwaMwPXI9LgfICtaHho.zM97GXmGjRFqgYL.K/o7jlLYiIwPZTi";
//    Correct password is: fang
    Cracking_bcrypt(password_, 4);
    return 0;
}