/*
 @Author
 Sudent Name: Selin Eylul Bilen
 Date: 22.10.2019
*/
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <fstream>

using namespace std;

struct node{
int size;
int quant;
node *next;
};

struct stock{
node *head;
void create();
void add_stock(int);
void sell(int);
void current_stock();
void clear();
};

void stock::create(){
    head = NULL;
}

void stock::add_stock(int value){
    node* new_node = new node;
    new_node->next = NULL;
    new_node->size = value;
    new_node->quant = 1;
    node* temp=head;
    node* tail;


  while(temp){
        if(temp->size == value){ //adding the quantities
            temp->quant ++;
      }
    temp = temp->next;
    }
    temp = head;
    if(head == NULL ||new_node->size < head->size){
      new_node->next = head;
      head = new_node;
    }

    while(temp && (new_node->size > temp->size)){

      tail = temp;
      temp = temp->next;

      if(temp && (new_node->size < temp->size)){
        new_node->next=temp;
        tail->next = new_node;
      }
      if(temp == NULL){
        tail->next = new_node;
      }
    }
  }
void stock::sell(int val){
    node* traverse;
    node* ptr;

    traverse = head;

    while(traverse!=NULL){

        if(traverse->size == val){

            if(traverse->quant>1){
                traverse->quant -= 1;
                break;
            }
            else if(traverse->quant ==1 ){
                if(traverse == head){
                    head = head->next;
                    delete traverse;
                    break;
                }
                else if(traverse->next == NULL){
                    ptr->next = NULL;
                    delete traverse;
                    break;
                }
                else{
                    ptr->next = traverse->next;
                    delete traverse;
                    break;
                }
            }
        }


        ptr = traverse;
        traverse = traverse->next;
    }
  if(traverse==NULL){
    cout<<"NO_STOCK"<<endl;
  }
}

void stock::current_stock(){
    node* temp = head;
    while (temp != NULL){
      cout << temp->size <<":"<<temp->quant<<endl;
      temp=temp->next;

    }
}

void stock::clear(){
    node *ptr;
    while (head != NULL){
        ptr = head;
        head = head->next;
        delete ptr;
    }
}

int main(){
    struct stock shoe_stock;
    shoe_stock.create();
    int input;
    ifstream ss;
    ss.open("input.txt");

    while(ss >> input){
        if(input > 0){
            shoe_stock.add_stock(input);
        }
        else if(input == 0){
            shoe_stock.current_stock();
        }
        else{
            shoe_stock.sell((input*(-1)));
        }
    }


    ss.close();
    shoe_stock.clear();
    return 0;
}
