#include "I_type.h"


Itype::Itype(){
}

Itype::Itype(vector<string> a){
    v=a;
}


// deals with the lw and sw type instruction
void Itype::memAccess(){
    if (v.size()<3){
        errorMessage+="ERROR: Not enough data fields. ";
        return;
    }
    else if (v.size()>3){
        errorMessage+="ERROR: Too much data fields. ";
        return;
    }

    if (m.find(v[1])==m.end()){
        errorMessage="ERROR: Register number "+v[1]+" is not valid";
        return;
    }

    if (v[0]=="lw"){
        translated=toBinary(3,4);
    }
    else {
        translated=toBinary(4,4);
    }

    if (toInt(v[2])>3){
        errorMessage="ERROR: Offset value can not be more than 7";
        return;
    }
    if (toInt(v[2])<0){
        errorMessage="ERROR: Offset value can not be negative";
    }

    translated+=" "+m[v[1]]+" "+toBinary(toInt(v[2]),2);


}

// deals with beq and bne type instruction
void Itype::decision(){
    /*if (m.find(v[1])==m.end()){
        errorMessage="ERROR: Register number "+v[1]+" is not valid";
        return;
    }
    if (m.find(v[2])==m.end()){
        errorMessage="ERROR: Register number "+v[2]+" is not valid";
        return;
    }

    if (v[0]=="beq"){
        translated=toBinary(4,6);
    }
    else {
        translated=toBinary(5,6);
    }


    if (toInt(v[3])>32767){ if (v.size()<3){
        errorMessage+="ERROR: Not enough data fields. ";
        return;
    }
    else if (v.size()>3){
        errorMessage+="ERROR: Too much data fields. ";
        return;
    }
        errorMessage="ERROR: jump value can not be more than 32767";
        return;
    }

    if (toInt(v[3])<-32768){
        errorMessage="ERROR: jump value can not be less than -32768";
        return;
    }
    if (toInt(v[3])%4!=0){
        errorMessage="ERROR: Offset value must be divisible by 4";
        return;
    }


    translated+=" "+m[v[1]]+" "+m[v[2]]+" "+toBinary(toInt(v[3]),16);*/

    if(v[0]=="beq"){

                if (v.size()<3){
                    errorMessage+="ERROR: Not enough data fields. ";
                    return;
                }
                else if (v.size()>3){
                    errorMessage+="ERROR: Too much data fields. ";
                    return;
                }

                if (toInt(v[2])>3){
                    errorMessage="ERROR: jump value can not be more than 7";
                    return;
                }

                if (toInt(v[2])<0){
                    errorMessage="ERROR: jump value can not be less than 0";
                    return;
                }

                if (m.find(v[1])==m.end()){
                    errorMessage="ERROR: Register number "+v[1]+" is not valid";
                    return;
                }
            }
    else if(v[0]=="addi")
    {
        if (v.size()<3){
            errorMessage+="ERROR: Not enough data fields. ";
            return;
        }
        else if (v.size()>3){
            errorMessage+="ERROR: Too much data fields. ";
            return;
        }


            if (toInt(v[2])>3){
                errorMessage="ERROR: constant value can not be more than 7";
                return;
            }

            if (toInt(v[2])<0){
                errorMessage="ERROR: constant value can not be less than 0";
                return;
            }



        if (m.find(v[1])==m.end()){
            errorMessage="ERROR: Register number "+v[1]+" is not valid";
            return;
        }

    }
    else{
        if (v.size()<2){
            errorMessage+="ERROR: Not enough data fields. ";
            return;
        }
        else if (v.size()>2){
            errorMessage+="ERROR: Too much data fields. ";
            return;
        }

        if (toInt(v[1])>3){
            errorMessage="ERROR: jump value can not be more than 31";
            return;
        }

        if (toInt(v[1])<0){
            errorMessage="ERROR: jump value can not be less than 0";
            return;
        }
    }

    if (v[0]=="beq"){
        translated=toBinary(6,4);
        translated+=" "+m[v[1]]+" "+toBinary(toInt(v[2]),2);
    }
    else if(v[0]=="addi")
    {
         translated+=toBinary(1,4)+" "+m[v[1]]+" "+toBinary(toInt(v[2]),2);
    }
    else{
        translated=toBinary(7,4);
        translated+=" "+toBinary(toInt(v[1]),2);
    }
}






void Itype::solve(){

    if (v[0]=="lw" || v[0]=="sw"){
        return memAccess();
    }
    else if (v[0]=="beq" || v[0]=="bne"){
        return decision();
    }

}
