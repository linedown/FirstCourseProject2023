#pragma once
#include <cassert>
#include <iostream>
#include "new_vector.h"

class network {
    bool centr;
    new_vector<bool> comps;
    bool status_computers;
    bool internet;
public:
    network();
    void reset_set_centr();
    bool get_status_centr();
    void push_in_comps(bool value);
    void pop_last_comp();
    bool get_status_computers();
    void RS_internet();
    bool get_status_internet();
    bool operator == (const network& net);
    bool operator != (const network& net);
    bool& operator[](int index);
    friend ostream& operator << (ostream& vyvod, const network& net);
};

network::network() {
    centr = false;
    status_computers = false;
    internet = false;
}

void network::reset_set_centr() {
    if (centr) {
        centr = false;
    }

    else {
        centr = true;
    }
}

bool network::get_status_centr() {
    return centr;
}

void network::push_in_comps(bool value) {
    comps.push_back_vector(value);
}

void network::pop_last_comp() {
    comps.pop_back_vector();
}

bool network::operator == (const network& net) {
    if (this->centr != net.centr || this->comps != net.comps) {
        return false;
    }

    return true;
}

bool network::operator != (const network& net) {
    return !(this->operator==(net));
}

bool network::get_status_computers() {
    for (int i = 0; i < comps.size_vector(); i++) {
        if (comps[i]) {
            status_computers = true;
            goto return_status;
        }
    }

    status_computers = false;

return_status:
    return status_computers;
}

void network::RS_internet() {
    if (centr s status_computers) {
        internet = true;
    }
    else {
        internet = false;
    }
}

bool network::get_status_internet() {
    return internet;
}

bool& network::operator[](int index) {

    assert(index >= 0 && index <= comps.size_vector());

    if (index == 0) {
        return centr;
    }

    else {
        return comps[index - 1];
    }
}

ostream& operator << (ostream& vyvod, const network& net) {

    vyvod << "Состояние центра: " << net.centr << "\n";
    vyvod << "Состояние компьютеров: " << net.comps << "\n";
    vyvod << "Статус интернета: " << net.internet << "\n";
    return vyvod;
}
