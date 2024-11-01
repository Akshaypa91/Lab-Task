// Calculator
// Credit by Coep Student's

#include <stdio.h>
int main(){
  int x = 0,x1 = 0,x2=0,op1,op2;
  char opr1,opr2;
  while((x = scanf("%d",&op1)) != EOF){
  
  if(x == 0){
   printf("bad op1\n");
   break;
   }
   scanf(" %c",&opr1);
   if(opr1 == '>' || opr1 == '<'){
     x1 = scanf("%c",&opr2);
     if(x1 == 0) {
      printf("bad opr2\n");
      }
     if(opr1 == '>' && opr2 == '>'){
        scanf("%d",&op2);
        printf("%d\n",op1>>op2);
     }
     else if(opr1 == '<' && opr2 == '<'){
        scanf("%d",&op2);
        printf("%d\n",op1<<op2);
        }
   else {
   scanf("%d",&op2);
       printf("opr1 %c != opr2 %c\n",opr1,opr2);
       } 
   }
   else{ 
     x2 = scanf("%d",&op2);
        if(x2 == 0) {
          printf("bad op2\n");
          break;
          }
          
     switch(opr1){  
   
       
          
          case '+':
         printf("%d\n",op1 + op2);
           break;
           
         case '-' :
         printf("%d\n",op1 - op2);
            break;
                  
         case '%' :
         if(op2 != 0){
          printf("%d\n",op1 % op2);
         }else{
            printf("bad op2\n");
   } 
     break;
          case '/' :
          if(op2 != 0){
          printf("%d\n",op1 / op2);
         }else{
            printf("bad op2\n");
            }
              break;
              
            case '*' :
            printf("%d\n",op1 * op2);
              break;
               
             case '|' :
            printf("%d\n",op1 | op2);
            break;
              
            case '&' :
            printf("%d\n",op1 & op2);
            break;
            
            default :
            printf("bad opr1\n");
            break;
           
   }
   }
   }
   return 0;
}
