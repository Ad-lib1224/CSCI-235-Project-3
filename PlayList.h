#ifndef ENHANCED_PLAY_LIST_H_
#define ENHANCED_PLAY_LIST_H_

#include "LinkedSet.h"
#include "Song.h"
    
class PlayList : public LinkedSet<Song> {

//Inherited Protected Members from LinkedSet
    
protected:
    
    // Pointer to first node
    
    Node<Song>* head_ptr_;
    
    // Current count of set items
    
    int item_count_;
    
    // Returns either a pointer to the node containing a target or the null pointer if the target is not in the set.
    
    Node<Song>* getPointerTo(const Song& target) const;
   
public:
    
    //Default constructor
    
    PlayList(); 
    
    //parameterized constructor
    
    PlayList(const Song& a_song); 
    
    // copy constructor
    
    PlayList(const PlayList& a_play_list): LinkedSet(a_play_list) {
        
        head_ptr_ = a_play_list.head_ptr_;
        
        tail_ptr_ = a_play_list.getPointerToLastNode();     
    }
    
    // Destructor
    
    ~PlayList(); 
    //Inherited Public functions from LinkedSet
    
    //Override functions
    //Adds songs to end of PlayList
    
    bool add(const Song& new_song) override; 

    //Removes songs and preserves the order of the Songs
    
    bool remove(const Song& a_song) override;
    
    //Plays Songs in a loop
    
    void loop();  
    //Unloops Songs in PLayList
    
    void unloop();

    //Displays Songs in PLayList
    
    void displayPlayList();

private: 
    //Private Data Member
    // Pointer to last node
    
    Node<Song>* tail_ptr_;
    /*post: previous_ptr is null if target is not in PlayList or if target is the first node, otherwise it points to the node preceding target return: either a pointer to the node containing target or the null pointer if the target is not in the PlayList.*/

    Node<Song>* getPointerTo(const Song& target, Node<Song>*& previous_ptr) const;
    
    //Transverses the chain and returns a pointer to the last node
    
    Node<Song>* getPointerToLastNode() const; 
    
};

//endif
#endif
    