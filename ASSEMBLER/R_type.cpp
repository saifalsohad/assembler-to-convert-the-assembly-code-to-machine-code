#include "R_type.h"




R_type::R_type(){
}

R_type::R_type(vector<string> a){
    v=a;
}


// special function specifically written to deal with sll and slr
void R_type:: shift(){
    if (toInt(v[2])>1){
        errorMessage+="ERROR: shifting can not be done more than 1 times";
        return;
    }
    if (toInt(v[2])<0){
        errorMessage+="ERROR: shift amount can not be negative";
        return;
    }

    translated=toBinary(5,4)+" "+m[v[1]]+" "+m[v[1]]+" "+toBinary(toInt(v[2]),1)+" ";

    /*if (v[0]=="sll"){
        translated+=toBinary(0,6);
    }
    else {
        translated+=toBinary(2,6);

    }*/
}


void R_type::solve(){

     if (v.size()<3){
        errorMessage+="ERROR: Not enough data fields. ";
        return;
    }
    else if (v.size()>3){
        errorMessage+="ERROR: Too much data fields. ";
        return;
    }

    /*if (v[0]=="sll")
        return shift(); */

    int vecsize = v.size();

    /*for(int i=1;i<vecsize;i++){
       if (m.find(v[i])==m.end()){
            errorMessage+="ERROR: Register number "+v[i]+" is not valid";
            return;
       }
    }*/

    if (v[0]=="add"){
        for(int i=1;i<vecsize;i++){
           if (m.find(v[i])==m.end()){
                errorMessage+="ERROR: Register number "+v[i]+" is not valid";
                return;
           }
        }
        translated+=toBinary(0,4)+" "+m[v[1]]+" "+m[v[2]];
    }
    else if (v[0]=="sub"){
        for(int i=1;i<vecsize;i++){
           if (m.find(v[i])==m.end()){
                errorMessage+="ERROR: Register number "+v[i]+" is not valid";
                return;
           }
        }
        translated+=toBinary(2,4)+" "+m[v[1]]+" "+m[v[2]];
    }
    else if (v[0]=="sll"){
        for(int i=1;i<vecsize-1;i++){
           if (m.find(v[i])==m.end()){
                errorMessage+="ERROR: Register number "+v[i]+" is not valid";
                return;
           }
        }
        return shift();
    }


}
