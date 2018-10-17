#include "PlayList.h"
#include "LinkedSet.h"
#include "Node.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;
//Default Constructor
    
PlayList::PlayList() {
    
    tail_ptr_ = nullptr;
    
}
//Parameterized Constructor
PlayList::PlayList(const Song& a_song) {
    
    add(a_song); 
}
//Loop Playlist
void PlayList::loop() {
    tail_ptr_->setNext(head_ptr_);
    
}
void PlayList::unloop() {
 
    clear();
}
// Destructor
    
PlayList::~PlayList() {
    
    unloop();
    clear();
}
//Display PlayList
void PlayList::displayPlayList() {
    
  std::vector<Song> vec_list = toVector();
    
  for(unsigned int i = 0; i < getCurrentSize(); i++) {
      
    std::cout << "* Title: " << vec_list[i].getTitle() << " * Author: " << vec_list[i].getAuthor() << " * Album: " << vec_list[i].getAlbum() << " *" << std::endl;
      
  }
    
  std::cout << "End of playlist" << std::endl;
    
}
//Transverses the chain and returns a pointer to the last node
    
//Add Override
bool PlayList::add(const Song& new_entry) {
    
    if(!contains(new_entry)) {
        
        //Add to the end of chain
        
        //(head_ptr_ is null if chain is empty)
        
        Node<Song>* next_node_ptr = new Node<Song>();
        
        next_node_ptr->setItem(new_entry);
        
        // New node points to chain
        
        next_node_ptr->setNext(head_ptr_);  
        
        head_ptr_ = next_node_ptr;
        
        // New node is now first node
        
       item_count_++;
    
       return true;
    
    } else
        return false;
    
}  // end add
//Remove Override
 
bool PlayList::remove(const Song& a_song) {
   Node<Song>* previous_ptr = nullptr;//create a previous pointer
    
   Node<Song>* entry_node_ptr_ = getPointerTo(a_song, previous_ptr);
    
   bool can_remove_item = !isEmpty() && (entry_node_ptr_ != nullptr);
    
   if (entry_node_ptr_ == head_ptr_) {
           
       // create a temp pointer
       
       Node<Song>* temp_ptr_;
       //set head pointer to temp pointer
       temp_ptr_ = head_ptr_;
       //set head pointer to headpoint->getNext()
       head_ptr_ = head_ptr_->getNext();
           
       //temp pointer = nullptr
       
       temp_ptr_ = nullptr;
       //delete temp pointer
       
       delete temp_ptr_;
       
       item_count_--;
       
       return true;
       
   } else {
       
       if (can_remove_item) {
           
           previous_ptr->setNext(entry_node_ptr_->getNext());
           
           entry_node_ptr_ = nullptr;
           
           entry_node_ptr_->getNext();
           
           delete entry_node_ptr_;
           
           item_count_--;
           
       }                     
  
	return can_remove_item;
   }// end remove
}
Node<Song>* PlayList::getPointerTo(const Song& target, Node<Song>*& previous_ptr) const {
    
    bool found = false;
   
    Node<Song>* cur_ptr_ = head_ptr_;
    
    Node<Song>* pre_ptr_ = head_ptr_;
    
    while (cur_ptr_ != nullptr) {
        
      if (target == cur_ptr_->getItem())
          
         found = true;
        
      else
         
          pre_ptr_ = cur_ptr_;
        
          cur_ptr_ = cur_ptr_->getNext();
   
    } // end while
    
    previous_ptr = pre_ptr_;
    
    return cur_ptr_;
} // end getPointerTo
Node<Song>* PlayList::getPointerToLastNode() const { 
    
    Node<Song>* pre_ptr_ = head_ptr_;
    
    if (head_ptr_ == nullptr) {
        
        pre_ptr_ = nullptr;
      
    } else {
        
        while (pre_ptr_->getNext() != nullptr)
            
            pre_ptr_ = pre_ptr_->getNext();
            
        }
        
        return pre_ptr_;
    
}