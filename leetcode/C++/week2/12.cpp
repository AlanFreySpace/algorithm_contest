class Solution {
public:
    string intToRoman(int num) {//模拟题
        int values[]={
            1000,
            900,500,400,100,
            90,50,40,10,
            9,5,4,1
        };
        string str[]={
            "M",
            "CM","D","CD","C",
            "XC","L","XL","X",
            "IX","V","IV","I"
        };
        string res;
        for(int i=0;i<13;i++){
            while(num>=values[i]){
                num-=values[i];
                res+=str[i];
            }
        }
        return res;
    }
};
