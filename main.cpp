#include <iostream>
#include <string>
#include <cctype> //to check if characters are whitespaces or digits
using namespace std;
class parser
{
    public:
    int parseExpression(const string & inp_exp, size_t & index)
    {
        //parse addition(+) and subtraction(-)
        int result=parseterm(inp_exp,index);
        while(index<inp_exp.length())
        {
            char op= inp_exp[index];
            if(op=='+' || op=='-')
            {
                index++;
                //move past opearator
            
                int term=parseterm(inp_exp, index);
                if(op=='+')
                {
                    //when the operator is +
                    result= result + term;
                }
                else
                {
                    //when the operator is -
                    result= result- term;
                }
            }
            else
            {
                //end while if no more + or - operators
                break;
            }
        }
       return result; 
    }


    int parseterm(const string & inp_exp, size_t & index)
    {
        //parse multiplication(*) and division(/)
        int result=parsefactor(inp_exp, index);
        while(index<inp_exp.length())
        {
            char op= inp_exp[index];
            if(op=='*' || op=='/')
            {
                index++;
            
                int term=parseterm(inp_exp, index);
                if(op=='*')
                {
                    //when the operator is *
                    result= result * term;
                }
                else
                {
                    //when the operator is *
                    result= result / term;
                }
            }
            else
            {
                //end while if no more * or / operators
                break;
            }
        }
       return result;

    }


    int parsefactor(const string & inp_exp, size_t &index)
    {
        //parse parantheses and numbers
        int result=0;

        //skip whitespaces
        while(index<inp_exp.length() && isspace(inp_exp[index]))
        {
            index++;
        }

        //handle parantheses
        if(inp_exp[index]=='(')
        {
            index++;
            result=parseExpression(inp_exp,index);
            index++;
        }
        else
        {
            while(index <inp_exp.length() && isdigit(inp_exp[index]))
            {
                result= result *10 +(inp_exp[index] - '0'); //char to integer
                index++;
            }
        }
        return result;
    }

};
int main()
{
    parser p;

    string expression;

    cout<<"Enter the arithmetic expression: ";

    getline(cin,expression);

    size_t index=0;

    int result= p.parseExpression(expression, index);

     //display result
    cout<<"\nResult: "<<result;
    return 0;
}