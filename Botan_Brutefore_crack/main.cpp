#include <iostream>
#include "Hashing.h"
#include "Cracking.h"
#include <string>
int main() {

    //Test lenght 2 to 12 SHA-256 estimate time
    //The Output Estimate time:
    //SHA-256 length 2 should be cracked: 0.014320s
    //SHA-256 length 3 should be cracked: 1.219556s
    //SHA-256 length 4 should be cracked: 58.889198s
    //SHA-256 length 5 should be cracked: 3798.150179s
    //SHA-256 length 6 should be cracked: 171338.774756s
    //SHA-256 length 7 should be cracked: 10727297.202087s
    //SHA-256 length 8 should be cracked: 589739704.719610s
    //SHA-256 length 9 should be cracked: 33025423464.298149s
    //SHA-256 length 10 should be cracked: 1995430849316.540771s
    //SHA-256 length 11 should be cracked: 90829451280119.750000s
    //SHA-256 length 12 should be cracked: 5835374317824626.000000s

    std::cout<<Estimate_time("ab",1,2,"SHA-256",1)<<"\n";
    std::cout<<Estimate_time("abc",1,3,"SHA-256",1)<<"\n";
    std::cout<<Estimate_time("abc!",1,4,"SHA-256",1)<<"\n";
    std::cout<<Estimate_time("abc!@",1,5,"SHA-256",1)<<"\n";
    std::cout<<Estimate_time("abc!@#",1,6,"SHA-256",1)<<"\n";
    std::cout<<Estimate_time("abc!@#1",1,7,"SHA-256",1)<<"\n";
    std::cout<<Estimate_time("abc!@#12",1,8,"SHA-256",1)<<"\n";
    std::cout<<Estimate_time("abc!@#123",1,9,"SHA-256",1)<<"\n";
    std::cout<<Estimate_time("abc!@#123d",1,10,"SHA-256",1)<<"\n";
    std::cout<<Estimate_time("abc!@#123de",1,11,"SHA-256",1)<<"\n";
    std::cout<<Estimate_time("abc!@#123def",1,12,"SHA-256",1)<<"\n";
    //Test lenght 2 to 12 SHA-256-I 1000 iterates estimate time
    //The Output Estimate time:
    //SHA-256 iterated 1000 length 2 should be cracked: 12.061538s
    //SHA-256 iterated 1000 length 3 should be cracked: 605.572414s
    //SHA-256 iterated 1000 length 4 should be cracked: 29801.503030s
    //SHA-256 iterated 1000 length 5 should be cracked: 2118199.138462s
    //SHA-256 iterated 1000 length 6 should be cracked: 118619151.753846s
    //SHA-256 iterated 1000 length 7 should be cracked: 7196228539.733334s
    //SHA-256 iterated 1000 length 8 should be cracked: 333507970944.882751s
    //SHA-256 iterated 1000 length 9 should be cracked: 18676446372913.433594s
    //SHA-256 iterated 1000 length 10 should be cracked: 1263772871233809.000000s
    //SHA-256 iterated 1000 length 11 should be cracked: 67940429557529576.000000s
    //SHA-256 iterated 1000 length 12 should be cracked: 3397021477876478464.000000s

    std::cout<<Estimate_time("ab",1,2,"SHA-256-I",1000)<<"\n";
    std::cout<<Estimate_time("abc",1,3,"SHA-256-I",1000)<<"\n";
    std::cout<<Estimate_time("abc!",1,4,"SHA-256-I",1000)<<"\n";
    std::cout<<Estimate_time("abc!@",1,5,"SHA-256-I",1000)<<"\n";
    std::cout<<Estimate_time("abc!@#",1,6,"SHA-256-I",1000)<<"\n";
    std::cout<<Estimate_time("abc!@#1",1,7,"SHA-256-I",1000)<<"\n";
    std::cout<<Estimate_time("abc!@#12",1,8,"SHA-256-I",1000)<<"\n";
    std::cout<<Estimate_time("abc!@#123",1,9,"SHA-256-I",1000)<<"\n";
    std::cout<<Estimate_time("abc!@#123d",1,10,"SHA-256-I",1000)<<"\n";
    std::cout<<Estimate_time("abc!@#123de",1,11,"SHA-256-I",1000)<<"\n";
    std::cout<<Estimate_time("abc!@#123def",1,12,"SHA-256-I",1000)<<"\n";
    //Test lenght 2 to 12 SHA-256-I 10000 iterates estimate time
    //The Output Estimate time:
    //SHA-256 iterated 10000 length 2 should be cracked: 107.397260s
    //SHA-256 iterated 10000 length 3 should be cracked: 5893.154362s
    //SHA-256 iterated 10000 length 4 should be cracked: 372518.787879s
    //SHA-256 iterated 10000 length 5 should be cracked: 19810495.539568s
    //SHA-256 iterated 10000 length 6 should be cracked: 1109387750.215827s
    //SHA-256 iterated 10000 length 7 should be cracked: 59554994811.586205s
    //SHA-256 iterated 10000 length 8 should be cracked: 3807768172205.354492s
    //SHA-256 iterated 10000 length 9 should be cracked: 197670417815507.125000s
    //SHA-256 iterated 10000 length 10 should be cracked: 11665595734465930.000000s
    //SHA-256 iterated 10000 length 11 should be cracked: 629078051458607104.000000s
    //SHA-256 iterated 10000 length 12 should be cracked: 33257552930259234816.000000s

    std::cout<<Estimate_time("ab",5,2,"SHA-256-I",10000)<<"\n";
    std::cout<<Estimate_time("abc",5,3,"SHA-256-I",10000)<<"\n";
    std::cout<<Estimate_time("abc!",5,4,"SHA-256-I",10000)<<"\n";
    std::cout<<Estimate_time("abc!@",5,5,"SHA-256-I",10000)<<"\n";
    std::cout<<Estimate_time("abc!@#",5,6,"SHA-256-I",10000)<<"\n";
    std::cout<<Estimate_time("abc!@#1",5,7,"SHA-256-I",10000)<<"\n";
    std::cout<<Estimate_time("abc!@#12",5,8,"SHA-256-I",10000)<<"\n";
    std::cout<<Estimate_time("abc!@#123",5,9,"SHA-256-I",10000)<<"\n";
    std::cout<<Estimate_time("abc!@#123d",5,10,"SHA-256-I",10000)<<"\n";
    std::cout<<Estimate_time("abc!@#123de",5,11,"SHA-256-I",10000)<<"\n";
    std::cout<<Estimate_time("abc!@#123def",5,12,"SHA-256-I",10000)<<"\n";
    //Test lenght 2 to 12 SHA-256-I 100000 iterates estimate time
    //The Output Estimate time:
    //SHA-256 iterated 100000 length 2 should be cracked: 1363.478261s
    //SHA-256 iterated 100000 length 3 should be cracked: 84975.483871s
    //SHA-256 iterated 100000 length 4 should be cracked: 3782498.461538s
    //SHA-256 iterated 100000 length 5 should be cracked: 199059678.072289s
    //SHA-256 iterated 100000 length 6 should be cracked: 12850408106.666668s
    //SHA-256 iterated 100000 length 7 should be cracked: 809575710720.000000s
    //SHA-256 iterated 100000 length 8 should be cracked: 36728093002790.890625s
    //SHA-256 iterated 100000 length 9 should be cracked: 1911589216992316.250000s
    //SHA-256 iterated 100000 length 10 should be cracked: 121322195638445680.000000s
    //SHA-256 iterated 100000 length 11 should be cracked: 7176805939175659520.000000s
    //SHA-256 iterated 100000 length 12 should be cracked: 407642577345177452544.000000s

    std::cout<<Estimate_time("ab",30,2,"SHA-256-I",100000)<<"\n";
    std::cout<<Estimate_time("abc",30,3,"SHA-256-I",100000)<<"\n";
    std::cout<<Estimate_time("abc!",30,4,"SHA-256-I",100000)<<"\n";
    std::cout<<Estimate_time("abc!@",30,5,"SHA-256-I",100000)<<"\n";
    std::cout<<Estimate_time("abc!@#",30,6,"SHA-256-I",100000)<<"\n";
    std::cout<<Estimate_time("abc!@#1",30,7,"SHA-256-I",100000)<<"\n";
    std::cout<<Estimate_time("abc!@#12",30,8,"SHA-256-I",100000)<<"\n";
    std::cout<<Estimate_time("abc!@#123",30,9,"SHA-256-I",100000)<<"\n";
    std::cout<<Estimate_time("abc!@#123d",30,10,"SHA-256-I",100000)<<"\n";
    std::cout<<Estimate_time("abc!@#123de",30,11,"SHA-256-I",100000)<<"\n";
    std::cout<<Estimate_time("abc!@#123def",30,12,"SHA-256-I",100000)<<"\n";
    //Test lenght 2 to 12 Bcrypt estimate time
    //The Output Estimate time:
    //Bcrypt length 2 should be cracked: 0.006523s
    //Bcrypt length 3 should be cracked: 0.797281s
    //Bcrypt length 4 should be cracked: 2565520.695652s
    //Bcrypt length 5 should be cracked: 142430631.724138s
    //Bcrypt length 6 should be cracked: 7710244864.000000s
    //Bcrypt length 7 should be cracked: 1918994277262.222412s
    //Bcrypt length 8 should be cracked: 103625690972160.000000s
    //Bcrypt length 9 should be cracked: 5803038694440960.000000s
    //Bcrypt length 10 should be cracked: 324970166888693760.000000s
    //Bcrypt length 11 should be cracked: 18872341543758217216.000000s
    //Bcrypt length 12 should be cracked: 1019106443362943631360.000000s

    std::cout<<Estimate_time("ab",30,2,"Bcrypt",1)<<"\n";
    std::cout<<Estimate_time("abc",30,3,"Bcrypt",1)<<"\n";
    std::cout<<Estimate_time("abc!",30,4,"Bcrypt",1)<<"\n";
    std::cout<<Estimate_time("abc!@",30,5,"Bcrypt",1)<<"\n";
    std::cout<<Estimate_time("abc!@#",30,6,"Bcrypt",1)<<"\n";
    std::cout<<Estimate_time("abc!@#1",30,7,"Bcrypt",1)<<"\n";
    std::cout<<Estimate_time("abc!@#12",30,8,"Bcrypt",1)<<"\n";
    std::cout<<Estimate_time("abc!@#123",30,9,"Bcrypt",1)<<"\n";
    std::cout<<Estimate_time("abc!@#123d",30,10,"Bcrypt",1)<<"\n";
    std::cout<<Estimate_time("abc!@#123de",30,11,"Bcrypt",1)<<"\n";
    std::cout<<Estimate_time("abc!@#123def",30,12,"Bcrypt",1)<<"\n";
    return 0;

}