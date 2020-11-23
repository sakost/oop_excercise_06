//
// Created by sakost on 23.11.2020.
//

#ifndef OOP_EXCERCISE_06_CUSTOMLIST_H
#define OOP_EXCERCISE_06_CUSTOMLIST_H

#include "listitem.h"

#include <memory>

template <typename T>
struct CustomList {
    using value_type = T;
    using pointer = value_type *;
    using reference = value_type &;
    using const_reference = const value_type &;

    using item_type = ListItem<T>;
    using const_item_type = ListItem<const T>;
    using item_pointer = item_type *;
    using item_reference = item_type &;
    using const_item_reference = const_item_type &;

    using size_type = std::size_t;

    CustomList(){
        head = last = nullptr;
    }

    size_type size(){
        return size(head);
    }

    size_type size(item_pointer node){
        if(node == nullptr) return 0;
        return size(node->get_next()) + 1;
    }


    void push_back(value_type val){
        auto prev = back_item();
        auto item = new item_type(val, prev);
        if(prev == nullptr){
            head = item;
        } else{
            prev->set_next(item);
        }
        last = item;
    }

    item_pointer back_item(){
        return last;
    }

    item_pointer front_item(){
        return head;
    }

    reference front(){
        if(empty()){
            throw std::out_of_range("List is empty");
        }
        return head->get_item();
    }
    reference back(){
        if(empty()){
            throw std::out_of_range("List is empty");
        }
        return last->get_item();
    }

    void pop_back(){
        if(empty()){
            throw std::out_of_range("List is empty");
        }
        auto prev = last->get_prev();
        if(prev != nullptr){
            prev->set_next(nullptr);
        }
        delete last;
        last = prev;
    }


    void pop_front(){
        if(empty()){
            throw std::out_of_range("List is empty");
        }
        auto next = head->get_next();
        if(next != nullptr){
            next->set_prev(nullptr);
        }
        delete head;
        head = next;
    }

    void push_front(value_type val){
        auto front = front_item();
        auto item = new item_type (val, nullptr, front);
        if(front == nullptr){
            last = item;
        } else{
            front->set_prev(item);
        }
        head = item;
    }

    [[nodiscard]] bool empty() const{
        return head == last == nullptr;
    }

    item_pointer head, last;
};


#endif //OOP_EXCERCISE_06_CUSTOMLIST_H
