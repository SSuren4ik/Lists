#pragma once
#include <iostream>
#include <fstream>
#include <string>
using namespace std;


struct Link {
    int val;
    Link* next;
    Link(int _val = 0, Link* _n = nullptr) {
        val = _val;
        next = _n;
    }
    ~Link()
    {
        ;
    }
};

class List {
private:
    Link* head;

public:
    List() {
        head = new Link();
        head->next = head;
    }
    List(List& l)
    {
        Link* tmp = l.head->next;
        while (l.head != l.head->next)
        {
            add(tmp->val);
            tmp = tmp->next;
        }
    }
    List& operator= (const List& l)
    {
        this->clear();
        Link* tmp = l.head->next;
        while (tmp!= l.head)
        {
            add(tmp->val);
            tmp = tmp->next;
        }
        return *this;
    }
    bool find(int x) {
        Link* t = head->next;
        while (t != head) {
            if (t->val == x)
                return true;
            t = t->next;
        }
        return false;
    }
    void add(int x)
    {
        //считаем , что список упорядочен
        Link* t = head->next;
        Link* tmp = new Link(x);
        while (t->next != head) {
            if (t->next->val > x) {
                //добавляем
                tmp->next = t->next;
                t->next = tmp;
                return;
            }
            t = t->next;
        }
        t->next = tmp;
        tmp->next = head;
    }
    void clear()
    {
        head->next = head;
    }
    friend ostream& operator <<(ostream& out, List& obj)
    {
        Link* t = obj.head->next;
        while (t != obj.head) {
            out << t->val << ' ';
            t = t->next;
        }
        return out;
    }
    friend istream& operator >> (istream& in, List& obj)
    {
        obj.clear();
        string s;
        string sep = "$";
        while (true) {
            in >> s;
            if (s == sep)
                break;
            obj.add(stoi(s));
        }
        return in;
    }
    List merge(List& l1)
    {
        List l;
        Link* tmp1 = this->head->next;
        Link* tmp2 = l1.head->next;
        while ((tmp2 != l1.head) && (tmp1!= this->head))
        {
            if (tmp1->val == tmp2->val)
            {
                l.add(tmp1->val);
                tmp1 = tmp1->next;
                tmp2 = tmp2->next;
            }
            else
            {
                if (tmp1->val > tmp2->val)
                {
                    tmp2 = tmp2->next;
                }
                else
                {
                    tmp1 = tmp1->next;
                }
            }
        }
        return l;
    }
    ~List()
    {
        Link* tmp = head->next;
        Link* tmp1 = tmp->next;
        while (tmp!=head)
        {
            delete tmp;
            tmp = tmp1;
            tmp1 = tmp->next;
        }
    }
};

