#define NMAX 100
#include<stdio.h>
#include<malloc.h>

class stackElement {
      private:
              float x; //element itself
              stackElement* prev; //pointer to previous element
              stackElement* next; //pointer to next element
              //float index; //index of element
      
      public:
             stackElement():
                            x(0),
                            prev(NULL),
                            next(NULL)
             {} //default constructor
             
             stackElement(const float& xx):
                          x(xx),
                          prev(NULL),
                          next(NULL)
             {} //constructor with known amount
             
             stackElement(const float& xx, stackElement* prvPtr, stackElement* nxtPtr):
                                x(xx),
                                prev(prvPtr),
                                next(nxtPtr)
             {} //constructor with known amount and pointers
             
             stackElement(const stackElement& sE):
                                x(sE.x),
                                prev(sE.prev),
                                next(sE.next)
             {} //constructor - copier
             
             
             ~stackElement() {} //destructor
             
             void copy(const stackElement& sE) { //make copy of existing element
                  this->x = sE.x;
                  this->prev = sE.prev;
                  this->next = sE.next;
                  return;    
             }
             
             float get() {
                   return x;      
             } //get the amount
             
             stackElement& nextEl() {
                          if (this->next != NULL)
                             return *(this->next);
                          else {
                               printf("There's no next stackElement!\n");
                               return *this;
                          }
             } //returns next element
             
             stackElement *nextElPtr() {
                          return this->next;
             } //returns pointer of next element
             
             stackElement& previousEl() {
                          if (this->prev != NULL)
                             return *(this->prev);
                          else {
                               printf("There's no previous stackElement!\n");
                               return *this;
                          }
             } //returns previous element
             
             stackElement *previousElPtr() {
                          return this->prev;
             } //returns pointer to previous element
             
             
             
             void linkToPreviousEl(stackElement& prevElement) {
                  this->prev = &prevElement;
                  prevElement.next = this;
                  return;
             } //links element to the given previous one
             
             void linkToNextEl(stackElement& nextElement) {
                  this->next = &nextElement;
                  nextElement.prev = this;
                  return;
             } //links element to the given next one
             
             void nullNextElPtr() {
                  this->next = NULL;
                  return;     
             } //make pointer to next NULL
             
             void nullPreviousElPtr() {
                  this->prev = NULL;
                  return;     
             } //make pointer to previous NULL
             
             void changeOrderWithPreviousEl() { //substitute element with the previous one in the chain
                  stackElement* prv;
                  if (this-> prev == NULL)
                     printf("there's no previous element!\n");
                  else {
                       prv = this->prev;
                       this->excludeFromChain();
                       this->insertLower(*prv);
                  }         
                        
                  return;     
             }
                 
             void changeOrderWithNextEl() { //substitute element with the next one in the chain
                       stackElement* sE;
                       if (this->next != NULL) {
                          sE = this->next;
                          sE->changeOrderWithPreviousEl();
                       } else 
                              printf("There's no next element!\n");
                       return;
             }
             
             void insertUpper(stackElement& prv) {  // insert element after given one in the chain
                  stackElement* nxt;
                  int flag = 1;
                  if (prv.next != NULL)
                     nxt = prv.next;
                  else 
                       flag = 0;
                  this->linkToPreviousEl(prv);
                  if (flag == 1)
                     this->linkToNextEl(*nxt);
                  return;                  
             }
             
             void insertLower(stackElement& nxt) {  // insert element before given one in the chain
                  stackElement* prv;
                  int flag = 1;
                  if (nxt.prev != NULL)
                     prv = nxt.prev;
                  else 
                       flag = 0;
                  this->linkToNextEl(nxt);
                  if (flag == 1)
                     this->linkToPreviousEl(*prv);
                  return;                  
             }
             
             void excludeFromChain() {  //exclude the element from the chain
                  stackElement *nxt;
                  stackElement *prv;
                  int flag_next = 1;
                  int flag_prev = 1;
                  if (this->next == NULL)
                     flag_next = 0;
                  else
                      nxt = this->next;
                  if (this->prev == NULL)
                     flag_prev = 0;
                  else
                      prv = this->prev;
                  if (flag_next * flag_prev == 1)
                     nxt->linkToPreviousEl(*prv);
                  else if (flag_next == 0)
                       prv->next = NULL;
                  else 
                       nxt->prev = NULL;
                  this->next = NULL;
                  this->prev = NULL;
                  return;
             }
};


class stack {
	private:
            stackElement* header;
            int length;
 
    public:   
	          stack():
                      header(new stackElement()),
                      length(0)
                      {}
	~stack(){}

void push(stackElement& sE) { 
     sE.insertLower(*(this->header));
     ++(this->length);
     return;
} 

void input_stack() {
	int initial_length;
	int i, n;
	float elem;
	initial_length = this -> length;
	printf("input number of elements to input: ");
  	scanf("%d", &n);
  	for(i = initial_length + 1; i <= initial_length + n; i++) {
    	printf("input element # %d: ", i);
    	scanf("%f", &elem);
    	this->push(*(new stackElement(elem)));
  	}
  	return;
}

void stkPrint() {
  int i;
  stackElement* sEP;
  i = this->length;
  sEP = this->header;
  if(i == 0) {
       printf("Stack is empty!\n");
       return;
  }
  do {
    i--;
    sEP = sEP->previousElPtr();
    printf("%f\n", sEP->get());
  } while(i>0);
  printf("End of stack!\n");
  return;
}

stackElement& pop() {
  if((this->length) > 0) {
    this->length--;
    
    stackElement &sE = this->header->previousEl();
    sE.excludeFromChain();
    
    return(sE);
  } else {
    printf("stack is empty!\n");
    return *(this->header);
  }
}

stackElement& stkTop() {
  if((this->length) > 0) {
    return( this->header->previousEl() );
  } else {
    printf("stack is empty!\n");
    return *(this->header);
  }
}

int getlength() {
 return(this->length);
}

void sort() {
     if (this->length < 2) 
        return;
     stack sorted;
     stackElement* current;
     sorted.header = this->header;
     sorted.length = 1;
     int flag, j;
     
     stackElement* sE;
     stackElement* prv = NULL;
     sE = this->header->previousElPtr()->previousElPtr();
     for (int i = this->length - 2; i >= 0; --i) {
         if (i > 0)
            prv = sE->previousElPtr();
         sE->excludeFromChain();
         current = sorted.header->previousElPtr();
         flag = 0;
         j = sorted.length;
         while (flag == 0 && j > 0) {
               --j;
               if (sE->get() >= current->get())
                  flag = 1;
               if (j > 0 && flag == 0)
                  current = current->previousElPtr();                  
         }
         if (flag == 1)
            sE->insertUpper(*current);
         else
             sE->insertLower(*current);
         ++(sorted.length);
         if (i > 0)
            sE = prv;
     }
     return;
}

void inverse() {  //invert stack
	int n = this->length;
	if (n < 2)
	   return;           //if length <2 - nothing to do
     stackElement *current;   //the last new-ordered element
	stackElement *beforeLast; //the element next to old-ordered last 
	stackElement *last;       //old-ordered last element
	
	current = (this->header);
	beforeLast =  (this->header);
	
	for (int i = 1; i < n; ++i)
	    beforeLast = beforeLast->previousElPtr();
     last = beforeLast->previousElPtr();
     for (int i = 1; i <= n; ++i) {
         last->excludeFromChain();
         last->insertLower(*current);
         current = last;
         last = beforeLast;
         beforeLast = beforeLast->nextElPtr();
     }
     return;
}


void mergeToTop(stack& paste) {
     int n_bottom = this->length;
     int n_top = paste.getlength();
     stackElement *sE;
     sE = paste.header;
     for (int i = 1; i <= n_top; i++)
         sE = sE->previousElPtr();
     this->header->linkToNextEl(*sE);
     this->header->excludeFromChain();
     this->header = paste.header;
     this->length = n_top + n_bottom;
     return;
}


void delete_by_index(float key) {
     int n = this->length;
     if (n == 0)
        return;
     stackElement* sE;
     stackElement* removed;
     sE = this->header->previousElPtr();
     while (n > 0) {
             --n;
             if (sE->get() == key) {
                           removed = sE;
                           if (n>0) 
                              sE = sE->previousElPtr();
                           removed->excludeFromChain();
                           --(this->length);
                           delete removed;
             } else
                   if (n>0)
                      sE = sE->previousElPtr();
                      
     }
	return;
}


};
