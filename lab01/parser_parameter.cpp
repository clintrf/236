#include "parser_parameter.h"

Parameter::Parameter(Lexer* lex){
    //parameterId = NULL;
    //parameterString = NULL;
    //parameterExpression = NULL;
    // /parameterIdHead = NULL;
    // //parameterStringHead = NULL;
    // //parameterExpressionHead = NULL;
    
    // if((lex)->tokenList.back().getTokenType() == STRING){
    //     parameterStringHead = new String(lex);
    // }
    // else if ((lex)->tokenList.back().getTokenType() == ID){
    //     parameterIdHead = new Id(lex);
    // }
    // else{
    // //    parameterExpressionHead = new Expression(lex);
    // }
    
    // if((lex)->tokenList.back().getTokenType() == COMMA){
    //     (lex)->tokenList.pop_back();
        
    //     while((lex)->tokenList.back().getTokenType() == COMMA){
    //         if((lex)->tokenList.back().getTokenType() == STRING){
    //             parameterString = new String(lex);
    //         }
    //         else if ((lex)->tokenList.back().getTokenType() == ID){
    //             parameterId = new Id(lex);
    //         }
    //         else{
    // //            parameterExpression = new Expression(lex);
    //         }
    //     } 
    // }
}

Parameter* Parameter::createParameter(Lexer* lex){
    if((lex)->tokenList.back().getTokenType() == STRING){
//        Parameter* myPara = new String(lex);
 //       return myPara;
    }
    else if ((lex)->tokenList.back().getTokenType() == ID){
        //return (new Id(lex));
    }
    else{
    //    parameterExpressionHead = new Expression(lex);
    }
}

// string Parameter::toString(){
//     if(stringFlag == 1){
//         return "string";
//     }
//     else if (idFlag == 1){
//         return "id";
//     }
//     else{
//         return "exp";
//     }
// }

