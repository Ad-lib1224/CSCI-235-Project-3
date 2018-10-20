#include "PlayList.h"
#include "LinkedSet.h"
#include "Node.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;
//Default Constructor
    
PlayList::PlayList() {
    
    head_ptr_ = nullptr;
    tail_ptr_ = nullptr;
    item_count_ = 0;
    
}
//Parameterized Constructor
PlayList::PlayList(const Song& a_song) {
    
    add(a_song); 
}

// Destructor
    
PlayList::~PlayList() {
    
    unloop();
    
}

//Add Override
//adds a new song to the end of the playlist if it isn't included already
bool PlayList::add(const Song &new_song) {
  // checks if song is already in playlist using contains from linked set
  // false if song is already in playlist
    
    if (contains(new_song)) {

      return false;
      
  } else {
    
    Node<Song> *new_node_ptr =
        
        new Node<Song>;              // allocates memory for a new node
    
        new_node_ptr->setItem(new_song); // puts the new song in it
    
        new_node_ptr->setNext(nullptr);  // marks node as the end of the chain
    // case if the playlist is empty, added item is the first and last
        if (item_count_ == 0) {
        
            head_ptr_ = new_node_ptr;
        
            tail_ptr_ = new_node_ptr;
    
    } else {
      // if the playlist is not empty, point the last item to it, then make it the tail pointer
      
        tail_ptr_->setNext(new_node_ptr);
        
        tail_ptr_ = tail_ptr_->getNext();
    }
    
        item_count_++;
    
        return true;

    }
    
}

//Remove Override

bool PlayList::remove(const Song& a_song) {
    
   Node<Song>* previous_ptr_ = nullptr;//create a previous pointer
    
   Node<Song>* temp_ptr_ = getPointerTo(a_song, previous_ptr_);
    
   if (temp_ptr_ == nullptr) {
       
       return 0;
       
   } else {
       
       if(head_ptr_ == temp_ptr_) {
           
           head_ptr_ = temp_ptr_->getNext();
           
           item_count_--;
           
           return true;
       
   } else if (tail_ptr_ == temp_ptr_) {
           
           previous_ptr_->setNext(nullptr);
           
           tail_ptr_ = previous_ptr_;
           
           item_count_--;
           
           return true;
           
       } else {
           
           previous_ptr_->setNext(temp_ptr_->getNext());
           
           item_count_--;
           
           return true;
           
       }
       
   }
  
	return 0;

} // end remove

//Loop Playlist
void PlayList::loop() {
    
    tail_ptr_->setNext(head_ptr_);
    
}

void PlayList::unloop() {
 
    tail_ptr_->setNext(nullptr);
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
 
Node<Song> *PlayList::getPointerToLastNode() const {
    
  // cylces through each node until it finds one that points to nullptr and
  // returns a pointer to it
    
  Node<Song> *current = head_ptr_;
    
  Node<Song> *previous = nullptr;
    
  while (current != nullptr) {
      
    previous = current;
      
    current = current->getNext();
      
  }
    
  return previous;
}

Node<Song> *PlayList::getPointerTo(const Song &target, Node<Song> *&previous_ptr) const {
    
    Song my_target = target;
    
    Node<Song> *current = head_ptr_;
    
    Node<Song> *previous = nullptr;
  // cycles through each node until it finds one whose song matches target,
  // which it returns
  // if nothing is found, nullptr is returned
    
    while (current != nullptr) {
        
        if (current->getItem() == my_target) {
            
            previous_ptr = previous;
            
            return current;
        
        }
        
    previous = current;
        
    current = current->getNext();
        
  }
    
  return nullptr;
    
}