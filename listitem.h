//
// Created by sakost on 23.11.2020.
//

#ifndef OOP_EXCERCISE_06_LISTITEM_H
#define OOP_EXCERCISE_06_LISTITEM_H

template <typename T>
struct ListItem {
    using value_type = T;
    using pointer = T*;
    using reference = T&;
    using const_reference = const T&;
    using rvalue_reference = T&&;

    using self_type = ListItem<T>;
    using self_pointer = self_type *;

    ListItem() : ListItem(value_type()){}

    explicit ListItem(value_type item, self_pointer prev = nullptr, self_pointer next = nullptr){
        m_item = item;
        m_next = next;
        m_prev = prev;
    }

    self_pointer get_next(){
        return m_next;
    }

    self_pointer get_prev(){
        return m_prev;
    }

    void set_prev(self_pointer prev){
        m_prev = prev;
    }

    void set_next(self_pointer next){
        m_next = next;
    }

    reference get_item(){
        return m_item;
    }

    value_type m_item;
    self_pointer m_prev, m_next;
};


#endif //OOP_EXCERCISE_06_LISTITEM_H
