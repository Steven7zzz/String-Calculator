#include <iostream>
#include <string>
#include "./string_calculator.h"

using std::cout;
using std::endl;
using std::string;

unsigned int digit_to_decimal(char digit) {
    // TODO(student): implement
    if (digit < 48 || digit >57){
        throw std::invalid_argument("s to i");
    }
    int x = digit - 48;
    return x;
}

char decimal_to_digit(unsigned int decimal) {
    // TODO(student): implement
    if (decimal >9){
        throw std::invalid_argument("i to s");
    }

    char x = decimal + 48;
    return x;
}

string trim_leading_zeros(string num) {
    if (num.size() == 0){
        throw std::invalid_argument("none");
    }

    if (num.at(0) != '-'){
        while(num.at(0) == '0') {
            num.erase(0,1);
            if (num.size() == 0){
                num='0';
                return num;
            }
        }
        
    }

    else if (num.at(0) == '-'){
        num.erase(0,1);
        if (num.size() == 0){
            num='0';
            return num;
        }

        while(num.at(0) == '0') {
            num.erase(0,1);
            if (num.size() == 0){
                num='0';
            return num;
            }
        }
        string n = "-";
        n+=num;
        return n;
    }

    // TODO(student): implement
    return num;
}

string add(string a, string b) {
    // TODO(student): implement
    int carry = 0;
    int ans = 0;
    string out;
    
    if (a.at(0) != '-' && b.at(0) != '-'){
        if (a.size() > b.size()){
            while (b.size() != a.size()){
                b.insert(0,"0");
            }
        }
        else if (b.size() > a.size()){
            while (b.size() != a.size()){
                a.insert(0,"0");
            }
        }

        for (int i = b.size()-1; i >= 0; i-- ){
        int temp = digit_to_decimal(b[i]) + digit_to_decimal(a[i]) + carry;
        if (temp >= 10){
            carry = 1;
            ans = temp - 10;
        }
        else{
            carry = 0;
            ans = temp;
        }
        out += decimal_to_digit(ans);   
        }


        if (carry != 0){
            out += decimal_to_digit(carry);
        }

        string rout;
        for (int i = out.size() - 1; i >=0; i--){
            rout += out[i];
        }

        rout = trim_leading_zeros(rout);

        return rout;

    }


    else{
        if (a.size() > b.size()){
            while (b.size() != a.size()){
                b.insert(1,"0");
            }
        }
        else if (b.size() > a.size()){
            while (b.size() != a.size()){
                a.insert(1,"0");
            }
        }

        for (int i = b.size()-1; i >= 1; i-- ){
        int temp = digit_to_decimal(b[i]) + digit_to_decimal(a[i]) + carry;
        if (temp >= 10){
            carry = 1;
            ans = temp - 10;
        }
        else{
            carry = 0;
            ans = temp;
        }
        out += decimal_to_digit(ans);   
        }


        if (carry != 0){
            out += decimal_to_digit(carry);
        }

        string rout;
        for (int i = out.size() - 1; i >=0; i--){
            rout += out[i];
        }

        rout.insert(0,"-");

        rout = trim_leading_zeros(rout);

        return rout;
    }
                                                          

    
}

string multiply(string a, string b) {
    // TODO(student): implement
    int carry = 0;
    int ans = 0;
    int temp = 0;
    string tout;
    string rout;
    string out = "0";

    if (a.at(0) != '-' && b.at(0) != '-'){ // a+ b+

        if (a.size() > b.size() || a.size() == b.size()){
            
            for (int se = b.size() -1; se >= 0; se--){
                
                for (int f = a.size() -1; f >= 0; f--){
                    temp = digit_to_decimal(a[f]) * digit_to_decimal(b[se]);
                    ans = temp % 10 + carry;
                    if (ans >=10){
                        carry =1 +temp /10;
                        ans -= 10;
                    }
                    else{
                    carry = temp /10;
                    }
                    tout += decimal_to_digit(ans);
                }

                tout += decimal_to_digit(carry);

                for (int c = tout.size() - 1; c >=0; c--){
                    rout += tout[c];
                }

                int t = se;
                while (b.size()-1-t !=0){
                    rout.insert(rout.size(),"0");
                    t++;
                }

                out = add(out,rout);
                
                rout ="";
                tout ="";
                carry = 0;
                ans = 0;
                temp = 0;

            }

            return out;

        }
        else{

            for (int se = a.size() -1; se >= 0; se--){
                
                for (int f = b.size() -1; f >= 0; f--){
                    temp = digit_to_decimal(b[f]) * digit_to_decimal(a[se]);
                    ans = temp % 10 + carry;
                    if (ans >=10){
                        carry =1 +temp /10;
                        ans -= 10;
                    }
                    else{
                    carry = temp /10;
                    }
                    tout += decimal_to_digit(ans);
                }

                tout += decimal_to_digit(carry);

                for (int c = tout.size() - 1; c >=0; c--){
                    rout += tout[c];
                }

                int t = se;
                while (a.size()-1-t !=0){
                    rout.insert(rout.size(),"0");
                    t++;
                }

                out = add(out,rout);
                
                rout ="";
                tout ="";
                carry = 0;
                ans = 0;
                temp = 0;

            }

            return out;
        }
    }

    else if (a.at(0) != '-' && b.at(0) == '-'){ // a+ b-
        if (a.size() > b.size() || a.size() == b.size()){
            
            for (int se = b.size() -1; se >= 1; se--){
                
                for (int f = a.size() -1; f >= 0; f--){
                    temp = digit_to_decimal(a[f]) * digit_to_decimal(b[se]);
                    ans = temp % 10 + carry;
                    if (ans >=10){
                        carry =1 +temp /10;
                        ans -= 10;
                    }
                    else{
                    carry = temp /10;
                    }
                    tout += decimal_to_digit(ans);
                }

                tout += decimal_to_digit(carry);

                for (int c = tout.size() - 1; c >=0; c--){
                    rout += tout[c];
                }

                int t = se;
                while (b.size()-1-t !=0){
                    rout.insert(rout.size(),"0");
                    t++;
                }

                out = add(out,rout);
                
                rout ="";
                tout ="";
                carry = 0;
                ans = 0;
                temp = 0;

            }

            out.insert(0,"-");
            return out;

        }
        else{

            for (int se = a.size() -1; se >= 0; se--){
                
                for (int f = b.size() -1; f >= 1; f--){
                    temp = digit_to_decimal(b[f]) * digit_to_decimal(a[se]);
                    ans = temp % 10 + carry;
                    if (ans >=10){
                        carry =1 +temp /10;
                        ans -= 10;
                    }
                    else{
                    carry = temp /10;
                    }
                    tout += decimal_to_digit(ans);
                }

                tout += decimal_to_digit(carry);

                for (int c = tout.size() - 1; c >=0; c--){
                    rout += tout[c];
                }

                int t = se;
                while (a.size()-1-t !=0){
                    rout.insert(rout.size(),"0");
                    t++;
                }

                out = add(out,rout);
                
                rout ="";
                tout ="";
                carry = 0;
                ans = 0;
                temp = 0;

            }
            out.insert(0,"-");
            return out;
        }
    }




    else if (a.at(0) == '-' && b.at(0) != '-'){ // a- b+
        if (a.size() > b.size() || a.size() == b.size()){
            
            for (int se = b.size() -1; se >= 0; se--){
                
                for (int f = a.size() -1; f >= 1; f--){
                    temp = digit_to_decimal(a[f]) * digit_to_decimal(b[se]);
                    ans = temp % 10 + carry;
                    if (ans >=10){
                        carry =1 +temp /10;
                        ans -= 10;
                    }
                    else{
                    carry = temp /10;
                    }
                    tout += decimal_to_digit(ans);
                }

                tout += decimal_to_digit(carry);

                for (int c = tout.size() - 1; c >=0; c--){
                    rout += tout[c];
                }

                int t = se;
                while (b.size()-1-t !=0){
                    rout.insert(rout.size(),"0");
                    t++;
                }

                out = add(out,rout);
                
                rout ="";
                tout ="";
                carry = 0;
                ans = 0;
                temp = 0;

            }

            out.insert(0,"-");
            return out;

        }
        else{

            for (int se = a.size() -1; se >= 1; se--){
                
                for (int f = b.size() -1; f >= 0; f--){
                    temp = digit_to_decimal(b[f]) * digit_to_decimal(a[se]);
                    ans = temp % 10 + carry;
                    if (ans >=10){
                        carry =1 +temp /10;
                        ans -= 10;
                    }
                    else{
                    carry = temp /10;
                    }
                    tout += decimal_to_digit(ans);
                }

                tout += decimal_to_digit(carry);

                for (int c = tout.size() - 1; c >=0; c--){
                    rout += tout[c];
                }

                int t = se;
                while (a.size()-1-t !=0){
                    rout.insert(rout.size(),"0");
                    t++;
                }

                out = add(out,rout);
                
                rout ="";
                tout ="";
                carry = 0;
                ans = 0;
                temp = 0;

            }
            out.insert(0,"-");
            return out;
        }
    }



    else{ // a- b-
        if (a.size() > b.size() || a.size() == b.size()){
            
            for (int se = b.size() -1; se >= 1; se--){
                
                for (int f = a.size() -1; f >= 1; f--){
                    temp = digit_to_decimal(a[f]) * digit_to_decimal(b[se]);
                    ans = temp % 10 + carry;
                    if (ans >=10){
                        carry =1 +temp /10;
                        ans -= 10;
                    }
                    else{
                    carry = temp /10;
                    }
                    tout += decimal_to_digit(ans);
                }

                tout += decimal_to_digit(carry);

                for (int c = tout.size() - 1; c >=0; c--){
                    rout += tout[c];
                }

                int t = se;
                while (b.size()-1-t !=0){
                    rout.insert(rout.size(),"0");
                    t++;
                }

                out = add(out,rout);
                
                rout ="";
                tout ="";
                carry = 0;
                ans = 0;
                temp = 0;

            }

            return out;

        }
        else{

            for (int se = a.size() -1; se >= 1; se--){
                
                for (int f = b.size() -1; f >= 1; f--){
                    temp = digit_to_decimal(b[f]) * digit_to_decimal(a[se]);
                    ans = temp % 10 + carry;
                    if (ans >=10){
                        carry =1 +temp /10;
                        ans -= 10;
                    }
                    else{
                    carry = temp /10;
                    }
                    tout += decimal_to_digit(ans);
                }

                tout += decimal_to_digit(carry);

                for (int c = tout.size() - 1; c >=0; c--){
                    rout += tout[c];
                }

                int t = se;
                while (a.size()-1-t !=0){
                    rout.insert(rout.size(),"0");
                    t++;
                }

                out = add(out,rout);
                
                rout ="";
                tout ="";
                carry = 0;
                ans = 0;
                temp = 0;

            }

            return out;
        }
    }

}
