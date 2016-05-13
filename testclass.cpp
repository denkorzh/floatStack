#include "myStack.h"
#include <stdio.h>

int main() {

    stack S;      //initialize stack
    
    /*                                  //showing push
    stackElement a = stackElement(101);
    S.push(a);
    S.stkPrint();
    printf("\n");
    */
    
    S.input_stack(); //input stack from keyboard
    printf("\n");
    
    S.stkPrint();    //printing stack
    printf("\n");
    
    /*           //showing pop
    printf("top element was ~ %f\n", S.pop().get());
    printf("\n"); 
    S.stkPrint();
    printf("\n");
    */
    
    /*           //showing length and top
    printf("length = %d\n", S.getlength());
    printf("top element is ~ %f\n", S.stkTop().get());
    */
    
    /*          //showing inverse
    S.inverse();
    S.stkPrint();
    printf("\n");
    */
    
    /*           //showing merging
    printf("now input second stack!\n");
    stack Q;
    Q.input_stack();
    Q.stkPrint();
    printf("\n");
    printf("now look at merged stacks!\n");
    Q.mergeToTop(S);
    Q.stkPrint();
    printf("\n");
    */
    
    /*             //showing deletion by index
    float index;
    printf("input index to search and delete: ");
    scanf("%f", &index);
    S.delete_by_index(index);
    S.stkPrint();
    printf("\n");
    */
    
    /*             //showing sorted
    S.sort();
    S.stkPrint();
    */
    
    getchar(); getchar();
    return 0;
}
